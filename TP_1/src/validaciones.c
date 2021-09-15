/*
 * validaciones.c
 *
 *  Created on: 12 sep. 2021
 *      Author: Fede
 */
#include "validaciones.h"

/**
 * @fn int ingresoNum( int, int, int*)
 * @brief pide el ingreso de un número y valida que se encuentre en el rango establecido.
 *
 * @param min recibe el valor minimo que puede tener el numero ingresado.
 * @param max recibe el valor maximo que puede tener el numero ingresado.
 * @param operando recibe la direccion de memoria de la variable donde guardara el numero ingresado ya validado.
 * @return retorna 0 cuando la validacion dio OK.
 */

int ingresoNum (int min, int max, int* operando)
{
	int retorno;
	int aux;


	printf("Ingrese un número: ");
	fflush(stdin);
	scanf("%d", &aux);

		while (aux < min || aux > max)
		{
			printf("El número ingresado excedió la capacidad. Reingrese un número entre %d y %d : ", min, max);
			fflush(stdin);
			scanf("%d", &aux);
		}

	printf("Usted ha ingresado: %d\n", aux);

	*operando = aux;
	 retorno = 0;


	return retorno;
}
