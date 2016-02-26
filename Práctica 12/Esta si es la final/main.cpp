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
        while (opcion[0] != 's'){
            system ("clear");
            cout << "\nMoney Money v4.3.01" << endl;
            cout << "\nEste programa le permitirá conocer el cambio en monedas o billetes de una cantidad dada en céntimos o en euros." << endl;
            cout << "\nMenú de opciones del cambio de dinero." << endl;
            cout << "b. Cambio en [b]illetes." << endl;
            cout << "m. Cambio en [m]onedas." << endl;
            cout << "a. Cambio en [a]mbos." << endl;
            cout << "s. [s]alir del programa." << endl;
            cout << "Introduzca una opción: " << endl;
            cin >> opcion;
            while (opcion[0] != 'b' && opcion[0] != 'm' && opcion[0] != 'a' && opcion[0] != 's'){
                cout << endl << "La opción introducida no es correcta. Introduzca otra: " << endl;
                cin >> opcion;
            }
            
            switch (opcion[0]){
                case 'b':   cambito.cambio_billetes();
                    break;
                case 'm':   cambito.cambio_monedas();
                    break;
                case 'a':   cambito.cambio_ambos();
                    break;
                case 's': cout << "\n¡Hasta pronto!\n" << endl,
                    exit(0);
            }
        }
    }

