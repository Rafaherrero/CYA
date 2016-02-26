////////////////////////////////////////
//Clase LISTA (con punto de interes)
//Interfaz
//Autor: Jesus Albert (18 abril 2005)
////////////////////////////////////////

#ifndef _LISTA_H_
#define _LISTA_H_
//Declaracion del tipo base de la lista
//Si el tipo base cambia es preciso modificar esta linea

class Lista
{
    public:
        typedef Planeta Valor;

        //Constructores, destructor y asignacion
        Lista ();
        Lista (const Lista&);
        ~Lista();
        const Lista& operator= (const Lista&);

        //Operaciones con datos:
        //Insertar (Valor): Inserta el Valor delante del pto de interes
        //devuelve false si no hay memoria suficiente
        bool Insertar (Valor);
        //Eliminar(): Elimina el Valor del pto de interes
        //devuelve false si el pto de interes es nulo
        bool Eliminar ();
        //Consultar (Valor&): Recupera el Valor del pto de interes
        //y lo almacena en el argumento por referencia
        //devuelve false si el pto de interes es nulo
        bool Consultar (Valor&);
        //ListaVacia(): Indica si la lista no tiene elementos
        //devuelve true si la lista esta vacia
        bool ListaVacia();

        //Operaciones con el pto. de interes:
        //IrInicio(): Desplaza el pto. de interes al primer elemento
        //de la lista
        void IrAInicio();
        //IrUltimo(): Desplaza el pto. de interes al ultimo elemento
        //de la lista
        void IrUltimo();
        //Avanzar(): Desplaza el pto. de interes al siguiente elemento
        //de la lista. Es posible ir una posicion mas alla del ultimo
        //Devuelve false si el pto. de interes es nulo y no es posible
        //seguir avanzando
        bool Avanzar();
        //Retroceder(): Desplaza el pto. de interes al anterior elemento
        //de la lista. No es posible retroceder mas atras del primer elemento
        //Devuelve false si el pto. de interes es el inicio
        bool Retroceder ();
        //FinalLista(): Indica si el pto. de interes ha sobrepasado
        //la posicion del ultimo elemento de la lista y devuelve true
        //en ese caso.
        bool FinalLista();

    private: //lista simplemente enlazada
        struct Nodo;
        typedef Nodo* Puntero;
        struct Nodo
        {
            Valor info;
            Puntero sig;
        };

        Puntero inicio, fin;
        Puntero pto;
        bool Copiar (const Lista&);
        void Vaciar ();
};
#endif