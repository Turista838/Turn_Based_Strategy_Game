//Programação Orientada a Objetos ISEC LEI - 20/21
//Trabalho Prático Realizado por:
//Gonçalo Ramalho 2019106561
//Rafael Correia 2019131435

#ifndef RECURSOS_H
#define RECURSOS_H
#include <iostream>
using namespace std;

class recursos
{
	int produtos = 0;
	int ouro = 0;

public:
	recursos(int a, int b);
	void actualiza(int p, int o);
	int retorna_produtos();
	int retorna_ouro();
	void adiciona_recursos(int x, int y, int lim_x, int lim_y);
	void mostra_ambos() const;
	void retira_custo(int a); //função para pagar tecnologias
	bool retira_recursos(int o, int p);  // tec da bolsa
	bool compra_militar();
	void mod_recursos_DEBUG(string tipo, int lim_p, int lim_o);

};

#endif
