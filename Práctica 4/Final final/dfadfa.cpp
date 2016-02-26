#include "cdfa.hpp"

using namespace std;

DFA::DFA (char nombrefichero[], int&errorapertura) {
actualizar (nombrefichero, errorapertura);
}


void DFA::actualizar (char nombrefichero[], int &errorapertura){

VE.clear();
VT.clear();

EL_estado muneco;
LA_transi muneco2;
unsigned est, muerto, trans, estsig;
char letrita;
int pr;
bool error = false; 

cantidad = 0;
inicial = 0;
est = 0;
muerto = 0;
trans = 0;
estsig = 0;
pr = 0;

cout << endl << "Introduzca el nombre del fichero: " << endl;
cin >> nombrefichero;
ifstream fich;
fich.open(nombrefichero);
 if (!fich.is_open()) { 
 cout << "\nError en la apertura del fichero." << endl;
 errorapertura = 1;
 } 

 else{

 errorapertura = 0;
 fich >> (unsigned &) cantidad >> (unsigned &) inicial;
 VE.resize(cantidad);
 VT.resize(cantidad);

for (int w = 0; (w < cantidad)&&(error == false); w++){
fich >> (unsigned &) est >> (unsigned &) muerto >> (unsigned &) trans;
muneco.estado = est;
muneco.tipo = muerto;
muneco.ctr = trans;
VE.insert (VE.begin()+w, muneco);

if (VE[0].estado != 0){
cout << "\n¡ERROR!Hay más de un estado inicial¡ERROR!\nVuelva a cargar el fichero" << endl;
error = true;
}
//VE.push_back(muneco);

for (int p = 0; (p < trans)&&(error == false); p++){
fich >> (char &) letrita >> (unsigned &) estsig;
muneco2.entr = letrita;
muneco2.next_estado = estsig;
VT[est].push_back(muneco2);
}
}
}

if (error == true){
}
else{
for (int a = 0; a < cantidad; a++){
for (int s = 0; s < trans-1; s++){
for (int d = s+1; d < trans-1; d++){
if (VT[a][s].entr == VT[a][d].entr){
cout << "\n¡ERROR!Algún estado tiene más de una transición para el mismo símbolo.¡ERROR!\nVuelva a cargar el fichero" << endl;
error = true;
}
}
}
}
}

if (error == false){
cout << "\nEl fichero se ha cargado correctamente." << endl;
}
}


/*
for (int q = 0; q < cantidad; q++){
for (int y = 0; y < trans-1; y++){
for (int t = 0; t < trans-1; t++){
if (VT[q][y].entr == VT[q][y+t+1].entr){
cout << "\nAlgún estado tiene más de una transición para el mismo símbolo." << endl;
exit(EXIT_FAILURE);
}
}
}
}
*/


DFA::~DFA(){
VE.clear();
VT.clear();
cantidad = 0;
inicial = 0;
}

void DFA::mDFA (void){
cout << "\nEl DFA leido tiene la siguiente estructura:";
cout << "\nTiene " << cantidad << " estados.";
cout << "\nEl estado inicial es el " << inicial << ".";
for (int i = 0; i < cantidad; i++){
cout << "\nEl estado " << VE[i].estado << " es de ";
if(VE[i].tipo == 0){ 
cout << "no aceptación";
}
else{
cout << "aceptación";
}
cout << " y tiene " << VE[i].ctr << " transiciones.";
for (int p = 0; p < VE[i].ctr; p++){
cout << endl << VT[i][p].entr << " ---> " << VT[i][p].next_estado;
}
}
cout << endl << endl;
}

void DFA::mestadosmuerte (void){
int ninguno = 0;
bool emuerte = false;
int estadosmuerte[cantidad];

for (int i = 0; i < cantidad; i++){
if (VE[i].tipo == 0){
emuerte = true;
}
for (int p = 0; (p < VE[i].ctr) && (emuerte == true); p++){
if (VT[i][p].next_estado != i){
emuerte = false;
}
}
if (emuerte == true){
estadosmuerte[i] = 1;
cout << "\nEl estado " << i << " es un estado de muerte.";
}
if (estadosmuerte[i] == 0){
ninguno++;
}
}

if (ninguno == cantidad){
cout << "\nNinguno de los estados analizados es de muerte.";
}
cout << endl << endl;
} 
	
void DFA::acadena (void){

char *cadena = new char [50];
bool palfabeto = true;
bool vueltamenu = false;

cout << "\nIntroduzca la cadena a analizar: ";
cin >> cadena;

for (int e = 0; (e < strlen(cadena))&&(vueltamenu == false); e++){
palfabeto = false;

for (int w = 0; (w < VE[0].ctr)&&(palfabeto == false); w++){
if (VT[0][w].entr == cadena[e]){
palfabeto = true;
}
}
if (palfabeto == false){
cout << "\nEl símbolo " << cadena[e] << " no pertenece al alfabeto." << endl;
delete [] cadena;
vueltamenu = true;
}
}
if (vueltamenu == false){
unsigned actual = inicial;
unsigned siguiente = 0;
bool encontrado;


cout << "\nCadena de entrada: " << cadena << endl;
cout << "Estado actual			Entrada			Siguiente estado" << endl; 
for (int q = 0; q < strlen(cadena); q++){
encontrado = false;
for (int w = 0; (w < VE[0].ctr)&&(encontrado == false); w++){
if (VT[actual][w].entr == cadena[q]){
siguiente = VT[actual][w].next_estado;
encontrado = true;
}
}
cout << "	" << actual << "			" << cadena[q] << "				" << siguiente << endl;
actual = siguiente;
}


if (VE[actual].tipo == 1){
cout << "\nCadena de entrada ACEPTADA." << endl;
}
else{
cout << "\nCadena de entrada NO ACEPTADA." << endl;
}

}
}

//Rafael Herrero Álvarez