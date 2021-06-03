#include <iostream>
#include <sstream>
#include <fstream>
#include "string"
#include "vector"
#include "queue"
#include "stack"
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
void swap(Nodo* pointer1); //sobreescribe
void swapear(Nodo* pointer1,Nodo* pointer2);
void reOrdenar(Nodo* raiz, string aux);
Nodo* obtenerRaiz(Nodo* ultimoHijo);
Nodo* buscarMax(Nodo* padre);
void ordenar();

//Variables globales
Nodo *arbol = NULL;
int cantidadDeHijos, cantPalabras, contaFlag=0;
long int comparaciones, swaps;
queue<Nodo*> terminado;
queue<string> colaP;
queue<Nodo*> colaA;
stack<Nodo*> pilaA;

int main() {
    encolarPalabras();

    cout<<"ingrese hijos "<<endl;
    cin>>cantidadDeHijos;

    //Armado del heap.
    insertarRaiz();
    pasoRecursivo();

    //Ordenado HeapSort
    ordenar();

    return 0;
}

void swap(Nodo* pointer1){
    comparaciones++;
    if((pointer1->padre != NULL)&&(pointer1->padre->palabra < pointer1->palabra)){
        swaps++;
        string aux = pointer1->padre->palabra;
        pointer1->padre->palabra = pointer1->palabra;
        pointer1->palabra = aux;
        swap(pointer1->padre);
    }
} //sobreescribe

void swapear(Nodo* pointer1,Nodo* pointer2){
    string aux = " ";
    pointer1->palabra = pointer2->palabra;
    pointer2->palabra = aux;
    swaps++; //guardr palabra en txt?
}

void ordenar(){
    while (!pilaA.empty()){
        Nodo *ultimoHijo = pilaA.top();
        pilaA.pop();
        string aux = ultimoHijo->palabra;
        Nodo *raiz = obtenerRaiz(ultimoHijo);
        swapear(ultimoHijo, raiz);
        reOrdenar(raiz, aux);
    }
}

Nodo* obtenerRaiz(Nodo * ultimoHijo){
    if(ultimoHijo->padre != NULL){
        obtenerRaiz(ultimoHijo->padre);
    } else{
        return ultimoHijo;
    }
}

Nodo* buscarMax(Nodo* padre){
    vector<Nodo*> hijos= padre->hijos;
    string max=" ";
    Nodo* mayor = NULL; //error??
    for (int i = 0; i < ( hijos.size() && hijos.size() != 0 ); ++i) {
        comparaciones++;
        if (hijos[i]->palabra >= max){
            max = hijos[i]->palabra;
            mayor = hijos[i];
        }
    }
    return mayor;
}

void reOrdenar(Nodo* raiz, string aux){
    Nodo* mayorN= buscarMax(raiz);
    if(mayorN!=NULL){
        swapear(raiz,mayorN);
        reOrdenar(mayorN,aux);
    }
    else{
        raiz->palabra=aux;
        swap(raiz);
    }
}

void insertarRaiz(){
    //Insertar raiz
    arbol = crearNodo(colaP.front(), cantidadDeHijos);
    arbol->padre = NULL;
    pilaA.push(arbol);
    colaP.pop();
    for (int i = 0; i < cantidadDeHijos; ++i) {
        Nodo *ni = crearNodo(colaP.front(), cantidadDeHijos);
        ni->padre = arbol;
        pilaA.push(ni);
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
            nj->padre = colaA.front();
            pilaA.push(nj);
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
