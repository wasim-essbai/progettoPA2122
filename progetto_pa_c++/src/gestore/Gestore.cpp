/*
 * gestore.cpp
 *
 *      Author: Wasim
 */


#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include <iostream>
#include "../utente/Studente.h"
#include "../utente/tutor.h"
#include "../lezione/LezioneSingola.h"
#include "../lezione/Lezione.h"
#include "../lezione/LezioneSingola.h"

#include "utils.h"
#include "Gestore.h"

using namespace std;

Gestore::Gestore(){
	init();
}

void Gestore::init(){
	//init studenti
	lista_studenti.push_back(make_shared<Studente>("Mario", "Rossi"));
	lista_studenti.push_back(make_shared<Studente>("Giuseppe", "Verdi"));
	lista_studenti.push_back(make_shared<Studente>("Pinco", "Pallino"));

	//init tutor
	tutor_ref t1(new Tutor("Pino", "Pasticcino"));
	lista_tutor.push_back(t1);
	lista_tutor.push_back(make_shared<Tutor>("Pluto", "Plutone"));
	lista_tutor.push_back(make_shared<Tutor>("Pippo", "Plutone"));

	//init lezioni
	lista_lezioni_singola.push_back(make_shared<LezioneSingola>(lista_studenti.at(2), time(0)+200000, "test2", time(0), time(0), lista_tutor.at(1)));
	lista_lezioni_singola.push_back(make_shared<LezioneSingola>(lista_studenti.at(0), time(0)+100000, "test", time(0), time(0), lista_tutor.at(0)));
	lista_lezioni_singola.push_back(make_shared<LezioneSingola>(lista_studenti.at(1), time(0), "test1", time(0), time(0), lista_tutor.at(0)));

}

void Gestore::nuova_lezione(){
	cout << "Sei nella sezione per inserire una nuova lezione! " << endl;
	cout << "Inserisci in qualsiasi momento il carattere '!' per annullare." << endl;
	cout << "Premi invio per procedere.." << endl;
	cin.ignore();
	string line;
	int scelta = -1;
	while(scelta == -1){
		cout << "Che tipo di lezione vuoi creare?" << endl;
		cout << "0 - Singola" << endl;
		cout << "1 - Collettiva" << endl;
		cout << "2 - Ricevimento aperto" << endl;
		getline(cin, line);
		scelta = stoi(line);
		//scelta = 2; //Test
		switch(scelta){
		case 0:
			nuova_lezione_singola();
			break;
		case 1:
			nuova_lezione_collettiva();
			break;
		case 2:
			nuovo_ricevimento_aperto();
			break;
		case 33:
			return;
		default:
			cout << "Scelta non valida." << endl;
			scelta = -1;
			break;
		}
	}

}

void Gestore::nuova_lezione_singola(){
	int scelta = -2;
	int index = 0;
	string line;
	cout << "Inserimento di una nuova lezione singola: " << endl;

	//Scelta studente
	cout << "Seleziona lo studente dalla lista oppure insersci '-1' per crearne uno nuovo: " << endl;
	for(auto& el: lista_studenti){
		cout << index << " - " << el->get_string() << endl;
		index++;
	}
	getline(cin, line);
	if (line == "!") {
		return;
	}
	scelta = stoi(line);
	//scelta = 0; //Test
	if(scelta == -2){
		return;
	}
	studente_ref studente_scelto;
	if(scelta == -1){
		studente_scelto = move(registra_studente());
	}
	if (scelta < index && scelta >= 0){
		studente_scelto = lista_studenti.at(scelta);
	} else {
		stampa_errore();
		return;
	}
	lezione_ref lezione = crea_lezione();
	if(lezione == nullptr){
		return;
	}
	lezione_singola_ref lezione_singola = make_shared<LezioneSingola>(studente_scelto, lezione);
	lista_lezioni_singola.push_back(lezione_singola);
	stampa_lezione(lezione_singola);
}

void Gestore::nuova_lezione_collettiva(){
	cout << "Inserimento di una nuova lezione collettiva: " << endl;
	lezione_ref lezione = crea_lezione();
	if(lezione == nullptr){
		return;
	}
	lezione_collettiva_ref lezione_collettiva = make_shared<LezioneCollettiva>(lezione);

	int scelta = -2;
	int index = 0;
	string line;
	//Scelta studente
	cout << "Seleziona gli studenti dalla lista oppure insersci '-1' per crearne uno nuovo: " << endl;
	cout << "Inserisci uno alla volta il numero della scelta selezione e digita 'ok' per terminare" << endl;
	for(auto& el: lista_studenti){
		cout << index << " - " << el->get_string() << endl;
		index++;
	}
	vector<int> aggiunti;
	while(true){
		getline(cin, line);
		if (line == "!") {
			return;
		}
		if(line == "ok"){
			break;
		}
		scelta = stoi(line);
		//scelta = 0; //Test
		if(scelta == -2){
			return;
		}
		studente_ref studente_scelto;
		if(scelta == -1){
			studente_scelto = move(registra_studente());
		} else if (scelta < index && scelta >= 0){
			vector<int>::iterator it = find(aggiunti.begin(), aggiunti.end(), scelta);
			if (it != aggiunti.end()){
				cout << "Studente già aggiunto! " << endl;
				cout << "Inserisci un altro studente " << endl;
				continue;
			}
			studente_scelto = lista_studenti.at(scelta);
			aggiunti.push_back(scelta);
		} else {
			stampa_errore();
			return;
		}

		lezione_collettiva->aggiungi_studente(studente_scelto);
		cout << "Studente aggiunto! " << endl;
	}
	lista_lezioni_collettiva.push_back(lezione_collettiva);
}

void Gestore::nuovo_ricevimento_aperto(){
	cout << "Inserimento di una nuova lezione singola: " << endl;
	string line;
	//Inserimento data
	time_t now = time(0);
	tm* current_local_time = localtime(&now);
	int year;
	int month;
	int day;

	cout << "Inserisci anno: " << endl;
	getline(cin, line);
	if (line == "!") {
		return;
	}
	year = stoi(line);
	//year = 2022; //Test

	if (year < current_local_time->tm_year + 1900) {
		stampa_errore_data_passata();
	}
	bool stesso_anno = year == current_local_time->tm_year + 1900;

	cout << "Inserisci mese: " << endl;
	getline(cin, line);
	if (line == "!") {
		return;
	}

	month = stoi(line);
	//month = 2; //Test
	if (month < current_local_time->tm_mon + 1 && stesso_anno) {
		stampa_errore_data_passata();
		return;
	}
	bool stesso_mese = month == current_local_time->tm_mon + 1;

	cout << "Inserisci giorno: " << endl;
	getline(cin, line);
	if (line == "!") {
		return;
	}

	day = stoi(line);
	//day = 13;
	if (day <= current_local_time->tm_mday && stesso_anno && stesso_mese) {
		stampa_errore_data_passata();
		return;
	}

	time_t data;
	time(&data);
	tm* local_data_time = localtime(&data);

	local_data_time->tm_year = year - 1900;
	local_data_time->tm_mon = month - 1;
	local_data_time->tm_mday = day;
	local_data_time->tm_hour = 0;
	local_data_time->tm_min = 0;
	local_data_time->tm_sec = 0;
	data = mktime(local_data_time);

	//Inserimento luogo
	string luogo;

	cout << "Inserisci luogo: " << endl;
	getline(cin, luogo);
	//luogo = "bog";//Test
	if(luogo == "!"){
		return;
	}

	ricevimento_aperto_ref ricevimento_aperto = make_shared<RicevimentoAperto>(data, luogo);

	//Scelta tutor
	int index = 0;
	int scelta = -2;
	cout << "Seleziona i tutor dalla lista: " << endl;
	cout << "Inserisci uno alla volta il numero della scelta selezione e digita 'ok' per terminare" << endl;
	for(auto& el: lista_tutor){
		cout << index << " - " << el->get_string() << endl;
		index++;
	}

	vector<int> aggiunti;
	while(true){
		getline(cin, line);
		if (line == "!") {
			return;
		}
		if(line == "ok"){
			break;
		}
		scelta = stoi(line);
		if(scelta == -2){
			return;
		}
		tutor_ref tutor_scelto;

		if (scelta < index && scelta >= 0){
			vector<int>::iterator it = find(aggiunti.begin(), aggiunti.end(), scelta);
			if (it != aggiunti.end()){
				cout << "Tutor già aggiunto! " << endl;
				cout << "Inserisci un altro tutor " << endl;
				continue;
			}
			tutor_scelto = lista_tutor.at(scelta);
			aggiunti.push_back(scelta);
		} else {
			stampa_errore();
			return;
		}
		ricevimento_aperto->aggiungi_tutor(tutor_scelto);
		cout << "Tutor aggiunto! " << endl;
	}

	lista_ricevimento_aperto.push_back(ricevimento_aperto);
}

lezione_ref Gestore::crea_lezione() {
	int scelta = -2;
	int index = 0;
	string line;
	//Inserimento data
	time_t now = time(0);
	tm* current_local_time = localtime(&now);
	int year;
	int month;
	int day;

	cout << "Inserisci anno: " << endl;
	getline(cin, line);
	if (line == "!") {
		return nullptr;
	}
	year = stoi(line);
	//year = 2022; //Test

	if (year < current_local_time->tm_year + 1900) {
		stampa_errore_data_passata();
		return nullptr;
	}
	bool stesso_anno = year == current_local_time->tm_year + 1900;

	cout << "Inserisci mese: " << endl;
	getline(cin, line);
	if (line == "!") {
		return nullptr;
	}
	month = stoi(line);
	//month = 2; //Test
	if (month < current_local_time->tm_mon + 1 && stesso_anno) {
		stampa_errore_data_passata();
		return nullptr;
	}
	bool stesso_mese = month == current_local_time->tm_mon + 1;

	cout << "Inserisci giorno: " << endl;
	getline(cin, line);
	if (line == "!") {
		return nullptr;
	}
	day = stoi(line);
	//day = 13;
	if (day <= current_local_time->tm_mday && stesso_mese && stesso_anno) {
		stampa_errore_data_passata();
		return nullptr;
	}

	time_t data;
	time(&data);
	tm* local_data_time = localtime(&data);

	local_data_time->tm_year = year - 1900;
	local_data_time->tm_mon = month - 1;
	local_data_time->tm_mday = day;
	local_data_time->tm_hour = 0;
	local_data_time->tm_min = 0;
	local_data_time->tm_sec = 0;
	data = mktime(local_data_time);

	//Inserimento luogo
	string luogo;

	cout << "Inserisci luogo: " << endl;
	getline(cin, luogo);
	//luogo = "bog";//Test
	if(luogo == "!"){
		return nullptr;
	}

	//Inserimento orario inzio
	time_t ora_inizio;
	time(&ora_inizio);
	tm* local_ora_inizio_time = localtime(&ora_inizio);
	int inizio_hour;
	int inizio_minute;

	cout << "Inserisci ora inizio: " << endl;
	getline(cin, line);
	if (line == "!") {
		return nullptr;
	}
	inizio_hour = stoi(line);
	//inizio_hour = 11; //Test

	cout << "Inserisci minuto: " << endl;
	getline(cin, line);
	if (line == "!") {
		return nullptr;
	}
	inizio_minute = stoi(line);
	//inizio_minute = 0; //Test

	local_ora_inizio_time->tm_year = local_data_time->tm_year;
	local_ora_inizio_time->tm_mon = local_data_time->tm_mon;
	local_ora_inizio_time->tm_mday = local_data_time->tm_mday;
	local_ora_inizio_time->tm_hour = inizio_hour;
	local_ora_inizio_time->tm_min = inizio_minute;
	local_ora_inizio_time->tm_sec = 0;
	ora_inizio = mktime(local_ora_inizio_time);

	//Inserimento orario fine
	time_t ora_fine;
	time(&ora_fine);
	tm* local_ora_fine_time = localtime(&ora_fine);
	int fine_hour;
	int fine_minute;

	cout << "Inserisci ora fine: " << endl;
	getline(cin, line);
	if (line == "!") {
		return nullptr;
	}
	fine_hour = stoi(line);
	//fine_hour = 12; //Test
	if(fine_hour < inizio_hour){
		stampa_errore_ora_passata();
		return nullptr;
	}
	bool stessa_ora = fine_hour == inizio_hour;

	cout << "Inserisci minuto: " << endl;
	getline(cin, line);
	if (line == "!") {
		return nullptr;
	}
	fine_minute = stoi(line);
	//fine_minute = 0; //Test
	if (fine_minute <= inizio_minute && stessa_ora) {
		stampa_errore_ora_passata();
		return nullptr;
	}

	local_ora_fine_time->tm_year = local_data_time->tm_year;
	local_ora_fine_time->tm_mon = local_data_time->tm_mon;
	local_ora_fine_time->tm_mday = local_data_time->tm_mday;
	local_ora_fine_time->tm_hour = fine_hour;
	local_ora_fine_time->tm_min = fine_minute;
	local_ora_fine_time->tm_sec = 0;
	ora_fine = mktime(local_ora_fine_time);

	//Scelta tutor
	tutor_ref tutor_scelto;
	scelta = -2;
	index = 0;
	cout << "Selezione il tutor dalla lista: " << endl;
	for (auto &el : lista_tutor) {
		cout << index << " - " << el->get_string() << endl;
		index++;
	}

	getline(cin, line);
	if (line == "!") {
		return nullptr;
	}
	scelta = stoi(line);
	//scelta = 0; //Test
	if(scelta ==-2){
		return nullptr;
	}
	if (scelta < index && scelta >= 0) {
		tutor_scelto = lista_tutor.at(scelta);
	} else {
		stampa_errore();
		return nullptr;
	}

	return make_shared<Lezione>(data, luogo, ora_inizio, ora_fine, tutor_scelto);

}

studente_ref Gestore::registra_studente(){
	string nome, cognome;
	cout << "Sei nella sezione di registrazione di un nuovo studente: " << endl;
	cout << "Inserisci il nome dello studente: " << endl;
	getline(cin, nome);
	cout << "Inserisci il cognome dello studente: " << endl;
	getline(cin, cognome);
	studente_ref studente_creato = make_shared<Studente>(nome, cognome);
	lista_studenti.push_back(studente_creato);
	return studente_creato;
}

void Gestore::stampa_lista_lezioni(){
	stampa_lista_lezioni_singola();
	stampa_lista_lezioni_collettiva();
	stampa_lista_ricevimento_aperto();
}

void Gestore::stampa_lista_lezioni_singola(){
	cout << "Lezioni singole: " << endl;
	sort_list(lista_lezioni_singola);
	for(auto& el: lista_lezioni_singola){
		stampa_lezione(el);
	}
}

void Gestore::stampa_lista_lezioni_collettiva(){
	cout << "Lezioni collettive: " << endl;
	sort_list(lista_lezioni_collettiva);
	for(auto& el: lista_lezioni_collettiva){
		stampa_lezione(el);
	}
}

void Gestore::stampa_lista_ricevimento_aperto(){
	cout << "Ricevimenti aperti: " << endl;
	sort_list(lista_ricevimento_aperto);
	for(auto& el: lista_ricevimento_aperto){
		stampa_ricevimento(el);
	}
}

Gestore::~Gestore(){

}


