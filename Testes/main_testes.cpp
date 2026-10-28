#include <iostream>
#include "testes.hpp"

using namespace std;

int main(){
    TUPessoa testePessoa;
    if (testePessoa.run() == TUPessoa::SUCESSO)
        cout << "TUPessoa: SUCESSO" << endl;
    else
        cout << "TUPessoa: FALHA" << endl;

    TUProjeto testeProjeto;
    if (testeProjeto.run() == TUProjeto::SUCESSO)
        cout << "TUProjeto: SUCESSO" << endl;
    else
        cout << "TUProjeto: FALHA" << endl;

    TUQuadro testeQuadro;
    if (testeQuadro.run() == TUQuadro::SUCESSO)
        cout << "TUQuadro: SUCESSO" << endl;
    else
        cout << "TUQuadro: FALHA" << endl;

    TUCartaoDeAtividade testeCartao;
    if (testeCartao.run() == TUCartaoDeAtividade::SUCESSO)
        cout << "TUCartaoDeAtividade: SUCESSO" << endl;
    else
        cout << "TUCartaoDeAtividade: FALHA" << endl;

    return 0;
}
