/* File: main_simulator.c */
// gcc main_simulator.c ../../prioqueue/prioqueuetime.c ../../wordmachine/wordmachine.c ../../wordmachine/charmachine.c ../time/time.c -o main
#include "simulator.c"

int main(){
    // Deklarasi S
    Simulator S;
    
    // Create S
    printf("Membuat Simulator Dengan Nama Michael dan Lokasi di (0,0)\n");
    CreateSimulator(&S, "Michael", 0, 0);

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
}
