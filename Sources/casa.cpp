
#include "casa.h"

Casa::Casa(){
	this->setProx(NULL);
	this->setPrev(NULL);
}

void Casa::setPos(int pos){
	this->pos = pos;
}

int Casa::getPos(){
	return this->pos;
}

int Casa::setStatus(int status){
    this->status = status;
}

void Casa::setJogadorProprietario(int jogador_proprietario){
	this->jogador_proprietario = jogador_proprietario;

}

void Casa::setJogadores(int jogadores[]){
    for (int i = 0; i < sizeof(jogadores); i++){
        this->jogadores_na_pos[i] = jogadores[i];
    }
}

void Casa::setJogadoresNull(){
    for (int i = 0; i < sizeof(jogadores_na_pos)/4; i++){
        this->jogadores_na_pos[i] = 0;
    }
}

void Casa::setProx(Casa * e){
	this->prox = e;
}

void Casa::setPrev(Casa * e){
	this->prev = e;
}

int Casa::getStatus(){
	return this->status;
}

Casa * Casa::getPrev(){
	return this->prev;
}

Casa * Casa::getProx(){
	return this->prox;
}

int * Casa::getJogadores(){
	return this->jogadores_na_pos;
}

int Casa::getJogadorProprietario(){
	return this->jogador_proprietario;
}

void walk(Casa * pos_j, int andar_casas){

    for (int i = 0; i < andar_casas; i++){
        pos_j = pos_j->getProx();
    }

}
