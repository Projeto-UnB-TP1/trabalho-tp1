#include "Nome.hpp"

bool Nome::ehLetra(char c) const {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

void Nome::validar(std::string valor) {
    unsigned int tamanho = valor.length();
    if (tamanho == 0 || tamanho > 15) {
        throw std::invalid_argument("Nome invalido: deve ter entre 1 e 15 caracteres.");
    }
    if (valor[0] == ' ' || valor[tamanho - 1] == ' ') {
        throw std::invalid_argument("Nome invalido: nao pode iniciar ou terminar com espaco.");
    }

    for (unsigned int i = 0; i < tamanho; i++) {
        if (!ehLetra(valor[i]) && valor[i] != ' ') {
            throw std::invalid_argument("Nome invalido: deve conter apenas letras e espacos.");
        }
        if (valor[i] == ' ' && i < tamanho - 1 && !ehLetra(valor[i + 1])) {
            throw std::invalid_argument("Nome invalido: espaco deve ser seguido por letra.");
        }
    }
}

void Nome::setValor(std::string valor) {
    validar(valor);
    this->valor = valor;
}

std::string Nome::getValor() const {
    return valor;
}
