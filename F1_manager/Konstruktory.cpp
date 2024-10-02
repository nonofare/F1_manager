#include <iostream>
#include <string>
#include "Zespol.h"
using namespace std;



Data::Data(int in_d, int in_m, int in_r) {
	dzien = in_d;
	miesiac = in_m;
	rok = in_r;
}

Osoba::Osoba(string in_godnosc, string in_plec, string in_pochodzenie, int in_pesel, int in_wiek, int in_wynagrodzenie,
	int in_dr, int in_mr, int in_rr, int in_dz, int in_mz, int in_rz) {
	godnosc = in_godnosc;
	plec = in_plec;
	pochodzenie = in_pochodzenie;
	pesel = in_pesel;
	wiek = in_wiek;
	wynagrodzenie = in_wynagrodzenie;

	zatrudniony_od.set_d(in_dr);
	zatrudniony_od.set_m(in_mr);
	zatrudniony_od.set_r(in_rr);
	zatrudniony_do.set_d(in_dz);
	zatrudniony_do.set_m(in_mz);
	zatrudniony_do.set_r(in_rz);
}



Zespol::Kierowca::Bolid::Uszkodzenia::Uszkodzenia(string in_nazwa, bool in_natychmiastowa_naprawa) {
	nazwa = in_nazwa;
	natychmiastowa_naprawa = in_natychmiastowa_naprawa;
}



Zespol::Kierowca::Bolid::Bolid(string in_model) {
	model = in_model;
}

Zespol::Kierowca::Bolid::Bolid(const Bolid& inny) {
	ilosc_uszkodzen = inny.ilosc_uszkodzen;
	model = inny.model;
	stan = inny.stan;

	uszkodzenia = new Uszkodzenia * [inny.ilosc_uszkodzen];
	for (size_t i = 0; i < inny.ilosc_uszkodzen; i++) {
		uszkodzenia[i] = new Uszkodzenia(*inny.uszkodzenia[i]);
	}
}

Zespol::Kierowca::Bolid& Zespol::Kierowca::Bolid::operator=(const Bolid& inny) {
	if (this != &inny) {
		if (uszkodzenia != nullptr) {
			for (size_t i = 0; i < ilosc_uszkodzen; ++i) {
				delete uszkodzenia[i];
			}
			delete[] uszkodzenia;
		}
		uszkodzenia = new Uszkodzenia * [inny.ilosc_uszkodzen];
		for (size_t i = 0; i < inny.ilosc_uszkodzen; i++) {
			uszkodzenia[i] = new Uszkodzenia(*inny.uszkodzenia[i]);
		}

		ilosc_uszkodzen = inny.ilosc_uszkodzen;
		model = inny.model;
		stan = inny.stan;
	}

	return *this;
}

Zespol::Kierowca::Bolid& Zespol::Kierowca::Bolid::operator=(const Bolid&& inny) noexcept {
	if (this != &inny) {
		if (uszkodzenia != nullptr) {
			for (size_t i = 0; i < ilosc_uszkodzen; ++i) {
				delete uszkodzenia[i];
			}
			delete[] uszkodzenia;
			uszkodzenia = nullptr;
		}

		uszkodzenia = inny.uszkodzenia;
		ilosc_uszkodzen = inny.ilosc_uszkodzen;
		model = inny.model;
		stan = inny.stan;

		inny.uszkodzenia = nullptr;
		inny.ilosc_uszkodzen = 0;
		inny.model = "n/a";
		inny.stan = 10;
	}

	return *this;
}

Zespol::Kierowca::Bolid::~Bolid() {
	for (size_t i = 0; i < ilosc_uszkodzen; i++) {
		delete uszkodzenia[i];
	}
	delete[] uszkodzenia;
}



Zespol::Kierowca::Kierowca(string in_godnosc, string in_plec, string in_pochodzenie, int in_pesel, int in_wiek, int in_wynagrodzenie,
	int in_dr, int in_mr, int in_rr, int in_dz, int in_mz, int in_rz, string in_model)
	: Osoba(in_godnosc, in_plec, in_pochodzenie, in_pesel, in_wiek, in_wynagrodzenie, in_dr, in_mr, in_rr, in_dz, in_mz, in_rz) {
	bolid.model = in_model;
}

Zespol::Kierowca::Kierowca(const Kierowca& inny) : Osoba(inny), bolid(inny.bolid) {
	ilosc_pozycji = inny.ilosc_pozycji;

	pozycje = new size_t[inny.ilosc_pozycji];
	for (size_t i = 0; i < inny.ilosc_pozycji; i++) {
		pozycje[i] = inny.pozycje[i];
	}
}

Zespol::Kierowca& Zespol::Kierowca::operator=(const Kierowca& inny) {
	if (this != &inny) {
		if (pozycje != nullptr) {
			delete pozycje;
		}
		pozycje = new size_t[inny.ilosc_pozycji];
		for (size_t i = 0; i < inny.ilosc_pozycji; i++) {
			pozycje[i] = inny.pozycje[i];
		}

		Osoba::operator=(inny);
		bolid = inny.bolid;
		ilosc_pozycji = inny.ilosc_pozycji;
	}

	return *this;
}

Zespol::Kierowca& Zespol::Kierowca::operator=(const Kierowca&& inny) noexcept {
	if (this != &inny) {
		if (pozycje != nullptr) {
			delete pozycje;
			pozycje = nullptr;
		}

		Osoba::operator=(move(inny));
		bolid = move(inny.bolid);
		pozycje = inny.pozycje;
		ilosc_pozycji = inny.ilosc_pozycji;


		inny.pozycje = nullptr;
		inny.ilosc_pozycji = 0;
	}

	return *this;
}

Zespol::Kierowca::~Kierowca() {
	delete[] pozycje;
}



Zespol::Mechanik::Mechanik(string in_godnosc, string in_plec, string in_pochodzenie, int in_pesel, int in_wiek, int in_wynagrodzenie,
	int in_dr, int in_mr, int in_rr, int in_dz, int in_mz, int in_rz, string in_specjalizacja)
	: Osoba(in_godnosc, in_plec, in_pochodzenie, in_pesel, in_wiek, in_wynagrodzenie, in_dr, in_mr, in_rr, in_dz, in_mz, in_rz) {
	specjalizacja = in_specjalizacja;
}



Zespol::Inzynier::Inzynier(string in_godnosc, string in_plec, string in_pochodzenie, int in_pesel, int in_wiek, int in_wynagrodzenie,
	int in_dr, int in_mr, int in_rr, int in_dz, int in_mz, int in_rz, string in_stanowisko)
	: Osoba(in_godnosc, in_plec, in_pochodzenie, in_pesel, in_wiek, in_wynagrodzenie, in_dr, in_mr, in_rr, in_dz, in_mz, in_rz) {
	stanowisko = in_stanowisko;
}



Zespol::Wyscig::Pogoda::Pogoda(string in_opis, int in_szansa_opadow, int in_predkosc_wiatru) {
	opis = in_opis;
	szansa_opadow = in_szansa_opadow;
	predkosc_wiatru = in_predkosc_wiatru;
}



Zespol::Wyscig::Tor::Tor(string in_miasto, size_t in_dlugosc) {
	miasto = in_miasto;
	dlugosc = in_dlugosc;
}



Zespol::Wyscig::Wyscig(int in_d, int in_m, int in_r,
	string in_pogoda_opis, int in_szansa_opadow, int in_predkosc_wiatru,
	string in_miasto, size_t in_dlugosc_toru) {
	data.set_d(in_d);
	data.set_m(in_m);
	data.set_r(in_r);

	pogoda.opis = in_pogoda_opis;
	pogoda.szansa_opadow = in_szansa_opadow;
	pogoda.predkosc_wiatru = in_predkosc_wiatru;

	tor.miasto = in_miasto;
	tor.dlugosc = in_dlugosc_toru;
}



Zespol* Zespol::get_Zespol() {
	if (!zespol) {
		zespol = new Zespol();
	}
	return zespol;
}

Zespol::~Zespol() {
	for (size_t i = 0; i < ilosc_kierowcow; i++) {
		delete kierowcy[i];
	}
	delete[] kierowcy;

	for (size_t i = 0; i < ilosc_mechanikow; i++) {
		delete mechanicy[i];
	}
	delete[] mechanicy;

	for (size_t i = 0; i < ilosc_inzynierow; i++) {
		delete inzynierowie[i];
	}
	delete[] inzynierowie;

	for (size_t i = 0; i < ilosc_nowych_wyscigow; i++) {
		delete nowe_wyscigi[i];
	}
	delete[] nowe_wyscigi;

	for (size_t i = 0; i < ilosc_starych_wyscigow; i++) {
		delete stare_wyscigi[i];
	}
	delete[] stare_wyscigi;
}