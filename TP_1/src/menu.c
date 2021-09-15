/*
 * menu.c
 *
 *  Created on: 15 sep. 2021
 *      Author: Fede
 */


#include "menu.h"
#include "stdio.h"
#include "stdlib.h"


/**
 * @fn void menu(int*)
 * @brief muestra el menu de opciones y valida que el num ingresado sea correcto
 *
 * @param eleccion recibe la direccion de memoria de la variable donde se carga el valor de la respuesta.
 */
void menu (int* eleccion)
{
	int aux;

	printf("\n1. Ingresar 1er operando (A=x)\n2. Ingresar 2do operando (B=y)\n3. Calcular todas las operaciones\n\na) Calcular la suma (A+B)\nb) Calcular la resta (A-B)\nc) Calcular la division(A/B)\nd) Calcular la multiplicacion\ne) Calcular el factorial\n\n4. Informar resultados\n5. Salir\n\n");
	printf("\n====================\n");
	printf("Elija una opción: ");
	fflush(stdin);
	scanf("%d", &aux);


	while (aux != 1 && aux != 2 && aux != 3 && aux != 4 && aux != 5)
				{
					printf("\nError. Ingrese un número de los indicados en el menú: \n");
					printf("\n1. Ingresar 1er operando (A=x)\n2. Ingresar 2do operando (B=y)\n3. Calcular todas las operaciones\n\na) Calcular la suma (A+B)\nb) Calcular la resta (A-B)\nc) Calcular la division(A/B)\nd) Calcular la multiplicacion\ne) Calcular el factorial\n\n4. Informar resultados\n5. Salir\n\n");
					fflush(stdin);
					scanf("%d", &aux);
				}

	*eleccion = aux;
}


/**
 * @fn void menu2(int*, int, int)
 * @brief muestra el menu de opciones y valida que el num ingresado sea correcto, y además muestra los numeros cargados.
 *
 * @param eleccion recibe la direccion de memoria de la variable donde se carga el valor de la respuesta.
 * @param operando1 recibe el valor que tiene cargado la primera variable que quiero mostrar.
 * @param operando2 recibe el valor que tiene que cargado la segunda variable que quiero mostrar.
 */
void menu2 (int* eleccion, int operando1, int operando2)
{
	int aux;

	printf("\n1. Ingresar 1er operando (A = %d)\n2. Ingresar 2do operando (B = %d)\n3. Calcular todas las operaciones\n\na) Calcular la suma (A+B)\nb) Calcular la resta (A-B)\nc) Calcular la division(A/B)\nd) Calcular la multiplicacion\ne) Calcular el factorial\n\n4. Informar resultados\n5. Salir\n\n", operando1, operando2);
	printf("\n====================\n");
	printf("Elija una opción: ");
	fflush(stdin);
	scanf("%d", &aux);


	while (aux != 1 && aux != 2 && aux != 3 && aux != 4 && aux != 5)
				{
					printf("\nError. Ingrese un número de los indicados en el menú: \n");
					printf("\n1. Ingresar 1er operando (A = %d)\n2. Ingresar 2do operando (B = %d)\n3. Calcular todas las operaciones\n\na) Calcular la suma (A+B)\nb) Calcular la resta (A-B)\nc) Calcular la division(A/B)\nd) Calcular la multiplicacion\ne) Calcular el factorial\n\n4. Informar resultados\n5. Salir\n\n", operando1, operando2);
					fflush(stdin);
					scanf("%d", &aux);
				}

	*eleccion = aux;
}
