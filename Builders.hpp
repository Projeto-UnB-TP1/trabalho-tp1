#ifndef BUILDERS_HPP
#define BUILDERS_HPP

#include "Interfaces/Interfaces.hpp"
#include "Apresentacao/ControladorasApresentacao.hpp"
#include "Servicos/ControladorasServico.hpp"

class BuilderSistema{
    private:
        CntrApresentacaoControle *cntrApresentacaoControle;
        IApresentacaoPessoas *cntrApresentacaoPessoas;
        IApresentacaoProjetos *cntrApresentacaoProjetos;
        IApresentacaoQuadros *cntrApresentacaoQuadros;
        IApresentacaoCartoes *cntrApresentacaoCartoes;
        IServicoPessoas *cntrServicoPessoas;
        IServicoProjetos *cntrServicoProjetos;
        IServicoQuadros *cntrServicoQuadros;
        IServicoCartoes *cntrServicoCartoes;
    public:
        CntrApresentacaoControle* construir();
        ~BuilderSistema();
};

#endif
