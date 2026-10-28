#include "Quadro.hpp"

void Quadro::setIdentificador(Identificador identificador){
    this->identificador = identificador;
}

Identificador Quadro::getIdentificador() const {
    return identificador;
}

void Quadro::setNome(Nome nome){
    this->nome = nome;
}

Nome Quadro::getNome() const {
    return nome;
}

void Quadro::setLimite(Limite limite){
    this->limite = limite;
}

Limite Quadro::getLimite() const {
    return limite;
}

void Quadro::setIdentificadorProjeto(Identificador identificadorProjeto){
    this->identificadorProjeto = identificadorProjeto;
}

Identificador Quadro::getIdentificadorProjeto() const {
    return identificadorProjeto;
}
