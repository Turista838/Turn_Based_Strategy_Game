//Programação Orientada a Objetos ISEC LEI - 20/21
//Trabalho Prático Realizado por:
//Gonçalo Ramalho 2019106561
//Rafael Correia 2019131435

#include "ilha.h"

ilha::ilha(string s, int cont, int res, int prod, int ouro) : territorio(s, cont, res, prod, ouro), pontos(2) {};

int ilha::devolve_pontos(){
    return pontos;
}
