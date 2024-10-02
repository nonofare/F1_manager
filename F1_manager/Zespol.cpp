#include <iostream>
#include <string>
#include <random>
#include "Zespol.h"
using namespace std;



static random_device rd;
static default_random_engine dfe(rd());

const size_t ilosc_imion_s = 32;
const size_t ilosc_nazwisk_s = 32;
const size_t ilosc_krajow_s = 20;
const size_t ilosc_modeli_s = 20;
const size_t ilosc_stanowisk_inzynierow_s = 7;
const size_t ilosc_miast_s = 10;
const size_t ilosc_pogody_s = 5;
const size_t ilosc_uszkodzen_s = 10;
string imiona[ilosc_imion_s]{ "Sara", "Jack", "Darius", "Luke", "Max", "Simon",
							"Kamil", "Martin", "Patrick", "Peter", "Bartosz", "Adam",
							"Jacob", "John", "Andrew", "Matthew", "Christopher", "Karol",
							"Michael", "Don", "Michael", "Dominic", "Nathaniel", "Andrew",
							"Martin", "Matthew", "Alexander", "Thomas", "Daniel", "Evan",
							"Gabriel", "Charles" };
string nazwiska[ilosc_nazwisk_s]{ "Smith", "Johnson", "Williams", "Brown", "Jones",
							"Miller", "Davis", "Garcia", "Rodriguez", "Martinez",
							"Lopez", "Gonzalez", "Wilson", "Anderson", "Jackson",
							"Lee", "Perez", "Thompson", "Harris", "Sanchez", "Clark",
							"Ramirez", "Lewis", "Robinson", "Walker", "Allen", "King",
							"Wright", "Scott", "Torres", "Nguyen", "Hill" };
string kraje[ilosc_krajow_s]{ "Polska", "Niemcy", "Wlochy", "Francja", "Hiszpania", "Portugalia",
							"Brazylia", "Australia", "Kanada", "Wielka Brytania", "USA", "Holandia",
							"Ukraina", "Japonia", "Chiny", "Indie", "Meksyk", "Argentyna",
							"Egipt", "Grecja" };
string modele[ilosc_modeli_s]{ "SF90", "F2004", "RB16", "W12", "MCL36", "A522", "AMR23", "C42",
							"AR13", "FW44", "R34", "LH777", "MS2024", "VF21", "AP19", "RS25",
							"STR10", "SA2024", "MP4-36", "ZG33" };
string stanowiska_inzynierow[ilosc_stanowisk_inzynierow_s]{ "Inzynier areodynamiki", "Inzynier silnika",
							"Inzynier Elektroniki", "Iznynier rozwoju", "Inzynier symulacji",
							"Inzynier zawieszenia", "Inzynier paliwowy" };
string miasta[ilosc_miast_s]{ "Monako", "Melbourne", "Monza", "Szanghaj", "Spa-Francorchamps",
							"Montreal", "Suzuka", "Silverstone", "Budapeszt", "Austin" };
string pogoda[ilosc_pogody_s]{ "Slonecznie", "Pochmurnie", "Desczowo", "Mglisto", "Burzowo" };
string uszkodzenia[ilosc_uszkodzen_s]{ "Uszkodzenie skrzydla", "Uszkodzenie spojlera", "Uszkodzenie zawieszenia",
							"Uszkodzenie silnika", "Uszkodzenie podwozia", "Uszkodzenie ukladu hamulcowego",
							"Uszkodzenie skrzyni biegow", "Uszkodzenie ukladu elektrycznego", "Uszkodzenie poszycia",
							"Uszkodzenie poszycia" };



void Zespol::dodajKierowce(string godnosc, string plec, string pochodzenie, int pesel, int wiek, int wynagrodzenie,
	int dr, int mr, int rr, int dz, int mz, int rz, string model) {
	Kierowca** temp = new Kierowca * [ilosc_kierowcow + 1];

	if (ilosc_kierowcow == 0) {
		temp[ilosc_kierowcow] = new Kierowca(godnosc, plec, pochodzenie, pesel, wiek, wynagrodzenie, dr, mr, rr, dz, mz, rz, model);
	}
	else {
		for (size_t i = 0; i < ilosc_kierowcow; i++) {
			temp[i] = kierowcy[i];
		}
		temp[ilosc_kierowcow] = new Kierowca(godnosc, plec, pochodzenie, pesel, wiek, wynagrodzenie, dr, mr, rr, dz, mz, rz, model);
		delete[] kierowcy;
	}

	kierowcy = temp;
	ilosc_kierowcow++;
}

void Zespol::dodajMechanika(string godnosc, string plec, string pochodzenie, int pesel, int wiek, int wynagrodzenie,
	int dr, int mr, int rr, int dz, int mz, int rz, string specjalizacja) {
	Mechanik** temp = new Mechanik * [ilosc_mechanikow + 1];

	if (ilosc_mechanikow == 0) {
		temp[ilosc_mechanikow] = new Mechanik(godnosc, plec, pochodzenie, pesel, wiek, wynagrodzenie, dr, mr, rr, dz, mz, rz, specjalizacja);
	}
	else {
		for (size_t i = 0; i < ilosc_mechanikow; i++) {
			temp[i] = mechanicy[i];
		}
		temp[ilosc_mechanikow] = new Mechanik(godnosc, plec, pochodzenie, pesel, wiek, wynagrodzenie, dr, mr, rr, dz, mz, rz, specjalizacja);
		delete[] mechanicy;
	}

	mechanicy = temp;
	ilosc_mechanikow++;
}

void Zespol::dodajInzyniera(string godnosc, string plec, string pochodzenie, int pesel, int wiek, int wynagrodzenie,
	int dr, int mr, int rr, int dz, int mz, int rz, string stanowisko) {
	Inzynier** temp = new Inzynier * [ilosc_inzynierow + 1];

	if (ilosc_inzynierow == 0) {
		temp[ilosc_inzynierow] = new Inzynier(godnosc, plec, pochodzenie, pesel, wiek, wynagrodzenie, dr, mr, rr, dz, mz, rz, stanowisko);
	}
	else {
		for (size_t i = 0; i < ilosc_inzynierow; i++) {
			temp[i] = inzynierowie[i];
		}
		temp[ilosc_inzynierow] = new Inzynier(godnosc, plec, pochodzenie, pesel, wiek, wynagrodzenie, dr, mr, rr, dz, mz, rz, stanowisko);
		delete[] inzynierowie;
	}

	inzynierowie = temp;
	ilosc_inzynierow++;
}

void Zespol::dodajWyscig(int d, int m, int r, string pogoda_opis, int szansa_opadow, int predkosc_wiatru,
	string miasto, size_t dlugosc_toru) {
	Wyscig** temp = new Wyscig * [ilosc_nowych_wyscigow + 1];

	if (ilosc_nowych_wyscigow == 0) {
		temp[ilosc_nowych_wyscigow] = new Wyscig(d, m, r, pogoda_opis, szansa_opadow, predkosc_wiatru, miasto, dlugosc_toru);
	}
	else {
		for (size_t i = 0; i < ilosc_nowych_wyscigow; i++) {
			temp[i] = nowe_wyscigi[i];
		}
		temp[ilosc_nowych_wyscigow] = new Wyscig(d, m, r, pogoda_opis, szansa_opadow, predkosc_wiatru, miasto, dlugosc_toru);
		delete[] nowe_wyscigi;
	}

	nowe_wyscigi = temp;
	ilosc_nowych_wyscigow++;
}

void Zespol::dodajStaryWyscig() {
	Wyscig** temp = new Wyscig * [ilosc_starych_wyscigow + 1];

	if (ilosc_starych_wyscigow == 0) {
		temp[ilosc_starych_wyscigow] = new Wyscig(*nowe_wyscigi[0]);
	}
	else {
		for (size_t i = 0; i < ilosc_starych_wyscigow; i++) {
			temp[i] = stare_wyscigi[i];
		}
		temp[ilosc_starych_wyscigow] = new Wyscig(*nowe_wyscigi[0]);
		delete[] stare_wyscigi;
	}

	stare_wyscigi = temp;
	ilosc_starych_wyscigow++;

	usunWyscig(0);
}



void Zespol::stworzKierowce() {
	string zdanie;
	size_t pozycja = 0;
	string godnosc, plec, pochodzenie, model;
	int wiek, pesel, wynagrodzenie, dr, mr, rr, dz, mz, rz;

	cout << "Imie i Nazwisko; Wiek; Plec[m/k]; Kraj; Pesel; Wynagrodzenie; Rozpoczecie kontraktu[dd.mm.rr]; Zakonczenie kontraktu[dd.mm.rr]; Model bolidu" << endl;
	cin.ignore();
	getline(cin, zdanie);

	pozycja = zdanie.find(';');
	zdanie[0] = toupper(zdanie[0]);
	zdanie[zdanie.find(' ') + 1] = toupper(zdanie[zdanie.find(' ') + 1]);
	godnosc = zdanie.substr(0, pozycja);

	zdanie.erase(0, pozycja + 2);
	pozycja = zdanie.find(';');
	wiek = stoi(zdanie.substr(0, pozycja));

	zdanie.erase(0, pozycja + 2);
	pozycja = zdanie.find(';');
	if (zdanie.substr(0, pozycja) == "m" || zdanie.substr(0, pozycja) == "M") {
		plec = "Mezczyzna";
	}
	else if (zdanie.substr(0, pozycja) == "k" || zdanie.substr(0, pozycja) == "K") {
		plec = "Kobieta";
	}
	else {
		plec = "Inna";
	}

	zdanie.erase(0, pozycja + 2);
	pozycja = zdanie.find(';');
	zdanie[0] = toupper(zdanie[0]);
	pochodzenie = zdanie.substr(0, pozycja);

	zdanie.erase(0, pozycja + 2);
	pozycja = zdanie.find(';');
	pesel = stoi(zdanie.substr(0, pozycja));

	zdanie.erase(0, pozycja + 1);
	wynagrodzenie = zdanie.find(';');
	wynagrodzenie = stoi(zdanie.substr(0, pozycja));

	zdanie.erase(0, pozycja + 2);
	pozycja = zdanie.find('.');
	dr = stoi(zdanie.substr(0, pozycja));
	zdanie.erase(0, pozycja + 1);
	pozycja = zdanie.find('.');
	mr = stoi(zdanie.substr(0, pozycja));
	zdanie.erase(0, pozycja + 1);
	pozycja = zdanie.find(';');
	rr = stoi(zdanie.substr(0, pozycja));

	zdanie.erase(0, pozycja + 2);
	pozycja = zdanie.find('.');
	dz = stoi(zdanie.substr(0, pozycja));
	zdanie.erase(0, pozycja + 1);
	pozycja = zdanie.find('.');
	mz = stoi(zdanie.substr(0, pozycja));
	zdanie.erase(0, pozycja + 1);
	pozycja = zdanie.find(';');
	rz = stoi(zdanie.substr(0, pozycja));

	zdanie.erase(0, pozycja + 2);
	pozycja = zdanie.find(';');
	zdanie[0] = toupper(zdanie[0]);
	model = zdanie.substr(0, pozycja);

	dodajKierowce(godnosc, plec, pochodzenie, pesel, wiek, wynagrodzenie, dr, mr, rr, dz, mz, rz, model);
}

void Zespol::stworzMechanika() {
	string zdanie;
	size_t pozycja = 0;
	string godnosc, plec, pochodzenie, specjalizacja;
	int wiek, pesel, wynagrodzenie, dr, mr, rr, dz, mz, rz;

	cout << "Imie i Nazwisko; Wiek; Plec[m/k]; Kraj; Pesel; Wynagrodzenie; Rozpoczecie kontraktu[dd.mm.rr]; Zakonczenie kontraktu[dd.mm.rr]; Specjalizacja" << endl;
	cin.ignore();
	getline(cin, zdanie);

	pozycja = zdanie.find(';');
	zdanie[0] = toupper(zdanie[0]);
	zdanie[zdanie.find(' ') + 1] = toupper(zdanie[zdanie.find(' ') + 1]);
	godnosc = zdanie.substr(0, pozycja);

	zdanie.erase(0, pozycja + 2);
	pozycja = zdanie.find(';');
	wiek = stoi(zdanie.substr(0, pozycja));

	zdanie.erase(0, pozycja + 2);
	pozycja = zdanie.find(';');
	if (zdanie.substr(0, pozycja) == "m" || zdanie.substr(0, pozycja) == "M") {
		plec = "Mezczyzna";
	}
	else if (zdanie.substr(0, pozycja) == "k" || zdanie.substr(0, pozycja) == "K") {
		plec = "Kobieta";
	}
	else {
		plec = "Inna";
	}

	zdanie.erase(0, pozycja + 2);
	pozycja = zdanie.find(';');
	zdanie[0] = toupper(zdanie[0]);
	pochodzenie = zdanie.substr(0, pozycja);

	zdanie.erase(0, pozycja + 2);
	pozycja = zdanie.find(';');
	pesel = stoi(zdanie.substr(0, pozycja));

	zdanie.erase(0, pozycja + 1);
	wynagrodzenie = zdanie.find(';');
	wynagrodzenie = stoi(zdanie.substr(0, pozycja));

	zdanie.erase(0, pozycja + 2);
	pozycja = zdanie.find('.');
	dr = stoi(zdanie.substr(0, pozycja));
	zdanie.erase(0, pozycja + 1);
	pozycja = zdanie.find('.');
	mr = stoi(zdanie.substr(0, pozycja));
	zdanie.erase(0, pozycja + 1);
	pozycja = zdanie.find(';');
	rr = stoi(zdanie.substr(0, pozycja));

	zdanie.erase(0, pozycja + 2);
	pozycja = zdanie.find('.');
	dz = stoi(zdanie.substr(0, pozycja));
	zdanie.erase(0, pozycja + 1);
	pozycja = zdanie.find('.');
	mz = stoi(zdanie.substr(0, pozycja));
	zdanie.erase(0, pozycja + 1);
	pozycja = zdanie.find(';');
	rz = stoi(zdanie.substr(0, pozycja));

	zdanie.erase(0, pozycja + 2);
	pozycja = zdanie.find(';');
	zdanie[0] = toupper(zdanie[0]);
	specjalizacja = zdanie.substr(0, pozycja);

	dodajMechanika(godnosc, plec, pochodzenie, pesel, wiek, wynagrodzenie, dr, mr, rr, dz, mz, rz, specjalizacja);
}

void Zespol::stworzInzyniera() {
	string zdanie;
	size_t pozycja = 0;
	string godnosc, plec, pochodzenie, stanowisko;
	int wiek, pesel, wynagrodzenie, dr, mr, rr, dz, mz, rz;

	cout << "Imie i Nazwisko; Wiek; Plec[m/k]; Kraj; Pesel; Wynagrodzenie; Rozpoczecie kontraktu[dd.mm.rr]; Zakonczenie kontraktu[dd.mm.rr]; Stanowisko" << endl;
	cin.ignore();
	getline(cin, zdanie);

	pozycja = zdanie.find(';');
	zdanie[0] = toupper(zdanie[0]);
	zdanie[zdanie.find(' ') + 1] = toupper(zdanie[zdanie.find(' ') + 1]);
	godnosc = zdanie.substr(0, pozycja);

	zdanie.erase(0, pozycja + 2);
	pozycja = zdanie.find(';');
	wiek = stoi(zdanie.substr(0, pozycja));

	zdanie.erase(0, pozycja + 2);
	pozycja = zdanie.find(';');
	if (zdanie.substr(0, pozycja) == "m" || zdanie.substr(0, pozycja) == "M") {
		plec = "Mezczyzna";
	}
	else if (zdanie.substr(0, pozycja) == "k" || zdanie.substr(0, pozycja) == "K") {
		plec = "Kobieta";
	}
	else {
		plec = "Inna";
	}

	zdanie.erase(0, pozycja + 2);
	pozycja = zdanie.find(';');
	zdanie[0] = toupper(zdanie[0]);
	pochodzenie = zdanie.substr(0, pozycja);

	zdanie.erase(0, pozycja + 2);
	pozycja = zdanie.find(';');
	pesel = stoi(zdanie.substr(0, pozycja));

	zdanie.erase(0, pozycja + 1);
	wynagrodzenie = zdanie.find(';');
	wynagrodzenie = stoi(zdanie.substr(0, pozycja));

	zdanie.erase(0, pozycja + 2);
	pozycja = zdanie.find('.');
	dr = stoi(zdanie.substr(0, pozycja));
	zdanie.erase(0, pozycja + 1);
	pozycja = zdanie.find('.');
	mr = stoi(zdanie.substr(0, pozycja));
	zdanie.erase(0, pozycja + 1);
	pozycja = zdanie.find(';');
	rr = stoi(zdanie.substr(0, pozycja));

	zdanie.erase(0, pozycja + 2);
	pozycja = zdanie.find('.');
	dz = stoi(zdanie.substr(0, pozycja));
	zdanie.erase(0, pozycja + 1);
	pozycja = zdanie.find('.');
	mz = stoi(zdanie.substr(0, pozycja));
	zdanie.erase(0, pozycja + 1);
	pozycja = zdanie.find(';');
	rz = stoi(zdanie.substr(0, pozycja));

	zdanie.erase(0, pozycja + 2);
	pozycja = zdanie.find(';');
	zdanie[0] = toupper(zdanie[0]);
	stanowisko = zdanie.substr(0, pozycja);

	dodajInzyniera(godnosc, plec, pochodzenie, pesel, wiek, wynagrodzenie, dr, mr, rr, dz, mz, rz, stanowisko);
}

void Zespol::stworzWyscig() {
	string zdanie;
	size_t pozycja = 0;
	string miasto, pogoda_opis;
	int d, m, r, dlugosc_toru, szansa_opadow, predkosc_wiatru;

	cout << "Miasto; Dlugosc toru(km); Dzien odbycia [dd.mm.rr]" << endl;
	cin.ignore();
	getline(cin, zdanie);

	pozycja = zdanie.find(';');
	zdanie[0] = toupper(zdanie[0]);
	zdanie[zdanie.find(' ') + 1] = toupper(zdanie[zdanie.find(' ') + 1]);
	miasto = zdanie.substr(0, pozycja);

	zdanie.erase(0, pozycja + 2);
	pozycja = zdanie.find(';');
	dlugosc_toru = stoi(zdanie.substr(0, pozycja));

	zdanie.erase(0, pozycja + 2);
	pozycja = zdanie.find('.');
	d = stoi(zdanie.substr(0, pozycja));
	zdanie.erase(0, pozycja + 1);
	pozycja = zdanie.find('.');
	m = stoi(zdanie.substr(0, pozycja));
	zdanie.erase(0, pozycja + 1);
	pozycja = zdanie.find(';');
	r = stoi(zdanie.substr(0, pozycja));

	cout << "Prognozowana pogoda; Szansa opadow(0-100%); Predkosc wiatru(km/h)" << endl;
	getline(cin, zdanie);

	pozycja = zdanie.find(';');
	zdanie[0] = toupper(zdanie[0]);
	pogoda_opis = zdanie.substr(0, pozycja);

	zdanie.erase(0, pozycja + 2);
	pozycja = zdanie.find(';');
	szansa_opadow = stoi(zdanie.substr(0, pozycja));

	zdanie.erase(0, pozycja + 2);
	pozycja = zdanie.find(';');
	predkosc_wiatru = stoi(zdanie.substr(0, pozycja));

	dodajWyscig(d, m, r, pogoda_opis, szansa_opadow, predkosc_wiatru, miasto, dlugosc_toru);
}



void Zespol::usunKierowce(size_t index) {
	if (ilosc_kierowcow == 0) {
		cout << "Brak kierowcow w bazie danych" << endl;
	}
	else if (index < 0 || index >= ilosc_kierowcow) {
		cout << "Podany indeks jest nieprawidlowy" << endl;
	}
	else {
		Kierowca** temp = new Kierowca * [ilosc_kierowcow - 1];
		short int j{ -1 };

		for (size_t i = 0; i < ilosc_kierowcow; i++) {
			if (i != index) {
				j++;
				temp[j] = kierowcy[i];
			}
		}

		delete[] kierowcy;
		kierowcy = temp;
		ilosc_kierowcow--;
	}
}

void Zespol::usunMechanika(size_t index) {
	if (ilosc_mechanikow == 0) {
		cout << "Brak mechanikow w bazie danych" << endl;
	}
	else if (index < 0 || index >= ilosc_mechanikow) {
		cout << "Podany indeks jest nieprawidlowy" << endl;
	}
	else {
		Mechanik** temp = new Mechanik * [ilosc_mechanikow - 1];
		short int j{ -1 };

		for (size_t i = 0; i < ilosc_mechanikow; i++) {
			if (i != index) {
				j++;
				temp[j] = mechanicy[i];
			}
		}

		delete[] mechanicy;
		mechanicy = temp;
		ilosc_mechanikow--;
	}
}

void Zespol::usunInzyniera(size_t index) {
	if (ilosc_inzynierow == 0) {
		cout << "Brak inzynierow w bazie danych" << endl;
	}
	else if (index < 0 || index >= ilosc_inzynierow) {
		cout << "Podany indeks jest nieprawidlowy" << endl;
	}
	else {
		Inzynier** temp = new Inzynier * [ilosc_inzynierow - 1];
		short int j{ -1 };

		for (size_t i = 0; i < ilosc_inzynierow; i++) {
			if (i != index) {
				j++;
				temp[j] = inzynierowie[i];
			}
		}

		delete[] inzynierowie;
		inzynierowie = temp;
		ilosc_inzynierow--;
	}
}

void Zespol::usunWyscig(size_t index) {
	if (ilosc_nowych_wyscigow == 0) {
		cout << "Brak wyscigow w bazie danych" << endl;
	}
	else if (index < 0 || index >= ilosc_nowych_wyscigow) {
		cout << "Podany indeks jest nieprawidlowy" << endl;
	}
	else {
		Wyscig** temp = new Wyscig * [ilosc_nowych_wyscigow - 1];
		short int j{ -1 };

		for (size_t i = 0; i < ilosc_nowych_wyscigow; i++) {
			if (i != index) {
				j++;
				temp[j] = nowe_wyscigi[i];
			}
		}

		delete[] nowe_wyscigi;
		nowe_wyscigi = temp;
		ilosc_nowych_wyscigow--;
	}
}



void Zespol::wypiszKierowcow() const {
	for (size_t i = 0; i < ilosc_kierowcow; i++) {
		if (i > 1) {
			cout << "Kierowca rezerwowy: " << i << endl;
		}
		else {
			cout << "Kierowca: " << i << endl;
		}
		kierowcy[i]->wypisz();
	}
}

void Zespol::wypiszMechanikow() const {
	for (size_t i = 0; i < ilosc_mechanikow; i++) {
		cout << "Mechanik: " << i << endl;
		mechanicy[i]->wypisz();
	}
}

void Zespol::wypiszInzynierow() const {
	for (size_t i = 0; i < ilosc_inzynierow; i++) {
		cout << "Inzynier: " << i << endl;
		inzynierowie[i]->wypisz();
	}
}

void Zespol::wypiszWyscigi() const {
	for (size_t i = 0; i < ilosc_nowych_wyscigow; i++) {
		cout << "Wyscig: " << i + ilosc_starych_wyscigow << endl;
		cout << ">>>> Dane <<<<" << endl;
		cout << "Miasto: " << nowe_wyscigi[i]->tor.miasto << endl;
		cout << "Dlugosc toru: " << nowe_wyscigi[i]->tor.dlugosc << "km" << endl;
		cout << "Data: " << nowe_wyscigi[i]->data.get_d() << "." <<
			nowe_wyscigi[i]->data.get_m() << "." << nowe_wyscigi[i]->data.get_r() << endl;
		cout << ">>>> Pogoda <<<<" << endl;
		cout << "Opis: " << nowe_wyscigi[i]->pogoda.opis << endl;
		cout << "Szansa opadow: " << nowe_wyscigi[i]->pogoda.szansa_opadow << "%" << endl;
		cout << "Predkosc wiatru: " << nowe_wyscigi[i]->pogoda.predkosc_wiatru << "km/h" << endl;
		cout << "--------------------------------" << endl;
	}
}

void Zespol::wypiszStareWyscigi() const {
	for (size_t i = 0; i < ilosc_starych_wyscigow; i++) {
		cout << "Wyscig: " << i << endl;
		cout << ">>>> Dane <<<<" << endl;
		cout << "Miasto: " << stare_wyscigi[i]->tor.miasto << endl;
		cout << "Dlugosc toru: " << stare_wyscigi[i]->tor.dlugosc << "km" << endl;
		cout << "Data: " << stare_wyscigi[i]->data.get_d() << "." <<
			stare_wyscigi[i]->data.get_m() << "." << stare_wyscigi[i]->data.get_r() << endl;
		cout << ">>>> Pogoda <<<<" << endl;
		cout << "Opis: " << stare_wyscigi[i]->pogoda.opis << endl;
		cout << "Szansa opadow: " << stare_wyscigi[i]->pogoda.szansa_opadow << "%" << endl;
		cout << "Predkosc wiatru: " << stare_wyscigi[i]->pogoda.predkosc_wiatru << "km/h" << endl;
		cout << "--------------------------------" << endl;
	}
}



void Zespol::wylosujKierowce() {
	string imie = imiona[wylosuj(0, ilosc_imion_s - 1)];
	string nazwisko = nazwiska[wylosuj(0, ilosc_nazwisk_s - 1)];
	string godnosc = imie + " " + nazwisko;
	string plec;
	if (wylosuj(0, 1) == 1) {
		plec = "Kobieta";
	}
	else {
		plec = "Mezczyzna";
	}
	string pochodzenie = kraje[wylosuj(0, ilosc_krajow_s - 1)];
	int pesel = wylosuj(100000, 999999);
	int wiek = wylosuj(18, 80);
	int wynagrodzenie = wylosuj(1000, 32000);
	int dr = wylosuj(1, 31);
	int mr = wylosuj(1, 12);
	int rr = wylosuj(2016, 2024);
	int dz = wylosuj(1, 31);
	int mz = wylosuj(1, 12);
	int rz = wylosuj(2016, 2024);
	string model = modele[wylosuj(0, ilosc_modeli_s - 1)];

	dodajKierowce(godnosc, plec, pochodzenie, pesel, wiek, wynagrodzenie, dr, mr, rr, dz, mz, rz, model);
}

void Zespol::wylosujMechanika() {
	string imie = imiona[wylosuj(0, ilosc_imion_s - 1)];
	string nazwisko = nazwiska[wylosuj(0, ilosc_nazwisk_s - 1)];
	string godnosc = imie + " " + nazwisko;
	string plec;
	if (wylosuj(0, 1) == 1) {
		plec = "Kobieta";
	}
	else {
		plec = "Mezczyzna";
	}
	string pochodzenie = kraje[wylosuj(0, ilosc_krajow_s - 1)];
	int pesel = wylosuj(100000, 999999);
	int wiek = wylosuj(18, 80);
	int wynagrodzenie = wylosuj(1000, 32000);
	int dr = wylosuj(1, 31);
	int mr = wylosuj(1, 12);
	int rr = wylosuj(2016, 2024);
	int dz = wylosuj(1, 31);
	int mz = wylosuj(1, 12);
	int rz = wylosuj(2016, 2024);
	string specjalizacja = uszkodzenia[wylosuj(0, ilosc_uszkodzen_s - 1)];

	dodajMechanika(godnosc, plec, pochodzenie, pesel, wiek, wynagrodzenie, dr, mr, rr, dz, mz, rz, specjalizacja);
}

void Zespol::wylosujInzyniera() {
	string imie = imiona[wylosuj(0, ilosc_imion_s - 1)];
	string nazwisko = nazwiska[wylosuj(0, ilosc_nazwisk_s - 1)];
	string godnosc = imie + " " + nazwisko;
	string plec;
	if (wylosuj(0, 1) == 1) {
		plec = "Kobieta";
	}
	else {
		plec = "Mezczyzna";
	}
	string pochodzenie = kraje[wylosuj(0, ilosc_krajow_s - 1)];
	int pesel = wylosuj(100000, 999999);
	int wiek = wylosuj(18, 80);
	int wynagrodzenie = wylosuj(1000, 32000);
	int dr = wylosuj(1, 31);
	int mr = wylosuj(1, 12);
	int rr = wylosuj(2016, 2024);
	int dz = wylosuj(1, 31);
	int mz = wylosuj(1, 12);
	int rz = wylosuj(2016, 2024);
	string stanowisko = stanowiska_inzynierow[wylosuj(0, ilosc_stanowisk_inzynierow_s - 1)];

	dodajInzyniera(godnosc, plec, pochodzenie, pesel, wiek, wynagrodzenie, dr, mr, rr, dz, mz, rz, stanowisko);
}

void Zespol::wylosujWyscig() {
	int d = wylosuj(1, 31);
	int m = wylosuj(1, 12);
	int r = wylosuj(2016, 2024);
	string pogoda_opis = pogoda[wylosuj(0, ilosc_pogody_s - 1)];
	int szansa_opadow = wylosuj(0, 100);
	int predkosc_wiatru = wylosuj(0, 100);
	string miasto = miasta[wylosuj(0, ilosc_miast_s - 1)];
	int dlugosc_toru = wylosuj(0, 10);

	dodajWyscig(d, m, r, pogoda_opis, szansa_opadow, predkosc_wiatru, miasto, dlugosc_toru);
}



void Zespol::naprawBolidy() {
	size_t naprawione_uszkodzenia = 0;
	bool mozliwa_naprawa = false;

	for (size_t i = 0; i < ilosc_kierowcow; i++) {
		for (size_t j = 0; j < kierowcy[i]->bolid.ilosc_uszkodzen; j++) {
			for (size_t k = 0; k < ilosc_mechanikow; k++) {
				if (kierowcy[i]->bolid.uszkodzenia[j]->nazwa == mechanicy[k]->specjalizacja) {
					mozliwa_naprawa = true;
					mechanicy[k]->ilosc_napraw++;
				}
			}
			if (mozliwa_naprawa == true) {
				naprawione_uszkodzenia++;
			}
			else {
				cout << kierowcy[i]->bolid.uszkodzenia[j]->nazwa << " kierowcy: " << i << " nie ma odpowiedniego mechanika do naprawy" << endl;
			}
			mozliwa_naprawa = false;
		}
		if (naprawione_uszkodzenia == kierowcy[i]->bolid.ilosc_uszkodzen) {
			for (size_t j = 0; j < kierowcy[i]->bolid.ilosc_uszkodzen; j++) {
				delete kierowcy[i]->bolid.uszkodzenia[j];
			}
			delete[] kierowcy[i]->bolid.uszkodzenia;
			kierowcy[i]->bolid.uszkodzenia = nullptr;
			kierowcy[i]->bolid.ilosc_uszkodzen = 0;
			kierowcy[i]->bolid.stan = 10;
		}
		naprawione_uszkodzenia = 0;
	}
}

void Zespol::pojedzWyscig() {
	if (ilosc_nowych_wyscigow == 0) {
		cout << "Brak nadchodzacych wyscigow" << endl;
	}
	else if (ilosc_kierowcow < 2) {
		cout << "Potrzebujesz dwoch kierowcow do wyscigu" << endl;
	}
	else if (kierowcy[0]->bolid.stan == 0 || kierowcy[1]->bolid.stan == 0) {
		cout << "Musisz naprawic swoje bolidy" << endl;
	}
	else {
		int pozycja1 = wylosuj(1, 19);
		kierowcy[0]->dodajDoTabeli(pozycja1);
		string uszkodzenia_opis1 = uszkodzenia[wylosuj(1, ilosc_uszkodzen_s - 1)];
		bool naprawa1 = wylosuj(0, 1);
		kierowcy[0]->bolid.dodajUszkodzenia(uszkodzenia_opis1, naprawa1);
		int stan1 = wylosuj(0, 3);
		if (kierowcy[0]->bolid.stan > stan1) {
			kierowcy[0]->bolid.stan -= stan1;
		}
		else {
			kierowcy[0]->bolid.stan = 0;
		}

		int pozycja2 = wylosuj(1, 19);
		kierowcy[1]->dodajDoTabeli(pozycja2);
		string uszkodzenia_opis2 = uszkodzenia[wylosuj(1, ilosc_uszkodzen_s - 1)];
		bool naprawa2 = wylosuj(0, 1);
		kierowcy[1]->bolid.dodajUszkodzenia(uszkodzenia_opis2, naprawa2);
		int stan2 = wylosuj(0, 3);
		if (kierowcy[1]->bolid.stan > stan2) {
			kierowcy[1]->bolid.stan -= stan2;
		}
		else {
			kierowcy[1]->bolid.stan = 0;
		}

		cout << ">>>> Wyniki wyscigu: " << nowe_wyscigi[0]->tor.miasto << " <<<<" << endl;
		for (size_t i = 0; i < 20; i++) {
			if (i + 1 == pozycja1) {
				cout << "#" << i + 1 << " " << kierowcy[0]->get_godnosc() << " --> nasz kierowca" << endl;
			}
			else if (i + 1 == pozycja2) {
				cout << "#" << i + 1 << " " << kierowcy[1]->get_godnosc() << " --> nasz kierowca" << endl;
			}
			else {
				cout << "#" << i + 1 << " " << imiona[wylosuj(0, ilosc_imion_s - 1)] << " " << nazwiska[wylosuj(0, ilosc_nazwisk_s - 1)] << endl;
			}
		}

		dodajStaryWyscig();
	}
}

int Zespol::wylosuj(int min, int max) {
	uniform_int_distribution<int> rnd(min, max);
	return rnd(dfe);
}

void Zespol::zatrzymaj() {
	string stop;
	cout << "Nacisnij Enter by kontynuowac...";
	cin.ignore();
	getline(cin, stop);
}