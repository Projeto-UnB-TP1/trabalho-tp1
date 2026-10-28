#include "testes.hpp"

// ---------------- TUPessoa ----------------

const string TUPessoa::EMAIL_VALIDO = "kaio@unb.br";
const string TUPessoa::NOME_VALIDO = "Kaio Xavier";
const string TUPessoa::SENHA_VALIDA = "abc12";
const string TUPessoa::PAPEL_VALIDO = "GESTOR";

void TUPessoa::setUp(){
    pessoa = new Pessoa();
    estado = SUCESSO;
}

void TUPessoa::tearDown(){
    delete pessoa;
}

void TUPessoa::testarCenario(){
    Email email;
    email.setValor(EMAIL_VALIDO);
    pessoa->setEmail(email);
    if (pessoa->getEmail().getValor() != EMAIL_VALIDO)
        estado = FALHA;

    Nome nome;
    nome.setValor(NOME_VALIDO);
    pessoa->setNome(nome);
    if (pessoa->getNome().getValor() != NOME_VALIDO)
        estado = FALHA;

    Senha senha;
    senha.setValor(SENHA_VALIDA);
    pessoa->setSenha(senha);
    if (pessoa->getSenha().getValor() != SENHA_VALIDA)
        estado = FALHA;

    Papel papel;
    papel.setValor(PAPEL_VALIDO);
    pessoa->setPapel(papel);
    if (pessoa->getPapel().getValor() != PAPEL_VALIDO)
        estado = FALHA;
}

int TUPessoa::run(){
    setUp();
    testarCenario();
    tearDown();
    return estado;
}

// ---------------- TUProjeto ----------------

const string TUProjeto::IDENTIFICADOR_VALIDO = "PRJ001";
const string TUProjeto::NOME_VALIDO = "Projeto Kanban";
const string TUProjeto::DESCRICAO_VALIDA = "Sistema de gestao Kanban.";
const string TUProjeto::INICIO_VALIDO = "1-SET-2026-08:00";
const string TUProjeto::TERMINO_VALIDO = "30-NOV-2026-18:00";
const string TUProjeto::EMAIL_GESTOR_VALIDO = "kaio@unb.br";

void TUProjeto::setUp(){
    projeto = new Projeto();
    estado = SUCESSO;
}

void TUProjeto::tearDown(){
    delete projeto;
}

void TUProjeto::testarCenario(){
    Identificador identificador;
    identificador.setValor(IDENTIFICADOR_VALIDO);
    projeto->setIdentificador(identificador);
    if (projeto->getIdentificador().getValor() != IDENTIFICADOR_VALIDO)
        estado = FALHA;

    Nome nome;
    nome.setValor(NOME_VALIDO);
    projeto->setNome(nome);
    if (projeto->getNome().getValor() != NOME_VALIDO)
        estado = FALHA;

    Texto descricao;
    descricao.setValor(DESCRICAO_VALIDA);
    projeto->setDescricao(descricao);
    if (projeto->getDescricao().getValor() != DESCRICAO_VALIDA)
        estado = FALHA;

    Timestamp inicio;
    inicio.setValor(INICIO_VALIDO);
    projeto->setInicio(inicio);
    if (projeto->getInicio().getValor() != INICIO_VALIDO)
        estado = FALHA;

    Timestamp termino;
    termino.setValor(TERMINO_VALIDO);
    projeto->setTermino(termino);
    if (projeto->getTermino().getValor() != TERMINO_VALIDO)
        estado = FALHA;

    Email emailGestor;
    emailGestor.setValor(EMAIL_GESTOR_VALIDO);
    projeto->setEmailGestor(emailGestor);
    if (projeto->getEmailGestor().getValor() != EMAIL_GESTOR_VALIDO)
        estado = FALHA;
}

int TUProjeto::run(){
    setUp();
    testarCenario();
    tearDown();
    return estado;
}

// ---------------- TUQuadro ----------------

const string TUQuadro::IDENTIFICADOR_VALIDO = "QDR001";
const string TUQuadro::NOME_VALIDO = "Quadro Geral";
const string TUQuadro::IDENTIFICADOR_PROJETO_VALIDO = "PRJ001";

void TUQuadro::setUp(){
    quadro = new Quadro();
    estado = SUCESSO;
}

void TUQuadro::tearDown(){
    delete quadro;
}

void TUQuadro::testarCenario(){
    Identificador identificador;
    identificador.setValor(IDENTIFICADOR_VALIDO);
    quadro->setIdentificador(identificador);
    if (quadro->getIdentificador().getValor() != IDENTIFICADOR_VALIDO)
        estado = FALHA;

    Nome nome;
    nome.setValor(NOME_VALIDO);
    quadro->setNome(nome);
    if (quadro->getNome().getValor() != NOME_VALIDO)
        estado = FALHA;

    Limite limite;
    limite.setValor(LIMITE_VALIDO);
    quadro->setLimite(limite);
    if (quadro->getLimite().getValor() != LIMITE_VALIDO)
        estado = FALHA;

    Identificador identificadorProjeto;
    identificadorProjeto.setValor(IDENTIFICADOR_PROJETO_VALIDO);
    quadro->setIdentificadorProjeto(identificadorProjeto);
    if (quadro->getIdentificadorProjeto().getValor() != IDENTIFICADOR_PROJETO_VALIDO)
        estado = FALHA;
}

int TUQuadro::run(){
    setUp();
    testarCenario();
    tearDown();
    return estado;
}

// ---------------- TUCartaoDeAtividade ----------------

const string TUCartaoDeAtividade::IDENTIFICADOR_VALIDO = "CRT001";
const string TUCartaoDeAtividade::NOME_VALIDO = "Tela de login";
const string TUCartaoDeAtividade::DESCRICAO_VALIDA = "Criar tela de login.";
const string TUCartaoDeAtividade::PRIORIDADE_VALIDA = "ALTA";
const string TUCartaoDeAtividade::ESTADO_VALIDO = "A FAZER";
const string TUCartaoDeAtividade::TAMANHO_VALIDO = "MEDIO";
const string TUCartaoDeAtividade::ENTRADA_VALIDA = "1-OUT-2026-08:00";
const string TUCartaoDeAtividade::INICIO_VALIDO = "2-OUT-2026-09:30";
const string TUCartaoDeAtividade::TERMINO_VALIDO = "5-OUT-2026-17:45";
const string TUCartaoDeAtividade::IDENTIFICADOR_QUADRO_VALIDO = "QDR001";

void TUCartaoDeAtividade::setUp(){
    cartao = new CartaoDeAtividade();
    estado = SUCESSO;
}

void TUCartaoDeAtividade::tearDown(){
    delete cartao;
}

void TUCartaoDeAtividade::testarCenario(){
    Identificador identificador;
    identificador.setValor(IDENTIFICADOR_VALIDO);
    cartao->setIdentificador(identificador);
    if (cartao->getIdentificador().getValor() != IDENTIFICADOR_VALIDO)
        estado = FALHA;

    Nome nome;
    nome.setValor(NOME_VALIDO);
    cartao->setNome(nome);
    if (cartao->getNome().getValor() != NOME_VALIDO)
        estado = FALHA;

    Texto descricao;
    descricao.setValor(DESCRICAO_VALIDA);
    cartao->setDescricao(descricao);
    if (cartao->getDescricao().getValor() != DESCRICAO_VALIDA)
        estado = FALHA;

    Prioridade prioridade;
    prioridade.setValor(PRIORIDADE_VALIDA);
    cartao->setPrioridade(prioridade);
    if (cartao->getPrioridade().getValor() != PRIORIDADE_VALIDA)
        estado = FALHA;

    Estado estadoCartao;
    estadoCartao.setValor(ESTADO_VALIDO);
    cartao->setEstado(estadoCartao);
    if (cartao->getEstado().getValor() != ESTADO_VALIDO)
        estado = FALHA;

    Tamanho tamanho;
    tamanho.setValor(TAMANHO_VALIDO);
    cartao->setTamanho(tamanho);
    if (cartao->getTamanho().getValor() != TAMANHO_VALIDO)
        estado = FALHA;

    Timestamp entrada;
    entrada.setValor(ENTRADA_VALIDA);
    cartao->setEntrada(entrada);
    if (cartao->getEntrada().getValor() != ENTRADA_VALIDA)
        estado = FALHA;

    Timestamp inicio;
    inicio.setValor(INICIO_VALIDO);
    cartao->setInicio(inicio);
    if (cartao->getInicio().getValor() != INICIO_VALIDO)
        estado = FALHA;

    Timestamp termino;
    termino.setValor(TERMINO_VALIDO);
    cartao->setTermino(termino);
    if (cartao->getTermino().getValor() != TERMINO_VALIDO)
        estado = FALHA;

    Identificador identificadorQuadro;
    identificadorQuadro.setValor(IDENTIFICADOR_QUADRO_VALIDO);
    cartao->setIdentificadorQuadro(identificadorQuadro);
    if (cartao->getIdentificadorQuadro().getValor() != IDENTIFICADOR_QUADRO_VALIDO)
        estado = FALHA;
}

int TUCartaoDeAtividade::run(){
    setUp();
    testarCenario();
    tearDown();
    return estado;
}
