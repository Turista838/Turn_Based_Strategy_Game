//Programação Orientada a Objetos ISEC LEI - 20/21
//Trabalho Prático Realizado por:
//Gonçalo Ramalho 2019106561
//Rafael Correia 2019131435

#include <iostream>
#include "utils.h"
#include "mundo.h"
#include "territorio.h"
#include "jogador.h"

int main()
{
    srand((unsigned int)time(NULL));
    mundo *m = new mundo;
    jogador alberto(m);
    alberto.iniciar();
    delete m;
}

