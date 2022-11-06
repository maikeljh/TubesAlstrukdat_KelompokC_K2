/* File: simulatort.h */
/* *** Definisi ABSTRACT DATA TYPE SIMULATOR *** */

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "../../boolean.h"
#include "../point/point.c"
#include "../../prioqueue/prioqueuetime.c"
#include "../../matrix/matrix.h"
#include "../../notifikasi/notifikasi.h"
#include "../time/time.h"

typedef struct { 
    PrioQueueTime Inventory;
    ListNotif Notif;
    PrioQueueTime Delivery;
    TIME Waktu;
	Word Nama;
    POINT Lokasi;
} Simulator;

/* *** Notasi Akses: Selektor SIMULATOR *** */
#define Inventory(S) (S).Inventory
#define NamaSimulator(S) (S).Nama
#define LokasiSimulator(S) (S).Lokasi
#define WaktuSimulator(S) (S).Waktu
#define DeliverySimulator(S) (S).Delivery
#define NotifSimulator(S) (S).Notif

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk SIMULATOR *** */
void CreateSimulator (Simulator * S, Word Nama, POINT P, TIME Waktu);
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