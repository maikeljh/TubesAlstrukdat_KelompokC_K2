/* File: main_simulator.c */
// cd src/lib/adt/sederhana/simulator
// gcc main_simulator.c simulator.c ../../prioqueue/prioqueuetime.c ../../wordmachine/wordmachine.c ../../wordmachine/charmachine.c ../time/time.c ../point/point.c ../../notifikasi/notifikasi.c -o ../../../../../build/lib/adt/sederhana/main_simulator
#include "simulator.h"
#include <stdio.h>
int main(){
    // Deklarasi S
    Simulator S;

    // Create S
    POINT P;
    CreatePoint(&P, 0 , 0);
    Word Name;
    Name.TabWord[0] = 'M';
    Name.TabWord[1] = 'I';
    Name.TabWord[2] = 'C';
    Name.Length = 3;
    TIME W;
    CreateTime(&W, 1 , 2, 3);
    printf("Membuat Simulator Dengan Nama Michael dan Lokasi di (0,0)\n");
    CreateSimulator(&S, Name, P, W);

    // Print S
    printf("Menulis Simulator Untuk Peta\n");
    TulisSimulator(S);

    // Geser Simulator ke kanan
    printf("Simulator bergerak ke arah timur\n");
    UbahLokasiSimulator(&S, 1, 0);
    TulisSimulator(S);

    // Geser Simulator ke kiri
    printf("Simulator bergerak ke arah barat\n");
    UbahLokasiSimulator(&S, -1, 0);
    TulisSimulator(S);

    // Geser Simulator ke bawah
    printf("Simulator bergerak ke arah selatan\n");
    UbahLokasiSimulator(&S, 0, 1);
    TulisSimulator(S);

    // Geser Simulator ke atas
    printf("Simulator bergerak ke arah utara\n");
    UbahLokasiSimulator(&S, 0, -1);
    TulisSimulator(S);
    int n;
    printf("\nKetik 0 untuk exit. ");
    scanf("%d", &n); 
}
