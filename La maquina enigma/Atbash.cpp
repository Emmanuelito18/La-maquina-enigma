#include "Atbash.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

//atributos
Atbash::nodoArbolA* Atbash::vaciar(Atbash::nodoArbolA* arbol) {//elimina el nodo del árbol, se utiliza cuando se cuierra el programa
	if (arbol == nullptr) {//si el árbol está vacio
		return nullptr;
	}
	else {
		vaciar(arbol->izquierdo);
		vaciar(arbol->derecho);
		delete arbol;
	}
	return nullptr;
}

//inserta valores al los nodos del árbol
Atbash::nodoArbolA* Atbash::insertar(char letra, int numero, char equivalente, Atbash::nodoArbolA* arbol) {
	if (arbol == nullptr) {
		arbol = new nodoArbolA;
		arbol->letra = letra;
		arbol->indice = numero;
		arbol->salida = equivalente;
		arbol->izquierdo = arbol->derecho = nullptr;
	}
	else if (numero < arbol->indice)
		arbol->izquierdo = insertar(letra, numero, equivalente, arbol->izquierdo);
	else if (numero > arbol->indice)
		arbol->derecho = insertar(letra, numero, equivalente, arbol->derecho);
	return arbol;
}

void Atbash::InOrder(Atbash::nodoArbolA* arbol) {//muestra el árbol completo, solo utilizado para depuración
	if (arbol == nullptr)
		return;
	InOrder(arbol->izquierdo);
	cout << arbol->letra << ":" << arbol->indice << ":" << arbol->salida << "  ";
	InOrder(arbol->derecho);
}

/*Busca caracteres ingresados por el usuario en le árbol*/
Atbash::nodoArbolA* Atbash::buscar(Atbash::nodoArbolA* arbol, char caracter, bool& encontrado) {
	if (arbol == nullptr) {
		encontrado = false;
		return nullptr;
	}
	else if (caracter < arbol->letra) {
		return buscar(arbol->izquierdo, caracter, encontrado);
	}
	else if (caracter > arbol->letra) {
		return buscar(arbol->derecho, caracter, encontrado);
	}
	else {
		encontrado = true;
		return arbol;
	}
}

//Constructor
Atbash::Atbash() {
	arbol = NULL;
}

//Destructor
Atbash::~Atbash() {
	arbol= vaciar(arbol);
}
  
void Atbash::ingresar(char caracter, int indice,char equivalente) {
	arbol = insertar(caracter, indice, equivalente, arbol);
}

void Atbash::ver() {
	InOrder(arbol);
	cout << endl;
}

char Atbash::encontrar(char caracter) {
	char resultado=NULL;
	bool encontrado = false;
	arbol = buscar(arbol, caracter, encontrado);
	if (encontrado) {
		cout << "El caracter '" << caracter << "' se ha encontrado en el árbol." << endl;
		cout << "Indice: " << arbol->indice << endl;
		cout << "Equivalencia: " << arbol->salida<<endl;
		resultado = arbol->salida;
	}
	else {
		cout << "El caracter '" << caracter << "' no se ha encontrado en el árbol." << endl;
	}
	return resultado;//este valor se debe guardar en el arreglo textoA
}