
#include "casa.h"

Casa::Casa(){
	this->setProx(NULL);
	this->setPrev(NULL);
	this->setStatus(0);
    this->setJogadorProprietario(0);
    this->setJogadoresNull();
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

//void Casa::addJogadores(){
//    jogadores_na_pos.push_back(this);
//}

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

//void Casa::showJogadores() {
//    for (vector<Jogador*>::iterator p = jogadores_na_pos.begin(); p != instances_.end(); ++p) {
//        cout << (*p) << " ";
//        cout << (*p)->getPos() << "\n";
//    }
//}

Casa * Casa::walk(Casa * pos_j, int andar_casas, int sentido){
    Casa * pos_final = pos_j;
    if(sentido == 1)
        for (int i = 0; i < andar_casas; i++)
            pos_final = pos_final->getProx();
    else
        for (int i = 0; i < andar_casas; i++)
            pos_final = pos_final->getPrev();
    return pos_final;
}
