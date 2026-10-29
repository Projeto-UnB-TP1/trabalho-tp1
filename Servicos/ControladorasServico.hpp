#ifndef CONTROLADORASSERVICO_HPP
#define CONTROLADORASSERVICO_HPP

#include "../Interfaces/Interfaces.hpp"
#include "Containers.hpp"

class CntrServicoPessoas:public IServicoPessoas{
    public:
        bool autenticar(Email, Senha);
        bool criar(Pessoa);
        bool ler(Pessoa*);
        bool atualizar(Pessoa);
        bool excluir(Email);
        list<Email> listar();
};

class CntrServicoProjetos:public IServicoProjetos{
    public:
        bool criar(Projeto);
        bool ler(Projeto*);
        bool atualizar(Projeto);
        bool excluir(Identificador);
        list<Identificador> listar();
};

class CntrServicoQuadros:public IServicoQuadros{
    public:
        bool criar(Quadro);
        bool ler(Quadro*);
        bool atualizar(Quadro);
        bool excluir(Identificador);
        list<Identificador> listar(Identificador);
};

class CntrServicoCartoes:public IServicoCartoes{
    private:
        int contarFazendo(Identificador);
        int tempoCiclo(CartaoDeAtividade);
        int leadTime(CartaoDeAtividade);
    public:
        bool criar(CartaoDeAtividade);
        bool ler(CartaoDeAtividade*);
        bool atualizar(CartaoDeAtividade);
        bool excluir(Identificador);
        list<Identificador> listar(Identificador);
        bool mover(Identificador, Timestamp);
        bool lerTempoCiclo(Identificador, int*);
        bool lerTempoCicloMedio(Identificador, int*);
        bool lerLeadTime(Identificador, int*);
        bool lerLeadTimeMedio(Identificador, int*);
        bool lerWIP(Identificador, int*);
};

#endif
