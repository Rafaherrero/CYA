//
//  main.cpp
//  Monedas
//
//  Created by Rafael Herrero on 28/11/14.
//  Copyright (c) 2014 Rafael Herrero. All rights reserved.
//

#include "Cambio.cpp"
using namespace std;

int main() {
    char opcion[10] = "0";
   
    
    cambio cambito;
        while (opcion[0] != 'a'){
            system ("clear");
            cout << "\nMoney Money v3.2.13" << endl;
            cout << "\nEste programa le permitirá conocer el cambio en monedas o billetes de una cantidad dada en céntimos." << endl;
            cout << "\nMenú de opciones del cambio de dinero." << endl;
            cout << "b. Cambio en [b]illetes." << endl;
            cout << "m. Cambio en [m]onedas." << endl;
            cout << "c. [c]ambio en billetes y monedas." << endl;
            cout << "a. [a]bandonar el programa." << endl;
            cout << "Introduzca una opción: " << endl;
            cin >> opcion;
            while (opcion[0] != 'b' && opcion[0] != 'm' && opcion[0] != 'c' && opcion[0] != 'a'){
                cout << endl << "La opción introducida no es correcta. Introduzca otra: " << endl;
                cin >> opcion;
            }
            
            switch (opcion[0]){
                case 'b':   cambito.cambio_billetes();
                    break;
                case 'm':   cambito.cambio_monedas();
                    break;
                case 'c':   cambito.cambio_ambos();
                    break;
                case 'a': cout << "\n¡Hasta pronto!\n" << endl,
                    exit(0);
            }
        }
    }

