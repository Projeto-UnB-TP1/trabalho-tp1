#include "Texto.hpp"

bool Texto::isPontuacao(char c) const {
    return (c == ',' || c == ';' || c == '.' || c == ':' || c == '?' || c == '!');
}

bool Texto::isLetraOuDigito(char c) const {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

void Texto::validar(std::string valor) {
    unsigned int tamanho = valor.length();
    if (tamanho == 0 || tamanho > 30) {
        throw std::invalid_argument("Texto invalido: deve ter entre 1 e 30 caracteres.");
    }

    if (!(valor[0] >= 'A' && valor[0] <= 'Z')) {
        throw std::invalid_argument("Texto invalido: primeiro caractere deve ser letra maiuscula.");
    }

    if (valor[tamanho - 1] != '.') {
        throw std::invalid_argument("Texto invalido: ultimo caractere deve ser um ponto (.).");
    }

    for (unsigned int i = 0; i < tamanho; i++) {
        char c = valor[i];

        bool isValido = isLetraOuDigito(c) || c == ' ' || isPontuacao(c);
        if (!isValido) {
            throw std::invalid_argument("Texto invalido: contem caractere nao permitido.");
        }

        if (i > 0 && isPontuacao(c) && isPontuacao(valor[i - 1])) {
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
