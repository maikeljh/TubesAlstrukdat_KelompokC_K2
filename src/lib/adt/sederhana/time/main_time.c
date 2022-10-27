/* Fail: main_time.c */
/* Driver ADT TIME */

#include <stdio.h>
#include "time.h"

/********** Definisi Fungsi **********/
void printHeading(char msg[]);
/* Mencetak heading */
void printMenu(void);
/* Mencetak menu */
void getDHM(int *D, int *H, int *M);
/* Membaca hari, jam, dan menit */
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
    int pilihan, D, H, M, N;

    /* ALGORITMA */
    printMenu();
    do {
        printf("^_^ Silakan pilih fungsi/prosedur yang ingin diuji (0--15): "); scanf("%d", &pilihan);
        if (pilihan != 0)
            printf("...\n");
        if (pilihan == 1) {
            printHeading("1. IsTIMEValid(D, H, M)");
            getDHM(&D, &H, &M);
            printf("IsTIMEValid(%d, %d, %d)? ", D, H, M);
            if (IsTIMEValid(D,H,M))
                printTrueMsg("TIME valid");
            else
                printFalseMsg("TIME tidak valid");
        }
        else if (pilihan == 2) {
            printHeading("2. CreateTime(*T1, D, H, M)");
            getDHM(&D, &H, &M);
            if (IsTIMEValid(D,H,M)) {
                printf("CreateTime(&T1, %d, %d, %d)\n", D, H, M);
                CreateTime(&T1, D, H, M);
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
            printHeading("5. TIMEToMenit(T1)");
            getT1(&T1);
            printf("T1 dalam menit = 24 * 60 * %i + 60 * %i + %i = %li\n", Day(T1), Hour(T1), Minute(T1), TIMEToMenit(T1));
        }
        else if (pilihan == 6) {
            printHeading("6. MenitToTIME(N)");
            printf("Masukkan jumlah menit N yang ingin diubah ke TIME: \n");scanf("%d", &N);
            printf("%i menit dalam TIME = ", N); TulisTIME(MenitToTIME(N)); printf("\n");
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
            printHeading("11. NextMenit(T1)");
            getT1(&T1);
            printf("NextMenit(T1) = "); TulisTIME(NextMenit(T1)); printf("\n");
        }
        else if (pilihan == 12) {
            printHeading("12. NextNMenit(T1, N)");
            getT1(&T1);
            printf("Masukkan N menit yang ingin ditambahkan ke T1: \n");scanf("%d", &N);
            printf("NextNMenit(T1, %i) = ", N); TulisTIME(NextNMenit(T1, N)); printf("\n");
        }
        else if (pilihan == 13) {
            printHeading("13. PrevMenit(T1)");
            getT1(&T1);
            printf("PrevMenit(T1) = "); TulisTIME(PrevMenit(T1)); printf("\n");
        }
        else if (pilihan == 14) {
            printHeading("14. PrevNMenit(T1, N)");
            getT1(&T1);
            printf("Masukkan N menit yang ingin dikurangi dari T1: \n");scanf("%d", &N);
            printf("PrevNMenit(T1, %i) = ", N); TulisTIME(PrevNMenit(T1, N)); printf("\n");
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
    printf(" 1. isTIMEValid(D, H, M)\n");
    printf(" 2. CreateTime(*T, DD, HH, MM)\n");
    printf(" 3. BacaTIME(*T)\n");
    printf(" 4. TulisTIME(T)\n");
    printf(" 5. TIMEToMenit(T)\n");
    printf(" 6. MenitToTIME(N)\n");
    printf(" 7. TEQ(T1, T2)\n");
    printf(" 8. TNEQ(T1, T2)\n");
    printf(" 9. TLT(T1, T2)\n");
    printf("10. TGT(T1, T2)\n");
    printf("11. NextMenit(T)\n");
    printf("12. NextNMenit(T, N)\n");
    printf("13. PrevMenit(T)\n");
    printf("14. PrevNMenit(T, N)\n");
    printf("15. Durasi(T1, T2)\n");
}

void getDHM(int *D, int *H, int *M)
/* Membaca D, H, dan M */
{
    /* KAMUS LOKAL */

    /* ALGORITMA */
    printf("Masukkan D: ");scanf("%d", D);
    printf("Masukkan H: ");scanf("%d", H);
    printf("Masukkan M: ");scanf("%d", M);
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