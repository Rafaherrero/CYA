#include "dfadfa.cpp"

using namespace std;

int main (void){
char opcion;
char nombrefichero[50];
int errorapertura;

cout << "\nDFA Detector v1.8.5" << endl;
cout << "\nEste programa le permitirá conocer si una cadena es válida en base a un DFA introducido." << endl;

DFA dfacito (nombrefichero, errorapertura);

while (errorapertura == 0){
	while (opcion != 's'){
		cout << "\nMenú de opciones del DFA." << endl;
		cout << "c. [c]argar fichero .dfa" << endl;
		cout << "m. [m]ostrar DFA." << endl;
		cout << "i. [i]dentificar estados de muerte." << endl;
		cout << "a. [a]nalizar cadena." << endl;
		cout << "s. [s]alir del programa." << endl;
		cout << "Introduzca una opción: " << endl;
		cin >> opcion;
		while (opcion != 'c' && opcion != 'm' && opcion != 'i' && opcion != 'a' && opcion != 's'){
			cout << endl << "La opción introducida no es correcta. Introduzca otra: " << endl;
			cin >> opcion;
		}
	
	switch (opcion){
		case 'c': dfacito.actualizar (nombrefichero, errorapertura);
		while (errorapertura == 1){
		dfacito.actualizar (nombrefichero, errorapertura);
		}
		break;
		case 'm': dfacito.mDFA ();
		break;
		case 'i': dfacito.mestadosmuerte ();
		break;
		case 'a': dfacito.acadena ();
		break;
		case 's': cout << "\n¡Hasta pronto!\n" << endl,
		errorapertura = 354321;
	}
}
}
}

//Rafael Herrero Álvarez