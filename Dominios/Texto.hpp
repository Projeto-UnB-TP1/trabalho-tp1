#ifndef TEXTO_HPP
#define TEXTO_HPP

#include <string>
#include <stdexcept>

///
/// Padrão para representação de texto.
///
/// Regras de formato:
///
/// - Até 30 caracteres.
/// - Cada caractere é letra, dígito, espaço em branco ou sinal de pontuação (, ; . : ? !).
/// - Não há dois sinais de pontuação seguidos.
/// - Primeiro caractere é letra maiúscula e último caractere é ponto.
///

class Texto {
private:
    std::string valor;
    void validar(std::string valor);
    bool isPontuacao(char c) const;
    bool isLetraOuDigito(char c) const;

public:

///
/// Armazena texto caso o mesmo seja válido.
///
/// Lança exceção caso o texto seja inválido.
///
/// @param valor Texto.
///
/// @throw invalid_argument
///

    void setValor(std::string valor);

///
/// Retorna texto.
///
/// @return Texto.
///

    std::string getValor() const;
};

#endif
