/*
 ============================================================================
Trabajo práctico N°2
Alumno: Federico Elías Silvero
División: 1°D
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "input.h"
#include "menu.h"
#define ELEMENTS 10
#define ID 1000

int main(void) {
	setbuf(stdout, NULL);

	Employee employee[ELEMENTS];

	initEmployees (employee, ELEMENTS);
	mainMenu (employee , ELEMENTS , ID);

	return 0;
}
