//Programação Orientada a Objetos ISEC LEI - 20/21
//Trabalho Prático Realizado por:
//Gonçalo Ramalho 2019106561
//Rafael Correia 2019131435

#include "recursos.h"

recursos::recursos(int a, int b) : produtos(a), ouro(b) {};


void recursos::actualiza(int p, int o)
{
	produtos = p;
	ouro = o;
}

int recursos::retorna_produtos() { return produtos; }

int recursos::retorna_ouro() { return ouro; }

void recursos::adiciona_recursos(int x, int y, int lim_x, int lim_y)
{
	produtos = produtos + x;
	ouro = ouro + y;
	if (produtos > lim_x) {
		produtos = lim_x;
	}
	if (ouro > lim_y) {
		ouro = lim_y;
	}

}

void recursos::mostra_ambos() const
{
	cout << "Qtd de Produtos: " << produtos << endl;
	cout << "Qtd de Ouro: " << ouro << endl;
}

void recursos::retira_custo(int a)
{
	ouro = ouro - a;
}

bool recursos::retira_recursos(int o, int p)
{
	if (ouro >= o) {
		ouro = ouro - o;
	}
	else {
		cout << "Ouro insuficiente" << endl;
		return false;
	}
	if (produtos >= p) {
		produtos = produtos - p;
	}
	else {
		cout << "Produtos insuficientes" << endl;
		return false;
	}
	return true;
}

bool recursos::compra_militar()
{
	if (ouro > 0 && produtos > 0)
	{
		ouro = ouro - 1;
		produtos = produtos - 1;
		return true;
	}
	return false;
}

void recursos::mod_recursos_DEBUG(string tipo, int lim_p, int lim_o)
{

	ouro = tipo[0] - 48;
	produtos = tipo[2] - 48;

}