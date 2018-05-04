#include "Manage.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

void Manage::pravi_acc() {
	Account nalog;
	ofstream out;
	out.open("nalog.dat", ios::binary | ios::app);   //svi podaci su binarni
	nalog.Account::noviAcc();
	out.write(reinterpret_cast <char *> (&nalog), sizeof(Account));  //da bi se dobila tacna vrednost
	out.close();
}

void Manage::prikazi_acc(int p) {
	Account nalog;
	bool flag = false;
	ifstream in;
	in.open("nalog.dat", ios::binary);
	if (!in) {
		cout << "Fajl se ne moze otvoriti, pritisni enter";
		return;
	}
	cout << "\nPodaci o nalogu\n";
	while(in.read(reinterpret_cast <char *> (&nalog), sizeof(Account)))
	{
		if (nalog.retAccBr() == p) {
			nalog.prikaziAcc();
			flag = true;
		}

	}
	in.close();
	if (flag == false)
		cout << "\n\nNepostojeci broj naloga";
}

void Manage::izmeni_acc(int f) {
	bool nadjen = false;
	Account nalog;
	fstream File;
	File.open("nalog.dat", ios::binary | ios::in | ios::out);
	if (!File) {
		cout << "Fajl ne moze biti otvoren,pritisni enter";
		return;
	}
	while (!File.eof() && nadjen == false) {
		File.read(reinterpret_cast <char *> (&nalog), sizeof(Account));
		if (nalog.Account::retAccBr() == f) {
			nalog.Account::prikaziAcc();
			cout << "\n\nUnesite nove podatke: " << endl;
			nalog.Account::menjaj();
			int pos = (-1)*static_cast<int>(sizeof(Account));
			File.seekp(pos, ios::cur);
			File.write(reinterpret_cast<char *> (&nalog), sizeof(Account));
			cout << "\n\n\tNalog je azuriran";
			nadjen = true;
		}
	}
	File.close();
	if (nadjen == false)
		cout << "\n\n Podaci nisu pronadjeni";
}

void Manage::obrisi_acc(int g) {

	Account nalog;
	ifstream in;
	ofstream out;
	in.open("nalog.dat", ios::binary);
	if (!in) {
		cout << "Fajl se ne moze otvoriti, pritisni enter";
		return;
	}
	out.open("Temp.dat", ios::binary);
	in.seekg(0, ios::beg);
	while (in.read(reinterpret_cast<char *> (&nalog), sizeof(Account))) {
		if (nalog.Account::retAccBr() != g) {
			out.write(reinterpret_cast<char *> (&nalog), sizeof(Account));
		}
	}
	in.close();
	out.close();
	remove("nalog.dat");
	rename("Temp.dat", "nalog.dat");  //privremeno cuvanje svih naloga dok se ne obrise
	cout << "\n\n\tNalog obrisan";
}

void Manage::prikazi_sve() {
	Account nalog;
	ifstream in;
	in.open("nalog.dat", ios::binary);
	if (!in) {
		cout << "Fajl ne moze biti otvoren, pritisni enter";
		return;
	}
	cout << "\n\n\t\tLista naloga\n";
	cout << "----------------------------------------------------\n";
	cout << "Acc br.      Ime        Tip        Stanje\n";
	cout << "\n----------------------------------------------------\n";
	while (in.read(reinterpret_cast<char *> (&nalog), sizeof(Account)))
	{
		nalog.Account::prikaz();
	}
	in.close();
}

void Manage::deposit_withdraw(int i, int o) {
	int amount;
	bool nadjen = false;
	Account nalog;
	fstream File;
	File.open("nalog.dat", ios::binary | ios::in | ios::out);
	if (!File) {
		cout << "Fajl ne moze biti pronadjen, pritisni enter";
		return;
	}
	while (!File.eof() && nadjen == false)
	{
		File.read(reinterpret_cast<char *> (&nalog), sizeof(Account));
		if (nalog.Account::retAccBr() == i) {
			nalog.Account::prikaziAcc();
			if (o == 1) {
				cout << "\n\n\tZa uplatu:";
				cout << "\n\nUnesite kolicinu novca";
				cin >> amount;
				nalog.Account::depo(amount);
			}
			if (o == 2) {
				cout << "\n\n\tZa podizanje";
				cout << "\n\nUnesi kolicinu za podizanje";
				cin >> amount;
				int balance = nalog.Account::retDepo() - amount;
				if ((balance < 500 && nalog.Account::retTip() == 'S') || (balance < 1000 && nalog.Account::retTip() == 'C'))
					cout << "Nedozvoljeno stanje";
				else
					nalog.Account::draw(amount);
			}
			int pos = (-1)*static_cast<int>(sizeof(nalog));
			File.seekp(pos, ios::cur);
			File.write(reinterpret_cast<char *> (&nalog), sizeof(Account));
			cout << "\n\n\t Azurirano";
			nadjen = true;
		}
	}
	File.close();
	if (nadjen == false)
		cout << "\n\n Nalog nije pronadjen";
}

void Manage::start() {
	cout << "\n\n\n\t Dobrodosli u sistem";
	cin.get();
}