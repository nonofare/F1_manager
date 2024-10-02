using namespace std;



class Data {
	mutable int dzien;
	mutable int miesiac;
	mutable int rok;

public:
	Data(int in_d = 1, int in_m = 1, int in_r = 1);

	int get_d() const { return dzien; }
	void set_d(int i) const { dzien = i; }

	int get_m() const { return miesiac; }
	void set_m(int i) const { miesiac = i; }

	int get_r() const { return rok; }
	void set_r(int i) const { rok = i; }
};

class Osoba {
	mutable string godnosc;
	mutable string plec;
	mutable string pochodzenie;
	mutable int pesel;
	mutable int wiek;
	mutable int wynagrodzenie;
	mutable Data zatrudniony_od;
	mutable Data zatrudniony_do;

public:
	Osoba(string in_godnosc = "n/a", string in_plec = "n/a", string in_pochodzenie = "n/a", int in_pesel = 0, int in_wiek = 0,
		int wynagrodzenie = 0, int in_dr = 1, int in_mr = 1, int in_rr = 2000, int in_dz = 1, int in_mz = 1, int in_rz = 2000);

	virtual string get_godnosc() const final { return godnosc; }
	virtual void set_godnosc(string i) const final { godnosc = i; }

	virtual string get_plec() const final { return plec; }
	virtual void set_plec(string i) const final { plec = i; }

	virtual string get_pochodzenie() const final { return pochodzenie; }
	virtual void set_pochodzenie(string i) const final { pochodzenie = i; }

	virtual int get_pesel() const final { return pesel; }
	virtual void set_pesel(int i) const final { pesel = i; }

	virtual int get_wiek() const final { return wiek; }
	virtual void set_wiek(int i) const final { wiek = i; }

	virtual int get_wynagrodzenie() const final { return wynagrodzenie; }
	virtual void set_wynagrodzenie(int i) const final { wynagrodzenie = i; }

	virtual int get_zatrudniony_od_d() const final { return zatrudniony_od.get_d(); }
	virtual void set_zatrudniony_od_d(int i) const final { zatrudniony_od.set_d(i); }
	virtual int get_zatrudniony_od_m() const final { return zatrudniony_od.get_m(); }
	virtual void set_zatrudniony_od_m(int i) const final { zatrudniony_od.set_m(i); }
	virtual int get_zatrudniony_od_r() const final { return zatrudniony_od.get_r(); }
	virtual void set_zatrudniony_od_r(int i) const final { zatrudniony_od.set_r(i); }

	virtual int get_zatrudniony_do_d() const final { return zatrudniony_do.get_d(); }
	virtual void set_zatrudniony_do_d(int i) const final { zatrudniony_do.set_d(i); }
	virtual int get_zatrudniony_do_m() const final { return zatrudniony_do.get_m(); }
	virtual void set_zatrudniony_do_m(int i) const final { zatrudniony_do.set_m(i); }
	virtual int get_zatrudniony_do_r() const final { return zatrudniony_do.get_r(); }
	virtual void set_zatrudniony_do_r(int i) const final { zatrudniony_do.set_r(i); }

	virtual void wypisz() = 0 {
		cout << ">>>> Dane <<<<" << endl;
		cout << "Godnosc: " << godnosc << endl;
		cout << "Plec: " << plec << endl;
		cout << "Wiek: " << wiek << endl;
		cout << "Pochodzenie: " << pochodzenie << endl;
		cout << "Pesel: " << pesel << endl;
		cout << "Wynagrodzenie: " << wynagrodzenie << "zl" << endl;
		cout << "Rozpoczecie kontraktu: " << get_zatrudniony_od_d() << "." <<
			get_zatrudniony_od_m() << "." << get_zatrudniony_od_r() << endl;
		cout << "Zakonczenie kontraktu: " << get_zatrudniony_do_d() << "." <<
			get_zatrudniony_do_m() << "." << get_zatrudniony_do_r() << endl;
	}

	virtual void obliczEfektywnosc() = 0 {}
};



class Zespol {

	class Kierowca : private Osoba {
		friend class Zespol;

		class Bolid {
			friend class Zespol;
			friend class Kierowca;

			class Uszkodzenia {
				friend class Zespol;
				friend class Kierowca;
				friend class Bolid;

				string nazwa;
				bool natychmiastowa_naprawa = false;



				Uszkodzenia(string in_nazwa = "n/a", bool natychmiastowa_naprawa = false);
			};

			mutable Uszkodzenia** uszkodzenia = nullptr;
			mutable size_t ilosc_uszkodzen = 0;
			mutable int stan = 10;
			mutable string model;



			Bolid(string in_model = "n/a");
			Bolid(const Bolid& inny);
			Bolid& operator=(const Bolid& inny);
			Bolid& operator=(const Bolid&& inny) noexcept;
			~Bolid();

			void dodajUszkodzenia(string nazwa, bool natychmiastowa_naprawa) {
				Uszkodzenia** temp = new Uszkodzenia * [ilosc_uszkodzen + 1];

				if (ilosc_uszkodzen == 0) {
					temp[ilosc_uszkodzen] = new Uszkodzenia(nazwa, natychmiastowa_naprawa);
				}
				else {
					for (size_t i = 0; i < ilosc_uszkodzen; i++) {
						temp[i] = uszkodzenia[i];
					}
					temp[ilosc_uszkodzen] = new Uszkodzenia(nazwa, natychmiastowa_naprawa);
					delete[] uszkodzenia;
				}

				uszkodzenia = temp;
				ilosc_uszkodzen++;
			}
		};

		mutable Bolid bolid;
		mutable size_t* pozycje = nullptr;
		mutable size_t ilosc_pozycji = 0;



		Kierowca(string in_godnosc = "n/a", string in_plec = "n/a", string in_pochodzenie = "n/a", int in_pesel = 0, int in_wiek = 0,
			int wynagrodzenie = 0, int in_dr = 1, int in_mr = 1, int in_rr = 2000, int in_dz = 1, int in_mz = 1, int in_rz = 2000,
			string in_model = "n/a");
		Kierowca(const Kierowca& inny);
		Kierowca& operator=(const Kierowca& inny);
		Kierowca& operator=(const Kierowca&& inny) noexcept;
		~Kierowca();

		void dodajDoTabeli(size_t pozycja) {
			size_t* temp = new size_t[ilosc_pozycji + 1];

			for (size_t i = 0; i < ilosc_pozycji; i++) {
				temp[i] = pozycje[i];
			}

			temp[ilosc_pozycji] = pozycja;
			delete[] pozycje;
			pozycje = temp;

			ilosc_pozycji++;
		}

	public:
		void wypisz() override {
			Osoba::wypisz();
			cout << endl << ">>>> Pozycje w wyscigach <<<<" << endl;
			for (size_t i = 0; i < ilosc_pozycji; i++) {
				cout << zespol->stare_wyscigi[i]->tor.miasto << ": #" << pozycje[i] << endl;
			}
			cout << endl << ">>>> Bolid <<<<" << endl;
			cout << "Model: " << bolid.model << endl;
			cout << "Stan: " << bolid.stan << "/10" << endl;
			cout << endl << "Uszkodzenia: " << endl;
			for (size_t i = 0; i < bolid.ilosc_uszkodzen; i++) {
				cout << i + 1 << ". " << bolid.uszkodzenia[i]->nazwa << endl;
				cout << "Wymagana natychmiastowa naprawa: ";
				if (bolid.uszkodzenia[i]->natychmiastowa_naprawa == true) {
					cout << "Tak" << endl;
				}
				else {
					cout << "Nie" << endl;
				}
			}
			cout << "--------------------------------" << endl;
		}

		void obliczEfektywnosc() override {
			int suma = 0, wynik_pozycji, wynik_wynagrodzen;

			if (Zespol::get_Zespol()->get_ilosc_odbytych_wyscigow() != 0) {
				for (size_t i = 0; i < ilosc_pozycji; i++) {
					suma += pozycje[i];
				}
				wynik_pozycji = suma / ilosc_pozycji;
				wynik_wynagrodzen = get_wynagrodzenie() / suma;
			}
			else {
				wynik_pozycji = 0;
				wynik_wynagrodzen = 0;
			}

			cout << "Kierowca: " << get_godnosc() << endl;
			cout << "Efektywnosc: " << wynik_pozycji << " (pozycja/wyscig)" << endl;
			cout << "Proponowana premia: " << wynik_wynagrodzen << "zl" << endl << endl;
		}
	};

	class Mechanik : private Osoba {
		friend class Zespol;

		string specjalizacja;
		size_t ilosc_napraw = 0;



		Mechanik(string in_godnosc = "n/a", string in_plec = "n/a", string in_pochodzenie = "n/a", int in_pesel = 0, int in_wiek = 0,
			int wynagrodzenie = 0, int in_dr = 1, int in_mr = 1, int in_rr = 2000, int in_dz = 1, int in_mz = 1, int in_rz = 2000,
			string in_specjalizacja = "n/a");

	public:
		void wypisz() override {
			Osoba::wypisz();
			cout << "Ilosc napraw: " << ilosc_napraw << endl;
			cout << "Specjalizacja: " << specjalizacja << endl;
			cout << "--------------------------------" << endl;
		}

		void obliczEfektywnosc() override {
			int wynik_napraw, wynik_wynagrodzen;

			if (Zespol::get_Zespol()->get_ilosc_odbytych_wyscigow() != 0) {
				wynik_napraw = ilosc_napraw / Zespol::get_Zespol()->get_ilosc_odbytych_wyscigow();
				wynik_wynagrodzen = (get_wynagrodzenie() / 10) * wynik_napraw;
			}
			else {
				wynik_napraw = 0;
				wynik_wynagrodzen = 0;
			}

			cout << "Mechanik: " << get_godnosc() << endl;
			cout << "Efektywnosc: " << wynik_napraw << " (naprawa/wyscig)" << endl;
			cout << "Proponowana premia: " << wynik_wynagrodzen << "zl" << endl << endl;
		}
	};

	class Inzynier : private Osoba {
		friend class Zespol;

		string stanowisko;



		Inzynier(string in_godnosc = "n/a", string in_plec = "n/a", string in_pochodzenie = "n/a", int in_pesel = 0, int in_wiek = 0,
			int wynagrodzenie = 0, int in_dr = 1, int in_mr = 1, int in_rr = 2000, int in_dz = 1, int in_mz = 1, int in_rz = 2000,
			string in_stanowisko = "n/a");

	public:
		void wypisz() override {
			Osoba::wypisz();
			cout << "Stanowisko: " << stanowisko << endl;
			cout << "--------------------------------" << endl;
		}

		void obliczEfektywnosc() override {
			cout << "Inzynier: " << get_godnosc() << endl;
			cout << "Efektywnosc: 1 (innowacja/wyscig)" << endl;
			cout << "Proponowana premia: 0zl" << endl << endl;
		}
	};

	class Wyscig {
		friend class Zespol;

		class Pogoda {
			friend class Zespol;
			friend class Wyscig;

			string opis;
			int szansa_opadow;
			int predkosc_wiatru;



			Pogoda(string in_opis = "n/a", int in_szansa_opadow = 0, int in_predkosc_wiatru = 0);
		};

		class Tor {
			friend class Zespol;
			friend class Wyscig;

			string miasto;
			size_t dlugosc;



			Tor(string in_miasto = "n/a", size_t in_dlugosc = 0);
		};

		Data data;
		Pogoda pogoda;
		Tor tor;



		Wyscig(int in_d = 1, int in_m = 1, int in_r = 2000,
			string in_pogoda_opis = "n/a", int in_szansa_opadow = 0, int in_predkosc_wiatru = 0,
			string in_miasto = "n/a", size_t in_dlugosc_toru = 0);
	};

	static Zespol* zespol;
	mutable string nazwa;
	mutable Kierowca** kierowcy = nullptr;
	mutable Mechanik** mechanicy = nullptr;
	mutable Inzynier** inzynierowie = nullptr;
	mutable Wyscig** nowe_wyscigi = nullptr;
	mutable Wyscig** stare_wyscigi = nullptr;
	mutable size_t ilosc_kierowcow = 0;
	mutable size_t ilosc_mechanikow = 0;
	mutable size_t ilosc_inzynierow = 0;
	mutable size_t ilosc_nowych_wyscigow = 0;
	mutable size_t ilosc_starych_wyscigow = 0;

public:
	static Zespol* get_Zespol();
	~Zespol();

	void set_nazwa(string i) const { nazwa = i; }
	string get_nazwa() const { return nazwa; }
	size_t get_ilosc_kierowcow() const { return ilosc_kierowcow; }
	size_t get_ilosc_mechanikow() const { return ilosc_mechanikow; }
	size_t get_ilosc_inzynierow() const { return ilosc_inzynierow; }
	size_t get_ilosc_nowych_wyscigow() const { return ilosc_nowych_wyscigow; }
	size_t get_ilosc_odbytych_wyscigow() const { return ilosc_starych_wyscigow; }

	void dodajKierowce(string godnosc = "n/a", string plec = "n/a", string pochodzenie = "n/a", int pesel = 0, int wiek = 0,
		int wynagrodzenie = 0, int dr = 1, int mr = 1, int rr = 2000, int dz = 1, int mz = 1, int rz = 2000, string model = "n/a");
	void dodajMechanika(string godnosc = "n/a", string plec = "n/a", string pochodzenie = "n/a", int pesel = 0, int wiek = 0,
		int wynagrodzenie = 0, int dr = 1, int mr = 1, int rr = 2000, int dz = 1, int mz = 1, int rz = 2000, string specjalizacja = "n/a");
	void dodajInzyniera(string godnosc = "n/a", string plec = "n/a", string pochodzenie = "n/a", int pesel = 0, int wiek = 0,
		int wynagrodzenie = 0, int dr = 1, int mr = 1, int rr = 2000, int dz = 1, int mz = 1, int rz = 2000, string stanowisko = "n/a");
	void dodajWyscig(int d = 1, int m = 1, int r = 2000, string pogoda_opis = "n/a", int szansa_opadow = 0, int predkosc_wiatru = 0,
		string miasto = "n/a", size_t dlugosc_toru = 0);
	void dodajStaryWyscig();

	void stworzKierowce();
	void stworzMechanika();
	void stworzInzyniera();
	void stworzWyscig();

	void usunKierowce(size_t index);
	void usunMechanika(size_t index);
	void usunInzyniera(size_t index);
	void usunWyscig(size_t index);

	void wypiszKierowcow() const;
	void wypiszMechanikow() const;
	void wypiszInzynierow() const;
	void wypiszWyscigi() const;
	void wypiszStareWyscigi() const;

	void wylosujKierowce();
	void wylosujMechanika();
	void wylosujInzyniera();
	void wylosujWyscig();

	void naprawBolidy();
	void pojedzWyscig();
	int wylosuj(int min, int max);
	void zatrzymaj();
};