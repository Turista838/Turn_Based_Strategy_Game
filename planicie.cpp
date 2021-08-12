//Programação Orientada a Objetos ISEC LEI - 20/21
//Trabalho Prático Realizado por:
//Gonçalo Ramalho 2019106561
//Rafael Correia 2019131435

#include "planicie.h"

int planicie::cont = 1;

planicie::planicie() : continente("Planicie", cont, 5, 1, 1) {
	cont++;
};

void planicie::altera_recursos(int turno)
{
	if (turno < 7) {
		alterador(1, 1);
	}
	if (turno >= 7) {
		alterador(2, 1);
	}
}

territorio* planicie::duplica()
{
	return new planicie(*this);
}
