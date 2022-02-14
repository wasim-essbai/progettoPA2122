#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
#include <memory>
#include "../utente/Studente.h"
#include "../utente/tutor.h"
#include "../lezione/Lezione.h"
#include "../lezione/RicevimentoAperto.h"


void stampa_lezione(lezione_ref lezione);

void stampa_ricevimento(ricevimento_aperto_ref ricevimento_aperto);

void stampa_errore();

void stampa_errore_data_passata();

#endif
