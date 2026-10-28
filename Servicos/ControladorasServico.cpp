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
