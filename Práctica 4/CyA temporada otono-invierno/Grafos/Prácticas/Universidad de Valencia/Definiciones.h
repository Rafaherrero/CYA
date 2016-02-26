
/************************** Practica 08: 00Definiciones.h *********************
 *
 *  Proposito: Definiciones de la información que vamos a guardar, tanto en
 *             la lista como en los nodos de los grafos.
 *
 *  Historial del Desarrollo:
 *  Fecha       Autor              Id Cambio  Version  Descripcion del cambio
 *  ----------  ------------------ ---------  -------  ----------------------
 *  06-05-2005  Ricardo Ferris          0      0.9
 ******************************************************************************/
#ifndef _DEFINICIONES_
#define _DEFINICIONES_

#include <math.h>

typedef float Coordenadas[3];

struct Planeta
{
    string nombre;
    int codigo;
    Coordenadas coord;
};

double pdistancia(Planeta , Planeta );

#endif