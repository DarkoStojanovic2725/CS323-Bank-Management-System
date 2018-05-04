#ifndef MANAGE_H
#define MANAGE_H
#include <iostream>
#include <string>
#include "Account.h"

using namespace std;

class Manage: public Account {
public:
	static void pravi_acc();
	static void prikazi_acc(int p);
	static void izmeni_acc(int f);
	static void obrisi_acc(int g);
	static void prikazi_sve();
	static void deposit_withdraw(int i, int o);
	static void start();

};

#endif // !MANAGE_H
