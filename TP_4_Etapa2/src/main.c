#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "input.h"

int main()
{
	setbuf(stdout, NULL);

    int option = 0;
    int flag = 0;
    int lastIdMain;

    lastIdMain = getLastIdFromTxt();

    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaEmpleados2 = ll_newLinkedList();

    do{

    	getInt (&option,
				 "\n------------------------------------MENU----------------------------------------\n"
				 "\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)."
				 "\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)."
				 "\n3. Alta de empleado"
				 "\n4. Modificar datos de empleado"
				 "\n5. Baja de empleado"
				 "\n6. Listar empleados"
				 "\n7. Ordenar empleados"
				 "\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)."
				 "\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario)."
				 "\n10.Agregar un empleado en una posicion específica"
				 "\n11.Eliminar un empleado en una posicion específica"
				 "\n12.Verificar si la lista esta vacia"
				 "\n13.Clonar lista"
				 "\n14.Crear una sublista"
				 "\n15.Verificar si la segunda lista contiene todos los elementos de la primera"
				 "\n16. Salir"
				 "\n-------------------------------------------------------------------------------\n"
				 "Ingrese una opcion (1 - 16): ",
				 "\nERROR!\n"
				 "\n------------------------------------MENU----------------------------------------\n"
				 "\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)."
				 "\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)."
				 "\n3. Alta de empleado"
				 "\n4. Modificar datos de empleado"
				 "\n5. Baja de empleado"
				 "\n6. Listar empleados"
				 "\n7. Ordenar empleados"
				 "\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)."
				 "\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario)."
				 "\n10.Agregar un empleado en una posicion específica"
				 "\n11.Eliminar un empleado en una posicion específica"
				 "\n12.Verificar si la lista esta vacia"
				 "\n13.Clonar lista"
				 "\n14.Crear una sublista"
				 "\n15.Verificar si la segunda lista contiene todos los elementos de la primera"
				 "\n16. Salir"
				 "\n-------------------------------------------------------------------------------\n"
				 "Reingrese una opcion valida (1 - 16): ", 1 , 16 );

        switch(option)
        {
            case 1:
					if (!controller_loadFromText("src\\data.csv", listaEmpleados) )
					{
						printf("\n*****ARCHIVO LEIDO EXITOSAMENTE!*****\n");
						systemPause("Presione enter para continuar...\n");
						flag = 1;
					}

					else
					{
						printf("\nERROR. NO SE HA PODIDO LEER EL ARCHIVO!");
						systemPause("\nPresione enter para continuar...\n");
					}

					break;

            case 2:
            		if (flag)
            		{
						controller_loadFromBinary("src\\data.csv", listaEmpleados);
						printf("\n*****ARCHIVO LEIDO (MODO BINARIO) EXITOSAMENTE!*****\n");
            		}

            		else
					{
						printf("\nERROR. ACCESO DENEGADO. DEBE CARGAR LOS DATOS DE LOS EMPLEADOS (MODO TEXTO) PREVIAMENTE!");
						systemPause("\nPresione enter para continuar...\n");
					}
					break;

            case 3:
					if (flag)
					{
						if ( controller_addEmployee(listaEmpleados, lastIdMain) )
						{
							lastIdMain++;
						}
						systemPause("\nPresione enter para continuar...\n");
					}

					else
					{
						printf("\nERROR. ACCESO DENEGADO. DEBE CARGAR LOS DATOS DE LOS EMPLEADOS PREVIAMENTE!");
						systemPause("\nPresione enter para continuar...\n");
					}
					break;

            case 4:
					if(flag)
					{
						controller_editEmployee(listaEmpleados);
					}

					else
					{
						printf("\nERROR. ACCESO DENEGADO. DEBE CARGAR LOS DATOS DE LOS EMPLEADOS PREVIAMENTE!");
						systemPause("\nPresione enter para continuar...\n");
					}
					break;

            case 5:
					if(flag)
					{
						if ( controller_removeEmployee(listaEmpleados) )
						{
							printf("\n*****EMPLEADO DADO DE BAJA EXITOSAMENTE!*****");
						}

						else
						{
							printf("\nERROR. NO FUE POSIBLE REALIZAR LA BAJA DEL EMPLEADO!");
						}
					}

					else
					{
						printf("\nERROR. ACCESO DENEGADO. DEBE CARGAR LOS DATOS DE LOS EMPLEADOS PREVIAMENTE!");
						systemPause("\nPresione enter para continuar...\n");
					}
					break;

            case 6:
					if(flag)
					{
						printf("\nListando empleados...\n");
						controller_ListEmployee(listaEmpleados);
						systemPause("\nPresione enter para continuar...\n");
					}

					else
					{
						printf("\nERROR. ACCESO DENEGADO. DEBE CARGAR LOS DATOS DE LOS EMPLEADOS PREVIAMENTE!");
						systemPause("\nPresione enter para continuar...\n");
					}
					break;

            case 7:
					if(flag)
					{
						controller_sortEmployee(listaEmpleados);
					}

					else
					{
						printf("\nERROR. ACCESO DENEGADO. DEBE CARGAR LOS DATOS DE LOS EMPLEADOS PREVIAMENTE!");
						systemPause("\nPresione enter para continuar...\n");
					}
					break;

            case 8:
					if(flag)
					{
						if ( controller_saveAsText("src\\data.csv", listaEmpleados) )
						{
							saveLastIdToTxt(lastIdMain);
							printf("\n*****DATOS GUARDADOS (MODO TEXTO) EXITOSAMENTE!*****");
							systemPause("\nPresione enter para continuar...\n");
						}

						else
						{
							printf("\nERROR. NO SE HAN PODIDO GUARDAR LOS DATOS EN MODO TEXTO!");
							systemPause("\nPresione enter para continuar...\n");
						}
					}

					else
					{
						printf("\nERROR. ACCESO DENEGADO. DEBE CARGAR LOS DATOS DE LOS EMPLEADOS PREVIAMENTE!");
						systemPause("\nPresione enter para continuar...\n");
					}
					break;

            case 9:
					if(flag)
					{
						if (controller_saveAsBinary("src\\dataBinary.csv", listaEmpleados) )
						{
							saveLastIdToTxt(lastIdMain);
							printf("\n*****DATOS GUARDADOS (MODO BINARIO) EXITOSAMENTE!*****");
							systemPause("\nPresione enter para continuar...\n");
						}
						else
						{
							printf("\nERROR. NO SE HAN PODIDO GUARDAR LOS DATOS EN MODO BINARIO!");
							systemPause("\nPresione enter para continuar...\n");
						}
					}

					else
					{
						printf("\nERROR. ACCESO DENEGADO. DEBE CARGAR LOS DATOS DE LOS EMPLEADOS PREVIAMENTE!");
					}
					break;




            case 10:
            		if(flag)
					{
            			controller_addEmployeeHere (listaEmpleados, lastIdMain );
					}
            		else
					{
						printf("\nERROR. ACCESO DENEGADO. DEBE CARGAR LOS DATOS DE LOS EMPLEADOS PREVIAMENTE!");
					}

            		break;


            case 11:
            		if(flag)
					{
						controller_removeEmployeeHere (listaEmpleados, lastIdMain );
					}
					else
					{
						printf("\nERROR. ACCESO DENEGADO. DEBE CARGAR LOS DATOS DE LOS EMPLEADOS PREVIAMENTE!");
					}

            		break;


            case 12:
            		controller_isEmpty(listaEmpleados);
            		break;


            case 13:
            		listaEmpleados2 = ll_clone(listaEmpleados);
            		controller_ListEmployee(listaEmpleados2);
            		break;



            case 14:
            		controller_createSublist(listaEmpleados);
            		break;


            case 15:
            		controller_checkContainsAll(listaEmpleados, listaEmpleados2);
            		break;

            case 16:
            		printf("\nSaliendo del programa...");
            		ll_deleteLinkedList(listaEmpleados);
            		break;
        }

    }while(option != 15);

    printf("\nFIN DEL PROGRAMA.");

    return 0;
}

