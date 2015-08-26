/**
 * @file aritmetica_punteros.cpp
 * @brief Ejemplo de aritmética de punteros en C++, crear un vector dinámico y buscar los elementos máximo y mínimo teniendo al final un puntero apuntando a ellos
 * @author Francis
*/

#include<iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

#define TAMA 10

int main()
{
	// ***** Operaciones necesarias para generar números aleatorios distintos en cada ejecución *****
	time_t t;
	time(&t);
	srand((unsigned int) t);
	// **********************************************************************************************
	
	int *vector = 0, *maximo = 0, *minimo = 0, contador;				// Creo las variables
	vector = new int[TAMA];												// Doy memoria al vector dinánico
	maximo = &vector[0];												// Hago que el máximo apunte al primer elemento del vector
	minimo = &vector[0];												// Hago que el mínimo apunte al primer elemento del vector
	
	cout << "El vector aleatorio generado es: " << endl;
	for(int *i = vector, contador = 0; contador < TAMA; i++, contador++)// Recorro el vector dinámico con aritmética de punteros
	{
		*i = rand()%100;												// Introduzco los elementos aleatorios en el vector, con aritmética de punteros
		cout << "\tvector[" << contador << "] = " << *i << endl;		// Muestro el elemento del vector
		
		if( *maximo < *i )												// Si el máximo es mas pequeño que el elemento del vector de la posición i
			maximo = &vector[contador];									// Hago que maximo apunte al elemento el cuál es el máximo
			
		if( *minimo > *i )												// Si el mínimo es mayor que el elemento del vector de la posición i
			minimo = &vector[contador];									// Hago que minimo apunte al elemento el cuál es el mínimo
	}
	
	cout << "El maximo elemento es: " << *maximo << endl;
	cout << "El minimo elemento es: " << *minimo << endl;
	
	delete [] vector;
	vector = 0;
}
