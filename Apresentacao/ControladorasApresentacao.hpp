#ifndef CONTROLADORASAPRESENTACAO_HPP
#define CONTROLADORASAPRESENTACAO_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "../Interfaces/Interfaces.hpp"

using namespace std;

class Tela{
    public:
        static string lerCampo(string);
        static int lerOpcao();
        static int converterNumero(string);
        static bool lerIdentificador(string, Identificador*);
        static bool ehGestor(IServicoPessoas*, Email);
        static string valorOuTraco(string);
        static void mostrarTempo(string, int);
        static void mostrarProjeto(Projeto);
        static void mostrarQuadro(Quadro);
        static void mostrarCartao(CartaoDeAtividade);
        static void listarIdentificadores(list<Identificador>, string);
};

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
        void executar();
        void setCntrApresentacaoPessoas(IApresentacaoPessoas*);
        void setCntrApresentacaoProjetos(IApresentacaoProjetos*);
        void setCntrApresentacaoQuadros(IApresentacaoQuadros*);
        void setCntrApresentacaoCartoes(IApresentacaoCartoes*);
        void setCntrServicoPessoas(IServicoPessoas*);
};

class CntrApresentacaoPessoas:public IApresentacaoPessoas{
    private:
        IServicoPessoas *cntr;
        void ler();
        void atualizar(Email);
        bool excluir(Email);
        void listar();
    public:
        bool autenticar(Email*);
        void cadastrar();
        void executar(Email);
        void setCntrServicoPessoas(IServicoPessoas*);
};

class CntrApresentacaoProjetos:public IApresentacaoProjetos{
    private:
        IServicoProjetos *cntr;
        IServicoPessoas *cntrServicoPessoas;
        void criar(Email);
        void ler();
        void atualizar();
        void excluir();
        void listar();
    public:
        void executar(Email);
        void setCntrServicoProjetos(IServicoProjetos*);
        void setCntrServicoPessoas(IServicoPessoas*);
};

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
        void executar(Email);
        void setCntrServicoQuadros(IServicoQuadros*);
        void setCntrServicoPessoas(IServicoPessoas*);
};

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
        void executar(Email);
        void setCntrServicoCartoes(IServicoCartoes*);
        void setCntrServicoPessoas(IServicoPessoas*);
};

#endif
