#include "A1Z26.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string>

using namespace std;

//atributos
//Funci�n para crear un nuevo nodo
A1Z26::nodoArbolAZ* A1Z26::crearNodo(char letra, int indice, string salida, A1Z26::nodoArbolAZ* padre) {
	nodoArbolAZ* nuevoNodo = new nodoArbolAZ();

	nuevoNodo->letra = letra;
	nuevoNodo->indice = indice;
	nuevoNodo->salida = salida;
	nuevoNodo->izquierdo = NULL;
	nuevoNodo->derecho = NULL;
	nuevoNodo->padre = padre;

	return nuevoNodo;
}

//Funci�n para insertar un nodo en el �rbol
void A1Z26::insertarNodo(A1Z26::nodoArbolAZ*& arbol, char letra, int indice, string salida, nodoArbolAZ* padre) {
	if (arbol == NULL) {//si el �rbol est� vac�o
		nodoArbolAZ* nuevoNodo = crearNodo(letra, indice, salida, padre);//creamos un nuevo nodo
		arbol = nuevoNodo;//el nuevo nodo es ahora la ra�z del �rbol
	}
	else {//si el �rbol no est� vac�o
		int valorRaiz = arbol->indice;//obtenemos el valor de la ra�z
		if (indice < valorRaiz) {//si el valor a insertar es menor que la ra�z, insertamos en izquierda
			insertarNodo(arbol->izquierdo, letra, indice, salida, arbol);
		}
		else {//si el valor a insertar es mayor que la ra�z, insertamos en derecha
			insertarNodo(arbol->derecho, letra, indice, salida, arbol);
		}
	}
}

//Funci�n para mostrar el �rbol completo
void A1Z26::mostrarArbol(A1Z26::nodoArbolAZ* arbol, int cont) {
	if (arbol == NULL) {//si el �rbol est� vacio
		return;//No haces nada
	}
	else {
		mostrarArbol(arbol->derecho, cont + 1);//recorremos subarbol derecho
		for (int i = 0; i < cont; i++) {//damos espaciado
			cout << "   ";
		}
		cout << arbol->letra << " : " << arbol->indice << " : " << arbol->salida << endl;//imprimimos raiz
		mostrarArbol(arbol->izquierdo, cont + 1);//recorremos subarbol izquierdo
	}
}

//Funci�n para buscar un nodo en el �rbol
string A1Z26::busqueda(A1Z26::nodoArbolAZ* arbol, int indice) {
	if (arbol == NULL) {//si el �rbol est� vac�o
		//No haces nada
	}
	else if (arbol->indice == indice) {//Si el nodo es igual al elemento
		cout << "Se ha encontrado el elemento: " << arbol->letra << " : " << arbol->indice << " : " << arbol->salida << endl;//Imprimimos el nodo
		return arbol->salida;//retornamos el nodo
	}
	else if (indice < arbol->indice) {//Si el elemento es menor al nodo
		return busqueda(arbol->izquierdo, indice);//Buscamos en el sub�rbol izquierdo
	}
	else {//Si el elemento es mayor al nodo
		return busqueda(arbol->derecho, indice);//Buscamos en el sub�rbol derecho
	}
}

//Funci�n para recorrido en profundidad - PreOrden
void A1Z26::preOrden(A1Z26::nodoArbolAZ* arbol) {
	if (arbol == NULL) {//si el �rbol est� vac�o
		return;//No haces nada
	}
	else {//Si no est� vac�o
		cout << arbol->letra << " : " << arbol->indice << " : " << arbol->salida << " - ";//Imprimimos la ra�z
		preOrden(arbol->izquierdo);//Recorremos sub�rbol izquierdo
		preOrden(arbol->derecho);//Recorremos sub�rbol derecho
	}
}

//M�todos
//Constructor
A1Z26::A1Z26() {
	arbol = NULL;
}

//Destructor
A1Z26::~A1Z26() {

}

//M�todo ingresar elementos al �rbol
void A1Z26::ingresar(char letra, int indice, string salida) {
	insertarNodo(arbol, letra, indice, salida, NULL);//Insertamos un nuevo nodo llamando a la funci�n insertarNodo
}

//M�todo mostrar �rbol
void A1Z26::ver() {
	int contador = 0;
	mostrarArbol(arbol, contador);//Llamamos a la funci�n mostrarArbol
}

//M�todo para cifrar un caracter
string A1Z26::cifrar(int indice) {
	return busqueda(arbol, indice);//Llamamos a la funci�n busqueda
}
