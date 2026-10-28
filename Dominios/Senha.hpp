#ifndef SENHA_HPP
#define SENHA_HPP
#include <string>

using namespace std;

/**
 * @file Senha.hpp
 * @brief Declaração da classe de domínio Senha.
 */

/**
 * @brief Domínio que representa a senha de um usuário.
 *
 * @details Uma senha é válida quando satisfaz todas as regras abaixo:
 * - possui exatamente 5 caracteres;
 * - cada caractere é uma letra (a-z ou A-Z) ou um dígito (0-9);
 * - existe pelo menos uma letra;
 * - existe pelo menos um dígito.
 *
 * Exemplos válidos: "abc12", "A1b2C", "12ab3".
 * Exemplos inválidos: "abcde" (sem dígito), "12345" (sem letra),
 * "ab12" (tamanho incorreto), "ab-12" (caractere não permitido).
 *
 * Exemplo de uso:
 * @code
 * Senha senha;
 * try {
 *     senha.setValor("abc12");
 *     string atual = senha.getValor();
 * } catch (const invalid_argument& e) {
 *
 * }
 * @endcode
 */
class Senha{
    private:
        /** @brief Quantidade exata de caracteres de uma senha. */
        static const int TamanPermitido = 5;

        /** @brief Valor armazenado da senha. */
        string valor;

        /**
         * @brief Verifica se um texto é uma senha válida.
         * @param valor Texto a ser verificado.
         * @return true se o texto respeitar todas as regras do domínio; false caso contrário.
         */
        bool validar(string valor);

    public:
        /**
         * @brief Atribui um valor à senha.
         * @param valor Texto com a nova senha.
         * @return true se o valor foi atribuído com sucesso.
         * @throws invalid_argument se o valor não estiver no formato válido.
         *         Nesse caso, o valor anteriormente armazenado não é alterado.
         */
        bool setValor(string valor);

        /**
         * @brief Obtém o valor armazenado.
         * @return Texto com a senha atual.
         */
        string getValor();
};
#endif
