//Programação Orientada a Objetos ISEC LEI - 20/21
//Trabalho Prático Realizado por:
//Gonçalo Ramalho 2019106561
//Rafael Correia 2019131435

#ifndef ILHA_H
#define ILHA_H
#include <vector>
#include <string>
#include "territorio.h"

using namespace std;

class ilha : public territorio
{
	const int pontos;

public:
	ilha(string s, int cont, int res, int prod, int ouro);
        int devolve_pontos();

};
#endif

