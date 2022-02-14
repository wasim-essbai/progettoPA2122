//============================================================================
// Name        : progetto_pa_c++.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <vector>
#include <memory>
#include "gestore/Gestore.h"
#include "utente/Studente.h"
#include "utente/Tutor.h"


using namespace std;

int main() {
	unique_ptr<Gestore> gestore(new Gestore);
	string line;
	int scelta = -1;
	cout << "Benvenuto nel sistema di prenotazione lezioni!" << endl;
	cout << "Per selezionare l'operazione da svolgere digita il corrispondente numero nel menu." << endl;
	cout << "Digita -1 per terminare il programma." << endl;
	while(true){
		cout << "Seleziona l'operazione che vuoi svolgere dal menu:" << endl;
		cout << "0 - Stampa la lista di tutte le lezioni" << endl;
		cout << "1 - Stampa la lista delle lezioni singole" << endl;
		cout << "2 - Stampa la lista delle lezioni collettive" << endl;
		cout << "3 - Stampa la lista dei ricevimenti aperti" << endl;
		cout << "4 - Inserisci una nuova lezione" << endl;
		getline(cin, line);
		scelta = stoi(line);
		if(scelta == -1){
			break;
		}
		switch(scelta){
		case 0:
			gestore->stampa_lista_lezioni();
			break;
		case 1:
			gestore->stampa_lista_lezioni_singola();
			break;
		case 2:
			gestore->stampa_lista_lezioni_collettiva();
			break;
		case 3:
			gestore->stampa_lista_ricevimento_aperto();
			break;
		case 4:
			gestore->nuova_lezione();
			break;
		default:
			cout << "Scelta non valida!" << endl;
		}
	}

	cout <<"Grazie per aver usato il nostro sistema di prenotazioni! " << endl;
	cout<<"Arrivederci :)";
	return 0;
}