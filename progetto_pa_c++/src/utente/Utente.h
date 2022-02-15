#ifndef UTENTE_H
#define UTENTE_H

#include <string>
#include <vector>
#include <memory>
#include <list>
#include <iostream>
#include <assert.h>
#include <cstdlib>
#include <ctime>

using namespace std;

const string STUDENTE_PREFIX = "S";

class Utente
{
private:
	static int  numUtenti;

	int codice_utente;

	string nome;

	string cognome;

protected:
	virtual int get_codice();

public:
	Utente(string nome, string cognome);

	virtual string get_nome();

	virtual string get_cognome();

	virtual void set_nome(string const nome);

	virtual void set_cognome(string cognome);

	virtual string get_string();

	virtual ~Utente();

};

typedef shared_ptr<Utente> utente_ref;
#endif
