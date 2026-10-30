#ifndef PROJETO_HPP
#define PROJETO_HPP

#include "../Dominios/Identificador.hpp"
#include "../Dominios/Nome.hpp"
#include "../Dominios/Texto.hpp"
#include "../Dominios/Timestamp.hpp"
#include "../Dominios/E-mail.hpp"

///
/// Entidade que representa projeto.
///
/// Atributos: identificador, nome, descrição, início, término e e-mail do gestor.
///
/// O identificador identifica o projeto. O e-mail do gestor indica a pessoa que gerencia o projeto.
///

class Projeto{
    private:
        Identificador identificador;
        Nome nome;
        Texto descricao;
        Timestamp inicio;
        Timestamp termino;
        Email emailGestor;

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
/// Armazena descrição.
///
/// @param descricao Descrição.
///

        void setDescricao(Texto descricao);

///
/// Retorna descrição.
///
/// @return Descrição.
///

        Texto getDescricao() const;

///
/// Armazena data e horário de início.
///
/// @param inicio Início.
///

        void setInicio(Timestamp inicio);

///
/// Retorna data e horário de início.
///
/// @return Início.
///

        Timestamp getInicio() const;

///
/// Armazena data e horário de término.
///
/// @param termino Término.
///

        void setTermino(Timestamp termino);

///
/// Retorna data e horário de término.
///
/// @return Término.
///

        Timestamp getTermino() const;

///
/// Armazena e-mail do gestor.
///
/// @param emailGestor E-mail do gestor.
///

        void setEmailGestor(Email emailGestor);

///
/// Retorna e-mail do gestor.
///
/// @return E-mail do gestor.
///

        Email getEmailGestor() const;
};

#endif
