#ifndef CARTAODEATIVIDADE_HPP
#define CARTAODEATIVIDADE_HPP

#include "../Dominios/Identificador.hpp"
#include "../Dominios/Nome.hpp"
#include "../Dominios/Texto.hpp"
#include "../Dominios/Prioridade.hpp"
#include "../Dominios/Estado.hpp"
#include "../Dominios/Tamanho.hpp"
#include "../Dominios/Timestamp.hpp"

///
/// Entidade que representa cartão de atividade.
///
/// Atributos: identificador, nome, descrição, prioridade, estado, tamanho, entrada, início, término e identificador do quadro.
///
/// O identificador identifica o cartão. O identificador do quadro indica o quadro ao qual o cartão pertence.
///

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
/// Armazena prioridade.
///
/// @param prioridade Prioridade.
///

    void setPrioridade(Prioridade prioridade);

///
/// Retorna prioridade.
///
/// @return Prioridade.
///

    Prioridade getPrioridade() const;

///
/// Armazena estado, que indica a coluna do quadro.
///
/// @param estado Estado.
///

    void setEstado(Estado estado);

///
/// Retorna estado, que indica a coluna do quadro.
///
/// @return Estado.
///

    Estado getEstado() const;

///
/// Armazena tamanho.
///
/// @param tamanho Tamanho.
///

    void setTamanho(Tamanho tamanho);

///
/// Retorna tamanho.
///
/// @return Tamanho.
///

    Tamanho getTamanho() const;

///
/// Armazena data e horário de entrada na coluna A FAZER.
///
/// @param entrada Entrada.
///

    void setEntrada(Timestamp entrada);

///
/// Retorna data e horário de entrada na coluna A FAZER.
///
/// @return Entrada.
///

    Timestamp getEntrada() const;

///
/// Armazena data e horário de entrada na coluna FAZENDO.
///
/// @param inicio Início.
///

    void setInicio(Timestamp inicio);

///
/// Retorna data e horário de entrada na coluna FAZENDO.
///
/// @return Início.
///

    Timestamp getInicio() const;

///
/// Armazena data e horário de entrada na coluna FEITO.
///
/// @param termino Término.
///

    void setTermino(Timestamp termino);

///
/// Retorna data e horário de entrada na coluna FEITO.
///
/// @return Término.
///

    Timestamp getTermino() const;

///
/// Armazena identificador do quadro.
///
/// @param identificadorQuadro Identificador do quadro.
///

    void setIdentificadorQuadro(Identificador identificadorQuadro);

///
/// Retorna identificador do quadro.
///
/// @return Identificador do quadro.
///

    Identificador getIdentificadorQuadro() const;
};

#endif
