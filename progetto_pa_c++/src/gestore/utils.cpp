/*
 * utils.cpp
 *
 *      Author: Wasim
 */

#include <vector>
#include <string>
#include <list>
#include <iostream>
#include <memory>

#include "utils.h"

using namespace std;


void stampa_lezione(lezione_ref lezione){
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
	cout << "Dettaglio lezione: " << endl;
	cout << lezione->get_string() << endl;
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
}

void stampa_ricevimento(ricevimento_aperto_ref ricevimento_aperto){
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
	cout << "Dettaglio ricevimento: " << endl;
	cout << ricevimento_aperto->get_string() << endl;
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
}

void stampa_errore(){
	cout << "Scelta non valida! " << endl;
	cout << "Reset operazione.. " << endl;
}

void stampa_errore_data_passata(){
	cout << "La data deve essere futura!" << endl;
	stampa_errore();
}

void void stampa_errore_ora_passata(){
	cout << "L'orario di fine non può essere antecedente a quello di inizio!" << endl;
	stampa_errore();
}
