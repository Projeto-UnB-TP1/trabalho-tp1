#ifndef PRIORIDADE_HPP
#define PRIORIDADE_HPP

#include <string>
#include <stdexcept>

///
/// Padrão para representação de prioridade de cartão de atividade.
///
/// Regras de formato:
///
/// - Prioridade é válida caso seja ALTA, MEDIA ou BAIXA.
///

class Prioridade{
  private:
  std::string valor;

  public:

///
/// Armazena prioridade caso a mesma seja válida.
///
/// Lança exceção caso a prioridade seja inválida.
///
/// @param valor Prioridade.
///
/// @throw invalid_argument
///

  void setValor(std::string valor);

///
/// Retorna prioridade.
///
/// @return Prioridade.
///

  std::string getValor() const;
};

#endif
