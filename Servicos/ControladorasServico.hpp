#ifndef CONTROLADORASSERVICO_HPP
#define CONTROLADORASSERVICO_HPP

#include "../Interfaces/Interfaces.hpp"
#include "Containers.hpp"

///
/// Controladora do módulo de serviço de pessoas.
///
/// Realiza a interface IServicoPessoas.
///

class CntrServicoPessoas:public IServicoPessoas{
    public:
        bool autenticar(Email email, Senha senha);
        bool criar(Pessoa pessoa);
        bool ler(Pessoa *pessoa);
        bool atualizar(Pessoa pessoa);
        bool excluir(Email email);
        list<Email> listar();
};

///
/// Controladora do módulo de serviço de projetos.
///
/// Realiza a interface IServicoProjetos.
///

class CntrServicoProjetos:public IServicoProjetos{
    public:
        bool criar(Projeto projeto);
        bool ler(Projeto *projeto);
        bool atualizar(Projeto projeto);
        bool excluir(Identificador identificador);
        list<Identificador> listar();
};

///
/// Controladora do módulo de serviço de quadros.
///
/// Realiza a interface IServicoQuadros.
///

class CntrServicoQuadros:public IServicoQuadros{
    public:
        bool criar(Quadro quadro);
        bool ler(Quadro *quadro);
        bool atualizar(Quadro quadro);
        bool excluir(Identificador identificador);
        list<Identificador> listar(Identificador identificadorProjeto);
};

///
/// Controladora do módulo de serviço de cartões de atividade.
///
/// Realiza a interface IServicoCartoes.
///

class CntrServicoCartoes:public IServicoCartoes{
    private:
        int contarFazendo(Identificador identificadorQuadro);
        int tempoCiclo(CartaoDeAtividade cartao);
        int leadTime(CartaoDeAtividade cartao);
    public:
        bool criar(CartaoDeAtividade cartao);
        bool ler(CartaoDeAtividade *cartao);
        bool atualizar(CartaoDeAtividade cartao);
        bool excluir(Identificador identificador);
        list<Identificador> listar(Identificador identificadorQuadro);
        bool mover(Identificador identificador, Timestamp momento);
        bool lerTempoCiclo(Identificador identificador, int *resultado);
        bool lerTempoCicloMedio(Identificador identificadorQuadro, int *resultado);
        bool lerLeadTime(Identificador identificador, int *resultado);
        bool lerLeadTimeMedio(Identificador identificadorQuadro, int *resultado);
        bool lerWIP(Identificador identificadorQuadro, int *resultado);
};

#endif
