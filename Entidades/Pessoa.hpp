#ifndef PESSOA_HPP
#define PESSOA_HPP

#include "../Dominios/E-mail.hpp"
#include "../Dominios/Nome.hpp"
#include "../Dominios/Senha.hpp"
#include "../Dominios/Papel.hpp"

class Pessoa{
  private:
  Email email;
  Nome nome;
  Senha senha;
  Papel papel;

  public:

  void setEmail(Email email);
  Email getEmail() const;

  void setNome(Nome nome);
  Nome getNome() const;

  void setSenha(Senha senha);
  Senha getSenha() const;

  void setPapel(Papel papel);
  Papel getPapel() const;
};

#endif
