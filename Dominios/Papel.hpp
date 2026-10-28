#ifndef PAPEL_HPP
#define PAPEL_HPP

#include <string>

class Papel{
  private: 
  std:: string valor;

  public: 

  void setValor(std:: string valor);
  std:: string getValor() const;
};

#endif