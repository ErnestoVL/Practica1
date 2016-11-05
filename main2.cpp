#include <iostream>
#include <cmath>
#include <cstring>
#include <cctype>
using namespace std;

int solicitaAnyo(int& anyo, string msg) {
	cout << msg ;
	cin >> anyo;
	while (anyo < 1900){
		cin.fail ();
		cin.clear();
		cin.sync();
		cout << "ERROR: El año introducido no es válido" << endl;
		cout << msg;
		cin >> anyo;
	}
	return anyo;
}

int solicitaMes(int& mes, string msg) {
	cout << msg;
	cin >> mes;
	while (mes < 1 || mes > 12){
		cin.fail ();
		cin.clear();
		cin.sync();
		cout << "ERROR: El mes introducido no es válido" << endl;
		cout << msg;
		cin >> mes;
	}
	return mes;
}

bool esBisiesto (int anyo){
	return anyo%4==0 && anyo%100!=0 || anyo%400==0;
}

int solicitaDia(int anyo, int mes, int& dia, string msg){
	cout <<msg;
	cin >> dia;
	if (dia<1 || dia>31){
		cout <<"ERROR: El dia introducido no es válido" <<endl;
		solicitaDia(anyo, mes, dia, msg);
	}
	if (dia>30 && mes==4 || mes==6 || mes==9 || mes==11){
		cout <<"ERROR: El dia introducido no es válido" <<endl;
		solicitaDia(anyo, mes, dia, msg);
	}
	if (dia>28 && mes==2 && !esBisiesto(anyo)){
		cout <<"ERROR: El dia introducido no es válido" <<endl;
		solicitaDia(anyo, mes, dia, msg);
	}
	if (dia>29 && mes==2 && esBisiesto(anyo)){
		cout <<"ERROR: El dia introducido no es válido" <<endl;
		solicitaDia(anyo, mes, dia, msg);
	}
	return dia;
}



void mostrar(int anyo, int mes, int dia){
	cout <<dia <<"/" <<mes <<"/" <<anyo <<endl;
}

int main(int argc, char** args){
	setlocale(LC_ALL, "spanish");
	int anyo, mes, dia;
	solicitaAnyo(anyo, "Introduzca un año: ");
	solicitaMes(mes, "Introduzca un mes: ");
	solicitaDia (anyo, mes, dia, "Introduzca un dia: ");
	mostrar(anyo, mes, dia);
	system("pause");
	return 0;
}
