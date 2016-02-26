//
//  merge.h
//  ordenacionporfusion
//
//  Created by Rafael Herrero on 08/12/14.
//  Copyright (c) 2014 Rafael Herrero. All rights reserved.
//


#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class mergeordenar {

private:

    bool verbose;
    bool doble;
    
public:
    
    mergeordenar(void);
    ~mergeordenar(void);

    void ordenacionporfusion (vector<int> &T);
    void fusionar (vector<int> U, vector<int> V, vector<int> &T);

};