#include "kulkas.h"

int main(){
    // KAMUS GLOBAL
    Kulkas K;

    // INISIASI CREATE KULKAS
    createKulkas(&K);

    // INISIASI MAKANAN
    Makanan M, Temp, Cek;
    ID(M) = 1;
    Lebar(M) = 2;
    Panjang(M) = 3;
    ID(Temp) = 2;
    Lebar(Temp) = 1;
    Panjang(Temp) = 4;

    // OPERASI INSERT KULKAS
    printf("\nMELAKUKAN OPERASI INSERT KULKAS\n");
    insertKulkas(&K, M, 1, 4);
    insertKulkas(&K, Temp, 3, 4);


    // OPERASI DISPLAY KULKAS
    displayKulkas(K);

    // VALIDASI INSERT KULKAS
    insertKulkas(&K, Temp, 2, 1);
    insertKulkas(&K, M, 2, 2);

    // OPERASI DELETE KULKAS
    printf("\nMELAKUKAN OPERASI DELETE KULKAS\n");
    deleteKulkas(&K, 1, &Cek);
    displayKulkas(K);
}