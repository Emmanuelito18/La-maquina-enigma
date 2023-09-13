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
#include <fstream>//para leer y escribir archivos
#include <string>//para poder partir el texto introducido en caracteres
#include <cctype>//para poder convertir los caracteres a su valor en la tabla ASCII
#include <thread>//para la programación por hilos
#include <vector>//para poder utilizar arreglos dinamicos

//inclución de clases personales
#include "Atbash.h"
#include "Caezar.h"
#include "A1Z26.h"

#define color SetConsoleTextAttribute

using namespace std;

//Creación de  objetos de clases
Atbash atbash;
Caezar caezar;
A1Z26 a1z26;

//prototipado de funciones
void Portada(void);
void Menu(void);
//Inserción
void manual(void);
void lecturaDocumento(void);
//Cifrados
/*En estás funciones se realizan cada uno de los cifrados por independiente*/
void CAtbash(void);
void CCaezar(void);
void CA1Z26(void);
//llenado de árboles cifrados
void llenadoAtbash(char abecedario[], int, int espacio[], int,char abecedarioA[],int);
void llenadoCaezar(char abecedario[], int, int espacio[], int,char abecedarioC[],int);
void llenadoAZ(char abecedario[], int, int espacio[], int,string abecedarioAZ[],int);
//salida
void nombradoArchivo(void);
void escrituraDocumento(void);

//declaración de variables globales
/*const int capacidad = 1000;//capacidad del arreglo
char texto[capacidad], textoA[capacidad], textoC[capacidad];//arreglo para guardar el texto a cifrar
string textoAZ[capacidad];//arreglo para guardar el texto cifrado*/

vector<char>texto;//Se usa para guardar el texto ingresado por el usuario por caracteres
vector<char>textoA;//e usa para guardar el texto cifrado por caracteres
vector<char>textoC;//Se usa para guardar el texto cifrado por caracteres
vector<string>textoAZ;//Se usa para guardar el texto cifrado por caracteres
string ingresion;//Se usa para guardar el texto ingresado por el usuario

const int TAM = 95;
char abecedario[TAM] = { '/','O','7','<','X','"','i','3','B','>','~','F','Q','a','P','Y','6','%','e',' ','u','I','c','V','{',';','L','t','n','b','5','|','H','[','p','E','A','D','`','U','&',')','\\','g','v','N','o','f','R','M','z','=','W','y','J','$','}','#','(','8','9','_','+','Z','h','0',':','^',',','2','-','1','w','S',']','G','?','T','r','x','*','k','4','d','C','@','m','q','.','j','\'','s','l','K','!' };
 
char abecedarioA[TAM] = { '/','L','7','<','C','"','r','3','Y','>','~','U','J','z','K','B','6','%','v',' ','f','R','x','E','{',';','O','g','m','y','5','|','S','[','k','V','Z','W','`','F','&',')','\\','t','e','M','l','u','I','N','a','=','D','b','Q','$','}','#',')','8','9','_','+','A','s','0',':','^',',','2','-','1','d','H',']','T','?','G','i','c','*','p','4','w','X','@','n','j','.','q','\'','h','o','P','!' };

char abecedarioC[TAM] = { '/','L','7','<','U','"','f','3','Y','>','~','C','N','x','M','V','6','%','b',' ','r','F','z','S','{',';','i','q','k','y','5','|','E','[','m','B','X','A','`','R','&',')','\\','d','s','K','l','c','O','J','w','=','T','v','G','$','}','#','(','8','9','_','+','W','e','0',':','^',',','2','-','1','t','P',']','D','?','Q','o','u','*','h','4','a','Z','@','j','n','.','g','\'','p','i','H','!'};

string abecedarioAZ[TAM] = { " 41"," 15"," 49"," 54"," 24"," 28"," 67"," 45"," 2"," 56"," 94"," 6"," 17"," 59"," 16"," 83"," 48"," 37"," 63"," "," 79"," 9"," 61"," 22"," 91"," 53"," 12"," 78"," 72"," 60"," 47"," 92"," 8"," 85"," 74"," 5"," 1"," 4"," 90"," 21"," 32"," 35"," 86"," 65"," 79"," 14"," 73"," 64"," 18"," 13"," 84"," 55"," 23"," 68"," 10"," 30"," 93"," 29"," 34"," 50"," 51"," 89"," 37"," 26",
" 66"," 42"," 52"," 88"," 38"," 44"," 39"," 43"," 81"," 19"," 87"," 7"," 57"," 20"," 76"," 82"," 36"," 69"," 46"," 62"," 3"," 58"," 71"," 75"," 40"," 77"," 70"," 11"," 27" };

int espacio[TAM]={47,79,55,60,88,34,105,51,66,62,126,70,81,97,80,89,54,37,101,32,117,73,99,86,123,59,76,116,110,98,53,124,72,91,112,69,65,68,96,85,38,41,92,103,118,78,111,102,82,77,122,61,87,121,74,36,125,35,40,56,57,95,43,90,104,48,58,94,44,50,45,49,119,83,93,71,63,84,114,120,42,107,52,100,67,64,109,113,46,106,39,115,108,75,33};

ofstream archivoSalida;//creo un objeto de la clase ofstream
bool llamada = false;//para saber si se ha llamado a la función para nombrar el archivo
string direccion, nombreArchivo;//para guardar la dirección y el nombre del archivo
int main() {
	//Cuerpo del programa
	thread hiloPortada(Portada);//creo un hilo para la portada
	thread hilollenadoAtbash(llenadoAtbash, abecedario, TAM, espacio, TAM, abecedarioA, TAM);//creo un hilo para el llenado de atbash
	thread hilollenadoCaezar(llenadoCaezar, abecedario, TAM, espacio, TAM, abecedarioC, TAM);//creo un hilo para el llenado de caezar
	thread hilollenadoAZ(llenadoAZ, abecedario, TAM, espacio, TAM, abecedarioAZ, TAM);//creo un hilo para el llenado de A1Z26

	hiloPortada.join();
	hilollenadoAtbash.join();
	hilollenadoCaezar.join();
	hilollenadoAZ.join();
	
	Menu();
	//parte final del código
	archivoSalida.close();//cierro el archivo
	setlocale(LC_ALL, "spanish");//Cambio el idioma de la consola a español
	cout << "Esta es la parte final del programa" << endl;
	cout << "Que la fuerza de velocidad te acompañe" << endl << endl;
#ifdef _WIN32
	system("pause");
#else
	getch();
#endif
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
		cout << "                        |                 INSTITUTO POLITECNICO NACIONAL               |" << endl;
		cout << "                        |     Escuela Superior de Ingenieria Mecanica y electronica    |" << endl;
		cout << "                        |                        Unidad Culhuacan                      |" << endl;
		cout << "                        |              Nombre: Mejia Castaneda Bryan Emmanuel          |" << endl;
		cout << "                        |                     Materia: Estructura de datos             |" << endl;
		cout << "                        |                    Proyecto: La maquina enigma               |" << endl;
		cout << "                        |                          Grupo: 3CV25                        |" << endl;
		cout << "                        |                   Profesor: Cruz Garcia Oscar                |" << endl;
		cout << "                        |______________________________________________________________|" << endl << endl;
		cout << "                                   Esta portada se quitara en 30 segundos" << endl;
		cout << "                               Recuerda que si pudes imaginarlo, puedes programarlo" << endl << endl;

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
			cout << "                        |                 INSTITUTO POLITECNICO NACIONAL               |" << endl;
			cout << "                        |     Escuela Superior de Ingenieria Mecanica y electronica    |" << endl;
			cout << "                        |                        Unidad Culhuacan                      |" << endl;
			cout << "                        |              Nombre: Mejia Castaneda Bryan Emmanuel          |" << endl;
			cout << "                        |                     Materia: Estructura de datos             |" << endl;
			cout << "                        |                    Proyecto: La maquina enigma               |" << endl;
			cout << "                        |                          Grupo: 3CV25                        |" << endl;
			cout << "                        |                   Profesor: Cruz Garcia Oscar                |" << endl;
			cout << "                        |______________________________________________________________|" << endl << endl;
			cout << "                                   Esta portada se quitara en 30 segundos" << endl;
			cout << "                               Recuerda que si pudes imaginarlo, puedes programarlo" << endl << endl;

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
	do {
		cout << "\tMenu" << endl;
		cout << "1. Cifrar un texto ingresado manualmente" << endl;
		cout << "2. Cifrar un documento de texto" << endl;
		cout << "3. Salir" << endl;
		cout << "Ingrese el numero de su opcion: ";
		cin >> opc;
		switch (opc) {
		case 1:
			cin.ignore();//libero el búfer del teclado
			manual();
			opc= 3;//para que salga del ciclo
			break;
		case 2:
			cin.ignore();
			lecturaDocumento();
			opc = 3;//para que salga del ciclo
			break;
		case 3:
			break;
		default:
			cout << "Error, opcion invalida por favor vuelva a intentar" << endl;
		}
#ifdef _WIN32
		Sleep(2000);
		system("cls");
#else
		sleep(2000);
		clrscr();
#endif
	}
	while (opc != 3);
}

//Inserción de texto a cifrar
void manual() {
	HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
	color(consola, 14);//color amarillo
	cout<<"Atencion, el programa solo acepta caracteres disponibles en el teclado en INGLES"<<endl;
	color(consola, 7);//color blanco
	cout << "Ingrese el texto a cifrar: " << endl;
	//cin.getline(texto, 1000, '\n');//parte el texto ingresado por letras

	getline(cin, ingresion);//guardo el texto ingresado en una variable
	for (char c : ingresion) {//recorro el texto ingresado
		texto.push_back(c);//guardo el texto ingresado en un arreglo
	}
	color(consola, 10);//color verde
	cout<<"Un momento por favor, el programa esta cifrando el texto"<<endl;
	color(consola, 7);//color blanco
#ifdef _WIN32
	Sleep(5000);
	system("cls");
#else
	sleep(5000);
	clrscr();
#endif
	nombradoArchivo();//llamo a la función para nombrar el archivo
	CAtbash();
}

void lecturaDocumento() {
	HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
	ifstream archivo;
	string nombre;//variable para el uso del archivo .txt 
	color(consola, 14);//color amarillo
	cout << "Atencion debe ser un archivo .txt, para que sea más fácil tenga el archivo de texto en el ESCRITORIO" << endl;
	cout << "El programa solo acepta caracteres disponibles en el teclado INGLES" << endl;
	color(consola, 7);//color blanco
	cout << "Ingrese la direccion completa del archivo de texto a cifrar sin la extencion del archivo: ";
	cin >> nombre;
	nombre = nombre + ".txt";//concateno el nombre del archivo con la terminación .txt
	
	archivo.open(nombre.c_str(), ios::in);//abro el archivo en modo lectura

	if (archivo.fail()) {//si no se pudo abrir el archivo
		cout << "No se pudo abrir el archivo" << endl;
		exit(1);
	}
	color(consola, 10);//color verde
	cout << "Un momento por favor, el programa esta cifrando el texto" << endl;
	color(consola, 7);//color blanco
#ifdef _WIN32
	Sleep(5000);
	system("cls");
#else
	sleep(5000);
	clrscr();
#endif
	nombradoArchivo();//llamo a la función para nombrar el archivo

	/*while (archivo.getline(texto, capacidad)) {
		//cout << texto << endl;
		CAtbash();
		for (int i = 0; i < capacidad; i++) {
			texto[i]= NULL;
		}
	}*/

	while (getline(archivo, ingresion)) {
		for (char c : ingresion) {//recorro el texto ingresado
					texto.push_back(c);//guardo el texto ingresado en un arreglo
			}
		texto.push_back('\n');
	}

	if (archivo.eof()) {
		cout << "Lectura del archivo completada" << endl;
		CAtbash();
	}
	else if (archivo.fail()) {
		cout<<"Error al leer el archivo"<<endl;
	}
	archivo.close();//cierro el archivo
}

// Cifrados
//Función para cifrar con el método Atbash
void CAtbash() {
	char caracter = NULL;
	int entero = NULL;
	//cout<<"imprimiendo el resultado de Atbash"<<endl;
	/*for (int i = 0; i <strlen(texto); i++) {//para recorrer el arreglo mientras no haya un caracter nulo \n
		caracter = texto[i];//guardo el caracter en una variable
		entero=int(caracter);//convierto el caracter a su valor en la tabla ASCII
		textoA[i] = atbash.cifrar(entero);//busco el caracter en el árbol
	}*/

	for (char c : texto) {
		entero=int(c);//convierto el caracter a su valor en la tabla ASCII
		textoA.push_back(atbash.cifrar(entero));//busco el caracter en el árbol
	}
	CCaezar();
}

//Función para cifrar con el método Caezar
void CCaezar() {
	char caracter = NULL;
	int entero = NULL;
	//cout<<"imprimiendo el resultado de Caezar"<<endl;
	/*for (int i = 0; i < strlen(textoA); i++) {//para recorrer el arreglo mientras no haya un caracter nulo \n
		caracter = textoA[i];//guardo el caracter en una variable
		entero=int(caracter);//convierto el caracter a su valor en la tabla ASCII
		textoC[i] = caezar.cifrar(entero);//busco el caracter en el árbol
	}*/

	for (char c : textoA) {
		entero = int(c);//convierto el caracter a su valor en la tabla ASCII
		textoC.push_back(caezar.cifrar(entero));//busco el caracter en el árbol
	}
	CA1Z26();
}

//Función para cifrar con el método A1Z26
void CA1Z26() {
	char caracter = NULL;
	int entero = NULL;
	//cout << "imprimiendo el resultado de A1Z26" << endl;
	/*for (int i = 0; i < strlen(textoC); i++) {
		caracter = textoC[i];
		entero = int(caracter);
		textoAZ[i] = a1z26.cifrar(entero);
	}*/

	for (char c : textoC) {
		entero = int(c);//convierto el caracter a su valor en la tabla ASCII
		textoAZ.push_back(a1z26.cifrar(entero));//busco el caracter en el árbol
	}
	escrituraDocumento();
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
		atbash.ingresar(caracter, indice,salida);
	}
	/*cout << "Mostrando árbol de Atbash" << endl;
	atbash.ver();*/
}

void llenadoCaezar(char abecedario[],int tam_letra, int espacio[],int tam_espacio,char abecedarioC[],int tam) {
	char caracter = NULL;
	int indice = NULL;
	char salida = NULL;
	for (int i = 0; i < 95; i++) {
		caracter = abecedario[i];
		indice = espacio[i];
		salida = abecedarioC[i];
		caezar.ingresar(caracter, indice, salida);
	}
	/*cout << "Mostrando árbol de Caezar" << endl;
	caezar.ver();*/
}

void llenadoAZ(char abecedario[], int tam_letra, int espacio[], int tam_espacio, string abecedarioAZ[], int tam) {
	char caracter = NULL;
	int indice = NULL;
	string salida;
	for (int i = 0; i < 95; i++) {
		caracter = abecedario[i];
		indice = espacio[i];
		salida = abecedarioAZ[i];
		a1z26.ingresar(caracter, indice, salida);
	}
	/*cout << "Mostrando árbol de A1Z26" << endl;
	a1z26.ver();*/
}

//salida
void nombradoArchivo() {
	HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
	//obtengo la dirección del escritorio
	char respuesta = '\0';
	char* carpetaUsuario = nullptr;
	size_t tamanoCarpetaUsuario;
	errno_t error = _dupenv_s(&carpetaUsuario, &tamanoCarpetaUsuario, "USERPROFILE");
	if (error == 0 && carpetaUsuario != nullptr) {
		direccion = carpetaUsuario;
		direccion += "\\Desktop\\";
		free(carpetaUsuario); // Liberar la memoria asignada por _dupenv_s()
	}
	else {
		cout << "Error al obtener la direccion del escritorio" << endl;
		exit(1);
	}

	cout << "Quiere nombrar el archivo de salida? (s/n)" << endl;
	cin >> respuesta;
	if (respuesta == 's' || respuesta == 'S') {
		color(consola, 14);//color amarillo
		cout << "Ingrese el nombre del archivo SIN la extencion .txt" << endl;
		cout << "El archivo se guardara en el escritorio" << endl;
		color(consola, 7);//color blanco
		cin >> nombreArchivo;//guardo el nombre del archivo
		nombreArchivo = nombreArchivo + ".txt";//concateno el nombre del archivo con la extencion .txt
		direccion = direccion + nombreArchivo;//concateno la direccion con el nombre del archivo
	}
	else {
		direccion = direccion + "Cifrado.txt";//concateno la direccion con el nombre del archivo
	}
	archivoSalida.open(direccion.c_str(), ios::out);//abro el archivo en modo escritura
	if (archivoSalida.fail()) {//si no se pudo abrir el archivo
		cout << "No se pudo abrir el archivo" << endl;
		exit(1);//salgo del programa
	}
	else {
		cout << "Archivo creado correctamente" << endl;

	}
}
void escrituraDocumento() {
	HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
	string cifrado;//variable para guardar el nombre del archivo

	//recorro el arreglo de cifrado concatenando el contenido
	/*for (int i = 0; i < capacidad; i++) {
		if (textoAZ[i].empty()) {//si el arreglo esta vacio
			break;//salgo del ciclo

		}
		cifrado = cifrado + textoAZ[i];//concateno el contenido del arreglo en una variable
	}*/

	for (string c : textoAZ) {
		cifrado = cifrado + c;//concateno el contenido del arreglo en una variable
	}
	archivoSalida << cifrado << endl;//escribo en el archivo
}
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
