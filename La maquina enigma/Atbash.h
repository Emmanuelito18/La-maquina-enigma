#pragma once

//clase para cifrado atbash
class Atbash {
private://atributos
	char textoA[1000];
	//Estructura cifrado Atbash
	struct nodoArbolA {
		char letra;//Es el caracter que se encuentra en el arreglo abecedario
		int indice;//Es el identificador ASCII de ese caracter
		char salida;//Es el caracter que obtendremos del crifrado
		nodoArbolA* izquierdo;
		nodoArbolA* derecho;
	};

	nodoArbolA* arbol;//es el nodo del árbol

	nodoArbolA* vaciar(nodoArbolA* arbol);
	nodoArbolA* insertar(char letra, int numero, char equivalente, nodoArbolA* arbol);
	void InOrder(nodoArbolA* arbol);
	nodoArbolA* buscar(nodoArbolA* arbol, char caracter, bool& encontrado);

public://métodos
	Atbash();//Constructor
	~Atbash();//Destructor
	void ingresar(char, int, char);
	void ver();
	char encontrar(char);
};