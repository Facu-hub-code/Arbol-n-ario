#include <iostream>
#include <sstream>
#include <fstream>
#include "string"
#include "vector"
#include "ColaP.h"
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
void encolarPalabras();

//variables globales
Nodo *arbol = NULL;
int cantidadDeHijos, cantPalabras;
ColaP *colaP = new ColaP();


int main() {
    encolarPalabras();

    cout<<"Ingrese la cantidad de hijos"<<endl;
    cin>>cantidadDeHijos;

    insertarNodo(arbol, "primera", cantidadDeHijos, 0);

    for (int j = 0; j < cantidadDeHijos; ++j) {
        string aux = to_string(j);
        insertarNodo(arbol, aux, cantidadDeHijos, j);
    }
    for (int j = 0; j < cantidadDeHijos; ++j) {
        string aux = to_string(j);
        insertarNodo(arbol, aux, cantidadDeHijos, j);
    }

    for (int j = 0; j < cantidadDeHijos; ++j) {
        string aux = to_string(j);
        insertarNodo(arbol, aux, cantidadDeHijos, j);
    }

    for (int j = 0; j < cantidadDeHijos; ++j) {
        string aux = to_string(j);
        insertarNodo(arbol, aux, cantidadDeHijos, j);
    }

    for (int j = 0; j < cantidadDeHijos; ++j) {
        string aux = to_string(j);
        insertarNodo(arbol, aux, cantidadDeHijos, j);
    }

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

void encolarPalabras(){
    fstream myFile; //Creo un string para analizar el txt
    string tempStr,line,direccion = "C:\\Users\\Facundo\\Desktop\\TextoPractica.txt";
    myFile.open(direccion, ios::in); //abre el archivo, en base al nombre y al modo especificado
    if (myFile.is_open()){
        while (getline(myFile, line)){
            istringstream isstream(line);
            while(!isstream.eof()){// Mientras que no termine la linea del txt no sale del while
                isstream >> tempStr;// Guardo la palabra
                colaP->encolarNodo(tempStr);// Encolo la palabra
                cantPalabras++;
            }
        }
    }
    myFile.close();
}
