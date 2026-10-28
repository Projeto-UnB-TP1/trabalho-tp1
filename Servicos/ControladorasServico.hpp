#ifndef CONTROLADORASSERVICO_HPP
#define CONTROLADORASSERVICO_HPP

#include "../Interfaces/Interfaces.hpp"
#include "Containers.hpp"

class CntrServicoPessoas:public IServicoPessoas{
    public:
        bool autenticar(Email, Senha);
        bool criar(Pessoa);
        bool ler(Pessoa*);
        bool atualizar(Pessoa);
        bool excluir(Email);
        list<Email> listar();
};

#endif
