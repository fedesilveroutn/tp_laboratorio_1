/*
 ============================================================================
Enunciado:

Una empresa requiere un sistema para administrar su nómina de empleados.
Se sabe que dicha nómina bajo ninguna circunstancia superara los 1000 empleados.

El sistema deberá tener el siguiente menú de opciones:

1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número de Id.
		  El resto de los campos se le pedirá al usuario.

2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
			  o Salario o Sector.

3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.


4. INFORMAR:
			1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
			2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.

NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de algún empleado.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#define ELEMENTS 5
#define UP 1
#define DOWN 0

int main(void) {
	setbuf(stdout, NULL);

	Employee employee[ELEMENTS];
	int i;
	int index;


	//Para testear initEmployees---------------------------------------------------
	initEmployees (employee , ELEMENTS);
	for( i = 0; i < ELEMENTS; i++)
	{
		printf("Employee %d estado: %d\n" , i , employee[i].isEmpty);
	}
	//Fin testing------------------------------------------------------------------




	//Para testear addEmployee------------------------------------------------------
	addEmployee (&employee[0], ELEMENTS, 1000 , "Melissa","Brizuela", 12500.83 , 1);
	addEmployee (&employee[1], ELEMENTS, 1001 , "Valentin","Silvero", 13000.57 , 2);
	addEmployee (&employee[2], ELEMENTS, 1002 , "Federico","Silvero", 18600.57 , 4);
	addEmployee (&employee[3], ELEMENTS, 1003 , "Constanza","Arancio", 12000.50 , 3);
	addEmployee (&employee[4], ELEMENTS, 1004 , "JuanPaulo","Scallise", 12800.50 , 4);

	printf("\nEmpleado %s %s dado de alta exitosamente!\n", employee[0].name, employee[0].lastName);
	printf("Empleado %s %s dado de alta exitosamente!\n", employee[1].name, employee[1].lastName);
	printf("Empleado %s %s dado de alta exitosamente!\n", employee[2].name, employee[2].lastName);
	printf("Empleado %s %s dado de alta exitosamente!\n", employee[3].name, employee[3].lastName);
	printf("Empleado %s %s dado de alta exitosamente!\n", employee[4].name, employee[4].lastName);



	for (i = 0; i < ELEMENTS; i++)
	{
		printf("\n%-5s %-20s %-20s %-20s %-20s\n", "ID" , "Nombre", "Apellido" , "Salario" , "Sector");
		printf("%-5d %-20s %-20s %-20.2f %-20d\n", employee[i].id,
												   employee[i].name,
												   employee[i].lastName,
												   employee[i].salary,
												   employee[i].sector);
	}
	//Fin testing------------------------------------------------------------------





	//Para testear findEmployeeById------------------------------------------------
	index = findEmployeeById(employee, ELEMENTS , 1004);
	printf("\nINDEX cargado con: %d\n", index);
	printf("\nID: %d\nName: %s\nLastName: %s\nSalary: %.2f\nSector: %d",
			employee[index].id,
			employee[index].name,
			employee[index].lastName,
			employee[index].salary,
			employee[index].sector);
	//Fin testing------------------------------------------------------------------



/*
	//Para testear removeEmployee
	removeEmployee (employee , ELEMENTS , 1002);
	removeEmployee (employee , ELEMENTS , 1004);
	//Fin testing------------------------------------------------------------------
*/



	//Para testear sortEmployee
	sortEmployees(employee, ELEMENTS, UP);
	printf("Los empleados han sido ordenados exitosamente!\n");




	printf("\nOrdenamiento creciente:\n");
	for (i = 0; i < ELEMENTS; i++)
		{
				if (employee[i].isEmpty == FALSE)
				{
					printf("\n%-5s %-20s %-20s %-20s %-20s\n", "ID" , "Nombre", "Apellido" , "Salario" , "Sector");
					printf("%-5d %-20s %-20s %-20.2f %-20d\n", employee[i].id,
													   	   employee[i].name,
														   employee[i].lastName,
														   employee[i].salary,
														   employee[i].sector);
				}
		}

	sortEmployees(employee, ELEMENTS, DOWN);
	printf("\nOrdenamiento decreciente:\n");

	for (i = 0; i < ELEMENTS; i++)
		{
			if (employee[i].isEmpty == FALSE)
			{
				printf("\n%-5s %-20s %-20s %-20s %-20s\n", "ID" , "Nombre", "Apellido" , "Salario" , "Sector");
				printf("%-5d %-20s %-20s %-20.2f %-20d\n", employee[i].id,
													   	   employee[i].name,
														   employee[i].lastName,
														   employee[i].salary,
														   employee[i].sector);
			}
		}
	//Fin testing------------------------------------------------------------------





	//Para testear printEmployee---------------------------------------------------
	printf("\nFUNCION DE MOSTRAR: \n");
	printEmployees(employee , ELEMENTS);
	//Fin testing------------------------------------------------------------------









	return 0;
}
