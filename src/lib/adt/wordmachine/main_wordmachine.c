#include "wordmachine.h"
#include <stdio.h>
#include <stdlib.h>

// Compiler command: gcc main_wordmachine.c wordmachine.c charmachine.c -o main
/* void menuWordmachine(void){
    printf("*** Berikut menu untuk menguji coba fungsi: ***\n");
    printf("0. KELUAR\n");
    printf("1. STARTWORD()\n");
    printf("2. ADVWORD()\n");
} */
int main(){
    printf(" ** STARTWORD() mulai. Silahkan masukan input kalimat atau kata untuk dibaca pita. **\n");
    printf("Kalimat yang akan dibaca pita: ");
    STARTWORD();
    printf("STARTWORD() selesai. berikut data setelah STARTWORD(): \n");
    printf("currentWord yang telah diakuisisi : "); PrintWord(currentWord); printf("\n");
    printf("ADVWORD() sekarang dilakukan untuk mengakuisisi kata selanjutnya.\n");
    while (currentChar != MARK){
        ADVWORD();
        printf("currentWord yang telah diakuisisi : "); PrintWord(currentWord); printf("\n");
    }
    printf("Seluruh kata dalam pita telah diakuisisi.");
    printf(" ** Fungsi LowerCase() digunakan untuk mengubah isi kalimat yang menggunakan huruf kapital menjadi huruf kecil.");
    printf("Silahkan masukan input kalimat yang akan difilter dengan LowerCase(): \n");
    if (currentChar == '\n'){
        printf("currentChar udah sampe end");
    }
    STARTWORD();
}

/*STARTWORD();
    printf("currentWord: ");PrintWord(currentWord);
    int pilihan;
    menuWordmachine();
    printf("Silahkan pilih 0-2: ");
    scanf("%d", &pilihan);
    if (pilihan == 1){
        STARTWORD();
        printf("** Uji coba STARTWORD() dimulai dengan input. **\n");
        printf("** Silahkan input sebuah kalimat atau kata: \n");
        printf("currentWord: ");PrintWord(currentWord);
        STARTWORD();
    }
    if (pilihan == 2){
        printf(" ** ADVWORD() digunakan untuk mengakuisisi kata selanjutnya  dalam pita dari yang sudah diakuisisi.");
        printf("Isi kata sebelum ADVWORD(): ");
        PrintWord(currentWord);
        printf("\n");
        ADVWORD();
        printf("Isi kata setelah ADVWORD(): ");
        PrintWord(currentWord);
        printf("\n");
    }
    STARTWORD();*/