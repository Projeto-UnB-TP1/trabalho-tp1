#ifndef PRIORIDADE_HPP
#define PRIORIDADE_HPP

#include <string>
#include <stdexcept>

/**
 * @file Prioridade.hpp
 * @brief Declaração da classe de domínio Prioridade.
 */

/**
 * @brief Domínio que representa a prioridade de um cartão de atividade.
 *
 * @details Os valores válidos são exatamente "ALTA", "MEDIA" e "BAIXA", em maiúsculas
 * e sem acento.
 *
 * Exemplo de uso:
 * @code
 * Prioridade prioridade;
 * prioridade.setValor("MEDIA");
 * string atual = prioridade.getValor();   // "MEDIA"
 * @endcode
 */
class Prioridade{
  private:
  std::string valor;

  public:

  /**
   * @brief Define o valor da prioridade.
   * @param valor Texto com a prioridade: "ALTA", "MEDIA" ou "BAIXA".
   * @throw std::invalid_argument Se o valor for diferente de "ALTA", "MEDIA" e "BAIXA".
   *        Nesse caso, o valor armazenado anteriormente não é alterado.
   */
  void setValor(std::string valor);

  /**
   * @brief Retorna o valor da prioridade.
   * @return std::string A prioridade atual: "ALTA", "MEDIA" ou "BAIXA".
   */
  std::string getValor() const;
};

#endif
