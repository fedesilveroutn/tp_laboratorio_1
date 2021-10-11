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
#define ELEMENTS 5
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
		//ALTA
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




		//MODIFICACION
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



		//BAJA
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


		//INFORMES
		case 4:
				printf("\nPara ver la lista de empleados ordenada de forma creciente ingrese 1 , para verla de forma decreciente ingrese 0: ");
				fflush(stdin);
				scanf("%d", &order);

				sortEmployees(employee, ELEMENTS, order);
				printf("\n1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector: \n");
				printEmployees(employee , ELEMENTS);

				break;




		}



	}while (option != 5);


	printEmployees(employee , ELEMENTS);

	return 0;
}






/*
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




	//Para testear removeEmployee
	removeEmployee (employee , ELEMENTS , 1002);
	removeEmployee (employee , ELEMENTS , 1004);
	//Fin testing------------------------------------------------------------------




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




	//Para testear INPUTS----------------------------------------------------------
	getInt(&num , "Ingrese un numero: ", "Error.Reingrese numero: ", 0, 10);
	printf("\nNumero ingresado: %d", num);
	getFloat(&numFloat , "Ingrese un numero flotante: ", "Error.Reingrese numero flotante: ", 0, 10);
	printf("\nNumero ingresado: %.2f", numFloat);
	getChar(&letter , "Ingrese un caracter: ", "Error.Reingrese caracter: ", 'A', 'z');
	printf("\nCaracter ingresado: %c", letter);
	getString(name , "Ingrese un nombre: ", "Error.Reingrese nombre: ", 51);
	printf("\nNombre ingresado: %s", name);
	//Fin testing------------------------------------------------------------------
	*/
