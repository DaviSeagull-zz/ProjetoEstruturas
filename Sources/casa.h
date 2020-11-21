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
    void setPos(int pos);
    int getPos();
    void setJogadorProprietario(int jogador_proprietario);
    int getJogadorProprietario();
    void setJogadores(int jogadores[]);
    int * getJogadores();
    void setProx(Casa * e);
    Casa * getProx();
    void setPrev(Casa * e);
    Casa * getPrev();
    int setStatus(int status);
    int getStatus();
    void setJogadoresNull();

};

#endif // CASA_H
