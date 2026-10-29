#ifndef BUILDERS_HPP
#define BUILDERS_HPP

#include "Interfaces/Interfaces.hpp"
#include "Apresentacao/ControladorasApresentacao.hpp"
#include "Servicos/ControladorasServico.hpp"

/**
 * @file Builders.hpp
 * @brief Declaração da classe que constrói o sistema.
 */

/**
 * @brief Constrói o sistema seguindo o padrão de projeto Builder.
 *
 * @details Cria as controladoras de apresentação e de serviço e liga cada módulo de
 * apresentação aos módulos de serviço de que ele depende, por meio dos métodos set.
 * Assim, nenhuma controladora de apresentação conhece as classes concretas da camada de
 * serviço, apenas as interfaces.
 *
 * Exemplo de uso:
 * @code
 * BuilderSistema *builder = new BuilderSistema();
 * CntrApresentacaoControle *sistema = builder->construir();
 * sistema->executar();
 * delete builder;
 * @endcode
 */
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
        /**
         * @brief Cria e liga todas as controladoras do sistema.
         * @return Ponteiro para a controladora que coordena o sistema.
         */
        CntrApresentacaoControle* construir();

        /**
         * @brief Destrói todas as controladoras criadas por construir().
         */
        ~BuilderSistema();
};

#endif
