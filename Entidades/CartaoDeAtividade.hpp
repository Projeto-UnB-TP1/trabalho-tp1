#ifndef CARTAODEATIVIDADE_HPP
#define CARTAODEATIVIDADE_HPP

#include "../Dominios/Identificador.hpp"
#include "../Dominios/Nome.hpp"
#include "../Dominios/Texto.hpp"
#include "../Dominios/Prioridade.hpp"
#include "../Dominios/Estado.hpp"
#include "../Dominios/Tamanho.hpp"
#include "../Dominios/Timestamp.hpp"

class CartaoDeAtividade{
  private:
  Identificador identificador;
  Nome nome;
  Texto descricao;
  Prioridade prioridade;
  Estado estado;
  Tamanho tamanho;
  Timestamp entrada;
  Timestamp inicio;
  Timestamp termino;
  Identificador identificadorQuadro;

  public:

  void setIdentificador(Identificador identificador);
  Identificador getIdentificador() const;

  void setNome(Nome nome);
  Nome getNome() const;

  void setDescricao(Texto descricao);
  Texto getDescricao() const;

  void setPrioridade(Prioridade prioridade);
  Prioridade getPrioridade() const;

  void setEstado(Estado estado);
  Estado getEstado() const;

  void setTamanho(Tamanho tamanho);
  Tamanho getTamanho() const;

  void setEntrada(Timestamp entrada);
  Timestamp getEntrada() const;

  void setInicio(Timestamp inicio);
  Timestamp getInicio() const;

  void setTermino(Timestamp termino);
  Timestamp getTermino() const;

  void setIdentificadorQuadro(Identificador identificadorQuadro);
  Identificador getIdentificadorQuadro() const;
};

#endif
