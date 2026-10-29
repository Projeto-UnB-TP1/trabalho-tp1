#include "ControladorasApresentacao.hpp"

string Tela::lerCampo(string rotulo){
    char campo[400];
    campo[0] = '\0';
    cout << rotulo;
    cin.getline(campo, sizeof(campo));
    return string(campo);
}

int Tela::lerOpcao(){
    string campo = Tela::lerCampo("Opcao: ");
    if (!cin){
        return 0;
    }
    if (campo.length() != 1 || !(campo[0] >= '0' && campo[0] <= '9')){
        return -1;
    }
    return campo[0] - 48;
}

int Tela::converterNumero(string texto){
    if (texto.length() == 0 || texto.length() > 3){
        return 0;
    }
    int resultado = 0;
    for (unsigned int i = 0; i < texto.length(); i++){
        if (!(texto[i] >= '0' && texto[i] <= '9')){
            return 0;
        }
        resultado = resultado * 10 + (texto[i] - '0');
    }
    return resultado;
}

bool Tela::lerIdentificador(string rotulo, Identificador *identificador){
    try{
        identificador->setValor(Tela::lerCampo(rotulo));
    }
    catch(invalid_argument &exp){
        cout << "Dado invalido: " << exp.what() << endl;
        return false;
    }
    return true;
}

bool Tela::ehGestor(IServicoPessoas *cntr, Email email){
    Pessoa pessoa;
    pessoa.setEmail(email);
    if (!cntr->ler(&pessoa)){
        return false;
    }
    return pessoa.getPapel().getValor() == "GESTOR";
}

string Tela::valorOuTraco(string valor){
    if (valor.length() == 0){
        return "-";
    }
    return valor;
}

void Tela::mostrarTempo(string rotulo, int minutos){
    cout << rotulo << minutos / 1440 << " dia(s), " << (minutos % 1440) / 60 << " hora(s) e "
         << minutos % 60 << " minuto(s)." << endl;
}

void Tela::mostrarProjeto(Projeto projeto){
    cout << "Identificador: " << projeto.getIdentificador().getValor() << endl;
    cout << "Nome         : " << projeto.getNome().getValor() << endl;
    cout << "Descricao    : " << projeto.getDescricao().getValor() << endl;
    cout << "Inicio       : " << projeto.getInicio().getValor() << endl;
    cout << "Termino      : " << projeto.getTermino().getValor() << endl;
    cout << "Gestor       : " << projeto.getEmailGestor().getValor() << endl;
}

void Tela::mostrarQuadro(Quadro quadro){
    cout << "Identificador: " << quadro.getIdentificador().getValor() << endl;
    cout << "Nome         : " << quadro.getNome().getValor() << endl;
    cout << "Limite WIP   : " << quadro.getLimite().getValor() << endl;
    cout << "Projeto      : " << quadro.getIdentificadorProjeto().getValor() << endl;
}

void Tela::mostrarCartao(CartaoDeAtividade cartao){
    cout << "Identificador: " << cartao.getIdentificador().getValor() << endl;
    cout << "Nome         : " << cartao.getNome().getValor() << endl;
    cout << "Descricao    : " << cartao.getDescricao().getValor() << endl;
    cout << "Prioridade   : " << cartao.getPrioridade().getValor() << endl;
    cout << "Tamanho      : " << cartao.getTamanho().getValor() << endl;
    cout << "Estado       : " << cartao.getEstado().getValor() << endl;
    cout << "Entrada      : " << Tela::valorOuTraco(cartao.getEntrada().getValor()) << endl;
    cout << "Inicio       : " << Tela::valorOuTraco(cartao.getInicio().getValor()) << endl;
    cout << "Termino      : " << Tela::valorOuTraco(cartao.getTermino().getValor()) << endl;
    cout << "Quadro       : " << cartao.getIdentificadorQuadro().getValor() << endl;
}

void Tela::listarIdentificadores(list<Identificador> identificadores, string vazio){
    if (identificadores.begin() == identificadores.end()){
        cout << vazio << endl;
        return;
    }
    for (list<Identificador>::iterator identificador = identificadores.begin(); identificador != identificadores.end(); identificador++){
        cout << identificador->getValor() << endl;
    }
}

void CntrApresentacaoControle::setCntrApresentacaoPessoas(IApresentacaoPessoas *cntr){
    cntrApresentacaoPessoas = cntr;
}

void CntrApresentacaoControle::setCntrApresentacaoProjetos(IApresentacaoProjetos *cntr){
    cntrApresentacaoProjetos = cntr;
}

void CntrApresentacaoControle::setCntrApresentacaoQuadros(IApresentacaoQuadros *cntr){
    cntrApresentacaoQuadros = cntr;
}

void CntrApresentacaoControle::setCntrApresentacaoCartoes(IApresentacaoCartoes *cntr){
    cntrApresentacaoCartoes = cntr;
}

void CntrApresentacaoControle::setCntrServicoPessoas(IServicoPessoas *cntr){
    cntrServicoPessoas = cntr;
}

void CntrApresentacaoControle::executar(){
    bool apresentar = true;
    while (apresentar){
        cout << endl << "SISTEMA KANBAN" << endl;
        cout << "1 - Entrar." << endl;
        cout << "2 - Cadastrar pessoa." << endl;
        cout << "0 - Encerrar." << endl;
        switch (Tela::lerOpcao()){
            case 1: if (cntrApresentacaoPessoas->autenticar(&email)){
                        executarSessao();
                    } else {
                        cout << "Falha na autenticacao." << endl;
                    }
                    break;
            case 2: cntrApresentacaoPessoas->cadastrar();
                    break;
            case 0: apresentar = false;
                    break;
            default: cout << "Opcao invalida." << endl;
        }
    }
}

void CntrApresentacaoControle::executarSessao(){
    Pessoa pessoa;
    pessoa.setEmail(email);
    while (cntrServicoPessoas->ler(&pessoa)){
        cout << endl << "MENU PRINCIPAL - " << pessoa.getNome().getValor() << " (" << pessoa.getPapel().getValor() << ")" << endl;
        cout << "1 - Pessoas." << endl;
        cout << "2 - Projetos." << endl;
        cout << "3 - Quadros." << endl;
        cout << "4 - Cartoes de atividade." << endl;
        cout << "0 - Sair." << endl;
        switch (Tela::lerOpcao()){
            case 1: cntrApresentacaoPessoas->executar(email);
                    break;
            case 2: cntrApresentacaoProjetos->executar(email);
                    break;
            case 3: cntrApresentacaoQuadros->executar(email);
                    break;
            case 4: cntrApresentacaoCartoes->executar(email);
                    break;
            case 0: return;
            default: cout << "Opcao invalida." << endl;
        }
    }
}

void CntrApresentacaoPessoas::setCntrServicoPessoas(IServicoPessoas *cntr){
    this->cntr = cntr;
}

bool CntrApresentacaoPessoas::autenticar(Email *email){
    Senha senha;
    cout << endl << "AUTENTICACAO" << endl;
    string campoEmail = Tela::lerCampo("E-mail: ");
    string campoSenha = Tela::lerCampo("Senha : ");
    try{
        email->setValor(campoEmail);
        senha.setValor(campoSenha);
    }
    catch(invalid_argument &exp){
        cout << "Dado invalido: " << exp.what() << endl;
        return false;
    }
    return cntr->autenticar(*email, senha);
}

void CntrApresentacaoPessoas::cadastrar(){
    Email email;
    Nome nome;
    Senha senha;
    Papel papel;
    cout << endl << "CADASTRAR PESSOA" << endl;
    string campoEmail = Tela::lerCampo("E-mail                       : ");
    string campoNome = Tela::lerCampo("Nome                         : ");
    string campoSenha = Tela::lerCampo("Senha                        : ");
    string campoPapel = Tela::lerCampo("Papel (GESTOR/DESENVOLVEDOR) : ");
    try{
        email.setValor(campoEmail);
        nome.setValor(campoNome);
        senha.setValor(campoSenha);
        papel.setValor(campoPapel);
    }
    catch(invalid_argument &exp){
        cout << "Dado invalido: " << exp.what() << endl;
        return;
    }
    Pessoa pessoa;
    pessoa.setEmail(email);
    pessoa.setNome(nome);
    pessoa.setSenha(senha);
    pessoa.setPapel(papel);
    if (cntr->criar(pessoa)){
        cout << "Pessoa cadastrada." << endl;
    } else {
        cout << "Falha: e-mail ja cadastrado." << endl;
    }
}

void CntrApresentacaoPessoas::executar(Email email){
    bool apresentar = true;
    while (apresentar){
        cout << endl << "PESSOAS" << endl;
        cout << "1 - Ler pessoa." << endl;
        cout << "2 - Atualizar minha conta." << endl;
        cout << "3 - Excluir minha conta." << endl;
        cout << "4 - Listar pessoas." << endl;
        cout << "0 - Voltar." << endl;
        switch (Tela::lerOpcao()){
            case 1: ler();
                    break;
            case 2: atualizar(email);
                    break;
            case 3: if (excluir(email)){
                        apresentar = false;
                    }
                    break;
            case 4: listar();
                    break;
            case 0: apresentar = false;
                    break;
            default: cout << "Opcao invalida." << endl;
        }
    }
}

void CntrApresentacaoPessoas::ler(){
    Email email;
    try{
        email.setValor(Tela::lerCampo("E-mail da pessoa: "));
    }
    catch(invalid_argument &exp){
        cout << "Dado invalido: " << exp.what() << endl;
        return;
    }
    Pessoa pessoa;
    pessoa.setEmail(email);
    if (!cntr->ler(&pessoa)){
        cout << "Falha: pessoa nao encontrada." << endl;
        return;
    }
    cout << "E-mail: " << pessoa.getEmail().getValor() << endl;
    cout << "Nome  : " << pessoa.getNome().getValor() << endl;
    cout << "Papel : " << pessoa.getPapel().getValor() << endl;
}

void CntrApresentacaoPessoas::atualizar(Email email){
    Pessoa pessoa;
    pessoa.setEmail(email);
    if (!cntr->ler(&pessoa)){
        cout << "Falha: pessoa nao encontrada." << endl;
        return;
    }
    cout << "Nome atual: " << pessoa.getNome().getValor() << endl;
    cout << "Digite os novos valores (Enter mantem o atual)." << endl;
    string campoNome = Tela::lerCampo("Nome : ");
    string campoSenha = Tela::lerCampo("Senha: ");
    Nome nome;
    Senha senha;
    try{
        if (campoNome.length() > 0){
            nome.setValor(campoNome);
            pessoa.setNome(nome);
        }
        if (campoSenha.length() > 0){
            senha.setValor(campoSenha);
            pessoa.setSenha(senha);
        }
    }
    catch(invalid_argument &exp){
        cout << "Dado invalido: " << exp.what() << endl;
        return;
    }
    if (cntr->atualizar(pessoa)){
        cout << "Conta atualizada." << endl;
    } else {
        cout << "Falha ao atualizar a conta." << endl;
    }
}

bool CntrApresentacaoPessoas::excluir(Email email){
    string confirmacao = Tela::lerCampo("Confirma a exclusao da sua conta? (S/N): ");
    if (confirmacao != "S" && confirmacao != "s"){
        cout << "Exclusao cancelada." << endl;
        return false;
    }
    if (cntr->excluir(email)){
        cout << "Conta excluida. Sessao encerrada." << endl;
        return true;
    }
    cout << "Falha: a pessoa e gestora de algum projeto." << endl;
    return false;
}

void CntrApresentacaoPessoas::listar(){
    list<Email> emails = cntr->listar();
    if (emails.begin() == emails.end()){
        cout << "Nenhuma pessoa cadastrada." << endl;
        return;
    }
    for (list<Email>::iterator email = emails.begin(); email != emails.end(); email++){
        cout << email->getValor() << endl;
    }
}

void CntrApresentacaoProjetos::setCntrServicoProjetos(IServicoProjetos *cntr){
    this->cntr = cntr;
}

void CntrApresentacaoProjetos::setCntrServicoPessoas(IServicoPessoas *cntr){
    cntrServicoPessoas = cntr;
}

void CntrApresentacaoProjetos::executar(Email email){
    bool apresentar = true;
    while (apresentar){
        bool gestor = Tela::ehGestor(cntrServicoPessoas, email);
        cout << endl << "PROJETOS" << endl;
        if (gestor){
            cout << "1 - Criar projeto." << endl;
        }
        cout << "2 - Ler projeto." << endl;
        if (gestor){
            cout << "3 - Atualizar projeto." << endl;
            cout << "4 - Excluir projeto." << endl;
        }
        cout << "5 - Listar projetos." << endl;
        cout << "0 - Voltar." << endl;
        int opcao = Tela::lerOpcao();
        if (!gestor && (opcao == 1 || opcao == 3 || opcao == 4)){
            opcao = -1;
        }
        switch (opcao){
            case 1: criar(email);
                    break;
            case 2: ler();
                    break;
            case 3: atualizar();
                    break;
            case 4: excluir();
                    break;
            case 5: listar();
                    break;
            case 0: apresentar = false;
                    break;
            default: cout << "Opcao invalida." << endl;
        }
    }
}

void CntrApresentacaoProjetos::criar(Email email){
    Identificador identificador;
    Nome nome;
    Texto descricao;
    Timestamp inicio;
    Timestamp termino;
    cout << endl << "CRIAR PROJETO" << endl;
    string campoIdentificador = Tela::lerCampo("Identificador (ex.: PRJ001)        : ");
    string campoNome = Tela::lerCampo("Nome                               : ");
    string campoDescricao = Tela::lerCampo("Descricao                          : ");
    string campoInicio = Tela::lerCampo("Inicio (ex.: 01-JAN-2026-08:00)    : ");
    string campoTermino = Tela::lerCampo("Termino (ex.: 30-JUN-2026-18:00)   : ");
    try{
        identificador.setValor(campoIdentificador);
        nome.setValor(campoNome);
        descricao.setValor(campoDescricao);
        inicio.setValor(campoInicio);
        termino.setValor(campoTermino);
    }
    catch(invalid_argument &exp){
        cout << "Dado invalido: " << exp.what() << endl;
        return;
    }
    Projeto projeto;
    projeto.setIdentificador(identificador);
    projeto.setNome(nome);
    projeto.setDescricao(descricao);
    projeto.setInicio(inicio);
    projeto.setTermino(termino);
    projeto.setEmailGestor(email);
    if (cntr->criar(projeto)){
        cout << "Projeto criado." << endl;
    } else {
        cout << "Falha: identificador ja cadastrado." << endl;
    }
}

void CntrApresentacaoProjetos::ler(){
    Identificador identificador;
    if (!Tela::lerIdentificador("Identificador do projeto: ", &identificador)){
        return;
    }
    Projeto projeto;
    projeto.setIdentificador(identificador);
    if (!cntr->ler(&projeto)){
        cout << "Falha: projeto nao encontrado." << endl;
        return;
    }
    Tela::mostrarProjeto(projeto);
}

void CntrApresentacaoProjetos::atualizar(){
    Identificador identificador;
    if (!Tela::lerIdentificador("Identificador do projeto: ", &identificador)){
        return;
    }
    Projeto projeto;
    projeto.setIdentificador(identificador);
    if (!cntr->ler(&projeto)){
        cout << "Falha: projeto nao encontrado." << endl;
        return;
    }
    Tela::mostrarProjeto(projeto);
    cout << "Digite os novos valores (Enter mantem o atual)." << endl;
    string campoNome = Tela::lerCampo("Nome     : ");
    string campoDescricao = Tela::lerCampo("Descricao: ");
    string campoInicio = Tela::lerCampo("Inicio   : ");
    string campoTermino = Tela::lerCampo("Termino  : ");
    Nome nome;
    Texto descricao;
    Timestamp inicio;
    Timestamp termino;
    try{
        if (campoNome.length() > 0){
            nome.setValor(campoNome);
            projeto.setNome(nome);
        }
        if (campoDescricao.length() > 0){
            descricao.setValor(campoDescricao);
            projeto.setDescricao(descricao);
        }
        if (campoInicio.length() > 0){
            inicio.setValor(campoInicio);
            projeto.setInicio(inicio);
        }
        if (campoTermino.length() > 0){
            termino.setValor(campoTermino);
            projeto.setTermino(termino);
        }
    }
    catch(invalid_argument &exp){
        cout << "Dado invalido: " << exp.what() << endl;
        return;
    }
    if (cntr->atualizar(projeto)){
        cout << "Projeto atualizado." << endl;
    } else {
        cout << "Falha ao atualizar o projeto." << endl;
    }
}

void CntrApresentacaoProjetos::excluir(){
    Identificador identificador;
    if (!Tela::lerIdentificador("Identificador do projeto: ", &identificador)){
        return;
    }
    if (cntr->excluir(identificador)){
        cout << "Projeto excluido." << endl;
    } else {
        cout << "Falha: projeto nao encontrado ou possui quadros." << endl;
    }
}

void CntrApresentacaoProjetos::listar(){
    Tela::listarIdentificadores(cntr->listar(), "Nenhum projeto cadastrado.");
}

void CntrApresentacaoQuadros::setCntrServicoQuadros(IServicoQuadros *cntr){
    this->cntr = cntr;
}

void CntrApresentacaoQuadros::setCntrServicoPessoas(IServicoPessoas *cntr){
    cntrServicoPessoas = cntr;
}

void CntrApresentacaoQuadros::executar(Email email){
    bool apresentar = true;
    while (apresentar){
        bool gestor = Tela::ehGestor(cntrServicoPessoas, email);
        cout << endl << "QUADROS" << endl;
        if (gestor){
            cout << "1 - Criar quadro." << endl;
        }
        cout << "2 - Ler quadro." << endl;
        if (gestor){
            cout << "3 - Atualizar quadro." << endl;
            cout << "4 - Excluir quadro." << endl;
        }
        cout << "5 - Listar quadros de um projeto." << endl;
        cout << "0 - Voltar." << endl;
        int opcao = Tela::lerOpcao();
        if (!gestor && (opcao == 1 || opcao == 3 || opcao == 4)){
            opcao = -1;
        }
        switch (opcao){
            case 1: criar();
                    break;
            case 2: ler();
                    break;
            case 3: atualizar();
                    break;
            case 4: excluir();
                    break;
            case 5: listar();
                    break;
            case 0: apresentar = false;
                    break;
            default: cout << "Opcao invalida." << endl;
        }
    }
}

void CntrApresentacaoQuadros::criar(){
    Identificador identificadorProjeto;
    Identificador identificador;
    Nome nome;
    Limite limite;
    cout << endl << "CRIAR QUADRO" << endl;
    string campoProjeto = Tela::lerCampo("Identificador do projeto        : ");
    string campoIdentificador = Tela::lerCampo("Identificador do quadro         : ");
    string campoNome = Tela::lerCampo("Nome                            : ");
    string campoLimite = Tela::lerCampo("Limite WIP (1 a 25)             : ");
    try{
        identificadorProjeto.setValor(campoProjeto);
        identificador.setValor(campoIdentificador);
        nome.setValor(campoNome);
        limite.setValor(Tela::converterNumero(campoLimite));
    }
    catch(invalid_argument &exp){
        cout << "Dado invalido: " << exp.what() << endl;
        return;
    }
    Quadro quadro;
    quadro.setIdentificador(identificador);
    quadro.setNome(nome);
    quadro.setLimite(limite);
    quadro.setIdentificadorProjeto(identificadorProjeto);
    if (cntr->criar(quadro)){
        cout << "Quadro criado." << endl;
    } else {
        cout << "Falha: projeto nao encontrado ou identificador ja cadastrado." << endl;
    }
}

void CntrApresentacaoQuadros::ler(){
    Identificador identificador;
    if (!Tela::lerIdentificador("Identificador do quadro: ", &identificador)){
        return;
    }
    Quadro quadro;
    quadro.setIdentificador(identificador);
    if (!cntr->ler(&quadro)){
        cout << "Falha: quadro nao encontrado." << endl;
        return;
    }
    Tela::mostrarQuadro(quadro);
}

void CntrApresentacaoQuadros::atualizar(){
    Identificador identificador;
    if (!Tela::lerIdentificador("Identificador do quadro: ", &identificador)){
        return;
    }
    Quadro quadro;
    quadro.setIdentificador(identificador);
    if (!cntr->ler(&quadro)){
        cout << "Falha: quadro nao encontrado." << endl;
        return;
    }
    Tela::mostrarQuadro(quadro);
    cout << "Digite os novos valores (Enter mantem o atual)." << endl;
    string campoNome = Tela::lerCampo("Nome      : ");
    string campoLimite = Tela::lerCampo("Limite WIP: ");
    Nome nome;
    Limite limite;
    try{
        if (campoNome.length() > 0){
            nome.setValor(campoNome);
            quadro.setNome(nome);
        }
        if (campoLimite.length() > 0){
            limite.setValor(Tela::converterNumero(campoLimite));
            quadro.setLimite(limite);
        }
    }
    catch(invalid_argument &exp){
        cout << "Dado invalido: " << exp.what() << endl;
        return;
    }
    if (cntr->atualizar(quadro)){
        cout << "Quadro atualizado." << endl;
    } else {
        cout << "Falha ao atualizar o quadro." << endl;
    }
}

void CntrApresentacaoQuadros::excluir(){
    Identificador identificador;
    if (!Tela::lerIdentificador("Identificador do quadro: ", &identificador)){
        return;
    }
    if (cntr->excluir(identificador)){
        cout << "Quadro excluido." << endl;
    } else {
        cout << "Falha: quadro nao encontrado ou possui cartoes." << endl;
    }
}

void CntrApresentacaoQuadros::listar(){
    Identificador identificadorProjeto;
    if (!Tela::lerIdentificador("Identificador do projeto: ", &identificadorProjeto)){
        return;
    }
    Tela::listarIdentificadores(cntr->listar(identificadorProjeto), "Nenhum quadro neste projeto.");
}

void CntrApresentacaoCartoes::setCntrServicoCartoes(IServicoCartoes *cntr){
    this->cntr = cntr;
}

void CntrApresentacaoCartoes::setCntrServicoPessoas(IServicoPessoas *cntr){
    cntrServicoPessoas = cntr;
}

void CntrApresentacaoCartoes::executar(Email email){
    bool apresentar = true;
    while (apresentar){
        bool gestor = Tela::ehGestor(cntrServicoPessoas, email);
        cout << endl << "CARTOES DE ATIVIDADE" << endl;
        if (gestor){
            cout << "1 - Criar cartao." << endl;
        }
        cout << "2 - Ler cartao." << endl;
        if (gestor){
            cout << "3 - Atualizar cartao." << endl;
            cout << "4 - Excluir cartao." << endl;
        }
        cout << "5 - Listar cartoes de um quadro." << endl;
        cout << "6 - Mover cartao." << endl;
        cout << "7 - Metricas." << endl;
        cout << "0 - Voltar." << endl;
        int opcao = Tela::lerOpcao();
        if (!gestor && (opcao == 1 || opcao == 3 || opcao == 4)){
            opcao = -1;
        }
        switch (opcao){
            case 1: criar();
                    break;
            case 2: ler();
                    break;
            case 3: atualizar();
                    break;
            case 4: excluir();
                    break;
            case 5: listar();
                    break;
            case 6: mover();
                    break;
            case 7: executarMetricas();
                    break;
            case 0: apresentar = false;
                    break;
            default: cout << "Opcao invalida." << endl;
        }
    }
}

void CntrApresentacaoCartoes::executarMetricas(){
    bool apresentar = true;
    while (apresentar){
        cout << endl << "METRICAS" << endl;
        cout << "1 - Tempo de ciclo de um cartao." << endl;
        cout << "2 - Tempo de ciclo medio de um quadro." << endl;
        cout << "3 - Lead time de um cartao." << endl;
        cout << "4 - Lead time medio de um quadro." << endl;
        cout << "5 - WIP de um quadro." << endl;
        cout << "0 - Voltar." << endl;
        switch (Tela::lerOpcao()){
            case 1: lerTempoCiclo();
                    break;
            case 2: lerTempoCicloMedio();
                    break;
            case 3: lerLeadTime();
                    break;
            case 4: lerLeadTimeMedio();
                    break;
            case 5: lerWIP();
                    break;
            case 0: apresentar = false;
                    break;
            default: cout << "Opcao invalida." << endl;
        }
    }
}

void CntrApresentacaoCartoes::criar(){
    Identificador identificadorQuadro;
    Identificador identificador;
    Nome nome;
    Texto descricao;
    Prioridade prioridade;
    Tamanho tamanho;
    Timestamp entrada;
    cout << endl << "CRIAR CARTAO DE ATIVIDADE" << endl;
    string campoQuadro = Tela::lerCampo("Identificador do quadro              : ");
    string campoIdentificador = Tela::lerCampo("Identificador do cartao              : ");
    string campoNome = Tela::lerCampo("Nome                                 : ");
    string campoDescricao = Tela::lerCampo("Descricao                            : ");
    string campoPrioridade = Tela::lerCampo("Prioridade (ALTA/MEDIA/BAIXA)        : ");
    string campoTamanho = Tela::lerCampo("Tamanho (GRANDE/MEDIO/PEQUENO)       : ");
    string campoEntrada = Tela::lerCampo("Entrada (ex.: 05-MAR-2026-09:00)     : ");
    try{
        identificadorQuadro.setValor(campoQuadro);
        identificador.setValor(campoIdentificador);
        nome.setValor(campoNome);
        descricao.setValor(campoDescricao);
        prioridade.setValor(campoPrioridade);
        tamanho.setValor(campoTamanho);
        entrada.setValor(campoEntrada);
    }
    catch(invalid_argument &exp){
        cout << "Dado invalido: " << exp.what() << endl;
        return;
    }
    CartaoDeAtividade cartao;
    cartao.setIdentificador(identificador);
    cartao.setNome(nome);
    cartao.setDescricao(descricao);
    cartao.setPrioridade(prioridade);
    cartao.setTamanho(tamanho);
    cartao.setEntrada(entrada);
    cartao.setIdentificadorQuadro(identificadorQuadro);
    if (cntr->criar(cartao)){
        cout << "Cartao criado na coluna A FAZER." << endl;
    } else {
        cout << "Falha: quadro nao encontrado ou identificador ja cadastrado." << endl;
    }
}

void CntrApresentacaoCartoes::ler(){
    Identificador identificador;
    if (!Tela::lerIdentificador("Identificador do cartao: ", &identificador)){
        return;
    }
    CartaoDeAtividade cartao;
    cartao.setIdentificador(identificador);
    if (!cntr->ler(&cartao)){
        cout << "Falha: cartao nao encontrado." << endl;
        return;
    }
    Tela::mostrarCartao(cartao);
}

void CntrApresentacaoCartoes::atualizar(){
    Identificador identificador;
    if (!Tela::lerIdentificador("Identificador do cartao: ", &identificador)){
        return;
    }
    CartaoDeAtividade cartao;
    cartao.setIdentificador(identificador);
    if (!cntr->ler(&cartao)){
        cout << "Falha: cartao nao encontrado." << endl;
        return;
    }
    Tela::mostrarCartao(cartao);
    cout << "Digite os novos valores (Enter mantem o atual)." << endl;
    string campoNome = Tela::lerCampo("Nome      : ");
    string campoDescricao = Tela::lerCampo("Descricao : ");
    string campoPrioridade = Tela::lerCampo("Prioridade: ");
    string campoTamanho = Tela::lerCampo("Tamanho   : ");
    Nome nome;
    Texto descricao;
    Prioridade prioridade;
    Tamanho tamanho;
    try{
        if (campoNome.length() > 0){
            nome.setValor(campoNome);
            cartao.setNome(nome);
        }
        if (campoDescricao.length() > 0){
            descricao.setValor(campoDescricao);
            cartao.setDescricao(descricao);
        }
        if (campoPrioridade.length() > 0){
            prioridade.setValor(campoPrioridade);
            cartao.setPrioridade(prioridade);
        }
        if (campoTamanho.length() > 0){
            tamanho.setValor(campoTamanho);
            cartao.setTamanho(tamanho);
        }
    }
    catch(invalid_argument &exp){
        cout << "Dado invalido: " << exp.what() << endl;
        return;
    }
    if (cntr->atualizar(cartao)){
        cout << "Cartao atualizado." << endl;
    } else {
        cout << "Falha ao atualizar o cartao." << endl;
    }
}

void CntrApresentacaoCartoes::excluir(){
    Identificador identificador;
    if (!Tela::lerIdentificador("Identificador do cartao: ", &identificador)){
        return;
    }
    if (cntr->excluir(identificador)){
        cout << "Cartao excluido." << endl;
    } else {
        cout << "Falha: cartao nao encontrado." << endl;
    }
}

void CntrApresentacaoCartoes::listar(){
    Identificador identificadorQuadro;
    if (!Tela::lerIdentificador("Identificador do quadro: ", &identificadorQuadro)){
        return;
    }
    Tela::listarIdentificadores(cntr->listar(identificadorQuadro), "Nenhum cartao neste quadro.");
}

void CntrApresentacaoCartoes::mover(){
    Identificador identificador;
    Timestamp momento;
    cout << endl << "MOVER CARTAO (A FAZER -> FAZENDO -> FEITO)" << endl;
    string campoIdentificador = Tela::lerCampo("Identificador do cartao            : ");
    string campoMomento = Tela::lerCampo("Horario (ex.: 06-MAR-2026-14:30)   : ");
    try{
        identificador.setValor(campoIdentificador);
        momento.setValor(campoMomento);
    }
    catch(invalid_argument &exp){
        cout << "Dado invalido: " << exp.what() << endl;
        return;
    }
    if (!cntr->mover(identificador, momento)){
        cout << "Falha: cartao nao encontrado, ja esta em FEITO, quadro no limite de WIP ou horario anterior ao registrado." << endl;
        return;
    }
    CartaoDeAtividade cartao;
    cartao.setIdentificador(identificador);
    cntr->ler(&cartao);
    cout << "Cartao movido para " << cartao.getEstado().getValor() << "." << endl;
}

void CntrApresentacaoCartoes::lerTempoCiclo(){
    Identificador identificador;
    if (!Tela::lerIdentificador("Identificador do cartao: ", &identificador)){
        return;
    }
    int minutos;
    if (cntr->lerTempoCiclo(identificador, &minutos)){
        Tela::mostrarTempo("Tempo de ciclo: ", minutos);
    } else {
        cout << "Falha: cartao nao encontrado ou ainda nao esta em FEITO." << endl;
    }
}

void CntrApresentacaoCartoes::lerTempoCicloMedio(){
    Identificador identificadorQuadro;
    if (!Tela::lerIdentificador("Identificador do quadro: ", &identificadorQuadro)){
        return;
    }
    int minutos;
    if (cntr->lerTempoCicloMedio(identificadorQuadro, &minutos)){
        Tela::mostrarTempo("Tempo de ciclo medio: ", minutos);
    } else {
        cout << "Falha: o quadro nao tem cartoes em FEITO." << endl;
    }
}

void CntrApresentacaoCartoes::lerLeadTime(){
    Identificador identificador;
    if (!Tela::lerIdentificador("Identificador do cartao: ", &identificador)){
        return;
    }
    int minutos;
    if (cntr->lerLeadTime(identificador, &minutos)){
        Tela::mostrarTempo("Lead time: ", minutos);
    } else {
        cout << "Falha: cartao nao encontrado ou ainda nao esta em FEITO." << endl;
    }
}

void CntrApresentacaoCartoes::lerLeadTimeMedio(){
    Identificador identificadorQuadro;
    if (!Tela::lerIdentificador("Identificador do quadro: ", &identificadorQuadro)){
        return;
    }
    int minutos;
    if (cntr->lerLeadTimeMedio(identificadorQuadro, &minutos)){
        Tela::mostrarTempo("Lead time medio: ", minutos);
    } else {
        cout << "Falha: o quadro nao tem cartoes em FEITO." << endl;
    }
}

void CntrApresentacaoCartoes::lerWIP(){
    Identificador identificadorQuadro;
    if (!Tela::lerIdentificador("Identificador do quadro: ", &identificadorQuadro)){
        return;
    }
    int quantidade;
    if (cntr->lerWIP(identificadorQuadro, &quantidade)){
        cout << "WIP do quadro: " << quantidade << " cartao(oes) em FAZENDO." << endl;
    } else {
        cout << "Falha: quadro nao encontrado." << endl;
    }
}
