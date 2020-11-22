#include <sstream>
#include <iostream>

#include "jogador.h"

using namespace std;

vector<Jogador*> Jogador::instances_;

Jogador::Jogador(int i, int n_moedas, Casa * c) {

    instances_.push_back(this);
	this->jogador = i;
    this->vivo = true;
	this->setMoedas(n_moedas);
	this->setPos(c);

}

Jogador * Jogador::returnAddress(int i){
    return instances_[i];
}

void Jogador::updatePos(int andar_casas, int sentido){

    Casa * c_atual = this->getPos();
    int j = this->getJogador();
    this->setPos(Casa::walk(c_atual, andar_casas, sentido, j));
    Casa * c_final = this->getPos();
    if(this->getJogador() != c_final->getMarcadoPor() && c_final->getStatus() == 1){
        int opc;
        cout << "- Digite 1 caso queira deixar como esta e nao pagar nada\n- Digite 2 caso queira pagar 1 moeda e desmarcar o jogador: ";
        cin >> opc;
        if(opc == 2){
            this->setMoedas(-1);
            Jogador * j_da_casa = returnAddress((c_final->getMarcadoPor()-1));
            j_da_casa->setMoedas(1);
            c_final->setMarcadoPor(0);
            c_final->setStatus(0);
        }
    }

    if(c_final->getJogadorProprietario() != 0)
    if(this->getJogador() != c_final->getJogadorProprietario() && c_final->getStatus() == 2){
        int opc;
        cout << "- Digite 1 caso queira apenas a multa de 2 moedas\n";
        cout << "- Digite 2 caso queira pagar a multa 4 moeda e deixar a casa como marcada\n";
        cout << "- Digite 3 caso queira pagar a multa de 8 moedas e deixar a casa livre";
        cout << "Opcao: ";
        cin >> opc;
        if(opc == 1){
            this->setMoedas(-2);
            Jogador * j_da_casa = returnAddress((c_final->getMarcadoPor()-1));
            j_da_casa->setMoedas(2);
        } else if (opc == 2){
            this->setMoedas(-4);
            Jogador * j_da_casa = returnAddress((c_final->getMarcadoPor()-1));
            j_da_casa->setMoedas(4);
            c_final->setStatus(1);
            c_final->setJogadorProprietario(0);
        } else if(opc == 3) {
            this->setMoedas(-4);
            Jogador * j_da_casa = returnAddress((c_final->getMarcadoPor()-1));
            j_da_casa->setMoedas(4);
            c_final->setStatus(0);
            c_final->setMarcadoPor(0);
            c_final->setJogadorProprietario(0);
        }

    }
}

void Jogador::setPos(Casa * c){
    this->pos = c;
    this->getPos()->addJogadores(this->getJogador());
}

void Jogador::setMoedas(int n_moedas){
	this->moedas += n_moedas;
}

void Jogador::setDerrota(){
	this->vivo = false;
}

Casa * Jogador::getPos(){
    return this->pos;
}

int Jogador::getJogador(){
    return this->jogador;
}

bool Jogador::getVivo(){
    return this->vivo;
}

int Jogador::getMoedas(){
    return this->moedas;
}

void Jogador::showList() {
    for (vector<Jogador*>::iterator p = instances_.begin(); p != instances_.end(); ++p) {
        cout << (*p)->getJogador() << " ";
        cout << (*p)->getMoedas() << "\n";
    }
}
