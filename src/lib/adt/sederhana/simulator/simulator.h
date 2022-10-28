/* File: simulatort.h */
/* *** Definisi ABSTRACT DATA TYPE SIMULATOR *** */

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "../../boolean.h"
#include "../point/point.c"
#include "../../prioqueue/prioqueuetime.h"

typedef struct { 
	char Nama[NMax];
    POINT Lokasi;
    PrioQueueTime Inventory;
} Simulator;

/* *** Notasi Akses: Selektor SIMULATOR *** */
#define Inventory(S) (S).Inventory
        
/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk SIMULATOR *** */
void CreateSimulator (Simulator * S, char Nama[], int x, int y);
/* Membentuk sebuah Simulator dari komponen-komponennya */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */  
                                               
void TulisSimulator(Simulator S);
/* Simulator ditulis ke layar dengan format "Nama di posisi: Lokasi" */
/* I.S. S terdefinisi */
/* F.S. S tertulis di layar dengan format "Nama di posisi: Lokasi" */                


/* *** KELOMPOK OPERASI TERHADAP SIMULATOR *** */                           
void UbahLokasiSimulator(Simulator * S, int deltaX, int deltaY);
/* Lokasi Simulator digeser sesuai deltaX dan deltaY */
/* I.S. S terdefinisi */
/* F.S. Lokasi S digeser sesuai deltaX dan deltaY  */ 

#endif