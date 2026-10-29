#ifndef IDENTIFICADOR_HPP
#define IDENTIFICADOR_HPP

#include <string>
#include <stdexcept>

///
/// Padrão para representação de identificador.
///
/// Regras de formato:
///
/// - 6 caracteres.
/// - Os três primeiros caracteres são letras.
/// - Os três últimos caracteres são dígitos.
///

class Identificador {
private:
    std::string valor;
    void validar(std::string valor);
public:

///
/// Armazena identificador caso o mesmo seja válido.
///
/// Lança exceção caso o identificador seja inválido.
///
/// @param valor Identificador.
///
/// @throw invalid_argument
///

    void setValor(std::string valor);

///
/// Retorna identificador.
///
/// @return Identificador.
///

    std::string getValor() const;
};

#endif
