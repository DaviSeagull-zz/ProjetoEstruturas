#ifndef PILHA_H
#define PILHA_H

using namespace std;

class Pilha{

    private:
        int * itens;
        int topo;
        int maximo;

    public:
        Pilha();
        Pilha(int n);
        bool empty();
        bool full();
        bool push(int);
        int pop();
        string print();
        int quantity();
        int verifyValue(int n);
        int valuesAbove(int n);
        void countFreq(int n);
};

#endif // PILHA_H
