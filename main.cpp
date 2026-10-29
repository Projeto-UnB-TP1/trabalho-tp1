#include "Builders.hpp"

int main(){
    BuilderSistema *builder;
    builder = new BuilderSistema();

    CntrApresentacaoControle *cntrApresentacaoControle;
    cntrApresentacaoControle = builder->construir();

    cntrApresentacaoControle->executar();

    delete builder;

    return 0;
}
