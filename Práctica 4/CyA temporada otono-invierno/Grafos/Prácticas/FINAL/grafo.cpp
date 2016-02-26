#include "grafo.hpp"

using namespace std;

GRAFO::GRAFO (char nombrefichero[], int &errorapertura)
{
unsigned i,j;
ElementoLista dummy;

cout << "Introduzca el nombre del fichero: " << endl;
cin >> nombrefichero;
ifstream fich;
fich.open(nombrefichero);
 if (!fich.is_open()) { 
 cout << "\nError en la apertura del fichero." << endl;
 errorapertura = 1;
 } 

 else{
cout << "\nEl fichero se ha cargado correctamente." << endl;
 errorapertura = 0;
fich >> (unsigned &) n >> (unsigned &) m >> (unsigned &) dirigido;
LS.resize(n);

for (int q = 0; q < m; q++){

//fich >> (unsigned &) i >> (unsigned &) j;
//if (dirigido == 1){
fich >> (unsigned &) i >> (unsigned &) j;
dummy.j = j-1;
LS [i-1].push_back(dummy);


//else{
if (dirigido == 0){
if (i == j){
}
else{
dummy.j = i-1;
LS [j-1].push_back(dummy);
}
}
}

fich.close();
ListaPredecesores();
 }
if (dirigido != 0 && dirigido != 1){
cout << "ERROR EN EL ARCHIVO" << endl;
}
}


void GRAFO::actualizar(char nombrefichero[], int &errorapertura){

LS.clear();
LP.clear();

unsigned i,j;
ElementoLista dummy;

cout << "\nIntroduzca el nombre del fichero: " << endl;
cin >> nombrefichero;
ifstream fich;
fich.open(nombrefichero);
 if (!fich.is_open()) { 
 cout << "\nError en la apertura del fichero." << endl;
 errorapertura = 1;
 } 
 
 else{
cout << "\nEl fichero se ha cargado correctamente." << endl;
 errorapertura = 0;
fich >> (unsigned &) n >> (unsigned &) m >> (unsigned &) dirigido;
LS.resize(n);
for (int q = 0; q < m; q++){

//fich >> (unsigned &) i >> (unsigned &) j;
//if (dirigido == 1){
fich >> (unsigned &) i >> (unsigned &) j;
dummy.j = j-1;
LS [i-1].push_back(dummy);

//else{
if (dirigido == 0){
dummy.j = i-1;
LS [j-1].push_back(dummy);
}
}
fich.close();
ListaPredecesores();
 }
if (dirigido != 0 && dirigido != 1){
cout << "ERROR EN EL ARCHIVO" << endl;
}
}

void GRAFO::Info_Grafo(){
if (dirigido == 1){
cout << endl << "El grafo es dirigido." << endl;
}
else{
cout << endl << "El grafo es NO dirigido." << endl;
}

cout << "Hay " << n << " nodos y "<< m << " aristas" << endl;
}

void GRAFO::Mostrar_Listas(int l){

if (l==0){
cout << "Mostrando la lista de predecesores." << endl;
for (int q = 0; q < n; q++){
cout << endl << "El nodo " << q+1 << " tiene como predecesores a: ";
for (int w = 0; w < LP[q].size(); w++){
cout << " " << (LP[q][w].j)+1;
}
}
}

if (l==1){
cout << "Mostrando la lista de sucesores." << endl;
for (int q = 0; q < n; q++){
cout << endl << "El nodo " << q+1 << " tiene como sucesores a: ";
for (int w = 0; w < LS[q].size(); w++){
cout << " " << (LS[q][w].j)+1;
}
}
}

if (l==2){
cout << "Mostrando la lista de adyacentes." << endl;
for (int q = 0; q < n; q++){
cout << endl << "El nodo " << q+1 << " tiene como adyacentes a: ";
for (int w = 0; w < LS[q].size(); w++){
cout << " " << (LS[q][w].j)+1;
}
}
}
cout << endl;
}

void GRAFO::ListaPredecesores(){
ElementoLista dummy;
LP.resize(n);
for (int q = 0; q < n; q++){
for (int w = 0; w < LS[q].size(); w++){
dummy.j = q;
LP[LS[q][w].j].push_back(dummy);
}
}
}

GRAFO::~GRAFO(){
for (int q; q < n; q++){
LS[q].clear();
LP[q].clear();
}
LS.clear();
LP.clear();
}

