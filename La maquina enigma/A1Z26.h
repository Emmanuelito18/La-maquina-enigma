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

	nodoArbolAZ* arbol;//es el nodo del �rbola

	nodoArbolAZ* crearNodo(char, int, string, nodoArbolAZ*);//crea un nodo del �rbol
	void insertarNodo(nodoArbolAZ*&, char, int, string, nodoArbolAZ*);//inserta un nodo en el �rbol
	void mostrarArbol(nodoArbolAZ*, int);//muestra el �rbol
	string busqueda(nodoArbolAZ*, int);//busca un nodo en el �rbol

	//recorridos del �rbol
	void preOrden(nodoArbolAZ*);
public://m�todos
	A1Z26();//Constructor
	~A1Z26();//Destructor
	void ingresar(char, int, string);
	void ver();
	string cifrar(int);
};

