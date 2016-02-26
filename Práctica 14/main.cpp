//
//  main.cpp
//  ordenacionporfusion
//
//  Created by Rafael Herrero on 08/12/14.
//  Copyright (c) 2014 Rafael Herrero. All rights reserved.
//

#include "merge.cpp"
using namespace std;

int main(void) {
    
    mergeordenar mergerito;
   
    char nombrefichero[30];
    unsigned ctnum=0;
    int copia;
    
    vector <int> numeros;
    
    cout << "Introduzca el nombre del fichero: " << endl;
    cin >> nombrefichero;
    fstream fich;
    fich.open(nombrefichero);
    if (!fich.is_open()) {
        cout << "\nError en la apertura del fichero." << endl;
        exit (0);
    }
    else{
        cout << "\nEl fichero se ha cargado correctamente.\n" << endl;
        fich >> (unsigned &) ctnum;
        for (int w=0; w<ctnum; w++){
            fich >> (unsigned &) copia;
            numeros.push_back(copia);
        }
        
    }
    
    mergerito.ordenacionporfusion(numeros);
    
    cout << endl;
    for (int i=0; i<ctnum; i++){
        cout << "\e[0;36m" << numeros[i] << " " << "\e[0m";
    }
    cout << endl << endl;
    
}
