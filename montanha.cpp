//Programação Orientada a Objetos ISEC LEI - 20/21
//Trabalho Prático Realizado por:
//Gonçalo Ramalho 2019106561
//Rafael Correia 2019131435

#include "montanha.h"

int montanha::cont = 1;

montanha::montanha() : continente("Montanha", cont, 6, 0, 0) {
	cont++;
};

void montanha::altera_recursos(int turno)
{
	if (verifica_imperio())
		cont_is_imperium++;
	if (cont_is_imperium > 2)
		alterador(1, 0);
}

territorio* montanha::duplica()
{
	return new montanha(*this);
}