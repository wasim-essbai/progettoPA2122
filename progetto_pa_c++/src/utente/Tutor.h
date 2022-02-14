#ifndef TUTOR_H
#define TUTOR_H

#include <string>
#include <vector>
#include <memory>
#include <list>
#include <iostream>
#include <assert.h>
#include <cstdlib>
#include <ctime>

#include "Utente.h"

using namespace std;

const string TUTOR_PREFIX = "T";

class Tutor : public Utente
{
private:
	static int num_tutor;

	string codice_tutor;

	int ore_svolte;


public:
	Tutor(string nome, string cognome);
	string get_codice_tutor();

	int get_ore_svolte();

	void incrementa_ore_svolte(int const incremento_ore);

	void decrementa_ore_svolte(int const decremento_ore);

	string get_string();

	virtual ~Tutor();

};

typedef shared_ptr<Tutor> tutor_ref;
#endif
