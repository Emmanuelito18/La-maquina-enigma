#pragma once

//clase para cifrado atbash
class Atbash {
private://atributos
	//Estructura cifrado Atbash
	struct nodoArbolA {
		int indice;//Es el identificador ASCII de ese caracter
		char letra;//Es el caracter que se encuentra en el arreglo abecedario
		char salida;//Es el caracter que obtendremos del crifrado
		nodoArbolA* izquierdo;
		nodoArbolA* derecho;
		nodoArbolA* padre;
	};

	nodoArbolA* arbol;//es el nodo del árbol
	
	nodoArbolA* crearNodo(char, int, char,nodoArbolA*);//crea un nodo del árbol
	void insertarNodo(nodoArbolA*&, char, int, char,nodoArbolA*);//inserta un nodo en el árbol
	void mostrarArbol(nodoArbolA*, int);//muestra el árbol
	char busqueda(nodoArbolA*,int);//busca un nodo en el árbol
	void destruirArbol(nodoArbolA*);//destruye el árbol

	//recorridos del árbol
	void preOrden(nodoArbolA*);
public://métodos
	Atbash();//Constructor
	~Atbash();//Destructor
	void ingresar(char, int, char);
	void ver();
	char cifrar(int);
};