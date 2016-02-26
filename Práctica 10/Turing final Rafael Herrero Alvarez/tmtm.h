//
//  tmtm.h
//  Turing
//
//  Created by Rafael Herrero on 15/11/14.
//  Copyright (c) 2014 Rafael Herrero. All rights reserved.
//

#include <stdio.h>
#include <fstream>
#include <vector>
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

// En esta estructura almacenamos la t-upla
typedef struct{
    char entrada;
    char escribe;
    char movimiento;
    unsigned siguienteestado;
} Estadito;

typedef vector<Estadito> Vectordeestados;

class TURING{
    
private:
    
    unsigned cantidaddeestados;
    unsigned estadosfinales;
    unsigned tutiplen;
    vector<Vectordeestados> VDE;
    
public:
    
    TURING ();
    void actualizar (char nombrefichero[], int &errorapertura);
    void comprobarerrores (char nombrefichero[], int &errorapertura);
    ~TURING (void);
    void mTM (char nombrefichero[], int &errorapertura);
    void simulacion (char nombrefichero[], int &errorapertura);
};