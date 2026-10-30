#ifndef LIMITE_HPP
#define LIMITE_HPP

#include <stdexcept>

///
/// Padrão para representação de limite de work in progress (WIP).
///
/// Regras de formato:
///
/// - Limite é válido caso seja de 1 a 25.
///

class Limite {
private:
    int valor;
    void validar(int valor);

public:

///
/// Armazena limite caso o mesmo seja válido.
///
/// Lança exceção caso o limite seja inválido.
///
/// @param valor Limite.
///
/// @throw invalid_argument
///

    void setValor(int valor);

///
/// Retorna limite.
///
/// @return Limite.
///

    int getValor() const;
};

#endif
