#include "Anima.h"

Anima::Anima(int _patas) {
	patas = _patas;
}
Anima::~Anima() {

}
void Anima::setPatas(int _patas) {
	patas = _patas;
}
void Anima::hablar() {
	cout << "Animal Habla"<<endl;
}
int Anima::getPatas() {
	return patas;
}



// Set and Geter
