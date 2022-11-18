/* File: main_liststatik.c */
/* Driver ADT List Statik */

#include "liststatik.h"
#include <stdio.h>
// cd src/lib/adt/liststatik
// gcc main_liststatik.c liststatik.c ../wordmachine/wordmachine.c ../wordmachine/charmachine.c ../sederhana/time/time.c ../sederhana/makanan/makanan.c ../wordfilemachine/wordfilemachine.c ../wordfilemachine/charfilemachine.c -o ../../../../build/lib/adt/non_sederhana/main_liststatik

int main(){
    // Create List Statik
    ListStatik L;
    CreateListStatik(&L);

    // Print List Statik
    printf("List Statik yang terbentuk : ");
    printList(L);
    printf("\n");

    // Jumlah Elemen List Statik
    printf("\nJumlah Elemen : %d\n", Length(L));
    printf("\n");

    // First Indeks List Statik
    printf("First Index : %d\n", getFirstIdx(L));
    printf("\n");

    // Last Indeks List Statik
    printf("Last Index : %d\n", getLastIdx(L));
    printf("\n");

    // Cek indeks valid atau tidak
    int indeks;
    printf("Masukkan indeks yang ingin diperiksa : ");
    scanf("%d", &indeks);
    if(isIdxValid(L, indeks)){
        printf("Indeks valid!\n");
    } else {
        printf("Indeks tidak valid!\n");
    }
    printf("\n");

    // Cek indeks valid atau tidak
    if(isIdxValid(L, indeks)){
        printf("Indeks terdefinisi!\n");
    } else {
        printf("Indeks tidak terdefinisi!\n");
    }
    printf("\n");

    // Cek List Statik Empty atau tidak
    if(isEmpty(L)){
        printf("List kosong\n");
    } else {
        printf("List tidak kosong!\n");
    }
    printf("\n");

    // Cek List Statik Full atau tidak
    if(isFull(L)){
        printf("List penuh\n");
    } else {
        printf("List tidak penuh!\n");
    }
    printf("\n");

    // Melakukan insertFirst pada List Statik
    Makanan Food;
    TIME WK, LP, PO;
    Word yummy = CreateWord("Yummy", 5);
	CreateTime(&WK, 1, 0, 0);
	CreateTime(&LP, 2, 10, 0);
	CreateTime(&PO, 0, 20, 0);
	CreateMakanan(&Food, 1, 3, yummy, WK, LP, PO, 2, 3);
    printf("Insert pada awal List Statik : \n");
    insertFirst(&L, Food);
    printList(L);

    // Cek Indeks Of
    indeks = indexOf(L, Food);
    printf("Indeks elemen tersebut : ");
    printf("%d\n", indeks);
    printf("\n");

    // Melakukan insertAt pada List Statik
    printf("Insert 1 pada indeks 1 List Statik : \n");
    insertAt(&L, Food, 1);
    printList(L);
    printf("\n");

    printf("\n");
    // Melakukan insertLast pada List Statik
    printf("Insert 2 pada akhir List Statik : \n");
    insertLast(&L, Food);
    printList(L);
    printf("\n");

    printf("\n");
    // Melakukan deleteFirst pada List Statik
    printf("Delete elemen awal List Statik : \n");
    deleteFirst(&L, &Food);
    printList(L);
    printf("\n");

    printf("\n");
    // Melakukan deleteAt pada List Statik
    printf("Delete elemen indeks ke-1 List Statik : \n");
    deleteAt(&L, &Food, 1);
    printList(L);
    printf("\n");

    printf("\n");
    // Melakukan deleteLast pada List Statik
    printf("Delete elemen akhir List Statik : \n");
    deleteLast(&L, &Food);
    printList(L);
    printf("\n");
    printf("\n");
    int iptklr;
    printf("\nKetik 0 untuk keluar."); 
    scanf("%d", &iptklr);
}