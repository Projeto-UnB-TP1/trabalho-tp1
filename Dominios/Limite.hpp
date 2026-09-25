#ifndef LIMITE_HPP
#define LIMITE_HPP

#include <stdexcept>

/**
 * @brief Classe de domínio que representa um Limite.
 * Regra de formato: Valor inteiro de 1 a 25.
 */
class Limite {
private:
    int valor;
    void validar(int valor);

public:
    /**
     * @brief Define o valor do limite.
     * @param valor Valor inteiro a ser definido.
     * @throw std::invalid_argument Se o valor não estiver entre 1 e 25.
     */
    void setValor(int valor);

    /**
     * @brief Retorna o valor do limite.
     * @return int O valor atual do limite.
     */
    int getValor() const;
};

#endif // LIMITE_HPP