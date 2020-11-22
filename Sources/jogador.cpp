#include <sstream>
#include <iostream>

#include "jogador.h"
#include "tabuleiro.h"
#include "casa.h"

using namespace std;

vector<Jogador*> Jogador::instances_;

Jogador::Jogador(int i, int n_moedas, Casa * c) {

    instances_.push_back(this);
	this->jogador = i;
    this->derrota = true;
	this->setMoedas(n_moedas);
	this->setPos(c);

}

Jogador * Jogador::returnAddress(int i){
    return instances_[i];
}

void Jogador::updatePos(int andar_casas){
    Casa * c_atual = this->getPos();
    Casa::walk(c_atual, andar_casas);
    this->getPos();
}

void Jogador::setPos(Casa * c){
    this->pos = c;
}

void Jogador::setMoedas(int n_moedas){
	this->moedas += n_moedas;
}

void Jogador::setDerrota(){
	this->derrota = true;
}

Casa * Jogador::getPos(){
    return this->pos;
}

int Jogador::getJogador(){
    return this->jogador;
}

bool Jogador::getDerrota(){
    return this->derrota;
}

int Jogador::getMoedas(){
    return this->moedas;
}

void Jogador::showList() {
    for (vector<Jogador*>::iterator p = instances_.begin(); p != instances_.end(); ++p) {
        cout << (*p) << " ";
        cout << (*p)->getPos() << "\n";
    }
}
