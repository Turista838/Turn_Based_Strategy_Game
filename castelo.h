//Programação Orientada a Objetos ISEC LEI - 20/21
//Trabalho Prático Realizado por:
//Gonçalo Ramalho 2019106561
//Rafael Correia 2019131435
#ifndef CASTELO_H
#define CASTELO_H
#include <string>
#include "continente.h"

using namespace std;

class castelo : public continente
{
	static int cont;

public:
	castelo();
	void altera_recursos(int turno);
	territorio* duplica();
};
#endif

