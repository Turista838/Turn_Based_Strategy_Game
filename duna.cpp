//Programação Orientada a Objetos ISEC LEI - 20/21
//Trabalho Prático Realizado por:
//Gonçalo Ramalho 2019106561
//Rafael Correia 2019131435

#include "duna.h"

int duna::cont = 1;

duna::duna() : continente("Duna", cont, 4, 1, 0) {
	cont++;
}

void duna::altera_recursos(int turno) {}; // � necess�rio? a duna nunca vai alterar nada

territorio* duna::duplica()
{
	return new duna(*this);
}