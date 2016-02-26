
/************************** Practica sobre Grafos ***************************
 *
 *  Proposito: Construir un grafo a partir de la informacion de los nodos y
 *             arcos contenidos en dos ficheros y a partir del grafo 
 *             calcular informacion asociada
 *             
 *
 *  Historial del Desarrollo:
 *  Fecha       Autor              Id Cambio  Version  Descripcion del cambio
 *  ----------  ------------------ ---------  -------  ----------------------
 *  06-05-2005  Ricardo Ferris          0      0.9
 *  
 ******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const char PAUSE[]="read"; // para linux
//const char PAUSE[]="PAUSE"; // para windows

#include "Definiciones.h"
#include "Lista.h"
#include "Grafo.h"

void MostrarLista (Lista);
bool GuardarLista (Lista);

/************************************************************************
 ********************** Programa Principal ******************************
 ************************************************************************/
int main (void)
{
    Grafo grafo;
    Lista list;
    int inicio;

    cout << "********* STAR WARS TRIP **************" << endl;

    if (!grafo.LeerGrafo ("nodos.dat", "grafo.dat") )
        cout << "Se ha producido algun error en la apertura de los ficheros.";
    else
    {
      cout << "Planeta de partida (codigo): ";
      cin >> inicio ;

      if (inicio >= 0)
         cout << grafo.cinfo(inicio).nombre << endl;
      else
	{
	  cout << "Recorriendo toda la galaxia desde ..." << endl;
          inicio = -inicio +1;
          cout << grafo.cinfo(inicio).nombre << endl;
          grafo.Conectar();
        }     
      
      grafo.CalcularCamino (inicio,list);

      // MostrarLista (list);
      GuardarLista (list);

    }
    system (PAUSE);
    return 0;
}



/*************** void MostrarLista (Lista list) *************************
 *
 *  Descripcion: Muestra por pantalla la información referente a los
 *               planetas que son punto de ruptura en la red de 
 *               comunicaciones
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  list            Lista       E    Lista donde estan guardados los puntos
 *                                   de ruptura
 *                                   
 *  Valor devuelto:
 *  void
 *
 ************************************************************************/
void MostrarLista (Lista list)
{
    Planeta x;

    cout << "Lista de planetas:\n";
    list.IrAInicio ();
    while (!list.FinalLista () )
    {
        list.Consultar (x);
        cout << x.codigo << " - ";
        cout << x.nombre;
        cout << " (" << x.coord[0] << "," << x.coord[1] << ","  << x.coord[2] << ")" << endl;
        list.Avanzar ();
    }
}

/*************** void GuardarLista (Lista list) *************************
 *
 *  Descripcion: Guarda en ficheros texto la informacion 
 *               de los planetas municaciones
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  list            Lista       E    Lista donde estan guardados los puntos
 *                                   de ruptura
 *                                   
 *  Valor devuelto:
 *  bool            true  -> La operacion ha podido ser realizada con exito
 *                  false -> La operacion no ha podido ser realizada con exito
 *                           (Ha habido problemas abriendo el fichero)
 *
 ************************************************************************/
bool GuardarLista (Lista list)
{
    ofstream fcoord,fnoms;
    Planeta x;
    bool exito;

    fcoord.open ("coords.dat");
    fnoms.open("noms.dat");
    if (!fcoord and ! fnoms)
        exito = false;
    else
    {
        exito = true;
        list.IrAInicio ();
        while (!list.FinalLista () )
        {
            list.Consultar (x);
            //f.write ( (char *)(&x), sizeof (x) );
            fcoord  << x.coord[0] << " " << x.coord[1] << " "  << x.coord[2] << endl;
            fnoms << x.nombre+"          " << endl;
            list.Avanzar ();
        }
        fcoord.close ();
        fnoms.close();
    }
    
    return exito;
}

/********************************************************************
 *  Descrip: calcula distancia entre 2 planetas
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  x,y             Planeta      E    planetas
 *                                                                      
 *  Valor devuelto:
 *    double        distancia       

 ********************************************************************/
double pdistancia(Planeta x, Planeta y)
{
  double ac = 0;
  int i;

  for (i=0;i<3;i++)
    ac =  ac + pow(x.coord[i]-y.coord[i],2);
  
  return sqrt(ac);

}