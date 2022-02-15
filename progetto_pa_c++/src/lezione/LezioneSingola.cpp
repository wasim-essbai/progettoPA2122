#include <string>
#include <sstream>
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
	stringstream streamer;
	streamer << Lezione::get_string() <<endl;
	streamer << "Studente: "<<endl;
	streamer << studente->get_string();
	return streamer.str();
}

int LezioneSingola::compare_to(comparable_ref c){
	unique_ptr<LezioneSingola> other(dynamic_cast<LezioneSingola*>(c.get()));
	return this->get_data() - other->get_data();
}

LezioneSingola::~LezioneSingola(){

}
