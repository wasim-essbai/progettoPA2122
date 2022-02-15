#ifndef LEZIONE_SINGOLA_H
#define LEZIONE_SINGOLA_H

#include <string>
#include <vector>
#include <memory>
#include <list>
#include <iostream>
#include <assert.h>
#include <cstdlib>
#include <ctime>

#include "../comparable/comparable.h"
#include "../utente/Studente.h"
#include "Lezione.h"

using namespace std;

class LezioneSingola : public Lezione, public Comparable
{
private:
	studente_ref studente;

public:
	LezioneSingola(studente_ref studente, time_t data, string luogo, time_t ora_inizio, time_t ora_fine, tutor_ref tutor);

	LezioneSingola(studente_ref studente, lezione_ref lezione);

	studente_ref get_studente();

	void set_studente(studente_ref studente);

	string get_string();

	int compare_to(comparable_ref c);

	virtual ~LezioneSingola();
};

typedef shared_ptr<LezioneSingola> lezione_singola_ref;
#endif
