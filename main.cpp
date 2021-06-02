#include <iostream>
#include "vector"
using namespace std;

//Defino la estructura de un Nodo
struct Nodo{
    string palabra;
    vector<Nodo*> hijos;
    int cantHijos;
};


//Prototipos de funciones
Nodo *crearNodo(string, int);
void insertarNodo(Nodo*&, string , int , int);

//variables globales
Nodo *arbol = NULL;
int cantidadDeHijos;


int main() {
    cout << "Hello, World!" << endl;

    cout<<"Ingrese la cantidad de hijos"<<endl;
    cin>>cantidadDeHijos;

    insertarNodo(arbol, "primera", cantidadDeHijos, 0);
    insertarNodo(arbol, "2", cantidadDeHijos, 0);
    insertarNodo(arbol, "3", cantidadDeHijos, 1);
    insertarNodo(arbol, "4", cantidadDeHijos, 0);
    insertarNodo(arbol, "5", cantidadDeHijos, 1);
    insertarNodo(arbol, "6", cantidadDeHijos, 0);
    insertarNodo(arbol, "7", cantidadDeHijos, 1);
    insertarNodo(arbol, "8", cantidadDeHijos, 0);
    insertarNodo(arbol, "ultima", cantidadDeHijos, 1);

    return 0;
}

//Funcion para insertar un Nodo
void insertarNodo(Nodo *&arbolP, string palara, int cantidadHijos, int indice){
    if(arbolP == NULL){                      //si el arbolP esta vacio
        Nodo *nuevo_nodo = crearNodo(palara, cantidadHijos);
        arbolP = nuevo_nodo;
    }else{
        insertarNodo(arbolP->hijos[indice], palara, cantidadHijos, indice);
        //insertarNodo(arbolP->hijos.operator[](indice), palara, cantidadHijos, indice);
    }
}

Nodo *crearNodo(string dato, int cantidadHijos){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->palabra = dato;

    for (int i = 0; i < cantidadHijos; ++i) {
        nuevo_nodo->hijos.push_back(NULL);  //ver como asigna
    }

    return nuevo_nodo;
}




