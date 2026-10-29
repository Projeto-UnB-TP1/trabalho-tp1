#ifndef EMAIL_HPP
#define EMAIL_HPP
#include <string>

using namespace std;

///
/// Padrão para representação de e-mail.
///
/// Regras de formato:
///
/// - Formato parte local, caractere arroba e domínio, por exemplo nome@unb.br.
/// - Parte local com até 64 caracteres: letras minúsculas, dígitos, ponto ou hífen.
/// - Parte local não inicia nem termina com ponto ou hífen.
/// - Ponto ou hífen seguido por letra ou dígito.
/// - Domínio com até 255 caracteres: partes separadas por ponto, cada parte com letras minúsculas, dígitos ou hífen.
/// - Parte do domínio não inicia nem termina com hífen.
///

class Email {
    private:
        static const int LimiteLocal = 64;
        static const int LimiteDominio = 255;
        string valor;
        bool minusculaOuDigito(char c) const;
        void validar(string valor);

    public:

///
/// Armazena e-mail caso o mesmo seja válido.
///
/// Lança exceção caso o e-mail seja inválido.
///
/// @param valor E-mail.
///
/// @throw invalid_argument
///

        void setValor(string valor);

///
/// Retorna e-mail.
///
/// @return E-mail.
///

        string getValor() const;
};
#endif
