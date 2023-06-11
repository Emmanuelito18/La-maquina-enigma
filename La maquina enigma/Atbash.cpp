#include "Atbash.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

//atributos
//Función para crear un nuevo nodo
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

//Función para insertar un nodo en el árbol
void Atbash::insertarNodo(Atbash::nodoArbolA*& arbol, char letra, int indice, char salida, nodoArbolA* padre) {
	if (arbol == NULL) {//si el árbol está vacío
		nodoArbolA* nuevoNodo = crearNodo(letra, indice, salida, padre);//creamos un nuevo nodo
		arbol = nuevoNodo;//el nuevo nodo es ahora la raíz del árbol
	}
	else {//si el árbol no está vacío
		int valorRaiz = arbol->indice;//obtenemos el valor de la raíz
		if (indice < valorRaiz) {//si el valor a insertar es menor que la raíz, insertamos en izquierda
			insertarNodo(arbol->izquierdo, letra, indice, salida, arbol);
		}
		else {//si el valor a insertar es mayor que la raíz, insertamos en derecha
			insertarNodo(arbol->derecho, letra, indice, salida, arbol);
		}
	}
}

//Función para mostrar el árbol completo
void Atbash::mostrarArbol(Atbash::nodoArbolA* arbol, int cont) {
	if (arbol == NULL) {//si el árbol está vacio
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

//Función para buscar un nodo en el árbol
char Atbash::busqueda(Atbash::nodoArbolA* arbol, int indice) {
	if (arbol == NULL) {//si el árbol está vacío
			//No haces nada
	}
	else if (arbol->indice == indice) {//Si el nodo es igual al elemento
		cout<<"Se ha encontrado el elemento: "<<arbol->letra<<" : "<<arbol->indice<<" : "<<arbol->salida<<endl;//Imprimimos el nodo
		return arbol->salida;//retornamos el nodo
	}
	else if(indice < arbol->indice) {//Si el elemento es menor al nodo
			return busqueda(arbol->izquierdo, indice);//Buscamos en el subárbol izquierdo
		}
	else {//Si el elemento es mayor al nodo
			return busqueda(arbol->derecho, indice);//Buscamos en el subárbol derecho
		}
}

//Función para recorrido en profundidad - PreOrden
void Atbash::preOrden(Atbash::nodoArbolA* arbol) {
	if (arbol == NULL) {//si el árbol está vacío
			return;//No haces nada
		}
	else {//Si no está vacío
			cout << arbol->letra << " : " << arbol->indice << " : " << arbol->salida << " - ";//Imprimimos la raíz
			preOrden(arbol->izquierdo);//Recorremos subárbol izquierdo
			preOrden(arbol->derecho);//Recorremos subárbol derecho
		}
}

//Métodos
//Constructor
Atbash::Atbash() {
	arbol = NULL;
}

//Destructor
Atbash::~Atbash() {
	
}

//Método ingresar elementos al árbol
void Atbash::ingresar(char letra, int indice,char salida) {
	insertarNodo(arbol, letra, indice, salida, NULL);//Insertamos un nuevo nodo llamando a la función insertarNodo
}

//Método mostrar árbol
void Atbash::ver() {
	int contador = 0;
	mostrarArbol(arbol, contador);//Llamamos a la función mostrarArbol
}

//Método buscar un elemento en el árbol
char Atbash::buscar(int indice) {
	return busqueda(arbol, indice);//Llamamos a la función busqueda
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