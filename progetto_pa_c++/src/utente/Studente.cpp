#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include <cstdlib>
#include <ctime>

#include "Studente.h"

using namespace std;

unsigned int  Studente::num_studenti = 0;

Studente::Studente(string nome, string cognome)
:Utente(nome, cognome){
	codice_studente = STUDENTE_PREFIX + to_string(Utente::get_codice());

}
string Studente::get_codice_studente()
{
	return codice_studente;
}

string Studente::get_string(){
	return "Codice studente: " + codice_studente + " " + Utente::get_string();
}

Studente::~Studente(){}
