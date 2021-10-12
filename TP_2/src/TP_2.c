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
#include "input.h"
#include "menu.h"
#define ELEMENTS 10
#define UP 1
#define DOWN 0
#define ID 1000

int main(void) {
	setbuf(stdout, NULL);

	//MAIN
	Employee employee[ELEMENTS];
	int lastId = ID;
	int option;
	int accountant = 0;

	//AUX
	Employee auxEmployee;
	int preId;
	char preName[51];
	char preLastName[51];
	float preSalary;
	int preSector;
	int flag = 0;
	int idSearch;
	int indexSearch;

	int optionSubMenu;
	int order;

	float fullSalary = 0;
	int salaryAccountant = 0;
	float salaryAverage;
	int overAverage = 0;;

	initEmployees (employee, ELEMENTS);

	do
	{
		preId = lastId;
		getInt(&option,
						"\nMENU PRINCIPAL"
						"\n--------------------------------\n"
						"1. ALTAS\n"
						"2. MODIFICAR\n"
						"3. BAJA\n"
						"4. INFORMAR\n"
						"5. SALIR DEL PROGRAMA"
						"\n--------------------------------\n"
						"Ingrese una opción (1-5): ",
						"\n--------------------------------\n"
						"1. ALTAS\n"
						"2. MODIFICAR\n"
						"3. BAJA\n"
						"4. INFORMAR\n"
						"5. SALIR DEL PROGRAMA"
						"\n--------------------------------\n"
						"Error. Reingrese una opción válida (1-5): ", 1 , 5);

		switch (option)
		{

		case 1:
				printf("\nDando de alta un empleado...");

				getString (preName, "\nIngrese nombre: ", "\nError. Reingrese un nombre válido (hasta 50 caracteres): ", 51);
				getString (preLastName, "Ingrese apellido: ", "\nError. Reingrese un nombre válido (hasta 50 caracteres): ", 51);
				getFloat (&preSalary, "Ingrese sueldo: ", "\nError. Reingrese un sueldo válido (5000 - 500000): ", 5000 , 500000);
				getInt (&preSector, "Ingrese sector: ", "\nError. Reingrese un sector válido (1 - 8): ", 1 , 8);

				auxEmployee.id = preId + 1;
				strcpy (auxEmployee.name , preName);
				strcpy (auxEmployee.lastName , preLastName);
				auxEmployee.salary = preSalary;
				auxEmployee.sector =  preSector;

				printf("\nEmpleado a ser dado de ALTA: \n");

				if ( confirmation (auxEmployee) == 0)
				{
					addEmployee(employee, ELEMENTS , auxEmployee.id, auxEmployee.name, auxEmployee.lastName, auxEmployee.salary, auxEmployee.sector);

					lastId++;
					flag = 1;
					accountant++;

					printf("\nEmpleado dado de ALTA exitosamente!\n\n");
					system("pause");
				}

				else
				{
					printf("\nUsted ha CANCELADO el alta!\n\n");
					system("pause");
				}

				break;





		case 2:
				printf("\n%-10s %-20s %-20s %-20s %-20s\n", "ID" , "Nombre", "Apellido" , "Salario" , "Sector");

				for (int i = 0; i < ELEMENTS; i++)
				{
					if(employee[i].isEmpty == FALSE)
					printf("%-10d %-20s %-20s %-20.2f %-20d\n\n", employee[i].id, employee[i].name , employee[i].lastName , employee[i].salary , employee[i].sector);
				}

				printf("\nIngrese el ID correspondiente al empleado que quiere MODIFICAR: ");
				fflush(stdin);
				scanf("%d", &idSearch);

				indexSearch = findEmployeeById(employee, ELEMENTS , idSearch);
				printf("\nElija la opción que desea MODIFICAR: \n");


					do
					{
					getInt (&optionSubMenu, "\nMENU DE MODIFICACIONES"
											"\n--------------------------------\n"
											"1. NOMBRE\n"
											"2. APELLIDO\n"
											"3. SALARIO\n"
											"4. SECTOR\n"
											"5. SALIR DEL SUBMENU DE MODIFICACIONES"
											"\n--------------------------------\n"
											"Ingrese una opción (1-5): ",
											"\n--------------------------------\n"
											"1. NOMBRE\n"
											"2. APELLIDO\n"
											"3. SALARIO\n"
											"4. SECTOR\n"
											"5. SALIR DEL SUBMENU DE MODIFICACIONES\n"
											"\n--------------------------------\n"
											"Error. Reingrese una opción válida (1-5): ", 1 , 5);

					switch (optionSubMenu)
					{

					case 1:
							getString(preName , "Ingrese el NUEVO NOMBRE: ", "Error. Reingrese un nombre válido (hasta 50 caracteres): ", 51);

							auxEmployee = employee[indexSearch];
							strcpy (auxEmployee.name , preName);

							if( confirmation(auxEmployee) == 0)
							{
								strcpy (employee[indexSearch].name , preName);
								printf("\nNOMBRE modificado exitosamente!\n\n");
								system ("pause");
							}
							else
							{
								printf("\nUsted ha CANCELADO la modificación del nombre.\n\n");
								system ("pause");
							}

							break;

					case 2:
							getString(preLastName , "Ingrese el NUEVO APELLIDO: ", "Error. Reingrese un apellido válido (hasta 50 caracteres): ", 51);
							auxEmployee = employee[indexSearch];
							strcpy (auxEmployee.lastName , preLastName);

							if( confirmation(auxEmployee) == 0)
							{
								strcpy (employee[indexSearch].lastName , preLastName);
								printf("\nAPELLIDO modificado exitosamente!\n\n");
								system ("pause");
							}
							else
							{
								printf("\nUsted ha CANCELADO la modificación del apellido.\n\n");
								system ("pause");
							}

							break;

					case 3:
							getFloat (&preSalary, "Ingrese el NUEVO SALARIO: ", "Error. Reingrese un salario válido (5000-500000): ", 500 , 500000 );
							auxEmployee = employee[indexSearch];
							auxEmployee.salary = preSalary;

							if ( confirmation (auxEmployee) == 0)
							{
								employee[indexSearch].salary = preSalary;
								printf("\nSALARIO modificado exitosamente!\n\n");
								system ("pause");
							}
							else
							{
								printf("\nUsted ha CANCELADO la modificacion del salario.\n\n");
								system("pause");
							}

							break;


					case 4:
							getInt (&preSector, "Ingrese el NUEVO SECTOR: ", "Error. Reingrese un sector válido (1-8): ", 1 , 8 );
							auxEmployee = employee[indexSearch];
							auxEmployee.sector = preSector;

							if ( confirmation (auxEmployee) == 0)
							{
								employee[indexSearch].sector = preSector;
								printf("\nSECTOR modificado exitosamente!\n\n");
								system ("pause");
							}
							else
							{
								printf("\nUsted ha CANCELADO la modificacion del sector.\n\n");
								system("pause");
							}

							break;

					case 5:
							printf("\nSaliendo del submenú del modificaciones...\n\n");
							break;
					}

				}while(optionSubMenu != 5);

				break;




		case 3:
				if (flag == 1)
				{
					printf("\n%-10s %-20s %-20s %-20s %-20s\n", "ID" , "Nombre", "Apellido" , "Salario" , "Sector");

					for (int i = 0; i < ELEMENTS; i++)
					{
						if(employee[i].isEmpty == FALSE)
						printf("%-10d %-20s %-20s %-20.2f %-20d\n\n", employee[i].id, employee[i].name , employee[i].lastName , employee[i].salary , employee[i].sector);
					}


					printf("\nIngrese el ID correspondiente al empleado que quiere dar de BAJA: ");
					fflush(stdin);
					scanf("%d", &idSearch);
					indexSearch = findEmployeeById(employee, ELEMENTS , idSearch);

					printf("\nEmpleado a ser dado de BAJA: \n");

						if ( confirmation (employee[indexSearch]) == 0)
						{
							removeEmployee (employee, ELEMENTS, idSearch);
							accountant--;

							system("pause");
						}

						else
						{
							printf("\nUsted ha CANCELADO la baja!\n\n");
							system("pause");
						}
				}

				else
				{
					printf("\nPara acceder a todas las funciones debe dar de ALTA por lo menos a un empleado!\n\n");
					system ("pause");
				}

				break;



		case 4:

			if( flag == 1)
			{
				printf("\nPara ver la lista de empleados ordenada de forma creciente ingrese 1 , para verla de forma decreciente ingrese 0: ");
				fflush(stdin);
				scanf("%d", &order);

				sortEmployees(employee, ELEMENTS, order);
				printf("\n1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector: \n"
						"----------------------------------------------------------------------------------------\n");
				printEmployees(employee , ELEMENTS);
				printf("\n----------------------------------------------------------------------------------------\n");

				///////////////////////////////////////////////////////////////////////////////////////////////////////////

				for (int i = 0; i < ELEMENTS; i++)
				{
					if (employee[i].isEmpty == FALSE)
					{
						fullSalary += employee[i].salary;
						salaryAccountant++;
					}
				}

				salaryAverage = fullSalary / salaryAccountant;
				for (int i = 0; i < ELEMENTS; i++)
				{
					if (employee[i].isEmpty == FALSE)
					{
						if (employee[i].salary > salaryAverage)
						{
							overAverage++;
						}

					}
				}

				printf("\nEl total de los salarios es: %.2f", fullSalary);
				printf("\nEl promedio de los salarios es: %.2f", salaryAverage);
				printf("\nLa cantidad de empleados que superan el salario promedio son: %d\n", overAverage);
				system("pause");


				break;
			}

			else
			{
				printf("\nPara acceder a todas las funciones debe dar de ALTA por lo menos a un empleado!\n\n");
				system ("pause");
			}

		}

	}while (option != 5);


	return 0;
}
