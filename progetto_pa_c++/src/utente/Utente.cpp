#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include <cstdlib>
#include <ctime>

#include "Utente.h"

using namespace std;

int  Utente::numUtenti = 0;

Utente::Utente(string nome, string cognome){
	this->codice_utente = numUtenti++;
	this->nome = nome;
	this->cognome = cognome;
}

int Utente::get_codice()
{
	return codice_utente;
}

string Utente::get_nome()
{
	return nome;
}

string Utente::get_cognome()
{
	return cognome;
}

void Utente::set_nome(string const nome)
{
	this->nome = nome;
}

void Utente::set_cognome(string const cognome)
{
	this->cognome = cognome;
}

string Utente::get_string(){
	return "Nome: " + nome + " Cognome: " + cognome;
}

Utente::~Utente(){}
