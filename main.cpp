#include <iostream>
#include <sstream>
#include <fstream>
#include "string"
#include "vector"
#include "queue"
using namespace std;

//Defino la estructura de un Nodo
struct Nodo{
    string palabra;
    Nodo *padre;
    vector<Nodo*> hijos;
    int cantHijos, repeticiones;
};

//Prototipos de funciones
Nodo *crearNodo(string, int);
void insertarNodo(Nodo*&, string , int , int);
void encolarPalabras();
void insertarRaiz();
void pasoRecursivo();

//variables globales
Nodo *arbol = NULL;
int cantidadDeHijos, cantPalabras, contaFlag=0;
queue<string> colaP;
queue<Nodo*> colaA;

int main() {
    //todo setear padres
    encolarPalabras();

    cout<<"ingrese hijos "<<endl;
    cin>>cantidadDeHijos;

    //Armado del heap.
    insertarRaiz();
    pasoRecursivo();

    cout<<"aber"<<endl;
    return 0;
}

void insertarRaiz(){
    //Insertar raiz
    arbol = crearNodo(colaP.front(), cantidadDeHijos);
    colaP.pop();
    for (int i = 0; i < cantidadDeHijos; ++i) {
        Nodo *ni = crearNodo(colaP.front(), cantidadDeHijos);
        colaP.pop();contaFlag++;
        arbol->hijos[i] = ni;
        colaA.push(ni);
    }
}

void pasoRecursivo(){
    //Paso recursivo
    while (contaFlag<(cantPalabras-10)){
        for (int j = 0; j < cantidadDeHijos; ++j) {
            Nodo *nj = crearNodo(colaP.front(), cantidadDeHijos);
            colaP.pop();contaFlag++;
            colaA.front()->hijos[j] = nj;
            colaA.push(nj);
        }
        colaA.pop();
    }
}

Nodo *crearNodo(string dato, int cantidadHijos){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->palabra = dato;
    for (int i = 0; i < cantidadHijos; ++i) {
        nuevo_nodo->hijos.push_back(NULL);
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
                colaP.push(tempStr);
                cantPalabras++;
            }
        }
    }
    myFile.close();
}
