#include "Containers.hpp"

ContainerPessoa* ContainerPessoa::instancia = nullptr;

ContainerPessoa* ContainerPessoa::getInstancia(){
    if (instancia == nullptr)
        instancia = new ContainerPessoa();
    return instancia;
}

bool ContainerPessoa::incluir(Pessoa pessoa){
    for(list<Pessoa>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getEmail().getValor() == pessoa.getEmail().getValor()){
            return false;
        }
    }
    container.push_back(pessoa);
    return true;
}

bool ContainerPessoa::remover(Email email){
    for(list<Pessoa>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getEmail().getValor() == email.getValor()){
            container.erase(elemento);
            return true;
        }
    }
    return false;
}

bool ContainerPessoa::pesquisar(Pessoa* pessoa){
    for(list<Pessoa>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getEmail().getValor() == pessoa->getEmail().getValor()){
            *pessoa = *elemento;
            return true;
        }
    }
    return false;
}

bool ContainerPessoa::atualizar(Pessoa pessoa){
    for(list<Pessoa>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getEmail().getValor() == pessoa.getEmail().getValor()){
            *elemento = pessoa;
            return true;
        }
    }
    return false;
}

list<Pessoa> ContainerPessoa::listar(){
    return container;
}

ContainerProjeto* ContainerProjeto::instancia = nullptr;

ContainerProjeto* ContainerProjeto::getInstancia(){
    if (instancia == nullptr)
        instancia = new ContainerProjeto();
    return instancia;
}

bool ContainerProjeto::incluir(Projeto projeto){
    for(list<Projeto>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getIdentificador().getValor() == projeto.getIdentificador().getValor()){
            return false;
        }
    }
    container.push_back(projeto);
    return true;
}

bool ContainerProjeto::remover(Identificador identificador){
    for(list<Projeto>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getIdentificador().getValor() == identificador.getValor()){
            container.erase(elemento);
            return true;
        }
    }
    return false;
}

bool ContainerProjeto::pesquisar(Projeto* projeto){
    for(list<Projeto>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getIdentificador().getValor() == projeto->getIdentificador().getValor()){
            *projeto = *elemento;
            return true;
        }
    }
    return false;
}

bool ContainerProjeto::atualizar(Projeto projeto){
    for(list<Projeto>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getIdentificador().getValor() == projeto.getIdentificador().getValor()){
            *elemento = projeto;
            return true;
        }
    }
    return false;
}

list<Projeto> ContainerProjeto::listar(){
    return container;
}

ContainerQuadro* ContainerQuadro::instancia = nullptr;

ContainerQuadro* ContainerQuadro::getInstancia(){
    if (instancia == nullptr)
        instancia = new ContainerQuadro();
    return instancia;
}

bool ContainerQuadro::incluir(Quadro quadro){
    for(list<Quadro>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getIdentificador().getValor() == quadro.getIdentificador().getValor()){
            return false;
        }
    }
    container.push_back(quadro);
    return true;
}

bool ContainerQuadro::remover(Identificador identificador){
    for(list<Quadro>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getIdentificador().getValor() == identificador.getValor()){
            container.erase(elemento);
            return true;
        }
    }
    return false;
}

bool ContainerQuadro::pesquisar(Quadro* quadro){
    for(list<Quadro>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getIdentificador().getValor() == quadro->getIdentificador().getValor()){
            *quadro = *elemento;
            return true;
        }
    }
    return false;
}

bool ContainerQuadro::atualizar(Quadro quadro){
    for(list<Quadro>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getIdentificador().getValor() == quadro.getIdentificador().getValor()){
            *elemento = quadro;
            return true;
        }
    }
    return false;
}

list<Quadro> ContainerQuadro::listar(){
    return container;
}

ContainerCartao* ContainerCartao::instancia = nullptr;

ContainerCartao* ContainerCartao::getInstancia(){
    if (instancia == nullptr)
        instancia = new ContainerCartao();
    return instancia;
}

bool ContainerCartao::incluir(CartaoDeAtividade cartao){
    for(list<CartaoDeAtividade>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getIdentificador().getValor() == cartao.getIdentificador().getValor()){
            return false;
        }
    }
    container.push_back(cartao);
    return true;
}

bool ContainerCartao::remover(Identificador identificador){
    for(list<CartaoDeAtividade>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getIdentificador().getValor() == identificador.getValor()){
            container.erase(elemento);
            return true;
        }
    }
    return false;
}

bool ContainerCartao::pesquisar(CartaoDeAtividade* cartao){
    for(list<CartaoDeAtividade>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getIdentificador().getValor() == cartao->getIdentificador().getValor()){
            *cartao = *elemento;
            return true;
        }
    }
    return false;
}

bool ContainerCartao::atualizar(CartaoDeAtividade cartao){
    for(list<CartaoDeAtividade>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getIdentificador().getValor() == cartao.getIdentificador().getValor()){
            *elemento = cartao;
            return true;
        }
    }
    return false;
}

list<CartaoDeAtividade> ContainerCartao::listar(){
    return container;
}
