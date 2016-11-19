
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int dias[12] = { 0, 31, 29, 31, 30, 31, 30, 30, 31, 30, 31, 30 };//Array que contiene los dias de los meses

int solicitaAnyo(int& anyo) {
	cout << "Introduce el año: ";
	cin >> anyo;
	while (anyo < 1900){
		cin.fail();
		cin.clear();
		cin.sync();
		cout << "ERROR: El año introducido no es válido" << endl;
		cout << "Introduce el año: ";
		cin >> anyo;
	}
	return anyo;
}

int solicitaMes(int& mes) {
	cout << "Introduce el mes: ";
	cin >> mes;
	while (mes < 1 || mes > 12){
		cin.fail();
		cin.clear();
		cin.sync();
		cout << "ERROR: El mes introducido no es válido" << endl;
		cout << "Introduce el mes: ";
		cin >> mes;
	}
	return mes;
}

bool esBisiesto(int anyo){
	return anyo % 4 == 0 && anyo % 100 != 0 || anyo % 400 == 0;
}

int solicitaDia(int anyo, int mes, int& dia){
	cout << "Introduce el dia: ";
	cin >> dia;
	if (dia<1 || dia>31){
		cin.sync();
		cout << "ERROR: El dia introducido no es válido" << endl;
		solicitaDia(anyo, mes, dia);
	}
	if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && (dia>30)){
		cin.sync();
		cout << "ERROR: El dia introducido no es válido" << endl;
		solicitaDia(anyo, mes, dia);
	}
	if (dia>28 && mes == 2 && !esBisiesto(anyo)){
		cin.sync();
		cout << "ERROR: El dia introducido no es válido" << endl;
		solicitaDia(anyo, mes, dia);
	}
	if (dia>29 && mes == 2 && esBisiesto(anyo)){
		cin.sync();
		cout << "ERROR: El dia introducido no es válido" << endl;
		solicitaDia(anyo, mes, dia);
	}
	return dia;
}

int contarBisiestos(int& anyoInicio, int& anyoFinal, int anyo){ //<-- numero de bisiestos entre 1900--aaaa
	int numBisiestos;
	anyoInicio = 1900;
	anyoFinal = anyo;
	numBisiestos = (anyoFinal - anyoInicio) / 4; //<-- Dividir entre 4 pues es el periodo de los bisiestos
	return numBisiestos;
}

long int diasAnyosCompletos(int anyo, int numBisiestos){ //<-- dias entre 1/1/1900--1/1/aaaa
	long int numAnyos;
	numAnyos = ((anyo - 1900) - numBisiestos) * 365 + (numBisiestos * 366);
	return numAnyos;//<-- Dias transcurridos de aaaa--1900	
}

int dias_transcurridos_en_el_mes_dado(int dia){// <-- Calcula los dias entre el 1--dd
	int dias_mes;
	dias_mes = dia - 1;
	return dias_mes; //<-- Dias transcurridos de dd--01 en el mes introducido
}

int dias_anyo_mas_transcurridos_en_el_mes(long int numAnyos, int dias_mes){//<-- Calcula la suma de dias transcurridos en mm y los transcurridos entre 1900-aaaa
	int suma1;
	suma1 = numAnyos + dias_mes;
	return suma1;//<-- Dias transcurridos de aaaa--1900+dd--01
}

int diferencia_de_meses(int mes){//<-- Calcula el numero de meses entre enero--mm
	int meses;
	meses = mes - 1;
	return meses;//<-- Numero de meses transcurridos de mm--01
}

int dias_de_la_diferencia_de_meses(int meses){//<-- Calcula el numero de dias total entre los meses transcurridos hasta enero
	int diferencia_meses, n;
	diferencia_meses = 0;
	for (n = 0; n <= meses; n++){
		diferencia_meses = diferencia_meses + dias[n];
	}
	return diferencia_meses; //<-- Dias transcurridos de mm--01
}

long int diasTranscurridos(int anyo, int suma1, int mes, int diferencia_meses){//<-- Calcula la suma del metodo anterior mas los dias entre enero--mm
	long int numDias;
	if (esBisiesto(anyo) && (mes==1 || mes==2)){
		numDias = (suma1 + diferencia_meses) - 1;
	}
	else {
		numDias = suma1 + diferencia_meses;
	}
	return numDias; //<-- Todos los dias transcurridos desde dd/mm/aaaa hasta 01/01/1900
}

int diaSemana(long int numDias){//<-- Calcula el dia de la semana de la fecha introducida
	int representacionDia;
	representacionDia = numDias % 7;
	return representacionDia;
}

string nombreDiaSemana(int representacionDia){//<-- Asigna el dia de la semana al numero del metodo anterior
	string nombreDia;
	switch (representacionDia){
	case 0: nombreDia = "Lunes"; break;
	case 1: nombreDia = "Martes"; break;
	case 2: nombreDia = "Miercoles"; break;
	case 3: nombreDia = "Jueves"; break;
	case 4: nombreDia = "Viernes"; break;
	case 5: nombreDia = "Sabado"; break;
	case 6: nombreDia = "Domingo"; break;
	}
	return nombreDia;
}

void mostrar(string nombreDia, int anyo, int mes, int dia, long int numAnyos, long int numDias){
	cout <<"1-> Fecha Introducida: " <<dia <<"/"<<mes <<"/" <<anyo <<endl;
	cout <<"2-> Años transcurridos expresados en dias: " <<numAnyos <<endl;
	cout <<"3-> Dias transcurridos: " <<numDias <<endl;
	cout <<"4-> Dia de la semana de la fecha introducida: " <<nombreDia <<endl;
}

int main(int argc, char** args){
	setlocale(LC_ALL, "spanish");
	int anyo, mes, dia, anyoInicio, anyoFinal, numBisiestos, dias_mes, suma1, meses, diferencia_meses;
	int representacionDia;
	long int numAnyos, numDias;
	string nombreDia;
	solicitaAnyo(anyo);
	solicitaMes(mes);
	solicitaDia(anyo, mes, dia);
	numBisiestos = contarBisiestos(anyoInicio, anyoFinal, anyo);
	numAnyos = diasAnyosCompletos(anyo, numBisiestos);
	dias_mes = dias_transcurridos_en_el_mes_dado(dia);
	suma1 = dias_anyo_mas_transcurridos_en_el_mes(numAnyos, dias_mes);
	meses = diferencia_de_meses(mes);
	diferencia_meses = dias_de_la_diferencia_de_meses(meses);
	numDias = diasTranscurridos(anyo, suma1, mes, diferencia_meses);
	representacionDia = diaSemana(numDias);
	nombreDia = nombreDiaSemana(representacionDia);
	mostrar(nombreDia, anyo, mes, dia, numAnyos, numDias);
	system("pause");
	return 0;
}
