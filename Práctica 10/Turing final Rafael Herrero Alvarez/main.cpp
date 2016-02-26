
//  main.cpp
//  Turing
//
//  Created by Rafael Herrero on 15/11/14.
//  Copyright (c) 2014 Rafael Herrero. All rights reserved.
//

#include "tmtm.cpp"
using namespace std;

int main (void){
    char opcion = 0;
    char nombrefichero[50] = "";
    int errorapertura;
    
    cout << "\nTuring Machine v1.3.45" << endl;
    cout << "\nEste programa le permitirá trabajar con máquinas de Turing." << endl;
    
   TURING turincito;
    
    while (errorapertura == 0){
        while (opcion != 'a'){
            cout << "\nMenú de opciones de la máquina de Turing." << endl;
            cout << "l. [l]eer fichero de Máquina de Turing" << endl;
            cout << "m. [m]ostrar Máquina de Turing." << endl;
            cout << "s. [s]imular Máquina de Turing." << endl;
            cout << "a. [a]bandonar el programa." << endl;
            cout << "Introduzca una opción: " << endl;
            cin >> opcion;
            while (opcion != 'l' && opcion != 'm' && opcion != 's' && opcion != 'a'){
                cout << endl << "La opción introducida no es correcta. Introduzca otra: " << endl;
                cin >> opcion;
            }
            
            switch (opcion){
                case 'l': turincito.actualizar (nombrefichero, errorapertura);
                    break;
                case 'm': turincito.mTM (nombrefichero, errorapertura);
                    break;
                case 's': turincito.simulacion (nombrefichero, errorapertura);
                    break;
                case 'a': cout << "\n¡Hasta pronto!\n" << endl,
                    errorapertura = 12345;
            }
        }
    }
}

