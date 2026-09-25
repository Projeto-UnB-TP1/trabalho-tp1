#include "Tamanho.hpp"

void Tamanho::validar(std::string valor) {
    if (valor != "GRANDE" && valor != "MEDIO" && valor != "PEQUENO") {
        throw std::invalid_argument("Tamanho invalido. Formatos aceitos: GRANDE, MEDIO, PEQUENO.");
    }
}

void Tamanho::setValor(std::string valor) {
    validar(valor);
    this->valor = valor;
}

std::string Tamanho::getValor() const {
    return valor;
}