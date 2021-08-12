//Programação Orientada a Objetos ISEC LEI - 20/21
//Trabalho Prático Realizado por:
//Gonçalo Ramalho 2019106561
//Rafael Correia 2019131435

#include "castelo.h"

int castelo::cont = 1;

castelo::castelo() : continente("Castelo", cont, 7, 3, 1) {
	cont++;
}

void castelo::altera_recursos(int turno)
{
	if (turno == 1 || turno == 2 || turno == 6 || turno == 7) {
		alterador(3, 1);
	}
	else {
		alterador(0, 1);
	}
}

territorio* castelo::duplica()
{
	return new castelo(*this);
}

