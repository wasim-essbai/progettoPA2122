#include <string>
#include <sstream>
#include <vector>
#include <memory>
#include <list>
#include <iostream>
#include <assert.h>
#include <cstdlib>
#include <ctime>

#include "LezioneCollettiva.h"

using namespace std;

LezioneCollettiva::LezioneCollettiva(time_t data, string luogo, time_t ora_inizio=0, time_t ora_fine=0, tutor_ref tutor=nullptr)
:Lezione(data, luogo, ora_inizio, ora_fine, tutor){
}

LezioneCollettiva::LezioneCollettiva(lezione_ref lezione)
:Lezione(*lezione){
}

void LezioneCollettiva::aggiungi_studente(studente_ref const studente)
{
	lista_studenti.push_back(studente);
}

void LezioneCollettiva::rimuovi_studente(string const codice_studente)
{
	for (auto iterator = lista_studenti.begin(); iterator != lista_studenti.end(); ++iterator) {
		if((*iterator)->get_codice_studente() == codice_studente){
			lista_studenti.erase(iterator);
			break;
		}
	}
}

vector<studente_ref> LezioneCollettiva::get_lista_studenti()
{
	return move(lista_studenti);
}

void LezioneCollettiva::set_lista_studenti(vector<studente_ref> const lista_studenti){
	for(auto& e: lista_studenti){
		this->lista_studenti.push_back(e);
	}
}

string LezioneCollettiva::get_string(){
	stringstream streamer;
	streamer << Lezione::get_string() <<endl;
	streamer << "Gli studenti registrati sono: " << endl;
	for(auto& el: lista_studenti){
		streamer << el->get_string() << endl;
	}
	return streamer.str();
}

int LezioneCollettiva::compare_to(comparable_ref c){
	unique_ptr<LezioneCollettiva> other(dynamic_cast<LezioneCollettiva*>(c.get()));
	return this->get_data() - other->get_data();
}

LezioneCollettiva::~LezioneCollettiva(){}
