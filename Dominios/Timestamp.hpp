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
  bool bissexto(int ano) const;
  int diasNoMes(int mes, int ano) const;
  int numero(std::string texto, unsigned int inicio, unsigned int quantidade) const;
  int indiceMes(std::string texto, unsigned int p) const;

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

  /**
   * @brief Converte o timestamp em minutos contados a partir de 1-JAN-2000-00:00.
   *
   * A diferença entre os valores convertidos de dois timestamps é a duração, em minutos,
   * entre eles. Usado no cálculo de tempo de ciclo e lead time.
   * @return int Quantidade de minutos desde 1-JAN-2000-00:00.
   * @throw std::invalid_argument Se o timestamp ainda não tiver valor.
   */
  int converterParaMinutos() const;
};

#endif
