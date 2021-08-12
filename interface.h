//Programação Orientada a Objetos ISEC LEI - 20/21
//Trabalho Prático Realizado por:
//Gonçalo Ramalho 2019106561
//Rafael Correia 2019131435

#ifndef INTERFACE_H
#define INTERFACE_H
#include <vector>
#include <string>

using namespace std;

class interface
{
	vector<string> commands;

public:
	interface();
	bool chama_verifica_comando(string cmd);
	string comando(int fase);
	void evento_selecionado(int num, int turno);
	void fim_invasao(bool flag_inv);
	bool verifica_tipo_toma(string tipo);

};
#endif
