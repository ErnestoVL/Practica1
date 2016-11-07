#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

/**********TODOS LOS PROCESOS NECESARIOS PARA TODAS LAS OPCIONES**********/

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

/**********MENU**********/

void mostrarMenu(){
	cout <<"1 - Calcular el dia de la semana para una fecha dada" <<endl;
	cout <<"2 - Obtener la fecha correspondiente al primer domingo de un año"<<endl;
	cout <<"3 - Obtener los domingos de un año"<<endl;
	cout <<"4 - Obtener los posibles puentes de un año"<<endl;
	cout <<"0 - Salir"<<endl;
	cout <<"Opción: ";
}

bool esOpcionValida(int opc){
	return opc==1 || opc==2 || opc==3 || opc==4 || opc==0;
}

int leerOpcion(int& opc){
	cin >> opc;
	while(cin.fail() || !esOpcionValida(opc)){
		cin.clear();
		cin.sync();
		mostrarMenu();
		cin >> opc;
	}
	return opc;
}

int menu(int opc){
	mostrarMenu();
	opc=leerOpcion(opc);
	return opc;
}

void _Opcion1(){
	ejecutarOpcion1();
}

void _Opcion2(){
	ejecutarOpcion2();
}

void _Opcion3(){
	ejecutarOpcion3();
}

void _Opcion4(){
	ejecutarOpcion4();
}

void _Opcion0(){
	ejecutarOpcion0();
}


void ejecutarOpciones(int opc){
	switch(opc){
		case 1: _Opcion1(); break;
		case 2: _Opcion2(); break;
		case 3: _Opcion3(); break;
		case 4: _Opcion4(); break;
		case 0: _Opcion0(); break;
	}
}

/**********MAIN**********/

int main(int argc, char** args){
	int opc;
	opc=menu(opc);
	ejecutarOpciones(opc);
	system ("pause");
	return 0;
}





