#include "Prioridade.hpp"
#include <stdexcept>


void Prioridade::setValor(std::string valor){
    if(valor!= "ALTA" && valor != "MEDIA" && valor != "BAIXA"){
        throw std:: invalid_argument("Prioridade invalida");
    } 
    this->valor = valor;
}

std:: string Prioridade:: getValor(){
    return valor;
}