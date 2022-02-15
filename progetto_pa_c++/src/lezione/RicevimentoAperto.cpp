#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include <cstdlib>
#include <ctime>

#include "RicevimentoAperto.h"

using namespace std;

const int  RicevimentoAperto::DURATA = 4;

RicevimentoAperto::RicevimentoAperto(time_t data, string luogo)
:Lezione(data, luogo){

}

int RicevimentoAperto::get_codice()
{
	return Lezione::get_codice();
}

void RicevimentoAperto::aggiungi_tutor(tutor_ref const tutor)
{
	lista_tutor.push_back(tutor);
}

void RicevimentoAperto::rimuovi_tutor(string const codice_tutor)
{
	for (auto iterator = lista_tutor.begin(); iterator != lista_tutor.end(); ++iterator) {
		if((*iterator)->get_codice_tutor() == codice_tutor){
			lista_tutor.erase(iterator);
			break;
		}
	}
}

vector<tutor_ref> RicevimentoAperto::get_lista_tutor()
{
	return lista_tutor;
}

void RicevimentoAperto::set_lista_tutor(vector<tutor_ref> const lista_tutor)
{
	this->lista_tutor = lista_tutor;
}

time_t RicevimentoAperto::get_data()
{
	return Lezione::get_data();
}

void RicevimentoAperto::set_data(time_t const data)
{
	Lezione::set_data(data);
}

string RicevimentoAperto::get_luogo()
{
	return Lezione::get_luogo();
}

void RicevimentoAperto::set_luogo(int const luogo)
{
	Lezione::set_luogo(luogo);
}

string RicevimentoAperto::get_string(){
	stringstream streamer;
	streamer << "Codice lezione: " << Lezione::get_codice();

	time_t data = Lezione::get_data();
	tm* local_data_time = localtime(&data);
	streamer << " Data: ";
	if(local_data_time != NULL){
		int year = 1900 + local_data_time->tm_year;
		int month = 1 + local_data_time->tm_mon;
		int day = local_data_time->tm_mday;
		streamer << year << "-" << month << "-" << day << endl;
	} else {
		streamer << "null ";
	}

	streamer << "Luogo: " << Lezione::get_luogo() << endl;
	streamer << "I tutor presenti sono: " << endl;
	for(auto& el: lista_tutor){
		streamer << el->get_string() << endl;
	}
	return streamer.str();
}

int RicevimentoAperto::compare_to(comparable_ref c){
	unique_ptr<RicevimentoAperto> other(dynamic_cast<RicevimentoAperto*>(c.get()));
	return Lezione::get_data() - other->get_data();
}
