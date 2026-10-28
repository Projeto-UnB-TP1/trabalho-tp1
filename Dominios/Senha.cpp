#include "Senha.hpp"
#include <stdexcept>
#include <cctype>

using namespace std;

string Senha::getValor(){
    return valor;
}

bool Senha::validar(string valor){
    if (valor.length() != TamanPermitido) {
        return false;
    }
    bool temLetra = false;
    bool temDigito = false;

    for (char c : valor) {
        if (isalpha(static_cast<unsigned char>(c))) {
            temLetra = true;
        } else if (isdigit(static_cast<unsigned char>(c))) {
            temDigito = true;
        }
        else {
            return false;
        }
    }
    if (temLetra && temDigito) {
        return true;
    } else {
        return false;
    }
}
bool Senha::setValor(string valor){
    if (validar(valor)){
        this->valor = valor;
        return true;
    }
    throw invalid_argument("Senha invalida");
}
