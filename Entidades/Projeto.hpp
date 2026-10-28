#ifndef PROJETO_HPP
#define PROJETO_HPP

#include "../Dominios/Identificador.hpp"
#include "../Dominios/Nome.hpp"
#include "../Dominios/Texto.hpp"
#include "../Dominios/Timestamp.hpp"
#include "../Dominios/E-mail.hpp"

class Projeto{
  private:
  Identificador identificador;
  Nome nome;
  Texto descricao;
  Timestamp inicio;
  Timestamp termino;
  Email emailGestor;

  public:

  void setIdentificador(Identificador identificador);
  Identificador getIdentificador() const;

  void setNome(Nome nome);
  Nome getNome() const;

  void setDescricao(Texto descricao);
  Texto getDescricao() const;

  void setInicio(Timestamp inicio);
  Timestamp getInicio() const;

  void setTermino(Timestamp termino);
  Timestamp getTermino() const;

  void setEmailGestor(Email emailGestor);
  Email getEmailGestor() const;
};

#endif
