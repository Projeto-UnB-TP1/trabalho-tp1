#include <iostream>
#include "Limite.hpp"
#include "Tamanho.hpp"
#include "Texto.hpp"

int main() {
    try {
        Limite l;
        l.setValor(10);
        std::cout << "Limite criado: " << l.getValor() << std::endl;

        Tamanho t;
        t.setValor("GRANDE");
        std::cout << "Tamanho criado: " << t.getValor() << std::endl;

        Texto txt;
        txt.setValor("Meu texto valido.");
        std::cout << "Texto criado: " << txt.getValor() << std::endl;

    } catch(std::invalid_argument &e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    return 0;
}