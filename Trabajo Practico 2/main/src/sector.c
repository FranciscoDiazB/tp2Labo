/*
 * sector.c
 *
 *  Created on: 16 oct. 2021
 *      Author: Asus
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sector.h"

int printSectors(sSector sectores[], int tamS){

	int exito = -1;
    printf("\n\t\tSectores\n\n");
    printf("\tID del Sector\t\tDescripcion del Sector\n");
    printf("\t--------------------------------------------------\n\n");

    for(int i = 0; i < tamS; i++){

       printf("\t%d\t\t\t%-10s\n", sectores[i].id, sectores[i].descripcion);
       exito = 1;
    }
    printf("\n\n");
    return exito;
}

int descriptionSector(int id, sSector sectores[], int tam, char descr[]){

    int exito = 0;

    if(sectores != NULL && tam > 0 && descr != NULL && id >= 500 && id <= 504){

        for(int i = 0; i < tam; i++){
            if(sectores[i].id == id){
                strcpy(descr, sectores[i].descripcion);
                exito = 1;
                break;
            }
        }
    }

    return exito;
}
