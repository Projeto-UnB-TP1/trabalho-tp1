#ifndef PAPEL_HPP
#define PAPEL_HPP

#include <string>
#include <stdexcept>

///
/// Padrão para representação de papel de pessoa.
///
/// Regras de formato:
///
/// - Papel é válido caso seja GESTOR ou DESENVOLVEDOR.
///

class Papel{
  private:
  std::string valor;

  public:

///
/// Armazena papel caso o mesmo seja válido.
///
/// Lança exceção caso o papel seja inválido.
///
/// @param valor Papel.
///
/// @throw invalid_argument
///

  void setValor(std::string valor);

///
/// Retorna papel.
///
/// @return Papel.
///

  std::string getValor() const;
};

#endif
