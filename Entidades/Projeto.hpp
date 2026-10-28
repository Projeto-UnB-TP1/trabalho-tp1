#ifndef PROJETO_HPP
#define PROJETO_HPP

#include "../Dominios/Identificador.hpp"
#include "../Dominios/Nome.hpp"
#include "../Dominios/Texto.hpp"
#include "../Dominios/Timestamp.hpp"
#include "../Dominios/E-mail.hpp"

/**
 * @file Projeto.hpp
 * @brief Declaração da classe de entidade Projeto.
 */

/**
 * @brief Entidade que representa um projeto gerenciado com o método Kanban.
 *
 * @details Um projeto possui identificador, nome, descrição, data de início e data de
 * término. Cada atributo é uma instância de uma classe de domínio, portanto o formato
 * de cada valor já é garantido pelo próprio domínio: a validação acontece quando o
 * objeto de domínio é preenchido (método setValor do domínio), e esta classe apenas
 * armazena e devolve os objetos recebidos.
 *
 * O identificador é a chave primária do projeto e não deve ser alterado depois que o
 * projeto é criado.
 *
 * Relacionamentos:
 * - o gestor do projeto é a pessoa que o criou. Esse relacionamento
 *   (Pessoa 1 : 0..* Projeto) é representado pelo e-mail do gestor
 *   (veja setEmailGestor);
 * - um projeto possui zero ou mais quadros (veja Quadro::setIdentificadorProjeto).
 *
 * Exemplo de uso:
 * @code
 * Identificador id;
 * id.setValor("ABC123");
 *
 * Projeto projeto;
 * projeto.setIdentificador(id);
 * Identificador lido = projeto.getIdentificador();   // lido.getValor() == "ABC123"
 * @endcode
 */
class Projeto{
    private:
        /** @brief Identificador do projeto (chave primária). */
        Identificador identificador;

        /** @brief Nome do projeto. */
        Nome nome;

        /** @brief Descrição do projeto. */
        Texto descricao;

        /** @brief Data e horário de início do projeto. */
        Timestamp inicio;

        /** @brief Data e horário de término do projeto. */
        Timestamp termino;

        /**
         * @brief E-mail do gestor do projeto.
         * @details Referencia a Pessoa que criou o projeto e implementa o
         * relacionamento Pessoa 1 : 0..* Projeto.
         */
        Email emailGestor;

    public:
        /**
         * @brief Atribui o identificador do projeto.
         * @param identificador Objeto Identificador já validado pelo domínio.
         * @note O identificador não deve ser alterado após a criação do projeto.
         */
        void setIdentificador(Identificador identificador);

        /**
         * @brief Obtém o identificador do projeto.
         * @return Objeto Identificador armazenado.
         */
        Identificador getIdentificador() const;

        /**
         * @brief Atribui o nome do projeto.
         * @param nome Objeto Nome já validado pelo domínio.
         */
        void setNome(Nome nome);

        /**
         * @brief Obtém o nome do projeto.
         * @return Objeto Nome armazenado.
         */
        Nome getNome() const;

        /**
         * @brief Atribui a descrição do projeto.
         * @param descricao Objeto Texto já validado pelo domínio.
         */
        void setDescricao(Texto descricao);

        /**
         * @brief Obtém a descrição do projeto.
         * @return Objeto Texto armazenado.
         */
        Texto getDescricao() const;

        /**
         * @brief Atribui a data e o horário de início do projeto.
         * @param inicio Objeto Timestamp já validado pelo domínio.
         */
        void setInicio(Timestamp inicio);

        /**
         * @brief Obtém a data e o horário de início do projeto.
         * @return Objeto Timestamp armazenado.
         */
        Timestamp getInicio() const;

        /**
         * @brief Atribui a data e o horário de término do projeto.
         * @param termino Objeto Timestamp já validado pelo domínio.
         */
        void setTermino(Timestamp termino);

        /**
         * @brief Obtém a data e o horário de término do projeto.
         * @return Objeto Timestamp armazenado.
         */
        Timestamp getTermino() const;

        /**
         * @brief Atribui o e-mail do gestor do projeto.
         * @param emailGestor Objeto Email já validado pelo domínio, correspondente
         *        a uma Pessoa com papel GESTOR.
         */
        void setEmailGestor(Email emailGestor);

        /**
         * @brief Obtém o e-mail do gestor do projeto.
         * @return Objeto Email armazenado.
         */
        Email getEmailGestor() const;
};

#endif
