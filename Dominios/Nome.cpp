#include "Nome.hpp"
#include <cctype>

void Nome::validar(std::string valor) {
    if (valor.empty() || valor.length() > 15) {
        throw std::invalid_argument("Nome invalido: deve ter entre 1 e 15 caracteres.");
    }
    if (valor.front() == ' ' || valor.back() == ' ') {
        throw std::invalid_argument("Nome invalido: nao pode iniciar ou terminar com espaco.");
    }
    
    for (size_t i = 0; i < valor.length(); i++) {
        if (!isalpha(valor[i]) && valor[i] != ' ') {
            throw std::invalid_argument("Nome invalido: deve conter apenas letras e espacos.");
        }
        if (valor[i] == ' ' && i < valor.length() - 1 && !isalpha(valor[i+1])) {
            throw std::invalid_argument("Nome invalido: espaco deve ser seguido por letra.");
        }
    }
}

void Nome::setValor(std::string valor) {
    validar(valor);
    this->valor = valor;
}