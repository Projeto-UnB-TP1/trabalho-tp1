#ifndef IDENTIFICADOR_HPP
#define IDENTIFICADOR_HPP

#include <string>
#include <stdexcept>

/**
 * @class Identificador
 * @brief Domínio que representa o código de identificação.
 * 
 * Regra de formato: 6 caracteres, sendo os três primeiros letras e os três últimos dígitos.
 */
class Identificador {
private:
    std::string valor;
    void validar(std::string valor);
public:
    /**
     * @brief Define o identificador.
     * @param valor String a ser armazenada.
     * @throw std::invalid_argument se não respeitar o padrão LLLDDD.
     */
    void setValor(std::string valor);

    /**
     * @brief Retorna o identificador.
     * @return std::string 
     */
    std::string getValor() const;
};

inline std::string Identificador::getValor() const {
    return valor;
}

#endif // IDENTIFICADOR_HPP