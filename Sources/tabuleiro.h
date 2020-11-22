#ifndef TABULEIRO_H
#define TABULEIRO_H

#include "casa.h"

class Tabuleiro {

    private:
    Casa * inicio;
    Casa * c;

    public:
    Tabuleiro();
    bool vazia();
    Casa * getInicio();
    void incluir(Casa * e);
    void localizarFrente(int id);
    void localizarTras(int id);
    void imprimir();


};



#endif // tabuleiro_H_INCLUDED
