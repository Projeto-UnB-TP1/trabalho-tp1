#include "Papel.hpp"

using namespace std;

void Papel::setValor(string valor){
    if(valor != "GESTOR" && valor != "DESENVOLVEDOR"){
        throw invalid_argument("Papel invalido. Valores aceitos: GESTOR, DESENVOLVEDOR.");
    }
    this->valor = valor;
}

string Papel::getValor() const {
    return valor;
}
