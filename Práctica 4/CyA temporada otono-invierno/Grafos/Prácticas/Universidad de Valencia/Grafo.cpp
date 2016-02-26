
/************************** Grafo.cpp***************************
 *
 *  Proposito: Implementacion de los metodos propios de la clase Grafo
 *
 *  Historial del Desarrollo:
 *  Fecha       Autor              Id Cambio  Version  Descripcion del cambio
 *  ----------  ------------------ ---------  -------  ----------------------
 *  06-05-2005  Ricardo Ferris          0      0.9
 ******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include <stdlib.h>
#include <math.h>

#include "Definiciones.h"
#include "Lista.h"
#include "Grafo.h"


/*************** Grafo::Grafo (void) ************************************
 *
 *  Descripcion:  Metodo de la clase 'Grafo'. Constructor de la clase.
 *                Inicia el objeto a 'vacio' (numero de nodos a cero
 *                y todas las posibles relaciones a inexistente
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  ninguno
 *
 *  Valor devuelto:
 *  Ninguno
 *
 ************************************************************************/
Grafo::Grafo (void)
{
    int i, j;

    num_nodos = 0;    
    for (i = 0; i < MAX_NODOS; i++)
        for (j = 0; j < MAX_NODOS; j++)
            arcos[i][j].existe = false;
}

/*************** bool Grafo::LeerGrafo (string, string) *****************
 *
 *  Descripcion: Metodo de la clase 'Grafo'. 
 *               Lee la información de los ficheros de nodos y de arcos
 *               y la pone en el vector de nodos y la matriz de arcos
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  cad_nodos       string      E    Cadena con el nombre del fichero de nodos
 *  cad_relaciones  string      E    Cadena con el nombre del fichero de arcos
 *                                   
 *  Valor devuelto:
 *  bool            true  -> La operacion ha podido ser realizada con exito
 *                  false -> La operacion no ha podido ser realizada con exito
 *                           (Ha habido problemas abriendo alguno de los ficheros)
 *
 ************************************************************************/
bool Grafo::LeerGrafo (string cad_nodos, string cad_relaciones)
{
    ifstream f_nodos, f_relaciones;
    bool exito = true;
    int i, j, num, na;
    
    f_nodos.open (cad_nodos.c_str () );
    if (!f_nodos)
        exito = false;
    else
    {
        f_relaciones.open (cad_relaciones.c_str () );
        if (!f_relaciones)
            exito = false;
        else
        {
            i = 0;
            while (getline (f_nodos, nodos[i].info.nombre) )
            {
                f_nodos >> nodos[i].info.codigo;
                for (j = 0; j < 3; j++)
                    f_nodos >> nodos[i].info.coord[j];
                f_nodos.ignore ();
                i++;
            }
            num_nodos = i;
            cout << "Num. nodos = " << num_nodos << endl;
            na = 0;
            for (i = 0; i < num_nodos; i++)
                for (j = 0; j < num_nodos; j++)
		  {
                    f_relaciones >> arcos[i][j].existe;
                    if ( arcos[i][j].existe ) na++;
                  }
            cout << "Num. arcos = " << na << endl;
        }
    }
    
    return exito;
}

/*************** void CalcularCamino (int i, Lista & l) *************
 *
 *  Descripcion: Metodo de la clase 'Grafo'.
 *               Calcula un camino como lista de nodos
 *               y los guarda en una lista
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  i               int           E  nodo inicial
 *  list            Lista         S  Lista donde guardaremos los nodos 
 *                                   
 *                                   
 *  Valor devuelto:
 *  void
 *
 ************************************************************************/
void Grafo::CalcularCamino (int i, Lista & l)
{
   Planeta  x,y;
   int j, seg,lcam;
   bool final;
   double mind,d,distt;


    lcam=1;
    final = false;
    distt = 0;

    while (!final)
      {   
       nodos[i].visitado = true;
       x = nodos[i].info ;
       
       l.Insertar(nodos[i].info);
       seg = i;
       //       cout << i << " - " << nodos[i].info.nombre <<  "== ";
    
       mind = HUGE_VAL;
       for (j=0; j<num_nodos; j++)
          if (!nodos[j].visitado and arcos[i][j].existe)
	    {
	      //              cout << j << " ";  
              y = nodos[j].info ;
              d = pdistancia(x,y);
	      if ( d < mind )
		{
                 seg = j;
	         mind = d;
                }
              }
    
       //      cout << "(" << seg << ")" << endl;
      if (seg != i) 
        { 
         i = seg;
         lcam++;
         distt += mind;
        }
      else
        final = true;   

    }// while

    cout << "Camino: " << lcam << endl;
    cout << "Distancia: " << distt << endl;
    return;
}
