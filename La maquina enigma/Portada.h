#ifndef PORTADA_H
#define PORTADA_H

#include <string>

using namespace std;

class Portada {
private:
	string materia, grupo, profesor;
public:
	//Constructor
	Portada();
	//Destructor
	~Portada();
	void mostrarPortada();
	void setVariables(string, string, string);//método setter
protected:
	void irA(int, int);
	void ocultarCursor();
	void mostrarCursor();
	void portada();
	void animacion();
};

#endif