#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include <cstdlib>
#include <ctime>

#include "RicevimentoAperto.h"

using namespace std;

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
	time_t data = Lezione::get_data();
	unique_ptr<tm> local_data_time(localtime(&data));
	string data_string = "null ";
	if(local_data_time.get() != NULL){
		int year = 1900 + local_data_time->tm_year;
		int month = 1 + local_data_time->tm_mon;
		int day = local_data_time->tm_mday;
		data_string = to_string(year) + "-" + to_string(month) + "-" + to_string(day) + "\n";
	}

	string descrizione = "Codice lezione: " + to_string(Lezione::get_codice()) + " Data: " + data_string + "Luogo: " + Lezione::get_luogo() + "\n";
	descrizione += "I tutor presenti sono: \n";
	for(auto& el: lista_tutor){
		descrizione += el->get_string();
	}
	return descrizione;
}
