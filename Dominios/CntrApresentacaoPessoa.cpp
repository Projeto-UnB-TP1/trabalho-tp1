#include "CntrApresentacaoPessoa.hpp"
#include <iostream>
#include <string>

void CntrApresentacaoPessoa::executar() {
    std::string inputEmail, inputSenha;
    Email email;
    Senha senha;
    bool dadosValidos = false;

    std::cout << "--- MENU DE AUTENTICACAO ---" << std::endl;

    while (!dadosValidos) {
        try {
            std::cout << "Digite o seu E-mail: ";
            std::cin >> inputEmail;
            email.setValor(inputEmail);

            std::cout << "Digite a sua Senha: ";
            std::cin >> inputSenha;
            senha.setValor(inputSenha);

            dadosValidos = true;
        } catch (std::invalid_argument &exp) {
            std::cout << "Erro de formatacao: " << exp.what() << std::endl;
            std::cout << "Por favor, tente novamente.\n" << std::endl;
        }
    }

    if (servico->autenticar(email, senha)) {
        std::cout << "Autenticacao realizada com sucesso!" << std::endl;
    } else {
        std::cout << "Falha na autenticacao. Dados incorretos no sistema." << std::endl;
    }
}