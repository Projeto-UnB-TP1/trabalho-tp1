#ifndef NOME_HPP
#define NOME_HPP

#include <string>
#include <stdexcept>

///
/// Padrão para representação de nome.
///
/// Regras de formato:
///
/// - Até 15 caracteres.
/// - Cada caractere é letra ou espaço em branco.
/// - Espaço em branco seguido por letra.
/// - Não inicia nem termina com espaço em branco.
///

class Nome {
private:
    std::string valor;
    void validar(std::string valor);
    bool ehLetra(char c) const;
public:

///
/// Armazena nome caso o mesmo seja válido.
///
/// Lança exceção caso o nome seja inválido.
///
/// @param valor Nome.
///
/// @throw invalid_argument
///

    void setValor(std::string valor);

///
/// Retorna nome.
///
/// @return Nome.
///

    std::string getValor() const;
};

#endif
