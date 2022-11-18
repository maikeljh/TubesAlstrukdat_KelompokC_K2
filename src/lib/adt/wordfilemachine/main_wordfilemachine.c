#include "wordfilemachine.h"
#include "../tree/tree.h"
#include "../matrix/matrix.h"
#include "../sederhana/makanan/makanan.h"
#include "../sederhana/point/point.h"
#include "../../peta.c"
#include <stdio.h>
#include <stdlib.h>

// cd src/lib/adt/wordfilemachine
// gcc main_wordfilemachine.c wordfilemachine.c charfilemachine.c ../tree/tree.c ../matrix/matrix.c ../sederhana/point/point.c ../sederhana/makanan/makanan.c ../wordmachine/wordmachine.c ../wordmachine/charmachine.c ../sederhana/time/time.c -o ../../../../build/lib/adt/non_sederhana/main_wordfilemachine

int main(){
    ListMakanan KumpulanMakanan;
    Matrix peta;
    POINT S,T,M,C,F,B;
    Tree Resep;

    char fileMakanan[100] = "../../../../config/makanan.txt";
    char fileResep[100] = "../../../../config/resep.txt";
    char path[50] = "../../../../config/testPeta.txt";

    printf("\n/* Membaca Konfigurasi File Makanan */\n");
    KumpulanMakanan = BacaMakanan(fileMakanan);
    TulisListMakanan(KumpulanMakanan, JumlahMakanan(KumpulanMakanan));
    printf("\n");

    printf("\n/* Membaca Konfigurasi File Resep */\n");
    Resep = BacaResep(fileResep);
    PrintTree(Resep);
    printf("\n");

    printf("\n/* Membaca Konfigurasi File Peta */\n");
    bacaPeta(path,&peta, &S, &T, &M, &C, &F, &B);
    displayPeta(peta, S);
    printf("\n");

    int iptklr;
    printf("\nKetik 0 untuk keluar. "); 
    scanf("%d", &iptklr);
}