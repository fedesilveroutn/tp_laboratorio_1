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
 * @fn void menu(int*, int, int)
 * @brief muestra el menu de opciones, valida que el num ingresado sea correcto y  muestra los numeros cargados si son != de 0.
 *
 * @param eleccion recibe la direccion de memoria de la variable donde se carga el valor de la respuesta.
 * @param operando1 recibe el valor que tiene cargado la primera variable que quiero mostrar.
 * @param operando2 recibe el valor que tiene que cargado la segunda variable que quiero mostrar.
 */
void menu (int* eleccion, int operando1, int operando2)
{
	int aux;

	if (operando1 == 0 && operando2 == 0)
	{
		printf("\n1. Ingresar 1er operando (A = X)\n2. Ingresar 2do operando (B = Y)\n3. Calcular todas las operaciones\n\n      a) Calcular la suma (A+B)\n      b) Calcular la resta (A-B)\n      c) Calcular la division(A/B)\n      d) Calcular la multiplicacion(A*B)\n      e) Calcular el factorial(A! | B!)\n\n4. Informar resultados\n5. Salir\n\n");
	}
	else if (operando1 != 0 && operando2 == 0)
	{
		printf("\n1. Ingresar 1er operando (A = %d)\n2. Ingresar 2do operando (B = Y)\n3. Calcular todas las operaciones\n\n     a) Calcular la suma (A+B)\n     b) Calcular la resta (A-B)\n     c) Calcular la division(A/B)\n     d) Calcular la multiplicacion(A*B)\n     e) Calcular el factorial(A! | B!)\n\n4. Informar resultados\n5. Salir\n\n", operando1);
	}
	else if (operando1 != 0 && operando2 != 0)
	{
		printf("\n1. Ingresar 1er operando (A = %d)\n2. Ingresar 2do operando (B = %d)\n3. Calcular todas las operaciones\n\n     a) Calcular la suma (A+B)\n     b) Calcular la resta (A-B)\n     c) Calcular la division(A/B)\n     d) Calcular la multiplicacion(A*B)\n     e) Calcular el factorial(A! | B!)\n\n4. Informar resultados\n5. Salir\n\n", operando1, operando2);
	}


	printf("Elija una opción (1-2-3-4-5): ");
	fflush(stdin);
	scanf("%d", &aux);


	while (aux != 1 && aux != 2 && aux != 3 && aux != 4 && aux != 5)
				{
					separador();
					printf("\nError. Ingrese un número de los indicados en el menú: \n");
					separador();
					printf("\n1. Ingresar 1er operando (A = %d)\n2. Ingresar 2do operando (B = %d)\n3. Calcular todas las operaciones\n\na) Calcular la suma (A+B)\nb) Calcular la resta (A-B)\nc) Calcular la division(A/B)\nd) Calcular la multiplicacion\ne) Calcular el factorial\n\n4. Informar resultados\n5. Salir\n\n", operando1, operando2);
					fflush(stdin);
					scanf("%d", &aux);
				}

	*eleccion = aux;
}


/**
 * @fn void eleccion(int, int*, int*, int*, int*, int*, int*)
 * @brief muestra diferentes flujos dependiendo de la opcion elegida, su proposito es lograr que el usuario cargue los numeros
 *
 * @param eleccion recibe el valor de la eleccion del usuario
 * @param operandoUno recibe la direccion de memoria donde cargará el valor del primer numero ingresado por el usuario
 * @param operandoDos recibe la direccion de memoria donde cargará el valor del segundo numero ingresado por el usuario
 * @param continuar recibe la direccion de memoria de una variable que utilizaré para romper un bucle
 * @param flagCargaOperando2 permite cargar un segundo numero si ya se cargó el operando1 previamente
 * @param flagCalculos bloquea los calculos si no se ingresaron los dos operandos previamente
 * @param flagMenu permite saber si se cargaron ambos operandos
 */
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
						if(*flagCalculos == 0)
						{
							separador();
							printf("\nError. Debe ingresar ambos operandos para poder continuar.\n");
							separador();
							break;
						}
			}
}



/**
 * @fn void separador()
 * @brief es un elemento visual que divide un contenido de otro con lineas para mejorar la experiencia de usuario
 *
 */
void separador()
{
	printf("\n================================\n");
}


/**
 * @fn void separadorPunto()
 * @brief  es un elemento visual que divide un contenido de otro con puntos para mejorar la experiencia de usuario
 *
 */
void separadorPunto()
{
	printf("\n********************************\n");
}



/**
 * @fn void instrucciones()
 * @brief imprime en consola las instrucciones del programa para el usuario
 *
 */
void instrucciones()
{
	printf("¡Bienvenidx a la calculadora!\n");
	separadorPunto();
	printf("\nInstrucciones: \n");
	printf("\n-El objetivo de esta calculadora es recibir dos números enteros, realizar todas las operaciones posibles a la vez y mostrarlas.");
	printf("\n-Usted se moverá a través del menú, seleccionando los número que anteceden a las opciones, es decir: 1-2-3-4-5 (NO LETRAS NI SIMBOLOS).");
	printf("\n-Por último, recuerde cargar solo números enteros.\n");
	separadorPunto();
}



