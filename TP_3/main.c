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
				 "\n10. Salir"
				 "\n-------------------------------------------------------------------------------\n"
				 "Ingrese una opcion (1 - 10): ",
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
				 "\n10. Salir"
				 "\n-------------------------------------------------------------------------------\n"
				 "Reingrese una opcion valida (1 - 10): ", 1 , 10 );

        switch(option)
        {
            case 1:
					if (!controller_loadFromText("data.csv", listaEmpleados) )
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
						controller_loadFromBinary("data.csv", listaEmpleados);
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
						if ( controller_saveAsText("data.csv", listaEmpleados) )
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
						if (controller_saveAsBinary("dataBinary.csv", listaEmpleados) )
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
            		printf("\nSaliendo del programa...");
            		break;
        }

    }while(option != 10);

    printf("\nFIN DEL PROGRAMA.");

    return 0;
}

