//
// Created by Facundo on 01/06/2021.
//

#ifndef MARTES_NODOP_H
#define MARTES_NODOP_H
#include <iostream>
using namespace std;

class NodoP {
private:
    string dato;
    NodoP *siguiente;
public:
    NodoP(){ siguiente = NULL; }

    NodoP(string datop){
        dato = datop;
        siguiente = NULL;
    }

    bool es_vacio() { return siguiente == NULL; }

    //Getters y setters
    const string &getDato() const {return dato;}

    void setDato(const string &dato) {NodoP::dato = dato;}

    NodoP *getSiguiente() const {return siguiente;}

    void setSiguiente(NodoP *siguiente) {NodoP::siguiente = siguiente;}
};


#endif //MARTES_NODOP_H
