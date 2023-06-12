#pragma once

class Caezar{
private://atributos
    struct nodoArbolC {
	int indice;//Es el identificador ASCII de ese caracter
    char letra;//Es el caracter que se encuentra en el arreglo abecedario
	char salida;//Es el caracter que obtendremos del crifrado
    nodoArbolC* izquierdo;
    nodoArbolC* derecho;
	nodoArbolC* padre;
    };

    
    nodoArbolC* arbol;

	nodoArbolC* crearNodo(char, int, char, nodoArbolC*);//crea un nodo del árbol
	void insertarNodo(nodoArbolC*&, char, int, char, nodoArbolC*);//inserta un nodo en el árbol
	void mostrarArbol(nodoArbolC*, int);//muestra el árbol
	char busqueda(nodoArbolC*, int);//busca un nodo en el árbol
	void destruirArbol(nodoArbolC*);//destruye el árbol

	//recorridos del árbol
	void preOrden(nodoArbolC*);
public://métodos
	Caezar();//Constructor
	~Caezar();//Destructor
	void ingresar(char, int, char);
	void ver();
	char cifrar(int);
};