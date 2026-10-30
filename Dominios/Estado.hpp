#ifndef ESTADO_HPP
#define ESTADO_HPP
#include <string>

using namespace std;

///
/// Padrão para representação de estado de cartão de atividade.
///
/// Regras de formato:
///
/// - Estado é válido caso seja A FAZER, FAZENDO ou FEITO.
///

class Estado{
    private:
        string valor;
        void validar(string valor);

    public:

///
/// Armazena estado caso o mesmo seja válido.
///
/// Lança exceção caso o estado seja inválido.
///
/// @param valor Estado.
///
/// @throw invalid_argument
///

        void setValor(string valor);

///
/// Retorna estado.
///
/// @return Estado.
///

        string getValor() const;
};
#endif
