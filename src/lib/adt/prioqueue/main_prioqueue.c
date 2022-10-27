#include "prioqueuetime.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    /* KAMUS UTAMA */
    PrioQueueTime inventory;
    Makanan M;
    int id, lokasi;
    TIME wk, lp;
    Word name;
    // Sampel data makanan:
    id = 1; lokasi = 1; 
    STARTWORD();
    name = currentWord;
    CreateTime(&wk, 3, 2, 30);
    CreateTime(&lp, 0, 15, 0);
    CreateMakanan(&M, id, lokasi, name, wk, lp);
    //

    /* ALGORITMA UTAMA */
    // printf("Silahkan pilih \n");

    // 1. MakeEmpty
    MakeEmpty(&inventory, NMax);
    
    // 2. Enqueue makanan (Makanan terdefinisi)
    Enqueue(&inventory, M);

    // 3. Print Isi Prio Queue
    PrintPrioQueueTime(inventory);
}