#ifndef PORTADA_H
#define PORTADA_H

#include <string>

using namespace std;

class Portada {
public:
	//Constructor
	Portada();
	//Destructor
	~Portada();
	void mostrarPortada();
protected:
	void irA(int, int);
	void ocultarCursor();
	void mostrarCursor();
	void portada();
	void animacion();
};

#endif