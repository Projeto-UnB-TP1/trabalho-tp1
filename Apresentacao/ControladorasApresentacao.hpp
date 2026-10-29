#ifndef CONTROLADORASAPRESENTACAO_HPP
#define CONTROLADORASAPRESENTACAO_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "../Interfaces/Interfaces.hpp"

using namespace std;

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

inline void CntrApresentacaoControle::setCntrApresentacaoPessoas(IApresentacaoPessoas *cntr){
    cntrApresentacaoPessoas = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoProjetos(IApresentacaoProjetos *cntr){
    cntrApresentacaoProjetos = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoQuadros(IApresentacaoQuadros *cntr){
    cntrApresentacaoQuadros = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoCartoes(IApresentacaoCartoes *cntr){
    cntrApresentacaoCartoes = cntr;
}

inline void CntrApresentacaoControle::setCntrServicoPessoas(IServicoPessoas *cntr){
    cntrServicoPessoas = cntr;
}

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

inline void CntrApresentacaoPessoas::setCntrServicoPessoas(IServicoPessoas *cntr){
    this->cntr = cntr;
}

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

inline void CntrApresentacaoProjetos::setCntrServicoProjetos(IServicoProjetos *cntr){
    this->cntr = cntr;
}

inline void CntrApresentacaoProjetos::setCntrServicoPessoas(IServicoPessoas *cntr){
    cntrServicoPessoas = cntr;
}

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

inline void CntrApresentacaoQuadros::setCntrServicoQuadros(IServicoQuadros *cntr){
    this->cntr = cntr;
}

inline void CntrApresentacaoQuadros::setCntrServicoPessoas(IServicoPessoas *cntr){
    cntrServicoPessoas = cntr;
}

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

inline void CntrApresentacaoCartoes::setCntrServicoCartoes(IServicoCartoes *cntr){
    this->cntr = cntr;
}

inline void CntrApresentacaoCartoes::setCntrServicoPessoas(IServicoPessoas *cntr){
    cntrServicoPessoas = cntr;
}

#endif
