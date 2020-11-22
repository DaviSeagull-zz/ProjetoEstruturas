
#include "tabuleiro.h"

using namespace std;

Tabuleiro::Tabuleiro() {
	this->inicio = NULL;
	this->c = NULL;
}

Casa * Tabuleiro::getInicio(){
    return this->inicio;
}

bool Tabuleiro::vazia(){
	return this->inicio == NULL;
}

void Tabuleiro::incluir(Casa * e) {
	if (vazia()){
		inicio = e;
		e->setProx(e);
		e->setPrev(e);
	}
	else{
		e->setPrev(c);
		e->setProx(inicio);
		c->setProx(e);
		inicio->setPrev(e);
	}
    c = e;
}

void Tabuleiro::imprimir(){

	cout << "\nImpressao do tabuleiro\n";
	cout << "Casa  Status  MarcadoPor  Jogador*  Jogadores** \n";
	if (!vazia()){
		Casa * cursor = inicio;
		int n = 0;
		while (true){
            if (n < 9){
                cout << "  " << cursor->getPos() << "    ";
                cout << "  " << cursor->getStatus()<< "     ";
                cout << "  " << cursor->getMarcadoPor()<< "        ";
                cout << "  " << cursor->getJogadorProprietario() << "       ";
                cursor->showJogadores();
                cout << "\n";

            }
            else{
                cout << "  " << cursor->getPos() << "   ";
                cout << "  " << cursor->getStatus()<< "     ";
                cout << "  " << cursor->getMarcadoPor()<< "        ";
                cout << "  " << cursor->getJogadorProprietario() << "       ";
                cursor->showJogadores();
                cout << "\n";
            }

            n++;
			cursor = cursor->getProx();
			if (cursor == inicio){
				break;
			}
		}
	}

}
