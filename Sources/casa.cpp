
#include "casa.h"

Casa::Casa(){
	this->setProx(NULL);
	this->setPrev(NULL);
	this->setStatus(0);
    this->setJogadorProprietario(0);
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

void Casa::addJogadores(int j){
    jogadores_na_pos.push_back(j);
}


void Casa::removeJogadores(Casa * pos_j, int j){
    auto it = find(pos_j->jogadores_na_pos.begin(), pos_j->jogadores_na_pos.end(), j);
    if (it != pos_j->jogadores_na_pos.end())
        pos_j->jogadores_na_pos.erase(it);
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


int Casa::getJogadorProprietario(){
	return this->jogador_proprietario;
}

void Casa::showJogadores() {
    for (vector<int>::iterator p = jogadores_na_pos.begin(); p != jogadores_na_pos.end(); ++p) {
        cout << (*p) << " ";
    }
}

Casa * Casa::walk(Casa * pos_j, int andar_casas, int sentido, int j){
    Casa * pos_final = pos_j;
    removeJogadores(pos_j, j);
    if(sentido == 1)
        for (int i = 0; i < andar_casas; i++)
            pos_final = pos_final->getProx();
    else
        for (int i = 0; i < andar_casas; i++)
            pos_final = pos_final->getPrev();
    return pos_final;
}
