//Programação Orientada a Objetos ISEC LEI - 20/21
//Trabalho Prático Realizado por:
//Gonçalo Ramalho 2019106561
//Rafael Correia 2019131435

#include "tecnologias.h"
#include <iostream>
#include "utils.h"

bool tecnologias::verifica_recursos(string tipo, int ouro) 
{
	if (tipo == "DRONE" && ouro >= 3) {
		return true;
	}
	if (tipo == "MISSIL" && ouro >= 4) {
		return true;
	}
	if (tipo == "DEFESA" && ouro >= 4) {
		return true;
	}
	if (tipo == "BOLSA" && ouro >= 2) {
		return true;
	}
	if (tipo == "BANCO" && ouro >= 3) {
		return true;
	}
		return false;
}

bool tecnologias::retorna_estado_drone() {
	if (drone_militar == true)
		return true;
	return false;
};

bool tecnologias::retorna_estado_misseis() {
	if (misseis_teleguiados == true)
		return true;
	return false;
};

bool tecnologias::retorna_estado_defesas() {
	if (defesas_territoriasis == true)
		return true;
	return false;
};


bool tecnologias::retorna_estado_bolsa() {
	if (bolsa_valores == true)
		return true;
	return false;
}
int tecnologias::pontos_tecnologias()
{
	int pontos = 0;
	if (drone_militar == true)
		pontos++;
	if (misseis_teleguiados == true)
		pontos++;
	if (defesas_territoriasis == true)
		pontos++;
	if (bolsa_valores == true)
		pontos++;
	if (banco_central == true)
		pontos++;

	cout << "Pontos ganhos pelas tecnologias adquiridas: " << pontos << endl;

	if (pontos == 5) {
		cout << "Bonus cientificco + 1 ponto" << endl;
		pontos++;
	}

	return pontos;
}
void tecnologias::toma_a_forca_tec(string antvalor)
{
	if (uppercase_funcao(antvalor) == "DRONE") {
		compra_drone();
		return;
	}

	if (uppercase_funcao(antvalor) == "MISSIL") {
		compra_misseis();
		return;
	}

	if (uppercase_funcao(antvalor) == "DEFESA") {
		compra_defesas();
		return;
	}

	if (uppercase_funcao(antvalor) == "BOLSA") {
		compra_bolsa();
		return;
	}

	if (uppercase_funcao(antvalor) == "BANCO") {
		compra_banco();
		return;
	}

	cout << "Tecnologia nao existe" << endl;

}


