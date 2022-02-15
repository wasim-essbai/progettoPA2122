#ifndef UTILS_H
#define UTILS_H


#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include "../utente/Studente.h"
#include "../utente/tutor.h"
#include "../lezione/Lezione.h"
#include "../lezione/LezioneSingola.h"
#include "../lezione/LezioneCollettiva.h"
#include "../lezione/RicevimentoAperto.h"
#include "../comparable/comparable.h"

using namespace std;

template <typename T>
void sort_list(vector<T>& lista_to_order){
	bubbleSortRic(lista_to_order, lista_to_order.size());
}

template<typename T>
void bubbleSortRic(vector<T>& lista, int n){
   if (n <= 1)
      return;
   for (int i=0; i < n-1; i++){
      if (*lista.at(i) > *lista.at(i+1)){
	   	   swap(lista.at(i), lista.at(i+1));
      }
   }
   bubbleSortRic(lista, n-1);
}

void stampa_lezione(lezione_ref lezione);

void stampa_ricevimento(ricevimento_aperto_ref ricevimento_aperto);

void stampa_errore();

void stampa_errore_data_passata();

void stampa_errore_ora_passata();

#endif
