#ifndef ESTADO_HPP
#define ESTADO_HPP
#include <string>

using namespace std;

/**
 * @file Estado.hpp
 * @brief Declaração da classe de domínio Estado.
 */

/**
 * @brief Domínio que representa o estado (coluna) de um cartão de atividade no quadro Kanban.
 *
 * @details Os valores válidos são exatamente os três textos abaixo, em maiúsculas
 * e, no primeiro caso, com um espaço em branco entre as palavras:
 * - "A FAZER"
 * - "FAZENDO"
 * - "FEITO"
 *
 * Qualquer outro texto é considerado inválido. A validação não considera acentuação.
 *
 * Exemplo de uso:
 * @code
 * Estado estado;
 * try {
 *     estado.setValor("FAZENDO");
 *     string atual = estado.getValor();   // "FAZENDO"
 * } catch (const invalid_argument& e) {
 *     // valor fora do formato permitido
 * }
 * @endcode
 */
class Estado{
    private:
        /** @brief Valor armazenado do estado. */
        string valor;

        /**
         * @brief Verifica se um texto é um estado válido.
         * @param valor Texto a ser verificado.
         * @return true se o texto for "A FAZER", "FAZENDO" ou "FEITO"; false caso contrário.
         */
        bool validar(string valor);

    public:
        /**
         * @brief Atribui um valor ao estado.
         * @param valor Texto com o novo estado: "A FAZER", "FAZENDO" ou "FEITO".
         * @return true se o valor foi atribuído com sucesso.
         * @throws invalid_argument se o valor não estiver no formato válido.
         *         Nesse caso, o valor anteriormente armazenado não é alterado.
         */
        bool setValor(string valor);

        /**
         * @brief Obtém o valor armazenado.
         * @return Texto com o estado atual.
         */
        string getValor();
};
#endif
