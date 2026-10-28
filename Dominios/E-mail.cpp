#include "E-mail.hpp"
#include <stdexcept>

using namespace std;

bool Email::minusculaOuDigito(char c) const {
    return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

void Email::validar(string valor){
    unsigned int tamanho = valor.length();
    unsigned int arroba = 0;
    int quantidadeArrobas = 0;

    for (unsigned int i = 0; i < tamanho; i++){
        if (valor[i] == '@'){
            arroba = i;
            quantidadeArrobas++;
        }
    }
    if (quantidadeArrobas != 1){
        throw invalid_argument("E-mail invalido: deve conter exatamente um @.");
    }

    unsigned int tamanhoLocal = arroba;
    unsigned int tamanhoDominio = tamanho - arroba - 1;
    if (tamanhoLocal == 0 || tamanhoLocal > LimiteLocal){
        throw invalid_argument("E-mail invalido: parte local deve ter de 1 a 64 caracteres.");
    }
    if (tamanhoDominio == 0 || tamanhoDominio > LimiteDominio){
        throw invalid_argument("E-mail invalido: dominio deve ter de 1 a 255 caracteres.");
    }

    for (unsigned int i = 0; i < arroba; i++){
        char c = valor[i];
        if (c == '.' || c == '-'){
            if (i == 0 || i == arroba - 1 || !minusculaOuDigito(valor[i + 1])){
                throw invalid_argument("E-mail invalido: ponto ou hifen da parte local deve ficar entre letras ou digitos.");
            }
        } else if (!minusculaOuDigito(c)){
            throw invalid_argument("E-mail invalido: parte local aceita letras minusculas, digitos, ponto e hifen.");
        }
    }

    for (unsigned int i = arroba + 1; i < tamanho; i++){
        char c = valor[i];
        bool inicioParte = (i == arroba + 1 || valor[i - 1] == '.');
        bool fimParte = (i == tamanho - 1 || valor[i + 1] == '.');
        if (c == '.'){
            if (inicioParte || i == tamanho - 1){
                throw invalid_argument("E-mail invalido: partes do dominio nao podem ser vazias.");
            }
        } else if (c == '-'){
            if (inicioParte || fimParte){
                throw invalid_argument("E-mail invalido: parte do dominio nao pode iniciar ou terminar com hifen.");
            }
        } else if (!minusculaOuDigito(c)){
            throw invalid_argument("E-mail invalido: dominio aceita letras minusculas, digitos, ponto e hifen.");
        }
    }
}

void Email::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

string Email::getValor() const {
    return valor;
}
