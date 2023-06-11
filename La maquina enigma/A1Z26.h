#pragma once
#include <string>

using namespace std;

class A1Z26{
private://atributos
	struct nodoArbolAZ {
		int indice;//Es el identificador ASCII de ese caracter
		char letra;//Es el caracter que se encuentra en el arreglo abecedario
		string salida;//Es el caracter que obtendremos del crifrado
		nodoArbolAZ* izquierdo;
		nodoArbolAZ* derecho;
		nodoArbolAZ* padre;
	};

	nodoArbolAZ* arbol;//es el nodo del árbola

	nodoArbolAZ* crearNodo(char, int, string, nodoArbolAZ*);//crea un nodo del árbol
	void insertarNodo(nodoArbolAZ*&, char, int, string, nodoArbolAZ*);//inserta un nodo en el árbol
	void mostrarArbol(nodoArbolAZ*, int);//muestra el árbol
	string busqueda(nodoArbolAZ*, int);//busca un nodo en el árbol

	//recorridos del árbol
	void preOrden(nodoArbolAZ*);
public://métodos
	A1Z26();//Constructor
	~A1Z26();//Destructor
	void ingresar(char, int, string);
	void ver();
	string cifrar(int);
};

