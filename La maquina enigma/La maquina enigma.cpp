// La maquina enigma.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

//Inclusión de librerias
#ifdef _WIN32
#include <Windows.h>
#include <conio.h>
#else
#include <conio.h>
#endif


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>//para cambiar el idioma de la consola
#include <iomanip>//para poder manipular el texto mostrado en consola
#include <fstream>//para leer y escribir archivos, aún no implementado
#include <string.h>//para poder partir el texto introducido en caracteres
#include <cctype>
#include <thread>//para la programación por hilos, aún no implementado

//inclución de clases personales
#include "Atbash.h"
#include "Caezar.h"

#define color SetConsoleTextAttribute

using namespace std;

//Creación de  objetos de clases
Atbash primero;
Caezar segundo;

//prototipado de funciones
void Portada(void);
void Menu(void);
//Inserción
void manual(void);
void documentoTexto(void);
//Cifrados
/*En estás funciones se realizan cada uno de los cifrados por independiente*/
void CAtbash();
void CCaezar(char textoA[], int);
//llenado de árboles cifrados
void llenadoAtbash(char abecedario[], int, int espacio[], int,char abecedarioA[],int);
void llenadoCaezar(char abecedario[], int, int espacio[], int,char abecedarioC[],int);
//salida
void Resultado(void);

//declaración de variables globales
const int capacidad = 1000;
char texto[capacidad], textoA[capacidad], textoC[capacidad];

string nombre;//variable para el uso del archivo .txt 

const int TAM = 95;
char abecedario[TAM] = { 'A','a','B','b','C','c','D','d','E','e','F','f','G','g','H','h','I','i','J','j','K','k','L','l','M','m','N','n','O','o','P','p','Q','q','R','r','S','s','T','t',
'U','u','V','v','W','w','X','x','Y','y','Z','z',' ','!','"','#','$','%','&','\39','(',')','*','\43',',','\45','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@',
'[','\92',']','\94','_','\96','{','\124','}','~'};

char abecedarioA[TAM] = { 'Z','z','Y','y','X','x','W','w','V','v','U','u','T','t','S','s','R','r','Q','q','P','p','O','o','N','n','M','m','L','l','K','k','J','j','I','i','H','h','G','g','F','f',
'E','e','D','d','C','c','B','b','A','a',' ','!','"','#','$','%','&','\39','(',')','*','\43',',','\45','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@',
'[','\92',']','\94','_','\96','{','\124','}','~' };

char abecedarioC[TAM] = {'X','x','Y','y','Z','z','A','a','B','b','C','c','D','d','E','e','F','f','G','g','H','h','I','i','J','j','K','k','L','l','M','m','N','n','O','o','P','p','Q','q','R','r','S','s',
'T','t','U','u','V','v','W','w',' ','!','"','#','$','%','&','\39','(',')','*','\43',',','\45','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@',
'[','\92',']','\94','_','\96','{','\124','}','~' };

int espacio[TAM]={65,97,66,98,67,99,68,100,69,101,70,102,71,103,72,104,73,105,74,106,75,107,76,108,77,109,78,110,79,111,80,112,81,113,82,114,83,115,84,116,85,117,86,118,87,119,88,120,89,121,90,122,
32,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,91,92,93,94,95,96,123,124,125,126};

int main() {
	
	//Portada();
	setlocale(LC_ALL, "spanish");
	
	//Cuerpo del programa
	llenadoAtbash(abecedario, TAM, espacio, TAM, abecedarioA, TAM);
	llenadoCaezar(abecedario, TAM, espacio, TAM, abecedarioC, TAM);

	/*
	Código temporal utilizado para depuración de búsqueda de cracteres en el árbol
	char trozo,salida,salida2;
	cout << "Ingrese un caracter a buscar: ";
	cin >> trozo;
	salida = primero.encontrar(trozo);
	cout << endl << endl << "La salida es: " << salida << endl;
	salida2 = segundo.encontrar(trozo);
	cout << endl << endl << "La salida es: " << salida2 << endl;
	*/
	
	//código temporal para probar el programa
	manual();
	//Menu();
	
	//parte final del código
	cout << "Esta es la parte final del programa" << endl;
	cout << "Que la fuerza de velocidad te acompañe" << endl << endl;
#ifdef _WIN32
	system("pause");
#else
	getch();
#endif
	/*
	delete texto;
	delete textoA;
	delete textoC;*/
	return 0;
	
}
//fin del código principal del programa

//definición de funciones
void Portada() {
	HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
	char progreso = char(219);
	/*convierte el numero 219 en su equivalente al código ascii, esto se utiliza para mostrar el progreso de la barra*/

	char barra[31] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' '
					,' ',' ',' ',' ',' ',' ',' ',' ',' ',' '
					,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',0 };
	/*En este arreglo, se mostrará el progreso*/
	int tiempoFaltante = 30;

	for (int contador = 0; contador < 30; contador++) {
		barra[contador] = progreso;
		/*llena el arreglo con el caracter 219*/
#ifdef _WIN32
		Sleep(1000);
		system("cls");
#else
		sleep(1000);
		clrscr();
#endif
		tiempoFaltante--;
		cout << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << "                        |--------------------------------------------------------------|" << endl;
		cout << "                        |                  INSTITUTO POLITCNICO NACIONAL               |" << endl;
		cout << "                        |      Escuela Superior de Ingeier¡a Mec nica y electr¢nica    |" << endl;
		cout << "                        |                        Unidad Culhuac n                      |" << endl;
		cout << "                        |              Nombre: Mej¡a Casta¤eda Bryan Emmanuel          |" << endl;
		cout << "                        |                     Materia: Estructura de datos             |" << endl;
		cout << "                        |                    Proyecto: La máquina enigma               |" << endl;
		cout << "                        |                          Grupo: 3CV25                        |" << endl;
		cout << "                        |                   Profesor: Cruz Garc¡a Oscar                |" << endl;
		cout << "                        |______________________________________________________________|" << endl << endl;
		cout << "                                   Esta portada se quitar  en 30 segundos" << endl;
		cout << "                               Recuerda que s¡ pudes imaginarlo, puedes programarlo" << endl << endl;

		cout << setw(40) << "Faltan " << tiempoFaltante << " segundos para que desaparesca la portada" << endl << endl;
		color(consola, 11);
		cout << setw(70) << barra << endl;
		color(consola, 7);

		if (tiempoFaltante == 0) {
#ifdef _WIN32
			system("cls");
#else
			clrscr();
#endif

			cout << endl << endl << endl << endl << endl << endl << endl << endl;
			cout << "                        |--------------------------------------------------------------|" << endl;
			cout << "                        |                  INSTITUTO POLITCNICO NACIONAL               |" << endl;
			cout << "                        |      Escuela Superior de Ingeier¡a Mec nica y electr¢nica    |" << endl;
			cout << "                        |                        Unidad Culhuac n                      |" << endl;
			cout << "                        |              Nombre: Mej¡a Casta¤eda Bryan Emmanuel          |" << endl;
			cout << "                        |                     Materia: Estructura de datos             |" << endl;
			cout << "                        |                    Proyecto: La máquina enigma               |" << endl;
			cout << "                        |                          Grupo: 3CV25                        |" << endl;
			cout << "                        |                   Profesor: Cruz Garc¡a Oscar                |" << endl;
			cout << "                        |______________________________________________________________|" << endl << endl;
			cout << "                                   Esta portada se quitar  en 30 segundos" << endl;
			cout << "                               Recuerda que s¡ pudes imaginarlo, puedes programarlo" << endl << endl;

			cout << setw(40) << "Faltan " << tiempoFaltante << " segundos para que desaparesca la portada" << endl << endl;
			color(consola, 10);
			cout << setw(70) << barra << endl;
			color(consola, 7);
		}

		/*Muestra el progreso*/
	}
#ifdef _WIN32
	Sleep(1000);
	system("cls");
#else
	sleep(1000);
	clrscr();
#endif
}

void Menu() {
	int opc = 0;
	cout << "\tMenu" << endl;
	cout << "1. Cifrar un texto ingresado manualmente" << endl;
	cout << "2. Cifrar un documento de texto" << endl;
	cout << "3. Salir" << endl;
	cout << "Ingrese el número de su opción: ";
	cin >> opc;
	switch (opc) {
	case 1:
		cin.ignore();//libero el búfer del teclado
		manual();
		break;
	case 2:
		cin.ignore();
		documentoTexto();
		break;
	case 3:
		cout << "mamahuevo" << endl;
		break;
	default:
		cout << "Error, opción inválida por favor vuelva a intentar" << endl;
	}
}

//Inserción de texto a cifrar
void manual() {
	cout << "Ingrese el texto a cifrar: "<<endl;
	cin.getline(texto, 1000, '\n');//parte el texto ingresado por letras
	/*
	for (int i = 0; i < strlen(texto); i++) {//para saber que hay en cada espacio del arreglo
		cout << texto[i] << endl;
	}*/
	CAtbash();
}

void documentoTexto() {

	cout << "Atención debe ser un archivo .txt" << endl;
	cout << "Ingrese el nombre del archivo de texto a cifrar sin la extención del archivo: ";
	cin >> nombre;
	nombre = nombre + ".txt";//concateno el nombre del archivo con la terminación .txt
	/*Falta hacer el código correspondiente para leer el archivo*/
}

// Cifrados
void CAtbash() {
	char caracter = NULL,salida;
	for (int i = 0; i <strlen(texto); i++) {//para recorrer el arreglo mientras no haya un caracter nulo \n
		caracter = texto[i];
		textoA[i] = primero.encontrar(caracter);
		Sleep(250);
	}
	CCaezar(textoA,capacidad);
}

void CCaezar(char textoA[],int capacidad) {
	for (int i = 0; i < strlen(textoA); i++) {
		textoC[i] = segundo.encontrar(textoA[i]);
	}
}

//lenado de árboles cifrados
void llenadoAtbash(char abecedario[],int tam_letra,int espacio[],int tam_espacio,char abecedarioA[],int tam) {
	char caracter=NULL;
	int indice=NULL;
	char aux = NULL;
	for (int i = 0; i < 95; i++) {
		caracter = abecedario[i];
		indice = espacio[i];
		aux = abecedarioA[i];
		primero.ingresar(caracter, indice,aux);
		//primero.ver();
	}
}

void llenadoCaezar(char abecedario[],int tam_letra, int espacio[],int tam_espacio,char abecedarioC[],int tam) {
	char caracter = NULL;
	int indice = NULL;
	char aux = NULL;
	for (int i = 0; i < 95; i++) {
		caracter = abecedario[i];
		indice = espacio[i];
		aux = abecedarioC[i];
		segundo.ingresar(caracter, indice, aux);
		//segundo.ver();
	}
}

//salida
void Resultado() {
	/*Aquí irá el código para guardar el resultado del cifrado en un archivo de texto*/
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
