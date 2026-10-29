#ifndef NOME_HPP
#define NOME_HPP

#include <string>
#include <stdexcept>

/**
 * @class Nome
 * @brief Domínio que representa o nome.
 * 
 * Regras: Até 15 caracteres. Letras ou espaço. Espaço seguido de letra. 
 * Não inicia nem termina com espaço.
 */
class Nome {
private:
    std::string valor;
    void validar(std::string valor);
    bool ehLetra(char c) const;
public:
    /**
     * @brief Define o nome.
     * @param valor String representando o nome.
     * @throw std::invalid_argument em caso de formato inválido.
     */
    void setValor(std::string valor);

    /**
     * @brief Retorna o nome.
     * @return std::string O nome atual.
     */
    std::string getValor() const;
};

#endif