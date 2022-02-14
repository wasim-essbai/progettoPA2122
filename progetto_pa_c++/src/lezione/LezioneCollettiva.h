#ifndef LEZIONE_COLLETTIVA_H
#define LEZIONE_COLLETTIVA_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include <cstdlib>
#include <ctime>
#include <memory>

#include "Lezione.h"
#include "../utente/Studente.h"

using namespace std;

class LezioneCollettiva : public Lezione
{
private:
	vector<studente_ref> lista_studenti;

public:
	LezioneCollettiva(time_t data, string luogo, time_t ora_inizio, time_t ora_fine, tutor_ref tutor);

	LezioneCollettiva(lezione_ref lezione);

	void aggiungi_studente(studente_ref const studente);

	void rimuovi_studente(string const codice_studente);

	vector<studente_ref> get_lista_studenti();

	void set_lista_studenti(vector<studente_ref> const lista_studenti);

	string get_string();

	virtual ~LezioneCollettiva();
};

typedef shared_ptr<LezioneCollettiva> lezione_collettiva_ref;
#endif
