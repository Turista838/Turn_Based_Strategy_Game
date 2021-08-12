//Programação Orientada a Objetos ISEC LEI - 20/21
//Trabalho Prático Realizado por:
//Gonçalo Ramalho 2019106561
//Rafael Correia 2019131435

#ifndef T_INICIAL_H
#define T_INICIAL_H
#include <vector>
#include <string>
#include "territorio.h"

using namespace std;

class t_inicial : public territorio
{

public:
	t_inicial();
	void altera_recursos(int turno);
        int devolve_pontos();
	territorio* duplica();

};
#endif

