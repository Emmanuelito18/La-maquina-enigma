#pragma once

class Caezar{
private://atributos
    struct nodoArbolC {
    char letra;//Es el caracter que se encuentra en el arreglo abecedario
    int indice;//Es el identificador ASCII de ese caracter
	char salida;//Es el caracter que obtendremos del crifrado
    nodoArbolC* izquierdo;
    nodoArbolC* derecho;
    };
    
    nodoArbolC* arbol;

	nodoArbolC* vaciar(nodoArbolC* arbol);
	nodoArbolC* insertar(char letra, int numero,char equivalente, nodoArbolC* Arbol);
	void InOrder(nodoArbolC* arbol);
	nodoArbolC* buscar(nodoArbolC* arbol, char caracter, bool& encontrado);

public://métodos
	Caezar();//Constructor
	~Caezar();//Destructor
	void ingresar(char, int, char);
	void ver();
	char encontrar(char);
};