#include <stdexcept>
#include "Papel.hpp"

using namespace std;


void Papel:: setValor(string valor){
    if(valor != "GESTOR" && valor != "DESENVOLVEDOR"){
       throw:: invalid_argument("Papel invalido");
    }
    this->valor = valor;
}

std:: string Papel:: getValor() const {
    return valor;
}


