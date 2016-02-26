//
//  Cambio.h
//  Monedas
//
//  Created by Rafael Herrero on 28/11/14.
//  Copyright (c) 2014 Rafael Herrero. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>


using namespace std;
typedef struct{
    int valor;
    int cantidad;
}estructura_de_cambio;

class cambio{
private:
    vector<int> billetes;
    vector<int> monedas;
    vector<int> ambos;
    vector<estructura_de_cambio> cartera;
    
public:
    cambio();
    ~cambio();
    void cambio_monedas();
    void cambio_billetes();
    void cambio_ambos();
};