#ifndef TIMESTAMP_HPP
#define TIMESTAMP_HPP

#include <string>
#include <stdexcept>

/**
 * @brief Classe de domínio que representa data e horário.
 * Regra de formato: DIA-MES-ANO-HORARIO, por exemplo 29-FEV-2024-13:45.
 * DIA é número de 1 a 31, com um ou dois dígitos.
 * MES é JAN, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV ou DEZ.
 * ANO é número de 2000 a 2099.
 * HORARIO é valor de 00:00 a 23:59.
 * A data deve existir, considerando anos bissextos.
 */
class Timestamp{
  private:
  std::string valor;
  void validar(std::string valor);
  bool bissexto(int ano);

  public:

  /**
   * @brief Define o valor do timestamp.
   * @param valor Texto no formato DIA-MES-ANO-HORARIO.
   * @throw std::invalid_argument Se o texto não seguir o formato ou se a data não existir.
   */
  void setValor(std::string valor);

  /**
   * @brief Retorna o valor do timestamp.
   * @return std::string O timestamp atual, no formato DIA-MES-ANO-HORARIO.
   */
  std::string getValor() const;
};

#endif
