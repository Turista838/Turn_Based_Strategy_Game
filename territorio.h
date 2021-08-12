//Programação Orientada a Objetos ISEC LEI - 20/21
//Trabalho Prático Realizado por:
//Gonçalo Ramalho 2019106561
//Rafael Correia 2019131435

#ifndef TERRITORIO_H
#define TERRITORIO_H
#include <string>
#include "recursos.h"
using namespace std;

class territorio
{
	string nome;
	bool is_imperium;
	int resistencia;
	recursos x;

public:
	territorio(string s, int cont, int res, int prod, int ouro);

	void alterador(int a, int b);
	string retorna_nome() const;
	virtual void adiciona_imperio();
	void retira_imperio();
	bool verifica_imperio() const;
	void mostra_territorio() const;
	void mostra_imperio() const;
	int devolve_resistencia() const;
	const int devolve_produtos();
	const int devolve_ouro();
	virtual int devolve_pontos() = 0;
	virtual territorio* duplica() = 0;
	virtual void altera_recursos(int turno) = 0;
	
};

#endif

