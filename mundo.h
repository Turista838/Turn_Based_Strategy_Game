//Programação Orientada a Objetos ISEC LEI - 20/21
//Trabalho Prático Realizado por:
//Gonçalo Ramalho 2019106561
//Rafael Correia 2019131435

#ifndef MUNDO_H
#define MUNDO_H
#include <vector>
#include "territorio.h"

class mundo
{
	vector<territorio*> terra;
	int turno = 1;
	int fator = 0;

public:
	mundo();
	mundo& operator=(const mundo& outro);
	mundo(const mundo& outro);
	void info_mundo() const;
	void info_imperio() const;
	void info_territorio(string nome_territorio) const;
	void acrescenta_terra(territorio* t);
	void procura_recursos(recursos* x, int lim_p, int lim_o);
	void actualizador_recursos_territorios();
	void fator_sorte();
	void conquista_territorio(string s, int* r, bool se_ilha);
	void aumenta_turno();
	void mostra_turno() const;
	int devolve_turno() const;
	bool tenta_invadir(int poder, bool defesas);
	int pontos_territorio();
	void toma_a_forca_terr(string antvalor);
	~mundo();

};

#endif
