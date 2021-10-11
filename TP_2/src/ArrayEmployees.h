
#ifndef ARRAYEMPLOYEES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

#define ARRAYEMPLOYEES_H_
#define TRUE 1
#define FALSE 0
#define UP 1
#define DOWN 0



struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;

}typedef Employee;



int initEmployees (Employee* list, int len);
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int findEmployeeById(Employee* list, int len,int id);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
int printEmployees(Employee* list, int length);







#endif /* ARRAYEMPLOYEES_H_ */
