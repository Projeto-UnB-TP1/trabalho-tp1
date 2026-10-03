#include "CntrServicoKanban.hpp"

// Implementação do cálculo de WIP (Requisito: Contar cartões na coluna FAZENDO)
int CntrServicoKanban::calcularWIP(const std::vector<CartaoDeAtividade>& cartoesNoQuadro) const {
    int wip = 0;
    for (const auto& cartao : cartoesNoQuadro) {
        if (cartao.getEstado().getValor() == "FAZENDO") { //
            wip++;
        }
    }
    return wip;
}

// Implementação da funcionalidade MOVER (Requisito: A FAZER -> FAZENDO e FAZENDO -> FEITO)
void CntrServicoKanban::moverCartao(CartaoDeAtividade& cartao, const Quadro& quadro, const std::vector<CartaoDeAtividade>& cartoesNoQuadro) const {
    std::string estadoAtual = cartao.getEstado().getValor();

    if (estadoAtual == "A FAZER") { //
        // Regra WIP: Verifica se há espaço antes de mover para FAZENDO
        int wipAtual = calcularWIP(cartoesNoQuadro); //
        int limiteQuadro = std::stoi(quadro.getLimite().getValor()); // Extrai limite inteiro

        if (wipAtual >= limiteQuadro) { //
            throw std::invalid_argument("Erro: Limite WIP do quadro atingido. Não é possível adicionar à coluna FAZENDO.");
        }
        
        Estado novoEstado;
        novoEstado.setValor("FAZENDO"); //[cite: 5]
        cartao.setEstado(novoEstado);
        
        // Define o Timestamp de Início assim que entra em FAZENDO
        // cartao.setInicio(Timestamp::agora()); 

    } else if (estadoAtual == "FAZENDO") { //[cite: 4]
        Estado novoEstado;
        novoEstado.setValor("FEITO"); //[cite: 5]
        cartao.setEstado(novoEstado);
        
        // Define o Timestamp de Término assim que entra em FEITO
        // cartao.setTermino(Timestamp::agora()); 

    } else {
        throw std::invalid_argument("Movimentação inválida: O cartão já está concluído (FEITO).");
    }
}

// Implementação do Cycle Time (Requisito: FAZENDO até FEITO)
double CntrServicoKanban::calcularCycleTime(const CartaoDeAtividade& cartao) const {
    if (cartao.getEstado().getValor() != "FEITO") {
        return 0.0; // Apenas cartões concluídos têm cycle time completo
    }
    // Tempo medido desde a entrada em FAZENDO (início) até FEITO (término)
    return calcularDiferencaTempo(cartao.getInicio(), cartao.getTermino()); //[cite: 4]
}

double CntrServicoKanban::calcularCycleTimeMedio(const std::vector<CartaoDeAtividade>& cartoesNoQuadro) const {
    double somaCycleTime = 0;
    int concluidos = 0;

    for (const auto& cartao : cartoesNoQuadro) {
        if (cartao.getEstado().getValor() == "FEITO") {
            somaCycleTime += calcularCycleTime(cartao);
            concluidos++;
        }
    }
    return (concluidos == 0) ? 0.0 : (somaCycleTime / concluidos); //[cite: 4]
}

// Implementação do Lead Time (Requisito: A FAZER até FEITO)
double CntrServicoKanban::calcularLeadTime(const CartaoDeAtividade& cartao) const {
    if (cartao.getEstado().getValor() != "FEITO") {
        return 0.0;
    }
    // Tempo medido desde a entrada em A FAZER (entrada) até FEITO (término)
    return calcularDiferencaTempo(cartao.getEntrada(), cartao.getTermino()); //[cite: 4]
}

double CntrServicoKanban::calcularLeadTimeMedio(const std::vector<CartaoDeAtividade>& cartoesNoQuadro) const {
    double somaLeadTime = 0;
    int concluidos = 0;

    for (const auto& cartao : cartoesNoQuadro) {
        if (cartao.getEstado().getValor() == "FEITO") {
            somaLeadTime += calcularLeadTime(cartao);
            concluidos++;
        }
    }
    return (concluidos == 0) ? 0.0 : (somaLeadTime / concluidos); //[cite: 4]
}

// Lógica auxiliar para o cálculo temporal
double CntrServicoKanban::calcularDiferencaTempo(const Timestamp& inicio, const Timestamp& fim) const {
    // Como a classe Timestamp foi formatada em string DIA-MÊS-ANO-HORÁRIO,
    // utilize <ctime> ou converta os campos para std::time_t aqui e subtraia os segundos, 
    // retornando o valor em horas ou dias conforme for preferível para o sistema.
    return 10.5; // Retorno simulado temporário
}