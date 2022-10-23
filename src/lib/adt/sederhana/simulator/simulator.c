/* File: simulator.h */
/* *** Definisi ABSTRACT DATA TYPE SIMULATOR *** */

#include "simulator.h"
#include <stdio.h>

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk SIMULATOR *** */
void CreateSimulator (Simulator * S, char Nama[], int x, int y){
    /* Membentuk sebuah Simulator dari komponen-komponennya */
    POINT P;
    PrioQueueTime Q;
    CreatePoint(&P, x , y);
    MakeEmpty(&Q, NMax);
    for(int i = 0; i < NMax; i++){
        Nama(*S)[i] = Nama[i];
    }
    Lokasi(*S) = P;
    Inventory(*S) = Q;
};


/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */  
                                               
void TulisSimulator(Simulator S){
    /* Simulator ditulis ke layar dengan format "Nama di posisi: Lokasi" */
    /* I.S. S terdefinisi */
    /* F.S. S tertulis di layar dengan format "Nama di posisi: Lokasi" */  
    printf("%s di posisi: ", Nama(S));
    TulisPOINT(Lokasi(S));
    printf("\n");
};
       
/* *** KELOMPOK OPERASI TERHADAP TYPE *** */                           
void UbahLokasiSimulator(Simulator * S, int deltaX, int deltaY){
    /* Lokasi Simulator digeser sesuai deltaX dan deltaY */
    /* I.S. S terdefinisi */
    /* F.S. Lokasi S digeser sesuai deltaX dan deltaY  */ 
    Geser(&Lokasi(*S), deltaX, deltaY);
}