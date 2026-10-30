#ifndef TIMESTAMP_HPP
#define TIMESTAMP_HPP

#include <string>
#include <stdexcept>

///
/// Padrão para representação de data e horário.
///
/// Regras de formato:
///
/// - Formato DIA-MES-ANO-HORARIO, por exemplo 29-FEV-2024-13:45.
/// - DIA de 1 a 31, com um ou dois dígitos.
/// - MES é JAN, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV ou DEZ.
/// - ANO de 2000 a 2099.
/// - HORARIO de 00:00 a 23:59.
/// - Data existente, considerando anos bissextos.
///

class Timestamp{
  private:
  std::string valor;
  void validar(std::string valor);
  bool bissexto(int ano) const;
  int diasNoMes(int mes, int ano) const;
  int numero(std::string texto, unsigned int inicio, unsigned int quantidade) const;
  int indiceMes(std::string texto, unsigned int p) const;

  public:

///
/// Armazena data e horário caso os mesmos sejam válidos.
///
/// Lança exceção caso a data ou o horário sejam inválidos.
///
/// @param valor Data e horário.
///
/// @throw invalid_argument
///

  void setValor(std::string valor);

///
/// Retorna data e horário.
///
/// @return Data e horário.
///

  std::string getValor() const;

///
/// Retorna quantidade de minutos desde 1-JAN-2000-00:00.
///
/// Lança exceção caso não exista data e horário armazenados.
///
/// @return Quantidade de minutos.
///
/// @throw invalid_argument
///

  int converterParaMinutos() const;
};

#endif
