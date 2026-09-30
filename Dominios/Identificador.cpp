#include "Identificador.hpp"
#include <cctype>

void Identificador::validar(std::string valor) {
    if (valor.length() != 6) {
        throw std::invalid_argument("Identificador invalido: deve ter exatos 6 caracteres.");
    }
    for (int i = 0; i < 3; i++) {
        if (!isalpha(valor[i])) throw std::invalid_argument("Identificador invalido: primeiros 3 caracteres devem ser letras.");
    }
    for (int i = 3; i < 6; i++) {
        if (!isdigit(valor[i])) throw std::invalid_argument("Identificador invalido: ultimos 3 caracteres devem ser digitos.");
    }
}

void Identificador::setValor(std::string valor) {
    validar(valor);
    this->valor = valor;
}