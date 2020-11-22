#ifndef CASA_H
#define CASA_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Casa {

private:
    int pos;
    int jogador_proprietario;
    int status;
    int marcado_por;
    Casa * prox;
    Casa * prev;
    vector<int> jogadores_na_pos;

public:
    Casa();

    static Casa * walk(Casa* pos_j, int andar_casas, int sentido, int j);
    void showJogadores();

    void setPos(int pos);
    void setJogadorProprietario(int jogador_proprietario);
    void addJogadores(int j);
    static void removeJogadores(Casa * pos_j, int j);
    void setProx(Casa * e);
    void setPrev(Casa * e);
    void setMarcadoPor(int marcado_por);
    int setStatus(int status);

    int getMarcadoPor();
    int getPos();
    int getJogadorProprietario();
    int getJogadores();
    Casa * getProx();
    Casa * getPrev();
    int getStatus();



};

#endif // CASA_H
