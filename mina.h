//Programação Orientada a Objetos ISEC LEI - 20/21
//Trabalho Prático Realizado por:
//Gonçalo Ramalho 2019106561
//Rafael Correia 2019131435

#ifndef MINA_H
#define MINA_H
#include <string>
#include "continente.h"

using namespace std;

class mina : public continente
{
	static int cont;

public:
	mina();
	void altera_recursos(int turno);
	territorio* duplica();

};
#endif
