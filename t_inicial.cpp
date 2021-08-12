//Programação Orientada a Objetos ISEC LEI - 20/21
//Trabalho Prático Realizado por:
//Gonçalo Ramalho 2019106561
//Rafael Correia 2019131435

#include "t_inicial.h"

t_inicial::t_inicial() : territorio("Territorio Inicial", 0, 9, 1, 1) {
};

void t_inicial::altera_recursos(int turno){}

int t_inicial::devolve_pontos(){}

territorio* t_inicial::duplica()
{
	return new t_inicial(*this);
}