#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "input.h"
#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int ret = 1;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path , "r");
		if(pFile != NULL)
		{
			ret = parser_EmployeeFromText(pFile , pArrayListEmployee);
		}
		fclose(pFile);
	}

	return ret;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int ret = 1;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path , "rb");
		if(pFile != NULL)
		{
			ret = parser_EmployeeFromText(pFile , pArrayListEmployee);
		}
		fclose(pFile);
	}

	return ret;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int lastIdFromMain)
{
	Employee* auxEmployee = NULL;
	int ret = 0;

	if(pArrayListEmployee != NULL)
	{
		auxEmployee = employee_add(lastIdFromMain);

		if ( employee_confirmacion(auxEmployee) )
		{
			ll_add(pArrayListEmployee, auxEmployee);
			printf("\n*****EMPLEADO CARGADO EXITOSAMENTE*****");
			ret = 1;
		}

		else
		{
			printf("\nHa cancelado la carga!");
		}
	}

    return ret;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int ret = 0;
	int option;
	int i;

	int len;
	int auxId;
	int idFromEmployee;
	char auxName[128];
	int auxHours;
	int auxSalary;
	Employee* auxEmployee = NULL;

	if (pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);

		controller_ListEmployee(pArrayListEmployee);
		printf("\nIngrese el ID correspondiente al empleado que desea modificar: ");
		fflush(stdin);
		scanf("%d", &auxId);
		for (i = 0; i < len; i++)
		{
			auxEmployee = ll_get(pArrayListEmployee, i);
			employee_getId(auxEmployee, &idFromEmployee);
			if (auxId == idFromEmployee)
			{
				getInt(&option, "\n------------------------------------------------------------\n"
								"\n1. Modificar nombre"
								"\n2. Modificar horas trabajadas"
								"\n3. Modificar sueldo"
								"\n------------------------------------------------------------\n"
								"\nIngrese la opcion a modificar (1-3): ",
								 "\n------------------------------------------------------------\n"
								"\n1. Modificar nombre"
								"\n2. Modificar horas trabajadas"
								"\n3. Modificar sueldo"
								"\n------------------------------------------------------------\n"
								"\nERROR. Reingrese una opcion valida (1-3): ", 1 , 3 );
				switch (option)
				{
					case 1:
							getString(auxName, "\nIngrese el nuevo nombre: ", "\nERROR. Reingrese un nombre valido (hasta 127 caracteres): ", 127);
							employee_setNombre(auxEmployee, auxName);
							ll_set(pArrayListEmployee, i, auxEmployee);
							break;

					case 2:
							getInt(&auxHours, "\nIngrese la nueva cantidad de horas: ", "\nERROR. Reingrese cantidad valida (hasta 10000): ", 0 , 10000);
							employee_setHorasTrabajadas(auxEmployee, auxHours);
							ll_set(pArrayListEmployee, i, auxEmployee);
							break;

					case 3:
							getInt(&auxSalary, "\nIngrese el nuevo salario: ", "\nERROR. Reingrese un monto valido (1000-1000000): ", 1000 , 1000000);
							employee_setSueldo(auxEmployee, auxSalary);
							ll_set(pArrayListEmployee, i, auxEmployee);
							break;
				}

				ret = 1;
			}
		}
	}

    return ret;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee = NULL;
	int idFromEmployee;
	int auxId;
	int len;
	int i;
	int ret = 0;

	if (pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);
		controller_ListEmployee(pArrayListEmployee);
		printf("\nIngrese el ID correspondiente al empleado que desea dar de baja: ");
		fflush(stdin);
		scanf("%d", &auxId);

		for (i = 0; i < len; i++)
		{
			auxEmployee = ll_get(pArrayListEmployee, i);
			employee_getId(auxEmployee, &idFromEmployee);
			if (auxId == idFromEmployee)
			{
				ll_remove(pArrayListEmployee, i);
				employee_delete(auxEmployee);
			}
		}
		ret = 1;
	}

    return ret;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int len;
	int i = 0;
	int ret = 0;
	Employee* auxEmployee;


	if (pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);
		printf("\n%-5s %-14s %-9s %-10s\n", "ID", "NOMBRE", "HORAS", "SALARIO");
		for (i = 0; i < len; i++ )
		{
			auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);

			//MODULARIZAR
			printf("\n%-5d %-14s %-9d %-10d", auxEmployee->id, auxEmployee->nombre, auxEmployee->horasTrabajadas, auxEmployee->sueldo );
		}

		ret = 1;
	}

    return ret;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int option;
	int order;
	int (*pFunctionSortById) (void* , void*);
	int (*pFunctionSortByName) (void* , void*);
	int (*pFunctionSortByHours) (void* , void*);
	int (*pFunctionSortBySalary) (void* , void*);

	pFunctionSortById = employee_sortById;
	pFunctionSortByName = employee_sortByName;
	pFunctionSortByHours = employee_sortByHours;
	pFunctionSortBySalary = employee_sortBySalary;

	getInt(&order, "De que manera desea ordenar la lista? (1 = CRECIENTE / 0 = DECRECIENTE): ",
				   "\nERROR. INGRESAR UN NUMERO VALIDO (1 = CRECIENTE / 0 = DECRECIENTE): ", 0 , 1);

	getInt(&option , "\n------------------------SUBMENU-------------------------\n"
					 "\n1. Ordenar segun el ID"
					 "\n2. Ordenar segun el NOMBRE"
					 "\n3. Ordenar segun las HORAS TRABAJADAS"
					 "\n4. Ordenar segun el SUELDO"
					 "\n--------------------------------------------------------\n"
					 "\nIngrese una opcion (1-4): ",
					 "\nERROR!\n"
					 "\n------------------------SUBMENU-------------------------\n"
					 "\n1. Ordenar segun el ID"
					 "\n2. Ordenar segun el NOMBRE"
					 "\n3. Ordenar segun las HORAS TRABAJADAS"
					 "\n4. Ordenar segun el SUELDO"
					 "\n--------------------------------------------------------\n"
					 "\nReingrese una opcion valida (1-4): ", 1 , 4	);
	switch (option)
	{
		case 1:
				ll_sort(pArrayListEmployee, pFunctionSortById, order);
				break;

		case 2:
				ll_sort(pArrayListEmployee, pFunctionSortByName, order);
				break;

		case 3:
				ll_sort(pArrayListEmployee, pFunctionSortByHours, order);
				break;

		case 4:
				ll_sort(pArrayListEmployee , pFunctionSortBySalary , order);
				break;
	}




    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int ret = 0;
	int len;
	int i;

	int auxId;
	char auxName[128];
	int auxHours;
	int auxSalary;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen (path, "w");
		len = ll_len(pArrayListEmployee);
		if (pFile != NULL)
		{
			fprintf(pFile,"%s\n", "id,nombre,horasTrabajadas,sueldo");
			for(i = 0; i < len; i++)
			{
				Employee* auxEmployee = (Employee*) ll_get (pArrayListEmployee , i );
				employee_getId(auxEmployee, &auxId);
				employee_getNombre(auxEmployee, auxName);
				employee_getHorasTrabajadas(auxEmployee, &auxHours);
				employee_getSueldo(auxEmployee, &auxSalary);

				fprintf(pFile, "%d,", auxId);
				fprintf(pFile, "%s," , auxName);
				fprintf(pFile, "%d," , auxHours);
				fprintf(pFile, "%d\n" , auxSalary);
			}

			ret = 1;
		}
		fclose (pFile);
		pFile = NULL;
	}
    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee = NULL;
	FILE* pFile;
	int ret = 0;
	int len;
	int i;

	int auxId;
	char auxName[128];
	int auxHours;
	int auxSalary;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen (path, "wb");
		len = ll_len(pArrayListEmployee);
		if (pFile != NULL)
		{
			fwrite(auxEmployee, sizeof(Employee), 1 , pFile );

			for(i = 0; i < len; i++)
			{
				Employee* auxEmployee = (Employee*) ll_get (pArrayListEmployee , i );
				employee_getId(auxEmployee, &auxId);
				employee_getNombre(auxEmployee, auxName);
				employee_getHorasTrabajadas(auxEmployee, &auxHours);
				employee_getSueldo(auxEmployee, &auxSalary);
				fwrite(auxEmployee, sizeof(Employee), 1 , pFile );
			}

			ret = 1;
		}
		fclose (pFile);
		pFile = NULL;
	}
	return ret;
}

