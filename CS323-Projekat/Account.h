#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>

using namespace std;

class Account {

public:
	void noviAcc();
	void const prikaziAcc();
	void menjaj();
	void depo(int d);
	void draw(int w);
	void const prikaz();
	const int retAccBr();
	const int retDepo();
	const char retTip();

protected:
	int BrAcc;
	char ime[50];
	int deposit;
	char tip;
};


#endif // !ACCOUNT_H

