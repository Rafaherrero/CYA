//
//  merge.cpp
//  ordenacionporfusion
//
//  Created by Rafael Herrero on 08/12/14.
//  Copyright (c) 2014 Rafael Herrero. All rights reserved.
//

#include "merge.h"

using namespace std;

mergeordenar::mergeordenar (void)
{
    
    verbose=false;
    string utilizarverbose;
    string utilizardoble;
    string verdadero = ("s");
    cout << "¿Desea utilizar la función verbose? (s/n)" << endl;
    cin >> utilizarverbose;
    cout << "¿Desea utilizar vectores con el doble de tamaño? (s/n)" << endl;
    cin >> utilizardoble;
    
    if (strcmp(utilizarverbose.c_str(), verdadero.c_str())==0){
        verbose=true;
    }
    
    if (strcmp(utilizardoble.c_str(), verdadero.c_str())==0){
        doble=true;
    }
    
}

mergeordenar::~mergeordenar()
{
    
}

void mergeordenar::ordenacionporfusion(vector<int> &T){
    
    
    if (verbose==true){
        cout << "{" << T.front() << "..." << T.back() << "}" << T.size() << endl;
        
    }
    
    if (T.size()==2&&doble){
        if (T[0]>T[1]){
            reverse(T.begin(), T.end());
        }
        return;
    }

    if (T.size()==1){
        return;
    }
    vector<int> U (T.cbegin(),T.cbegin()+T.size()/2);
    vector<int> V (T.cbegin()+T.size()/2,T.cend());
    
   
        
    ordenacionporfusion(U);
    ordenacionporfusion(V);
    
    fusionar (U,V,T);
}

void mergeordenar::fusionar (vector<int> U, vector<int> V, vector<int> &T){
    unsigned i=0,j =0;
    
    U.push_back(100000);
    V.push_back(100000);
    
    for (int whisky=0; whisky<((U.size()-1)+(V.size())-1) ; whisky++){
        if (U[i]<V[j]){
            T[whisky]=U[i];
            i++;
        }
        else{
            T[whisky]=V[j];
            j++;
        }
    }
    //U.pop_back();
    //V.pop_back();
}