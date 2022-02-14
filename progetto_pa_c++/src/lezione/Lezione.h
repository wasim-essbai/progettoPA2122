#ifndef LEZIONE_H
#define LEZIONE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include <cstdlib>
#include <ctime>
#include <memory>
#include "../utente/Tutor.h"

using namespace std;

class Lezione
{
private:
	static int  num_prenotazioni;

	time_t data;

	string luogo;

	time_t ora_inizio;

	time_t ora_fine;

	tutor_ref tutor;

protected:
	int codice;


public:

	Lezione(time_t data, string luogo, time_t ora_inizio=0, time_t ora_fine=0, tutor_ref tutor=nullptr);

	Lezione(const Lezione &lezione);

	virtual int get_codice();

	virtual time_t get_data();

	virtual void set_data(time_t const data);

	virtual string get_luogo();

	virtual void set_luogo(int const luogo);

	virtual tutor_ref get_tutor();

	virtual void set_tutor(tutor_ref const tutor);

	virtual time_t get_ora_inizio();

	virtual void set_ora_inizio(time_t const ora_inizio);

	virtual time_t get_ora_fine();

	virtual void set_ora_fine(time_t const ora_fine);

	virtual string get_string();

	virtual ~Lezione();
};

typedef shared_ptr<Lezione> lezione_ref;
#endif
