#ifndef PESSOA_HPP
#define PESSOA_HPP

#include "../Dominios/E-mail.hpp"
#include "../Dominios/Nome.hpp"
#include "../Dominios/Senha.hpp"
#include "../Dominios/Papel.hpp"

/**
 * @file Pessoa.hpp
 * @brief Declaração da classe de entidade Pessoa.
 */

/**
 * @brief Entidade que representa um usuário do sistema Kanban.
 *
 * @details Uma pessoa possui e-mail, nome, senha e papel (GESTOR ou DESENVOLVEDOR).
 * Cada atributo é uma instância de uma classe de domínio, portanto o formato de
 * cada valor já é garantido pelo próprio domínio: a validação acontece quando o
 * objeto de domínio é preenchido (método setValor do domínio), e esta classe apenas
 * armazena e devolve os objetos recebidos.
 *
 * O e-mail é o identificador da pessoa (chave primária) e não deve ser alterado
 * depois que a pessoa é criada.
 *
 * Relacionamentos:
 * - uma pessoa com papel GESTOR é gestora de zero ou mais projetos
 *   (veja Projeto::setEmailGestor);
 * - uma pessoa com papel DESENVOLVEDOR pode ser responsável por zero ou mais
 *   cartões de atividade.
 *
 * Exemplo de uso:
 * @code
 * Email email;
 * email.setValor("joao.silva@unb.br");
 *
 * Pessoa pessoa;
 * pessoa.setEmail(email);
 * Email lido = pessoa.getEmail();   // lido.getValor() == "joao.silva@unb.br"
 * @endcode
 */
class Pessoa{
    private:
        /** @brief E-mail da pessoa (identificador, chave primária). */
        Email email;

        /** @brief Nome da pessoa. */
        Nome nome;

        /** @brief Senha de acesso da pessoa. */
        Senha senha;

        /** @brief Papel da pessoa no sistema: GESTOR ou DESENVOLVEDOR. */
        Papel papel;

    public:
        /**
         * @brief Atribui o e-mail da pessoa.
         * @param email Objeto Email já validado pelo domínio.
         * @note O e-mail identifica a pessoa e não deve ser alterado após a criação.
         */
        void setEmail(Email email);

        /**
         * @brief Obtém o e-mail da pessoa.
         * @return Objeto Email armazenado.
         */
        Email getEmail() const;

        /**
         * @brief Atribui o nome da pessoa.
         * @param nome Objeto Nome já validado pelo domínio.
         */
        void setNome(Nome nome);

        /**
         * @brief Obtém o nome da pessoa.
         * @return Objeto Nome armazenado.
         */
        Nome getNome() const;

        /**
         * @brief Atribui a senha da pessoa.
         * @param senha Objeto Senha já validado pelo domínio.
         */
        void setSenha(Senha senha);

        /**
         * @brief Obtém a senha da pessoa.
         * @return Objeto Senha armazenado.
         */
        Senha getSenha() const;

        /**
         * @brief Atribui o papel da pessoa.
         * @param papel Objeto Papel já validado pelo domínio (GESTOR ou DESENVOLVEDOR).
         */
        void setPapel(Papel papel);

        /**
         * @brief Obtém o papel da pessoa.
         * @return Objeto Papel armazenado.
         */
        Papel getPapel() const;
};

#endif
