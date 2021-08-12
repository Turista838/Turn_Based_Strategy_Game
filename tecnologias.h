//Programação Orientada a Objetos ISEC LEI - 20/21
//Trabalho Prático Realizado por:
//Gonçalo Ramalho 2019106561
//Rafael Correia 2019131435

#ifndef TECNOLOGIAS_H
#define TECNOLOGIAS_H
#include <string>

using namespace std;

class tecnologias
{
	bool drone_militar = false;
	bool misseis_teleguiados = false;
	bool defesas_territoriasis = false;
	bool bolsa_valores = false;
	bool banco_central = false;

public:
	bool verifica_recursos(string tipo, int ouro); //verifica se o jogador tem ouro suficiente
	bool retorna_estado_drone();      //diz se as tecnologias estão true ou false
	bool retorna_estado_misseis();     
	bool retorna_estado_defesas();
	bool retorna_estado_bolsa();
	void compra_drone() { drone_militar = true; }     //mete cada tecnologia como true
	void compra_misseis() { misseis_teleguiados = true; }
	void compra_defesas() { defesas_territoriasis = true; }
	void compra_bolsa() { bolsa_valores = true; }
	void compra_banco() { banco_central = true; }
	int pontos_tecnologias();
	void toma_a_forca_tec(string antvalor);
};

#endif