#include "Identificador.hpp"

void Identificador::validar(std::string valor) {
    if (valor.length() != 6) {
        throw std::invalid_argument("Identificador invalido: deve ter exatos 6 caracteres.");
    }
    for (int i = 0; i < 3; i++) {
        bool letra = (valor[i] >= 'A' && valor[i] <= 'Z') || (valor[i] >= 'a' && valor[i] <= 'z');
        if (!letra) {
            throw std::invalid_argument("Identificador invalido: primeiros 3 caracteres devem ser letras.");
        }
    }
    for (int i = 3; i < 6; i++) {
        if (!(valor[i] >= '0' && valor[i] <= '9')) {
            throw std::invalid_argument("Identificador invalido: ultimos 3 caracteres devem ser digitos.");
        }
    }
}

void Identificador::setValor(std::string valor) {
    validar(valor);
    this->valor = valor;
}

std::string Identificador::getValor() const {
    return valor;
}
