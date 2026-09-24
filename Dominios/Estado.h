#include <string>

using namespace std;

class Estado{
    private:
        string valor;
        bool validar(string valor);
    public:
        bool setValor(string);
        string getValor();
};