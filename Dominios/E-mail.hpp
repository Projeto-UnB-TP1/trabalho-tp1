#ifndef EMAIL_HPP
#define EMAIL_HPP
#include <string>

using namespace std;

/**
 * @file E-mail.hpp
 * @brief Declaração da classe de domínio Email.
 */

/**
 * @brief Domínio que representa o endereço de e-mail de um usuário.
 *
 * @details O formato válido é <tt>parte-local\@dominio</tt>, com exatamente um
 * caractere '@'.
 *
 * **Parte local**
 * - contém apenas letras minúsculas (a-z), dígitos (0-9), ponto (.) ou hífen (-);
 * - não pode ser vazia e tem no máximo 64 caracteres;
 * - não pode iniciar nem terminar com ponto ou hífen;
 * - ponto ou hífen deve ser seguido por letra ou dígito.
 *
 * **Domínio**
 * - é composto por uma ou mais partes separadas por ponto (.);
 * - cada parte não pode ser vazia e contém apenas letras minúsculas (a-z),
 *   dígitos (0-9) ou hífen (-);
 * - cada parte não pode iniciar nem terminar com hífen;
 * - o comprimento máximo do domínio é 255 caracteres.
 *
 * Letras maiúsculas são consideradas inválidas.
 *
 * Exemplos válidos: "joao.silva\@unb.br", "a-b2\@x-y.com", "a\@b".
 * Exemplos inválidos: ".a\@x.com", "a..b\@x.com", "a\@-b.com", "a\@b..com", "A\@x.com".
 *
 * Exemplo de uso:
 * @code
 * Email email;
 * try {
 *     email.setValor("joao.silva@unb.br");
 *     string atual = email.getValor();
 * } catch (const invalid_argument& e) {
 *
 * }
 * @endcode
 */
class Email {
    private:
        /** @brief Comprimento máximo da parte local (antes do '@'). */
        static const int LimiteLocal = 64;

        /** @brief Comprimento máximo do domínio (depois do '@'). */
        static const int LimiteDominio = 255;

        /** @brief Valor armazenado do e-mail. */
        string valor;

        /**
         * @brief Verifica se um caractere é letra minúscula (a-z) ou dígito (0-9).
         * @param c Caractere a ser verificado.
         * @return true se for letra minúscula ou dígito; false caso contrário.
         */
        bool minusculaOuDigito(char c) const;

        /**
         * @brief Verifica se um texto é um e-mail válido.
         * @param valor Texto a ser verificado.
         * @throws invalid_argument se o texto não respeitar as regras da parte local e do domínio.
         */
        void validar(string valor);

    public:
        /**
         * @brief Atribui um valor ao e-mail.
         * @param valor Texto com o novo endereço de e-mail.
         * @throws invalid_argument se o valor não estiver no formato válido.
         *         Nesse caso, o valor anteriormente armazenado não é alterado.
         */
        void setValor(string valor);

        /**
         * @brief Obtém o valor armazenado.
         * @return Texto com o e-mail atual.
         */
        string getValor() const;
};
#endif
