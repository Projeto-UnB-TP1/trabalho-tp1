#ifndef QUADRO_HPP
#define QUADRO_HPP

#include "../Dominios/Identificador.hpp"
#include "../Dominios/Nome.hpp"
#include "../Dominios/Limite.hpp"

/**
 * @file Quadro.hpp
 * @brief Declaração da classe de entidade Quadro.
 */

/**
 * @brief Entidade que representa um quadro Kanban de um projeto.
 *
 * @details Um quadro é composto pelas colunas A FAZER, FAZENDO e FEITO e possui
 * identificador, nome e limite de work in progress (WIP). Cada atributo é uma
 * instância de uma classe de domínio, portanto o formato de cada valor já é
 * garantido pelo próprio domínio: a validação acontece quando o objeto de domínio
 * é preenchido (método setValor do domínio), e esta classe apenas armazena e
 * devolve os objetos recebidos.
 *
 * O identificador é a chave primária do quadro e não deve ser alterado depois que o
 * quadro é criado.
 *
 * Relacionamentos:
 * - um quadro pertence a exatamente um projeto. Esse relacionamento
 *   (Projeto 1 : 0..* Quadro) é representado pelo identificador do projeto
 *   (veja setIdentificadorProjeto);
 * - um quadro possui zero ou mais cartões de atividade.
 *
 * Exemplo de uso:
 * @code
 * Identificador id;
 * id.setValor("QDR001");
 *
 * Quadro quadro;
 * quadro.setIdentificador(id);
 * Identificador lido = quadro.getIdentificador();   // lido.getValor() == "QDR001"
 * @endcode
 */
class Quadro{
    private:
        /** @brief Identificador do quadro (chave primária). */
        Identificador identificador;

        /** @brief Nome do quadro. */
        Nome nome;

        /**
         * @brief Limite de work in progress (WIP) do quadro.
         * @details Número máximo de cartões de atividade que podem estar
         * simultaneamente na coluna FAZENDO.
         */
        Limite limite;

        /**
         * @brief Identificador do projeto ao qual o quadro pertence.
         * @details Implementa o relacionamento Projeto 1 : 0..* Quadro.
         */
        Identificador identificadorProjeto;

    public:
        /**
         * @brief Atribui o identificador do quadro.
         * @param identificador Objeto Identificador já validado pelo domínio.
         * @note O identificador não deve ser alterado após a criação do quadro.
         */
        void setIdentificador(Identificador identificador);

        /**
         * @brief Obtém o identificador do quadro.
         * @return Objeto Identificador armazenado.
         */
        Identificador getIdentificador() const;

        /**
         * @brief Atribui o nome do quadro.
         * @param nome Objeto Nome já validado pelo domínio.
         */
        void setNome(Nome nome);

        /**
         * @brief Obtém o nome do quadro.
         * @return Objeto Nome armazenado.
         */
        Nome getNome() const;

        /**
         * @brief Atribui o limite de work in progress (WIP) do quadro.
         * @param limite Objeto Limite já validado pelo domínio.
         */
        void setLimite(Limite limite);

        /**
         * @brief Obtém o limite de work in progress (WIP) do quadro.
         * @return Objeto Limite armazenado.
         */
        Limite getLimite() const;

        /**
         * @brief Atribui o identificador do projeto ao qual o quadro pertence.
         * @param identificadorProjeto Objeto Identificador já validado pelo domínio,
         *        correspondente a um Projeto existente.
         */
        void setIdentificadorProjeto(Identificador identificadorProjeto);

        /**
         * @brief Obtém o identificador do projeto ao qual o quadro pertence.
         * @return Objeto Identificador armazenado.
         */
        Identificador getIdentificadorProjeto() const;
};

#endif
