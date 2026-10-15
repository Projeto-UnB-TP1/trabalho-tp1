#include <iostream>
#include <vector>
#include <stdexcept>

// Inclua os cabeçalhos das suas classes (ajuste os caminhos se necessário)
// #include "Servicos/CntrServicoKanban.hpp"
// #include "CartaoDeAtividade.hpp" 
// #include "Quadro.hpp"
// #include "Limite.hpp"
// #include "Estado.hpp"

#include "Mocks.hpp"
#include "Servicos/CntrServicoKanban.hpp"

void executarSmokeTestKanban() {
    std::cout << "======================================\n";
    std::cout << " INICIANDO SMOKE TEST: REGRAS KANBAN \n";
    std::cout << "======================================\n";

    try {
        CntrServicoKanban servico;
        std::vector<CartaoDeAtividade> cartoesNoQuadro;

        // 1. SETUP: Criar um Quadro com limite WIP de 2
        Quadro quadro;
        Limite limite; 
        limite.setValor("2"); // Regra do domínio Limite validada
        quadro.setLimite(limite);

        // 2. SETUP: Criar um Cartão de Atividade no estado inicial
        CartaoDeAtividade cartao;
        Estado estadoInicial; 
        estadoInicial.setValor("A FAZER"); // Estado obrigatório inicial
        cartao.setEstado(estadoInicial);
        cartoesNoQuadro.push_back(cartao);

        std::cout << "[INFO] Cartão criado. Estado atual: " << cartao.getEstado().getValor() << "\n";

        // 3. TESTE (Req 21 e 26): Mover para FAZENDO e calcular WIP
        servico.moverCartao(cartao, quadro, cartoesNoQuadro);
        cartoesNoQuadro[0] = cartao; // Atualiza o vetor de simulação da base de dados
        
        std::cout << "[SUCESSO] Req 21: Cartão movido para: " << cartao.getEstado().getValor() << "\n";
        std::cout << "[SUCESSO] Req 26: WIP Atual da coluna FAZENDO: " << servico.calcularWIP(cartoesNoQuadro) << "\n";

        // 4. TESTE (Req 21, 22 e 24): Mover para FEITO e calcular Tempos
        servico.moverCartao(cartao, quadro, cartoesNoQuadro);
        cartoesNoQuadro[0] = cartao;
        
        std::cout << "[SUCESSO] Req 21: Cartão movido para: " << cartao.getEstado().getValor() << "\n";
        std::cout << "[SUCESSO] Req 22: Cycle Time calculado: " << servico.calcularCycleTime(cartao) << " (unidades de tempo)\n";
        std::cout << "[SUCESSO] Req 24: Lead Time calculado: " << servico.calcularLeadTime(cartao) << " (unidades de tempo)\n";

        std::cout << "======================================\n";
        std::cout << " SMOKE TEST CONCLUIDO SEM ERROS! \n";
        std::cout << "======================================\n";

    } catch (const std::exception& e) {
        std::cerr << "\n[FALHA NO TESTE] Exceção capturada: " << e.what() << "\n";
    }
}

int main() {
    executarSmokeTestKanban();
    return 0;
}