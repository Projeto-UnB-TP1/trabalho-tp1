#ifndef TIMESTAMP_HPP
#define TIMESTAMP_HPP

#include <string>
#include <stdexcept>

/**
 * @brief Domínio que representa um instante no tempo (data e horário).
 *
 * @details Formato válido: <tt>DIA-MES-ANO-HORARIO</tt>.
 * - DIA é número de 1 a 31, com um ou dois dígitos;
 * - MES é sigla: JAN, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV, DEZ;
 * - ANO é número de 2000 a 2099;
 * - HORARIO é valor de 00:00 a 23:59, no formato HH:MM;
 * - a data deve existir no calendário, considerando anos bissextos.
 *
 * Exemplos válidos: "29-FEV-2024-13:45", "1-JAN-2000-00:00", "05-MAR-2026-09:05".
 * Exemplos inválidos: "29-FEV-2026-12:30" (2026 não é bissexto),
 * "31-ABR-2026-10:00" (abril tem 30 dias), "10-JAN-2026-24:00".
 */
class Timestamp{
  private:
  static const int ANO_MINIMO = 2000;
  static const int ANO_MAXIMO = 2099;
  static const std::string MESES[12];

  std::string valor;

  void separarCampos(std::string valor, int& dia, int& mes, int& ano, int& hora, int& minuto) const;
  bool soDigitos(std::string texto) const;
  int numeroDoMes(std::string sigla) const;
  bool bissexto(int ano) const;
  int diasNoMes(int mes, int ano) const;

  public:

  /**
   * @brief Define o valor do timestamp.
   * @param valor Texto no formato DIA-MES-ANO-HORARIO.
   * @throw std::invalid_argument Se o valor não estiver no formato válido ou se a data não existir.
   *        Nesse caso, o valor armazenado anteriormente não é alterado.
   */
  void setValor(std::string valor);

  /**
   * @brief Retorna o valor do timestamp.
   * @return std::string Texto no formato DIA-MES-ANO-HORARIO.
   */
  std::string getValor() const;

  /**
   * @brief Converte o timestamp em minutos contados a partir de 01-JAN-2000-00:00.
   *
   * A diferença entre os valores convertidos de dois timestamps é a duração,
   * em minutos, entre eles. Usado no cálculo de tempo de ciclo e lead time.
   * @return long Quantidade de minutos desde 01-JAN-2000-00:00.
   */
  long converterParaMinutos() const;
};

#endif
