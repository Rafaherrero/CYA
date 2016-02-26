//
//  Cambio.cpp
//  Monedas
//
//  Created by Rafael Herrero on 28/11/14.
//  Copyright (c) 2014 Rafael Herrero. All rights reserved.
//

#include "Cambio.h"

using namespace std;

cambio::cambio(){
    monedas.push_back(200);
    monedas.push_back(100);
    monedas.push_back(50);
    monedas.push_back(20);
    monedas.push_back(10);
    monedas.push_back(5);
    monedas.push_back(2);
    monedas.push_back(1);
    
    billetes.push_back(50000);
    billetes.push_back(20000);
    billetes.push_back(10000);
    billetes.push_back(5000);
    billetes.push_back(2000);
    billetes.push_back(1000);
    billetes.push_back(500);
    
    ambos.insert(ambos.begin(), monedas.begin(), monedas.end());
    ambos.insert(ambos.begin(), billetes.begin(), billetes.end());
    
    
}

cambio::~cambio(){
    
}

void cambio::cambio_monedas(){
    system("clear");
    string dinero;
    double pedida, pedidadecimal;
    long int money, pedidafinal ,calculo=0;
    unsigned long x;
    int error=0;
    int k=0, n=0;
    int cantidadmonedas=0;
    bool fin = false, control = false;
    char opcionct[1];
    cartera.clear();
    estructura_de_cambio ct;
    
    cout << "Seleccione si desea introducir la cantidad en euros o en céntimos. (c/e)" << endl;
    cin >> opcionct;
    if (opcionct[0] == 'e'){
        cout << "Introduzca aquí la cantidad de dinero en euros que quiere convertir en monedas: " << endl;
        cin >> pedida;
        money = int(pedida);
        pedidadecimal = (pedida-money);
        pedidafinal = float(pedidadecimal*100);
        money=(money*100)+(pedidafinal);

    }
    else if(opcionct[0] == 'c'){
        cout << "Introduzca aquí la cantidad de dinero en céntimos que quiere convertir en monedas: " << endl;
        cin >> pedida;
        money = int(pedida);
    }
    else{
        error = 123;
        cout << "\n¡ERROR! Ha introducido algo que no es un número positivo o entero." << endl;
        error=123;
        cout << "\nPresione ENTER para volver al menú principal" << endl;
        cin.get();
        cin.ignore();
    }

//    
//    cout << "Introduzca aquí la cantidad de dinero que quiere convertir en monedas: " << endl;
//    cin >> dinero;
//    x = dinero.length();
//    if (error != 123){
//        for (int i=0;i<x && error != 123;i++){
//            if(dinero[i] >= '0' && dinero[i] <= '9'){
//                money=atoi(dinero.c_str());
//                
//            }
//            else{
//                cout << "\n¡ERROR! Ha introducido algo que no es un número positivo o entero." << endl;
//                error=123;
//                cout << "\nPresione ENTER para volver al menú principal." << endl;
//                cin.get();
//                cin.ignore();
//            }
//        }
//    }
    
    if (error != 123){
        calculo=money;
        
        while (fin==false) {
            
            calculo=calculo-monedas[k];
            
            if (calculo > 0){
                
                cantidadmonedas++;
                control=true;
                
            }

            if (calculo < 0){
                if (control==true){
                    ct.valor=monedas[k];
                    ct.cantidad=cantidadmonedas;
                    cartera.push_back(ct);
                }
                cantidadmonedas=0;
                control=false;
                calculo=calculo+monedas[k];
                k++;
                
            }
            
           
            
            if (calculo==0){
                cantidadmonedas++;
                        ct.valor=monedas[k];
                        ct.cantidad=cantidadmonedas;
                        cartera.push_back(ct);

                fin = true;
                
            }
            
            
        }
        
        
        cout << "\nEl cambio en monedas quedaría de la siguiente manera: " << endl;
        for (int i =0; i<cartera.size();i++) {
            if (cartera[i].cantidad == 1){
                if (cartera[i].valor==1) {
                cout << cartera[i].cantidad << " moneda de " << cartera[i].valor << " céntimo." << endl;
                n=n+cartera[i].cantidad;
            }
                else if (cartera[i].valor == 200){
                    cout << cartera[i].cantidad << " moneda de " << cartera[i].valor/100 << " euros." << endl;
                    n=n+cartera[i].cantidad;
                    
                }
                else if (cartera[i].valor == 100){
                    cout << cartera[i].cantidad << " moneda de " << cartera[i].valor/100 << " euro." << endl;
                    n=n+cartera[i].cantidad;
                    
                }
                else{
                    cout << cartera[i].cantidad << " moneda de " << cartera[i].valor << " céntimos." << endl;
                    n=n+cartera[i].cantidad;
                }
            }
        
            else{
                if (cartera[i].valor==1) {
                    cout << cartera[i].cantidad << " monedas de " << cartera[i].valor << " céntimo." << endl;
                    n=n+cartera[i].cantidad;
                }
                else if (cartera[i].valor == 200){
                    cout << cartera[i].cantidad << " monedas de " << cartera[i].valor/100 << " euros." << endl;
                    n=n+cartera[i].cantidad;
                    
                }
                else if (cartera[i].valor == 100){
                    cout << cartera[i].cantidad << " monedas de " << cartera[i].valor/100 << " euro." << endl;
                    n=n+cartera[i].cantidad;
                }
                else{
            cout << cartera[i].cantidad << " monedas de " << cartera[i].valor << " céntimos." << endl;
                n=n+cartera[i].cantidad;
            }
            }
        }
        if (n==1){
        cout << "Hay un total de " << n << " moneda." << endl;
        }
        else{
        cout << "Hay un total de " << n << " monedas." << endl;
        }
            
        cout << "\nPresione ENTER para volver al menú principal" << endl;
        cin.get();
        cin.ignore();
    }
}




void cambio::cambio_billetes(){
    system("clear");
    string dinero;
    double pedida, pedidadecimal;
    long int money, pedidafinal ,calculo=0;
    unsigned long x;
    int error=0;
    int k=0, n=0;
    int cantidadbilletes=0;
    bool fin = false, control = false;
    char opcionct[1];
    cartera.clear();
    estructura_de_cambio ct;
    
    cout << "Seleccione si desea introducir la cantidad en euros o en céntimos. (c/e)" << endl;
    cin >> opcionct;
    if (opcionct[0] == 'e'){
    cout << "Introduzca aquí la cantidad de dinero en euros que quiere convertir en billetes: " << endl;
    cin >> pedida;
        money = int(pedida);
        pedidadecimal = (pedida-money);
        pedidafinal = float(pedidadecimal*100);
        money=(money*100)+(pedidafinal);

    }
    else if(opcionct[0] == 'c'){
    cout << "Introduzca aquí la cantidad de dinero en céntimos que quiere convertir en billetes: " << endl;
    cin >> pedida;
        money = int(pedida);
    }
    else{
        error = 123;
        cout << "\n¡ERROR! Ha introducido algo que no es un número positivo o entero." << endl;
            error=123;
            cout << "\nPresione ENTER para volver al menú principal" << endl;
            cin.get();
            cin.ignore();
    }

//    x = dinero.length();
//
//    if (error != 123){
//    for (int i=0;i<x && error != 123;i++){
//        if(dinero[i] >= '0' && dinero[i] <= '9'){
//            pedida=atof(dinero.c_str());
//            cout << pedida << endl;
//            money = int(pedida *100);
//            cout << money << endl;
//
//        }
//        else{
//            cout << "\n¡ERROR! Ha introducido algo que no es un número positivo o entero." << endl;
//            error=123;
//            cout << "\nPresione ENTER para volver al menú principal" << endl;
//            cin.get();
//            cin.ignore();
//        }
//    }
//    }
    
    if (error != 123){
         calculo=money;

        while (fin==false) {
            
            calculo=calculo-billetes[k];
            
            if (calculo > 0){
                cantidadbilletes++;
                control=true;
                
            }
            
            if (calculo < 0){
                if (control==true){
                    ct.valor=billetes[k];
                    ct.cantidad=cantidadbilletes;
                    cartera.push_back(ct);
                }
                cantidadbilletes=0;
                control=false;
                calculo=calculo+billetes[k];
                k++;
                
            }
            
           
            
            if (calculo <= 500||calculo==0){
                if (money < 500){
                    
                }
                else{
                    if (money == 500){
                        calculo=0;
                        ct.valor=500;
                        ct.cantidad=1;
                        cartera.push_back(ct);
                    }
                    else{
                        
                        ct.valor=billetes[k];
                        ct.cantidad=cantidadbilletes;
                        cartera.push_back(ct);
                        if (calculo == 500){
                            calculo=0;
                            ct.valor=500;
                            ct.cantidad=1;
                            cartera.push_back(ct);
                        }
                    }
                }
                fin = true;
                
            }
            
            
        }

            

        
    
    cout << "\nEl cambio en billetes quedaría de la siguiente manera: " << endl;
    if (cartera.size()==0){
        cout << "\nNo se ha detectado una cantidad mayor a 5€, por lo que su cambio serían: " << calculo << " céntimos." << endl;
    }
    else{
        for (int i =0; i<cartera.size();i++) {
            if (cartera[i].cantidad==1){
                cout << cartera[i].cantidad << " billete de " << cartera[i].valor/100 << " euros." << endl;
                n=n+cartera[i].cantidad;
            }
            else{
            cout << cartera[i].cantidad << " billetes de " << cartera[i].valor/100 << " euros." << endl;
                n=n+cartera[i].cantidad;
        }
        }
        if(calculo != 0){
            cout << "Han sobrado " << calculo << " céntimos." << endl;
        }
        if (n==1){
        cout << "Hay un total de " << n << " billete." << endl;
    }
        else{
        cout << "Hay un total de " << n << " billetes." << endl;
        }
    }
        
    cout << "\nPresione ENTER para volver al menú principal" << endl;
    cin.get();
    cin.ignore();
    }
}


void cambio::cambio_ambos(){
    system("clear");
    string dinero;
    double pedida, pedidadecimal;
    long int money, pedidafinal, calculo=0;
    unsigned long x;
    int error=0;
    int k=0, b=0, m=0;
    int cantidadambos=0;
    bool fin = false, control = false;
    char opcionct[1];
    cartera.clear();
    estructura_de_cambio ct;
    
    cout << "Seleccione si desea introducir la cantidad en euros o en céntimos. (c/e)" << endl;
    cin >> opcionct;
    if (opcionct[0] == 'e'){
        cout << "Introduzca aquí la cantidad de dinero en euros que quiere convertir en billetes y monedas: " << endl;
        cin >> pedida;
        money = int(pedida);
        pedidadecimal = (pedida-money);
        pedidafinal = float(pedidadecimal*100);
        money=(money*100)+(pedidafinal);
    }
    else if(opcionct[0] == 'c'){
        cout << "Introduzca aquí la cantidad de dinero en céntimos que quiere convertir en billetes y monedas: " << endl;
        cin >> pedida;
        money = int(pedida);
    }
    else{
        error = 123;
        cout << "\n¡ERROR! Ha introducido algo que no es un número positivo o entero." << endl;
        error=123;
        cout << "\nPresione ENTER para volver al menú principal" << endl;
        cin.get();
        cin.ignore();
    }

//    
//    cout << "Introduzca aquí la cantidad de dinero que quiere convertir en billetes y monedas: " << endl;
//    cin >> dinero;
//    x = dinero.length();
//    if (error != 123){
//        for (int i=0;i<x && error != 123;i++){
//            if(dinero[i] >= '0' && dinero[i] <= '9'){
//                money=atoi(dinero.c_str());
//                
//            }
//            else{
//                cout << "\n¡ERROR! Ha introducido algo que no es un número positivo o entero." << endl;
//                error=123;
//                cout << "\nPresione ENTER para volver al menú principal." << endl;
//                cin.get();
//                cin.ignore();
//            }
//        }
//    }
    
    if (error != 123){
        calculo=money;
        
        while (fin==false) {
            
            calculo=calculo-ambos[k];
            
            if (calculo > 0){
                
                cantidadambos++;
                control=true;
                
            }
            
            if (calculo < 0){
                if (control==true){
                    ct.valor=ambos[k];
                    ct.cantidad=cantidadambos;
                    cartera.push_back(ct);
                }
                cantidadambos=0;
                control=false;
                calculo=calculo+ambos[k];
                k++;
                
            }
            
            if (calculo==0){
                cantidadambos++;
                ct.valor=ambos[k];
                ct.cantidad=cantidadambos;
                cartera.push_back(ct);
                
                fin = true;
                
            }
            
            
        }
        
        
        cout << "\nEl cambio en monedas quedaría de la siguiente manera: " << endl;
        for (int i =0; i<cartera.size();i++) {
            if (cartera[i].valor >= 500) {
                if (cartera[i].cantidad == 1){
                    cout << cartera[i].cantidad << " billete de " << cartera[i].valor/100 << " euros." << endl;
                    b=b+cartera[i].cantidad;
                }
                else{
                    cout << cartera[i].cantidad << " billetes de " << cartera[i].valor/100 << " euros." << endl;
                    b=b+cartera[i].cantidad;
                }
                
            
            }
            else{
            if (cartera[i].cantidad == 1){
                if (cartera[i].valor==1) {
                    cout << cartera[i].cantidad << " moneda de " << cartera[i].valor << " céntimo." << endl;
                    m=m+cartera[i].cantidad;
                }
                else if (cartera[i].valor == 200){
                    cout << cartera[i].cantidad << " moneda de " << cartera[i].valor/100 << " euros." << endl;
                    m=m+cartera[i].cantidad;

                }
                else if (cartera[i].valor == 100){
                    cout << cartera[i].cantidad << " moneda de " << cartera[i].valor/100 << " euro." << endl;
                    m=m+cartera[i].cantidad;
                    
                }
                else{
                cout << cartera[i].cantidad << " moneda de " << cartera[i].valor << " céntimos." << endl;
                m=m+cartera[i].cantidad;
                }
            }
            else{
                if (cartera[i].valor==1) {
                    cout << cartera[i].cantidad << " moneda de " << cartera[i].valor << " céntimo." << endl;
                    m=m+cartera[i].cantidad;
                }
                else if (cartera[i].valor == 200){
                    cout << cartera[i].cantidad << " monedas de " << cartera[i].valor/100 << " euros." << endl;
                    m=m+cartera[i].cantidad;
                    
                }
                else if (cartera[i].valor == 100){
                    cout << cartera[i].cantidad << " monedas de " << cartera[i].valor/100 << " euro." << endl;
                    m=m+cartera[i].cantidad;
                    
                }
                else{
                cout << cartera[i].cantidad << " monedas de " << cartera[i].valor << " céntimos." << endl;
                m=m+cartera[i].cantidad;
                }
            }
        }
        }
        if (b==1&&m==1) {
            cout << "Hay un total de " << b << " billete y " << m << " moneda." << endl;

        }
        if (b != 1 && m == 1){
        cout << "Hay un total de " << b << " billetes y " << m << " moneda." << endl;
        }
        if ( b != 1 && m != 1){
        cout << "Hay un total de " << b << " billetes y " << m << " monedas." << endl;
        }
        if (b == 1 && m != 1){
            cout << "Hay un total de " << b << " billete y " << m << " monedas." << endl;
        }
        
        cout << "\nPresione ENTER para volver al menú principal" << endl;
        cin.get();
        cin.ignore();
    }

    
}