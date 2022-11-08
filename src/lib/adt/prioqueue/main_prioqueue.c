#include "prioqueuetime.h"
#include <stdio.h>
#include <stdlib.h>

/* Cara kompilasi driver: 
gcc main_prioqueue.c prioqueuetime.c ../sederhana/time/time.c ../sederhana/makanan/makanan.c ../wordmachine/wordmachine.c ../wordmachine/charmachine.c ../wordfilemachine/wordfilemachine.c ../wordfilemachine/charfilemachine.c ../tree/tree.c ../notifikasi/notifikasi.c -o main
*/
Word BacaNama(void);
    // Membaca input nama makanan dan di assign ke suatu tipe Word yang menyimpan nama makanan tersebut.
void MenuAwal(void);
    // Membacakan menu awal yang bisa dilakukan, berkaitan sebuah prioqueue belum terbentuk, fungsi yang dapat digunakan masih terbatas.
void Menu(void);
    /* Membacakan Menu utama. Menu ini dapat diakses setelah sebuah prioqueue terbuat, berkaitan dengan hampir seluruh fungsi membutuhkan sebuah
     sebuah prioqueue terbentuk terlebih dahulu */
Word BacaNama(void) {
    // Membaca input nama makanan.
    int i, idxNama = 0;
    Word NamaMakanan;
    STARTWORD();
    while(currentChar != '\n'){
        for (i = 0; i < currentWord.Length; i++){
            NamaMakanan.TabWord[idxNama] = currentWord.TabWord[i];
            idxNama++;
        }
        NamaMakanan.TabWord[idxNama] = ' ';
        idxNama++;
        ADVWORD();
    }
    for (i = 0; i < currentWord.Length; i++){
        NamaMakanan.TabWord[idxNama] = currentWord.TabWord[i];
        idxNama++;
    }
    NamaMakanan.Length = idxNama;
    return NamaMakanan;
}
int main(){
    /* KAMUS UTAMA */
    Makanan M1;
    int id, lokasi, cmd, max;
    TIME wk, lp;
    Word NamaMakanan;
    PrioQueueTime inventory;
    bool created = false;

    while (cmd != 0){
        while(!created){
            printf("Silahkan pilih  untuk membuat  sebuah PrioQueue sehingga bisa menguji fungsi lainnya! :"); scanf("%d", &cmd);
            if (cmd == 1){
                printf("Input ukuran jumlah penyimpanan maksimum PrioQueue (max elemen): "); scanf("%d", &max);
                MakeEmpty(&inventory, max);
                printf("Terbentuk sebuah PrioQueue kosong dengan ukuran maksimum atau jumlah elemen dalam PrioQueue: %d elemen.", max);
                created = true;
            }
            else if (cmd == 0){
                printf("Terima kasih telah menggunakan driver!");
                return 0;
            }
        }
        if (cmd == 1){
            printf("Input ukuran jumlah penyimpanan maksimum PrioQueue (max elemen): "); scanf("%d", &max);
            MakeEmpty(&inventory, max);
            printf("Terbentuk sebuah PrioQueue kosong dengan ukuran maksimum atau jumlah elemen dalam PrioQueue: %d elemen.", max);
            created = true;
        }
        else if (cmd == 2){}
        else if (cmd == 3){}
    }
    printf("Terima kasih telah menggunakan driver!");
    return 0;
}