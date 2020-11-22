#include <ctime>
#include <iostream>
#include <cstdlib>


#include "tabuleiro.h"
#include "jogador.h"

using namespace std;

void cleanScreen(){
    system("cls||clear");
}

int dice(){
    _sleep(1000);
    unsigned seed = time(0);
    srand(seed);
    int n = 1 + rand()%6;
    return n;
}


int main()
{
	Tabuleiro tabuleiro;

    cout << "\n-----------------------------------------------------------------";
    cout << "\n              JOGO DA LISTA DUPLAMENTE ENCADEADA CIRCULAR        ";
    cout << "\n-----------------------------------------------------------------";
    cout << "\n";

    int n_casas, n_jogadores, n_moedas, n_rodadas, rodada_atual = 1;

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
        tabuleiro.incluir(e);
    }

    for(int i = 1; i <= n_jogadores; i++){
        Jogador * j = new Jogador(i, n_moedas, tabuleiro.getInicio());
    }

    cleanScreen();

	while (rodada_atual != n_rodadas){
        for(int i = 0; i < n_jogadores; i++){
            Jogador * j = Jogador::returnAddress(i);

            if(j->getVivo()){
                cleanScreen();

                tabuleiro.imprimir();

                int opc_dados, sentido, andar_casas;

                cout << "Vez do jogador " << (i+1) << "\n";
                cout << "\nRolando os dados...\n";
                int d1 = dice();
                int d2 = dice();

                cout << "\nResultado do Dado 1: " << d1 << "\nResultado do Dado 2: " << d2 << endl;

                while(true) {
                    cout << "\n- Digite 0 caso queira usar a soma dos dados";
                    cout << "\n- Digite 1 caso queira usar somente o resultado do dado 1";
                    cout << "\n- Digite 2 caso queira usar somente o resultado do dado 2\n";
                    cout << "Opcao: ";
                    cin >> opc_dados;

                    if(opc_dados == 0){
                        andar_casas = d1 + d2;
                        break;
                    } else if(opc_dados == 1) {
                        andar_casas = d1;
                        break;
                    } else if (opc_dados == 2){
                        andar_casas = d2;
                        break;
                    } else {
                        cleanScreen();
                        cout << "\nDigite um valor valido\n";
                    }
                }

                cout << "\nDigite 1 para sentido horario e 0 para sentido anti-horario: ";
                cin >> sentido;


                j->updatePos(andar_casas, sentido);
            }

        }
        rodada_atual++;
	}

    return 0;
}
