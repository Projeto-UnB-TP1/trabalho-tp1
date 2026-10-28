#ifndef CONTAINERS_HPP
#define CONTAINERS_HPP

#include <list>
#include "../Entidades/Pessoa.hpp"
#include "../Entidades/Projeto.hpp"
#include "../Entidades/Quadro.hpp"
#include "../Entidades/CartaoDeAtividade.hpp"

using namespace std;

class ContainerPessoa{
    private:
        list<Pessoa> container;
        static ContainerPessoa *instancia;
        ContainerPessoa(){};
    public:
        static ContainerPessoa* getInstancia();
        bool incluir(Pessoa);
        bool remover(Email);
        bool pesquisar(Pessoa*);
        bool atualizar(Pessoa);
        list<Pessoa> listar();
};

class ContainerProjeto{
    private:
        list<Projeto> container;
        static ContainerProjeto *instancia;
        ContainerProjeto(){};
    public:
        static ContainerProjeto* getInstancia();
        bool incluir(Projeto);
        bool remover(Identificador);
        bool pesquisar(Projeto*);
        bool atualizar(Projeto);
        list<Projeto> listar();
};

class ContainerQuadro{
    private:
        list<Quadro> container;
        static ContainerQuadro *instancia;
        ContainerQuadro(){};
    public:
        static ContainerQuadro* getInstancia();
        bool incluir(Quadro);
        bool remover(Identificador);
        bool pesquisar(Quadro*);
        bool atualizar(Quadro);
        list<Quadro> listar();
};

class ContainerCartao{
    private:
        list<CartaoDeAtividade> container;
        static ContainerCartao *instancia;
        ContainerCartao(){};
    public:
        static ContainerCartao* getInstancia();
        bool incluir(CartaoDeAtividade);
        bool remover(Identificador);
        bool pesquisar(CartaoDeAtividade*);
        bool atualizar(CartaoDeAtividade);
        list<CartaoDeAtividade> listar();
};

#endif
