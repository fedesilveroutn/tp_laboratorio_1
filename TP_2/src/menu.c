
#include "menu.h"



/**
 * @fn int confirmation(Employee)
 * @brief	shows to user the entered information in order to verificate it´s ok
 *
 * @param aux Employee
 * @return 0 if user confirms the entered information, -1 if he/her wants to cancell
 */
int confirmation (Employee aux)
{
	char answer;
	int ret;

	printf("----------------------------------------------------------------------------------------\n");
	printf("\n%-10s %-20s %-20s %-20s %-20s\n", "ID" , "Nombre", "Apellido" , "Salario" , "Sector");
	printf("%-10d %-20s %-20s %-20.2f %-20d\n\n", aux.id, aux.name ,aux.lastName ,aux.salary , aux.sector);

	printf("----------------------------------------------------------------------------------------\n"
			"\nDesea confirmar los datos ingresados? (s / n) : ");
	fflush (stdin);
	scanf("%c", &answer);

		while ( answer != 's' && answer != 'n' )
		{
			printf("Ha ingresado un caracter inválido. Reingrese su respuesta (s / n): ");
			fflush (stdin);
			scanf("%c", &answer);
		}

	if (answer == 's')
	{
		ret = 0;
	}
	else if (answer == 'n')
	{
		ret = -1;
	}

	return ret;
}



int mainMenu (Employee* list , int len , int lastIdentification)
{
	Employee auxEmployee;
	int option;
	int subOption;
	int preId;
	int preSector;
	int lastId;
	int idSearch;
	int indexSearch;
	int order;
	char preName [51];
	char preLastName[51];
	float preSalary;
	float fullSalary = 0;
	float salaryAverage;

	int accountant = 0;
	int salaryAccountant = 0;
	int overAverage = 0;
	int flag = 0;

	lastId = lastIdentification;

	do
	{


	preId = lastId;
	getInt(&option,
					"\n--------------------------------\n"
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
			if (accountant <= 1000)
			{
				printf("\nDando de alta un empleado...");
				//pido los datos del empleado a dar de alta
				getString (preName, "\nIngrese nombre: ", "\nError. Reingrese un nombre válido (hasta 50 caracteres): ", 51);
				getString (preLastName, "Ingrese apellido: ", "\nError. Reingrese un nombre válido (hasta 50 caracteres): ", 51);
				getFloat (&preSalary, "Ingrese sueldo: ", "\nError. Reingrese un sueldo válido (5000 - 500000): ", 5000 , 500000);
				getInt (&preSector, "Ingrese sector: ", "\nError. Reingrese un sector válido (1 - 8): ", 1 , 8);

				//guardo esos datos en la estructura auxiliar
				auxEmployee.id = preId + 1;
				strcpy (auxEmployee.name , preName);
				strcpy (auxEmployee.lastName , preLastName);
				auxEmployee.salary = preSalary;
				auxEmployee.sector =  preSector;

				//muestro los datos ingresado y pido confirmacion
				printf("\nEmpleado a ser dado de ALTA: \n");
				if ( confirmation (auxEmployee) == 0)
				{
					addEmployee(list, len , auxEmployee.id, auxEmployee.name, auxEmployee.lastName, auxEmployee.salary, auxEmployee.sector);
					accountant++;
					lastId++;
					flag = 1;
					printf("\nEmpleado dado de ALTA exitosamente!\n\n");
					system("pause");
				}

				else
				{
					printf("\nUsted ha CANCELADO el alta!\n\n");
					system("pause");
				}
			}

			else
			{
				printf("\nError. Ha alcanzado el límite de empleados permitidos.");
			}
			break;

	case 2:
		if(flag == 1)
		{
			//muestro la lista de empleados con sus datos
			printf("\n%-10s %-20s %-20s %-20s %-20s\n", "ID" , "Nombre", "Apellido" , "Salario" , "Sector");
			for (int i = 0; i < len; i++)
			{
				if(list[i].isEmpty == FALSE)
				printf("%-10d %-20s %-20s %-20.2f %-20d\n\n", list[i].id, list[i].name , list[i].lastName , list[i].salary , list[i].sector);
			}
			//solicito el ingreso del id del empleado a modificar y lo guardo en idSearch
			printf("\nIngrese el ID correspondiente al empleado que quiere MODIFICAR: ");
			fflush(stdin);
			scanf("%d", &idSearch);
			//busco la posicion en la que se encuentra el empleado que corresponde al id ingresado, guardo en indexSearch
			indexSearch = findEmployeeById(list, len , idSearch);

			//muestro submenu
			printf("\nElija la opción que desea MODIFICAR: \n");
			do
			{
			getInt (&subOption, "\n--------------------------------\n"
								"\nMENU DE MODIFICACIONES"
								"\n--------------------------------\n"
								"1. NOMBRE\n"
								"2. APELLIDO\n"
								"3. SALARIO\n"
								"4. SECTOR\n"
								"5. ATRAS"
								"\n--------------------------------\n"
								"Ingrese una opción (1-5): ",
								"\n--------------------------------\n"
								"1. NOMBRE\n"
								"2. APELLIDO\n"
								"3. SALARIO\n"
								"4. SECTOR\n"
								"5. ATRAS\n"
								"\n--------------------------------\n"
								"Error. Reingrese una opción válida (1-5): ", 1 , 5);

				switch (subOption)
				{

				case 1:
						//solicito el ingreso del nuevo nombre y lo guardo en un auxiliar
						getString(preName , "Ingrese el NUEVO NOMBRE: ", "Error. Reingrese un nombre válido (hasta 50 caracteres): ", 51);
						auxEmployee = list[indexSearch];
						strcpy (auxEmployee.name , preName);
						//muestro los datos y pido confirmacion
						if( confirmation(auxEmployee) == 0)
						{
							strcpy (list[indexSearch].name , preName);
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
						auxEmployee = list[indexSearch];
						strcpy (auxEmployee.lastName , preLastName);

						if( confirmation(auxEmployee) == 0)
						{
							strcpy (list[indexSearch].lastName , preLastName);
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
						auxEmployee = list[indexSearch];
						auxEmployee.salary = preSalary;

						if ( confirmation (auxEmployee) == 0)
						{
							list[indexSearch].salary = preSalary;
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
						auxEmployee = list[indexSearch];
						auxEmployee.sector = preSector;

						if ( confirmation (auxEmployee) == 0)
						{
							list[indexSearch].sector = preSector;
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

			}while(subOption != 5);
		}

		else
		{
			printf("\nPara acceder a todas las funciones debe dar de ALTA por lo menos a un empleado!\n\n");
			system ("pause");
		}

			break;

	case 3:
			if (flag == 1)
			{
				//muestro la lista de empleados con sus datos
				printf("\n%-10s %-20s %-20s %-20s %-20s\n", "ID" , "Nombre", "Apellido" , "Salario" , "Sector");
				for (int i = 0; i < len; i++)
				{
					if(list[i].isEmpty == FALSE)
					{
						printf("%-10d %-20s %-20s %-20.2f %-20d\n\n", list[i].id, list[i].name , list[i].lastName , list[i].salary , list[i].sector);
					}
				}
				//solicito el ingreso del id correspondiente al empleado a ser dado de baja
				printf("\nIngrese el ID correspondiente al empleado que quiere dar de BAJA: ");
				fflush(stdin);
				scanf("%d", &idSearch);
				//guardo la posicion en la que se encuentra el empleado que corresponde al id ingresado
				indexSearch = findEmployeeById(list, len , idSearch);
				//muestro el empleado a ser dadod de baja y pido confirmacion
				printf("\nEmpleado a ser dado de BAJA: \n");
				if ( confirmation (list[indexSearch]) == 0)
				{
					removeEmployee (list, len, idSearch);
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
				//pregunto el orden en el que se va a mostrar la lista y la ordeno
				printf("\nDe qué forma quiere ordenar la lista de empleados? (0 = decreciente / 1 = creciente): ");
				fflush(stdin);
				scanf("%d", &order);
				sortEmployees(list, len, order);
				//sumo todos los salarios que hay y por cada uno que haya sumo el contador de salarios
				for (int i = 0; i < len; i++)
				{
					if (list[i].isEmpty == FALSE)
					{
						fullSalary += list[i].salary;
						salaryAccountant++;
					}
				}
				//calculo el salario promedio y cuento cada empleado que lo supere
				salaryAverage = fullSalary / salaryAccountant;
				for (int i = 0; i < len; i++)
				{
					if (list[i].isEmpty == FALSE)
					{
						if (list[i].salary > salaryAverage)
						{
							overAverage++;
						}
					}
				}

				//informo los datos
				printf("\n1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector: "
					   "\n----------------------------------------------------------------------------------------\n");
				printEmployees(list , len);
				printf("\n----------------------------------------------------------------------------------------\n"
						"\nEl total de los salarios es: %.2f"
						"\nEl promedio de los salarios es: %.2f"
						"\nLa cantidad de empleados que superan el salario promedio son: %d\n"
						"\n----------------------------------------------------------------------------------------\n",
						fullSalary , salaryAverage , overAverage);


				fullSalary = 0;
				salaryAccountant = 0;
				salaryAverage = 0;
				overAverage = 0;

				system("pause");
			}

			else
			{
				printf("\nPara acceder a todas las funciones debe dar de ALTA por lo menos a un empleado!\n\n");
				system ("pause");
			}

			break;


	case 5:
			printf("\nSaliendo del programa...");
			break;

	}

	}while(option != 5);

	printf("\nFin del programa.");

	return 0;
}
