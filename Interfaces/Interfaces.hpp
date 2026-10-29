#ifndef INTERFACES_HPP
#define INTERFACES_HPP

#include <list>
#include "../Entidades/Pessoa.hpp"
#include "../Entidades/Projeto.hpp"
#include "../Entidades/Quadro.hpp"
#include "../Entidades/CartaoDeAtividade.hpp"

using namespace std;

class IServicoPessoas;
class IServicoProjetos;
class IServicoQuadros;
class IServicoCartoes;

class IApresentacaoPessoas {
    public:
        virtual bool autenticar(Email*) = 0;
        virtual void cadastrar() = 0;
        virtual void executar(Email) = 0;
        virtual void setCntrServicoPessoas(IServicoPessoas*) = 0;
        virtual ~IApresentacaoPessoas(){}
};

class IApresentacaoProjetos {
    public:
        virtual void executar(Email) = 0;
        virtual void setCntrServicoProjetos(IServicoProjetos*) = 0;
        virtual ~IApresentacaoProjetos(){}
};

class IApresentacaoQuadros {
    public:
        virtual void executar(Email) = 0;
        virtual void setCntrServicoQuadros(IServicoQuadros*) = 0;
        virtual ~IApresentacaoQuadros(){}
};

class IApresentacaoCartoes {
    public:
        virtual void executar(Email) = 0;
        virtual void setCntrServicoCartoes(IServicoCartoes*) = 0;
        virtual ~IApresentacaoCartoes(){}
};

class IServicoPessoas {
    public:
        virtual bool autenticar(Email, Senha) = 0;
        virtual bool criar(Pessoa) = 0;
        virtual bool ler(Pessoa*) = 0;
        virtual bool atualizar(Pessoa) = 0;
        virtual bool excluir(Email) = 0;
        virtual list<Email> listar() = 0;
        virtual ~IServicoPessoas(){}
};

class IServicoProjetos {
    public:
        virtual bool criar(Projeto) = 0;
        virtual bool ler(Projeto*) = 0;
        virtual bool atualizar(Projeto) = 0;
        virtual bool excluir(Identificador) = 0;
        virtual list<Identificador> listar() = 0;
        virtual ~IServicoProjetos(){}
};

class IServicoQuadros {
    public:
        virtual bool criar(Quadro) = 0;
        virtual bool ler(Quadro*) = 0;
        virtual bool atualizar(Quadro) = 0;
        virtual bool excluir(Identificador) = 0;
        virtual list<Identificador> listar(Identificador) = 0;
        virtual ~IServicoQuadros(){}
};

class IServicoCartoes {
    public:
        virtual bool criar(CartaoDeAtividade) = 0;
        virtual bool ler(CartaoDeAtividade*) = 0;
        virtual bool atualizar(CartaoDeAtividade) = 0;
        virtual bool excluir(Identificador) = 0;
        virtual list<Identificador> listar(Identificador) = 0;
        virtual bool mover(Identificador, Timestamp) = 0;
        virtual bool lerTempoCiclo(Identificador, int*) = 0;
        virtual bool lerTempoCicloMedio(Identificador, int*) = 0;
        virtual bool lerLeadTime(Identificador, int*) = 0;
        virtual bool lerLeadTimeMedio(Identificador, int*) = 0;
        virtual bool lerWIP(Identificador, int*) = 0;
        virtual ~IServicoCartoes(){}
};

#endif
