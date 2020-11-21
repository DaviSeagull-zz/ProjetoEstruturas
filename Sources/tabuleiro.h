#ifndef TABULEIRO_H
#define TABULEIRO_H

#include "casa.h"

class tabuleiro {

    private:
    Casa * inicio;
    Casa * c;

    public:
    tabuleiro();
    bool vazia();
    void incluir(Casa * e);
    void localizarFrente(int id);
    void localizarTras(int id);
    void imprimir();


};



#endif // tabuleiro_H_INCLUDED
