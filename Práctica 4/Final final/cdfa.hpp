#include <fstream>
#include <vector>
#include <iostream>
#include <cstring>
#include <cstdlib>

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
	
	public: 
	
	DFA (char nombrefichero[], int &errorapertura);
	void actualizar (char nombrefichero[], int &errorapertura);
	~DFA (void);
	void mDFA (void);
	void mestadosmuerte (void);
	void acadena (void);
	};
	
//Rafael Herrero Álvarez