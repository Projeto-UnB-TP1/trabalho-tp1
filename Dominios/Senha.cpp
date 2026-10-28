#include "Senha.hpp"
#include <stdexcept>

using namespace std;

void Senha::validar(string valor){
    if (valor.length() != TamanPermitido){
        throw invalid_argument("Senha invalida: deve ter exatamente 5 caracteres.");
    }

    bool temLetra = false;
    bool temDigito = false;

    for (unsigned int i = 0; i < valor.length(); i++){
        char c = valor[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
            temLetra = true;
        } else if (c >= '0' && c <= '9'){
            temDigito = true;
        } else {
            throw invalid_argument("Senha invalida: use apenas letras e digitos.");
        }
    }

    if (!temLetra || !temDigito){
        throw invalid_argument("Senha invalida: deve ter pelo menos uma letra e um digito.");
    }
}

void Senha::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

string Senha::getValor() const {
    return valor;
}
