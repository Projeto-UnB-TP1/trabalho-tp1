#include <iostream>
#include <vector>
#include <stdexcept>

#include "Mocks.hpp"
#include "Servicos/CntrServicoKanban.hpp"

void executarSmokeTestKanban() {
    std::cout << "======================================\n";
    std::cout << " INICIANDO SMOKE TEST: REGRAS KANBAN \n";
    std::cout << "======================================\n";

    try {
        CntrServicoKanban servico;
        std::vector<CartaoDeAtividade> cartoesNoQuadro;

        Quadro quadro;
        Limite limite; 
        limite.setValor("2");
        quadro.setLimite(limite);

        CartaoDeAtividade cartao;
        Estado estadoInicial; 
        estadoInicial.setValor("A FAZER");
        cartao.setEstado(estadoInicial);
        cartoesNoQuadro.push_back(cartao);

        std::cout << "[INFO] Cartão criado. Estado atual: " << cartao.getEstado().getValor() << "\n";

        servico.moverCartao(cartao, quadro, cartoesNoQuadro);
        cartoesNoQuadro[0] = cartao;
        
        std::cout << "[SUCESSO] Req 21: Cartão movido para: " << cartao.getEstado().getValor() << "\n";
        std::cout << "[SUCESSO] Req 26: WIP Atual da coluna FAZENDO: " << servico.calcularWIP(cartoesNoQuadro) << "\n";

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