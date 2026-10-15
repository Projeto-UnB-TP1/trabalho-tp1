#include "E-mail.hpp"
#include <stdexcept>

using namespace std;

static bool MinusculaDigito(char c){
    for (char i = 'a'; i <= 'z'; i++){
        if (c == i){
            return true;
        }
    }
    for (char i = '0'; i <= '9'; i++){
        if (c == i){
            return true;
        }
    }
    return false;
}

string Email::getValor(){
    return valor;
}

bool Email::validar(string valor){
    
    // Etapa 1: dividir em parte local e domínio
    size_t arroba = valor.find('@');
    size_t lastArroba = valor.rfind('@');
    if (arroba == string::npos){
        return false;
    }
    if (arroba != lastArroba){
        return false;
    }
    string local = valor.substr(0, arroba);
    string dominio = valor.substr(arroba + 1);

    // Tamanhos e vazios
    if (local.length() > LimiteLocal || dominio.length() > LimiteDominio){
        return false;
    }
    if (local.empty() || dominio.empty()){
        return false;
    }

    // Etapa 2: parte local
    for (size_t i = 0; i < local.size(); i++){
        char c = local[i];

        if (MinusculaDigito(c)){
            continue;
        }

        if (c == '.' || c == '-'){
            if (i == 0 || i == local.size() - 1){
                return false;
            }
            if (!MinusculaDigito(local[i + 1])){
                return false;
            }
        }
        else {
            return false;
        }
    }

    // Etapa 3: domínio
    size_t inicio = 0;
    while (true){
        size_t ponto = dominio.find('.', inicio);

        string parte;
        if (ponto == string::npos){
            parte = dominio.substr(inicio);
        } else {
            parte = dominio.substr(inicio, ponto - inicio);
        }

        if (parte.empty()){
            return false;
        }
        if (parte[0] == '-' || parte[parte.size() - 1] == '-'){
            return false;
        }
        for (char c : parte){
            if (!MinusculaDigito(c) && c != '-'){
                return false;
            }
        }

        if (ponto == string::npos){
            break;
        }
        inicio = ponto + 1;
    }

    return true;
}

bool Email::setValor(string valor){
    if (validar(valor)){
        this->valor = valor;
        return true;
    }
    throw invalid_argument("E-mail invalido");
}
