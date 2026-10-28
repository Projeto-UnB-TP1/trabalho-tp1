#include "Prioridade.hpp"

using namespace std;

void Prioridade::setValor(string valor){
    if(valor != "ALTA" && valor != "MEDIA" && valor != "BAIXA"){
        throw invalid_argument("Prioridade invalida. Valores aceitos: ALTA, MEDIA, BAIXA.");
    }
    this->valor = valor;
}

string Prioridade::getValor() const {
    return valor;
}
