#ifndef CARTAODEATIVIDADE_HPP
#define CARTAODEATIVIDADE_HPP

#include "../Dominios/Identificador.hpp"
#include "../Dominios/Nome.hpp"
#include "../Dominios/Texto.hpp"
#include "../Dominios/Prioridade.hpp"
#include "../Dominios/Estado.hpp"
#include "../Dominios/Tamanho.hpp"
#include "../Dominios/Timestamp.hpp"

/**
 * @file CartaoDeAtividade.hpp
 * @brief Declaração da classe de entidade CartaoDeAtividade.
 */

/**
 * @brief Entidade que representa um cartão de atividade de um quadro Kanban.
 *
 * @details Um cartão de atividade possui identificador, nome, descrição, prioridade,
 * estado, tamanho e três marcas de tempo (entrada, início e término). Cada atributo
 * é uma instância de uma classe de domínio, portanto o formato de cada valor já é
 * garantido pelo próprio domínio: a validação acontece quando o objeto de domínio
 * é preenchido (método setValor do domínio), e esta classe apenas armazena e
 * devolve os objetos recebidos.
 *
 * O identificador é a chave primária do cartão e não deve ser alterado depois que o
 * cartão é criado.
 *
 * O estado indica a coluna do quadro em que o cartão está (A FAZER, FAZENDO ou FEITO).
 * As marcas de tempo servem de base para as métricas do quadro:
 * - **entrada:** momento em que o cartão entra na coluna A FAZER;
 * - **início:** momento em que o cartão entra na coluna FAZENDO;
 * - **término:** momento em que o cartão chega à coluna FEITO.
 *
 * Com elas, o tempo de ciclo (cycle time) de um cartão é a diferença entre o término
 * e o início, e o lead time é a diferença entre o término e a entrada. Esta classe
 * apenas armazena as marcas de tempo; o cálculo das métricas é responsabilidade
 * de quem usa a entidade.
 *
 * Relacionamentos:
 * - um cartão pertence a exatamente um quadro. Esse relacionamento
 *   (Quadro 1 : 0..* CartaoDeAtividade) é representado pelo identificador do quadro
 *   (veja setIdentificadorQuadro).
 *
 * Exemplo de uso:
 * @code
 * Identificador id;
 * id.setValor("CRT001");
 *
 * CartaoDeAtividade cartao;
 * cartao.setIdentificador(id);
 * Identificador lido = cartao.getIdentificador();   // lido.getValor() == "CRT001"
 * @endcode
 */
class CartaoDeAtividade{
  private:
  /** @brief Identificador do cartão (chave primária). */
  Identificador identificador;

  /** @brief Nome do cartão. */
  Nome nome;

  /** @brief Descrição da atividade. */
  Texto descricao;

  /** @brief Prioridade da atividade: ALTA, MEDIA ou BAIXA. */
  Prioridade prioridade;

  /** @brief Estado do cartão, que indica a coluna do quadro: A FAZER, FAZENDO ou FEITO. */
  Estado estado;

  /** @brief Tamanho da atividade: GRANDE, MEDIO ou PEQUENO. */
  Tamanho tamanho;

  /** @brief Momento em que o cartão entra na coluna A FAZER (início do lead time). */
  Timestamp entrada;

  /** @brief Momento em que o cartão entra na coluna FAZENDO (início do tempo de ciclo). */
  Timestamp inicio;

  /** @brief Momento em que o cartão chega à coluna FEITO (fim do tempo de ciclo e do lead time). */
  Timestamp termino;

  /**
   * @brief Identificador do quadro ao qual o cartão pertence.
   * @details Implementa o relacionamento Quadro 1 : 0..* CartaoDeAtividade.
   */
  Identificador identificadorQuadro;

  public:
  /**
   * @brief Atribui o identificador do cartão.
   * @param identificador Objeto Identificador já validado pelo domínio.
   * @note O identificador não deve ser alterado após a criação do cartão.
   */
  void setIdentificador(Identificador identificador);

  /**
   * @brief Obtém o identificador do cartão.
   * @return Objeto Identificador armazenado.
   */
  Identificador getIdentificador() const;

  /**
   * @brief Atribui o nome do cartão.
   * @param nome Objeto Nome já validado pelo domínio.
   */
  void setNome(Nome nome);

  /**
   * @brief Obtém o nome do cartão.
   * @return Objeto Nome armazenado.
   */
  Nome getNome() const;

  /**
   * @brief Atribui a descrição da atividade.
   * @param descricao Objeto Texto já validado pelo domínio.
   */
  void setDescricao(Texto descricao);

  /**
   * @brief Obtém a descrição da atividade.
   * @return Objeto Texto armazenado.
   */
  Texto getDescricao() const;

  /**
   * @brief Atribui a prioridade da atividade.
   * @param prioridade Objeto Prioridade já validado pelo domínio (ALTA, MEDIA ou BAIXA).
   */
  void setPrioridade(Prioridade prioridade);

  /**
   * @brief Obtém a prioridade da atividade.
   * @return Objeto Prioridade armazenado.
   */
  Prioridade getPrioridade() const;

  /**
   * @brief Atribui o estado do cartão.
   * @param estado Objeto Estado já validado pelo domínio (A FAZER, FAZENDO ou FEITO).
   */
  void setEstado(Estado estado);

  /**
   * @brief Obtém o estado do cartão.
   * @return Objeto Estado armazenado.
   */
  Estado getEstado() const;

  /**
   * @brief Atribui o tamanho da atividade.
   * @param tamanho Objeto Tamanho já validado pelo domínio (GRANDE, MEDIO ou PEQUENO).
   */
  void setTamanho(Tamanho tamanho);

  /**
   * @brief Obtém o tamanho da atividade.
   * @return Objeto Tamanho armazenado.
   */
  Tamanho getTamanho() const;

  /**
   * @brief Atribui o momento de entrada do cartão na coluna A FAZER.
   * @param entrada Objeto Timestamp já validado pelo domínio.
   */
  void setEntrada(Timestamp entrada);

  /**
   * @brief Obtém o momento de entrada do cartão na coluna A FAZER.
   * @return Objeto Timestamp armazenado.
   */
  Timestamp getEntrada() const;

  /**
   * @brief Atribui o momento em que o cartão entra na coluna FAZENDO.
   * @param inicio Objeto Timestamp já validado pelo domínio.
   */
  void setInicio(Timestamp inicio);

  /**
   * @brief Obtém o momento em que o cartão entra na coluna FAZENDO.
   * @return Objeto Timestamp armazenado.
   */
  Timestamp getInicio() const;

  /**
   * @brief Atribui o momento em que o cartão chega à coluna FEITO.
   * @param termino Objeto Timestamp já validado pelo domínio.
   */
  void setTermino(Timestamp termino);

  /**
   * @brief Obtém o momento em que o cartão chega à coluna FEITO.
   * @return Objeto Timestamp armazenado.
   */
  Timestamp getTermino() const;

  /**
   * @brief Atribui o identificador do quadro ao qual o cartão pertence.
   * @param identificadorQuadro Objeto Identificador já validado pelo domínio,
   *        correspondente a um Quadro existente.
   */
  void setIdentificadorQuadro(Identificador identificadorQuadro);

  /**
   * @brief Obtém o identificador do quadro ao qual o cartão pertence.
   * @return Objeto Identificador armazenado.
   */
  Identificador getIdentificadorQuadro() const;
};

#endif