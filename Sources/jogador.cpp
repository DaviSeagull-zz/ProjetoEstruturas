#include <sstream>

#include "jogador.h"

Jogador::Jogador(int i) {

	this->jogador = i;
    this->derrota = false;
	this->pilha_de_dinheiro;

}

int Jogador::getJogador(){
    return this->jogador;
}

bool Jogador::getDerrota(){
    return this->derrota;
}

void Jogador::setDerrota(){
	this->derrota = true;
}

//int Jogador::getPilha(){
//    return pilha_de_dinheiro.print();
//}

//void casa::setPilha(int id){
//	this->jogador = id;
//}
