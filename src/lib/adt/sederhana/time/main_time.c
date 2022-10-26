/* File: main_time.c */
/* Driver ADT TIME */

#include <stdio.h>
#include "time.h"

/********** Definisi Fungsi **********/
void printHeading(char msg[]);
/* Mencetak heading */
void printMenu(void);
/* Mencetak menu */
void getHMS(int *H, int *M, int *S);
/* Membaca jam, menit, dan detik */
void getT1(TIME *T1);
/* Membaca T1 */
void getT1T2(TIME *T1, TIME *T2);
/* Membaca T1 dan T2 */
void printTrueMsg(char msg[]);
/* Mencetak pesan true */
void printFalseMsg(char msg[]);
/* Mencetak pesan false */

/********** Program Utama **********/
int main(void)
{
    /* KAMUS */
    TIME T1, T2;
    int pilihan, H, M, S, N;

    /* ALGORITMA */
    printMenu();
    do {
        printf("^_^ Silakan pilih fungsi/prosedur yang ingin diuji (0--15): "); scanf("%d", &pilihan);
        if (pilihan != 0)
            printf("...\n");
        if (pilihan == 1) {
            printHeading("1. IsTIMEValid(H, M, S)");
            getHMS(&H, &M, &S);
            printf("IsTIMEValid(%d, %d, %d)? ", H, M, S);
            if (IsTIMEValid(H,M,S))
                printTrueMsg("TIME valid");
            else
                printFalseMsg("TIME tidak valid");
        }
        else if (pilihan == 2) {
            printHeading("2. CreateTime(*T1, H, M, S)");
            getHMS(&H, &M, &S);
            if (IsTIMEValid(H,M,S)) {
                printf("CreateTime(&T1, %d, %d, %d)\n", H, M, S);
                CreateTime(&T1, H, M, S);
                printf("T1 = "); TulisTIME(T1); printf("\n");
            }
            else
                printFalseMsg("TIME tidak valid");
        }
        else if (pilihan == 3) {
            printHeading("3. BacaTIME(*T1)");
            getT1(&T1);
            printf("T1 = "); TulisTIME(T1); printf("\n");
        }
        else if (pilihan == 4) {
            printHeading("4. TulisTIME(T1)");
            getT1(&T1);
            printf("T1 = "); TulisTIME(T1); printf("\n");
        }
        else if (pilihan == 5) {
            printHeading("5. TIMEToDetik(T1)");
            getT1(&T1);
            printf("T1 dalam detik = 3600 * %i + 60 * %i + %i = %li\n", Hour(T1), Minute(T1), Second(T1), TIMEToDetik(T1));
        }
        else if (pilihan == 6) {
            printHeading("6. DetikToTIME(N)");
            printf("Masukkan detik N yang ingin diubah ke TIME: \n");scanf("%d", &N);
            printf("Detik %i dalam TIME = ", N); TulisTIME(DetikToTIME(N)); printf("\n");
        }
        else if (pilihan == 7) {
            printHeading("7. TEQ(T1, T2)");
            getT1T2(&T1, &T2);
            printf("TEQ(T1, T2)? ");
            if (TEQ(T1, T2))
                printTrueMsg("T1 sama dengan T2");
            else
                printFalseMsg("T1 tidak sama dengan T2");
        }
        else if (pilihan == 8) {
            printHeading("8. TNEQ(T1, T2)");
            getT1T2(&T1, &T2);
            printf("TNEQ(T1, T2)? ");
            if (TNEQ(T1, T2))
                printTrueMsg("T1 tidak sama dengan T2");
            else
                printFalseMsg("T1 sama dengan T2");
        }
        else if (pilihan == 9) {
            printHeading("9. TLT(T1, T2)");
            getT1T2(&T1, &T2);
            printf("TLT(T1, T2)? ");
            if (TLT(T1, T2))
                printTrueMsg("T1 lebih kecil daripada T2");
            else
                printFalseMsg("T1 tidak lebih kecil daripada T2");
        }
        else if (pilihan == 10) {
            printHeading("10. TGT(T1, T2)");
            getT1T2(&T1, &T2);
            printf("TGT(T1, T2)? ");
            if (TGT(T1, T2))
                printTrueMsg("T1 lebih besar daripada T2");
            else
                printFalseMsg("T1 tidak lebih besar daripada T2");
        }
        else if (pilihan == 11) {
            printHeading("11. NextDetik(T1)");
            getT1(&T1);
            printf("NextDetik(T1) = "); TulisTIME(NextDetik(T1)); printf("\n");
        }
        else if (pilihan == 12) {
            printHeading("12. NextNDetik(T1, N)");
            getT1(&T1);
            printf("Masukkan N detik yang ingin ditambahkan ke T1: \n");scanf("%d", &N);
            printf("NextNDetik(T1, %i) = ", N); TulisTIME(NextNDetik(T1, N)); printf("\n");
        }
        else if (pilihan == 13) {
            printHeading("13. PrevDetik(T1)");
            getT1(&T1);
            printf("PrevDetik(T1) = "); TulisTIME(PrevDetik(T1)); printf("\n");
        }
        else if (pilihan == 14) {
            printHeading("14. PrevNDetik(T1, N)");
            getT1(&T1);
            printf("Masukkan N detik yang ingin dikurangi dari T1: \n");scanf("%d", &N);
            printf("PrevNDetik(T1, %i) = ", N); TulisTIME(PrevNDetik(T1, N)); printf("\n");
        }
        else if (pilihan == 15) {
            printHeading("15. Durasi(T1, T2)");
            getT1T2(&T1, &T2);
            printf("Durasi(T1, T2) = %li\n", Durasi(T1, T2));
        }
    } while (pilihan != 0);
}

/********** Implementasi Fungsi **********/
void printHeading(char msg[])
/* Mencetak heading */
{
    /* KAMUS LOKAL */

    /* ALGORITMA */
    printf("---------------[%s]---------------\n", msg);
}

void printMenu(void)
/* Mencetak menu */
{
    /* KAMUS LOKAL */

    /* ALGORITMA */
    printHeading("MENU");
    printf(" 0. Keluar\n");
    printf(" 1. isTIMEValid(H, M, S)\n");
    printf(" 2. CreateTime(*T, HH, MM, SS)\n");
    printf(" 3. BacaTIME(*T)\n");
    printf(" 4. TulisTIME(T)\n");
    printf(" 5. TIMEToDetik(T)\n");
    printf(" 6. DetikToTIME(N)\n");
    printf(" 7. TEQ(T1, T2)\n");
    printf(" 8. TNEQ(T1, T2)\n");
    printf(" 9. TLT(T1, T2)\n");
    printf("10. TGT(T1, T2)\n");
    printf("11. NextDetik(T)\n");
    printf("12. NextNDetik(T, N)\n");
    printf("13. PrevDetik(T)\n");
    printf("14. PrevNDetik(T, N)\n");
    printf("15. Durasi(T1, T2)\n");
}

void getHMS(int *H, int *M, int *S)
/* Membaca H, M, dan S */
{
    /* KAMUS LOKAL */

    /* ALGORITMA */
    printf("Masukkan H: ");scanf("%d", H);
    printf("Masukkan M: ");scanf("%d", M);
    printf("Masukkan S: ");scanf("%d", S);
}

void getT1(TIME *T1)
/* Membaca T1 */
{
    /* KAMUS LOKAL */

    /* ALGORITMA */
    printf("Masukkan TIME T1 yang ingin dibaca.\n");
    printf("Contoh: 20 12 4\n");
    BacaTIME(T1);
}

void getT1T2(TIME *T1, TIME *T2)
/* Membaca T1 dan T2 */
{
    /* KAMUS LOKAL */

    /* ALGORITMA */
    printf("Masukkan TIME T1 yang ingin dibaca.\n");
    printf("Contoh: 20 12 4\n");
    BacaTIME(T1);
    printf("Masukkan TIME T2 yang ingin dibaca.\n");
    printf("Contoh: 20 12 4\n");
    BacaTIME(T2);
}

void printTrueMsg(char msg[])
/* Mencetak pesan true */
{
    /* KAMUS LOKAL */

    /* ALGORITMA */
    printf("Ya, %s. ^_^\n", msg);
}

void printFalseMsg(char msg[])
/* Mencetak pesan false */
{
    /* KAMUS LOKAL */

    /* ALGORITMA */
    printf("Tidak, %s. >_<\n", msg);
}