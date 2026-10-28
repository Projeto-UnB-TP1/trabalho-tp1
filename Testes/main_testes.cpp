#include <iostream>
#include "testes.hpp"

using namespace std;

int main(){
    TUEmail testeEmail;
    if (testeEmail.run() == TUEmail::SUCESSO)
        cout << "TUEmail: SUCESSO" << endl;
    else
        cout << "TUEmail: FALHA" << endl;

    TUEstado testeEstado;
    if (testeEstado.run() == TUEstado::SUCESSO)
        cout << "TUEstado: SUCESSO" << endl;
    else
        cout << "TUEstado: FALHA" << endl;

    TUIdentificador testeIdentificador;
    if (testeIdentificador.run() == TUIdentificador::SUCESSO)
        cout << "TUIdentificador: SUCESSO" << endl;
    else
        cout << "TUIdentificador: FALHA" << endl;

    TULimite testeLimite;
    if (testeLimite.run() == TULimite::SUCESSO)
        cout << "TULimite: SUCESSO" << endl;
    else
        cout << "TULimite: FALHA" << endl;

    TUNome testeNome;
    if (testeNome.run() == TUNome::SUCESSO)
        cout << "TUNome: SUCESSO" << endl;
    else
        cout << "TUNome: FALHA" << endl;

    TUPapel testePapel;
    if (testePapel.run() == TUPapel::SUCESSO)
        cout << "TUPapel: SUCESSO" << endl;
    else
        cout << "TUPapel: FALHA" << endl;

    TUPrioridade testePrioridade;
    if (testePrioridade.run() == TUPrioridade::SUCESSO)
        cout << "TUPrioridade: SUCESSO" << endl;
    else
        cout << "TUPrioridade: FALHA" << endl;

    TUSenha testeSenha;
    if (testeSenha.run() == TUSenha::SUCESSO)
        cout << "TUSenha: SUCESSO" << endl;
    else
        cout << "TUSenha: FALHA" << endl;

    TUTamanho testeTamanho;
    if (testeTamanho.run() == TUTamanho::SUCESSO)
        cout << "TUTamanho: SUCESSO" << endl;
    else
        cout << "TUTamanho: FALHA" << endl;

    TUTexto testeTexto;
    if (testeTexto.run() == TUTexto::SUCESSO)
        cout << "TUTexto: SUCESSO" << endl;
    else
        cout << "TUTexto: FALHA" << endl;

    TUTimestamp testeTimestamp;
    if (testeTimestamp.run() == TUTimestamp::SUCESSO)
        cout << "TUTimestamp: SUCESSO" << endl;
    else
        cout << "TUTimestamp: FALHA" << endl;

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
