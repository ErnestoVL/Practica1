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
		solicitaDia(anyo, mes, dia, msg);
	}
	if ((mes==4 || mes==6 || mes==9 || mes==11) && (dia>30)){
		solicitaDia(anyo, mes, dia, msg);	
	}
	if (dia>28 && mes==2 && !esBisiesto(anyo)){
		solicitaDia(anyo, mes, dia, msg);
	}
	if (dia>29 && mes==2 && esBisiesto(anyo)){
		solicitaDia(anyo, mes, dia, msg);
	}
	return dia;
}


int diasAnyosCompletos (int anyo, int numBisiestos){ //<-- dias entre 1/1/1900--1/1/aaaa
	int numAnyos;
	numAnyos = (anyo-numBisiestos)*365+numBisiestos;
	return numAnyos;	
}

/*
int diasEsteAnyo (int dia, int mes, int anyo){ //<-- dias entre 1/1/aaaa--dd/mm/aaaa
	
}
*/

int contarBisiestos (int anyoInicio, int anyoFinal, int anyo){ //<-- numero de bisiestos entre 1900--aaaa
	int numBisiestos;
	anyoInicio=1900;
	anyoFinal=anyo;
	numBisiestos = (anyoFinal-anyoInicio)/4; //<-- Dividir entre 4 pues es el periodo de los bisiestos
	return numBisiestos;
}

long int diasTranscurridos(int mes, int anyo, int dia){ //<-- dias entre 1/1/1900--dd/mm/aaaa
	int numDias;
	numDias = dia+mes+anyo;
	return numDias;
}


void mostrar(int anyo, int mes, int dia, int dif, int numBisiestos, int numAnyos){
	cout <<dia <<"/" <<mes <<"/" <<anyo <<endl;
	cout <<dif <<endl;
	cout <<numBisiestos <<endl;
	cout <<numAnyos <<endl;
}


int main(int argc, char** args){
	setlocale(LC_ALL, "spanish");
	int anyo, mes, dia, difM, difA, difD, difT, dif, anyoFinal, anyoInicio, numBisiestos, numAnyos;
	solicitaAnyo(anyo, "Introduzca un año: ");
	solicitaMes(mes, "Introduzca un mes: ");
	solicitaDia (anyo, mes, dia, "Introduzca un dia: ");
	numBisiestos = contarBisiestos(anyoInicio, anyoFinal, anyo);
	numAnyos = diasAnyosCompletos(anyo, numBisiestos);
	dif=diasTranscurridos(dia, mes, anyo);
	mostrar(anyo, mes, dia,dif, numBisiestos, numAnyos);
	system("pause");
	return 0;
}
