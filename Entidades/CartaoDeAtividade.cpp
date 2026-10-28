#include "CartaoDeAtividade.hpp"

void CartaoDeAtividade::setIdentificador(Identificador identificador){
    this->identificador = identificador;
}

Identificador CartaoDeAtividade::getIdentificador() const {
    return identificador;
}

void CartaoDeAtividade::setNome(Nome nome){
    this->nome = nome;
}

Nome CartaoDeAtividade::getNome() const {
    return nome;
}

void CartaoDeAtividade::setDescricao(Texto descricao){
    this->descricao = descricao;
}

Texto CartaoDeAtividade::getDescricao() const {
    return descricao;
}

void CartaoDeAtividade::setPrioridade(Prioridade prioridade){
    this->prioridade = prioridade;
}

Prioridade CartaoDeAtividade::getPrioridade() const {
    return prioridade;
}

void CartaoDeAtividade::setEstado(Estado estado){
    this->estado = estado;
}

Estado CartaoDeAtividade::getEstado() const {
    return estado;
}

void CartaoDeAtividade::setTamanho(Tamanho tamanho){
    this->tamanho = tamanho;
}

Tamanho CartaoDeAtividade::getTamanho() const {
    return tamanho;
}

void CartaoDeAtividade::setEntrada(Timestamp entrada){
    this->entrada = entrada;
}

Timestamp CartaoDeAtividade::getEntrada() const {
    return entrada;
}

void CartaoDeAtividade::setInicio(Timestamp inicio){
    this->inicio = inicio;
}

Timestamp CartaoDeAtividade::getInicio() const {
    return inicio;
}

void CartaoDeAtividade::setTermino(Timestamp termino){
    this->termino = termino;
}

Timestamp CartaoDeAtividade::getTermino() const {
    return termino;
}

void CartaoDeAtividade::setIdentificadorQuadro(Identificador identificadorQuadro){
    this->identificadorQuadro = identificadorQuadro;
}

Identificador CartaoDeAtividade::getIdentificadorQuadro() const {
    return identificadorQuadro;
}
