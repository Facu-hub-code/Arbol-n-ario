//
// Created by Facundo on 01/06/2021.
//

#ifndef MARTES_COLAP_H
#define MARTES_COLAP_H
#include <iostream>
#include "NodoP.h"
using namespace std;

class ColaP {
private:
    NodoP *comienzo;
public:
    ColaP(){comienzo = new NodoP();}
    ColaP(NodoP *nodoP){comienzo = nodoP;}
    ~ColaP();

    void encolarNodo(string dato){
        NodoP *nuevo = new NodoP(dato);
        nuevo->setSiguiente(comienzo);
        comienzo = nuevo;
    }

    bool esvacia(){ return comienzo == NULL; }

    string cabeza(void){     //retorna el dato del primer nodo
        if (esvacia()){return NULL;}
        return comienzo->getDato();
    }

    void borrar_first(){ //borra la cabeza
        if (!esvacia()){
            NodoP *temp = comienzo;
            comienzo = comienzo->getSiguiente();
            delete temp;
        }
    }

    void borrar_last(){ //borra el ultimo
        if (!esvacia()){
            if (comienzo->getSiguiente()->getSiguiente() == NULL){
                delete comienzo->getSiguiente();
                comienzo->setSiguiente(NULL);
            }else{
                this->resto()->borrar_last();
            }
        }
    }

    ColaP* resto(){
        ColaP *colaP = new ColaP(comienzo->getSiguiente());
        return (colaP);
    }

};


#endif //MARTES_COLAP_H
