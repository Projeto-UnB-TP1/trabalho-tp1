#ifndef CONTAINERS_HPP
#define CONTAINERS_HPP

#include <list>
#include "../Entidades/Pessoa.hpp"
#include "../Entidades/Projeto.hpp"
#include "../Entidades/Quadro.hpp"
#include "../Entidades/CartaoDeAtividade.hpp"

using namespace std;

///
/// Contêiner de pessoas, com instância única (Singleton).
///
/// A chave de cada objeto é o e-mail.
///

class ContainerPessoa{
    private:
        list<Pessoa> container;
        static ContainerPessoa *instancia;
        ContainerPessoa(){};
    public:

///
/// Retorna a instância única do contêiner.
///
/// @return Contêiner.
///

        static ContainerPessoa* getInstancia();

///
/// Inclui objeto.
///
/// @param pessoa Objeto.
///
/// @return
///
/// - Retorna true  caso o objeto tenha sido incluído.
/// - Retorna false caso já exista objeto com a mesma chave.
///

        bool incluir(Pessoa pessoa);

///
/// Remove objeto.
///
/// @param email Chave do objeto.
///
/// @return
///
/// - Retorna true  caso o objeto tenha sido removido.
/// - Retorna false caso o objeto não tenha sido encontrado.
///

        bool remover(Email email);

///
/// Pesquisa objeto.
///
/// @param pessoa Ponteiro para objeto com a chave informada. Recebe o objeto encontrado.
///
/// @return
///
/// - Retorna true  caso o objeto tenha sido encontrado.
/// - Retorna false caso contrário.
///

        bool pesquisar(Pessoa *pessoa);

///
/// Atualiza objeto com a mesma chave.
///
/// @param pessoa Objeto.
///
/// @return
///
/// - Retorna true  caso o objeto tenha sido atualizado.
/// - Retorna false caso o objeto não tenha sido encontrado.
///

        bool atualizar(Pessoa pessoa);

///
/// Retorna os objetos armazenados.
///
/// @return Objetos.
///

        list<Pessoa> listar();
};

///
/// Contêiner de projetos, com instância única (Singleton).
///
/// A chave de cada objeto é o identificador.
///

class ContainerProjeto{
    private:
        list<Projeto> container;
        static ContainerProjeto *instancia;
        ContainerProjeto(){};
    public:

///
/// Retorna a instância única do contêiner.
///
/// @return Contêiner.
///

        static ContainerProjeto* getInstancia();

///
/// Inclui objeto.
///
/// @param projeto Objeto.
///
/// @return
///
/// - Retorna true  caso o objeto tenha sido incluído.
/// - Retorna false caso já exista objeto com a mesma chave.
///

        bool incluir(Projeto projeto);

///
/// Remove objeto.
///
/// @param identificador Chave do objeto.
///
/// @return
///
/// - Retorna true  caso o objeto tenha sido removido.
/// - Retorna false caso o objeto não tenha sido encontrado.
///

        bool remover(Identificador identificador);

///
/// Pesquisa objeto.
///
/// @param projeto Ponteiro para objeto com a chave informada. Recebe o objeto encontrado.
///
/// @return
///
/// - Retorna true  caso o objeto tenha sido encontrado.
/// - Retorna false caso contrário.
///

        bool pesquisar(Projeto *projeto);

///
/// Atualiza objeto com a mesma chave.
///
/// @param projeto Objeto.
///
/// @return
///
/// - Retorna true  caso o objeto tenha sido atualizado.
/// - Retorna false caso o objeto não tenha sido encontrado.
///

        bool atualizar(Projeto projeto);

///
/// Retorna os objetos armazenados.
///
/// @return Objetos.
///

        list<Projeto> listar();
};

///
/// Contêiner de quadros, com instância única (Singleton).
///
/// A chave de cada objeto é o identificador.
///

class ContainerQuadro{
    private:
        list<Quadro> container;
        static ContainerQuadro *instancia;
        ContainerQuadro(){};
    public:

///
/// Retorna a instância única do contêiner.
///
/// @return Contêiner.
///

        static ContainerQuadro* getInstancia();

///
/// Inclui objeto.
///
/// @param quadro Objeto.
///
/// @return
///
/// - Retorna true  caso o objeto tenha sido incluído.
/// - Retorna false caso já exista objeto com a mesma chave.
///

        bool incluir(Quadro quadro);

///
/// Remove objeto.
///
/// @param identificador Chave do objeto.
///
/// @return
///
/// - Retorna true  caso o objeto tenha sido removido.
/// - Retorna false caso o objeto não tenha sido encontrado.
///

        bool remover(Identificador identificador);

///
/// Pesquisa objeto.
///
/// @param quadro Ponteiro para objeto com a chave informada. Recebe o objeto encontrado.
///
/// @return
///
/// - Retorna true  caso o objeto tenha sido encontrado.
/// - Retorna false caso contrário.
///

        bool pesquisar(Quadro *quadro);

///
/// Atualiza objeto com a mesma chave.
///
/// @param quadro Objeto.
///
/// @return
///
/// - Retorna true  caso o objeto tenha sido atualizado.
/// - Retorna false caso o objeto não tenha sido encontrado.
///

        bool atualizar(Quadro quadro);

///
/// Retorna os objetos armazenados.
///
/// @return Objetos.
///

        list<Quadro> listar();
};

///
/// Contêiner de cartões de atividade, com instância única (Singleton).
///
/// A chave de cada objeto é o identificador.
///

class ContainerCartao{
    private:
        list<CartaoDeAtividade> container;
        static ContainerCartao *instancia;
        ContainerCartao(){};
    public:

///
/// Retorna a instância única do contêiner.
///
/// @return Contêiner.
///

        static ContainerCartao* getInstancia();

///
/// Inclui objeto.
///
/// @param cartao Objeto.
///
/// @return
///
/// - Retorna true  caso o objeto tenha sido incluído.
/// - Retorna false caso já exista objeto com a mesma chave.
///

        bool incluir(CartaoDeAtividade cartao);

///
/// Remove objeto.
///
/// @param identificador Chave do objeto.
///
/// @return
///
/// - Retorna true  caso o objeto tenha sido removido.
/// - Retorna false caso o objeto não tenha sido encontrado.
///

        bool remover(Identificador identificador);

///
/// Pesquisa objeto.
///
/// @param cartao Ponteiro para objeto com a chave informada. Recebe o objeto encontrado.
///
/// @return
///
/// - Retorna true  caso o objeto tenha sido encontrado.
/// - Retorna false caso contrário.
///

        bool pesquisar(CartaoDeAtividade *cartao);

///
/// Atualiza objeto com a mesma chave.
///
/// @param cartao Objeto.
///
/// @return
///
/// - Retorna true  caso o objeto tenha sido atualizado.
/// - Retorna false caso o objeto não tenha sido encontrado.
///

        bool atualizar(CartaoDeAtividade cartao);

///
/// Retorna os objetos armazenados.
///
/// @return Objetos.
///

        list<CartaoDeAtividade> listar();
};

#endif
