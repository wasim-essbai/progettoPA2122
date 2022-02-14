#include <string>
#include <vector>
#include <memory>
#include <list>
#include <iostream>
#include <assert.h>
#include <cstdlib>
#include <ctime>

#include "LezioneSingola.h"

using namespace std;

LezioneSingola::LezioneSingola(studente_ref studente, time_t data, string luogo, time_t ora_inizio=0, time_t ora_fine=0, tutor_ref tutor=nullptr)
:Lezione(data, luogo, ora_inizio, ora_fine, tutor) {
	this->studente = studente;
}

LezioneSingola::LezioneSingola(studente_ref studente, lezione_ref lezione)
:Lezione(*lezione){
	this->studente = studente;
}

studente_ref LezioneSingola::get_studente()
{
	return studente;
}

void LezioneSingola::set_studente(studente_ref studente)
{
	this->studente = studente;
}

string LezioneSingola::get_string(){

	return Lezione::get_string() + "\nStudente: \n" + studente->get_string();
}

LezioneSingola::~LezioneSingola(){

}
