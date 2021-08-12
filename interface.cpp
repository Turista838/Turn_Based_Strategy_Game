//Programação Orientada a Objetos ISEC LEI - 20/21
//Trabalho Prático Realizado por:
//Gonçalo Ramalho 2019106561
//Rafael Correia 2019131435

#include "interface.h"
#include "utils.h"
#include <sstream>

interface::interface()
{
    commands.push_back("CRIAR");
    commands.push_back("CONQUISTA");
    commands.push_back("LISTA");
    commands.push_back("AVANCA");
    commands.push_back("PASSA");
    commands.push_back("CARREGA");
    commands.push_back("ADQUIRE");
    commands.push_back("MAISOURO");
    commands.push_back("MAISPROD");
    commands.push_back("MAISMILITAR");
    commands.push_back("FEVENTO");
    commands.push_back("MODIFICA");
    commands.push_back("TOMA");
    commands.push_back("GRAVA");
    commands.push_back("ATIVA");
    commands.push_back("APAGA");
    commands.push_back("SAIR");

}

bool interface::chama_verifica_comando(string cmd)
{
    if (verifica_comando(cmd, commands))
        return true;
    return false;
}

string interface::comando(int fase)
{
    string menu, cmd, tipo, anttipo, teste_toma, antvalor;
    int valor = 0;
    bool flag_menu = false;

    do {

        cout << "\nComando(fase " << fase << "): ";
        getline(cin, menu);

        istringstream iss_prev(menu);
        iss_prev >> teste_toma >> anttipo >> antvalor;
        if (uppercase_funcao(teste_toma) == "TOMA") {
            if (verifica_tipo_toma(anttipo) == true) {
                return uppercase_funcao(menu);
            }
        } 
        istringstream iss(menu);
        iss >> cmd >> tipo >> valor;

        cmd = uppercase_funcao(cmd);

        flag_menu = chama_verifica_comando(cmd);

        if (!flag_menu)
            cout << "Comando nao existe!" << endl;

        if (cmd == "CRIAR") {
            tipo = uppercase_funcao(tipo);

            flag_menu = verifica_tipo(tipo);

            if (!flag_menu) {
                valor = 0;
                cout << "Tipo nao existe" << endl;
            }
            if (valor <= 0) {
                cout << "Valor invalido" << endl;
            }
        }


    } while (!flag_menu);

    return uppercase_funcao(menu);

}

void interface::evento_selecionado(int num, int turno)
{
    if (num == 1) {
        if (turno <= 6) {
            cout << "Foi encontrado 1 unidade de produtos abandonado" << endl;
            cout << "Este sera adicionado aos seus recursos se possivel" << endl;
        }
        else {
            cout << "Foi encontrado 1 unidade de ouro abandonado" << endl;
            cout << "Este sera adicionado aos seus recursos se possivel" << endl;
        }
           
    }

    if (num == 2)
    {
        cout << "Um imperio inimigo esta a caminho de uma invasao num dos seus territorios" << endl;
    }

    if (num == 3)
    {
        cout << "\nO seu imperio fez uma alianca com um imperio vizinho" << endl;
        cout << "Como resultado o seu poder militar aumentara, se possivel" << endl;
    }
    if (num == 4)
    {
        cout << "Nada de especial aconteceu este turno" << endl;
    }
}

void interface::fim_invasao(bool flag_inv)
{
    if (flag_inv == true) {
        cout << "O imperio inimigo atacou com sucesso o seu territorio" << endl;
        cout << "Voce perdeu o territorio" << endl;
        return;
    }
    cout << "O ataque do imperio inimigo foi mal sucedido" << endl;
    cout << "O seu imperio nao sofreu danos significantes" << endl;
}

bool interface::verifica_tipo_toma(string tipo)
{
    if (uppercase_funcao(tipo) == "TERR" || uppercase_funcao(tipo) == "TEC") {
        return true;
    }
    cout << "So pode tomar territorios(terr) ou tecnologias(tec)" << endl;
    return false;
}