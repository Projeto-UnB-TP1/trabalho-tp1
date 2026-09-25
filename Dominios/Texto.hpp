#ifndef TEXTO_HPP
#define TEXTO_HPP

#include <string>
#include <stdexcept>

/**
 * @brief Classe de domínio que representa um Texto.
 * Regra de formato: Ate 30 caracteres. Pode conter letras, digitos, espacos em branco ou
 * sinais de pontuacao (, ; . : ? !). Nao pode haver dois sinais de pontuacao seguidos.
 * O primeiro caractere deve ser letra maiuscula e o ultimo deve ser ponto.
 */
class Texto {
private:
    std::string valor;
    void validar(std::string valor);
    bool isPontuacao(char c);

public:
    /**
     * @brief Define o valor do texto.
     * @param valor String com o texto.
     * @throw std::invalid_argument Se o texto nao seguir as regras de formatacao.
     */
    void setValor(std::string valor);

    /**
     * @brief Retorna o valor do texto.
     * @return std::string O texto atual.
     */
    std::string getValor() const;
};

#endif // TEXTO_HPP