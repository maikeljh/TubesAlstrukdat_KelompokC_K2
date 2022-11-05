#include <stdio.h>
#include "notifikasi.h"

void MakeEmptyNotif(ListNotif *l) {
  NeffNotif(*l) = 0;
}

void AddNotif(ListNotif *l, int T, Makanan M){
    /* Menambahkan notifikasi ke list notifikasi */
    /* I.S. notif terdefinisi */
    /* F.S. notif bertambah satu elemen */
    /* KAMUS LOKAL */
    NeffNotif(*l) ++;
    ElmtNotif(*l, NeffNotif(*l)-1).tipe = T;
    ElmtNotif(*l, NeffNotif(*l)-1).makanan= M;
}

void TulisNotif(ListNotif l) {
  if (NeffNotif(l) != 0) {
    printf("\n");
    int i;
    for (i = 0; i<NeffNotif(l); i++) {
      if (ElmtNotif(l, i).tipe == 1) {
        printf("  -%s telah masuk ke dalam inventory\n", ElmtNotif(l, i).makanan.Nama.TabWord);
      } else if (ElmtNotif(l, i).tipe == 2) {
        printf("  -%s telah kedaluwarsa\n", ElmtNotif(l, i).makanan.Nama.TabWord);

      } else if (ElmtNotif(l, i).tipe == 3) {
        printf("  -Proses mix %s dibatalkan.\n", ElmtNotif(l, i).makanan.Nama.TabWord);
      } else if (ElmtNotif(l, i).tipe == 4) {
        printf("  -Proses chop %s dibatalkan.\n", ElmtNotif(l, i).makanan.Nama.TabWord);
      } else if (ElmtNotif(l, i).tipe == 5) {
        printf("  -Proses fry %s dibatalkan.\n", ElmtNotif(l, i).makanan.Nama.TabWord);
      } else if (ElmtNotif(l, i).tipe == 6) {
        printf("  -Proses boil %s dibatalkan.\n", ElmtNotif(l, i).makanan.Nama.TabWord);

      } else if (ElmtNotif(l, i).tipe == 7) {
        printf("  -%s berhasil dikembalikan.\n", ElmtNotif(l, i).makanan.Nama.TabWord);
      }
      // } else if (ElmtNotif(l, i).tipe == 5) {
      // } else if (ElmtNotif(l, i).tipe == 5) {
      // } else if (ElmtNotif(l, i).tipe == 5) {
      // } else if (ElmtNotif(l, i).tipe == 5) {
      // }
    }
  } else {
    printf("-\n");
  }
}


