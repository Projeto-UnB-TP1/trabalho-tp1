#include "Estado.h"
#include <stdexcept>

using namespace std;

string Estado::getValor(){
    return valor;
}

bool Estado::validar(string valor){
    if (valor == "A FAZER" || valor == "FAZENDO" || valor == "FEITO"
    ){
        return true;
    }    
    return false;
}

bool Estado::setValor(string valor){
    if (validar(valor)){
        this->valor = valor;
        return true;
    }
    throw invalid_argument("Estado invalido");
}