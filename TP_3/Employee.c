
#include "Employee.h"

//FUNCIONA
/**
 * @brief reserva un lugar en la memoria del heap para una estructura del tipo Employee
 * @return
 */
Employee* employee_new()
{
	Employee* employee = NULL;
	employee = (Employee*) malloc (sizeof (Employee) );
	return employee;
}


//FUNCIONA
/**
 * @brief reserva espacio en memoria dentro del heap para una estructura Employee y ademas carga los campos ID, NOMBRE y HORAS
 *
 * @param idStr
 * @param nombreStr
 * @param horasTrabajadasStr
 * @return
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
	Employee* employee = NULL;
	employee = employee_new();
	int auxId;
	int auxHoras;

	if (employee != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL)
	{
		auxId = atoi (idStr);
		auxHoras = atoi (horasTrabajadasStr);

		employee->id = auxId;
		strcpy( employee->nombre , nombreStr );
		employee->horasTrabajadas = auxHoras;
	}

	return employee;
}


//FUNCIONA
/**
 * @fn
 * @brief asigna el ID recibido, al campo ID del puntero a una estructura Employee
 *
 * @param this
 * @param id
 * @return
 */
int employee_setId(Employee* this,int id)
{
	int ret = -1;
	if (this != NULL)
	{
		this->id = id;
		ret = 0;
	}
	return ret;
}


//FUNCIONA
/**
 * @brief guarda el ID del campo de la estructura Employee, en el puntero que se pasa como segundo parámetro
 *
 * @param this
 * @param id
 * @return
 */
int employee_getId(Employee* this,int* id)
{
	int ret = -1;
	if (this != NULL && id != NULL)
	{
		*id = this->id;
		ret = 0;
	}
	return ret;
}


//FUNCIONA
/**
 * @brief asigna el NOMBRE recibido, al campo nombre de la estructura Employeee
 *
 * @param this
 * @param nombre
 * @return
 */
int employee_setNombre(Employee* this,char* nombre)
{
	int ret = -1;
	if (this != NULL)
	{
		strcpy ( this->nombre , nombre );
		ret = 0;
	}
	return ret;
}


//FUNCIONA
/**
 * @brief guarda el NOMBRE del campo de la estructura Employee, en el puntero que se pasa como segundo parámetro
 *
 * @param this
 * @param nombre
 * @return
 */
int employee_getNombre(Employee* this,char* nombre)
{
	int ret = -1;
	if(this != NULL && nombre != NULL)
	{
		strcpy (nombre , this->nombre);
		ret = 0;
	}
	return ret;
}

