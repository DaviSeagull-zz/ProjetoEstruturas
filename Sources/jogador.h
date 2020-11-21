#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>

#include <pilha.h>

using namespace std;

class Jogador {

	private:
		int * fila;
        int jogador;
        bool derrota = false;
//        Pilha pilha_de dinheiro = new Pilha();

    public:
        Jogador(int i);
        int getJogador();
        bool getDerrota();

        void setJogador(int id);
        void setDerrota();

};

#endif
