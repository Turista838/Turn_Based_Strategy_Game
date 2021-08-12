//Programação Orientada a Objetos ISEC LEI - 20/21
//Trabalho Prático Realizado por:
//Gonçalo Ramalho 2019106561
//Rafael Correia 2019131435

#include "utils.h"

bool verifica_comando(string s, vector<string> c) {
    for (string cd : c)
        if (s == cd)
            return true;
    return false;
}

bool verifica_tipo(string s) {
    for (int i = 0; i < Terries; i++)
        if (s.compare(territories[i]) == 0)
            return true;
    return false;
}

string uppercase_funcao(string s) {
    for (int i = 0; i < s.length(); i++)
        s[i] = toupper(s[i]);
    return s;
}