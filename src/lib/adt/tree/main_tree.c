#include "tree.h"
#include <stdio.h>

// gcc main_tree.c tree.c ../sederhana/makanan/makanan.c ../wordfilemachine/wordfilemachine.c ../wordfilemachine/charfilemachine.c ../sederhana/time/time.c ../wordmachine/wordmachine.c ../wordmachine/charmachine.c -o main_tree

int main(){
    // Melakukan alokasi Node
    addrNode P1,P2,P3,P4,P5;
    P1 = AlokNode(11);
    P2 = AlokNode(21);
    P3 = AlokNode(10);
    P4 = AlokNode(31);
    P5 = AlokNode(15);

    // Melakukan Alokasi Tree
    Tree T1, T2, T3;
    MakeTree(21,0, NULL, &T1);
    MakeTree(31,0,NULL, &T2);
    MakeTree(37,0,NULL, &T3);

    // Memeriksa apakah tree kosong atau tidak
    if(IsTreeEmpty(T1)){
        printf("Tree 1 Kosong\n");
    } else {
        printf("Tree 1 tidak kosong\n");
    }

    // Melakukan penambahan daun sesuai dengan akar
    AddDaunByID(&T1, 21, 11);
    AddDaunByID(&T2, 31, 21);
    AddDaunByID(&T3, 37, 31);
    AddDaunByID(&T3, 37, 15);

    // Melakukan Pencetakan Tree
    printf("Tree 1 berisi ");
    PrintTree(T1);
    printf("\n");
    printf("Tree 2 berisi ");
    PrintTree(T2);
    printf("\n");
    printf("Tree 3 berisi ");
    PrintTree(T3);
    printf("\n");

    // Melakukan Merge Resep
    Tree T[3];
    T[0] = T1;
    T[1] = T2;
    T[2] = T3;
    Tree Resep = mergeResep(T, 3);
    printf("Tree Resep Dari Makanan Tersebut adalah ");
    PrintTree(Resep);
    printf("\n");
    
    // Melakukan membaca tree resep dari konfigurasi
	char fileName[100] = "../../../../config/resep.txt";
    Tree Main = BacaResep(fileName);
    printf("Tree Resep Dari Konfigurasi Resep adalah ");
    PrintTree(Main);
    printf("\n");
    int iptkeluar;
    printf("Ketik 0 untuk keluar.\n"); scanf("%d", &iptkeluar);
}