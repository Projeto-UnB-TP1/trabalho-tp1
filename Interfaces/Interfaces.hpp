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

///
/// Interface do módulo de apresentação de pessoas.
///

class IApresentacaoPessoas {
    public:

///
/// Solicita e-mail e senha e autentica o usuário.
///
/// @param email Ponteiro que recebe o e-mail do usuário.
///
/// @return
///
/// - Retorna true  caso o usuário tenha sido autenticado.
/// - Retorna false caso contrário.
///

        virtual bool autenticar(Email *email) = 0;

///
/// Solicita os dados de uma nova pessoa e cadastra a pessoa.
///

        virtual void cadastrar() = 0;

///
/// Apresenta o menu de serviços sobre pessoas.
///
/// @param email E-mail do usuário autenticado.
///

        virtual void executar(Email email) = 0;

///
/// Estabelece ligação com o módulo de serviço de pessoas.
///
/// @param cntr Módulo de serviço de pessoas.
///

        virtual void setCntrServicoPessoas(IServicoPessoas *cntr) = 0;

        virtual ~IApresentacaoPessoas(){}
};

///
/// Interface do módulo de apresentação de projetos.
///

class IApresentacaoProjetos {
    public:

///
/// Apresenta o menu de serviços sobre projetos.
///
/// @param email E-mail do usuário autenticado.
///

        virtual void executar(Email email) = 0;

///
/// Estabelece ligação com o módulo de serviço de projetos.
///
/// @param cntr Módulo de serviço de projetos.
///

        virtual void setCntrServicoProjetos(IServicoProjetos *cntr) = 0;

///
/// Estabelece ligação com o módulo de serviço de pessoas.
///
/// @param cntr Módulo de serviço de pessoas.
///

        virtual void setCntrServicoPessoas(IServicoPessoas *cntr) = 0;

        virtual ~IApresentacaoProjetos(){}
};

///
/// Interface do módulo de apresentação de quadros.
///

class IApresentacaoQuadros {
    public:

///
/// Apresenta o menu de serviços sobre quadros.
///
/// @param email E-mail do usuário autenticado.
///

        virtual void executar(Email email) = 0;

///
/// Estabelece ligação com o módulo de serviço de quadros.
///
/// @param cntr Módulo de serviço de quadros.
///

        virtual void setCntrServicoQuadros(IServicoQuadros *cntr) = 0;

///
/// Estabelece ligação com o módulo de serviço de pessoas.
///
/// @param cntr Módulo de serviço de pessoas.
///

        virtual void setCntrServicoPessoas(IServicoPessoas *cntr) = 0;

        virtual ~IApresentacaoQuadros(){}
};

///
/// Interface do módulo de apresentação de cartões de atividade.
///

class IApresentacaoCartoes {
    public:

///
/// Apresenta o menu de serviços sobre cartões de atividade.
///
/// @param email E-mail do usuário autenticado.
///

        virtual void executar(Email email) = 0;

///
/// Estabelece ligação com o módulo de serviço de cartões de atividade.
///
/// @param cntr Módulo de serviço de cartões de atividade.
///

        virtual void setCntrServicoCartoes(IServicoCartoes *cntr) = 0;

///
/// Estabelece ligação com o módulo de serviço de pessoas.
///
/// @param cntr Módulo de serviço de pessoas.
///

        virtual void setCntrServicoPessoas(IServicoPessoas *cntr) = 0;

        virtual ~IApresentacaoCartoes(){}
};

///
/// Interface do módulo de serviço de pessoas.
///

class IServicoPessoas {
    public:

///
/// Autentica pessoa.
///
/// @param email E-mail.
/// @param senha Senha.
///
/// @return
///
/// - Retorna true  caso a pessoa exista e a senha esteja correta.
/// - Retorna false caso contrário.
///

        virtual bool autenticar(Email email, Senha senha) = 0;

///
/// Cria pessoa.
///
/// @param pessoa Pessoa.
///
/// @return
///
/// - Retorna true  caso a pessoa tenha sido criada.
/// - Retorna false caso já exista pessoa com o mesmo e-mail.
///

        virtual bool criar(Pessoa pessoa) = 0;

///
/// Lê pessoa.
///
/// @param pessoa Ponteiro para pessoa com o e-mail informado. Recebe os dados da pessoa.
///
/// @return
///
/// - Retorna true  caso a pessoa tenha sido encontrada.
/// - Retorna false caso contrário.
///

        virtual bool ler(Pessoa *pessoa) = 0;

///
/// Atualiza pessoa. O e-mail não é alterado.
///
/// @param pessoa Pessoa.
///
/// @return
///
/// - Retorna true  caso a pessoa tenha sido atualizada.
/// - Retorna false caso a pessoa não tenha sido encontrada.
///

        virtual bool atualizar(Pessoa pessoa) = 0;

///
/// Exclui pessoa.
///
/// @param email E-mail.
///
/// @return
///
/// - Retorna true  caso a pessoa tenha sido excluída.
/// - Retorna false caso a pessoa não tenha sido encontrada ou seja gestora de projeto.
///

        virtual bool excluir(Email email) = 0;

///
/// Lista pessoas.
///
/// @return E-mails das pessoas.
///

        virtual list<Email> listar() = 0;

        virtual ~IServicoPessoas(){}
};

///
/// Interface do módulo de serviço de projetos.
///

class IServicoProjetos {
    public:

///
/// Cria projeto.
///
/// @param projeto Projeto.
///
/// @return
///
/// - Retorna true  caso o projeto tenha sido criado.
/// - Retorna false caso o identificador já exista ou o gestor não esteja cadastrado.
///

        virtual bool criar(Projeto projeto) = 0;

///
/// Lê projeto.
///
/// @param projeto Ponteiro para projeto com o identificador informado. Recebe os dados do projeto.
///
/// @return
///
/// - Retorna true  caso o projeto tenha sido encontrado.
/// - Retorna false caso contrário.
///

        virtual bool ler(Projeto *projeto) = 0;

///
/// Atualiza projeto. O identificador e o gestor não são alterados.
///
/// @param projeto Projeto.
///
/// @return
///
/// - Retorna true  caso o projeto tenha sido atualizado.
/// - Retorna false caso o projeto não tenha sido encontrado.
///

        virtual bool atualizar(Projeto projeto) = 0;

///
/// Exclui projeto.
///
/// @param identificador Identificador.
///
/// @return
///
/// - Retorna true  caso o projeto tenha sido excluído.
/// - Retorna false caso o projeto não tenha sido encontrado ou possua quadros.
///

        virtual bool excluir(Identificador identificador) = 0;

///
/// Lista projetos.
///
/// @return Identificadores dos projetos.
///

        virtual list<Identificador> listar() = 0;

        virtual ~IServicoProjetos(){}
};

///
/// Interface do módulo de serviço de quadros.
///

class IServicoQuadros {
    public:

///
/// Cria quadro.
///
/// @param quadro Quadro.
///
/// @return
///
/// - Retorna true  caso o quadro tenha sido criado.
/// - Retorna false caso o identificador já exista ou o projeto não esteja cadastrado.
///

        virtual bool criar(Quadro quadro) = 0;

///
/// Lê quadro.
///
/// @param quadro Ponteiro para quadro com o identificador informado. Recebe os dados do quadro.
///
/// @return
///
/// - Retorna true  caso o quadro tenha sido encontrado.
/// - Retorna false caso contrário.
///

        virtual bool ler(Quadro *quadro) = 0;

///
/// Atualiza quadro. O identificador e o projeto não são alterados.
///
/// @param quadro Quadro.
///
/// @return
///
/// - Retorna true  caso o quadro tenha sido atualizado.
/// - Retorna false caso o quadro não tenha sido encontrado.
///

        virtual bool atualizar(Quadro quadro) = 0;

///
/// Exclui quadro.
///
/// @param identificador Identificador.
///
/// @return
///
/// - Retorna true  caso o quadro tenha sido excluído.
/// - Retorna false caso o quadro não tenha sido encontrado ou possua cartões.
///

        virtual bool excluir(Identificador identificador) = 0;

///
/// Lista quadros de um projeto.
///
/// @param identificadorProjeto Identificador do projeto.
///
/// @return Identificadores dos quadros.
///

        virtual list<Identificador> listar(Identificador identificadorProjeto) = 0;

        virtual ~IServicoQuadros(){}
};

///
/// Interface do módulo de serviço de cartões de atividade.
///
/// Tempos são calculados em minutos.
///

class IServicoCartoes {
    public:

///
/// Cria cartão na coluna A FAZER.
///
/// @param cartao Cartão.
///
/// @return
///
/// - Retorna true  caso o cartão tenha sido criado.
/// - Retorna false caso o identificador já exista, o quadro não esteja cadastrado ou a entrada não tenha sido informada.
///

        virtual bool criar(CartaoDeAtividade cartao) = 0;

///
/// Lê cartão.
///
/// @param cartao Ponteiro para cartão com o identificador informado. Recebe os dados do cartão.
///
/// @return
///
/// - Retorna true  caso o cartão tenha sido encontrado.
/// - Retorna false caso contrário.
///

        virtual bool ler(CartaoDeAtividade *cartao) = 0;

///
/// Atualiza cartão. O identificador, o quadro, o estado, a entrada, o início e o término não são alterados.
///
/// @param cartao Cartão.
///
/// @return
///
/// - Retorna true  caso o cartão tenha sido atualizado.
/// - Retorna false caso o cartão não tenha sido encontrado.
///

        virtual bool atualizar(CartaoDeAtividade cartao) = 0;

///
/// Exclui cartão.
///
/// @param identificador Identificador.
///
/// @return
///
/// - Retorna true  caso o cartão tenha sido excluído.
/// - Retorna false caso o cartão não tenha sido encontrado.
///

        virtual bool excluir(Identificador identificador) = 0;

///
/// Lista cartões de um quadro.
///
/// @param identificadorQuadro Identificador do quadro.
///
/// @return Identificadores dos cartões.
///

        virtual list<Identificador> listar(Identificador identificadorQuadro) = 0;

///
/// Move cartão de A FAZER para FAZENDO ou de FAZENDO para FEITO.
///
/// @param identificador Identificador.
/// @param momento Data e horário da movimentação.
///
/// @return
///
/// - Retorna true  caso o cartão tenha sido movido.
/// - Retorna false caso o cartão não tenha sido encontrado, esteja em FEITO, o limite de WIP tenha sido atingido ou o horário seja anterior ao da etapa anterior.
///

        virtual bool mover(Identificador identificador, Timestamp momento) = 0;

///
/// Lê tempo de ciclo de cartão, de FAZENDO até FEITO.
///
/// @param identificador Identificador.
/// @param resultado Ponteiro que recebe o tempo de ciclo.
///
/// @return
///
/// - Retorna true  caso o tempo tenha sido calculado.
/// - Retorna false caso o cartão não tenha sido encontrado ou não esteja em FEITO.
///

        virtual bool lerTempoCiclo(Identificador identificador, int *resultado) = 0;

///
/// Lê tempo de ciclo médio dos cartões em FEITO de um quadro.
///
/// @param identificadorQuadro Identificador do quadro.
/// @param resultado Ponteiro que recebe o tempo de ciclo médio.
///
/// @return
///
/// - Retorna true  caso o tempo tenha sido calculado.
/// - Retorna false caso o quadro não possua cartões em FEITO.
///

        virtual bool lerTempoCicloMedio(Identificador identificadorQuadro, int *resultado) = 0;

///
/// Lê lead time de cartão, de A FAZER até FEITO.
///
/// @param identificador Identificador.
/// @param resultado Ponteiro que recebe o lead time.
///
/// @return
///
/// - Retorna true  caso o tempo tenha sido calculado.
/// - Retorna false caso o cartão não tenha sido encontrado ou não esteja em FEITO.
///

        virtual bool lerLeadTime(Identificador identificador, int *resultado) = 0;

///
/// Lê lead time médio dos cartões em FEITO de um quadro.
///
/// @param identificadorQuadro Identificador do quadro.
/// @param resultado Ponteiro que recebe o lead time médio.
///
/// @return
///
/// - Retorna true  caso o tempo tenha sido calculado.
/// - Retorna false caso o quadro não possua cartões em FEITO.
///

        virtual bool lerLeadTimeMedio(Identificador identificadorQuadro, int *resultado) = 0;

///
/// Lê work in progress (WIP) de um quadro.
///
/// @param identificadorQuadro Identificador do quadro.
/// @param resultado Ponteiro que recebe a quantidade de cartões em FAZENDO.
///
/// @return
///
/// - Retorna true  caso o WIP tenha sido calculado.
/// - Retorna false caso o quadro não tenha sido encontrado.
///

        virtual bool lerWIP(Identificador identificadorQuadro, int *resultado) = 0;

        virtual ~IServicoCartoes(){}
};

#endif
