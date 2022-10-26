/* File: main_liststatik.c */
/* Driver ADT List Statik */

#include "liststatik.c"

int main(){
    // Create List Statik
    ListStatik L;
    CreateListStatik(&L);

    // Read List Statik
    readList(&L);

    printf("\n");
    // Print List Statik
    printf("List Statik yang terbentuk : ");
    printList(L);

    printf("\n");
    // Jumlah Elemen List Statik
    printf("\nJumlah Elemen : %d\n", listLength(L));

    printf("\n");
    // First Indeks List Statik
    printf("First Index : %d\n", getFirstIdx(L));

    printf("\n");
    // Last Indeks List Statik
    printf("First Index : %d\n", getLastIdx(L));

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
    // Cek Plus Minus List Statik
    ListStatik L2 = L, L3;
    L3 = plusMinusList(L, L2, false);
    printf("List Statik 1 : ");
    printList(L);
    printf("\n");
    printf("List Statik 2 : ");
    printList(L2);
    printf("\n");
    printf("Hasil pengurangan List Statik : ");
    printList(L3);
    printf("\n");

    L3 = plusMinusList(L, L2, true);
    printf("Hasil penjumlahan List Statik : ");
    printList(L3);
    printf("\n");

    printf("\n");
    // Cek Is Equal List Statik
    if(isListEqual(L,L2)){
        printf("List 1 dan List 2 sama\n");
    } else {
        printf("List 1 dan List 2 tidak sama!\n");
    }

    printf("\n");
    // Cek Indeks Of
    int val;
    printf("Masukkan value yang ingin dicari indeksnya : ");
    scanf("%d", &val);
    indeks = indexOf(L, val);
    printf("Indeks elemen tersebut : ");
    printf("%d\n", indeks);

    printf("\n");
    // Mencari Max dan Min
    int maksimum, minimum;
    extremeValues(L, &maksimum, &minimum);
    printf("Nilai maksimum dari list statik : ");
    printf("%d\n", maksimum);
    printf("Nilai minimum dari list statik : ");
    printf("%d\n", minimum);

    printf("\n");
    // Melakukan insertFirst pada List Statik
    printf("Insert 1 pada awal List Statik : ");
    insertFirst(&L, 1);
    printList(L);
    printf("\n");

    printf("\n");
    // Melakukan insertAt pada List Statik
    printf("Insert 1 pada indeks 1 List Statik : ");
    insertAt(&L, 1, 1);
    printList(L);
    printf("\n");

    printf("\n");
    // Melakukan insertLast pada List Statik
    printf("Insert 2 pada akhir List Statik : ");
    insertLast(&L, 2);
    printList(L);
    printf("\n");

    printf("\n");
    // Melakukan deleteFirst pada List Statik
    printf("Delete elemen awal List Statik : ");
    deleteFirst(&L, &val);
    printList(L);
    printf("\n");

    printf("\n");
    // Melakukan deleteAt pada List Statik
    printf("Delete elemen indeks ke-1 List Statik : ");
    deleteAt(&L, &val, 1);
    printList(L);
    printf("\n");

    printf("\n");
    // Melakukan deleteLast pada List Statik
    printf("Delete elemen akhir List Statik : ");
    deleteLast(&L, &val);
    printList(L);
    printf("\n");

    printf("\n");
    // Melakukan sortList dengan terurut membesar pada List Statik
    printf("Sort List Statik Membesar : ");
    sortList(&L, true);
    printList(L);
    printf("\n");

    printf("\n");
    // Melakukan sortList dengan terurut mengecil pada List Statik
    printf("Sort List Statik Mengecil : ");
    sortList(&L, false);
    printList(L);
    printf("\n");
}