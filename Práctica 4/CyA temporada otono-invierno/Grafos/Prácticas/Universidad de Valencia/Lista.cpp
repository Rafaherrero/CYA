////////////////////////////////////////
//Clase LISTA (con punto de interes)
//Implementacion
//Autor: Jesus Albert (18 abril 2005)
////////////////////////////////////////
#include <iostream>
#include <string>
using namespace std;

#include "Definiciones.h"
#include "Lista.h"

Lista::Lista ()
{
    inicio = NULL;
    fin = NULL;
    pto = NULL;
}

Lista::Lista (const Lista& orig)
{
    if (! Copiar (orig))
       cerr << "Lista: Error en el constructor de copia" << endl;
}

Lista::~Lista ()
{
   Vaciar();
}

const Lista& Lista::operator= (const Lista& orig)
{
    if (! Copiar (orig))
       cerr << "Lista: Error en la asignacion" << endl;
    return (*this);
}

bool Lista::Insertar ( Valor x )
{
    bool ok;
    Puntero aux;

    aux = new Nodo;
    if ( aux == NULL )
        ok = false;
    else
    {
        ok = true;
        if (pto == NULL) //insertar al final
        {
            aux->info = x;
            aux->sig = NULL;
            if (inicio == NULL) //si vacia
                inicio = aux;
            else //detras del fin
                fin->sig = aux;
            fin = aux; //siempre es el fin
        }
        else
        {
            *aux = *pto;
            pto->info = x;
            pto->sig = aux;
            if ( pto == fin ) //caso particular
                fin = aux;
            pto = aux;
        }
    }
    return (ok);
}

bool Lista::Eliminar ()
{
    Puntero aux;
    bool ok;

    if ( (pto == NULL) || ListaVacia() )
        ok = false;
    else
    {
        ok = true;
        if (pto == fin) //no hay nada detrï¿½
        {
            if (pto == inicio) //es el nico
            {
                delete pto;
                inicio = fin = pto = NULL;
            }
            else
            {
                aux = inicio;
                //buscar el penfin
                while ( aux->sig != fin )
                    aux = aux->sig;
                fin = aux;
                fin->sig = NULL;
                delete pto;
                pto = NULL;
            }
        }
        else
        {
            //caso normal
            aux = pto->sig;
            *pto = *aux;
            if (aux == fin)
                fin = pto;
            delete aux;
        }
    }
    return (ok);
}

bool Lista::Consultar (Valor& x)
{
    bool ok;

    if ((pto == NULL) || ListaVacia())
        ok = false;
    else
    {
        ok = true;
        x = pto->info;
    }
    return (ok);
}

bool Lista::ListaVacia ()
{
    return ( inicio == NULL );
}

void Lista::IrAInicio()
{
    pto = inicio;
}

void Lista::IrUltimo()
{
    pto = fin;
}

bool Lista::Avanzar()
{
    bool ok;

    if ( pto == NULL )
        ok = false;
    else
    {
        ok = true;
        pto = pto->sig;
    }
    return (ok);
}

bool Lista::Retroceder()
{
    bool ok;
    Puntero aux;

    if ( pto == inicio )
        ok = false;
    else
    {
       ok= true;
       if ( pto == NULL)
          pto = fin;
       else
       {
          aux = inicio;
          //buscar el anterior
          while ( aux->sig != pto )
             aux = aux->sig;
          pto = aux;
       }
    }
    return (ok);
}

bool Lista::FinalLista()
{
    return ( pto == NULL );
}

bool Lista::Copiar (const Lista& orig)
{
    Puntero aux, dup;
    bool ok=true;

    inicio = NULL;
    fin = NULL;

    aux = orig.inicio;
    dup = NULL;

    while ( (aux != NULL) && ok )
    {
        dup = new Nodo;
        if (dup == NULL)
           ok =false;
        else
        {
           dup->info = aux->info;
           dup->sig = NULL;
           if (inicio == NULL) //si vacia
              inicio = dup;
           else //detras del fin
              fin->sig = dup;
           fin = dup; //siempre es el fin
           if ( aux == orig.pto ) //fijar pto. de interes
              pto = dup;
           aux = aux->sig;
        }
    }
    return (ok);
}

void Lista::Vaciar ()
{
   pto = inicio;
   while ( Eliminar() );
}