#include "prioqueuetime.h"
#include <stdio.h>
#include <stdlib.h>

/* Cara kompilasi driver:
cd src/lib/adt/prioqueue 
gcc main_prioqueue.c prioqueuetime.c ../sederhana/time/time.c ../sederhana/makanan/makanan.c ../wordmachine/wordmachine.c ../wordmachine/charmachine.c ../wordfilemachine/wordfilemachine.c ../wordfilemachine/charfilemachine.c ../tree/tree.c ../notifikasi/notifikasi.c -o main
*/
Word BacaNama(void);
    // Membaca input nama makanan dan di assign ke suatu tipe Word yang menyimpan nama makanan tersebut.
void MenuAwal(void);
    // Membacakan menu awal yang bisa dilakukan, berkaitan sebuah prioqueue belum terbentuk, fungsi yang dapat digunakan masih terbatas.
void Menu(void);
    /* Membacakan Menu utama. Menu ini dapat diakses setelah sebuah prioqueue terbuat, berkaitan dengan hampir seluruh fungsi membutuhkan sebuah
     sebuah prioqueue terbentuk terlebih dahulu */

int main(){
    /* KAMUS UTAMA */
    Makanan M;
    int id, lokasi, cmd, max, length;
    long wk, lp, dp;
    TIME wk2, lp2, dp2;
    Word NamaMakanan;
    PrioQueueTime Q;
    boolean menuawal= false, created = false;
    ListNotif l;
    MakeEmptyNotif(&l);

    printf("Tekan Enter untuk memulai program driver.");
    STARTWORD();
    while (cmd != 0){
        while(!created){
            if (!menuawal){
                MenuAwal();
            }
            printf("Silahkan pilih  untuk membuat  sebuah PrioQueue sehingga bisa menguji fungsi lainnya! : "); scanf("%d", &cmd);
            if (cmd == 4){
                printf("Input ukuran jumlah penyimpanan maksimum PrioQueue (max elemen): "); scanf("%d", &max);
                MakeEmpty(&Q, max);
                printf("Terbentuk sebuah PrioQueue kosong dengan ukuran maksimum atau jumlah elemen dalam PrioQueue: %d elemen.\n", max);
                created = true;
                printf("Tekan enter untuk melanjutkan program. ");
                STARTWORD();
                ADV();
            }
            else if (cmd == 0){
                printf("Terima kasih telah menggunakan driver!");
                return 0;
            }
            else{
                printf("Pilihan tersebut tidak ada. Silahkan input pilihan dengan benar sesuai menu yang disediakan!\n");
                printf("Tekan enter untuk melanjutkan program. ");
                STARTWORD();
                ADV();
            }
        }
        menuawal = true;
        Menu();
        printf("Silahkan pilih fungsi yang ingin diuji dengan menginput nomor urutan fungsi (0-14): "); scanf("%d", &cmd);
        if (cmd == 1){
            printf("1. IsEmpty(Q)\n");
            if (IsEmpty(Q)){
                printf("PrioQueueTime kosong (IsEmpty(Q) == true)\n");
            }
            else{
                printf("PrioQueueTime tidak kosong, terdapat informasi makanan di dalamnya. (IsEmpty(Q) = false)\n");
            }
            printf("Tekan enter untuk melanjutkan program. "); STARTWORD(); ADV();
        }
        else if (cmd == 2){
            printf("2. IsFull(Q)\n");
            if (IsFull(Q)){
                printf("PrioQueueTime penuh (IsEmpty(Q) == true)\n");
            }
            else{
                printf("PrioQueueTime tidak penuh, terdapat informasi makanan di dalamnya. (IsEmpty(Q) = false)\n");
            }
            printf("Tekan enter untuk melanjutkan program. "); STARTWORD(); ADV();
        }
        else if (cmd == 3){
            printf("3. NBElmt(Q)\n");
            length = NBElmt(Q);
            if (IsEmpty(Q)){
                printf("Jumlah elemen dalam PrioQueueTime: %d. Isi PrioQueueTime kosong.\n", length);
            }
            else if (IsFull(Q)){
                printf("Jumlah elemen dalam PrioQueueTime: %d. Isi PrioQueueTime penuh.\n", length);
            }
            else {
                printf("Jumlah elemen dalam PrioQueueTime: %d\n", length);
            }
            printf("Tekan enter untuk melanjutkan program. "); STARTWORD(); ADV();
        }
        else if (cmd == 4){
            printf("4. MakeEmpty(&Q, Max)\n");
            printf("Input ukuran jumlah penyimpanan maksimum PrioQueue (max elemen): "); scanf("%d", &max);
            MakeEmpty(&Q, max);
            printf("Terbentuk sebuah PrioQueue kosong dengan ukuran maksimum atau jumlah elemen dalam PrioQueue: %d elemen.", max);
            printf("Tekan enter untuk melanjutkan program. "); STARTWORD(); ADV();
        }
        else if (cmd == 5){
            printf("5. DeAlokasi(Q)\n");
            DeAlokasi(&Q);
            printf("Keterangan: Max <- 0 (Nilai Max atau jumlah elemen prioqueue menjadi 0).\n");
            printf("PrioQueueTime telah didealokasi. PrioQueueTime yang dibuat telah hilang. Jika ingin membuat baru, silahkan memanggil fungsi MakeEmpty(&Q, Max). \n");
            created = false; menuawal = false;
            printf("Tekan enter untuk melanjutkan program. "); STARTWORD(); ADV();
        }
        else if (cmd == 6){
            printf("6. Enqueue(&Q, M)\n");
            if (!IsFull(Q)){
                printf("Proses Enqueue dilakukan dengan menentukan makanan terlebih dahulu.\n");
                printf("Keterangan: Detil informasi makanan tidak penting. input sesuai aturan saja karena hanya dalam driver.\n");
                printf("Input nama makanan: "); STARTWORD(); NamaMakanan = BacaNama();
                printf("Input ID Makanan (integer): "); scanf("%d", &id);
                printf("Input Waktu Kedaluwarsa dalam satuan menit (long integer): "), scanf("%li", &wk); wk2 = MenitToTIME(wk);
                printf("Input Lama Pengiriman dalam satuan menit (long integer): "), scanf("%li", &lp); lp2 = MenitToTIME(lp);
                printf("Input Lokasi (integer): "); scanf("%d", &lokasi);
                printf("Input Durasi Pengolahan dalam satuan menit(long integer): "), scanf("%li", &dp); dp2 = MenitToTIME(dp);
                CreateMakanan(&M, id, lokasi, NamaMakanan, wk2, lp2, dp2);
                printf("Isi PrioQueueTime sebelum Enqueue: \n");
                if(!IsEmpty(Q)){
                    printf("(nama - waktu sisa kedaluwarsa)\n");
                }
                PrintPrioQueueTime(Q);
                Enqueue(&Q, M);
                printf("Isi PrioQueueTime setelah Enqueue: \n");
                if(!IsEmpty(Q)){
                    printf("(nama - waktu sisa kedaluwarsa)\n");
                }
                PrintPrioQueueTime(Q);
            }
            else{
                printf("PrioQueueTime sudah penuh! Enqueue tidak bisa dilakukan. Silahkan dequeue terlebih dahulu atau dealokasi PrioQueueTime.\n");
            }
            printf("Tekan enter untuk melanjutkan program. "); STARTWORD(); ADV();
        }
        else if (cmd == 7){
            printf("7. EnqueueDelivery(&Q, M)\n");
            if (!IsFull(Q)){
                printf("Proses EnqueueDelivery dilakukan dengan menentukan makanan terlebih dahulu.\n");
                printf("Keterangan: Detil informasi makanan tidak penting. input sesuai aturan saja karena hanya dalam driver.\n");
                printf("Input nama makanan: "); STARTWORD(); NamaMakanan = BacaNama();
                printf("Input ID Makanan (integer): "); scanf("%d", &id);
                printf("Input Waktu Kedaluwarsa dalam satuan menit (long integer): "), scanf("%li", &wk); wk2 = MenitToTIME(wk);
                printf("Input Lama Pengiriman dalam satuan menit (long integer): "), scanf("%li", &lp); lp2 = MenitToTIME(lp);
                printf("Input Lokasi (integer): "); scanf("%d", &lokasi);
                printf("Input Durasi Pengolahan dalam satuan menit(long integer): "), scanf("%li", &dp); dp2 = MenitToTIME(dp);
                CreateMakanan(&M, id, lokasi, NamaMakanan, wk2, lp2, dp2);
                printf("Isi PrioQueueTime sebelum EnqueueDelivery: \n");
                if(!IsEmpty(Q)){
                    printf("(nama - waktu sisa delivery)\n");
                }
                PrintDelivery(Q);
                EnqueueDelivery(&Q, M);
                printf("Isi PrioQueueTime setelah EnqueueDelivery: \n");
                if(!IsEmpty(Q)){
                    printf("(nama - waktu sisa delivery)\n");
                }
                PrintDelivery(Q);
            }
            else{
                printf("PrioQueueTime sudah penuh! EnqueueDelivery tidak bisa dilakukan. Silahkan dequeue terlebih dahulu atau dealokasi PrioQueueTime.\n");
            }
            printf("Tekan enter untuk melanjutkan program. "); STARTWORD(); ADV();
        }
        else if (cmd == 8){
            printf("8. Dequeue(&Q, &M");
            printf("Dequeue mengeluarkan elemen pertama pada PrioQueueTime.\n");
            if(!IsEmpty(Q)){
                printf("Isi PrioQueueTime sebelum Dequeue \n");
                printf("(nama - waktu sisa kedaluwarsa)\n");
                PrintPrioQueueTime(Q);
                Dequeue(&Q, &M);
                printf("Nama Makanan yang telah di dequeue: "); PrintWord(Nama(M));
                printf("\nIsi PrioQueueTime setelah Dequeue \n");
                if(!IsEmpty(Q)){
                    printf("(nama - waktu sisa kedaluwarsa)\n");
                }
                PrintPrioQueueTime(Q);
            }
            else{
                printf("PrioQueueTime kosong. Tidak ada elemen yang bisa di Dequeue. Silahkan Enqueue sebuah elemen terlebih dahulu untuk mengakses fungsi ini.\n");
            }

            printf("Tekan enter untuk melanjutkan program. "); STARTWORD(); ADV();
        }
        else if (cmd == 9){
            printf("9. PrintPrioQueueTime(Q)\n");
            printf("Isi PrioQueueTime\n");
            if(!IsEmpty(Q)){
                printf("(nama - waktu sisa kedaluwarsa)\n");
            }
            PrintPrioQueueTime(Q);
            printf("Tekan enter untuk melanjutkan program. "); STARTWORD(); ADV();
        }
        else if (cmd == 10){
            printf("10. PrintDelivery(Q)\n");
            printf("Isi PrioQueueTime :\n");
            if(!IsEmpty(Q)){
                printf("(nama - waktu sisa delivery)\n");
            }
            PrintDelivery(Q);
            printf("Tekan enter untuk melanjutkan program. "); STARTWORD(); ADV();
        }
        else if (cmd == 11){
            printf("11. CariMakanan(Q, id)\n");
            printf("Input ID makanan yang dicari: "); scanf("%d", &id);
            int find = CariMakanan(Q, id);
            if (find != -1){
                printf("Indeks makanan dalam PrioQueueTime: %d.\n", id);
                printf("Nama makanan yang ditemukan: "); PrintWord(Nama(Elmt(Q, find))); printf("\n");
            }
            else{
                printf("Makanan tidak ditemukan dalam PrioQueueTime.\n");
            }
            printf("Tekan enter untuk melanjutkan program. "); STARTWORD(); ADV();
        }
        else if (cmd == 12){
            printf("12. DequeueAt(&Q, id, &M)\n");
            printf("Input indeks (letak) makanan dalam PrioQueueTime yang ingin di Dequeue: "), scanf("%d", id);
            if(!IsEmpty(Q) && id < max){
                printf("Isi PrioQueueTime sebelum DequeueAt: \n");
                printf("(nama - waktu sisa kedaluwarsa)\n");
                PrintPrioQueueTime(Q);
                DequeueAt(&Q, id, &M);
                printf("Nama Makanan yang telah di dequeue: "); PrintWord(Nama(M));
                printf("\nIsi PrioQueueTime setelah DequeueAt: \n");
                if(!IsEmpty(Q)){
                    printf("(nama - waktu sisa kedaluwarsa)\n");
                }
                PrintPrioQueueTime(Q);
            }
            else{
                printf("PrioQueueTime kosong atau indeks tidak dalam cakupan jumlah elemen PrioQueueTime. Silahkan Enqueue terlebih dahulu apabila kosong.\n");
            }
            printf("Tekan enter untuk melanjutkan program. "); STARTWORD(); ADV();
        }
        else if (cmd == 13){
            printf("13. DecayKedaluwarsa(&Q, &l)\n");
            printf("Keterangan: ListNotif l berfungsi sebagai notifikasi main program, diluar keperluan driver main PrioQueueTime ini.\n");
            printf("Mengurangi waktu kedaluwarsa seluruh makanan dalam PrioQueueTime sebanyak 1 menit.\n");
            printf("Isi PrioQueueTime sebelum DecayKedaluwarsa: \n");
            if(!IsEmpty(Q)){
                printf("(nama - waktu sisa kedaluwarsa)\n");
            }
            PrintPrioQueueTime(Q);
            DecayKedaluwarsa(&Q, &l);
            printf("Isi PrioQueueTime setelah DecayKedaluwarsa: \n");
            if(!IsEmpty(Q)){
                printf("(nama - waktu sisa kedaluwarsa)\n");
            }
            PrintPrioQueueTime(Q);
            printf("Tekan enter untuk melanjutkan program. "); STARTWORD(); ADV();
        }
        else if (cmd == 14){
            printf("14. DequeueExpired(&Q, &l)\n");
            printf("Melakukan Dequeue terhadap seluruh makanan yang waktu kedaluwarsanya = 0 menit.\n");
            printf("Isi PrioQueueTime sebelum DequeueExpired: \n");
            if(!IsEmpty(Q)){
                printf("(nama - waktu sisa kedaluwarsa)\n");
            }
            PrintPrioQueueTime(Q);
            DequeueExpired(&Q, &l);
            printf("Isi PrioQueueTime setelah DequeueExpired: \n");
            if(!IsEmpty(Q)){
                printf("(nama - waktu sisa kedaluwarsa)\n");
            }
            PrintPrioQueueTime(Q);
            printf("Tekan enter untuk melanjutkan program. "); STARTWORD(); ADV();
            printf("Tekan enter untuk melanjutkan program. "); STARTWORD(); ADV();
        }
        else if (cmd != 0){
            printf("Pilihan tidak ada di menu. Silahkan input pilihan sesuai tampilan menu.\n");
            printf("Tekan enter untuk melanjutkan program. "); STARTWORD(); ADV();
        }
    }
    printf("Terima kasih telah menggunakan driver!");
    return 0;
}
void MenuAwal(void){
    printf("** MENU AWAL ** \n");
    printf(" 0. KELUAR\n");
    printf(" 4. MakeEmpty(&Q, Max)\n");
}
void Menu(void){
    printf("** MENU **\n");
    printf(" 0. KELUAR\n");
    printf(" 1. IsEmpty(Q)\n");
    printf(" 2. IsFull(Q)\n");
    printf(" 3. NBElmt(Q)\n");
    printf(" 4. MakeEmpty(&Q, Max)\n");
    printf(" 5. DeAlokasi(Q)\n");
    printf(" 6. Enqueue(&Q, M)\n");
    printf(" 7. EnqueueDelivery(&Q, M)\n");
    printf(" 8. Dequeue(&Q, &M)\n");
    printf(" 9. PrintPrioQueueTime(Q)\n");
    printf(" 10. PrintDelivery(Q)\n");
    printf(" 11. CariMakanan(Q, id)\n");
    printf(" 12. DequeueAt(&Q, id, M)\n");
    printf(" 13. DecayKedaluwarsa(&Q, &l)\n");
    printf(" 14. DequeueExpired(&Q, &l)\n");
}
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