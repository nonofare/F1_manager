#include <iostream>
#include <cstdlib>
#include <string>
#include <random>
#include "Zespol.h"
using namespace std;



const size_t max_ilosc_kierowcow = 2;
const size_t max_ilosc_pracownikow = 32;
const size_t max_ilosc_wyscigow = 20;

Zespol* Zespol::zespol = Zespol::get_Zespol();



int main() {
	int wybor;
	size_t index;
	string nazwa;

	cout << ">>>> Symulator zespolu F1 <<<<\nAutor: Adam Wojturski\n\nPodaj nazwe swojego zespolu: ";
	getline(cin, nazwa);
	Zespol::get_Zespol()->set_nazwa(nazwa);

	do {
		system("CLS");
		cout << ">>>>>>>> " << Zespol::get_Zespol()->get_nazwa() << " <<<<<<<<" << endl;
		cout << "Kierowcy: " << Zespol::get_Zespol()->get_ilosc_kierowcow() << endl
			<< "Mechanicy: " << Zespol::get_Zespol()->get_ilosc_mechanikow() << endl
			<< "Inzynierowie: " << Zespol::get_Zespol()->get_ilosc_inzynierow() << endl
			<< "Nadchodzace wyscigi: " << Zespol::get_Zespol()->get_ilosc_nowych_wyscigow() << endl
			<< "Odbyte wyscigi: " << Zespol::get_Zespol()->get_ilosc_odbytych_wyscigow() << endl << endl;
		cout << ">>>> Wyscigi <<<<" << endl;
		cout << "1. Dodaj wyscig\n2. Usun wyscig\n3. Wyswietl nadchodzace wyscigi\n4. Wyswietl odbyte wyscigi" << endl << endl;
		cout << ">>>> Kierowcy <<<<" << endl;
		cout << "5. Zatrudnij kierowce\n6. Zwolnij kierowce\n7. Wyswietl kierowcow" << endl << endl;
		cout << ">>>> Mechanicy <<<<" << endl;
		cout << "8. Zatrudnij mechanika\n9. Zwolnij mechanika\n10. Wyswietl mechanikow" << endl << endl;
		cout << ">>>> Inzynierowie <<<<" << endl;
		cout << "11. Zatrudnij inzyniera\n12. Zwolnij inzyniera\n13. Wyswietl inzynierow" << endl << endl;
		cout << ">>>> Akcje <<<<" << endl;
		cout << "14. Napraw bolidy\n15. Pojedz wyscig\n\n16. Wygeneruj losowo\n17. Zamknij program" << endl;

		cout << "Wybor: ";
		cin >> wybor;
		system("CLS");

		switch (wybor) {
		case 1:
			Zespol::get_Zespol()->stworzWyscig();
			break;

		case 2:
			cout << "Podaj index wyscigu do usuniecia: ";
			cin >> index;
			Zespol::get_Zespol()->usunWyscig(index);
			break;

		case 3:
			Zespol::get_Zespol()->wypiszWyscigi();
			Zespol::get_Zespol()->zatrzymaj();
			break;

		case 4:
			Zespol::get_Zespol()->wypiszStareWyscigi();
			Zespol::get_Zespol()->zatrzymaj();
			break;

		case 5:
			Zespol::get_Zespol()->stworzKierowce();
			break;

		case 6:
			cout << "Podaj index kierowcy do usuniecia: ";
			cin >> index;
			Zespol::get_Zespol()->usunKierowce(index);
			break;

		case 7:
			Zespol::get_Zespol()->wypiszKierowcow();
			Zespol::get_Zespol()->zatrzymaj();
			break;

		case 8:
			Zespol::get_Zespol()->stworzMechanika();
			break;

		case 9:
			cout << "Podaj index mechanika do usuniecia: ";
			cin >> index;
			Zespol::get_Zespol()->usunMechanika(index);
			break;

		case 10:
			Zespol::get_Zespol()->wypiszMechanikow();
			Zespol::get_Zespol()->zatrzymaj();
			break;

		case 11:
			Zespol::get_Zespol()->stworzInzyniera();
			break;

		case 12:
			cout << "Podaj index inzyniera do usuniecia: ";
			cin >> index;
			Zespol::get_Zespol()->usunInzyniera(index);
			break;

		case 13:
			Zespol::get_Zespol()->wypiszInzynierow();
			Zespol::get_Zespol()->zatrzymaj();
			break;

		case 14:
			Zespol::get_Zespol()->naprawBolidy();
			Zespol::get_Zespol()->zatrzymaj();
			break;

		case 15:
			Zespol::get_Zespol()->pojedzWyscig();
			Zespol::get_Zespol()->zatrzymaj();
			break;

		case 16:
			for (size_t i = 0; i < max_ilosc_kierowcow; i++) {
				Zespol::get_Zespol()->wylosujKierowce();
			}
			for (size_t i = 0; i < max_ilosc_pracownikow; i++) {
				Zespol::get_Zespol()->wylosujMechanika();
			}
			for (size_t i = 0; i < max_ilosc_pracownikow; i++) {
				Zespol::get_Zespol()->wylosujInzyniera();
			}
			for (size_t i = 0; i < max_ilosc_wyscigow; i++) {
				Zespol::get_Zespol()->wylosujWyscig();
			}
			break;

		case 17:
			delete Zespol::get_Zespol();
			break;

		default:
			cout << "Niepoprawny wybor" << endl;
			Zespol::get_Zespol()->zatrzymaj();
			break;

		}
	} while (wybor != 17);

	return 0;
}