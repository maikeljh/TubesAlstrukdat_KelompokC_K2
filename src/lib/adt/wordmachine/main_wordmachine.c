#include "wordmachine.h"
#include <stdio.h>
#include <stdlib.h>
// cd src/lib/adt/wordmachine
// gcc main_wordmachine.c wordmachine.c charmachine.c -o main_wordmachine

<<<<<<< HEAD
=======
// gcc main_wordmachine.c wordmachine.c charmachine.c -o main_wordmachine

>>>>>>> 1fa1daa48e965329f5f6bec65f1e7c113ada20ef
int main(){
    printf("\n ** STARTWORD() mulai. Silahkan masukan input kalimat atau kata untuk dibaca pita. **\n");
    printf("\nKalimat yang akan dibaca pita: ");

    STARTWORD();

    printf("\nSTARTWORD() selesai.\n\nBerikut data setelah STARTWORD():\n");
    if(currentChar == '\n'){
        printf("currentWord yang telah diakuisisi : "); PrintWord(currentWord); printf("\n\n");
    } else {
        while (currentChar != '\n'){
            printf("currentWord yang telah diakuisisi : "); PrintWord(currentWord); printf("\n\n");
            ADVWORD();
            printf("ADVWORD() sekarang dilakukan untuk mengakuisisi kata selanjutnya.\n\n");
        }
    }
    printf("Seluruh kata dalam pita telah diakuisisi.\n");

    printf("\n ** Fungsi LowerCase() digunakan untuk mengubah isi kalimat yang menggunakan huruf kapital menjadi huruf kecil.\n");
    printf("\nSilahkan masukan input satu kata yang akan difilter dengan LowerCase(): ");
    STARTWORD();
    if(currentWord.Length != 0){
        LowerCase();
        printf("\nHasil dari lowercase terhadap kata tersebut = ");
        PrintWord(currentWord);
    }
    int iptklr;
    printf("\nKetik 0 untuk keluar. "); 
    scanf("%d", &iptklr);
}