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
char texto[capacidad]={'t','r','o','z','o'}, textoA[capacidad], textoC[capacidad];
string nombre;//variable para el uso del archivo .txt 

const int TAM = 95;
char abecedario[TAM] = { '/','O','7','<','X','"','i','3','B','>','~','F','Q','a','P','Y','6','%','e',' ','u','I','c','V','{',';','L','t','n','b','5','|','H','[','p','E','A','D','`','U','&',')','\\','g','v','N','o','f','R','M','z','=','W','y','J','$','}','#','(','8','9','_','+','Z','h','0',':','^',',','2','-','1','w','S',']','G','?','T','r','x','*','k','4','d','C','@','m','q','.','j','\'','s','l','K','!' };
 
char abecedarioA[TAM] = { '/','L','7','<','X','"','r','3','Y','>','~','U','J','z','K','B','6','%','v',' ','f','R','x','E','{',';','O','G','m','y','5','|','S','[','k','V','Z','W','`','F','&',')','\\','t','e','M','l','u','i','N','a','=','D','b','Q','$','}','#',')','8','9','_','+','A','s','0',':','^','2','-','1','d','H',']','T','?','G','i','c','*','p','4','w','x','@','n','j','.','q','\'','h','o','p','!' };

char abecedarioC[TAM] = { '/','L','7','<','U','"','f','3','Y','>','~','C','N','x','M','V','6','%','b',' ','r','F','z','S','{',';','i','q','k','y','5','|','E','[','m','B','X','A','`','R','&',')','\\','d','s','K','l','c','O','J','w','=','T','v','G','$','}','#','(','8','9','_','+','W','e','0',':','^',',','2','-','1','t','P',']','D','?','Q','o','u','*','h','4','a','Z','@','j','n','.','g','\'','p','i','H','!'};

int espacio[TAM]={47,79,55,60,88,34,105,51,66,62,126,70,81,97,80,89,54,37,101,32,117,73,99,86,123,59,76,116,110,98,53,124,72,91,112,69,65,68,96,85,38,41,92,103,118,78,111,102,82,77,122,61,87,121,74,36,125,35,40,56,57,95,43,90,104,48,58,94,44,50,45,49,119,83,93,71,63,84,114,120,42,107,52,100,67,64,109,113,46,106,39,115,108,75,33};

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
	/*cout << "Ingrese el texto a cifrar: " << endl;
	cin.getline(texto, 1000, '\n');//parte el texto ingresado por letras*/
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
	int entero = NULL;
	for (int i = 0; i <strlen(texto); i++) {//para recorrer el arreglo mientras no haya un caracter nulo \n
		caracter = texto[i];//guardo el caracter en una variable
		entero=int(caracter);//convierto el caracter a su valor en la tabla ASCII
		/*textoA[i] = */ primero.buscar(entero);//busco el caracter en el árbol
	}
	CCaezar(textoA,capacidad);
}

void CCaezar(char textoA[],int capacidad) {
	char caracter = NULL,salida;
	int entero = NULL;
	for (int i = 0; i < strlen(textoA); i++) {
		caracter = textoA[i];
		entero=int(caracter);
		/*textoC[i] = */ segundo.encontrar(entero);
	}
}

//lenado de árboles cifrados
void llenadoAtbash(char abecedario[],int tam_letra,int espacio[],int tam_espacio,char abecedarioA[],int tam) {
	char caracter=NULL;
	int indice=NULL;
	char salida = NULL;

	for (int i = 0; i < 95; i++) {
		caracter = abecedario[i];
		indice = espacio[i];
		salida = abecedarioA[i];
		primero.ingresar(caracter, indice,salida);
	}
	primero.ver();
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
