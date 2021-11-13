#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	char auxId[51];
	char auxName[128];
	char auxHours[51];
	char auxSalary[51];
	int ret = 1;

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", auxId, auxName, auxHours, auxSalary);
		while (!feof(pFile))
		{
			fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", auxId, auxName, auxHours, auxSalary);
			Employee* auxEmployee = employee_newParametros(auxId, auxName, auxHours, auxSalary);
			ll_add(pArrayListEmployee, auxEmployee);
		}

		if (feof (pFile))
		{
			ret = 0;
		}
	}
    return ret;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
