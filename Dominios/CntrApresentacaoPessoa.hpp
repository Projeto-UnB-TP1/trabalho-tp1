#ifndef CNTR_APRESENTACAO_PESSOA_HPP
#define CNTR_APRESENTACAO_PESSOA_HPP

#include "Interfaces.hpp"

/**
 * @class CntrApresentacaoPessoa
 * @brief Classe controladora da camada de apresentação para Pessoa.
 * 
 * Implementa a interação com o usuário via console (cin/cout) e faz a validação inicial.
 */
class CntrApresentacaoPessoa : public IApresentacaoPessoa {
private:
    IServicoPessoa* servico; // Depende apenas da interface declarada
public:
    /**
     * @brief Executa o menu de interação com o usuário.
     */
    void executar() override;

    /**
     * @brief Conecta a camada de apresentação à camada de serviço.
     * @param servico Ponteiro para a interface de serviço de pessoa.
     */
    void setServicoPessoa(IServicoPessoa* servico) override;
};

inline void CntrApresentacaoPessoa::setServicoPessoa(IServicoPessoa* servico) {
    this->servico = servico;
}

#endif // CNTR_APRESENTACAO_PESSOA_HPP