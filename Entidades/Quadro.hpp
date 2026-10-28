#ifndef QUADRO_HPP
#define QUADRO_HPP

#include "../Dominios/Identificador.hpp"
#include "../Dominios/Nome.hpp"
#include "../Dominios/Limite.hpp"

class Quadro{
  private:
  Identificador identificador;
  Nome nome;
  Limite limite;
  Identificador identificadorProjeto;   // identificador do projeto ao qual o quadro pertence

  public:

  void setIdentificador(Identificador identificador);
  Identificador getIdentificador() const;

  void setNome(Nome nome);
  Nome getNome() const;

  void setLimite(Limite limite);
  Limite getLimite() const;

  void setIdentificadorProjeto(Identificador identificadorProjeto);
  Identificador getIdentificadorProjeto() const;
};

#endif
