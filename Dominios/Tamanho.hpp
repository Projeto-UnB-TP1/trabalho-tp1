#ifndef TAMANHO_HPP
#define TAMANHO_HPP

#include <string>
#include <stdexcept>

/**
 * @brief Classe de domínio que representa o Tamanho.
 * Regra de formato: GRANDE, MEDIO ou PEQUENO.
 */
class Tamanho {
private:
    std::string valor;
    void validar(std::string valor);

public:
    /**
     * @brief Define o valor do tamanho.
     * @param valor String representando o tamanho.
     * @throw std::invalid_argument Se o tamanho for diferente de GRANDE, MEDIO ou PEQUENO.
     */
    void setValor(std::string valor);

    /**
     * @brief Retorna o valor do tamanho.
     * @return std::string O tamanho atual.
     */
    std::string getValor() const;
};

#endif // TAMANHO_HPP