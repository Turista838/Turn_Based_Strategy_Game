//Programação Orientada a Objetos ISEC LEI - 20/21
//Trabalho Prático Realizado por:
//Gonçalo Ramalho 2019106561
//Rafael Correia 2019131435

#include "territorio.h"

territorio::territorio(string s, int cont, int res, int prod, int ouro) : nome(s), is_imperium(false), resistencia(res), x(prod, ouro)
{
	if (nome == "Territorio Inicial") {
		is_imperium = true;
	}
	else {
		nome = s + to_string(cont);
	}
}

void territorio::alterador(int a, int b)
{
	x.actualiza(a, b);
}


void territorio::adiciona_imperio()
{
	is_imperium = true;
}

void territorio::retira_imperio()
{
	is_imperium = false;
}

void territorio::mostra_territorio() const
{
	if (is_imperium == false) {
		cout << "Nome: " << nome << "\nResistencia: " << resistencia << endl;
		x.mostra_ambos();
		cout << endl;
	}
}

void territorio::mostra_imperio() const
{
	if (is_imperium == true) {
		cout << "Nome: " << nome << "\nResistencia: " << resistencia << endl;
		x.mostra_ambos();
		cout << endl;
	}
}

string territorio::retorna_nome() const { return nome; }

bool territorio::verifica_imperio() const { return is_imperium; }

int territorio::devolve_resistencia() const { return resistencia; }

const int territorio::devolve_produtos() { return x.retorna_produtos(); }

const int territorio::devolve_ouro() { return x.retorna_ouro(); }