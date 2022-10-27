#include "prioqueuetime.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    /* KAMUS UTAMA */
    PrioQueueTime inventory;
    Makanan M;
    int id, lokasi;
    TIME wk, lp;
    char name[100];
    // Sampel data makanan:
    id = 1; lokasi = 1; 
    name[0] = 'A'; nama[1] = 'y'; nama[2] = 'a'; nama[3] = 'm';
    CreateTime(&wk, 3, 2, 30);
    CreateTime(&lp, 0, 15, 0);
    CreateMakanan(&M, id, lokasi, name, wk, lp);
    //

    /* ALGORITMA UTAMA */
    // printf("Silahkan pilih \n");

    // 1. MakeEmpty
    MakeEmpty(&inventory);
    
    // 2. Enqueue makanan (Makanan terdefinisi)
    Enqueue(&inventory, M);
}