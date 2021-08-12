//Programação Orientada a Objetos ISEC LEI - 20/21
//Trabalho Prático Realizado por:
//Gonçalo Ramalho 2019106561
//Rafael Correia 2019131435

#include "mina.h"

int mina::cont = 1;

mina::mina() : continente("Mina", cont, 5, 0, 1) {
	cont++;
};

void mina::altera_recursos(int turno)
{
	if (turno == 1 || turno == 2 || turno == 3 || turno == 7 || turno == 8 || turno == 9)
		alterador(0, 1);
	else
		alterador(0, 2);
		
}

territorio* mina::duplica()
{
	return new mina(*this);
}
