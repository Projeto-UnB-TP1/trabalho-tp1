#include "testes.hpp"

const string TUEmail::VALOR_VALIDO = "kaio@unb.br";
const string TUEmail::VALOR_INVALIDO = ".kaio@unb.br";

void TUEmail::setUp(){
    email = new Email();
    estado = SUCESSO;
}

void TUEmail::tearDown(){
    delete email;
}

void TUEmail::testarCenarioValorValido(){
    try{
        email->setValor(VALOR_VALIDO);
        if (email->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUEmail::testarCenarioValorInvalido(){
    try{
        email->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (email->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUEmail::run(){
    setUp();
    testarCenarioValorValido();
    testarCenarioValorInvalido();
    tearDown();
    return estado;
}

const string TUEstado::VALOR_VALIDO = "FAZENDO";
const string TUEstado::VALOR_INVALIDO = "PARADO";

void TUEstado::setUp(){
    estadoDominio = new Estado();
    estado = SUCESSO;
}

void TUEstado::tearDown(){
    delete estadoDominio;
}

void TUEstado::testarCenarioValorValido(){
    try{
        estadoDominio->setValor(VALOR_VALIDO);
        if (estadoDominio->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUEstado::testarCenarioValorInvalido(){
    try{
        estadoDominio->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (estadoDominio->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUEstado::run(){
    setUp();
    testarCenarioValorValido();
    testarCenarioValorInvalido();
    tearDown();
    return estado;
}

const string TUIdentificador::VALOR_VALIDO = "ABC123";
const string TUIdentificador::VALOR_INVALIDO = "AB1234";

void TUIdentificador::setUp(){
    identificador = new Identificador();
    estado = SUCESSO;
}

void TUIdentificador::tearDown(){
    delete identificador;
}

void TUIdentificador::testarCenarioValorValido(){
    try{
        identificador->setValor(VALOR_VALIDO);
        if (identificador->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUIdentificador::testarCenarioValorInvalido(){
    try{
        identificador->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (identificador->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUIdentificador::run(){
    setUp();
    testarCenarioValorValido();
    testarCenarioValorInvalido();
    tearDown();
    return estado;
}

void TULimite::setUp(){
    limite = new Limite();
    estado = SUCESSO;
}

void TULimite::tearDown(){
    delete limite;
}

void TULimite::testarCenarioValorValido(){
    try{
        limite->setValor(VALOR_VALIDO);
        if (limite->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TULimite::testarCenarioValorInvalido(){
    try{
        limite->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (limite->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TULimite::run(){
    setUp();
    testarCenarioValorValido();
    testarCenarioValorInvalido();
    tearDown();
    return estado;
}

const string TUNome::VALOR_VALIDO = "Kaio Xavier";
const string TUNome::VALOR_INVALIDO = "Kaio3";

void TUNome::setUp(){
    nome = new Nome();
    estado = SUCESSO;
}

void TUNome::tearDown(){
    delete nome;
}

void TUNome::testarCenarioValorValido(){
    try{
        nome->setValor(VALOR_VALIDO);
        if (nome->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUNome::testarCenarioValorInvalido(){
    try{
        nome->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (nome->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUNome::run(){
    setUp();
    testarCenarioValorValido();
    testarCenarioValorInvalido();
    tearDown();
    return estado;
}

const string TUPapel::VALOR_VALIDO = "GESTOR";
const string TUPapel::VALOR_INVALIDO = "CHEFE";

void TUPapel::setUp(){
    papel = new Papel();
    estado = SUCESSO;
}

void TUPapel::tearDown(){
    delete papel;
}

void TUPapel::testarCenarioValorValido(){
    try{
        papel->setValor(VALOR_VALIDO);
        if (papel->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUPapel::testarCenarioValorInvalido(){
    try{
        papel->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (papel->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUPapel::run(){
    setUp();
    testarCenarioValorValido();
    testarCenarioValorInvalido();
    tearDown();
    return estado;
}

const string TUPrioridade::VALOR_VALIDO = "ALTA";
const string TUPrioridade::VALOR_INVALIDO = "URGENTE";

void TUPrioridade::setUp(){
    prioridade = new Prioridade();
    estado = SUCESSO;
}

void TUPrioridade::tearDown(){
    delete prioridade;
}

void TUPrioridade::testarCenarioValorValido(){
    try{
        prioridade->setValor(VALOR_VALIDO);
        if (prioridade->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUPrioridade::testarCenarioValorInvalido(){
    try{
        prioridade->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (prioridade->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUPrioridade::run(){
    setUp();
    testarCenarioValorValido();
    testarCenarioValorInvalido();
    tearDown();
    return estado;
}

const string TUSenha::VALOR_VALIDO = "abc12";
const string TUSenha::VALOR_INVALIDO = "abcde";

void TUSenha::setUp(){
    senha = new Senha();
    estado = SUCESSO;
}

void TUSenha::tearDown(){
    delete senha;
}

void TUSenha::testarCenarioValorValido(){
    try{
        senha->setValor(VALOR_VALIDO);
        if (senha->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUSenha::testarCenarioValorInvalido(){
    try{
        senha->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (senha->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUSenha::run(){
    setUp();
    testarCenarioValorValido();
    testarCenarioValorInvalido();
    tearDown();
    return estado;
}

const string TUTamanho::VALOR_VALIDO = "GRANDE";
const string TUTamanho::VALOR_INVALIDO = "ENORME";

void TUTamanho::setUp(){
    tamanho = new Tamanho();
    estado = SUCESSO;
}

void TUTamanho::tearDown(){
    delete tamanho;
}

void TUTamanho::testarCenarioValorValido(){
    try{
        tamanho->setValor(VALOR_VALIDO);
        if (tamanho->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUTamanho::testarCenarioValorInvalido(){
    try{
        tamanho->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (tamanho->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUTamanho::run(){
    setUp();
    testarCenarioValorValido();
    testarCenarioValorInvalido();
    tearDown();
    return estado;
}

const string TUTexto::VALOR_VALIDO = "Texto valido.";
const string TUTexto::VALOR_INVALIDO = "texto invalido.";

void TUTexto::setUp(){
    texto = new Texto();
    estado = SUCESSO;
}

void TUTexto::tearDown(){
    delete texto;
}

void TUTexto::testarCenarioValorValido(){
    try{
        texto->setValor(VALOR_VALIDO);
        if (texto->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUTexto::testarCenarioValorInvalido(){
    try{
        texto->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (texto->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUTexto::run(){
    setUp();
    testarCenarioValorValido();
    testarCenarioValorInvalido();
    tearDown();
    return estado;
}

const string TUTimestamp::VALOR_VALIDO = "29-FEV-2024-13:45";
const string TUTimestamp::VALOR_INVALIDO = "29-FEV-2023-13:45";

void TUTimestamp::setUp(){
    timestamp = new Timestamp();
    estado = SUCESSO;
}

void TUTimestamp::tearDown(){
    delete timestamp;
}

void TUTimestamp::testarCenarioValorValido(){
    try{
        timestamp->setValor(VALOR_VALIDO);
        if (timestamp->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUTimestamp::testarCenarioValorInvalido(){
    try{
        timestamp->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (timestamp->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUTimestamp::run(){
    setUp();
    testarCenarioValorValido();
    testarCenarioValorInvalido();
    tearDown();
    return estado;
}

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
