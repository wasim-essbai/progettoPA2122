#ifndef RICEVIMENTO_APERTO_H
#define RICEVIMENTO_APERTO_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include <cstdlib>
#include <ctime>

#include "../comparable/comparable.h"
#include "../utente/Tutor.h"
#include "Lezione.h"

using namespace std;

class RicevimentoAperto : private Lezione, public Comparable
{
private:
	vector<tutor_ref> lista_tutor;

public:
	static const int  DURATA;

	int get_codice();

	RicevimentoAperto(time_t data, string luogo);

	void aggiungi_tutor(tutor_ref const tutor);

	void rimuovi_tutor(string const codice_tutor);

	vector<tutor_ref> get_lista_tutor();

	void set_lista_tutor(vector<tutor_ref> const lista_tutor);

	time_t get_data();

	void set_data(time_t const data);

	string get_luogo();

	void set_luogo(int const luogo);

	int compare_to(comparable_ref c);

	bool operator > (RicevimentoAperto other)
	{
		return Lezione::get_data() > other.get_data();
	}

	string get_string();

};

typedef shared_ptr<RicevimentoAperto> ricevimento_aperto_ref;
#endif
