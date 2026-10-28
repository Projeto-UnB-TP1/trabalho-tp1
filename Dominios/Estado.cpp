#include "Estado.hpp"
#include <stdexcept>

using namespace std;

void Estado::validar(string valor){
    if (valor != "A FAZER" && valor != "FAZENDO" && valor != "FEITO"){
        throw invalid_argument("Estado invalido. Valores aceitos: A FAZER, FAZENDO, FEITO.");
    }
}

void Estado::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

string Estado::getValor() const {
    return valor;
}
