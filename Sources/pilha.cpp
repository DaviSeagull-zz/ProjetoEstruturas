#include <sstream>
#include <bits/stdc++.h>

#include "pilha.h"

using namespace std;


Pilha::Pilha(int n) {
	topo = -1;
	itens = new int[n];
	maximo = n;
}

bool Pilha::empty() {
	return (topo == -1);
}

bool Pilha::full(){
	return topo == maximo - 1;
}

// Insere um elemento na pilha.
bool Pilha::push(int elem) {
	if (full())
		return false;
	topo++;
	itens[topo] = elem;
	return true;
}

// Remove um elemento da pilha.
int Pilha::pop() {
	if (empty())
		return 0;
	int elem = itens[topo];
	topo--;
	return elem;
}

// Imprime a quantidade de elementos na pilha
int Pilha::quantity() {
    return topo + 1 ;
}

int Pilha::verifyValue(int n) {
    for (int i = 0; i <= topo; i++) {
        if (n == itens[i]){
            return i;
        }
        else if (i == topo) {
            return -1;
        }
    }
}

// Verifica quantos valores existem acima do valor determinado
int Pilha::valuesAbove(int n){
    for (int i = 0; i <= topo; i++) {
        if (n == itens[i]){
            int cont = 0;
            for (int x = (i + 1); x <= topo; x++){
                cont ++;
            }
            return cont;
        }
    }
}

//conta quantos elementos repetidos existem
void Pilha::countFreq(int n)
{
    // Marca os elementos como não visitado
    vector<bool> visited(n, false);

    // conta a frequencia de cada valor
    // conta a frequencia de cada valor
    for (int i = 0; i < n; i++) {
        if (visited[i] == true)
            continue;
        int contador = 1;
        for (int j = i + 1; j < n; j++) {
            if (itens[i] == itens[j]) {
                visited[j] = true;
                contador++;
            }
        }
        cout << "O elemento - " <<  itens[i] << " aparece " << contador << " vezes" << endl;
    }
}


/**
 * Retorna uma string com o texto da pilha impressa: "[ n1 n2 n3 n4 ]" onde
 * o primeiro elemento e' o topo.
 * Se a pilha estiver vazia, retorna "[ ]".
 */
string Pilha::print() {

	stringstream ss;
	ss << "";
	if (empty()) {
		ss << "A pilha esta' vazia.";
	} else {
		ss << "[ ";
		for (int i = 0; i <= topo; i++) {
			ss << itens[i] << " ";
		}
		ss << "]";
	}

	return ss.str();

}




