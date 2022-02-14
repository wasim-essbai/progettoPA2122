/*
 * utils.cpp
 *
 *      Author: Wasim
 */

#include <vector>
#include <string>
#include <memory>

#include "utils.h"


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
	cout << "La data deve essere futura! ";
	stampa_errore();
}
