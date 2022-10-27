#include "prioqueuetime.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    /* KAMUS UTAMA */
    printf("Nama makanan 1: \n");
    STARTWORD();
    PrioQueueTime inventory;
    Makanan M1, M2;
    int id, lokasi;
    TIME wk, lp;
   // Word name;
    // Sampel data makanan (Data Bebek):
    id = 1; lokasi = 1; 
    CreateTime(&wk, 3, 2, 30);
    CreateTime(&lp, 0, 15, 0);
    CreateMakanan(&M1, id, lokasi, currentWord, wk, lp);
    //

    // Data Sapi:
    printf("Nama makanan 2: \n");
    STARTWORD();
    id = 2; lokasi = 2;
    CreateTime(&wk, 0, 1, 10);
    CreateTime(&lp, 0, 10, 0);
    CreateMakanan(&M2, id, lokasi, currentWord, wk, lp);
    //

    /* ALGORITMA UTAMA */
    // printf("Silahkan pilih \n");

    // 1. MakeEmpty
    MakeEmpty(&inventory, NMax);
    
    // 2. Enqueue makanan (Makanan terdefinisi)
    Enqueue(&inventory, M1);
    Enqueue(&inventory, M2);

    // 3. Print Isi Prio Queue
    PrintPrioQueueTime(inventory);
}