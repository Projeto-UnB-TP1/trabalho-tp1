#ifndef INTERFACES_HPP
#define INTERFACES_HPP

#include <list>
#include "../Entidades/Pessoa.hpp"
#include "../Entidades/Projeto.hpp"
#include "../Entidades/Quadro.hpp"
#include "../Entidades/CartaoDeAtividade.hpp"

using namespace std;

/**
 * @file Interfaces.hpp
 * @brief Declaração das interfaces entre os módulos do sistema.
 *
 * @details O sistema adota o estilo de arquitetura em camadas, com uma camada de
 * apresentação e uma camada de serviço. Cada camada é dividida nos módulos
 * Pessoas, Projetos, Quadros e Cartões de atividade. Os módulos interagem apenas por
 * meio das interfaces declaradas neste arquivo, que são classes protocolo: não têm
 * atributos nem construtores, têm destrutor virtual e são compostas por métodos
 * virtuais puros.
 *
 * - As interfaces IApresentacao* especificam os serviços providos pelos módulos de
 *   apresentação (interação com o usuário).
 * - As interfaces IServico* especificam os serviços providos pelos módulos de serviço
 *   (lógica de negócio e armazenamento). A camada de apresentação depende somente
 *   dessas interfaces.
 */

class IServicoPessoas;
class IServicoProjetos;
class IServicoQuadros;
class IServicoCartoes;

/**
 * @brief Interface do módulo de apresentação de pessoas.
 *
 * @details Especifica a interação com o usuário para autenticação, criação de conta e
 * os serviços sobre pessoas (requisitos 1 a 5).
 */
class IApresentacaoPessoas {
    public:
        /**
         * @brief Solicita e-mail e senha ao usuário e pede a autenticação ao serviço.
         * @param email Ponteiro onde é armazenado o e-mail informado pelo usuário.
         * @return true se o usuário foi autenticado; false caso contrário.
         */
        virtual bool autenticar(Email *email) = 0;

        /**
         * @brief Solicita os dados de uma nova pessoa e pede a sua criação (requisito 1).
         */
        virtual void cadastrar() = 0;

        /**
         * @brief Apresenta o menu de serviços sobre pessoas (requisitos 2 a 5).
         * @param email E-mail do usuário autenticado.
         */
        virtual void executar(Email email) = 0;

        /**
         * @brief Define o módulo de serviço de pessoas usado por este módulo.
         * @param cntr Ponteiro para o serviço de pessoas.
         */
        virtual void setCntrServicoPessoas(IServicoPessoas *cntr) = 0;

        /** @brief Destrutor virtual. */
        virtual ~IApresentacaoPessoas(){}
};

/**
 * @brief Interface do módulo de apresentação de projetos.
 *
 * @details Especifica a interação com o usuário para os serviços sobre projetos
 * (requisitos 6 a 10). As opções de criar, atualizar e excluir são apresentadas somente
 * a usuários com papel GESTOR.
 */
class IApresentacaoProjetos {
    public:
        /**
         * @brief Apresenta o menu de serviços sobre projetos.
         * @param email E-mail do usuário autenticado.
         */
        virtual void executar(Email email) = 0;

        /**
         * @brief Define o módulo de serviço de projetos usado por este módulo.
         * @param cntr Ponteiro para o serviço de projetos.
         */
        virtual void setCntrServicoProjetos(IServicoProjetos *cntr) = 0;

        /**
         * @brief Define o módulo de serviço de pessoas, usado para consultar o papel do usuário.
         * @param cntr Ponteiro para o serviço de pessoas.
         */
        virtual void setCntrServicoPessoas(IServicoPessoas *cntr) = 0;

        /** @brief Destrutor virtual. */
        virtual ~IApresentacaoProjetos(){}
};

/**
 * @brief Interface do módulo de apresentação de quadros.
 *
 * @details Especifica a interação com o usuário para os serviços sobre quadros
 * (requisitos 11 a 15). As opções de criar, atualizar e excluir são apresentadas somente
 * a usuários com papel GESTOR.
 */
class IApresentacaoQuadros {
    public:
        /**
         * @brief Apresenta o menu de serviços sobre quadros.
         * @param email E-mail do usuário autenticado.
         */
        virtual void executar(Email email) = 0;

        /**
         * @brief Define o módulo de serviço de quadros usado por este módulo.
         * @param cntr Ponteiro para o serviço de quadros.
         */
        virtual void setCntrServicoQuadros(IServicoQuadros *cntr) = 0;

        /**
         * @brief Define o módulo de serviço de pessoas, usado para consultar o papel do usuário.
         * @param cntr Ponteiro para o serviço de pessoas.
         */
        virtual void setCntrServicoPessoas(IServicoPessoas *cntr) = 0;

        /** @brief Destrutor virtual. */
        virtual ~IApresentacaoQuadros(){}
};

/**
 * @brief Interface do módulo de apresentação de cartões de atividade.
 *
 * @details Especifica a interação com o usuário para os serviços sobre cartões de
 * atividade, a movimentação entre colunas e as métricas Kanban (requisitos 16 a 26).
 * As opções de criar, atualizar e excluir são apresentadas somente a usuários com
 * papel GESTOR.
 */
class IApresentacaoCartoes {
    public:
        /**
         * @brief Apresenta o menu de serviços sobre cartões de atividade.
         * @param email E-mail do usuário autenticado.
         */
        virtual void executar(Email email) = 0;

        /**
         * @brief Define o módulo de serviço de cartões usado por este módulo.
         * @param cntr Ponteiro para o serviço de cartões.
         */
        virtual void setCntrServicoCartoes(IServicoCartoes *cntr) = 0;

        /**
         * @brief Define o módulo de serviço de pessoas, usado para consultar o papel do usuário.
         * @param cntr Ponteiro para o serviço de pessoas.
         */
        virtual void setCntrServicoPessoas(IServicoPessoas *cntr) = 0;

        /** @brief Destrutor virtual. */
        virtual ~IApresentacaoCartoes(){}
};

/**
 * @brief Interface do módulo de serviço de pessoas.
 *
 * @details Especifica a autenticação e os serviços de criar, ler, atualizar, excluir e
 * listar pessoas (requisitos 1 a 5). A pessoa é identificada pelo e-mail, que não pode
 * ser alterado.
 */
class IServicoPessoas {
    public:
        /**
         * @brief Verifica se existe pessoa com o e-mail informado e se a senha confere.
         * @param email E-mail da pessoa.
         * @param senha Senha informada.
         * @return true se a pessoa existe e a senha confere; false caso contrário.
         */
        virtual bool autenticar(Email email, Senha senha) = 0;

        /**
         * @brief Cria uma pessoa (requisito 1).
         * @param pessoa Pessoa a ser criada.
         * @return true se a pessoa foi criada; false se já existe pessoa com o mesmo e-mail.
         */
        virtual bool criar(Pessoa pessoa) = 0;

        /**
         * @brief Lê os dados de uma pessoa (requisito 2).
         * @param pessoa Ponteiro para uma pessoa com o e-mail preenchido; recebe os dados lidos.
         * @return true se a pessoa foi encontrada; false caso contrário.
         */
        virtual bool ler(Pessoa *pessoa) = 0;

        /**
         * @brief Atualiza os dados de uma pessoa (requisito 3).
         * @param pessoa Pessoa com os novos dados; o e-mail identifica a pessoa e não é alterado.
         * @return true se a pessoa foi atualizada; false se não foi encontrada.
         */
        virtual bool atualizar(Pessoa pessoa) = 0;

        /**
         * @brief Exclui uma pessoa (requisito 4).
         * @param email E-mail da pessoa.
         * @return true se a pessoa foi excluída; false se não foi encontrada ou se é gestora
         *         de algum projeto.
         */
        virtual bool excluir(Email email) = 0;

        /**
         * @brief Lista as pessoas cadastradas (requisito 5).
         * @return Lista com o e-mail de cada pessoa.
         */
        virtual list<Email> listar() = 0;

        /** @brief Destrutor virtual. */
        virtual ~IServicoPessoas(){}
};

/**
 * @brief Interface do módulo de serviço de projetos.
 *
 * @details Especifica os serviços de criar, ler, atualizar, excluir e listar projetos
 * (requisitos 6 a 10). O projeto é identificado pelo identificador, que não pode ser
 * alterado, e tem por gestor a pessoa que o criou.
 */
class IServicoProjetos {
    public:
        /**
         * @brief Cria um projeto (requisito 6).
         * @param projeto Projeto a ser criado, com o e-mail do gestor preenchido.
         * @return true se o projeto foi criado; false se o identificador já existe ou se o
         *         gestor não está cadastrado.
         */
        virtual bool criar(Projeto projeto) = 0;

        /**
         * @brief Lê os dados de um projeto (requisito 7).
         * @param projeto Ponteiro para um projeto com o identificador preenchido; recebe os
         *        dados lidos.
         * @return true se o projeto foi encontrado; false caso contrário.
         */
        virtual bool ler(Projeto *projeto) = 0;

        /**
         * @brief Atualiza os dados de um projeto (requisito 8).
         * @param projeto Projeto com os novos dados; o identificador e o gestor não são alterados.
         * @return true se o projeto foi atualizado; false se não foi encontrado.
         */
        virtual bool atualizar(Projeto projeto) = 0;

        /**
         * @brief Exclui um projeto (requisito 9).
         * @param identificador Identificador do projeto.
         * @return true se o projeto foi excluído; false se não foi encontrado ou se possui quadros.
         */
        virtual bool excluir(Identificador identificador) = 0;

        /**
         * @brief Lista os projetos cadastrados (requisito 10).
         * @return Lista com o identificador de cada projeto.
         */
        virtual list<Identificador> listar() = 0;

        /** @brief Destrutor virtual. */
        virtual ~IServicoProjetos(){}
};

/**
 * @brief Interface do módulo de serviço de quadros.
 *
 * @details Especifica os serviços de criar, ler, atualizar, excluir e listar quadros
 * (requisitos 11 a 15). O quadro é identificado pelo identificador, que não pode ser
 * alterado, e pertence a um projeto.
 */
class IServicoQuadros {
    public:
        /**
         * @brief Cria um quadro (requisito 11).
         * @param quadro Quadro a ser criado, com o identificador do projeto preenchido.
         * @return true se o quadro foi criado; false se o identificador já existe ou se o
         *         projeto não está cadastrado.
         */
        virtual bool criar(Quadro quadro) = 0;

        /**
         * @brief Lê os dados de um quadro (requisito 12).
         * @param quadro Ponteiro para um quadro com o identificador preenchido; recebe os
         *        dados lidos.
         * @return true se o quadro foi encontrado; false caso contrário.
         */
        virtual bool ler(Quadro *quadro) = 0;

        /**
         * @brief Atualiza os dados de um quadro (requisito 13).
         * @param quadro Quadro com os novos dados; o identificador e o projeto não são alterados.
         * @return true se o quadro foi atualizado; false se não foi encontrado.
         */
        virtual bool atualizar(Quadro quadro) = 0;

        /**
         * @brief Exclui um quadro (requisito 14).
         * @param identificador Identificador do quadro.
         * @return true se o quadro foi excluído; false se não foi encontrado ou se possui
         *         cartões de atividade.
         */
        virtual bool excluir(Identificador identificador) = 0;

        /**
         * @brief Lista os quadros de um projeto (requisito 15).
         * @param identificadorProjeto Identificador do projeto.
         * @return Lista com o identificador de cada quadro do projeto.
         */
        virtual list<Identificador> listar(Identificador identificadorProjeto) = 0;

        /** @brief Destrutor virtual. */
        virtual ~IServicoQuadros(){}
};

/**
 * @brief Interface do módulo de serviço de cartões de atividade.
 *
 * @details Especifica os serviços de criar, ler, atualizar, excluir e listar cartões
 * (requisitos 16 a 20), a movimentação entre as colunas do quadro (requisito 21) e o
 * cálculo das métricas Kanban (requisitos 22 a 26). Os tempos são informados em minutos.
 */
class IServicoCartoes {
    public:
        /**
         * @brief Cria um cartão de atividade na coluna A FAZER (requisito 16).
         * @param cartao Cartão a ser criado, com o identificador do quadro e a entrada preenchidos.
         * @return true se o cartão foi criado; false se o identificador já existe, se o quadro
         *         não está cadastrado ou se a entrada não foi informada.
         */
        virtual bool criar(CartaoDeAtividade cartao) = 0;

        /**
         * @brief Lê os dados de um cartão de atividade (requisito 17).
         * @param cartao Ponteiro para um cartão com o identificador preenchido; recebe os
         *        dados lidos.
         * @return true se o cartão foi encontrado; false caso contrário.
         */
        virtual bool ler(CartaoDeAtividade *cartao) = 0;

        /**
         * @brief Atualiza os dados de um cartão de atividade (requisito 18).
         * @param cartao Cartão com os novos dados; o identificador, o quadro, o estado e os
         *        horários de entrada, início e término não são alterados.
         * @return true se o cartão foi atualizado; false se não foi encontrado.
         */
        virtual bool atualizar(CartaoDeAtividade cartao) = 0;

        /**
         * @brief Exclui um cartão de atividade (requisito 19).
         * @param identificador Identificador do cartão.
         * @return true se o cartão foi excluído; false se não foi encontrado.
         */
        virtual bool excluir(Identificador identificador) = 0;

        /**
         * @brief Lista os cartões de atividade de um quadro (requisito 20).
         * @param identificadorQuadro Identificador do quadro.
         * @return Lista com o identificador de cada cartão do quadro.
         */
        virtual list<Identificador> listar(Identificador identificadorQuadro) = 0;

        /**
         * @brief Move um cartão para a próxima coluna do quadro (requisito 21).
         *
         * @details As movimentações possíveis são A FAZER para FAZENDO, que registra o
         * início, e FAZENDO para FEITO, que registra o término. A entrada em FAZENDO respeita
         * o limite de WIP do quadro.
         * @param identificador Identificador do cartão.
         * @param momento Data e horário da movimentação.
         * @return true se o cartão foi movido; false se não foi encontrado, se já está em FEITO,
         *         se o quadro atingiu o limite de WIP ou se o horário é anterior ao da etapa anterior.
         */
        virtual bool mover(Identificador identificador, Timestamp momento) = 0;

        /**
         * @brief Lê o tempo de ciclo de um cartão: de FAZENDO até FEITO (requisito 22).
         * @param identificador Identificador do cartão.
         * @param resultado Ponteiro que recebe o tempo de ciclo, em minutos.
         * @return true se o tempo foi calculado; false se o cartão não foi encontrado ou não
         *         está em FEITO.
         */
        virtual bool lerTempoCiclo(Identificador identificador, int *resultado) = 0;

        /**
         * @brief Lê o tempo de ciclo médio dos cartões em FEITO de um quadro (requisito 23).
         * @param identificadorQuadro Identificador do quadro.
         * @param resultado Ponteiro que recebe o tempo de ciclo médio, em minutos.
         * @return true se o tempo foi calculado; false se o quadro não tem cartões em FEITO.
         */
        virtual bool lerTempoCicloMedio(Identificador identificadorQuadro, int *resultado) = 0;

        /**
         * @brief Lê o lead time de um cartão: de A FAZER até FEITO (requisito 24).
         * @param identificador Identificador do cartão.
         * @param resultado Ponteiro que recebe o lead time, em minutos.
         * @return true se o tempo foi calculado; false se o cartão não foi encontrado ou não
         *         está em FEITO.
         */
        virtual bool lerLeadTime(Identificador identificador, int *resultado) = 0;

        /**
         * @brief Lê o lead time médio dos cartões em FEITO de um quadro (requisito 25).
         * @param identificadorQuadro Identificador do quadro.
         * @param resultado Ponteiro que recebe o lead time médio, em minutos.
         * @return true se o tempo foi calculado; false se o quadro não tem cartões em FEITO.
         */
        virtual bool lerLeadTimeMedio(Identificador identificadorQuadro, int *resultado) = 0;

        /**
         * @brief Lê o work in progress (WIP) de um quadro (requisito 26).
         * @param identificadorQuadro Identificador do quadro.
         * @param resultado Ponteiro que recebe o número de cartões na coluna FAZENDO.
         * @return true se o WIP foi calculado; false se o quadro não foi encontrado.
         */
        virtual bool lerWIP(Identificador identificadorQuadro, int *resultado) = 0;

        /** @brief Destrutor virtual. */
        virtual ~IServicoCartoes(){}
};

#endif
