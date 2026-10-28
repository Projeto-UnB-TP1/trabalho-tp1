#include "CntrServicoKanban.hpp"

int CntrServicoKanban::calcularWIP(const std::vector<CartaoDeAtividade>& cartoesNoQuadro) const {
    int wip = 0;
    for (const auto& cartao : cartoesNoQuadro) {
        if (cartao.getEstado().getValor() == "FAZENDO") {
            wip++;
        }
    }
    return wip;
}

void CntrServicoKanban::moverCartao(CartaoDeAtividade& cartao, const Quadro& quadro, const std::vector<CartaoDeAtividade>& cartoesNoQuadro) const {
    std::string estadoAtual = cartao.getEstado().getValor();

    if (estadoAtual == "A FAZER") {
        int wipAtual = calcularWIP(cartoesNoQuadro);
        int limiteQuadro = std::stoi(quadro.getLimite().getValor());

        if (wipAtual >= limiteQuadro) {
            throw std::invalid_argument("Erro: Limite WIP do quadro atingido. Não é possível adicionar à coluna FAZENDO.");
        }
        
        Estado novoEstado;
        novoEstado.setValor("FAZENDO");
        cartao.setEstado(novoEstado);
        

    } else if (estadoAtual == "FAZENDO") {
        Estado novoEstado;
        novoEstado.setValor("FEITO");
        cartao.setEstado(novoEstado);
        

    } else {
        throw std::invalid_argument("Movimentação inválida: O cartão já está concluído (FEITO).");
    }
}

double CntrServicoKanban::calcularCycleTime(const CartaoDeAtividade& cartao) const {
    if (cartao.getEstado().getValor() != "FEITO") {
        return 0.0;
    }
    return calcularDiferencaTempo(cartao.getInicio(), cartao.getTermino());
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
    return (concluidos == 0) ? 0.0 : (somaCycleTime / concluidos);
}

double CntrServicoKanban::calcularLeadTime(const CartaoDeAtividade& cartao) const {
    if (cartao.getEstado().getValor() != "FEITO") {
        return 0.0;
    }
    return calcularDiferencaTempo(cartao.getEntrada(), cartao.getTermino());
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
    return (concluidos == 0) ? 0.0 : (somaLeadTime / concluidos);
}

double CntrServicoKanban::calcularDiferencaTempo(const Timestamp& inicio, const Timestamp& fim) const {
    return 10.5;
}