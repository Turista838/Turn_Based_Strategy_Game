//Programação Orientada a Objetos ISEC LEI - 20/21
//Trabalho Prático Realizado por:
//Gonçalo Ramalho 2019106561
//Rafael Correia 2019131435

#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include "castelo.h"
#include "duna.h"
#include "fortaleza.h"
#include "mina.h"
#include "montanha.h"
#include "pescaria.h"
#include "planicie.h"
#include "refugio.h"
using namespace std;

#define Terries 9 //Fazer altera��es quando 2� meta
const string territories[Terries] = { "TERRITORIO INICIAL", "MONTANHA", "PLANICIE", "FORTALEZA", "MINA", "DUNA", "CASTELO", "REFUGIO DOS PIRATAS", "PESCARIA" };

bool verifica_comando(string s, vector<string> c);
bool verifica_tipo(string s);
string uppercase_funcao(string s);

#endif
