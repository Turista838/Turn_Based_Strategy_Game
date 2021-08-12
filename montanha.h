//Programação Orientada a Objetos ISEC LEI - 20/21
//Trabalho Prático Realizado por:
//Gonçalo Ramalho 2019106561
//Rafael Correia 2019131435

#ifndef MONTANHA_H
#define MONTANHA_H
#include <string>
#include "continente.h"

using namespace std;

class montanha : public continente
{
	static int cont;
	int cont_is_imperium = 0; //necessário para actualizar recursos correctamente

public:
	montanha();
	void altera_recursos(int turno);
	territorio* duplica();
};
#endif

