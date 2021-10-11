
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
