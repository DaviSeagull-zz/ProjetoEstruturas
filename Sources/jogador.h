#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>
#include <vector>
#include <list>

#include "casa.h"
#include "tabuleiro.h"

using namespace std;

class Jogador {

	private:
		Casa * pos;
        int jogador;
        int derrota = false;
        int moedas = 0;

    public:
        static vector<Jogador*> instances_;
        static void showList();
        Jogador(int i, int n_moedas, Casa * c);

        int getJogador();
        bool getDerrota();
        int getMoedas();
        Casa * getPos();

        void setPos(Casa * c);
        void setMoedas(int n_moedas);
        void setJogador(int id);
        void setDerrota();

        static Jogador * returnAddress(int i);
        void updatePos(int andar_casas);

};

#endif
