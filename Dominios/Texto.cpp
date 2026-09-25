#include "Texto.hpp"
#include <cctype>

bool Texto::isPontuacao(char c) {
    return (c == ',' || c == ';' || c == '.' || c == ':' || c == '?' || c == '!');
}

void Texto::validar(std::string valor) {
    if (valor.length() == 0 || valor.length() > 30) {
        throw std::invalid_argument("Texto invalido: deve ter entre 1 e 30 caracteres.");
    }

    if (!isupper(valor[0])) {
        throw std::invalid_argument("Texto invalido: primeiro caractere deve ser letra maiuscula.");
    }

    if (valor.back() != '.') {
        throw std::invalid_argument("Texto invalido: ultimo caractere deve ser um ponto (.).");
    }

    for (size_t i = 0; i < valor.length(); ++i) {
        char c = valor[i];
        
        bool isValido = isalnum(c) || isspace(c) || isPontuacao(c);
        if (!isValido) {
            throw std::invalid_argument("Texto invalido: contem caractere nao permitido.");
        }

        if (i > 0 && isPontuacao(c) && isPontuacao(valor[i-1])) {
            throw std::invalid_argument("Texto invalido: nao pode conter sinais de pontuacao seguidos.");
        }
    }
}

void Texto::setValor(std::string valor) {
    validar(valor);
    this->valor = valor;
}

std::string Texto::getValor() const {
    return valor;
}