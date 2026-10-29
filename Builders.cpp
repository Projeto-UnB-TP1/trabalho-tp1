#include "Builders.hpp"

CntrApresentacaoControle* BuilderSistema::construir(){
    cntrApresentacaoControle = new CntrApresentacaoControle();
    cntrApresentacaoPessoas = new CntrApresentacaoPessoas();
    cntrApresentacaoProjetos = new CntrApresentacaoProjetos();
    cntrApresentacaoQuadros = new CntrApresentacaoQuadros();
    cntrApresentacaoCartoes = new CntrApresentacaoCartoes();

    cntrServicoPessoas = new CntrServicoPessoas();
    cntrServicoProjetos = new CntrServicoProjetos();
    cntrServicoQuadros = new CntrServicoQuadros();
    cntrServicoCartoes = new CntrServicoCartoes();

    cntrApresentacaoControle->setCntrApresentacaoPessoas(cntrApresentacaoPessoas);
    cntrApresentacaoControle->setCntrApresentacaoProjetos(cntrApresentacaoProjetos);
    cntrApresentacaoControle->setCntrApresentacaoQuadros(cntrApresentacaoQuadros);
    cntrApresentacaoControle->setCntrApresentacaoCartoes(cntrApresentacaoCartoes);
    cntrApresentacaoControle->setCntrServicoPessoas(cntrServicoPessoas);

    cntrApresentacaoPessoas->setCntrServicoPessoas(cntrServicoPessoas);
    cntrApresentacaoProjetos->setCntrServicoProjetos(cntrServicoProjetos);
    cntrApresentacaoProjetos->setCntrServicoPessoas(cntrServicoPessoas);
    cntrApresentacaoQuadros->setCntrServicoQuadros(cntrServicoQuadros);
    cntrApresentacaoQuadros->setCntrServicoPessoas(cntrServicoPessoas);
    cntrApresentacaoCartoes->setCntrServicoCartoes(cntrServicoCartoes);
    cntrApresentacaoCartoes->setCntrServicoPessoas(cntrServicoPessoas);

    return cntrApresentacaoControle;
}

BuilderSistema::~BuilderSistema(){
    delete cntrApresentacaoControle;
    delete cntrApresentacaoPessoas;
    delete cntrApresentacaoProjetos;
    delete cntrApresentacaoQuadros;
    delete cntrApresentacaoCartoes;
    delete cntrServicoPessoas;
    delete cntrServicoProjetos;
    delete cntrServicoQuadros;
    delete cntrServicoCartoes;
}
