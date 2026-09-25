#include "Limite.hpp"

void Limite::validar(int valor) {
    if (valor < 1 || valor > 25) {
        throw std::invalid_argument("Limite invalido. Deve ser um valor de 1 a 25.");
    }
}

void Limite::setValor(int valor) {
    validar(valor);
    this->valor = valor;
}

int Limite::getValor() const {
    return valor;
}