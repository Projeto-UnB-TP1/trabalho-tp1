#include "Timestamp.hpp"

using namespace std;

bool Timestamp::bissexto(int ano){
    if (ano % 400 == 0){
        return true;
    }
    if (ano % 4 == 0 && ano % 100 != 0){
        return true;
    }
    return false;
}

void Timestamp::validar(string valor){
    string meses[12] = {"JAN", "FEV", "MAR", "ABR", "MAI", "JUN",
                        "JUL", "AGO", "SET", "OUT", "NOV", "DEZ"};
    int diasDoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // p é a posição do primeiro hífen: 1 se o dia tem um dígito, 2 se tem dois.
    unsigned int tamanho = valor.length();
    unsigned int p;
    if (tamanho == 16){
        p = 1;
    } else if (tamanho == 17){
        p = 2;
    } else {
        throw invalid_argument("Timestamp invalido: formato deve ser DIA-MES-ANO-HORARIO.");
    }

    // Separadores nas posições fixas.
    if (valor[p] != '-' || valor[p + 4] != '-' || valor[p + 9] != '-' || valor[p + 12] != ':'){
        throw invalid_argument("Timestamp invalido: formato deve ser DIA-MES-ANO-HORARIO.");
    }

    // Fora os separadores e a sigla do mês, todo caractere deve ser dígito ('0' a '9').
    for (unsigned int i = 0; i < tamanho; i++){
        bool separador = (i == p || i == p + 4 || i == p + 9 || i == p + 12);
        bool siglaMes = (i > p && i < p + 4);
        bool digito = (valor[i] >= '0' && valor[i] <= '9');
        if (!separador && !siglaMes && !digito){
            throw invalid_argument("Timestamp invalido: dia, ano e horario devem ser numeros.");
        }
    }

    // Mês: procura a sigla na lista; mes fica com o índice de 0 a 11.
    int mes = -1;
    for (int i = 0; i < 12; i++){
        if (valor[p + 1] == meses[i][0] && valor[p + 2] == meses[i][1] && valor[p + 3] == meses[i][2]){
            mes = i;
        }
    }
    if (mes == -1){
        throw invalid_argument("Timestamp invalido: mes deve ser JAN, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV ou DEZ.");
    }

    // Converte os dígitos em números: subtrair '0' de um dígito dá o seu valor (ex.: '7' - '0' = 7).
    int dia = valor[0] - '0';
    if (p == 2){
        dia = dia * 10 + (valor[1] - '0');
    }
    int ano = (valor[p + 5] - '0') * 1000 + (valor[p + 6] - '0') * 100 + (valor[p + 7] - '0') * 10 + (valor[p + 8] - '0');
    int hora = (valor[p + 10] - '0') * 10 + (valor[p + 11] - '0');
    int minuto = (valor[p + 13] - '0') * 10 + (valor[p + 14] - '0');

    if (ano < 2000 || ano > 2099){
        throw invalid_argument("Timestamp invalido: ano deve estar entre 2000 e 2099.");
    }

    int ultimoDia = diasDoMes[mes];
    if (mes == 1 && bissexto(ano)){
        ultimoDia = 29;
    }
    if (dia < 1 || dia > ultimoDia){
        throw invalid_argument("Timestamp invalido: dia nao existe nesse mes.");
    }

    if (hora > 23 || minuto > 59){
        throw invalid_argument("Timestamp invalido: horario deve estar entre 00:00 e 23:59.");
    }
}

void Timestamp::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

string Timestamp::getValor() const {
    return valor;
}
