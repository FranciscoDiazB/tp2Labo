/*
 ============================================================================
 Name        : main.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "sector.h"

#define SIZE 1000
#define SIZESEC 5

int menu();

int main(void) {

	setbuf(stdout, NULL);

	sEmployee arrayEmpleados[SIZE];
	sSector arraySectors[SIZESEC] =
	{
		{500, "Sistemas"},
		{501, "Legales"},
		{502, "RRHH"},
		{503, "Contables"},
		{504, "Ventas"}
	};
	initEmployees(arrayEmpleados, SIZE);
	int idNext = 5000;
	char salir = 'n';
	int flag = 0;

	do{
		switch(menu()){

			case 1:
				if(addEmployes(arrayEmpleados, SIZE, arraySectors, SIZESEC, &idNext) == 1)
				{
					printf("\nAlta del empleado exitosa!!");
					flag = 1;
				}
				else{
					printf("\nHubo un problema en la carga del empleado");
				}
				printf("\n\n");
				system("pause");
				break;

			case 2:
				if(flag == 1)
				{
					if(changeEmployee(arrayEmpleados, arraySectors, SIZESEC, SIZE) == 1)
					{
						printf("\nModificacion exitosa!!");
					}
					else
					{
						printf("\nHubo un problema en la modificacion");
					}
				}
				else
				{
					printf("\nSe debe ingresar un empleado antes de poder modificarlos");
				}
				printf("\n\n");
				system("pause");
				break;


			case 3:
				if(flag == 1)
				{
					if(!removeEmployee(arrayEmpleados, arraySectors, SIZESEC, SIZE))
					{
						printf("\nHubo un problema en la baja del empleado");
					}
				}
				else
				{
					printf("\nSe debe ingresar un empleado antes de poder darlos de baja");
				}
				printf("\n\n");
				system("pause");
				break;

			case 4:
				if(flag == 1)
				{
					if(!printEmployees(arrayEmpleados, arraySectors, SIZESEC, SIZE))
					{
						printf("\nHubo un problema para mostrar a los empleados");
					}
				}
				else
				{
					printf("\nSe debe ingresar un empleado antes de poder Mostrarlos");
				}
				printf("\n\n");
				system("pause");
				break;

			case 5:
				printf("Esta seguro que desea salir? Omprima 's'. De lo contrario oprima 'n'\n");
				fflush(stdin);
				scanf("%c", &salir);
				break;

			default:
				printf("Dato invalido");
				fflush(stdin);
				printf("\n\n");
				system("pause");
				break;

		}
	}while( salir == 'n');

    return EXIT_SUCCESS;
}

int menu(){

	int opcion;

	printf("\n\t\t\t*** MENU ***\n\n");
	printf("1. ALTAS\n");
	printf("2. MODIFICAR\n");
	printf("3. BAJA\n");
	printf("4. INFORMAR\n");
	printf("5. SALIR\n\n");

	printf("Ingrese el numero de opcion correspondiente: ");
	scanf("%d", &opcion);

	return opcion;



}
