/* File: main_simulator.c */
#include "simulator.c"

int main(){
    // Deklarasi S
    Simulator S;
    
    // Create S
    CreateSimulator(&S, "Michael", 0, 0);

    // Print S
    TulisSimulator(S);

    // Geser Simulator ke kanan
    UbahLokasiSimulator(&S, 1, 0);
    TulisSimulator(S);

    // Geser Simulator ke kiri
    UbahLokasiSimulator(&S, -1, 0);
    TulisSimulator(S);

    // Geser Simulator ke bawah
    UbahLokasiSimulator(&S, 0, 1);
    TulisSimulator(S);

    // Geser Simulator ke atas
    UbahLokasiSimulator(&S, 0, -1);
    TulisSimulator(S);
}
