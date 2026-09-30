#include "E-mail.hpp"
#include <stdexcept>

using namespace std;

static bool MinusculaDigito(char c){
    for (char i = 'a'; i <= 'z'; i++){
        if (c == i){
            return true;
        }
    }
    return false;
}

string Email::getValor(){
    return valor;
}

bool Email::validar (string valor){
    size_t arroba = valor.find('@');
    size_t lastArroba = valor.rfind('@');
    if(arroba == string::npos){
        return false;
    }
    if(arroba != lastArroba){
        return false;
    }
    string local = valor.substr(0, arroba);
    string dominio = valor.substr(arroba + 1);



}


bool Email::setValor(string valor){
    if(validar(valor)){
        this->valor=valor;
        return true;
    }
    throw invalid_argument("E-mail invalido");
}
