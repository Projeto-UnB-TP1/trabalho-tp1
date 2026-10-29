#ifndef CONTROLADORASSERVICO_HPP
#define CONTROLADORASSERVICO_HPP

#include "../Interfaces/Interfaces.hpp"
#include "Containers.hpp"

/**
 * @file ControladorasServico.hpp
 * @brief Declaração das classes controladoras da camada de serviço.
 *
 * @details Cada controladora realiza uma interface IServico* e implementa a lógica de
 * negócio do seu módulo, usando os contêineres para armazenar as entidades. A
 * documentação de cada método é a da interface realizada.
 */

/**
 * @brief Controladora de serviço do módulo de pessoas.
 *
 * @details Realiza IServicoPessoas (autenticação e requisitos 1 a 5) usando ContainerPessoa.
 *
 * Regras de negócio:
 * - o e-mail identifica a pessoa e não muda em uma atualização;
 * - a exclusão é recusada se a pessoa é gestora de algum projeto, para não deixar
 *   projeto sem gestor;
 * - a listagem apresenta apenas os e-mails.
 */
class CntrServicoPessoas:public IServicoPessoas{
    public:
        bool autenticar(Email email, Senha senha);
        bool criar(Pessoa pessoa);
        bool ler(Pessoa *pessoa);
        bool atualizar(Pessoa pessoa);
        bool excluir(Email email);
        list<Email> listar();
};

/**
 * @brief Controladora de serviço do módulo de projetos.
 *
 * @details Realiza IServicoProjetos (requisitos 6 a 10) usando ContainerProjeto.
 *
 * Regras de negócio:
 * - a criação é recusada se o gestor informado não está cadastrado;
 * - a atualização mantém o identificador e o gestor (o gestor é quem criou o projeto);
 * - a exclusão é recusada se o projeto possui quadros;
 * - a listagem apresenta apenas os identificadores.
 */
class CntrServicoProjetos:public IServicoProjetos{
    public:
        bool criar(Projeto projeto);
        bool ler(Projeto *projeto);
        bool atualizar(Projeto projeto);
        bool excluir(Identificador identificador);
        list<Identificador> listar();
};

/**
 * @brief Controladora de serviço do módulo de quadros.
 *
 * @details Realiza IServicoQuadros (requisitos 11 a 15) usando ContainerQuadro.
 *
 * Regras de negócio:
 * - a criação é recusada se o projeto informado não está cadastrado;
 * - a atualização mantém o identificador e o projeto do quadro;
 * - a exclusão é recusada se o quadro possui cartões de atividade;
 * - a listagem apresenta apenas os identificadores dos quadros do projeto informado.
 */
class CntrServicoQuadros:public IServicoQuadros{
    public:
        bool criar(Quadro quadro);
        bool ler(Quadro *quadro);
        bool atualizar(Quadro quadro);
        bool excluir(Identificador identificador);
        list<Identificador> listar(Identificador identificadorProjeto);
};

/**
 * @brief Controladora de serviço do módulo de cartões de atividade.
 *
 * @details Realiza IServicoCartoes (requisitos 16 a 26) usando ContainerCartao.
 *
 * Regras de negócio:
 * - o cartão é criado na coluna A FAZER e só se o quadro está cadastrado e a entrada
 *   foi informada;
 * - a atualização mantém o identificador, o quadro, o estado e os horários; esses
 *   dados só mudam pela movimentação;
 * - movimentações possíveis: A FAZER para FAZENDO (registra o início, respeitando o
 *   limite de WIP do quadro) e FAZENDO para FEITO (registra o término); o horário da
 *   movimentação não pode ser anterior ao da etapa anterior;
 * - tempo de ciclo = término - início; lead time = término - entrada; ambos em minutos
 *   e calculados apenas para cartões em FEITO; as médias consideram os cartões em FEITO
 *   do quadro;
 * - WIP = número de cartões do quadro na coluna FAZENDO.
 */
class CntrServicoCartoes:public IServicoCartoes{
    private:
        int contarFazendo(Identificador identificadorQuadro);
        int tempoCiclo(CartaoDeAtividade cartao);
        int leadTime(CartaoDeAtividade cartao);
    public:
        bool criar(CartaoDeAtividade cartao);
        bool ler(CartaoDeAtividade *cartao);
        bool atualizar(CartaoDeAtividade cartao);
        bool excluir(Identificador identificador);
        list<Identificador> listar(Identificador identificadorQuadro);
        bool mover(Identificador identificador, Timestamp momento);
        bool lerTempoCiclo(Identificador identificador, int *resultado);
        bool lerTempoCicloMedio(Identificador identificadorQuadro, int *resultado);
        bool lerLeadTime(Identificador identificador, int *resultado);
        bool lerLeadTimeMedio(Identificador identificadorQuadro, int *resultado);
        bool lerWIP(Identificador identificadorQuadro, int *resultado);
};

#endif
