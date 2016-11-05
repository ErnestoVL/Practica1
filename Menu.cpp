#include <iostream>
#include <cmath>
#include <cstring>
#include <cctype>
using namespace std;

void ejecutarOpcion0(){
	exit (0);
}

void ejecutarOpcion1(){
	cout <<"1";
}

void ejecutarOpcion2(){
	cout <<"2";
}

void ejecutarOpcion3(){
	cout <<"3";
}

void ejecutarOpcion4(){
	cout <<"4";
}


/***************MENU************/
bool opcionCorrecta (int opc){
	return opc==1 || opc==2 || opc==3 || opc==4 || opc==0;
}

int mostrarMenu(int& opc){
	cout <<"1 - Calcular el dia de la semana para una fecha dada" <<endl;
	cout <<"2 - Obtener la fecha correspondiente al primer domingo de un año"<<endl;
	cout <<"3 - Obtener los domingos de un año"<<endl;
	cout <<"4 - Obtener los posibles puentes de un año"<<endl;
	cout <<"0 - Salir"<<endl;
	cout <<"Opción: ";
	cin >> opc;
	if(!opcionCorrecta(opc)){
		cin.clear();
		mostrarMenu(opc);
	}
	return opc;
}


void ejecutarOpcion(int opc){
	switch (opc) {
		case 1: ejecutarOpcion1(); break;
		case 2: ejecutarOpcion2(); break;
		case 3: ejecutarOpcion3(); break;
		case 4: ejecutarOpcion4(); break;
		case 0: ejecutarOpcion0(); break;
	}	
}

int main (int argc, char** args){
   int opc;
   mostrarMenu(opc);
   ejecutarOpcion(opc);
   system ("pause");
   return 0;
}
