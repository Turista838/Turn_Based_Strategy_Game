//Programação Orientada a Objetos ISEC LEI - 20/21
//Trabalho Prático Realizado por:
//Gonçalo Ramalho 2019106561
//Rafael Correia 2019131435

#include "fortaleza.h"

int fortaleza::cont = 1;

fortaleza::fortaleza() : continente("Fortaleza", cont, 8, 0, 0) {
	cont++;
};

void fortaleza::altera_recursos(int turno){}

territorio* fortaleza::duplica()
{
	return new fortaleza(*this);
}