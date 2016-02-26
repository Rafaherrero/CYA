#include "grafo.cpp"

using namespace std;

int main (void){
char opcion;
char nombrefichero[50];
int errorapertura;

cout << "\nEste programa le permitirá realizar diferentes operaciones con grafos." << endl;

GRAFO grafito (nombrefichero, errorapertura);

while ((grafito.dirigido == 0 || grafito.dirigido == 1) && errorapertura == 0){
if (grafito.dirigido == 0){
while (opcion != 'q' && grafito.dirigido == 0){
cout << "\nActividad I, Optimización: carga básica de un grafo." << endl;
cout << "c. [c]argar grafo desde archivo." << endl;
cout << "i. Mostrar [i]nformación básica del grafo." << endl;
cout << "a. Mostrar la lista de [a]dyacencia del grafo." << endl;
cout << "q. Finalizar el programa." << endl;
cout << "Introduzca la letra de la acción a ejecutar: ";
cin >> opcion;
while (opcion != 'c' && opcion != 'i' && opcion != 'a' && opcion != 'q'){
cout << endl << "Ha introducido una opción no correcta. Por favor introduzca otra nuevamente: " << endl;
cin >> opcion;
}
switch (opcion){
case 'c': grafito.actualizar(nombrefichero, errorapertura);
while (errorapertura == 1){
grafito.actualizar (nombrefichero, errorapertura);
}
break;
case 'i': grafito.Info_Grafo();
break;
case 'a': grafito.Mostrar_Listas(2);
break;
case 'q': cout << "\nGracias por utilizar este programa.\n" << endl;
grafito.dirigido = 2;

}
}
}

if (grafito.dirigido == 1 && errorapertura == 0){
while (opcion != 'q' && grafito.dirigido == 1){
cout << "\nActividad I, Optimización: carga básica de un grafo." << endl;
cout << "c. [c]argar grafo desde archivo." << endl;
cout << "i. Mostrar [i]nformación básica del grafo." << endl;
cout << "s. Mostrar la lista de [s]ucesores del grafo." << endl;
cout << "p. Mostrar la lista de [p]redecesores del grafo." << endl;
cout << "q. Finalizar el programa." << endl;
cout << "Introduzca la letra de la acción a ejecutar: ";
cin >> opcion;
while (opcion != 'c' && opcion != 'i' && opcion != 's' && opcion != 'p' && opcion != 'q'){
cout << endl << "Ha introducido una opción no correcta. Por favor introduzca otra nuevamente: " << endl;
cin >> opcion;
}
switch (opcion){
case 'c': grafito.actualizar(nombrefichero, errorapertura);
while (errorapertura == 1){
grafito.actualizar (nombrefichero, errorapertura);
}
break;
case 'i': grafito.Info_Grafo();
break;
case 's': grafito.Mostrar_Listas(1);
break;
case 'p': grafito.Mostrar_Listas(0);
break;
case 'q': cout << "\nGracias por utilizar este programa.\n" << endl;
grafito.dirigido = 2;
}
}
}
}
}


