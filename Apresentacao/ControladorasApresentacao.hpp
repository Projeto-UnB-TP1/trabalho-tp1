#ifndef CONTROLADORASAPRESENTACAO_HPP
#define CONTROLADORASAPRESENTACAO_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "../Interfaces/Interfaces.hpp"

using namespace std;

///
/// Métodos de apoio à leitura de dados e à apresentação de entidades na tela.
///

class Tela{
    public:

///
/// Apresenta rótulo e lê linha digitada.
///
/// @param rotulo Rótulo.
///
/// @return Texto digitado.
///

        static string lerCampo(string rotulo);

///
/// Lê opção de menu.
///
/// @return
///
/// - Retorna a opção, de 0 a 9.
/// - Retorna -1 caso o texto digitado não seja um dígito.
/// - Retorna 0 caso a entrada tenha terminado.
///

        static int lerOpcao();

///
/// Converte texto de até 3 dígitos em número.
///
/// @param texto Texto.
///
/// @return Número. Retorna 0 caso o texto seja inválido.
///

        static int converterNumero(string texto);

///
/// Lê identificador.
///
/// @param rotulo Rótulo.
/// @param identificador Ponteiro que recebe o identificador.
///
/// @return
///
/// - Retorna true  caso o identificador seja válido.
/// - Retorna false caso contrário.
///

        static bool lerIdentificador(string rotulo, Identificador *identificador);

///
/// Verifica se pessoa tem papel GESTOR.
///
/// @param cntr Módulo de serviço de pessoas.
/// @param email E-mail da pessoa.
///
/// @return
///
/// - Retorna true  caso a pessoa seja GESTOR.
/// - Retorna false caso contrário.
///

        static bool ehGestor(IServicoPessoas *cntr, Email email);

///
/// Retorna o texto ou um traço caso o texto esteja vazio.
///
/// @param valor Texto.
///
/// @return Texto ou traço.
///

        static string valorOuTraco(string valor);

///
/// Apresenta tempo em dias, horas e minutos.
///
/// @param rotulo Rótulo.
/// @param minutos Tempo em minutos.
///

        static void mostrarTempo(string rotulo, int minutos);

///
/// Apresenta dados de projeto.
///
/// @param projeto Projeto.
///

        static void mostrarProjeto(Projeto projeto);

///
/// Apresenta dados de quadro.
///
/// @param quadro Quadro.
///

        static void mostrarQuadro(Quadro quadro);

///
/// Apresenta dados de cartão de atividade.
///
/// @param cartao Cartão.
///

        static void mostrarCartao(CartaoDeAtividade cartao);

///
/// Apresenta lista de identificadores.
///
/// @param identificadores Identificadores.
/// @param vazio Mensagem apresentada caso a lista esteja vazia.
///

        static void listarIdentificadores(list<Identificador> identificadores, string vazio);
};

///
/// Controladora que coordena o sistema.
///
/// Apresenta a tela inicial e, após a autenticação, o menu principal.
///

class CntrApresentacaoControle{
    private:
        Email email;
        IApresentacaoPessoas *cntrApresentacaoPessoas;
        IApresentacaoProjetos *cntrApresentacaoProjetos;
        IApresentacaoQuadros *cntrApresentacaoQuadros;
        IApresentacaoCartoes *cntrApresentacaoCartoes;
        IServicoPessoas *cntrServicoPessoas;
        void executarSessao();
    public:

///
/// Apresenta a tela inicial.
///

        void executar();

///
/// Estabelece ligação com o módulo de apresentação de pessoas.
///
/// @param cntr Módulo de apresentação de pessoas.
///

        void setCntrApresentacaoPessoas(IApresentacaoPessoas *cntr);

///
/// Estabelece ligação com o módulo de apresentação de projetos.
///
/// @param cntr Módulo de apresentação de projetos.
///

        void setCntrApresentacaoProjetos(IApresentacaoProjetos *cntr);

///
/// Estabelece ligação com o módulo de apresentação de quadros.
///
/// @param cntr Módulo de apresentação de quadros.
///

        void setCntrApresentacaoQuadros(IApresentacaoQuadros *cntr);

///
/// Estabelece ligação com o módulo de apresentação de cartões de atividade.
///
/// @param cntr Módulo de apresentação de cartões de atividade.
///

        void setCntrApresentacaoCartoes(IApresentacaoCartoes *cntr);

///
/// Estabelece ligação com o módulo de serviço de pessoas.
///
/// @param cntr Módulo de serviço de pessoas.
///

        void setCntrServicoPessoas(IServicoPessoas *cntr);
};

///
/// Controladora do módulo de apresentação de pessoas.
///
/// Realiza a interface IApresentacaoPessoas.
///

class CntrApresentacaoPessoas:public IApresentacaoPessoas{
    private:
        IServicoPessoas *cntr;
        void ler();
        void atualizar(Email email);
        bool excluir(Email email);
        void listar();
    public:
        bool autenticar(Email *email);
        void cadastrar();
        void executar(Email email);
        void setCntrServicoPessoas(IServicoPessoas *cntr);
};

///
/// Controladora do módulo de apresentação de projetos.
///
/// Realiza a interface IApresentacaoProjetos.
///

class CntrApresentacaoProjetos:public IApresentacaoProjetos{
    private:
        IServicoProjetos *cntr;
        IServicoPessoas *cntrServicoPessoas;
        void criar(Email email);
        void ler();
        void atualizar();
        void excluir();
        void listar();
    public:
        void executar(Email email);
        void setCntrServicoProjetos(IServicoProjetos *cntr);
        void setCntrServicoPessoas(IServicoPessoas *cntr);
};

///
/// Controladora do módulo de apresentação de quadros.
///
/// Realiza a interface IApresentacaoQuadros.
///

class CntrApresentacaoQuadros:public IApresentacaoQuadros{
    private:
        IServicoQuadros *cntr;
        IServicoPessoas *cntrServicoPessoas;
        void criar();
        void ler();
        void atualizar();
        void excluir();
        void listar();
    public:
        void executar(Email email);
        void setCntrServicoQuadros(IServicoQuadros *cntr);
        void setCntrServicoPessoas(IServicoPessoas *cntr);
};

///
/// Controladora do módulo de apresentação de cartões de atividade.
///
/// Realiza a interface IApresentacaoCartoes.
///

class CntrApresentacaoCartoes:public IApresentacaoCartoes{
    private:
        IServicoCartoes *cntr;
        IServicoPessoas *cntrServicoPessoas;
        void criar();
        void ler();
        void atualizar();
        void excluir();
        void listar();
        void mover();
        void executarMetricas();
        void lerTempoCiclo();
        void lerTempoCicloMedio();
        void lerLeadTime();
        void lerLeadTimeMedio();
        void lerWIP();
    public:
        void executar(Email email);
        void setCntrServicoCartoes(IServicoCartoes *cntr);
        void setCntrServicoPessoas(IServicoPessoas *cntr);
};

#endif
