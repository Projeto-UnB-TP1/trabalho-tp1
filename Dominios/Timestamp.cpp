#include "Timestamp.hpp"

using namespace std;

bool Timestamp::bissexto(int ano) const {
    if (ano % 400 == 0){
        return true;
    }
    if (ano % 4 == 0 && ano % 100 != 0){
        return true;
    }
    return false;
}

int Timestamp::diasNoMes(int mes, int ano) const {
    int diasDoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (mes == 1 && bissexto(ano)){
        return 29;
    }
    return diasDoMes[mes];
}

int Timestamp::numero(string texto, unsigned int inicio, unsigned int quantidade) const {
    int resultado = 0;
    for (unsigned int i = inicio; i < inicio + quantidade; i++){
        resultado = resultado * 10 + (texto[i] - '0');
    }
    return resultado;
}

int Timestamp::indiceMes(string texto, unsigned int p) const {
    string meses[12] = {"JAN", "FEV", "MAR", "ABR", "MAI", "JUN",
                        "JUL", "AGO", "SET", "OUT", "NOV", "DEZ"};
    for (int i = 0; i < 12; i++){
        if (texto[p + 1] == meses[i][0] && texto[p + 2] == meses[i][1] && texto[p + 3] == meses[i][2]){
            return i;
        }
    }
    return -1;
}

void Timestamp::validar(string valor){
    unsigned int tamanho = valor.length();
    unsigned int p;
    if (tamanho == 16){
        p = 1;
    } else if (tamanho == 17){
        p = 2;
    } else {
        throw invalid_argument("Timestamp invalido: formato deve ser DIA-MES-ANO-HORARIO.");
    }

    if (valor[p] != '-' || valor[p + 4] != '-' || valor[p + 9] != '-' || valor[p + 12] != ':'){
        throw invalid_argument("Timestamp invalido: formato deve ser DIA-MES-ANO-HORARIO.");
    }

    for (unsigned int i = 0; i < tamanho; i++){
        bool separador = (i == p || i == p + 4 || i == p + 9 || i == p + 12);
        bool siglaMes = (i > p && i < p + 4);
        bool digito = (valor[i] >= '0' && valor[i] <= '9');
        if (!separador && !siglaMes && !digito){
            throw invalid_argument("Timestamp invalido: dia, ano e horario devem ser numeros.");
        }
    }

    int mes = indiceMes(valor, p);
    if (mes == -1){
        throw invalid_argument("Timestamp invalido: mes deve ser JAN, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV ou DEZ.");
    }

    int dia = numero(valor, 0, p);
    int ano = numero(valor, p + 5, 4);
    int hora = numero(valor, p + 10, 2);
    int minuto = numero(valor, p + 13, 2);

    if (ano < 2000 || ano > 2099){
        throw invalid_argument("Timestamp invalido: ano deve estar entre 2000 e 2099.");
    }
    if (dia < 1 || dia > diasNoMes(mes, ano)){
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

int Timestamp::converterParaMinutos() const {
    unsigned int p;
    if (valor.length() == 16){
        p = 1;
    } else if (valor.length() == 17){
        p = 2;
    } else {
        throw invalid_argument("Timestamp sem valor.");
    }

    int ano = numero(valor, p + 5, 4);
    int mes = indiceMes(valor, p);
    int dias = numero(valor, 0, p) - 1;

    for (int a = 2000; a < ano; a++){
        if (bissexto(a)){
            dias = dias + 366;
        } else {
            dias = dias + 365;
        }
    }
    for (int m = 0; m < mes; m++){
        dias = dias + diasNoMes(m, ano);
    }

    return dias * 1440 + numero(valor, p + 10, 2) * 60 + numero(valor, p + 13, 2);
}
