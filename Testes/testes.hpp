#ifndef TESTES_HPP
#define TESTES_HPP

#include <string>
#include <stdexcept>
#include "../Entidades/Pessoa.hpp"
#include "../Entidades/Projeto.hpp"
#include "../Entidades/Quadro.hpp"
#include "../Entidades/CartaoDeAtividade.hpp"

using namespace std;

class TUEmail {
  private:
  const static string VALOR_VALIDO;
  const static string VALOR_INVALIDO;
  Email *email;
  int estado;
  void setUp();
  void tearDown();
  void testarCenarioValorValido();
  void testarCenarioValorInvalido();

  public:
  const static int SUCESSO = 0;
  const static int FALHA = -1;
  int run();
};

class TUEstado {
  private:
  const static string VALOR_VALIDO;
  const static string VALOR_INVALIDO;
  Estado *estadoDominio;
  int estado;
  void setUp();
  void tearDown();
  void testarCenarioValorValido();
  void testarCenarioValorInvalido();

  public:
  const static int SUCESSO = 0;
  const static int FALHA = -1;
  int run();
};

class TUIdentificador {
  private:
  const static string VALOR_VALIDO;
  const static string VALOR_INVALIDO;
  Identificador *identificador;
  int estado;
  void setUp();
  void tearDown();
  void testarCenarioValorValido();
  void testarCenarioValorInvalido();

  public:
  const static int SUCESSO = 0;
  const static int FALHA = -1;
  int run();
};

class TULimite {
  private:
  const static int VALOR_VALIDO = 20;
  const static int VALOR_INVALIDO = 30;
  Limite *limite;
  int estado;
  void setUp();
  void tearDown();
  void testarCenarioValorValido();
  void testarCenarioValorInvalido();

  public:
  const static int SUCESSO = 0;
  const static int FALHA = -1;
  int run();
};

class TUNome {
  private:
  const static string VALOR_VALIDO;
  const static string VALOR_INVALIDO;
  Nome *nome;
  int estado;
  void setUp();
  void tearDown();
  void testarCenarioValorValido();
  void testarCenarioValorInvalido();

  public:
  const static int SUCESSO = 0;
  const static int FALHA = -1;
  int run();
};

class TUPapel {
  private:
  const static string VALOR_VALIDO;
  const static string VALOR_INVALIDO;
  Papel *papel;
  int estado;
  void setUp();
  void tearDown();
  void testarCenarioValorValido();
  void testarCenarioValorInvalido();

  public:
  const static int SUCESSO = 0;
  const static int FALHA = -1;
  int run();
};

class TUPrioridade {
  private:
  const static string VALOR_VALIDO;
  const static string VALOR_INVALIDO;
  Prioridade *prioridade;
  int estado;
  void setUp();
  void tearDown();
  void testarCenarioValorValido();
  void testarCenarioValorInvalido();

  public:
  const static int SUCESSO = 0;
  const static int FALHA = -1;
  int run();
};

class TUSenha {
  private:
  const static string VALOR_VALIDO;
  const static string VALOR_INVALIDO;
  Senha *senha;
  int estado;
  void setUp();
  void tearDown();
  void testarCenarioValorValido();
  void testarCenarioValorInvalido();

  public:
  const static int SUCESSO = 0;
  const static int FALHA = -1;
  int run();
};

class TUTamanho {
  private:
  const static string VALOR_VALIDO;
  const static string VALOR_INVALIDO;
  Tamanho *tamanho;
  int estado;
  void setUp();
  void tearDown();
  void testarCenarioValorValido();
  void testarCenarioValorInvalido();

  public:
  const static int SUCESSO = 0;
  const static int FALHA = -1;
  int run();
};

class TUTexto {
  private:
  const static string VALOR_VALIDO;
  const static string VALOR_INVALIDO;
  Texto *texto;
  int estado;
  void setUp();
  void tearDown();
  void testarCenarioValorValido();
  void testarCenarioValorInvalido();

  public:
  const static int SUCESSO = 0;
  const static int FALHA = -1;
  int run();
};

class TUTimestamp {
  private:
  const static string VALOR_VALIDO;
  const static string VALOR_INVALIDO;
  Timestamp *timestamp;
  int estado;
  void setUp();
  void tearDown();
  void testarCenarioValorValido();
  void testarCenarioValorInvalido();

  public:
  const static int SUCESSO = 0;
  const static int FALHA = -1;
  int run();
};

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
