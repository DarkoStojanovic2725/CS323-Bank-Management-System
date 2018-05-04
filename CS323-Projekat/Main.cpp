#include "Account.h"
#include "Manage.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	char c;
	int br;
	Manage::start();
	do {
		system("cls");
		cout << "\n\n\n\tMeni";
		cout << "\n\n\t01 Novi Nalog";
		cout << "\n\n\t02 Depozit novca";
		cout << "\n\n\t03 Podizanje novca";
		cout << "\n\n\t04 Stanje racuna";
		cout << "\n\n\t05 Svi nalozi";
		cout << "\n\n\t06 Gasenje naloga";
		cout << "\n\n\t07 Izmeni nalog";
		cout << "\n\n\t08 Izlaz";
		cout << "\n\n\tIzaberi jednu od opcija od 1 do 8 ";
		cin >> c;
		system("cls");
		switch (c)
		{
		case '1':
			Manage::pravi_acc();
			break;
		case '2':
			cout << "\n\n\tUnesi broj naloga: "; cin >> br;
			Manage::deposit_withdraw(br, 1);
			break;
		case '3':
			cout << "\n\n\tUnesi broj naloga: "; cin >> br;
			Manage::deposit_withdraw(br, 2);
			break;
		case '4':
			cout << "\n\n\tUnesi broj naloga: "; cin >> br;
			Manage::prikazi_acc(br);
			break;
		case '5':
			Manage::prikazi_sve();
			break;
		case '6':
			cout << "\n\n\tUnesi broj naloga: "; cin >> br;
			Manage::obrisi_acc(br);
			break;
		case '7':
			cout << "\n\n\tUnesi broj naloga: "; cin >> br;
			Manage::izmeni_acc(br);
			break;
		case '8':
			cout << "\n\n\tHvala na koriscenju ovog sistema";
			break;
		default:cout << "\a";
		}
		cin.ignore();
		cin.get();
	} while (c != '8');
	return 0;
}