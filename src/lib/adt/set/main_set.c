#include "set.h"
#include <stdio.h>

// cd src/lib/adt/set
// gcc main_set.c set.c ../sederhana/makanan/makanan.c ../wordfilemachine/wordfilemachine.c ../wordfilemachine/charfilemachine.c ../wordmachine/wordmachine.c ../wordmachine/charmachine.c ../sederhana/time/time.c ../tree/tree.c ../sederhana/simulator/simulator.c ../notifikasi/notifikasi.c ../sederhana/point/point.c ../prioqueue/prioqueuetime.c -o ../../../../build/lib/adt/non_sederhana/main_set

int main(){
    Set SetMakanan, SetMakanan2;

    // INISIASI LIST MAKANAN M
	ListMakanan M;
    Tree Resep;

	// INISIASI PATH KONFIGURASI FILE MAKANAN
	char fileName[100] = "config/makanan.txt";
    char fileResep[100] = "config/resep.txt";

	// MELAKUKAN MEMBACA MAKANAN
    printf("/* Melakukan Proses BacaMakanan dan BacaResep */\n");
	M = BacaMakanan(fileName);
    Resep = BacaResep(fileResep);
    printf("\n");

    // MELAKUKAN CREATE SET
    printf("/* Melakukan Proses createSet */\n");
    createSet(&SetMakanan, M);
    createSet(&SetMakanan2, M);
    printf("\n");

    // MELAKUKAN ADD SET
    printf("/* Melakukan Proses addSet */\n");
    addSet(&SetMakanan, Makanan(M, 0));
    addSet(&SetMakanan, Makanan(M, 1));
    addSet(&SetMakanan, Makanan(M, 2));

    addSet(&SetMakanan2, Makanan(M, 0));
    addSet(&SetMakanan2, Makanan(M, 1));
    printf("\n");

    // MEMERIKSA APAKAH SUBSET ATAU TIDAK
    printf("/* Melakukan Proses isSubset */\n");
    if(isSubset(SetMakanan2, SetMakanan)){
        printf("S1 SUBSET S2\n");
    }
    printf("\n");

    // MEMBUAT LIST RESEP DAN LIST REKOMENDASI
    printf("/* Melakukan Proses BacaRekomendasi */\n");
    ListMakanan ListResep = ListResepAll(M, Resep);
    ListSet ListRekomendasi = BacaRekomendasi(Resep, M, ListResep);
    printf("\n");

    // MEMBUAT SIMULATOR
    Simulator S;
    Word Name = CreateWord("NAMA", 4);
    POINT P;
    CreatePoint(&P, 1, 2);
    TIME W;
    CreateTime(&W, 1, 1, 1);
    CreateSimulator(&S, Name, P, W);

    // MELAKUKAN ENQUEUE MAKANAN KE INVENTORY
    Enqueue(&Inventory(S), M.M[0]);
    Enqueue(&Inventory(S), M.M[1]);

    // MENULISKAN REKOMENDASI
    printf("/* Melakukan Proses TulisRekomendasi */\n");
    TulisRekomandasi(M, ListRekomendasi, S);
    printf("\n");
    int keluars;
    printf("\nKetik 0 untuk keluar\n"); scanf("%d", &keluars);
}