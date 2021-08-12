//Programação Orientada a Objetos ISEC LEI - 20/21
//Trabalho Prático Realizado por:
//Gonçalo Ramalho 2019106561
//Rafael Correia 2019131435

#ifndef JOGADOR_H
#define JOGADOR_H
#include "mundo.h"
#include "interface.h"
#include "tecnologias.h"

class jogador
{
	recursos r;
	int militar;
	int fase;
	mundo* jogo;
	vector<mundo> mundos_guardados;
	vector<string> nomes_mundos_guardados;
	vector<recursos> recursos_guardados;
	vector<tecnologias> tecnologias_guardados;
	interface inter_jog;
	tecnologias tec;     // tecnologias
	int lim_militar = 3; //limite adicionado durante as tecnologias
	int lim_ouro = 3;    //limite adicionado durante as tecnologias
	int lim_prod = 3;    //limite adicionado durante as tecnologias

public:
	jogador(mundo* m);
	void iniciar();
	void operacoes(string cmd, string tipo, int valor);
	void tecnologias_func(string tipo);
	void aciona_evento(int a);
	void mais_func(int a);
	bool comeca_invasao();
	void evento_DEBUG(string tipo);
	void calcula_score();
	void toma_DEBUG(string anttipo, string antvalor);
};
#endif

