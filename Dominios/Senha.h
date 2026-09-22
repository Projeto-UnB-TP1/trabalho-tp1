#include <iostream>
#include <string>
using namespace std;

class Senha{
    private:
        static const int TamanPermitido = 5;
        string valor;
        bool validar(string valor);
    public:
        bool setValor(string);
        string getValor();
};