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
