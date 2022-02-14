#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

#include "Lezione.h"

using namespace std;

int  Lezione::num_prenotazioni = 0;

Lezione::Lezione(time_t data, string luogo, time_t ora_inizio, time_t ora_fine, tutor_ref tutor){
	this->codice = num_prenotazioni++;
	this->data = data;
	this->luogo = luogo;
	this->ora_inizio = ora_inizio;
	this->ora_fine = ora_fine;
	this->tutor = tutor;
}

Lezione::Lezione(const Lezione &lezione){
	this->codice = lezione.codice;
	this->data = lezione.data;
	this->luogo = lezione.luogo;
    this->ora_inizio = lezione.ora_inizio;
	this->ora_fine = lezione.ora_fine;
	this->tutor = lezione.tutor;

}

int Lezione::get_codice()
{
	return codice;
}

time_t Lezione::get_data()
{
	return data;
}

void Lezione::set_data(time_t const data)
{
	time_t now = time(0);

	if(data < now){
		throw invalid_argument( "La data deve essere futura!" );
	}

	this->data = data;
}

string Lezione::get_luogo()
{
	return luogo;
}

void Lezione::set_luogo(int const luogo)
{
	this->luogo = luogo;
}

tutor_ref Lezione::get_tutor()
{
	return tutor;
}

void Lezione::set_tutor(tutor_ref tutor)
{
	this->tutor = tutor;
}

time_t Lezione::get_ora_inizio()
{
	return ora_inizio;
}

void Lezione::set_ora_inizio(time_t const ora_inizio)
{
	time_t now = time(0);

	if(ora_inizio < now){
		throw invalid_argument( "Ora inzio deve essere futura!" );
	}

	this->ora_inizio = ora_inizio;
}

time_t Lezione::get_ora_fine()
{
	return ora_fine;
}

void Lezione::set_ora_fine(time_t const ora_fine)
{

	if(ora_fine < this->ora_inizio){
		throw invalid_argument( "Ora fine deve essere maggiore dell'ora di inizio!" );
	}

	this->ora_fine = ora_fine;
}

string Lezione::get_string(){
	unique_ptr<tm> local_data_time(localtime(&data));
	string data_string = "null ";
	if(local_data_time.get() != NULL){
		int year = 1900 + local_data_time->tm_year;
		int month = 1 + local_data_time->tm_mon;
		int day = local_data_time->tm_mday;
		data_string = to_string(year) + "-" + to_string(month) + "-" + to_string(day) + "\n";
	}

	unique_ptr<tm> local_orario_inizio_time(localtime(&ora_inizio));
	string orario = "null ";
	if(local_orario_inizio_time.get() != NULL){
		int inizio_hour = local_orario_inizio_time->tm_hour;
		int inizio_minute = local_orario_inizio_time->tm_min;
		orario = " Ora inizio: " + to_string(inizio_hour) + ":" + to_string(inizio_minute);
	}
	unique_ptr<tm> local_orario_fine_time(localtime(&ora_fine));

	if(local_orario_fine_time.get() != NULL){
		int fine_hour = local_orario_fine_time->tm_hour;
		int fine_minute = local_orario_fine_time->tm_min;
		orario += " Ora fine: " + to_string(fine_hour) + ":" + to_string(fine_minute);
	}
	return "Codice lezione: " + to_string(codice) + " Data: " + data_string + "Luogo: " + luogo + orario;
}

Lezione::~Lezione(){}
