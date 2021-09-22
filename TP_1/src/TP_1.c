/*
 ============================================================================
Federico Silvero
Trabajo pr�ctico N�1.

Consigna:

Hacer una calculadora. Para ello el programa iniciar� y contar� con un men� de opciones:

1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
	a) Calcular la suma (A+B)
	b) Calcular la resta (A-B)
	c) Calcular la division (A/B)
	d) Calcular la multiplicacion (A*B)
	e) Calcular el factorial (A!)

4. Informar resultados
	a) �El resultado de A+B es: r�
	b) �El resultado de A-B es: r�
	c) �El resultado de A/B es: r� o �No es posible dividir por cero�
	d) �El resultado de A*B es: r�
	e) �El factorial de A es: r1 y El factorial de B es: r2�

5. Salir


� Todas las funciones matem�ticas del men� se deber�n realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.

� En el men� deber�n aparecer los valores actuales cargados en los operandos A y B
(donde dice �x� e �y� en el ejemplo, se debe mostrar el n�mero cargado)

� Deber�n contemplarse los casos de error (divisi�n por cero, etc)

� Documentar todas las funciones

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"
#include "validaciones.h"
#include "menu.h"

#define MIN -30000
#define MAX 30000

int main(void) {
	setbuf(stdout, NULL);


	int operando1;//guarda el valor que ingresa el usuario para el operando 1
	int operando2;//guarda el valor que ingresa el usuario para el operando 2
	int accion;//variable que guarda la eleccion del usuario
	int seguir = 0;//salida del bucle do-while

	int resultadoSuma;//guarda el resultado de la suma
	int resultadoResta;//guarda el resultado de la resta
	int resultadoMultiplicacion;//guarda el resultado de la multiplicacion
	int seraDivision;//si es 0, quiere decir que la divisi�n pudo realizarse, si es 1 no
	int resultadoFactorial1 = 1;//guarda el resultado del factorial1
	int resultadoFactorial2 = 1;//guarda el resultado del factorial2
	float resultadoDivision;//guarda el resultado de la division

	int flagMenu = 0;//para saber si mostrar menuSinValores o menuConValores
	int flagHabilitacionOp2 = 0;//para saber si ya cargu� previamente el operando1
	int flagHabilitacionCalculos = 0;//para saber si puedo o no realizar los calculos
	int flagHabilitacionMostrar = 0;//para habilitar la visualizacion de las operaciones realizadas
	int flagFactorial1 = 0;//para saber si calcular el factorial1 pudo realizarse
	int flagFactorial2 = 0;//lo mismo pero para el factorial2





	printf("�Bienvenidx a la calculadora!\n\nRecuerde que los valores A y B se reemplazar�n una vez cargados ambos operandos.\n");

do{

		if (flagMenu == 0)//si todav�a no cargue ningun valor llamo a este codigo
		{

			menuSinValores (&accion); //muestra el menu de opciones sin cambiar el A ni B, ya que todav�a no se ingresaron
			eleccion (accion, &operando1, &operando2, &seguir, &flagHabilitacionOp2, &flagHabilitacionCalculos, &flagMenu);

		}

		else if (flagMenu == 1)

		{
			menuConValores (&accion, operando1, operando2);

			switch (accion)
			{

			case 1:
					printf("\nEligi� cargar el primer operando.\n\n");
					ingresoNum (MIN, MAX, &operando1);
					break;


			case 2:
					printf("\nEligi� cargar el segundo operando.\n\n");
					ingresoNum (MIN, MAX, &operando2);
					break;

			case 3:

					resultadoSuma = sumar(operando1, operando2);
					resultadoResta = restar (operando1, operando2);
					seraDivision = dividir ((float)operando1, operando2, &resultadoDivision);
					resultadoMultiplicacion = multiplicar (operando1, operando2);

					if (operando1 < 16)
					{
						resultadoFactorial1 = calcularFactorial (operando1);
						flagFactorial1 = 1;
					}

					if (operando2 < 16)
					{
						resultadoFactorial2 = calcularFactorial (operando2);
						flagFactorial2 = 1;
					}

					flagHabilitacionMostrar = 1;
					separador();
					printf("\nUsted ha calculado todas las operaciones.\n");
					separador();
					break;


			case 4:

				separador();
				if(flagHabilitacionMostrar == 1)
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


					if (flagFactorial1 == 1)
					{
						printf("\ne.1) El factorial de A es: %d\n", resultadoFactorial1);
						resultadoFactorial1 = 1;
						flagFactorial1 = 0;
					}
					else
					{
						printf("\ne.1) No se puede calcular el factorial de un n�mero tan grande.\n");
					}




					if (flagFactorial2 == 1)
					{
						printf("e.2) El factorial de B es: %d\n", resultadoFactorial2);
						resultadoFactorial2 = 1;
						flagFactorial2 = 0;
					}
					else
					{
						printf("e.2) No se puede calcular el factorial de un n�mero tan grande.\n");
					}


				}
				else
				{
					printf("No se pueden mostrar los resultados sin haber hecho los c�lculos anteriormente.\n");
				}

				flagHabilitacionCalculos = 0;
				flagMenu = 0;
				separador();
				system ("pause");
				break;


			case 5:

				printf("Seleccion� salir del programa.\n");
				separador();
				seguir = 1;
				break;


			default:

				printf("\nHa ingresado un caracter no valido. Los permitidos son a-b-c-d-e.\n");
				separador();
				break;
			}

		}

	}while (seguir == 0);


	printf("\nFin del programa.");

	return 0;
}
