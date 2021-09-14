/*
 ============================================================================
Federico Silvero
Trabajo práctico N°1.

Consigna:

Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:

1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
	a) Calcular la suma (A+B)
	b) Calcular la resta (A-B)
	c) Calcular la division (A/B)
	d) Calcular la multiplicacion (A*B)
	e) Calcular el factorial (A!)

4. Informar resultados
	a) “El resultado de A+B es: r”
	b) “El resultado de A-B es: r”
	c) “El resultado de A/B es: r” o “No es posible dividir por cero”
	d) “El resultado de A*B es: r”
	e) “El factorial de A es: r1 y El factorial de B es: r2”

5. Salir


• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.

• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)

• Deberán contemplarse los casos de error (división por cero, etc)

• Documentar todas las funciones

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

int main(void) {
	setbuf(stdout, NULL);


	int operando1;
	int operando2;

	int resultadoSuma;
	int resultadoResta;
	int resultadoMultiplicacion;
	int resultadoFactorial1 = 1;
	int resultadoFactorial2 = 1;

	int accion;
	int seraDivision;

	int seguir = 0;
	int flag = 0;
	int flagCalculos = 0;
	int flagMostrar = 0;
	int flagOperando = 0;

	float resultadoDivision;



	printf("¡Bienvenidx a la calculadora!\n\nRecuerde que los valores A y B se reemplazarán una vez cargados ambos operandos.\nElija una opción: \n");

do{


	if (flag == 0)
	{

		printf("\n1. Ingresar 1er operando (A=x)\n2. Ingresar 2do operando (B=y)\n3. Calcular todas las operaciones\n\na) Calcular la suma (A+B)\nb) Calcular la resta (A-B)\nc) Calcular la division(A/B)\nd) Calcular la multiplicacion\ne) Calcular el factorial\n\n4. Informar resultados\n5. Salir\n\n");
		printf("====================\n");
		fflush(stdin);
		scanf("%d", &accion);



			switch (accion)
			{

			case 1:
					printf("\nIngrese el 1er operando: ");
					fflush(stdin);
					scanf("%d", &operando1);
					printf("Usted ha ingresado: %d\n", operando1);
					printf("====================\n");
					flagOperando = 1;
					break;

			case 2:

				if(flagOperando == 1)
				{
					printf("Ingrese el 2do operando: ");
					fflush(stdin);
					scanf("%d", &operando2);
					printf("Usted ha ingresado: %d\n", operando2);
					printf("====================\n");
					flag = 1;
					flagCalculos = 1;
				}
				else
				{
					printf("Error. Debe ingresar el primer operando antes.");
					printf("====================\n");
				}
					break;

			case 5:
					printf("Seleccionó salir del programa.");
					seguir = 1;
					break;


			default:
					if(flagCalculos == 0)
					{
						printf("Error. Debe ingresar ambos operandos para poder continuar.\n\n");
						printf("====================\n");
						break;
					}
			}

	}

	else if (flag == 1)
	{

		printf("\n1. Ingresar 1er operando (A = %d)\n2. Ingresar 2do operando (B = %d)\n3. Calcular todas las operaciones\n\na) Calcular la suma (A+B)\nb) Calcular la resta (A-B)\nc) Calcular la division(A/B)\nd) Calcular la multiplicacion\ne) Calcular el factorial\n\n4. Informar resultados\n5. Salir\n\n", operando1, operando2);
		printf("====================\n");
		fflush(stdin);
		scanf("%d", &accion);


			switch (accion)
			{

			case 1:
					printf("\nIngrese el 1er operando: ");
					fflush(stdin);
					scanf("%d", &operando1);
					break;


			case 2:
					printf("Ingrese el 2do operando: ");
					fflush(stdin);
					scanf("%d", &operando2);
					break;


			case 3:
					resultadoSuma = sumar(operando1, operando2);
					resultadoResta = restar (operando1, operando2);
					seraDivision = dividir ((float)operando1, operando2, &resultadoDivision);
					resultadoMultiplicacion = multiplicar (operando1, operando2);
					resultadoFactorial1 = calcularFactorial (operando1);
					resultadoFactorial2 = calcularFactorial (operando2);
					flagMostrar = 1;

					printf("Usted ha calculado todas las operaciones.\n");
					printf("====================\n");

					break;


			case 4:
					if(flagMostrar == 1)
					{
						printf("\na) El resultado de A+B es: %d", resultadoSuma);
						printf("\nb) El resultado de A-B es: %d", resultadoResta);

						if (seraDivision == 0)
						{
							printf("\nc) El resultado de A/B es: %.2f", resultadoDivision);
						}
						else
						{
							printf("\nc) No es posible dividir por cero.");
						}

						printf("\nd) El resultado de A*B es: %d", resultadoMultiplicacion);
						printf("\ne)  El factorial de A es: %d y El factorial de B es: %d\n\n", resultadoFactorial1, resultadoFactorial2);


						resultadoFactorial1 = 1;
						resultadoFactorial2 = 1;
						flag = 0;
					}
					else
					{
						printf("No se pueden mostrar los resultados sin haber hecho los cálculos anteriormente.\n\n");
					}

					printf("====================\n");
					break;



			case 5:
					printf("Seleccionó salir del programa.\n");
					seguir = 1;
					break;


			default:
					printf("\nHa ingresado un caracter no valido. Los permitidos son a-b-c-d-e.\n\n");
					printf("====================\n");
					break;

			}
		}



	}while (seguir == 0);


	printf("\nFin del programa.");

	return 0;
}
