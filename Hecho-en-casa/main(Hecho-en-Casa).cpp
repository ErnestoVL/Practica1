/**********HECHO EN CASA**********/
#include <iostream>
#include <cmath>
#include <cstring>
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
}

bool esBisiesto (int anyo){
	return anyo%4==0 && anyo%100!=0 || anyo%400==0;
}

int solicitaDia(int anyo, int mes, int& dia, string msg){
	cout <<msg;
	cin >> dia;
	if (dia<1 || dia>31){
		cin.sync();
		cout <<"ERROR: El dia introducido no es válido" <<endl;
		solicitaDia(anyo, mes, dia, msg);
	}
	if ((mes==4 || mes==6 || mes==9 || mes==11) && (dia>30)){
		cin.sync();
		cout <<"ERROR: El dia introducido no es válido" <<endl;
		solicitaDia(anyo, mes, dia, msg);
	}
	if (dia>28 && mes==2 && !esBisiesto(anyo)){
		cin.sync();
		cout <<"ERROR: El dia introducido no es válido" <<endl;
		solicitaDia(anyo, mes, dia, msg);
	}
	if (dia>29 && mes==2 && esBisiesto(anyo)){
		cin.sync();
		cout <<"ERROR: El dia introducido no es válido" <<endl;
		solicitaDia(anyo, mes, dia, msg);
	}
}

int contarBisiestos (int anyoInicio, int anyoFinal, int anyo){ //<-- numero de bisiestos entre 1900--aaaa
	int numBisiestos;
	anyoInicio=1900;
	anyoFinal=anyo;
	numBisiestos = (anyoFinal-anyoInicio)/4; //<-- Dividir entre 4 pues es el periodo de los bisiestos
	return numBisiestos;
}

int diasAnyosCompletos (int anyo, int numBisiestos){ //<-- dias entre 1/1/1900--1/1/aaaa
	int numAnyos;
	numAnyos = ((anyo-1900)-numBisiestos)*365+(numBisiestos*366);
	return numAnyos;	
}


int dias_transcurridos_en_el_mes_dado(int dia, int mes, int anyo){// <-- Calcula los dias entre el 1--dd
	int dias_mes;
	dias_mes = dia-1;
	return dias_mes;
}

int dias_anyo_mas_transcurridos_en_el_mes (int numAnyos, int dias_mes){//<-- Calcula la suma de dias transcurridos en mm y los transcurridos entre 1900-aaaa
	int suma1;
	suma1 = numAnyos + dias_mes;
	return suma1;
}

int diferencia_de_meses(int mes){//<-- Calcula el numero de meses entre enero--mm
	int meses;
	meses = mes - 1;
	return meses;
}

int suma_1_mas_dias_transcurridos_entre_meses(int suma1, int mes, int diferencia_meses){//<-- Calcula la suma del metodo anterior mas los dias entre enero--mm	
}

void mostrar(int anyo,int mes,int dia,int numBisiestos,int numAnyos,int dias_mes, int suma1, int meses){
	cout <<"1-> Año introducido: " <<anyo <<endl;
	cout <<"2-> Mes introdocido: " <<mes <<endl;
	cout <<"3-> Dia introducido: " <<dia <<endl;
	cout <<"4-> Numero de años bisiestos: " <<numBisiestos <<endl;
	cout <<"5-> Diferencia de años transcurridos exprsado en dias: " <<numAnyos <<endl;
	cout <<"6-> Dias transcurridos hasta el primer dia del mes " <<mes <<" : " <<dias_mes <<endl;
	cout <<"7-> Apartado 5 + Apartado 6: "<<numAnyos <<" + " <<dias_mes <<" = " <<suma1 <<endl;
	cout <<"8-> Meses transcurridos: " <<meses <<endl;
	cout <<"9-> Diferencia de meses transcurridos expresada en dias: " <<endl;//<--Falta este metodo
	cout <<"10-> Apartado 7 + Apartado 9: " <<suma1 <<" + " <<" = " <<endl;
}

int main (int argc, char** args){
	int anyo, mes, dia, anyoInicio, anyoFinal, numBisiestos, numAnyos, dias_mes, suma1, meses;
	solicitaAnyo (anyo, "Introduce el año: ");
	solicitaMes (mes, "Introduce el mes: ");
	solicitaDia (anyo, mes, dia, "Introduce el dia: ");
	numBisiestos = contarBisiestos(anyoInicio, anyoFinal, anyo);
	numAnyos = diasAnyosCompletos (anyo, numBisiestos);
	dias_mes = dias_transcurridos_en_el_mes_dado(dia, mes, anyo);
	suma1 = dias_anyo_mas_transcurridos_en_el_mes (numAnyos, dias_mes);
	meses = diferencia_de_meses (mes);
	mostrar (anyo, mes, dia, numBisiestos, numAnyos, dias_mes, suma1, meses);
	system ("pause");
	return 0;
}
