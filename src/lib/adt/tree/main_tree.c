#include "tree.h"
#include <stdio.h>

// gcc main_tree.c tree.c ../sederhana/makanan/makanan.c ../wordfilemachine/wordfilemachine.c ../wordfilemachine/charfilemachine.c ../sederhana/time/time.c ../wordmachine/wordmachine.c ../wordmachine/charmachine.c -o ../../../../build/lib/adt/non_sederhana/main_tree

int main(){
    // Melakukan alokasi Node
    printf("Melakukan Alokasi Node Untuk Contoh Resep.\n");
    addrNode P1,P2,P3,P4,P5;
    P1 = AlokNode(11);
    P2 = AlokNode(21);
    P3 = AlokNode(10);
    P4 = AlokNode(31);
    P5 = AlokNode(15);
    printf("\n");

    // Melakukan Alokasi Tree
    printf("Melakukan Alokasi Tree Untuk Contoh Resep.\n");
    Tree T1, T2, T3;
    MakeTree(21,0, NULL, &T1);
    MakeTree(31,0,NULL, &T2);
    MakeTree(37,0,NULL, &T3);
    printf("\n");

    // Memeriksa apakah tree kosong atau tidak
    printf("Memeriksa Apakah Tree yang Dibuat Gagal (Kosong) atau Tidak.\n");
    if(IsTreeEmpty(T1)){
        printf("Tree 1 Kosong\n");
    } else {
        printf("Tree 1 tidak kosong\n");
    }
    printf("\n");

    // Melakukan penambahan daun sesuai dengan akar
    printf("Melakukan Penambahan Daun Pada Pohon Resep.\n");
    AddDaunByID(&T1, 21, 11);
    AddDaunByID(&T2, 31, 21);
    AddDaunByID(&T3, 37, 31);
    AddDaunByID(&T3, 37, 15);
    printf("\n");

    // Melakukan Pencetakan Tree
    printf("Melakukan Pencetakan Tree Resep.\n");
    printf("Tree 1 berisi ");
    PrintTree(T1);
    printf("\n");
    printf("Tree 2 berisi ");
    PrintTree(T2);
    printf("\n");
    printf("Tree 3 berisi ");
    PrintTree(T3);
    printf("\n");
    printf("\n");

    // Melakukan Merge Resep
    printf("Melakukan Merge Resep yaitu Merge dari Tree Resep yang Tersedia.\n");
    Tree T[3];
    T[0] = T1;
    T[1] = T2;
    T[2] = T3;
    Tree Resep = mergeResep(T, 3);
    printf("Tree Resep Dari Makanan Tersebut adalah ");
    PrintTree(Resep);
    printf("\n");
    printf("\n");
    
    // Melakukan membaca tree resep dari konfigurasi
    printf("Melakukan Membaca Tree Resep dari Konfigurasi.\n");
	char fileName[100] = "../../../../config/resep.txt";
    Tree Main = BacaResep(fileName);
    printf("Tree Resep Dari Konfigurasi Resep adalah ");
    PrintTree(Main);
    printf("\n");
    printf("\n");
    int iptkeluar;
    printf("Ketik 0 untuk keluar.\n"); scanf("%d", &iptkeluar);
}