//Programação Orientada a Objetos ISEC LEI - 20/21
//Trabalho Prático Realizado por:
//Gonçalo Ramalho 2019106561
//Rafael Correia 2019131435

#include "refugio.h"

int refugio::cont = 1;

refugio::refugio() : ilha("Refugio dos piratas", cont, 9, 0, 1) {
	cont++;
};

void refugio::altera_recursos(int turno) {}

territorio* refugio::duplica()
{
	return new refugio(*this);
}