#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include <cstdlib>
#include <ctime>

#include "Tutor.h"

using namespace std;

int Tutor::num_tutor = 0;

Tutor::Tutor(string nome, string cognome)
:Utente(nome, cognome), ore_svolte(0)
{
	codice_tutor = TUTOR_PREFIX + to_string(Utente::get_codice());
}

string Tutor::get_codice_tutor()
{
	return codice_tutor;
}

int Tutor::get_ore_svolte()
{
	return ore_svolte;
}

void Tutor::incrementa_ore_svolte(int const incremento_ore)
{
	ore_svolte +=  incremento_ore;
}

void Tutor::decrementa_ore_svolte(int const decremento_ore)
{
	if(decremento_ore >= ore_svolte){
		ore_svolte = 0;
	} else {
		ore_svolte -= decremento_ore;
	}
}

string Tutor::get_string(){
	return "Codice tutor: " + codice_tutor + " " + Utente::get_string();
}

Tutor::~Tutor(){

}

