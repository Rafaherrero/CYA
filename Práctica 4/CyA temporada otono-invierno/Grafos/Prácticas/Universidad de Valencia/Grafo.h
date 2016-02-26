
/************************************ Grafo.h *********************************
 *
 *  Proposito: Interfaz de la clase Grafo
 *
 *  Historial del Desarrollo:
 *  Fecha       Autor              Id Cambio  Version  Descripcion del cambio
 *  ----------  ------------------ ---------  -------  ----------------------
 *  06-05-2005  Ricardo Ferris          0      0.9
 *
 ******************************************************************************/

const int MAX_NODOS = 150;

class Grafo
{
    public:
        typedef Planeta Valor_Nodo;

        // Constructor por defecto
        Grafo (void);


        // Metodo que a partir del nombre de dos ficheros (fichero de nodos y
        // fichero de relaciones) rellena la información del vector de nodos y de
        // la matriz de relaciones
        bool LeerGrafo (string, string);

        // 
        void CalcularCamino (int, Lista &);

        Valor_Nodo cinfo (int i) { return nodos[i].info; }

        void Conectar (void) {
          cout << "!!!!"<<endl;
          for (int i=0;i<num_nodos;i++)
	    for (int j=i+1;j<num_nodos;j++)
	      { 
               arcos[i][j].existe = true;
               arcos[j][i].existe = true;
              }
	}

    private:
        struct Nodo
        {
            Valor_Nodo info;    /* Información asociada a cada nodo */
            bool visitado;
        };

        struct Arco
        {
            bool existe;
        };

        typedef Nodo Vect_Nodos[MAX_NODOS];
        typedef Arco Vect_Arcos[MAX_NODOS][MAX_NODOS];

        int num_nodos;
        Vect_Nodos nodos;
        Vect_Arcos arcos;
