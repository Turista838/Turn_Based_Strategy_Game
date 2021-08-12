//Programação Orientada a Objetos ISEC LEI - 20/21
//Trabalho Prático Realizado por:
//Gonçalo Ramalho 2019106561
//Rafael Correia 2019131435

#ifndef PESCARIA_H
#define PESCARIA_H
#include <string>
#include "ilha.h"

using namespace std;

class pescaria : public ilha
{
	static int cont;

public:
	pescaria();
	void altera_recursos(int turno);
	territorio* duplica();
};
#endif

