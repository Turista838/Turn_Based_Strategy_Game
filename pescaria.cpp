//Programação Orientada a Objetos ISEC LEI - 20/21
//Trabalho Prático Realizado por:
//Gonçalo Ramalho 2019106561
//Rafael Correia 2019131435

#include "pescaria.h"

int pescaria::cont = 1;

pescaria::pescaria() : ilha("Pescaria", cont, 9, 2, 0) {
	cont++;
};

void pescaria::altera_recursos(int turno)
{
	if (turno < 7) {
		alterador(2, 0);
	}
	if (turno >= 7) {
		alterador(4, 0);
	}
}

territorio* pescaria::duplica()
{
	return new pescaria(*this);
}