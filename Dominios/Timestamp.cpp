#include "Timestamp.hpp"
#include <sstream>

using namespace std;

const string Timestamp::MESES[12] = {"JAN", "FEV", "MAR", "ABR", "MAI", "JUN",
                                     "JUL", "AGO", "SET", "OUT", "NOV", "DEZ"};

bool Timestamp::soDigitos(string texto) const {
    if (texto.empty()) {
        return false;
    }
    for (char c : texto) {
        if (c < '0' || c > '9') {
            return false;
        }
    }
    return true;
}

int Timestamp::numeroDoMes(string sigla) const {
    for (int i = 0; i < 12; i++) {
        if (MESES[i] == sigla) {
            return i + 1;
        }
    }
    throw invalid_argument("Timestamp invalido: mes deve ser JAN, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV ou DEZ.");
}

bool Timestamp::bissexto(int ano) const {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int Timestamp::diasNoMes(int mes, int ano) const {
    if (mes == 2) {
        return bissexto(ano) ? 29 : 28;
    }
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        return 30;
    }
    return 31;
}

void Timestamp::separarCampos(string valor, int& dia, int& mes, int& ano, int& hora, int& minuto) const {
    stringstream fluxo(valor);
    string partes[4];
    string sobra;

    for (int i = 0; i < 4; i++) {
        if (!getline(fluxo, partes[i], '-')) {
            throw invalid_argument("Timestamp invalido: formato deve ser DIA-MES-ANO-HORARIO.");
        }
    }
    if (getline(fluxo, sobra)) {
        throw invalid_argument("Timestamp invalido: formato deve ser DIA-MES-ANO-HORARIO.");
    }

    string textoDia = partes[0];
    string textoAno = partes[2];
    string textoHorario = partes[3];

    if (textoDia.length() > 2 || !soDigitos(textoDia)) {
        throw invalid_argument("Timestamp invalido: dia deve ter 1 ou 2 digitos.");
    }
    if (textoAno.length() != 4 || !soDigitos(textoAno)) {
        throw invalid_argument("Timestamp invalido: ano deve ter 4 digitos.");
    }
    if (textoHorario.length() != 5 || textoHorario[2] != ':' ||
        !soDigitos(textoHorario.substr(0, 2)) || !soDigitos(textoHorario.substr(3, 2))) {
        throw invalid_argument("Timestamp invalido: horario deve estar no formato HH:MM.");
    }

    dia = stoi(textoDia);
    mes = numeroDoMes(partes[1]);
    ano = stoi(textoAno);
    hora = stoi(textoHorario.substr(0, 2));
    minuto = stoi(textoHorario.substr(3, 2));
}

void Timestamp::setValor(string valor){
    int dia, mes, ano, hora, minuto;
    separarCampos(valor, dia, mes, ano, hora, minuto);

    if (ano < ANO_MINIMO || ano > ANO_MAXIMO) {
        throw invalid_argument("Timestamp invalido: ano deve estar entre 2000 e 2099.");
    }
    if (dia < 1 || dia > diasNoMes(mes, ano)) {
        throw invalid_argument("Timestamp invalido: dia nao existe nesse mes.");
    }
    if (hora > 23 || minuto > 59) {
        throw invalid_argument("Timestamp invalido: horario deve estar entre 00:00 e 23:59.");
    }
    this->valor = valor;
}

string Timestamp::getValor() const {
    return valor;
}

long Timestamp::converterParaMinutos() const {
    int dia, mes, ano, hora, minuto;
    separarCampos(valor, dia, mes, ano, hora, minuto);

    long dias = 0;
    for (int a = ANO_MINIMO; a < ano; a++) {
        dias += bissexto(a) ? 366 : 365;
    }
    for (int m = 1; m < mes; m++) {
        dias += diasNoMes(m, ano);
    }
    dias += dia - 1;

    return dias * 24 * 60 + hora * 60 + minuto;
}
