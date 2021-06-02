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
    vector<Nodo*> hijos;
    int cantHijos;
};

//Prototipos de funciones
Nodo *crearNodo(string, int);
void insertarNodo(Nodo*&, string , int , int);
void encolarPalabras();
void insertarRaiz();
void pasoRecursivo();

//variables globales
Nodo *arbol = NULL;
int cantidadDeHijos, cantPalabras;
queue<string> colaP;
queue<Nodo*> colaA;

int main() {
    encolarPalabras();
    cout<<"Ingrese la cantidad de hijos"<<endl;
    cin>>cantidadDeHijos;
    insertarRaiz();

    for (int i = 0; i < cantPalabras; ++i) {
        pasoRecursivo();
    }

    return 0;
}

void pasoRecursivo(){
    for (int i = 0; i < cantidadDeHijos; ++i) {
        string temp = colaP.front();
        //Puede que no sea el mismo Nodo que encolo e inserto.
        Nodo *aux = crearNodo(temp, cantidadDeHijos);
        colaA.push(aux);
        insertarNodo(arbol, temp, cantidadDeHijos, i); //probar pasarle la cabeza de la lista
    }
    colaA.pop();
}

//Solo sirve para no sobrecargar el main
void insertarRaiz(){
    string p0 = colaP.front(); colaP.pop();
    insertarNodo(arbol, p0, cantidadDeHijos, 0);
    colaA.push(arbol);
}

//Funcion para insertar un Nodo
void insertarNodo(Nodo *&arbolP, string palara, int cantidadHijos, int indice){
    if(arbolP == NULL){                      //si el arbolP esta vacio
        Nodo *nuevo_nodo = crearNodo(palara, cantidadHijos);
        arbolP = nuevo_nodo;
    }else{
        insertarNodo(arbolP->hijos[indice], palara, cantidadHijos, indice);
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
