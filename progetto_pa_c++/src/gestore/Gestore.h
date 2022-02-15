/*
 * gestore.h
 *
 *  Created on: 11 feb 2022
 *      Author: Wasim
 */

#ifndef GESTORE_GESTORE_H_
#define GESTORE_GESTORE_H_

#include <vector>
#include <string>
#include <memory>
#include "../utente/Studente.h"
#include "../utente/Tutor.h"
#include "../lezione/Lezione.h"
#include "../lezione/LezioneSingola.h"
#include "../lezione/LezioneCollettiva.h"
#include "../lezione/RicevimentoAperto.h"

class Gestore{
private:
	void init();

	lezione_ref crea_lezione();

	vector<studente_ref> lista_studenti;

	vector<tutor_ref> lista_tutor;

	vector<lezione_singola_ref> lista_lezioni_singola;

	vector<lezione_collettiva_ref> lista_lezioni_collettiva;

	vector<ricevimento_aperto_ref> lista_ricevimento_aperto;

public:
	Gestore();

	void nuova_lezione();

	void nuova_lezione_singola();

	void nuova_lezione_collettiva();

	void nuovo_ricevimento_aperto();

	void stampa_lista_lezioni();

	void stampa_lista_lezioni_singola();

	void stampa_lista_lezioni_collettiva();

	void stampa_lista_ricevimento_aperto();

	void stampa_anagrafica_tutor();

	studente_ref registra_studente();

	~Gestore();
};


#endif /* GESTORE_GESTORE_H_ */
