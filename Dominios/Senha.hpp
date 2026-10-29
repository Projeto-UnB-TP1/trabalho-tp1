#ifndef SENHA_HPP
#define SENHA_HPP
#include <string>

using namespace std;

///
/// Padrão para representação de senha.
///
/// Regras de formato:
///
/// - 5 caracteres.
/// - Cada caractere é letra ou dígito.
/// - Pelo menos uma letra e pelo menos um dígito.
///

class Senha{
    private:
        static const int TamanPermitido = 5;
        string valor;
        void validar(string valor);

    public:

///
/// Armazena senha caso a mesma seja válida.
///
/// Lança exceção caso a senha seja inválida.
///
/// @param valor Senha.
///
/// @throw invalid_argument
///

        void setValor(string valor);

///
/// Retorna senha.
///
/// @return Senha.
///

        string getValor() const;
};
#endif
