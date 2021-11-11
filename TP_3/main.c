#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "input.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);

    //int option = 0;
    //LinkedList* listaEmpleados = ll_newLinkedList();

	//TEST
	Employee* employee = employee_new();

	int* id = NULL;
	id = (int*) malloc (sizeof(int));

	char* name = NULL;
	name = (char*) malloc (sizeof(char));

	employee_setId(employee, 1005);
	employee_setNombre(employee, "Constanza");

	employee_getNombre(employee, name);
	employee_getId(employee, id);

	printf("\nEl nombre es: %s - El ID es: %d", name , *id);
	//FIN TEST













    /*do{

    	getInt (&option,
				 "\n-------------------------------------------------------------------------------\n"
				 "\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)."
				 "\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)."
				 "\n3. Alta de empleado"
				 "\n4. Modificar datos de empleado"
				 "\n5. Baja de empleado"
				 "\n6. Listar empleados"
				 "\n7. Ordenar empleados"
				 "\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)."
				 "\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario)."
				 "\n10. Salir"
				 "\n-------------------------------------------------------------------------------\n"
				 "Ingrese una opcion (1 - 10): ",
				 "\nERROR!\n"
				 "\n-------------------------------------------------------------------------------\n"
				 "\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)."
				 "\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)."
				 "\n3. Alta de empleado"
				 "\n4. Modificar datos de empleado"
				 "\n5. Baja de empleado"
				 "\n6. Listar empleados"
				 "\n7. Ordenar empleados"
				 "\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)."
				 "\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario)."
				 "\n10. Salir"
				 "\n-------------------------------------------------------------------------------\n"
				 "Reingrese una opcion valida (1 - 10): ", 1 , 10 );

        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
        }

    }while(option != 10);*/

    return 0;
}

