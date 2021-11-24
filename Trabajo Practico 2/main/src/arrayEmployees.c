/*
 * arrayEmployees.c
 *
 *  Created on: 16 oct. 2021
 *      Author: Asus
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

int initEmployees(sEmployee empleados[], int tam)
{
	int exito = 0;

	if(empleados != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			empleados[i].isEmpty = 1;
			exito = 1;
		}
	}
	return exito;
}


int findFree(sEmployee empleados[], int tam)
{
	int indice = -1;

	if(empleados != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(empleados[i].isEmpty == 1)
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}

int addEmployes(sEmployee empleados[], int tam, sSector sectores[], int tamS, int* pId)
{

	int exito = -1;
	int indice;
	sEmployee nuevoEmpleado;

	printf("\n\tAlta del Empleado\n\n");
	printf("Su numero de Id es : %d\n\n", *pId);

	if(empleados != NULL && tam > 0 && pId != NULL && sectores != NULL && tamS > 0)
	{

		indice = findFree(empleados, tam);

		if(indice == -1)
		{
			printf("Disculpe las molestias. No hay lugar en el sistema");
		}
		else
		{

			printf("Ingrese nombre del empleado: ");
			fflush(stdin);
			gets(nuevoEmpleado.name);
			printf("\n");

			printf("Ingrese apellido del empleado: ");
			fflush(stdin);
			gets(nuevoEmpleado.lastName);
			printf("\n");

			printf("Ingrese salario del empleado: ");
			fflush(stdin);
			scanf("%f", &nuevoEmpleado.salary);
			printf("\n");
			while(!(nuevoEmpleado.salary > 0))
			{
				printf("Dato invalido. Re ingrese salario del empleado: ");
				fflush(stdin);
				scanf("%f", &nuevoEmpleado.salary);
				printf("\n");
			}

			printSectors(sectores, tamS);

			printf("Ingrese el sector al que pertenece el empleado: ");
			fflush(stdin);
			scanf("%d", &nuevoEmpleado.sector);
			printf("\n");
			while(!(nuevoEmpleado.sector >= 500 && nuevoEmpleado.sector <= 504))
			{
				printf("Sector invalido. Re ingrese el sector al que pertenece el empleado: ");
				fflush(stdin);
				scanf("%d", &nuevoEmpleado.sector);
				printf("\n");
			}


			nuevoEmpleado.id = *pId;
			(*pId)++;
			nuevoEmpleado.isEmpty = 0;

			empleados[indice] = nuevoEmpleado;
			exito = 1;

		}
	}
	return exito;
}


int findEmployee(sEmployee empleados[], int tam, int id)
{
	int indice = -1;

	if(empleados != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if( empleados[i].id == id && empleados[i].isEmpty == 0){

				indice = i;
				break;
			}
		}
	}
	return indice;
}

int removeEmployee(sEmployee empleados[], sSector sectores[], int tamS, int tam)
{
	int exito = -1;
	int idEmployee = 0;
	int indice;

	printEmployees(empleados, sectores, tamS, tam);
	printf("\t\n\nBaja de Empleados\n\n");
	printf("Introduza el numero de Id del empleado: ");
	fflush(stdin);
	scanf("%d", &idEmployee);
	if(validarId(empleados, tam, idEmployee) == -1)
	{
		printf("No existe ningun empleado con ese numero de Id. Reingrese: ");
		fflush(stdin);
		scanf("%d", &idEmployee);
	}



	if(empleados != NULL && tam > 0 && sectores != NULL && tamS > 0)
	{
		indice = findEmployee(empleados, tam, idEmployee);

		if(indice == -1)
		{
			printf("\nEl Id : %d no corresponde a ningun empleado del sistema", idEmployee);
		}
		else
		{

			empleados[indice].isEmpty = 1;

			exito = 1;

			printf("\nBaja realizada con exito");
		}
	}
	return exito;
}

int printEmployees(sEmployee empleados[], sSector sectores[], int tamS, int tam)
{
	int exito = -1;
	int flag = 1;
	float total;
	float avarage;
	char descripcion[51];
	int quantity = 0;

	total = totalSalary(empleados, tam);
	avarage = avarageSalary(empleados, tam);

	for(int i = 0; i < tam; i++){

		if(empleados[i].isEmpty == 0 && empleados[i].salary > avarage){

			quantity++;
		}
	}


	sortEmployees(empleados, sectores, tamS, tam);
	printf("\n\t\t\tListado de Empleados\t\t\t\n\n");
	printf("N del Id\tNombre\t\tApellido\tSueldo\t\tSector\n");
	printf(" ---------------------------------------------------------------------");
	printf("\n\n");

	if(empleados != NULL && tam > 0 && sectores != NULL && tamS > 0)
	{

	    for(int i = 0; i < tam; i++)
	    {
	        if(empleados[i].isEmpty == 0)
	        {
	        	if(descriptionSector(empleados[i].sector, sectores, tamS, descripcion))
	        	{
	        		printf("  %d\t%13s\t\t%-10s\t$%.2f\t%s",
	            		empleados[i].id, empleados[i].name,
	            		empleados[i].lastName, empleados[i].salary,
					    descripcion);
	        		printf("\n");
	        		flag = 0;

	        	}
	        }
	    }
	    if(flag)
	    {
	        printf("No hay empleados para mostrar");
	    }

	    if(total != 0 && avarage != 0)
	    {
	    	printf("\nEl salario total es de : $%.2f", total);
	    	printf("\nEl salario promedio es de : $%.2f", avarage);
	    	if(quantity != 0){

				printf("\nEl numero de empleados que superan el promedio de salario : %d", quantity);
	    	}
	    	else{
	    		printf("\nNo hay empleados que superen el promedio de sueldo. Todos los sueldos son iguales");
	    	}
	    	exito = 1;
	    }
	}

	return exito;
}

int sortEmployees(sEmployee empleados[], sSector sectores[], int tamS, int tam)
{
	sEmployee auxiliar;
	int exito = -1;

	for(int i = 0; i < tam - 1; i++){

		for(int j = i + 1; j < tam; j++){

			if(stricmp(empleados[i].lastName, empleados[j].lastName) > 0 )
			{
				auxiliar = empleados[i];
				empleados[i] = empleados[j];
				empleados[j] = auxiliar;
				exito = 1;
			}

			if((stricmp(empleados[i].lastName, empleados[j].lastName) == 0 &&
					stricmp(sectores[i].descripcion, sectores[j].descripcion) > 0)){

				auxiliar = empleados[i];
				empleados[i] = empleados[j];
				empleados[j] = auxiliar;
				exito = 1;
			}
		}
	}
	return exito;
}

int changeEmployee(sEmployee empleados[], sSector sectores[], int tamS, int tam)
{
	int exito = -1;
	int idEmployee;
	int indice;
	int opcion;

		printEmployees(empleados, sectores, tamS, tam);
		printf("\t\n\nModificacion de Empleados\n\n");
		printf("Introduza el numero de Id del empleado: ");
		fflush(stdin);
		scanf("%d", &idEmployee);
		if(validarId(empleados, tam, idEmployee) == -1)
		{
			printf("No existe ningun empleado con ese numero de Id. Reingrese: ");
			fflush(stdin);
			scanf("%d", &idEmployee);
		}

		if(empleados != NULL && tam > 0 && sectores != NULL && tamS > 0)
		{
			indice = findEmployee(empleados, tam, idEmployee);

			if(indice == -1)
			{
				printf("\nEl Id : %d no corresponde a ningun empleado del sistema", idEmployee);
			}
			else
			{
					printf("\n1. Modificar Nombre\n");
					printf("2. Modificar Apellido\n");
					printf("3. Modificar Salario\n");
					printf("4. Modificar Sector\n\n");

					printf("Ingrese el numero de opcion correspondiente: ");
					scanf("%d", &opcion);

					switch(opcion)
					{
						case 1:
							printf("Ingrese nuevo Nombre: ");
							fflush(stdin);
							gets(empleados[indice].name);
							exito = 1;
							break;

						case 2:
							printf("Ingrese nuevo Apellido: ");
							fflush(stdin);
							gets(empleados[indice].lastName);
							exito = 1;
							break;

						case 3:
							printf("Ingrese nuevo Salario: ");
							fflush(stdin);
							scanf("%f", &empleados[indice].salary);
							while(empleados[indice].salary < 0)
							{
								printf("Salario invalido. Re ingrese nuevo Salario: ");
								fflush(stdin);
								scanf("%f", &empleados[indice].salary);
							}
							exito = 1;
							break;

						case 4:
							printSectors(sectores, tamS);
							printf("Ingrese nuevo Sector: ");
							fflush(stdin);
							scanf("%d", &empleados[indice].sector);
							while(!(empleados[indice].sector >= 500 && empleados[indice].sector <= 504))
							{
								printf("Sector invalido. Re ingrese nuevo Sector: ");
								fflush(stdin);
								scanf("%d", &empleados[indice].sector);
							}
							exito = 1;
							break;

						default:
							printf("\n\nDato Invalido. Re ingrese opcion: ");
							fflush(stdin);
							break;
					}
			}
		}
		return exito;
}

int totalSalary(sEmployee empleados[], int tam)
{
	float totalSalary = 0;

	if(empleados != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(empleados[i].isEmpty == 0)
			{
				totalSalary += empleados[i].salary;
			}
		}
	}
	return totalSalary;
}

int avarageSalary(sEmployee empleados[], int tam)
{
	float totalSalary = 0;
	float loop = 0;
	float avarage;

		if(empleados != NULL && tam > 0)
		{
			for(int i = 0; i < tam; i++)
			{
				if(empleados[i].isEmpty == 0)
				{
					totalSalary += empleados[i].salary;
					loop++;
				}
			}
		}
		avarage = (float) totalSalary / loop;

		return avarage;

}

int validarId(sEmployee empleados[], int tam, int idSearch)
{
	int exito = -1;

	if(empleados != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(empleados[i].id == idSearch && empleados[i].isEmpty == 0)
			{
				exito = 1;
			}
		}
	}
	return exito;
}
