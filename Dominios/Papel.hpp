#ifndef PAPEL_HPP
#define PAPEL_HPP

#include <string>
#include <stdexcept>

/**
 * @file Papel.hpp
 * @brief Declaração da classe de domínio Papel.
 */

/**
 * @brief Domínio que representa o papel de uma pessoa no sistema.
 *
 * @details Os valores válidos são exatamente "GESTOR" e "DESENVOLVEDOR", em maiúsculas.
 * O papel define quais serviços a pessoa pode usar: somente GESTOR cria, atualiza e
 * exclui projetos, quadros e cartões de atividade.
 *
 * Exemplo de uso:
 * @code
 * Papel papel;
 * papel.setValor("GESTOR");
 * string atual = papel.getValor();   // "GESTOR"
 * @endcode
 */
class Papel{
  private:
  std::string valor;

  public:

  /**
   * @brief Define o valor do papel.
   * @param valor Texto com o papel: "GESTOR" ou "DESENVOLVEDOR".
   * @throw std::invalid_argument Se o valor for diferente de "GESTOR" e "DESENVOLVEDOR".
   *        Nesse caso, o valor armazenado anteriormente não é alterado.
   */
  void setValor(std::string valor);

  /**
   * @brief Retorna o valor do papel.
   * @return std::string O papel atual: "GESTOR" ou "DESENVOLVEDOR".
   */
  std::string getValor() const;
};

#endif
