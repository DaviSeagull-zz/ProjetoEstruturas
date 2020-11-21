/*
	Programa para estudo do TAD Lista Duplamente Encadeada Circular
	Desenvolvido por prof. Marcio Feitosa - 15/10/2020
*/
#include <iostream>

#include "tabuleiro.h"
#include "jogador.h"

using namespace std;

int main()
{

	tabuleiro tabuleiro;

	while (true){

		cout << "\n\n";
		cout << "\n-----------------------------------------------------------------";
		cout << "\n              JOGO DA LISTA DUPLAMENTE ENCADEADA CIRCULAR        ";
		cout << "\n-----------------------------------------------------------------";
		cout << "\n";

        int n_casas, n_jogadores, n_moedas, n_rodadas;

        while(true){
            cout << "\nInforme a quantidade de casas a partir de 10: ";
            cin >> n_casas;
            if(n_casas < 10)
                cout << "\nDigite uma quantidade valida\n";
            else
                break;
        }

        while(true){
            cout << "\nInforme a quantidade de jogadores: ";
            cin >> n_jogadores;
            if(n_jogadores < 2)
                cout << "\nDigite uma quantidade valida\n";
            else
                break;
        }

        cout << "\nInforme a quantidade de moedas: ";
        cin >> n_moedas;
        cout << "\nInforme a quantidade de rodadas que deseja jogar: ";
        cin >> n_rodadas;

        for (int i = 1; i <= n_casas; i++){
            Casa * e = new Casa();
            e->setPos(i);
            e->setStatus(0);
            e->setJogadorProprietario(0);
            e->setJogadoresNull();
            tabuleiro.incluir(e);
        }

        for(int i = 1; i <= n_jogadores; i++){


        }
        tabuleiro.imprimir();
	}

    return 0;
}
