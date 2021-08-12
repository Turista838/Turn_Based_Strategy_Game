//Programação Orientada a Objetos ISEC LEI - 20/21
//Trabalho Prático Realizado por:
//Gonçalo Ramalho 2019106561
//Rafael Correia 2019131435

#include "jogador.h"
#include "utils.h"
#include <sstream>
#include <fstream>
#include "t_inicial.h"

jogador::jogador(mundo* m) : jogo(m), militar(3), r(0,0), fase(0)
{
    t_inicial a;
    jogo->acrescenta_terra(&a);
}

void jogador::iniciar() {

    string menu, cmd, tipo, teste_toma, anttipo, antvalor;
    int valor = 0;
    jogo->fator_sorte();

    do {
        if (fase == 2) {
            jogo->procura_recursos(&r, lim_prod, lim_ouro);
            if (tec.retorna_estado_bolsa() == false) // se a tec bolsa de valores tiver comprada o jogador pode trocar recursos
                fase++;
        }
        if (fase == 4) {
            aciona_evento(10);
            jogo->fator_sorte();
            jogo->aumenta_turno();
            jogo->actualizador_recursos_territorios();
            fase = 1;
        }
        if (jogo->devolve_turno() == 13) {
            calcula_score();
            return;
        }
        menu = inter_jog.comando(fase);

        istringstream iss_prev(menu);
        iss_prev >> teste_toma >> anttipo >> antvalor;
        if (uppercase_funcao(teste_toma) == "TOMA") {
            toma_DEBUG(anttipo, antvalor);
            anttipo = "";
            antvalor = "";
        }
        else {
            istringstream iss(menu);

            iss >> cmd >> tipo >> valor;

            cout << menu << endl;

            if (fase == 0 && (cmd == "CONQUISTA" || cmd == "AVANCA"))
                fase = 1;

            jogador::operacoes(cmd, tipo, valor);
            tipo = "";
            valor = 0;
        }
    } while (cmd != "SAIR");
    calcula_score();
}


void jogador::operacoes(string cmd, string tipo, int valor)
{
    if (cmd == "CRIAR" && fase == 0) {
        for (int i = 0; i < valor; i++) {
            if (tipo == "MONTANHA") {
                montanha a;
                jogo->acrescenta_terra(&a);
            }
            if (tipo == "PLANICIE") {
                planicie a;
                jogo->acrescenta_terra(&a);
            }
            if (tipo == "FORTALEZA") {
                fortaleza a;
                jogo->acrescenta_terra(&a);
            }
            if (tipo == "MINA") {
                mina a;
                jogo->acrescenta_terra(&a);
            }
            if (tipo == "DUNA") {
                duna a;
                jogo->acrescenta_terra(&a);
            }
            if (tipo == "CASTELO") {
                castelo a;
                jogo->acrescenta_terra(&a);
            }
            if (tipo == "PESCARIA") {
                pescaria a;
                jogo->acrescenta_terra(&a);
            }
            if (tipo == "REFUGIO DOS PIRATAS") {
                refugio a;
                jogo->acrescenta_terra(&a);
            }
        }
    }
    else if (cmd == "CRIAR" && fase != 0) {
        cout << "Comando invalido! Ja passou a fase de defincao do mundo" << endl;
    }
    if (cmd == "CONQUISTA" && fase == 1) {
        jogo->conquista_territorio(tipo, &militar, tec.retorna_estado_misseis());
        fase++;
    }
    if (cmd == "AVANCA" && fase != 1) {
        fase++;
    }
    if (cmd == "PASSA" && fase == 1) {
        fase++;
    }
    if (cmd == "MAISMILITAR" && fase == 3) {
        mais_func(0);
        fase++;
    }
    if (cmd == "MAISOURO" && fase == 2 && tec.retorna_estado_bolsa() == true) {
        mais_func(1);
        fase++;
    }
    if (cmd == "MAISPROD" && fase == 2 && tec.retorna_estado_bolsa() == true) {
        mais_func(2);
        fase++;
    }
    if (cmd == "ADQUIRE" && fase == 3) {
        jogador::tecnologias_func(tipo); //fun��o que trata das tecnologias recebe tipo
        fase++;
    }
    if (cmd == "LISTA") {
        if (tipo != "") {
            jogo->info_territorio(tipo);
        }
        else {
            jogo->mostra_turno();
            cout << "Tem " << militar << " unidades militares" << endl;
            jogo->info_imperio();
            jogo->info_mundo();
            r.mostra_ambos();
        }
    }
    if (cmd == "CARREGA" && fase == 0) {
        ifstream ficheiro(tipo);
        if (!ficheiro.is_open()) {
            cout << "Erro ao abrir o ficheiro!" << endl;
        }
        string fich;
        while (getline(ficheiro, fich)) {
            istringstream ler(fich);
            ler >> cmd >> tipo >> valor;
            cmd = uppercase_funcao(cmd);
            if (fase == 0 && (cmd == "CONQUISTA" || cmd == "AVANCA")) {
                fase = 1;
            }
            if (fase == 2) {
                jogo->procura_recursos(&r, lim_prod, lim_ouro);
                fase++;
            }
            if (fase == 4) {
                jogo->fator_sorte();
                jogo->aumenta_turno();
                fase = 1;
            }
            if (inter_jog.chama_verifica_comando(cmd)) {
                if (cmd == "CRIAR") {
                    tipo = uppercase_funcao(tipo);
                    if (verifica_tipo(tipo))
                        jogador::operacoes(cmd, tipo, valor);
                    else
                        cout << "Tipo nao existe" << endl;
                }
                else
                    jogador::operacoes(cmd, tipo, valor);
            }
            else {
                cout << "Comando nao existe!" << endl;
            }
            tipo = "";
            valor = 0;
        }
        ficheiro.close();
    }
    if (cmd == "FEVENTO")
        evento_DEBUG(tipo);

    if (cmd == "MODIFICA")
        r.mod_recursos_DEBUG(tipo, lim_prod, lim_ouro);
    if (cmd == "GRAVA") {
        if(tipo != ""){
            mundo h(*jogo);
            recursos copia_r = r;
            tecnologias copia_t = tec;
            mundos_guardados.push_back(h);
            nomes_mundos_guardados.push_back(tipo);
            recursos_guardados.push_back(copia_r);
            tecnologias_guardados.push_back(copia_t);
            cout << "Savegame com o nome: " << tipo << endl;
        }
        else {
            cout << "Nome do Savegame invalido!" << endl;
        }
        
    }
    if (cmd == "ATIVA") {
        if (tipo != "") {
            for (int i = 0; i< nomes_mundos_guardados.size(); i++) {
                if (nomes_mundos_guardados[i] == tipo) {
                    jogo = &mundos_guardados[i];
                    r = recursos_guardados[i];
                    tec = tecnologias_guardados[i];
                    return;
                }    
            }
        }
        cout << "Nome do Savegame invalido!" << endl;
    }
    if (cmd == "APAGA") {
        if (tipo != "") {

            int i;
            for (i = 0; i < nomes_mundos_guardados.size(); i++) {
                if (nomes_mundos_guardados[i] == tipo) {
                    nomes_mundos_guardados.erase(nomes_mundos_guardados.begin()+i);
                    mundos_guardados.erase(mundos_guardados.begin() + i);
                    recursos_guardados.erase(recursos_guardados.begin() + i);
                    tecnologias_guardados.erase(tecnologias_guardados.begin() + i);
               }
            }
        }
    }
    
}

void jogador::evento_DEBUG(string tipo)
{
    tipo = uppercase_funcao(tipo);

    if (tipo == "RECURSO_ABANDONADO") {
        aciona_evento(1);
        return;
    }
    if (tipo == "INVASAO") {
        aciona_evento(2);
        return;
    }
    if (tipo == "ALIANCA_DIPLOMATICA") {
        aciona_evento(3);
        return;
    }
    cout << "Evento desconhecido" << endl;
}

void jogador::calcula_score()
{
    int pontos = 0;

    pontos = jogo->pontos_territorio();

    pontos = pontos + tec.pontos_tecnologias();


    cout << "\nPontuacao final: " << pontos << endl;
}


void jogador::aciona_evento(int a)
{
    int num, turno;
    bool flag_inv;
    num = 1 + rand() % 4;
    turno = jogo->devolve_turno();

    if (a != 10)
        num = a;

    inter_jog.evento_selecionado(num, turno);

    if (num == 1) {
        if (turno <= 6) {
            r.adiciona_recursos(1, 0, lim_prod, lim_ouro);
            return;
        }
        else {
            r.adiciona_recursos(0, 1, lim_prod, lim_ouro);
            return;
        }
    }
    if (num == 2) {
        flag_inv = comeca_invasao();
        inter_jog.fim_invasao(flag_inv);
        return;
    }

    if (num == 3) {
        if (militar < lim_militar) {
            militar++;
        }
    }
}

bool jogador::comeca_invasao()
{
    int poder_inv;

    poder_inv = 1 + rand() % 6;
    if (jogo->devolve_turno() <= 6) {
        poder_inv == poder_inv + 2;
    }
    else {
        poder_inv == poder_inv + 3;
    }
    if (jogo->tenta_invadir(poder_inv, tec.retorna_estado_defesas()) == true)
        return true;
    return false;
}

void jogador::mais_func(int a)
{
    if (a == 0 && militar != lim_militar) {
        if (r.retira_recursos(1, 1) == true) {
            militar++;
        }
        return;
    }

    if (a == 1 && r.retorna_ouro() != lim_ouro) {
        if (r.retira_recursos(0, 2) == true) {
            r.adiciona_recursos(0, 1, lim_prod, lim_ouro);
        }
        return;
    }

    if (a == 1 && r.retorna_produtos() != lim_prod) {
        if (r.retira_recursos(2, 0) == true) {
            r.adiciona_recursos(1, 0, lim_prod, lim_ouro);
        }
        return;
    }
    cout << "Ja esta no limite atual possivel" << endl;
}

void jogador::tecnologias_func(string tipo) {
    int ouro = r.retorna_ouro(); //ouro antes de ccomprar tecnologia
    tipo = uppercase_funcao(tipo);
    if (tec.verifica_recursos(tipo, ouro) == true) { //verifica se o jogador tem dinheiro para comprar
        if (tipo == "DRONE" && tec.retorna_estado_drone() == false) {
            lim_militar = 5;  //aumenta limite da for�a militar
            r.retira_custo(3);  //ver no .h das tenologias
            tec.compra_drone(); //ver no .h das tenologias
            return;
        }

        if (tipo == "MISSIL" && tec.retorna_estado_misseis() == false) {
            r.retira_custo(4);
            tec.compra_misseis();
            return;
        }

        if (tipo == "DEFESA" && tec.retorna_estado_defesas() == false) {
            r.retira_custo(4);
            tec.compra_defesas();
            return;
        }

        if (tipo == "BOLSA" && tec.retorna_estado_bolsa() == false) {
            r.retira_custo(2);
            tec.compra_bolsa(); //esta tecnologia cria a possibilidade de ser usada durante a segunda fase ao escrever no menu comando
            return;
        }

        if (tipo == "BANCO") {
            lim_ouro = 5;
            lim_prod = 5;
            r.retira_custo(3);
            tec.compra_banco();
            return;
        }

        cout << "Teccnologia ja adquirida" << endl;
        return;
    }

    cout << "Ouro insuficiente" << endl;
}

void jogador::toma_DEBUG(string anttipo, string antvalor) 
{
    if (uppercase_funcao(anttipo) == "TEC") {
        tec.toma_a_forca_tec(antvalor);
    }
    if (uppercase_funcao(anttipo) == "TERR") {
        jogo->toma_a_forca_terr(antvalor);
    }

}
