/*
 * sector.h
 *
 *  Created on: 16 oct. 2021
 *      Author: Asus
 */

#ifndef SECTOR_H_
#define SECTOR_H_

typedef struct
{
    int id;
    char descripcion[20];

}sSector;

int printSectors(sSector sectores[], int tamS);

int descriptionSector(int id, sSector sectores[], int tam, char descr[]);

#endif /* SECTOR_H_ */
