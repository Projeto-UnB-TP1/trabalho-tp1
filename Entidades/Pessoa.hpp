#ifndef PESSOA_HPP
#define PESSOA_HPP

#include "../Dominios/E-mail.hpp"
#include "../Dominios/Nome.hpp"
#include "../Dominios/Senha.hpp"
#include "../Dominios/Papel.hpp"

///
/// Entidade que representa pessoa usuária do sistema.
///
/// Atributos: e-mail, nome, senha e papel.
///
/// O e-mail identifica a pessoa.
///

class Pessoa{
    private:
        Email email;
        Nome nome;
        Senha senha;
        Papel papel;

    public:

///
/// Armazena e-mail.
///
/// @param email E-mail.
///

        void setEmail(Email email);

///
/// Retorna e-mail.
///
/// @return E-mail.
///

        Email getEmail() const;

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
/// Armazena senha.
///
/// @param senha Senha.
///

        void setSenha(Senha senha);

///
/// Retorna senha.
///
/// @return Senha.
///

        Senha getSenha() const;

///
/// Armazena papel.
///
/// @param papel Papel.
///

        void setPapel(Papel papel);

///
/// Retorna papel.
///
/// @return Papel.
///

        Papel getPapel() const;
};

#endif
