#ifndef TESTES_HPP
#define TESTES_HPP

#include <string>
#include <stdexcept>
#include "../Entidades/Pessoa.hpp"
#include "../Entidades/Projeto.hpp"
#include "../Entidades/Quadro.hpp"
#include "../Entidades/CartaoDeAtividade.hpp"

using namespace std;

class TUPessoa {
  private:
  const static string EMAIL_VALIDO;
  const static string NOME_VALIDO;
  const static string SENHA_VALIDA;
  const static string PAPEL_VALIDO;
  Pessoa *pessoa;
  int estado;
  void setUp();
  void tearDown();
  void testarCenario();

  public:
  const static int SUCESSO = 0;
  const static int FALHA = -1;
  int run();
};

class TUProjeto {
  private:
  const static string IDENTIFICADOR_VALIDO;
  const static string NOME_VALIDO;
  const static string DESCRICAO_VALIDA;
  const static string INICIO_VALIDO;
  const static string TERMINO_VALIDO;
  const static string EMAIL_GESTOR_VALIDO;
  Projeto *projeto;
  int estado;
  void setUp();
  void tearDown();
  void testarCenario();

  public:
  const static int SUCESSO = 0;
  const static int FALHA = -1;
  int run();
};

class TUQuadro {
  private:
  const static string IDENTIFICADOR_VALIDO;
  const static string NOME_VALIDO;
  const static int LIMITE_VALIDO = 5;
  const static string IDENTIFICADOR_PROJETO_VALIDO;
  Quadro *quadro;
  int estado;
  void setUp();
  void tearDown();
  void testarCenario();

  public:
  const static int SUCESSO = 0;
  const static int FALHA = -1;
  int run();
};

class TUCartaoDeAtividade {
  private:
  const static string IDENTIFICADOR_VALIDO;
  const static string NOME_VALIDO;
  const static string DESCRICAO_VALIDA;
  const static string PRIORIDADE_VALIDA;
  const static string ESTADO_VALIDO;
  const static string TAMANHO_VALIDO;
  const static string ENTRADA_VALIDA;
  const static string INICIO_VALIDO;
  const static string TERMINO_VALIDO;
  const static string IDENTIFICADOR_QUADRO_VALIDO;
  CartaoDeAtividade *cartao;
  int estado;
  void setUp();
  void tearDown();
  void testarCenario();

  public:
  const static int SUCESSO = 0;
  const static int FALHA = -1;
  int run();
};

#endif
