#ifndef CNTR_SERVICO_KANBAN_HPP
#define CNTR_SERVICO_KANBAN_HPP

#include <vector>
#include <stdexcept>
#include <string>

// Simulação das inclusões das suas classes de Entidade
// #include "CartaoDeAtividade.hpp"
// #include "Quadro.hpp"

#include "../Mocks.hpp"

/**
 * @class CntrServicoKanban
 * @brief Controladora da camada de serviço responsável pelas lógicas de negócio do quadro Kanban.
 * 
 * Implementa as regras de movimentação de cartões, restrições de limite WIP e 
 * os cálculos matemáticos de métricas ágeis (Lead Time e Cycle Time).
 */
class CntrServicoKanban {
private:
    /**
     * @brief Função utilitária para calcular a diferença em horas/dias entre duas datas.
     * @param inicio Timestamp inicial.
     * @param fim Timestamp final.
     * @return Diferença de tempo calculada em ponto flutuante.
     */
    double calcularDiferencaTempo(const Timestamp& inicio, const Timestamp& fim) const;

public:
    /**
     * @brief Move o cartão de atividade seguindo o fluxo do Kanban.
     * 
     * As movimentações possíveis são A FAZER -> FAZENDO e FAZENDO -> FEITO.
     * @param cartao Referência para o cartão que será movido.
     * @param quadro Referência para o quadro ao qual o cartão pertence.
     * @param cartoesNoQuadro Lista contendo todos os cartões atuais do quadro para verificação de limite.
     * @throw std::invalid_argument Caso o movimento seja inválido ou o limite WIP seja ultrapassado.
     */
    void moverCartao(CartaoDeAtividade& cartao, const Quadro& quadro, const std::vector<CartaoDeAtividade>& cartoesNoQuadro) const;

    /**
     * @brief Calcula o Work In Progress (WIP) atual do quadro.
     * @param cartoesNoQuadro Lista de cartões de atividade.
     * @return O número de cartões que estão atualmente na coluna FAZENDO.
     */
    int calcularWIP(const std::vector<CartaoDeAtividade>& cartoesNoQuadro) const;

    /**
     * @brief Calcula o tempo de ciclo (Cycle Time) de um cartão concluído.
     * 
     * Mede o tempo desde a entrada na coluna FAZENDO até a chegada na coluna FEITO.
     * @param cartao O cartão de atividade.
     * @return O valor do cycle time.
     */
    double calcularCycleTime(const CartaoDeAtividade& cartao) const;

    /**
     * @brief Calcula o Tempo de Ciclo Médio do quadro.
     * @param cartoesNoQuadro Lista de cartões do quadro.
     * @return A média dos tempos de ciclo de todos os cartões concluídos.
     */
    double calcularCycleTimeMedio(const std::vector<CartaoDeAtividade>& cartoesNoQuadro) const;

    /**
     * @brief Calcula o Lead Time de um cartão concluído.
     * 
     * Mede o tempo desde a entrada na coluna A FAZER até a conclusão na coluna FEITO.
     * @param cartao O cartão de atividade.
     * @return O valor do lead time.
     */
    double calcularLeadTime(const CartaoDeAtividade& cartao) const;

    /**
     * @brief Calcula o Lead Time Médio do quadro.
     * @param cartoesNoQuadro Lista de cartões do quadro.
     * @return A média dos lead times de todos os cartões concluídos.
     */
    double calcularLeadTimeMedio(const std::vector<CartaoDeAtividade>& cartoesNoQuadro) const;
};

#endif // CNTR_SERVICO_KANBAN_HPP