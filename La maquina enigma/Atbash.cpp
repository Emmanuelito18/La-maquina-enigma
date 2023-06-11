#include "Atbash.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

//atributos
//Funci�n para crear un nuevo nodo
Atbash::nodoArbolA* Atbash::crearNodo(char letra, int indice, char salida, Atbash::nodoArbolA* padre) {
	nodoArbolA* nuevoNodo = new nodoArbolA();

	nuevoNodo->letra = letra;
	nuevoNodo->indice = indice;
	nuevoNodo->salida = salida;
	nuevoNodo->izquierdo = NULL;
	nuevoNodo->derecho = NULL;
	nuevoNodo->padre = padre;

	return nuevoNodo;
}

//Funci�n para insertar un nodo en el �rbol
void Atbash::insertarNodo(Atbash::nodoArbolA*& arbol, char letra, int indice, char salida, nodoArbolA* padre) {
	if (arbol == NULL) {//si el �rbol est� vac�o
		nodoArbolA* nuevoNodo = crearNodo(letra, indice, salida, padre);//creamos un nuevo nodo
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
void Atbash::mostrarArbol(Atbash::nodoArbolA* arbol, int cont) {
	if (arbol == NULL) {//si el �rbol est� vacio
		return;//No haces nada
	}
	else {
		mostrarArbol(arbol->derecho, cont + 1);//recorremos subarbol derecho
		for(int i=0;i<cont;i++) {//damos espaciado
					cout << "   ";
		}
		cout<<arbol->letra<<" : "<<arbol->indice<<" : "<<arbol->salida<<endl;//imprimimos raiz
		mostrarArbol(arbol->izquierdo, cont + 1);//recorremos subarbol izquierdo
	}
}

//Funci�n para buscar un nodo en el �rbol
char Atbash::busqueda(Atbash::nodoArbolA* arbol, int indice) {
	if (arbol == NULL) {//si el �rbol est� vac�o
			//No haces nada
	}
	else if (arbol->indice == indice) {//Si el nodo es igual al elemento
		cout<<"Se ha encontrado el elemento: "<<arbol->letra<<" : "<<arbol->indice<<" : "<<arbol->salida<<endl;//Imprimimos el nodo
		return arbol->salida;//retornamos el nodo
	}
	else if(indice < arbol->indice) {//Si el elemento es menor al nodo
			return busqueda(arbol->izquierdo, indice);//Buscamos en el sub�rbol izquierdo
		}
	else {//Si el elemento es mayor al nodo
			return busqueda(arbol->derecho, indice);//Buscamos en el sub�rbol derecho
		}
}

//Funci�n para recorrido en profundidad - PreOrden
void Atbash::preOrden(Atbash::nodoArbolA* arbol) {
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
Atbash::Atbash() {
	arbol = NULL;
}

//Destructor
Atbash::~Atbash() {
	
}

//M�todo ingresar elementos al �rbol
void Atbash::ingresar(char letra, int indice,char salida) {
	insertarNodo(arbol, letra, indice, salida, NULL);//Insertamos un nuevo nodo llamando a la funci�n insertarNodo
}

//M�todo mostrar �rbol
void Atbash::ver() {
	int contador = 0;
	mostrarArbol(arbol, contador);//Llamamos a la funci�n mostrarArbol
}

//M�todo buscar un elemento en el �rbol
char Atbash::buscar(int indice) {
	return busqueda(arbol, indice);//Llamamos a la funci�n busqueda
}

/*
void Atbash::encriptar(char* textoA, char* textoB) {
	int i = 0;
	while (textoA[i] != '\0') {
		textoB[i] = encontrar(textoA[i]);
		i++;
	}
}

void Atbash::desencriptar(char* textoA, char* textoB) {
	int i = 0;
	while (textoA[i] != '\0') {
		textoB[i] = encontrar(textoA[i]);
		i++;
	}
}*/