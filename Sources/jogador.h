#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>
#include <vector>
#include <list>

#include "casa.h"

using namespace std;

class Jogador {

	private:
		Casa * pos;
        int jogador;
        int vivo;
        int moedas = 0;

    public:
        static vector<Jogador*> instances_;
        static void showList();
        static Jogador * returnAddress(int i);

        Jogador(int i, int n_moedas, Casa * c);

        int getJogador();
        bool getVivo();
        int getMoedas();
        Casa * getPos();

        void setPos(Casa * c);
        void setMoedas(int n_moedas);
        void setJogador(int id);
        void setDerrota();


        void updatePos(int andar_casas, int sentido);

};

#endif
