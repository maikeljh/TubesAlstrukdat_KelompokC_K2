#include "kulkas.h"

// gcc main_kulkas.c kulkas.c ../matrix/matrix.c ../sederhana/simulator/simulator.c ../sederhana/time/time.c ../wordmachine/wordmachine.c ../wordmachine/charmachine.c ../notifikasi/notifikasi.c ../sederhana/point/point.c ../prioqueue/prioqueuetime.c -o ../../../../build/lib/adt/non_sederhana/main_kulkas

int main(){
    // KAMUS GLOBAL
    Kulkas K;

    // INISIASI CREATE KULKAS
    createKulkas(&K);
    
    // INISIASI WAKTU DAN NAMA
    Word Nama;
    Nama.TabWord[0] = 'T';
    Nama.Length = 1;
    TIME WK;
    CreateTime(&WK, 1, 2, 3);

    // INISIASI MAKANAN
    Makanan M, Temp, Cek;
    Nama(Temp) = Nama;
    Kedaluwarsa(Temp) = WK;
    ID(M) = 1;
    Lebar(M) = 2;
    Panjang(M) = 3;
    Nama(Temp) = Nama;
    Kedaluwarsa(Temp) = WK;
    ID(Temp) = 2;
    Lebar(Temp) = 1;
    Panjang(Temp) = 4;

    // OPERASI INSERT KULKAS
    printf("\n/* MELAKUKAN OPERASI INSERT KULKAS */\n");
    insertKulkas(&K, M, 1, 4);
    insertKulkas(&K, Temp, 3, 4);

    // OPERASI DISPLAY KULKAS
    displayKulkas(K);

    // VALIDASI INSERT KULKAS
    printf("\n/* MELAKUKAN VALIDASI INSERT KULKAS */\n");
    printf("\n/* JIKA MAKANAN DIINSERT DI TEMPAT YANG SUDAH ADA MAKANAN */\n");
    insertKulkas(&K, Temp, 2, 1);
    insertKulkas(&K, M, 2, 2);

    // OPERASI DELETE KULKAS
    printf("\n/* MELAKUKAN OPERASI DELETE KULKAS */\n");
    deleteKulkas(&K, 0, &Cek);

    // Melakukan Operasi Kulkas
    Simulator S;
    POINT P;
    CreateSimulator(&S, Nama, P, WK);
    Nama(M) = Nama;
    Kedaluwarsa(M) = WK;
    Enqueue(&Inventory(S), M);

    printf("\n/* MELAKUKAN OPERASI KULKAS */\n");
    ProsesKulkas(&K, &S);
    int iptklr;
    printf("\nKetik 0 untuk keluar."); 
    scanf("%d", &iptklr);
}