#include "notifikasi.c"
#include "../wordfilemachine/wordfilemachine.c"
#include "../wordfilemachine/charfilemachine.c"
#include "../wordmachine/wordmachine.c"
#include "../wordmachine/charmachine.c"

int main() {
  Makanan Mangga, Pisang, Jeruk;
  Word mangga, pisang, jeruk;
  ListNotif L;

  mangga = CreateWord("mangga", 6);
  Mangga.Nama = mangga;
  pisang = CreateWord("pisang", 6);
  Pisang.Nama = pisang;
  jeruk = CreateWord("jeruk", 5);
  Jeruk.Nama = jeruk;
  // pisang.Nama = "Pisang";
  // jeruk.Nama = "Jeruk";

  //membuat list notifikasi
  MakeEmptyNotif(&L);
  printf("List notifikasi berhasil dibuat\n\n");

  /*KODE NOTIFIKASI
    1 - Makanan telah masuk ke dalam inventory
    2 - Makanan berhasil dikembalikan
    3 - Proses mix makanan berhasil dilakukan.
    4 - Proses chop makanan berhasil dilakukan.
    5 - Proses fry makanan berhasil dilakukan.
    6 - Proses boil makanan berhasil dilakukan.
    7 - Proses mix makanan dibatalkan.
    8 - Proses chop makanan dibatalkan.
    9 - Proses fry makanan dibatalkan.
    10 - Proses boil makanan dibatalkan.
    11 - Makanan telah kedaluwarsa.
    12 - Makanan berhasil dikembalikan.*/

  //menambahkan notifikasi dengan kode dan makanan tertentu
  printf("Menambahkan notifikasi dengan kode 1 dan makanan mangga\n");
  AddNotif(&L, 1, Mangga);
  printf("Menambahkan notifikasi dengan kode 2 dan makanan pisang\n");
  AddNotif(&L, 2, Pisang);
  printf("Menambahkan notifikasi dengan kode 3 dan makanan jeruk\n");
  AddNotif(&L, 3, Jeruk);

  //menampilkan isi list notifikasi
  printf("Menampilkan isi list notifikasi\n\n");
  printf("Notifikasi:\n");

  TulisNotif(L);
}