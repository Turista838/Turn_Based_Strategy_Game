//Programação Orientada a Objetos ISEC LEI - 20/21
//Trabalho Prático Realizado por:
//Gonçalo Ramalho 2019106561
//Rafael Correia 2019131435

#ifndef FORTALEZA_H
#define FORTALEZA_H
#include <string>
#include "continente.h"

using namespace std;

class fortaleza : public continente
{
	static int cont;

public:
	fortaleza();
	void altera_recursos(int turno);
	territorio* duplica();
};
#endif

