#include <iostream>
#include <cmath>
#include <string>
#include <cctype>
using namespace std;

int solicitaAnyo(string msg) {
	int anyo;
	cout << msg;
	cin >> anyo;
	while (anyo < 1900){
		cin.fail();
		cin.clear();
		cin.sync();
		cout << "ERROR: El año introducido no es válido" << endl;
		cout << msg;
		cin >> anyo;
	}
	return anyo;
}

int solicitaMes(string msg) {
	int mes;
	cout << msg;
	cin >> mes;
	while (mes < 1 || mes > 12){
		cin.fail();
		cin.clear();
		cin.sync();
		cout << "ERROR: El mes introducido no es válido" << endl;
		cout << msg;
		cin >> mes;
	}
	return mes;
}

bool esBisiesto(int anyo){
	return anyo % 4 == 0 && anyo % 100 != 0 || anyo % 400 == 0;
}

int solicitaDia(int anyo, int mes, int& dia, string msg){
	cout << msg;
	cin >> dia;
	while (dia<1 || dia>31){
		cin.fail();
		cin.clear();
		cin.sync();
		cout << "ERROR: El día introducido no es válido" << endl;
		cout << msg;
		cin >> dia;
	}
	while ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && (dia<1 || dia>30)){
		cin.fail();
		cin.clear();
		cin.sync();
		cout << "ERROR: El día introducido no es válido" << endl;
		cout << msg;
		cin >> dia;
	}
	while (dia>28 && mes == 2 && !esBisiesto(anyo)){
		cin.fail();
		cin.clear();
		cin.sync();
		cout << "ERROR: El día introducido no es válido" << endl;
		cout << msg;
		cin >> dia;
	}
	while (dia>29 && mes == 2 && esBisiesto(anyo)){
		cin.fail();
		cin.clear();
		cin.sync();
		cout << "ERROR: El día introducido no es válido" << endl;
		cout << msg;
		cin >> dia;
	}
	return dia;
}


long int diasAnyosCompletos(int anyo, int numBisiestos){ //<-- dias entre 1/1/1900--1/1/aaaa
	int numAnyos;
	numAnyos = (anyo-1900) * 365 + numBisiestos;
	return numAnyos;
}


int contarBisiestos(int anyo){ //<-- numero de bisiestos entre 1900--aaaa
	int numBisiestos, anyoFinal, anyoInicio;
	anyoInicio = 1900;
	anyoFinal = anyo;
	numBisiestos = (anyoFinal - anyoInicio) / 4; //<-- Dividir entre 4 pues es el periodo de los bisiestos
	return numBisiestos;
}

long int diferenciaDeDias(int dia){ //<-- Diferencia entre dd-01
	int difDia;
	difDia = dia - 1;
	return difDia;
}
/********DIAS DADOS UN MES Y UN AÑO********/
int diasMes(int mes, int anyo){
	int dias_mes;
	switch (mes){
	case 1:
	case 3: 
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: dias_mes = 31; break;
	case 4:
	case 6:
	case 9: 
	case 11: dias_mes = 30; break;
	case 2: while (esBisiesto(anyo)){
				dias_mes = 29;
			}; break;
			while (!esBisiesto(anyo)){
				dias_mes = 28;
			}; break;
	}
	return dias_mes;
}
/********FIN********/



/*int diasEsteAnyo(int dia, int mes, int anyo){ //<-- dias entre 1/1/aaaa--dd/mm/aaaa
	int diferenciaDia;
	diferenciaDia = dia - 1;
	int diferenciaMeses;
	diferenciaMeses = mes - 1;
	int diasPasadosEntreMeses;
	diasPasadosEntreMeses = 
}*/

long int diasTranscurridos(int mes, int numAnyos, int difDia){ //<-- dias entre 1/1/1900--dd/mm/aaaa
	int numDias;
	numDias = difDia + mes + numAnyos;
	return numDias;
}


void mostrar(int anyo, int mes, int dia, int dif, int numBisiestos, int numAnyos, int difDia, int dias_mes){
	cout << dia << "/" << mes << "/" << anyo << endl;
	cout << dif  << " = mes+dias transcurridos+dias transcurridos entre los dos años" << endl;
	cout << difDia << " dias transcurridos entre 1-" << dia << endl;
	cout << numBisiestos <<" año/s bisiestos" << endl;
	cout << numAnyos << " días transcurridos entre 1900-" << anyo <<" sin contar dia y mes" << endl;
	cout << dias_mes << " Dias dado un mes" << endl;
} 


int main(int argc, char** args){
	setlocale(LC_ALL, "spanish");
	int anyo, mes, dia, dif, anyoFinal, anyoInicio, numBisiestos, numAnyos, difDia, dias_mes;
	anyo = solicitaAnyo("Introduzca un año: ");
	mes = solicitaMes("Introduzca un mes: ");
	solicitaDia(anyo, mes, dia, "Introduzca un dia: ");
	numBisiestos = contarBisiestos(anyo);
	numAnyos = diasAnyosCompletos(anyo, numBisiestos);
	difDia = diferenciaDeDias(dia);
	dif = diasTranscurridos(difDia, mes, numAnyos);
	dias_mes = diasMes(mes, anyo);
	mostrar(anyo, mes, dia, dif, numBisiestos, numAnyos, difDia, dias_mes);
	system("pause");
	return 0;
}
