/*
 * arrayEmployees.h
 *
 *  Created on: 16 oct. 2021
 *      Author: Asus
 */
#include "sector.h"

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;

}sEmployee;

int initEmployees(sEmployee empleados[], int tam);

int findFree(sEmployee empleados[], int tam);

int addEmployes(sEmployee empleados[], int tam, sSector sectores[], int tamS, int* pId);

int findEmployee(sEmployee empleados[], int tam, int id);

int removeEmployee(sEmployee empleados[], sSector sectores[], int tamS, int tam);

int printEmployees(sEmployee empleados[], sSector sectores[], int tamS, int tam);

int sortEmployees(sEmployee empleados[], sSector sectores[], int tamS, int tam);

int changeEmployee(sEmployee empleados[], sSector sectores[], int tamS, int tam);

int totalSalary(sEmployee empleados[], int tam);

int avarageSalary(sEmployee empleados[], int tam);

int validarId(sEmployee empleados[], int tam, int id);


#endif /* ARRAYEMPLOYEES_H_ */
