//
//  tmtm.cpp
//  Turing
//
//  Created by Rafael Herrero on 15/11/14.
//  Copyright (c) 2014 Rafael Herrero. All rights reserved.
//

#include "tmtm.h"
using namespace std;

TURING::TURING (){
    
}

void TURING::actualizar(char nombrefichero[], int &errorapertura){
    
    comprobarerrores (nombrefichero, errorapertura);
    if (errorapertura==0){
    VDE.clear();
    Estadito playa;
    unsigned est, final, sigest, ctest, tuplas;
    char entr, escr, mov;
    est = 0;
    
    //cout << endl << "Introduzca el nombre del fichero: " << endl;
    //cin >> nombrefichero;
    ifstream fich;
    fich.open(nombrefichero);
    //if (!fich.is_open()) {
      //  cout << "\nError en la apertura del fichero. ¿Error en el nombre?" << endl;
        //errorapertura = 13;
    //}
    
    //else{
      //  errorapertura=0;
        cout << "\nEl fichero se ha abierto correctamente" << endl;
        fich >> (unsigned &) ctest >> (unsigned &) final >> (unsigned &) tuplas;
        VDE.resize(final+1);
        
        cantidaddeestados=ctest;
        estadosfinales=final;
        tutiplen=tuplas;
        
        for (int i=0;(i<tuplas); i++ ){
            fich >> (unsigned &) est >> (char &) entr >> (char &) escr >> (char &) mov >> (unsigned &) sigest;
            playa.entrada = entr;
            playa.escribe = escr;
            playa.movimiento = mov;
            playa.siguienteestado = sigest;
            VDE[est].push_back(playa);
        }
       }
}

void TURING::comprobarerrores(char *nombrefichero, int &errorapertura){
    
    string estados, finales, tuplas, estadoactual, entrada, escribimosjuntitos, movimiento, estadosiguiente;
    unsigned long x = 0;
    int numtuplas = 0;
    int numfin = 0;
    int numest = 0;
    int numestactual = 0;
    int numestsig = 0;
    
    estados.clear();
    finales.clear();
    tuplas.clear();
    estadoactual.clear();
    entrada.clear();
    escribimosjuntitos.clear();
    movimiento.clear();
    estadosiguiente.clear();
    errorapertura = 0;
    
    cout << endl << "Introduzca el nombre del fichero: " << endl;
    cin >> nombrefichero;
    ifstream fich;
    fich.open(nombrefichero);
    if (!fich.is_open()) {
    cout << "\n¡ERROR! Error en la apertura del fichero. ¿Error en el nombre?" << endl;
    errorapertura = 13;
    }
    else{
        fich >> (string &) estados;
        x = estados.length();
        for (int i=0;i<x && errorapertura==0;i++){
            if (estados[i] >= '0' && estados[i] <= '9'){
                numest=atoi(estados.c_str());
            }
            else{
                cout <<"\n¡ERROR! Se ha introducido un valor no válido para la cantidad de estados" << endl;
                errorapertura = 13;
            }
        }
        if (errorapertura == 0){
        fich >> (string &) finales;
        x = finales.length();
        for (int i=0;i<x && errorapertura==0;i++){
            if (finales[i] >= '0' && finales[i] <= '9'){
            }
            else{
                cout << "\n¡ERROR! Se ha introducido un valor no válido para el/los estado/s final/es" << endl;
                errorapertura = 13;
            }
        }
        numfin=atoi(finales.c_str());
            if (numfin>=numest && errorapertura==0){
                cout << "\n¡ERROR! El número de estado/s final/es es mayor que el número de estado/s" << endl;
                errorapertura = 13;
            }
            if (numfin==0 && errorapertura==0){
                cout << "\n¡ERROR! El estado final es el 0" << endl;
                errorapertura = 13;
            }
        }
        
        if (errorapertura == 0){
        fich >> (string &) tuplas;
        x = tuplas.length();
        for (int i=0;i<x && errorapertura==0;i++){
            if (tuplas[i] >= '0' && tuplas[i] <= '9'){
            }
            else{
                cout << "\n¡ERROR! Se ha introducido un valor no válido para la cantidad de tuplas" << endl;
                errorapertura = 13;
            }
    }
    }
        if (errorapertura == 0){
        numtuplas=atoi(tuplas.c_str());
        for (int i=0;i<numtuplas && errorapertura==0;i++){
            fich >> (string &) estadoactual >> (string &) entrada >> (string &) escribimosjuntitos >> (string &) movimiento >> (string &) estadosiguiente;
            x = estadoactual.length();

            for (int j=0; j<x; j++){
                if (i==0&&estadoactual[0]!='0'){
                    cout << "\n¡ERROR! La primera transición no es desde el estado 0" << endl;
                    errorapertura = 13;
                }
            
                if(errorapertura == 0){
                if (estadoactual[j] >= '0' && estadoactual[j] <= '9'){
                }
                else{
                    cout << "\n¡ERROR! El estado de la tupla " << i+1 << " no tiene un número por estado" << endl;
                    errorapertura = 13;
                }
                }
            }
            
            numestactual=atoi(estadoactual.c_str());
            if (numestactual == numfin && errorapertura==0){
                cout << "\n¡ERROR! Hay un estado que es igual al estado de aceptación en la tupla " << i+1 << endl;
                errorapertura=13;
            }
            
            if (numestactual > numfin && errorapertura==0){
                cout << "\n¡ERROR! Hay un estado que es mayor al estado de aceptación en la tupla " << i+1 << endl;
                errorapertura=13;
            }
            
            if (entrada.length()>1&&errorapertura==0){
                cout << "\n¡ERROR! La longitud de la entrada de la tupla " << i+1 << " es mayor a 1" << endl;
                errorapertura = 13;
                }
            
            if (escribimosjuntitos.length()>1&&errorapertura==0){
                cout << "\n¡ERROR! La longitud de la escritura de la tupla " << i+1 << " es mayor a 1" << endl;
                errorapertura = 13;
            }
            
            if (movimiento.length()>1&&errorapertura==0){
                cout << "\n¡ERROR! La longitud de movimiento de la tupla " << i+1 << " es mayor a 1" << endl;
                errorapertura = 13;
            }
            
            if (errorapertura==0 && movimiento[0] != 'L' && movimiento[0] != 'R' && movimiento[0] != 'S'){
                cout << "\n¡ERROR! El movimiento de la tupla " << i+1 << " es ilegal" << endl;
                errorapertura = 13;
            }
            
            x = estadosiguiente.length();
            for (int j=0; j<x&&errorapertura==0; j++){
                
                if(errorapertura == 0){
                    if (estadosiguiente[j] >= '0' && estadosiguiente[j] <= '9'){
                    }
                    else{
                        cout << "\n¡ERROR! La transición de la tupla " << i+1 << " no tiene un número por estado siguiente" << endl;
                        errorapertura = 13;
                    }
                }
            }
            numestsig=atoi(estadosiguiente.c_str());
            if (numestsig > numfin && errorapertura==0){
                cout << "\n¡ERROR! Hay una transición a un estado que es mayor al estado de aceptación en la tupla " << i+1 << endl;
                errorapertura=13;
            }

            }
        }
    }
}


void TURING::simulacion(char *nombrefichero, int &errorapertura){
    
    if ((strncmp(nombrefichero, "", 50) == 0) || errorapertura == 13){
        cout << "\nOpción no válida. No ha introducido nombre de fichero o no es válido." << endl;
        actualizar(nombrefichero, errorapertura);
    }
    else{
    vector<char> cintaVHS;
    cintaVHS.clear();
    long int cabezal = 1;
    long int estactual = 0;
    string copiacadena;
        char pasitos;
    copiacadena.clear();
    bool encontrado = false;
        bool baned = false;
        int cnt = 1;
    
    cout << "\nIntroduzca la cadena a analizar:" << endl;
    cin >> copiacadena;
    for (int i=0; i<copiacadena.length(); i++){
        cintaVHS.push_back(copiacadena[i]);
    }
    cintaVHS.insert(cintaVHS.begin(), '$');
    cintaVHS.push_back('$');
        cout << "\n¿Desea ejecutar la máquina paso por paso?(s/n)" << endl;
        cin >> pasitos;

        //for (int k=0; k < cintaVHS.size();k++){
        //    cout << cintaVHS[k];
        //}
        //cout << endl;
        
        if (pasitos=='s') {
            cout << endl;
            cout << "PASO " << cnt << ":" << endl;
            cout << "ESTADO ACTUAL " << estactual << ":" << endl;
            for (int k=0; k < cintaVHS.size();k++){
                cout << cintaVHS[k];
            }
            cout << endl;
            for (int lsd=0; lsd < cabezal; lsd++){
                cout << " ";
            }
            cout << "^";
            cnt++;
        }

            while ((estactual<estadosfinales)&&baned==false) {

        encontrado=false;
        baned=true;
        for (int j=0; j<VDE[estactual].size()&&encontrado==false;j++){
            
        if ((cintaVHS[cabezal]==VDE[estactual][j].entrada)||((VDE[estactual][j].entrada == '!')&&(cintaVHS[cabezal]!='$'))){
            if (VDE[estactual][j].escribe == '!'){
                
            }
            else{
                
            cintaVHS[cabezal]=VDE[estactual][j].escribe;
    
            }
            baned=false;
            encontrado=true;
            if (VDE[estactual][j].movimiento=='L'){
                cabezal--;
                if (cabezal < 0){
                    cabezal=0;
                    cintaVHS.insert(cintaVHS.begin(), '$');
                }
                else if (cabezal >= cintaVHS.size()){
                    cintaVHS.push_back('$');
                }
            }
            if (VDE[estactual][j].movimiento=='R'){
                cabezal++;
                if (cabezal < 0){
                    cabezal=0;
                    cintaVHS.insert(cintaVHS.begin(), '$');
                }
                else if (cabezal+1 >= cintaVHS.size()){
                    cintaVHS.push_back('$');
                }
            }
                if (VDE[estactual][j].movimiento=='S'){
                    
                }
             estactual=VDE[estactual][j].siguienteestado;
            }

           
        }
                if (pasitos=='s') {
                    cout << endl;
                    cout << "PASO " << cnt << ":" << endl;
                    cout << "ESTADO ACTUAL " << estactual << ":" << endl;
                for (int k=0; k < cintaVHS.size();k++){
                        cout << cintaVHS[k];
                    }
                    cout << endl;
                    for (int lsd=0; lsd < cabezal; lsd++){
                        cout << " ";
                    }
                    cout << "^";
                    cnt++;
                }

    }
        
        if(baned == true){
            cout << "\nCadena rechazada" << endl;
        }
        else{
            cout << "\nCadena aceptada" << endl;
        }
    }
}



void TURING::mTM(char *nombrefichero, int &errorapertura){
    long int x = 0;
    if ((strncmp(nombrefichero, "", 50) == 0) || errorapertura == 13){
        cout << "\nOpción no válida. No ha introducido nombre de fichero o no es válido." << endl;
        actualizar(nombrefichero, errorapertura);
    }
    else{
        cout << endl <<cantidaddeestados << endl;
        cout << estadosfinales << endl;
        cout << tutiplen << endl;
        for (int i = 0; i < cantidaddeestados; i++){
            x = VDE[i].size();
            for (int j = 0; j < x; j++){
                cout << i << " " << VDE[i][j].entrada << " " << VDE[i][j].escribe << " " << VDE[i][j].movimiento << " " << VDE[i][j].siguienteestado << endl;
            }
        }
        
    }
        
    }

TURING::~TURING(){
    
}
    
