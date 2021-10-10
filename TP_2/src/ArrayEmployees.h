
#ifndef ARRAYEMPLOYEES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAYEMPLOYEES_H_
#define TRUE 1
#define FALSE 0
#define UP 1
#define DOWN 0


//DEFINICION DE LA ESTRUCTURA EMPLOYEE
struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;

}typedef Employee;


//FUNCIONES EMPLOYEE
int initEmployees (Employee* list, int len);
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int findEmployeeById(Employee* list, int len,int id);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
int printEmployees(Employee* list, int length);







#endif /* ARRAYEMPLOYEES_H_ */
