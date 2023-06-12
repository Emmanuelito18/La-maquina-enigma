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

	nodoArbolA* arbol;//es el nodo del �rbol
	
	nodoArbolA* crearNodo(char, int, char,nodoArbolA*);//crea un nodo del �rbol
	void insertarNodo(nodoArbolA*&, char, int, char,nodoArbolA*);//inserta un nodo en el �rbol
	void mostrarArbol(nodoArbolA*, int);//muestra el �rbol
	char busqueda(nodoArbolA*,int);//busca un nodo en el �rbol
	void destruirArbol(nodoArbolA*);//destruye el �rbol

	//recorridos del �rbol
	void preOrden(nodoArbolA*);
public://m�todos
	Atbash();//Constructor
	~Atbash();//Destructor
	void ingresar(char, int, char);
	void ver();
	char cifrar(int);
};