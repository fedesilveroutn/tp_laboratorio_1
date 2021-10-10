
#include "ArrayEmployees.h"


/**
 * @fn int initEmployees(Employee*, int)
 * @brief To indicate that all position in the array are empty,
 * 		  this function put the flag (isEmpty) in TRUE in all
 *        position of the array
 *
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees (Employee* list, int len)
{
	int i;
	int ret = -1;

	if (list != NULL)
	{
		for (i = 0; i < len ; i++)
		{
			list[i].isEmpty = TRUE;
		}

		ret = 0;
	}

	return ret;
}



/**
 * @fn int addEmployee(Employee*, int, int, char[], char[], float, int)
 * @brief add in a existing list of employees the values received as parameters
 * 		  in the first empty position.
 *
 * @param list employee*
 * @param len int
 * @param id int
 * @param name[] char
 * @param lastName[] char
 * @param salary float
 * @param sector int
 * @return int Return (-1) if Error [Invalid length or NULL pointer or without
		   free space] - (0) if Ok.
 *
 */
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
	int i;
	int index;
	int flag = 0;
	int ret = -1;

	if ( len != 0 && list != NULL )
	{

		for (i = 0; i < len ; i++)
		{
			if ( list[i].isEmpty == TRUE && flag == 0)
			{
				index = i;
				flag = 1;
			}
		}

		list[index].id = id;
		strcpy (list[index].name, name);
		strcpy (list[index].lastName, lastName);
		list[index].salary = salary;
		list[index].sector = sector;
		list[index].isEmpty = FALSE;
		ret = 0;
	}

	return ret;
}



/**
 * @fn int findEmployeeById(Employee*, int, int)
 * @brief find an Employee by Id en returns the index position in array.
 *
 * @param list Employee*
 * @param len int
 * @param id int
 * @return Return employee index position or (-1) if [Invalid length or NULL
 * 		   pointer received or employee not found].
 */
int findEmployeeById(Employee* list, int len,int id)
{
	int i;
	int index;
	int ret = -1;

	if (list != NULL)
	{
		printf("\n\nBuscando coincidencia...\n");
		for ( i = 0; i < len ; i ++)
		{
			if ( list[i].id == id  )
			{
				index = i;
				ret = index;
			}
		}
	}

	return ret;
}



/**
 * @fn int removeEmployee(Employee*, int, int)
 * @brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * @param list Employee*
 * @param len int
 * @param id int
 * @return Return (-1) if Error [Invalid length or NULL pointer or if can't
 * 		   find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id)
{
	int i;
	int ret = -1;

	if (len != 0 && list != NULL)
	{
		printf("\n\nBuscando coincidencia...\n");

		for ( i = 0; i < len ; i++)
		{
			if (list[i].id == id )
			{
				list[i].isEmpty = TRUE;
				printf("Empleado %s %s dado de baja exitosamente!\n", list[i].name, list[i].lastName);
				ret = 0;
			}
		}
	}

	return ret;
}



/**
 * @fn int sortEmployees(Employee*, int, int)
 * @brief Sort the elements in the array of employees, the argument order
 * 		  indicate UP or DOWN order
 *
 * @param list Employee*
 * @param len int
 * @param order int [1] indicate UP - [0] indicate DOWN
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order)
{
	int i;
	int swap;
	int newLimit;
	int ret = -1;
	Employee aux;

	if (len != 0 && list != NULL )
	{
		if (order == UP)
		{
			newLimit = len - 1;

			do{
				swap = 0;

				for (i = 0; i < newLimit; i++)
				{
					if(list[i].isEmpty == FALSE)
					{
						if (strcmp (list[i].lastName , list[i + 1].lastName) == 1 )
						{
							aux = list[i];
							list[i] = list[i + 1];
							list[i + 1] = aux;
							swap = 1;
						}
					}
				}
				newLimit--;

			}while(swap==1);
		}

		else if ( order == DOWN)
		{
			newLimit = len - 1;

			do{
				swap = 0;
				for (i = 0; i < newLimit; i++)
				{
					if ( list[i].isEmpty == FALSE)
					{
						if (strcmp (list[i].lastName , list[i + 1].lastName) == -1 )
						{
							aux = list[i];
							list[i] = list[i + 1];
							list[i + 1] = aux;
							swap = 1;
						}
					}
				}

				newLimit--;

			}while(swap==1);
		}

		ret = 0;
	}
	return ret;
}



/**
 * @fn int printEmployees(Employee*, int)
 * @brief print the content of employees array
 *
 * @param list Employee*
 * @param length int
 * @return int
 */
int printEmployees(Employee* list, int length)
{
	int i;

	if (list != NULL)
	{
		printf("\n%-5s %-20s %-20s %-20s %-20s\n\n", "ID" , "Nombre", "Apellido" , "Salario" , "Sector");

		for( i = 0; i < length ; i++)
		{
			printf("%-5d %-20s %-20s %-20.2f %-20d\n", list[i].id,
													   list[i].name,
													   list[i].lastName,
													   list[i].salary,
													   list[i].sector);
		}
	}

	return 0;
}







