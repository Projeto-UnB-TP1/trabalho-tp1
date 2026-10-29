#include "ControladorasServico.hpp"

bool CntrServicoPessoas::autenticar(Email email, Senha senha){
    Pessoa pessoa;
    pessoa.setEmail(email);
    if (!ContainerPessoa::getInstancia()->pesquisar(&pessoa)){
        return false;
    }
    return pessoa.getSenha().getValor() == senha.getValor();
}

bool CntrServicoPessoas::criar(Pessoa pessoa){
    return ContainerPessoa::getInstancia()->incluir(pessoa);
}

bool CntrServicoPessoas::ler(Pessoa *pessoa){
    return ContainerPessoa::getInstancia()->pesquisar(pessoa);
}

bool CntrServicoPessoas::atualizar(Pessoa pessoa){
    return ContainerPessoa::getInstancia()->atualizar(pessoa);
}

bool CntrServicoPessoas::excluir(Email email){
    list<Projeto> projetos = ContainerProjeto::getInstancia()->listar();
    for (list<Projeto>::iterator projeto = projetos.begin(); projeto != projetos.end(); projeto++){
        if (projeto->getEmailGestor().getValor() == email.getValor()){
            return false;
        }
    }
    return ContainerPessoa::getInstancia()->remover(email);
}

list<Email> CntrServicoPessoas::listar(){
    list<Email> emails;
    list<Pessoa> pessoas = ContainerPessoa::getInstancia()->listar();
    for (list<Pessoa>::iterator pessoa = pessoas.begin(); pessoa != pessoas.end(); pessoa++){
        emails.push_back(pessoa->getEmail());
    }
    return emails;
}

bool CntrServicoProjetos::criar(Projeto projeto){
    Pessoa gestor;
    gestor.setEmail(projeto.getEmailGestor());
    if (!ContainerPessoa::getInstancia()->pesquisar(&gestor)){
        return false;
    }
    return ContainerProjeto::getInstancia()->incluir(projeto);
}

bool CntrServicoProjetos::ler(Projeto *projeto){
    return ContainerProjeto::getInstancia()->pesquisar(projeto);
}

bool CntrServicoProjetos::atualizar(Projeto projeto){
    Projeto atual;
    atual.setIdentificador(projeto.getIdentificador());
    if (!ContainerProjeto::getInstancia()->pesquisar(&atual)){
        return false;
    }
    projeto.setEmailGestor(atual.getEmailGestor());
    return ContainerProjeto::getInstancia()->atualizar(projeto);
}

bool CntrServicoProjetos::excluir(Identificador identificador){
    list<Quadro> quadros = ContainerQuadro::getInstancia()->listar();
    for (list<Quadro>::iterator quadro = quadros.begin(); quadro != quadros.end(); quadro++){
        if (quadro->getIdentificadorProjeto().getValor() == identificador.getValor()){
            return false;
        }
    }
    return ContainerProjeto::getInstancia()->remover(identificador);
}

list<Identificador> CntrServicoProjetos::listar(){
    list<Identificador> identificadores;
    list<Projeto> projetos = ContainerProjeto::getInstancia()->listar();
    for (list<Projeto>::iterator projeto = projetos.begin(); projeto != projetos.end(); projeto++){
        identificadores.push_back(projeto->getIdentificador());
    }
    return identificadores;
}

bool CntrServicoQuadros::criar(Quadro quadro){
    Projeto projeto;
    projeto.setIdentificador(quadro.getIdentificadorProjeto());
    if (!ContainerProjeto::getInstancia()->pesquisar(&projeto)){
        return false;
    }
    return ContainerQuadro::getInstancia()->incluir(quadro);
}

bool CntrServicoQuadros::ler(Quadro *quadro){
    return ContainerQuadro::getInstancia()->pesquisar(quadro);
}

bool CntrServicoQuadros::atualizar(Quadro quadro){
    Quadro atual;
    atual.setIdentificador(quadro.getIdentificador());
    if (!ContainerQuadro::getInstancia()->pesquisar(&atual)){
        return false;
    }
    quadro.setIdentificadorProjeto(atual.getIdentificadorProjeto());
    return ContainerQuadro::getInstancia()->atualizar(quadro);
}

bool CntrServicoQuadros::excluir(Identificador identificador){
    list<CartaoDeAtividade> cartoes = ContainerCartao::getInstancia()->listar();
    for (list<CartaoDeAtividade>::iterator cartao = cartoes.begin(); cartao != cartoes.end(); cartao++){
        if (cartao->getIdentificadorQuadro().getValor() == identificador.getValor()){
            return false;
        }
    }
    return ContainerQuadro::getInstancia()->remover(identificador);
}

list<Identificador> CntrServicoQuadros::listar(Identificador identificadorProjeto){
    list<Identificador> identificadores;
    list<Quadro> quadros = ContainerQuadro::getInstancia()->listar();
    for (list<Quadro>::iterator quadro = quadros.begin(); quadro != quadros.end(); quadro++){
        if (quadro->getIdentificadorProjeto().getValor() == identificadorProjeto.getValor()){
            identificadores.push_back(quadro->getIdentificador());
        }
    }
    return identificadores;
}

int CntrServicoCartoes::contarFazendo(Identificador identificadorQuadro){
    int quantidade = 0;
    list<CartaoDeAtividade> cartoes = ContainerCartao::getInstancia()->listar();
    for (list<CartaoDeAtividade>::iterator cartao = cartoes.begin(); cartao != cartoes.end(); cartao++){
        if (cartao->getIdentificadorQuadro().getValor() == identificadorQuadro.getValor() &&
            cartao->getEstado().getValor() == "FAZENDO"){
            quantidade++;
        }
    }
    return quantidade;
}

int CntrServicoCartoes::tempoCiclo(CartaoDeAtividade cartao){
    return cartao.getTermino().converterParaMinutos() - cartao.getInicio().converterParaMinutos();
}

int CntrServicoCartoes::leadTime(CartaoDeAtividade cartao){
    return cartao.getTermino().converterParaMinutos() - cartao.getEntrada().converterParaMinutos();
}

bool CntrServicoCartoes::criar(CartaoDeAtividade cartao){
    Quadro quadro;
    quadro.setIdentificador(cartao.getIdentificadorQuadro());
    if (!ContainerQuadro::getInstancia()->pesquisar(&quadro)){
        return false;
    }
    if (cartao.getEntrada().getValor().length() == 0){
        return false;
    }
    Estado estado;
    estado.setValor("A FAZER");
    cartao.setEstado(estado);
    Timestamp vazio;
    cartao.setInicio(vazio);
    cartao.setTermino(vazio);
    return ContainerCartao::getInstancia()->incluir(cartao);
}

bool CntrServicoCartoes::ler(CartaoDeAtividade *cartao){
    return ContainerCartao::getInstancia()->pesquisar(cartao);
}

bool CntrServicoCartoes::atualizar(CartaoDeAtividade cartao){
    CartaoDeAtividade atual;
    atual.setIdentificador(cartao.getIdentificador());
    if (!ContainerCartao::getInstancia()->pesquisar(&atual)){
        return false;
    }
    cartao.setEstado(atual.getEstado());
    cartao.setEntrada(atual.getEntrada());
    cartao.setInicio(atual.getInicio());
    cartao.setTermino(atual.getTermino());
    cartao.setIdentificadorQuadro(atual.getIdentificadorQuadro());
    return ContainerCartao::getInstancia()->atualizar(cartao);
}

bool CntrServicoCartoes::excluir(Identificador identificador){
    return ContainerCartao::getInstancia()->remover(identificador);
}

list<Identificador> CntrServicoCartoes::listar(Identificador identificadorQuadro){
    list<Identificador> identificadores;
    list<CartaoDeAtividade> cartoes = ContainerCartao::getInstancia()->listar();
    for (list<CartaoDeAtividade>::iterator cartao = cartoes.begin(); cartao != cartoes.end(); cartao++){
        if (cartao->getIdentificadorQuadro().getValor() == identificadorQuadro.getValor()){
            identificadores.push_back(cartao->getIdentificador());
        }
    }
    return identificadores;
}

bool CntrServicoCartoes::mover(Identificador identificador, Timestamp momento){
    CartaoDeAtividade cartao;
    cartao.setIdentificador(identificador);
    if (!ContainerCartao::getInstancia()->pesquisar(&cartao)){
        return false;
    }

    Estado novoEstado;
    if (cartao.getEstado().getValor() == "A FAZER"){
        Quadro quadro;
        quadro.setIdentificador(cartao.getIdentificadorQuadro());
        if (!ContainerQuadro::getInstancia()->pesquisar(&quadro)){
            return false;
        }
        if (contarFazendo(quadro.getIdentificador()) >= quadro.getLimite().getValor()){
            return false;
        }
        if (momento.converterParaMinutos() < cartao.getEntrada().converterParaMinutos()){
            return false;
        }
        novoEstado.setValor("FAZENDO");
        cartao.setInicio(momento);
    } else if (cartao.getEstado().getValor() == "FAZENDO"){
        if (momento.converterParaMinutos() < cartao.getInicio().converterParaMinutos()){
            return false;
        }
        novoEstado.setValor("FEITO");
        cartao.setTermino(momento);
    } else {
        return false;
    }

    cartao.setEstado(novoEstado);
    return ContainerCartao::getInstancia()->atualizar(cartao);
}

bool CntrServicoCartoes::lerTempoCiclo(Identificador identificador, int *resultado){
    CartaoDeAtividade cartao;
    cartao.setIdentificador(identificador);
    if (!ContainerCartao::getInstancia()->pesquisar(&cartao) || cartao.getEstado().getValor() != "FEITO"){
        return false;
    }
    *resultado = tempoCiclo(cartao);
    return true;
}

bool CntrServicoCartoes::lerTempoCicloMedio(Identificador identificadorQuadro, int *resultado){
    int soma = 0;
    int concluidos = 0;
    list<CartaoDeAtividade> cartoes = ContainerCartao::getInstancia()->listar();
    for (list<CartaoDeAtividade>::iterator cartao = cartoes.begin(); cartao != cartoes.end(); cartao++){
        if (cartao->getIdentificadorQuadro().getValor() == identificadorQuadro.getValor() &&
            cartao->getEstado().getValor() == "FEITO"){
            soma = soma + tempoCiclo(*cartao);
            concluidos++;
        }
    }
    if (concluidos == 0){
        return false;
    }
    *resultado = soma / concluidos;
    return true;
}

bool CntrServicoCartoes::lerLeadTime(Identificador identificador, int *resultado){
    CartaoDeAtividade cartao;
    cartao.setIdentificador(identificador);
    if (!ContainerCartao::getInstancia()->pesquisar(&cartao) || cartao.getEstado().getValor() != "FEITO"){
        return false;
    }
    *resultado = leadTime(cartao);
    return true;
}

bool CntrServicoCartoes::lerLeadTimeMedio(Identificador identificadorQuadro, int *resultado){
    int soma = 0;
    int concluidos = 0;
    list<CartaoDeAtividade> cartoes = ContainerCartao::getInstancia()->listar();
    for (list<CartaoDeAtividade>::iterator cartao = cartoes.begin(); cartao != cartoes.end(); cartao++){
        if (cartao->getIdentificadorQuadro().getValor() == identificadorQuadro.getValor() &&
            cartao->getEstado().getValor() == "FEITO"){
            soma = soma + leadTime(*cartao);
            concluidos++;
        }
    }
    if (concluidos == 0){
        return false;
    }
    *resultado = soma / concluidos;
    return true;
}

bool CntrServicoCartoes::lerWIP(Identificador identificadorQuadro, int *resultado){
    Quadro quadro;
    quadro.setIdentificador(identificadorQuadro);
    if (!ContainerQuadro::getInstancia()->pesquisar(&quadro)){
        return false;
    }
    *resultado = contarFazendo(identificadorQuadro);
    return true;
}
