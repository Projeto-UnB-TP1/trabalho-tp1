#ifndef MOCKS_HPP
#define MOCKS_HPP

#include <string>

// Mocks dos Domínios (caso também não estejam prontos)
class Estado {
private:
    std::string valor;
public:
    void setValor(std::string v) { valor = v; }
    std::string getValor() const { return valor; }
};

class Limite {
private:
    std::string valor;
public:
    void setValor(std::string v) { valor = v; }
    std::string getValor() const { return valor; }
};

class Timestamp {
public:
    static Timestamp agora() { return Timestamp(); }
};

// Mocks das Entidades
class Quadro {
private:
    Limite limite;
public:
    void setLimite(Limite l) { limite = l; }
    Limite getLimite() const { return limite; }
};

class CartaoDeAtividade {
private:
    Estado estado;
    Timestamp entrada, inicio, termino;
public:
    void setEstado(Estado e) { estado = e; }
    Estado getEstado() const { return estado; }
    
    Timestamp getEntrada() const { return entrada; }
    Timestamp getInicio() const { return inicio; }
    Timestamp getTermino() const { return termino; }
};

#endif // MOCKS_HPP