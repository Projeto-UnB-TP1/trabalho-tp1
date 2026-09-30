#ifndef INTERFACES_HPP
#define INTERFACES_HPP

#include "Dominios.hpp" // Assuma que este header inclui as suas classes de domínio
#include "Entidades.hpp" // Assuma que este header inclui as suas classes de entidade

/**
 * @class IServicoPessoa
 * @brief Interface para a camada de serviço referente à entidade Pessoa.
 * 
 * Especifica os serviços providos pela camada de negócio que a apresentação pode usar.
 */
class IServicoPessoa {
public:
    virtual bool criarPessoa(const Pessoa& pessoa) = 0;
    virtual bool autenticar(const Email& email, const Senha& senha) = 0;
    virtual ~IServicoPessoa() {}
};

/**
 * @class IApresentacaoPessoa
 * @brief Interface para a camada de apresentação referente à entidade Pessoa.
 */
class IApresentacaoPessoa {
public:
    virtual void executar() = 0;
    virtual void setServicoPessoa(IServicoPessoa* servico) = 0;
    virtual ~IApresentacaoPessoa() {}
};

#endif // INTERFACES_HPP