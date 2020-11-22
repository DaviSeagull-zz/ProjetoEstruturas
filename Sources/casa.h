#ifndef CASA_H
#define CASA_H

#include <iostream>
#include <string>

using namespace std;

class Casa {

private:
    int pos;
    int jogador_proprietario;
    int status;
    Casa * prox;
    Casa * prev;
    int jogadores_na_pos[15];

public:
    Casa();

    static void walk(Casa* pos_j, int andar_casas);

    void setPos(int pos);
    void setJogadorProprietario(int jogador_proprietario);
    void setJogadores(int jogadores[]);
    void setProx(Casa * e);
    void setPrev(Casa * e);
    int setStatus(int status);
    void setJogadoresNull();


    int getPos();
    int getJogadorProprietario();
    int * getJogadores();
    Casa * getProx();
    Casa * getPrev();
    int getStatus();



};

#endif // CASA_H
