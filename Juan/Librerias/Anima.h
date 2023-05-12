#ifndef _ANIMA
#define _ANIMA

#include <iostream>
#include "Cuentas.h"

using namespace std;

class Anima
{
private:
	int patas;
public:
	Anima(int _patas);
	~Anima();

	void setPatas(int _patas);
	int getPatas();

	void hablar();
};

#endif

