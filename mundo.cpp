//Programação Orientada a Objetos ISEC LEI - 20/21
//Trabalho Prático Realizado por:
//Gonçalo Ramalho 2019106561
//Rafael Correia 2019131435

#include "mundo.h"
#include "continente.h"
#include "ilha.h"
#include "t_inicial.h"
#include "utils.h"

mundo::mundo() {}

mundo& mundo::operator=(const mundo& outro)
{
	//preven��o da auto-atribui��o
	if (this == &outro) {
		return *this;
	}
	//libertar memoria dinamica do primeiro membro da atribui��o
	for (territorio* t : terra) {
		delete t;
	}
	//esvaziar o vector
	terra.clear();
	//copiar a informa��o de outro, duplicando os objectos dinamicos do tipo territorio
	for (territorio* t : outro.terra)
		terra.push_back(t->duplica());

	return *this;
}

mundo::mundo(const mundo& outro)
{
	*this = outro;
}

void mundo::info_mundo() const
{
	cout << "### TENHO NO MUNDO: " << endl;
	for (auto c : terra)
		c->mostra_territorio();
}

void mundo::info_imperio() const
{
	cout << "### PERTENCEM AO IMPERIO: " << endl;
	for (auto c : terra)
		c->mostra_imperio();
}

void mundo::info_territorio(string nome_territorio) const
{
	bool encontrei = false;
	for (auto c : terra) {
		if (uppercase_funcao(nome_territorio) == uppercase_funcao(c->retorna_nome())) {
			c->mostra_territorio();
			encontrei = true;
		}
	}
	if (!encontrei)
		cout << "Territorio nao existe!" << endl;
}

void mundo::acrescenta_terra(territorio* t)
{
		terra.push_back(t->duplica());
}

void mundo::procura_recursos(recursos* x, int lim_p, int lim_o)
{
	int p = 0, o = 0;
	for (auto c : terra) {
		if (c->verifica_imperio()) {
			p = p + c->devolve_produtos();
			o = o + c->devolve_ouro();
		}
	}
	(*x).adiciona_recursos(p, o, lim_p, lim_o);
}

void mundo::actualizador_recursos_territorios()
{
	for (auto c : terra) {
		c->altera_recursos(turno);
	}
}

void mundo::fator_sorte()
{
	fator = ( 1 + rand() % (6 - 1 + 1) );
}

void mundo::conquista_territorio(string s, int* militares, bool se_ilha)
{
	ilha* b;

	bool encontrei = false;
	for (auto& c : terra) {
		if ( (uppercase_funcao(s) == uppercase_funcao(c->retorna_nome())) && !(c->verifica_imperio()) ) {
			cout << (*militares + fator) << endl; //apagar
			if (b = dynamic_cast<ilha*> (c)) {
				if (se_ilha == false) {
					cout << "Para atacar uma ilha e preciso ter a tecnologia de misseis" << endl;
					return;
			   }
			}
			if ((*militares + fator) >= c->devolve_resistencia()) {
				c->adiciona_imperio();
				cout << "O ataque foi bem sucedido!" << endl;
			}
			else {
				cout << "O ataque nao foi bem sucedido!" << endl;
				if (*militares != 1) {
					(*militares)--;
					cout << "Perdeu 1 unidade de forca militar!" << endl;
				}
			}
			encontrei = true;
		}
	}
	if (!encontrei)
		cout << "Territorio para conquistar invalido!" << endl;
}

void mundo::aumenta_turno()
{
	turno++;
}

void mundo::mostra_turno() const
{
	if(turno <= 6)
		cout << "\n" << "Ano: 1" << endl;
	else
		cout << "\n" << "Ano: 2" << endl;
	cout << "Turno: " << turno << endl;
	cout << "Fator sorte gerado: " << fator << endl;
}

int mundo::devolve_turno() const
{
	return turno;
}

bool mundo::tenta_invadir(int poder, bool defesas)
{
	int a = 0;
	for (auto it = terra.rbegin(); it != terra.rend(); it++) {
		if ((*it)->verifica_imperio()) {
			cout << "O imperio inimigo esta a atacar " << (*it)->retorna_nome() << endl;
			if (defesas == true)
				a = 1;
			if (((*it)->devolve_resistencia() + a) < poder) {
				(*it)->retira_imperio();
				return true;
			}
			return false;
		}
	}
}

int mundo::pontos_territorio()
{
	int pontos = 0;
	bool tudo_conq = true;
	ilha* b;

	for (auto& c : terra) {
		if (c->verifica_imperio() && c->retorna_nome() != "Territorio Inicial") {
			pontos = c->devolve_pontos();
		}
		else {
			tudo_conq = false;
		}
	}
	cout << "Pontos recebidos por causa dos terrenos conquistados: " << pontos << endl;

	if (tudo_conq == true) {
		cout << "Bonus imperador supremo + 3 pontos" << endl;
		pontos = pontos + 3;
	}
	return pontos;
}

mundo::~mundo()
{
	for (territorio* t : terra)
		delete t;
}

void mundo::toma_a_forca_terr(string antvalor) 
{
	bool encontrei = false;
	for (auto& c : terra) {
		if ((uppercase_funcao(antvalor) == uppercase_funcao(c->retorna_nome())) && !(c->verifica_imperio())) {
				c->adiciona_imperio();
				encontrei = true;
			}
		}
	if (!encontrei)
		cout << "Territorio para tomar invalido!" << endl;
}

