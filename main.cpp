#include <iostream>
#include <cmath>
#include <cstring>
#include <cctype>
using namespace std;

int solicitaAnyo(int& anyo) {
	cout << "Indroduzca un año: " ;
	cin >> anyo;
	while (anyo < 1900 || !cin.good()){
		cin.clear();
		cin.sync();
		cout << "ERROR: El año introducido no es válido" << endl;
		cout << "Introduzca un año: ";
		cin >> anyo;
	}
	return anyo;
}

int solicitaMes(int& mes) {
	cout << "Introduzca un mes: ";
	cin >> mes;
	while (mes < 1 || mes > 12 || !cin.good()){
		cin.clear();
		cin.sync();
		cout << "ERROR: El mes introducido no es válido" << endl;
		cout << "Introduzca un mes: ";
		cin >> mes;
	}
	return mes;
}

void mostrar(int anyo, int mes) {
	cout << anyo << endl;
	cout << mes << endl;
}

int main(int argc, char** args) {
	int anyo, mes;
	solicitaAnyo(anyo);
	mostrar(anyo, mes);
	system("pause");
	return 0;
}
