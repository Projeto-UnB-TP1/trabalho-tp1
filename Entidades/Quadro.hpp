#ifndef QUADRO_HPP
#define QUADRO_HPP

#include "../Dominios/Identificador.hpp"
#include "../Dominios/Nome.hpp"
#include "../Dominios/Limite.hpp"

///
/// Entidade que representa quadro Kanban.
///
/// Atributos: identificador, nome, limite de work in progress (WIP) e identificador do projeto.
///
/// O identificador identifica o quadro. O identificador do projeto indica o projeto ao qual o quadro pertence.
///

class Quadro{
    private:
        Identificador identificador;
        Nome nome;
        Limite limite;
        Identificador identificadorProjeto;

    public:

///
/// Armazena identificador.
///
/// @param identificador Identificador.
///

        void setIdentificador(Identificador identificador);

///
/// Retorna identificador.
///
/// @return Identificador.
///

        Identificador getIdentificador() const;

///
/// Armazena nome.
///
/// @param nome Nome.
///

        void setNome(Nome nome);

///
/// Retorna nome.
///
/// @return Nome.
///

        Nome getNome() const;

///
/// Armazena limite de cartões na coluna FAZENDO.
///
/// @param limite Limite.
///

        void setLimite(Limite limite);

///
/// Retorna limite de cartões na coluna FAZENDO.
///
/// @return Limite.
///

        Limite getLimite() const;

///
/// Armazena identificador do projeto.
///
/// @param identificadorProjeto Identificador do projeto.
///

        void setIdentificadorProjeto(Identificador identificadorProjeto);

///
/// Retorna identificador do projeto.
///
/// @return Identificador do projeto.
///

        Identificador getIdentificadorProjeto() const;
};

#endif
