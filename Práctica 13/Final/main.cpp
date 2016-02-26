//
//  main.cpp
//  ordenacionporfusion
//
//  Created by Rafael Herrero on 08/12/14.
//  Copyright (c) 2014 Rafael Herrero. All rights reserved.
//

#include <iostream>
#include "merge.cpp"
using namespace std;

int main(void) {
    
    mergeordenar mergerito;
   
    unsigned ctnum=0;
    double copia;
    
    vector <int> numeros;
    
    cout << "Introduzca la cantidad de números que desea ordenar: " << endl;
    cin >> ctnum;
    
    
    
    cout << "Introduzca los números que desea ordenar: " << endl;
    for (int i=0; i<ctnum; i++){
        cin >> copia;
        numeros.push_back(copia);
    }
    
 
    mergerito.ordenacionporfusion(numeros);
    
    for (int i=0; i<ctnum; i++){
        cout << numeros[i] << " " ;
    }
    
}
