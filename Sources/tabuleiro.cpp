
#include "tabuleiro.h"

using namespace std;

tabuleiro::tabuleiro() {
	this->inicio = NULL;
	this->c = NULL;
}

bool tabuleiro::vazia(){
	return this->inicio == NULL;
}

void tabuleiro::incluir(Casa * e) {
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

//void tabuleiro::localizarFrente(int id){
//    casa  *atual;
//    int pos = 1;
//    if (inicio == NULL)
//        std::cout << "\n Lista Vazia";
//    else {
//        atual = inicio;
//        while (atual != NULL){
//            if (atual->getId() == id)
//            {
//                std::cout << "O elemento de id " << atual->getId() << " e nome " << atual->getNome() << " foi encontrado na posicao " << pos;
//                break;
//            }
//            atual = atual->getProx();
//            pos++;
//        }
//    }
//}

//void tabuleiro::localizarTras(int id){
//    Elemento  *atual;
//    int pos = 1;
//    if (inicio == NULL)
//        std::cout << "\n Lista Vazia";
//    else {
//        atual = inicio;
//        while (atual != NULL){
//            if (atual->getId() == id)
//            {
//                std::cout << "O elemento de id " << atual->getId() << " e nome " << atual->getNome() << " foi encontrado na posicao " << pos;
//                break;
//            }
//            atual = atual->getPrev();
//            pos++;
//        }
//    }
//}

void tabuleiro::imprimir(){

	cout << "\nImpressao do tabuleiro\n";
	cout << "Casa  Status  Jogador*  Jogadores** \n";
	if (!vazia()){
		Casa * cursor = inicio;
		int n = 0;
		while (true){
            if (n < 9){
                cout << "  " << cursor->getPos() << "    ";
                cout << "  " << cursor->getStatus()<< "     ";
                cout << "  " << cursor->getJogadorProprietario() << "          ";
                int * j = cursor->getJogadores();
                cout << j[n] << "\n";

            }
            else{
                cout << "  " << cursor->getPos() << "   ";
                cout << "  " << cursor->getStatus()<< "     ";
                cout << "  " << cursor->getJogadorProprietario() << "          ";
                int * j = cursor->getJogadores();
                cout << j[n] << "\n";
            }
            n++;


			cursor = cursor->getProx();
			if (cursor == inicio){
				break;
			}
		}
	}

}
