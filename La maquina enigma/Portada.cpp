#include "Portada.h"
#include <iostream>
#include <windows.h>//para las funciones sleep y coord
#include <locale.>
#include <string>
#include <mmsystem.h>//para la función Playsound
#pragma comment(lib,"winmm.lib")//para la función Playsound

using namespace std;

//Constructor
Portada::Portada() {
}

//Destructor
Portada::~Portada() {
}

void Portada::mostrarPortada() {
	system("color 1f");//cambia el color de la consola a fondo azul y texto blanco
	portada();//llama a la función portada
	system("pause");
	system("cls");
	system("color 0f");//pone el color de la consola al establecido por defecto configurado
	mostrarCursor();
	//Aquí se pondrá el resto del programa
}

//establecemos valores a los atributos 
void Portada::setVariables(string _materia, string _grupo, string _profesor) {
	materia = _materia;
	grupo = _grupo;
	profesor = _profesor;
}

void Portada::irA(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//modifica la ubicacion del cursor de la consola
}

void Portada::ocultarCursor() {
	CONSOLE_CURSOR_INFO cci = { 100,FALSE };

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);//oculta el cursor de la consola
}

void Portada::mostrarCursor() {
	CONSOLE_CURSOR_INFO cci = { 100,TRUE };

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);//oculta el cursor de la consola
}

void Portada::portada() {
	ocultarCursor();//llama a la función ocultaCursor
	animacion();//llama a la función para comenzar la animación
	setlocale(LC_ALL, "spanish");//se cambia la lozalizacion de la consola a español
	irA(50, 15);//cambia la posición del cursor para mostrar texto final de la portada
	cout << "INSTITUTO POLITÉCNICO NACIONAL";
	irA(35, 16);
	cout << "Escuela Superior de Ingieniería Mecánica y electrónica";
	irA(55, 17);
	cout << "Unidad Culhuacán";
	irA(45, 18);
	cout << "Nombre: Mejía Castañeda Bryan Emmanuel";
	irA(53, 19);
	cout << "Materia: " << materia;
	irA(55, 20);
	cout << "Grupo: " << grupo;
	irA(40, 21);
	cout << "Profesor: " << profesor;
	irA(35, 23);
	cout << "Recuerda que si puedes imaginarlo, puedes programarlo" << endl;
	irA(40, 25);//regresa el cursor a suposición original
	setlocale(LC_ALL, "C");//Se cambia la localización de la consola a la original
}

void Portada::animacion() {//cada parte de la animacion se hace imprimiendo partes de las letras mediante la función irA
	irA(45, 2);
	cout << "Este programa ha sido creado por:" << endl;
	//crea la letra E
	//linea 1
	irA(29, 4);
	cout << (char)219;
	irA(29, 5);
	cout << (char)219;
	irA(29, 6);
	cout << (char)219;
	irA(29, 7);
	cout << (char)219;
	irA(29, 8);
	cout << (char)219;
	irA(29, 9);
	cout << (char)219;
	irA(29, 10);
	cout << (char)219;
	irA(29, 11);
	cout << (char)219;
	irA(29, 12);
	cout << (char)219;
	Sleep(50);
	//linea 2
	irA(30, 4);
	cout << (char)219;
	irA(30, 5);
	cout << (char)178;
	irA(30, 6);
	cout << (char)178;
	irA(30, 7);
	cout << (char)178;
	irA(30, 8);
	cout << (char)219;
	irA(30, 9);
	cout << (char)178;
	irA(30, 10);
	cout << (char)178;
	irA(30, 11);
	cout << (char)178;
	irA(30, 12);
	cout << (char)219;
	Sleep(50);
	//linea 3
	irA(31, 4);
	cout << (char)219;
	irA(31, 5);
	cout << (char)178;
	irA(31, 8);
	cout << (char)219;
	irA(31, 9);
	cout << (char)178;
	irA(31, 12);
	cout << (char)219;
	Sleep(50);
	//linea 4
	irA(32, 4);
	cout << (char)219;
	irA(32, 5);
	cout << (char)178;
	irA(32, 8);
	cout << (char)178;
	irA(32, 9);
	cout << (char)178;
	irA(32, 12);
	cout << (char)219;
	Sleep(50);
	//linea 5
	irA(33, 4);
	cout << (char)178;
	irA(33, 5);
	cout << (char)178;
	irA(33, 12);
	cout << (char)178;
	Sleep(50);
	//crea la letra M
	//linea 1
	irA(34, 4);
	cout << (char)219;
	irA(34, 5);
	cout << (char)219;
	irA(34, 6);
	cout << (char)219;
	irA(34, 7);
	cout << (char)219;
	irA(34, 8);
	cout << (char)219;
	irA(34, 9);
	cout << (char)219;
	irA(34, 10);
	cout << (char)219;
	irA(34, 11);
	cout << (char)219;
	irA(34, 12);
	cout << (char)219;
	Sleep(50);
	//linea 2
	irA(35, 4);
	cout << (char)178;
	irA(35, 5);
	cout << (char)219;
	irA(35, 6);
	cout << (char)219;
	irA(35, 7);
	cout << (char)178;
	irA(35, 8);
	cout << (char)178;
	irA(35, 9);
	cout << (char)178;
	irA(35, 10);
	cout << (char)178;
	irA(35, 11);
	cout << (char)178;
	irA(35, 12);
	cout << (char)178;
	Sleep(50);
	//linea 3
	irA(36, 5);
	cout << (char)178;
	irA(36, 6);
	cout << (char)178;
	irA(36, 7);
	cout << (char)219;
	irA(36, 8);
	cout << (char)219;
	Sleep(50);
	//linea 4
	irA(37, 5);
	cout << (char)219;
	irA(37, 6);
	cout << (char)219;
	irA(37, 7);
	cout << (char)178;
	irA(37, 8);
	cout << (char)178;
	Sleep(50);
	//linea 5
	irA(38, 4);
	cout << (char)219;
	irA(38, 5);
	cout << (char)219;
	irA(38, 6);
	cout << (char)219;
	irA(38, 7);
	cout << (char)219;
	irA(38, 8);
	cout << (char)219;
	irA(38, 9);
	cout << (char)219;
	irA(38, 10);
	cout << (char)219;
	irA(38, 11);
	cout << (char)219;
	irA(38, 12);
	cout << (char)219;
	Sleep(50);
	//linea 6
	irA(39, 4);
	cout << (char)178;
	irA(39, 5);
	cout << (char)178;
	irA(39, 6);
	cout << (char)178;
	irA(39, 7);
	cout << (char)178;
	irA(39, 8);
	cout << (char)178;
	irA(39, 9);
	cout << (char)178;
	irA(39, 10);
	cout << (char)178;
	irA(39, 11);
	cout << (char)178;
	irA(39, 12);
	cout << (char)178;
	Sleep(50);
	//crea la letra M
	//linea 1
	irA(40, 4);
	cout << (char)219;
	irA(40, 5);
	cout << (char)219;
	irA(40, 6);
	cout << (char)219;
	irA(40, 7);
	cout << (char)219;
	irA(40, 8);
	cout << (char)219;
	irA(40, 9);
	cout << (char)219;
	irA(40, 10);
	cout << (char)219;
	irA(40, 11);
	cout << (char)219;
	irA(40, 12);
	cout << (char)219;
	Sleep(50);
	//linea 2
	irA(41, 4);
	cout << (char)178;
	irA(41, 5);
	cout << (char)219;
	irA(41, 6);
	cout << (char)219;
	irA(41, 7);
	cout << (char)178;
	irA(41, 8);
	cout << (char)178;
	irA(41, 9);
	cout << (char)178;
	irA(41, 10);
	cout << (char)178;
	irA(41, 11);
	cout << (char)178;
	irA(41, 12);
	cout << (char)178;
	Sleep(50);
	//linea 3
	irA(42, 5);
	cout << (char)178;
	irA(42, 6);
	cout << (char)178;
	irA(42, 7);
	cout << (char)219;
	irA(42, 8);
	cout << (char)219;
	Sleep(50);
	//linea 4
	irA(43, 5);
	cout << (char)219;
	irA(43, 6);
	cout << (char)219;
	irA(43, 7);
	cout << (char)178;
	irA(43, 8);
	cout << (char)178;
	Sleep(50);
	//linea 5
	irA(44, 4);
	cout << (char)219;
	irA(44, 5);
	cout << (char)219;
	irA(44, 6);
	cout << (char)219;
	irA(44, 7);
	cout << (char)219;
	irA(44, 8);
	cout << (char)219;
	irA(44, 9);
	cout << (char)219;
	irA(44, 10);
	cout << (char)219;
	irA(44, 11);
	cout << (char)219;
	irA(44, 12);
	cout << (char)219;
	Sleep(50);
	//linea 6
	irA(45, 4);
	cout << (char)178;
	irA(45, 5);
	cout << (char)178;
	irA(45, 6);
	cout << (char)178;
	irA(45, 7);
	cout << (char)178;
	irA(45, 8);
	cout << (char)178;
	irA(45, 9);
	cout << (char)178;
	irA(45, 10);
	cout << (char)178;
	irA(45, 11);
	cout << (char)178;
	irA(45, 12);
	cout << (char)178;
	Sleep(50);
	//crea la letra A
	//linea 1
	irA(46, 6);
	cout << (char)219;
	irA(46, 7);
	cout << (char)219;
	irA(46, 8);
	cout << (char)219;
	irA(46, 9);
	cout << (char)219;
	irA(46, 10);
	cout << (char)219;
	irA(46, 11);
	cout << (char)219;
	irA(46, 12);
	cout << (char)219;
	Sleep(50);
	//linea 2
	irA(47, 4);
	cout << (char)219;
	irA(47, 5);
	cout << (char)219;
	irA(47, 6);
	cout << (char)178;
	irA(47, 7);
	cout << (char)178;
	irA(47, 8);
	cout << (char)219;
	irA(47, 9);
	cout << (char)178;
	irA(47, 10);
	cout << (char)178;
	irA(47, 11);
	cout << (char)178;
	irA(47, 12);
	cout << (char)178;
	Sleep(50);
	//linea 3
	irA(48, 4);
	cout << (char)219;
	irA(48, 5);
	cout << (char)219;
	irA(48, 8);
	cout << (char)219;
	irA(48, 9);
	cout << (char)178;
	Sleep(50);
	//linea 4
	irA(49, 4);
	cout << (char)178;
	irA(49, 5);
	cout << (char)178;
	irA(49, 6);
	cout << (char)219;
	irA(49, 7);
	cout << (char)219;
	irA(49, 8);
	cout << (char)219;
	irA(49, 9);
	cout << (char)219;
	irA(49, 10);
	cout << (char)219;
	irA(49, 11);
	cout << (char)219;
	irA(49, 12);
	cout << (char)219;
	Sleep(50);
	//linea 5
	irA(50, 6);
	cout << (char)178;
	irA(50, 7);
	cout << (char)178;
	irA(50, 8);
	cout << (char)178;
	irA(50, 9);
	cout << (char)178;
	irA(50, 10);
	cout << (char)178;
	irA(50, 11);
	cout << (char)178;
	irA(50, 12);
	cout << (char)178;
	Sleep(50);
	//crea la letra N
	//linea 1
	irA(51, 4);
	cout << (char)219;
	irA(51, 5);
	cout << (char)219;
	irA(51, 6);
	cout << (char)219;
	irA(51, 7);
	cout << (char)219;
	irA(51, 8);
	cout << (char)219;
	irA(51, 9);
	cout << (char)219;
	irA(51, 10);
	cout << (char)219;
	irA(51, 11);
	cout << (char)219;
	irA(51, 12);
	cout << (char)219;
	Sleep(50);
	//linea 2
	irA(52, 4);
	cout << (char)178;
	irA(52, 5);
	cout << (char)178;
	irA(52, 6);
	cout << (char)178;
	irA(52, 7);
	cout << (char)219;
	irA(52, 8);
	cout << (char)219;
	irA(52, 9);
	cout << (char)178;
	irA(52, 10);
	cout << (char)178;
	irA(52, 11);
	cout << (char)178;
	irA(52, 12);
	cout << (char)178;
	Sleep(50);
	//linea 3
	irA(53, 7);
	cout << (char)178;
	irA(53, 8);
	cout << (char)178;
	irA(53, 9);
	cout << (char)219;
	irA(53, 10);
	cout << (char)219;
	Sleep(50);
	//linea 4
	irA(54, 4);
	cout << (char)219;
	irA(54, 5);
	cout << (char)219;
	irA(54, 6);
	cout << (char)219;
	irA(54, 7);
	cout << (char)219;
	irA(54, 8);
	cout << (char)219;
	irA(54, 9);
	cout << (char)219;
	irA(54, 10);
	cout << (char)219;
	irA(54, 11);
	cout << (char)219;
	irA(54, 12);
	cout << (char)219;
	//linea 5
	irA(55, 4);
	cout << (char)178;
	irA(55, 5);
	cout << (char)178;
	irA(55, 6);
	cout << (char)178;
	irA(55, 7);
	cout << (char)178;
	irA(55, 8);
	cout << (char)178;
	irA(55, 9);
	cout << (char)178;
	irA(55, 10);
	cout << (char)178;
	irA(55, 11);
	cout << (char)178;
	irA(55, 12);
	cout << (char)178;
	Sleep(50);
	//crea la letra U
	//linea 1
	irA(56, 4);
	cout << (char)219;
	irA(56, 5);
	cout << (char)219;
	irA(56, 6);
	cout << (char)219;
	irA(56, 7);
	cout << (char)219;
	irA(56, 8);
	cout << (char)219;
	irA(56, 9);
	cout << (char)219;
	irA(56, 10);
	cout << (char)219;
	irA(56, 11);
	cout << (char)178;
	Sleep(50);
	//linea 2
	irA(57, 4);
	cout << (char)178;
	irA(57, 5);
	cout << (char)178;
	irA(57, 6);
	cout << (char)178;
	irA(57, 7);
	cout << (char)178;
	irA(57, 8);
	cout << (char)178;
	irA(57, 9);
	cout << (char)178;
	irA(57, 10);
	cout << (char)178;
	irA(57, 11);
	cout << (char)219;
	irA(57, 12);
	cout << (char)219;
	Sleep(50);
	//lenea 3
	irA(58, 11);
	cout << (char)219;
	irA(58, 12);
	cout << (char)219;
	Sleep(50);
	//linea 4
	irA(59, 4);
	cout << (char)219;
	irA(59, 5);
	cout << (char)219;
	irA(59, 6);
	cout << (char)219;
	irA(59, 7);
	cout << (char)219;
	irA(59, 8);
	cout << (char)219;
	irA(59, 9);
	cout << (char)219;
	irA(59, 10);
	cout << (char)219;
	irA(59, 11);
	cout << (char)178;
	irA(59, 12);
	cout << (char)178;
	Sleep(50);
	//linea 5
	irA(60, 4);
	cout << (char)178;
	irA(60, 5);
	cout << (char)178;
	irA(60, 6);
	cout << (char)178;
	irA(60, 7);
	cout << (char)178;
	irA(60, 8);
	cout << (char)178;
	irA(60, 9);
	cout << (char)178;
	irA(60, 10);
	cout << (char)178;
	Sleep(50);
	//crea la letra E
	//linea 1
	irA(61, 4);
	cout << (char)219;
	irA(61, 5);
	cout << (char)219;
	irA(61, 6);
	cout << (char)219;
	irA(61, 7);
	cout << (char)219;
	irA(61, 8);
	cout << (char)219;
	irA(61, 9);
	cout << (char)219;
	irA(61, 10);
	cout << (char)219;
	irA(61, 11);
	cout << (char)219;
	irA(61, 12);
	cout << (char)219;
	Sleep(50);
	//linea 2
	irA(62, 4);
	cout << (char)219;
	irA(62, 5);
	cout << (char)178;
	irA(62, 6);
	cout << (char)178;
	irA(62, 7);
	cout << (char)178;
	irA(62, 8);
	cout << (char)219;
	irA(62, 9);
	cout << (char)178;
	irA(62, 10);
	cout << (char)178;
	irA(62, 11);
	cout << (char)178;
	irA(62, 12);
	cout << (char)219;
	Sleep(50);
	//linea 3
	irA(63, 4);
	cout << (char)219;
	irA(63, 5);
	cout << (char)178;
	irA(63, 8);
	cout << (char)219;
	irA(63, 9);
	cout << (char)178;
	irA(63, 12);
	cout << (char)219;
	Sleep(50);
	//linea 4
	irA(64, 4);
	cout << (char)219;
	irA(64, 5);
	cout << (char)178;
	irA(64, 8);
	cout << (char)178;
	irA(64, 9);
	cout << (char)178;
	irA(64, 12);
	cout << (char)219;
	Sleep(50);
	//linea 5
	irA(65, 4);
	cout << (char)178;
	irA(65, 5);
	cout << (char)178;
	irA(65, 12);
	cout << (char)178;
	Sleep(50);
	//crea la letra L
	//linea 1
	irA(66, 4);
	cout << (char)219;
	irA(66, 5);
	cout << (char)219;
	irA(66, 6);
	cout << (char)219;
	irA(66, 7);
	cout << (char)219;
	irA(66, 8);
	cout << (char)219;
	irA(66, 9);
	cout << (char)219;
	irA(66, 10);
	cout << (char)219;
	irA(66, 11);
	cout << (char)219;
	irA(66, 12);
	cout << (char)219;
	Sleep(50);
	//linea2
	irA(67, 4);
	cout << (char)178;
	irA(67, 5);
	cout << (char)178;
	irA(67, 6);
	cout << (char)178;
	irA(67, 7);
	cout << (char)178;
	irA(67, 8);
	cout << (char)178;
	irA(67, 9);
	cout << (char)178;
	irA(67, 10);
	cout << (char)178;
	irA(67, 11);
	cout << (char)178;
	irA(67, 12);
	cout << (char)219;
	Sleep(50);
	//linea 3
	irA(68, 12);
	cout << (char)219;
	Sleep(50);
	//linea 4
	irA(69, 12);
	cout << (char)219;
	Sleep(50);
	//linea 5
	irA(70, 12);
	cout << (char)178;
	Sleep(50);
	//crea la letra I
	//linea 1
	irA(71, 4);
	cout << (char)219;
	irA(71, 5);
	cout << (char)219;
	irA(71, 6);
	cout << (char)219;
	irA(71, 7);
	cout << (char)219;
	irA(71, 8);
	cout << (char)219;
	irA(71, 9);
	cout << (char)219;
	irA(71, 10);
	cout << (char)219;
	irA(71, 11);
	cout << (char)219;
	irA(71, 12);
	cout << (char)219;
	Sleep(50);
	//linea 2
	irA(72, 4);
	cout << (char)178;
	irA(72, 5);
	cout << (char)178;
	irA(72, 6);
	cout << (char)178;
	irA(72, 7);
	cout << (char)178;
	irA(72, 8);
	cout << (char)178;
	irA(72, 9);
	cout << (char)178;
	irA(72, 10);
	cout << (char)178;
	irA(72, 11);
	cout << (char)178;
	irA(72, 12);
	cout << (char)178;
	Sleep(50);
	//crea la letra T
	//linea 1
	irA(73, 4);
	cout << (char)219;
	irA(73, 5);
	cout << (char)178;
	Sleep(50);
	//linea 2
	irA(74, 4);
	cout << (char)219;
	irA(74, 5);
	cout << (char)178;
	Sleep(50);
	//linea 3
	irA(75, 4);
	cout << (char)219;
	irA(75, 5);
	cout << (char)219;
	irA(75, 6);
	cout << (char)219;
	irA(75, 7);
	cout << (char)219;
	irA(75, 8);
	cout << (char)219;
	irA(75, 9);
	cout << (char)219;
	irA(75, 10);
	cout << (char)219;
	irA(75, 11);
	cout << (char)219;
	irA(75, 12);
	cout << (char)219;
	Sleep(50);
	//linea 4
	irA(76, 4);
	cout << (char)219;
	irA(76, 5);
	cout << (char)178;
	irA(76, 6);
	cout << (char)178;
	irA(76, 7);
	cout << (char)178;
	irA(76, 8);
	cout << (char)178;
	irA(76, 9);
	cout << (char)178;
	irA(76, 10);
	cout << (char)178;
	irA(76, 11);
	cout << (char)178;
	irA(76, 12);
	cout << (char)178;
	Sleep(50);
	//linea 5
	irA(77, 4);
	cout << (char)219;
	irA(77, 5);
	cout << (char)178;
	Sleep(50);
	//linea 6
	irA(78, 4);
	cout << (char)178;
	irA(78, 5);
	cout << (char)178;
	Sleep(50);
	//crea la letra O
	//linea 1
	irA(79, 6);
	cout << (char)219;
	irA(79, 7);
	cout << (char)219;
	irA(79, 8);
	cout << (char)219;
	irA(79, 9);
	cout << (char)219;
	irA(79, 10);
	cout << (char)219;
	irA(79, 11);
	cout << (char)178;
	Sleep(50);
	//linea 2
	irA(80, 4);
	cout << (char)219;
	irA(80, 5);
	cout << (char)219;
	irA(80, 6);
	cout << (char)178;
	irA(80, 7);
	cout << (char)178;
	irA(80, 8);
	cout << (char)178;
	irA(80, 9);
	cout << (char)178;
	irA(80, 10);
	cout << (char)178;
	irA(80, 11);
	cout << (char)219;
	irA(80, 12);
	cout << (char)219;
	Sleep(50);
	//linea 3
	irA(81, 4);
	cout << (char)219;
	irA(81, 5);
	cout << (char)219;
	irA(81, 11);
	cout << (char)219;
	irA(81, 12);
	cout << (char)219;
	Sleep(50);
	//linea 4
	irA(82, 4);
	cout << (char)178;
	irA(82, 5);
	cout << (char)178;
	irA(82, 6);
	cout << (char)219;
	irA(82, 7);
	cout << (char)219;
	irA(82, 8);
	cout << (char)219;
	irA(82, 9);
	cout << (char)219;
	irA(82, 10);
	cout << (char)219;
	irA(82, 11);
	cout << (char)178;
	irA(82, 12);
	cout << (char)178;
	Sleep(50);
	//linea 5
	irA(83, 6);
	cout << (char)178;
	irA(83, 7);
	cout << (char)178;
	irA(83, 8);
	cout << (char)178;
	irA(83, 9);
	cout << (char)178;
	irA(83, 10);
	cout << (char)178;
	irA(83, 11);
	cout << (char)178;
	Sleep(50);
	//crea el número 1
	//linea 1
	irA(84, 5);
	cout << (char)219;
	irA(84, 6);
	cout << (char)219;
	irA(84, 7);
	cout << (char)178;
	irA(84, 12);
	cout << (char)219;
	Sleep(50);
	//linea 2
	irA(85, 4);
	cout << (char)219;
	irA(85, 5);
	cout << (char)219;
	irA(85, 6);
	cout << (char)219;
	irA(85, 7);
	cout << (char)219;
	irA(85, 8);
	cout << (char)219;
	irA(85, 9);
	cout << (char)219;
	irA(85, 10);
	cout << (char)219;
	irA(85, 11);
	cout << (char)219;
	irA(85, 12);
	cout << (char)219;
	Sleep(50);
	//linea 3
	irA(86, 4);
	cout << (char)178;
	irA(86, 5);
	cout << (char)178;
	irA(86, 6);
	cout << (char)178;
	irA(86, 7);
	cout << (char)178;
	irA(86, 8);
	cout << (char)178;
	irA(86, 9);
	cout << (char)178;
	irA(86, 10);
	cout << (char)178;
	irA(86, 11);
	cout << (char)178;
	irA(86, 12);
	cout << (char)219;
	Sleep(50);
	//linea 4
	irA(87, 12);
	cout << (char)178;
	//crea el número 8
	//linea 1
	irA(88, 6);
	cout << (char)219;
	irA(88, 7);
	cout << (char)219;
	irA(88, 9);
	cout << (char)219;
	irA(88, 10);
	cout << (char)219;
	Sleep(50);
	//linea 2
	irA(89, 4);
	cout << (char)219;
	irA(89, 5);
	cout << (char)219;
	irA(89, 6);
	cout << (char)178;
	irA(89, 7);
	cout << (char)178;
	irA(89, 8);
	cout << (char)219;
	irA(89, 9);
	cout << (char)178;
	irA(89, 10);
	cout << (char)178;
	irA(89, 11);
	cout << (char)219;
	irA(89, 12);
	cout << (char)219;
	Sleep(50);
	//linea 3
	irA(90, 4);
	cout << (char)219;
	irA(90, 5);
	cout << (char)219;
	irA(90, 6);
	cout << (char)178;
	irA(90, 8);
	cout << (char)219;
	irA(90, 9);
	cout << (char)178;
	irA(90, 11);
	cout << (char)219;
	irA(90, 12);
	cout << (char)219;
	Sleep(50);
	//linea 4
	irA(91, 4);
	cout << (char)178;
	irA(91, 5);
	cout << (char)178;
	irA(91, 6);
	cout << (char)219;
	irA(91, 7);
	cout << (char)219;
	irA(91, 8);
	cout << (char)178;
	irA(91, 9);
	cout << (char)219;
	irA(91, 10);
	cout << (char)219;
	irA(91, 11);
	cout << (char)178;
	irA(91, 12);
	cout << (char)178;
	Sleep(50);
	//linea 5
	irA(92, 6);
	cout << (char)178;
	irA(92, 7);
	cout << (char)178;
	irA(92, 9);
	cout << (char)178;
	irA(92, 10);
	cout << (char)178;
	PlaySound(L"moneda.wav", NULL, SND_FILENAME);
	/*Reproduce un sonido en formato wav
	si no encuentra el sonido reproduce el sonido de error del sistema*/
	Sleep(50);
}