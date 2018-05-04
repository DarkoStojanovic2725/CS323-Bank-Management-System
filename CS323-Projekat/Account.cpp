#include "Account.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;


void Account::noviAcc() {  //otvaranje novog naloga
	cout << "\nUnesite broj naloga: ";
	cin >> BrAcc;  //unos broja naloga
	cout << "\n\nUnesite ime vlasnika naloga: ";
	cin.ignore();  //za ignorisanje novog reda kao karaktera
	cin.getline(ime, 50);
	cout << "\nUnesite tip naloga(C/S): ";
	cin >> tip;
	tip = toupper(tip);
	cout << "\nUnesite pocetno stanje(500 ili vise za Devizni, 1000 ili vise za tekuci): ";
	cin >> deposit;
	cout << "\n\n\nNalog je kreiran";
}

void const Account::prikaziAcc() {
	cout << "\nBroj naloga: " << BrAcc;   //prikaz naloga po broju
	cout << "\nVlasnik naloga: ";
	cout << ime;
	cout << "\nTip naloga: " << tip;
	cout << "\nTrenutno stanje: " << deposit;
}

void Account::menjaj() {
	cout << "\nBroj naloga: " << BrAcc;  //nalog se menja po boju naloga
	cout << "\nPromeni ime vlasnika: ";
	cin.ignore();
	cin.getline(ime, 50);
	cout << "\nIzmeni tip naloga: ";
	cin >> tip;
	tip = toupper(tip);
	cout << "\nIzmeni stanje naloga: ";
	cin >> deposit;
}

void Account::depo(int d) {
	deposit += d;
}

void Account::draw(int w) {
	deposit -= w;
}

void const Account::prikaz() {
	cout << BrAcc << setw(10) << " " << ime << setw(10) << " " << tip << setw(10) << deposit << endl;
}

const int Account::retAccBr() {
	return BrAcc;
}

const int Account::retDepo() {
	return deposit;
}

const char Account::retTip() {
	return tip;
}
