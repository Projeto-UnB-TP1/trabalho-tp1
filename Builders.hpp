#ifndef BUILDERS_HPP
#define BUILDERS_HPP

#include "Interfaces/Interfaces.hpp"
#include "Apresentacao/ControladorasApresentacao.hpp"
#include "Servicos/ControladorasServico.hpp"

///
/// Constrói o sistema, criando as controladoras e estabelecendo as ligações entre elas.
///

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

///
/// Cria as controladoras e estabelece as ligações entre elas.
///
/// @return Controladora que coordena o sistema.
///

        CntrApresentacaoControle* construir();

///
/// Destrói as controladoras criadas.
///

        ~BuilderSistema();
};

#endif
