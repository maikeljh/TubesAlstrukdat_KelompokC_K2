/* File: simulator.h */
/* *** Definisi ABSTRACT DATA TYPE SIMULATOR *** */

#include "simulator.h"
#include <stdio.h>

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk SIMULATOR *** */
void CreateSimulator (Simulator * S, Word Nama, POINT P, TIME Waktu){
    /* Membentuk sebuah Simulator dari komponen-komponennya */
    PrioQueueTime Q, D;
    ListNotif N;
    MakeEmpty(&Q, NMax);
    MakeEmpty(&D, 100);
    MakeEmptyNotif(&N);
    NamaSimulator(*S) = Nama;
    LokasiSimulator(*S) = P;
    Inventory(*S) = Q;
    WaktuSimulator(*S) = Waktu;
    DeliverySimulator(*S) = D;
    NotifiSimulator(*S) = N;
};

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */  
                                               
void TulisSimulator(Simulator S){
    /* Simulator ditulis ke layar dengan format "Nama di posisi: Lokasi" */
    /* I.S. S terdefinisi */
    /* F.S. S tertulis di layar dengan format "Nama di posisi: Lokasi" */
    printf("\n");
    PrintWord(NamaSimulator(S));
    printf(" di posisi: ");
    TulisPOINT(LokasiSimulator(S));
    printf("\n");
    printf("Waktu:");
    TulisTIME(WaktuSimulator(S));
    printf("\n");
    printf("Notifikasi: ");
    TulisNotif(NotifiSimulator(S));
};
       
/* *** KELOMPOK OPERASI TERHADAP TYPE *** */                           
void UbahLokasiSimulator(Simulator * S, int deltaX, int deltaY){
    /* Lokasi Simulator digeser sesuai deltaX dan deltaY */
    /* I.S. S terdefinisi */
    /* F.S. Lokasi S digeser sesuai deltaX dan deltaY  */ 
    Geser(&LokasiSimulator(*S), deltaX, deltaY);
}