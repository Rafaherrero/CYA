#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

typedef struct{
	unsigned estado; //numero de estado
	unsigned tipo; //tipo de estado (no aceptacion o si)
	unsigned ctr; //cantidad de transiciones
} EL_estado;

typedef struct{
	char entr; //entrada
	int next_estado; //estado al que me piro
} LA_transi;
typedef vector<LA_transi> LA_transicion;

class DFA{
	
	private:
	
	unsigned cantidad; //numero de estados
	unsigned inicial; //estado inicial
	vector<EL_estado> VE; //vector de estados
	vector<LA_transicion> VT; //vector de transiciones
	
typedef struct
{
unsigned j; // nodo
int c; // atributo para expresar su peso, longitud, coste…
} ElementoLista;
typedef vector<ElementoLista> LA_nodo;

class GRAFO{

private:

unsigned n; // número de nodos o vértices
unsigned m; // número de arcos o aristas
vector<LA_nodo> LS; // lista de sucesores o de adyacencia
vector<LA_nodo> LP; // lista de predecesores

public:
unsigned dirigido; //0 si el grafo es no dirigido,1 si es dirigido
GRAFO(char nombrefichero[], int &errorapertura);
void actualizar (char nombrefichero[], int &errorapertura);
void Info_Grafo();
void Mostrar_Listas(int l);
void ListaPredecesores();
~GRAFO();


};
