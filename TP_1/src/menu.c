/*
 * menu.c
 *
 *  Created on: 15 sep. 2021
 *      Author: Fede
 */


#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "operaciones.h"
#include "validaciones.h"
#define MIN -30000
#define MAX 30000


/**
 * @fn void menu(int*)
 * @brief muestra el menu de opciones y valida que el num ingresado sea correcto
 *
 * @param eleccion recibe la direccion de memoria de la variable donde se carga el valor de la respuesta.
 */
void menuSinValores (int* eleccion)
{
	int aux;

	printf("\n1. Ingresar 1er operando (A=x)\n2. Ingresar 2do operando (B=y)\n3. Calcular todas las operaciones\n\na) Calcular la suma (A+B)\nb) Calcular la resta (A-B)\nc) Calcular la division(A/B)\nd) Calcular la multiplicacion\ne) Calcular el factorial\n\n4. Informar resultados\n5. Salir\n\n");
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
void menuConValores (int* eleccion, int operando1, int operando2)
{
	int aux;

	printf("\n1. Ingresar 1er operando (A = %d)\n2. Ingresar 2do operando (B = %d)\n3. Calcular todas las operaciones\n\na) Calcular la suma (A+B)\nb) Calcular la resta (A-B)\nc) Calcular la division(A/B)\nd) Calcular la multiplicacion\ne) Calcular el factorial\n\n4. Informar resultados\n5. Salir\n\n", operando1, operando2);
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



void eleccion (int eleccion, int* operandoUno, int* operandoDos, int* continuar, int* flagCargaOperando2, int* flagCalculos, int* flagMenu)
{
	switch (eleccion)
				{

				case 1:
						printf("\nEligió cargar el primer operando.\n");
						ingresoNum (MIN, MAX, operandoUno);
						*flagCargaOperando2 = 1;//si cargué el operando1 ya puedo cargar el operando2 gracias a este flag
						break;


				case 2:

						if(*flagCargaOperando2 == 1)//puedo entrar solamente si ya cargue el operando1 anteriormente
						{
							printf("\nEligió cargar el segundo operando.\n");
							ingresoNum (MIN, MAX, operandoDos);
							*flagCalculos = 1;//si no ingresé los dos operandos y quiero calcular, no voy a poder
							*flagMenu = 1;//me sirve para luego mostrar el menu con los valores cargados
						}
						else
						{
							separador();
							printf("\nError. Debe ingresar el primer operando antes.");
							separador();
						}

						break;


				case 5:
						separador();
						printf("\nSeleccionó salir del programa.\n");
						separador();
						*continuar = 1;
						break;



				default:
						if(flagCalculos == 0)
						{
							separador();
							printf("\nError. Debe ingresar ambos operandos para poder continuar.\n");
							separador();
							break;
						}
			}
}




void separador()
{
	printf("\n================================\n");
}



