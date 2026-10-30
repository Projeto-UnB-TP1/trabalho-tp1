#ifndef TAMANHO_HPP
#define TAMANHO_HPP

#include <string>
#include <stdexcept>

///
/// Padrão para representação de tamanho de cartão de atividade.
///
/// Regras de formato:
///
/// - Tamanho é válido caso seja GRANDE, MEDIO ou PEQUENO.
///

class Tamanho {
private:
    std::string valor;
    void validar(std::string valor);

public:

///
/// Armazena tamanho caso o mesmo seja válido.
///
/// Lança exceção caso o tamanho seja inválido.
///
/// @param valor Tamanho.
///
/// @throw invalid_argument
///

    void setValor(std::string valor);

///
/// Retorna tamanho.
///
/// @return Tamanho.
///

    std::string getValor() const;
};

#endif
