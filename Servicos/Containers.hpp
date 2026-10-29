#ifndef CONTAINERS_HPP
#define CONTAINERS_HPP

#include <list>
#include "../Entidades/Pessoa.hpp"
#include "../Entidades/Projeto.hpp"
#include "../Entidades/Quadro.hpp"
#include "../Entidades/CartaoDeAtividade.hpp"

using namespace std;

/**
 * @file Containers.hpp
 * @brief Declaração das classes contêiner da camada de serviço.
 *
 * @details Cada contêiner armazena em memória, em uma lista, as entidades de um tipo e
 * adota o padrão de projeto Singleton: existe uma única instância, obtida por
 * getInstancia(), compartilhada por todas as controladoras de serviço. A chave de cada
 * entidade é única dentro do contêiner.
 */

/**
 * @brief Contêiner de pessoas.
 *
 * @details Armazena objetos Pessoa. A chave de cada objeto é o e-mail.
 */
class ContainerPessoa{
    private:
        list<Pessoa> container;
        static ContainerPessoa *instancia;
        ContainerPessoa(){};
    public:
        /**
         * @brief Retorna a instância única do contêiner, criando-a na primeira chamada.
         * @return Ponteiro para o contêiner.
         */
        static ContainerPessoa* getInstancia();

        /**
         * @brief Inclui um objeto no contêiner.
         * @param pessoa Objeto a ser incluído.
         * @return true se o objeto foi incluído; false se já existe objeto com a mesma chave.
         */
        bool incluir(Pessoa pessoa);

        /**
         * @brief Remove o objeto com a chave informada.
         * @param email Chave do objeto.
         * @return true se o objeto foi removido; false se não foi encontrado.
         */
        bool remover(Email email);

        /**
         * @brief Pesquisa o objeto com a mesma chave do objeto apontado.
         * @param pessoa Ponteiro para um objeto com a chave preenchida; recebe o objeto encontrado.
         * @return true se o objeto foi encontrado; false caso contrário.
         */
        bool pesquisar(Pessoa *pessoa);

        /**
         * @brief Substitui o objeto que tem a mesma chave do objeto informado.
         * @param pessoa Objeto com os novos dados; a chave não é alterada.
         * @return true se o objeto foi atualizado; false se não foi encontrado.
         */
        bool atualizar(Pessoa pessoa);

        /**
         * @brief Retorna uma cópia de todos os objetos armazenados.
         * @return Lista com os objetos do contêiner.
         */
        list<Pessoa> listar();
};

/**
 * @brief Contêiner de projetos.
 *
 * @details Armazena objetos Projeto. A chave de cada objeto é o identificador.
 */
class ContainerProjeto{
    private:
        list<Projeto> container;
        static ContainerProjeto *instancia;
        ContainerProjeto(){};
    public:
        /**
         * @brief Retorna a instância única do contêiner, criando-a na primeira chamada.
         * @return Ponteiro para o contêiner.
         */
        static ContainerProjeto* getInstancia();

        /**
         * @brief Inclui um objeto no contêiner.
         * @param projeto Objeto a ser incluído.
         * @return true se o objeto foi incluído; false se já existe objeto com a mesma chave.
         */
        bool incluir(Projeto projeto);

        /**
         * @brief Remove o objeto com a chave informada.
         * @param identificador Chave do objeto.
         * @return true se o objeto foi removido; false se não foi encontrado.
         */
        bool remover(Identificador identificador);

        /**
         * @brief Pesquisa o objeto com a mesma chave do objeto apontado.
         * @param projeto Ponteiro para um objeto com a chave preenchida; recebe o objeto encontrado.
         * @return true se o objeto foi encontrado; false caso contrário.
         */
        bool pesquisar(Projeto *projeto);

        /**
         * @brief Substitui o objeto que tem a mesma chave do objeto informado.
         * @param projeto Objeto com os novos dados; a chave não é alterada.
         * @return true se o objeto foi atualizado; false se não foi encontrado.
         */
        bool atualizar(Projeto projeto);

        /**
         * @brief Retorna uma cópia de todos os objetos armazenados.
         * @return Lista com os objetos do contêiner.
         */
        list<Projeto> listar();
};

/**
 * @brief Contêiner de quadros.
 *
 * @details Armazena objetos Quadro. A chave de cada objeto é o identificador.
 */
class ContainerQuadro{
    private:
        list<Quadro> container;
        static ContainerQuadro *instancia;
        ContainerQuadro(){};
    public:
        /**
         * @brief Retorna a instância única do contêiner, criando-a na primeira chamada.
         * @return Ponteiro para o contêiner.
         */
        static ContainerQuadro* getInstancia();

        /**
         * @brief Inclui um objeto no contêiner.
         * @param quadro Objeto a ser incluído.
         * @return true se o objeto foi incluído; false se já existe objeto com a mesma chave.
         */
        bool incluir(Quadro quadro);

        /**
         * @brief Remove o objeto com a chave informada.
         * @param identificador Chave do objeto.
         * @return true se o objeto foi removido; false se não foi encontrado.
         */
        bool remover(Identificador identificador);

        /**
         * @brief Pesquisa o objeto com a mesma chave do objeto apontado.
         * @param quadro Ponteiro para um objeto com a chave preenchida; recebe o objeto encontrado.
         * @return true se o objeto foi encontrado; false caso contrário.
         */
        bool pesquisar(Quadro *quadro);

        /**
         * @brief Substitui o objeto que tem a mesma chave do objeto informado.
         * @param quadro Objeto com os novos dados; a chave não é alterada.
         * @return true se o objeto foi atualizado; false se não foi encontrado.
         */
        bool atualizar(Quadro quadro);

        /**
         * @brief Retorna uma cópia de todos os objetos armazenados.
         * @return Lista com os objetos do contêiner.
         */
        list<Quadro> listar();
};

/**
 * @brief Contêiner de cartões de atividade.
 *
 * @details Armazena objetos CartaoDeAtividade. A chave de cada objeto é o identificador.
 */
class ContainerCartao{
    private:
        list<CartaoDeAtividade> container;
        static ContainerCartao *instancia;
        ContainerCartao(){};
    public:
        /**
         * @brief Retorna a instância única do contêiner, criando-a na primeira chamada.
         * @return Ponteiro para o contêiner.
         */
        static ContainerCartao* getInstancia();

        /**
         * @brief Inclui um objeto no contêiner.
         * @param cartao Objeto a ser incluído.
         * @return true se o objeto foi incluído; false se já existe objeto com a mesma chave.
         */
        bool incluir(CartaoDeAtividade cartao);

        /**
         * @brief Remove o objeto com a chave informada.
         * @param identificador Chave do objeto.
         * @return true se o objeto foi removido; false se não foi encontrado.
         */
        bool remover(Identificador identificador);

        /**
         * @brief Pesquisa o objeto com a mesma chave do objeto apontado.
         * @param cartao Ponteiro para um objeto com a chave preenchida; recebe o objeto encontrado.
         * @return true se o objeto foi encontrado; false caso contrário.
         */
        bool pesquisar(CartaoDeAtividade *cartao);

        /**
         * @brief Substitui o objeto que tem a mesma chave do objeto informado.
         * @param cartao Objeto com os novos dados; a chave não é alterada.
         * @return true se o objeto foi atualizado; false se não foi encontrado.
         */
        bool atualizar(CartaoDeAtividade cartao);

        /**
         * @brief Retorna uma cópia de todos os objetos armazenados.
         * @return Lista com os objetos do contêiner.
         */
        list<CartaoDeAtividade> listar();
};

#endif
