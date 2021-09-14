/*
 * operaciones.c
 *
 *  Created on: 8 sep. 2021
 *      Author: Fede
 */

#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"



/**
 * @fn int sumar(int, int)
 * @brief recibe como parametro dos numeros enteros, los suma y retorna el resultado.
 *
 * @param a recibe un numero entero.
 * @param b recibe un numero entero.
 * @return retorna el resultado de la suma a + b.
 */
int sumar (int a, int b)
{
	int resultado;

	resultado = a + b;

	return resultado;
}

/**
 * @fn int restar(int, int)
 * @brief recibe dos numeros enteros y los resta.
 *
 * @param a recibe un numero entero.
 * @param b recibe un numero entero.
 * @return retorna el resultado de la resta a - b.
 */
int restar (int a, int b)
{
	int resultado;

	resultado = a - b;

	return resultado;
}


/**
 * @fn int dividir(float, int, float*)
 * @brief recibe un numero flotante, un numero entero, divide el primero por el segundo y si se pudo calcular a/b, escribe en la
 * 		  direccion de memoria que le fue pasada por parametro.
 *
 * @param a recibe un numero flotante.
 * @param b recibe un numero entero.
 * @param pResultado puntero que recibe la direccion de memoria de una variable tipo flotante.
 * @return retorna 1 si b es == 0 y no se pudo calcular la division, retorna 0 si la division si se pudo calcular.
 */
int dividir (float a, int b, float* pResultado)
{
	float resultado;
	int retorno;

	if (b == 0)
	{
		retorno = 1;


	}else{

		resultado = a / b;
	   *pResultado = resultado;

	    retorno = 0;
	}

	return retorno;
}


/**
 * @fn int multiplicar(int, int)
 * @brief recibe dos numeros entero y los multiplica a * b.
 *
 * @param a recibe un numero entero.
 * @param b recibe un numero entero.
 * @return retorna la multiplicacion de a * b.
 */
int multiplicar (int a, int b)
{
	int resultado;

	resultado = a * b;

	return resultado;
}

/**
 * @fn int calcularFactorial(int)
 * @brief recibe un numero entero y calcula su factorial de forma recursiva.
 *
 * @param a recibe un numero entero.
 * @return retorna el factorial calculado.
 */
int calcularFactorial (int a)
{
	int resultadoFactorial = 1;


	if (a != 0 && a > 0)
	{
		resultadoFactorial = a * calcularFactorial(a - 1);
	}


	return resultadoFactorial;
}












