#include <stdio.h>
#include "notifikasi.h"

void CreateListNotif(ListNotif *l) {
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


void TulisNotif(ListNotif *l) {
  if (NeffNotif(*l) != 0) {
    printf("\n");
    int i;
    for (i = 0; i<NeffNotif(*l); i++) {
      if (ElmtNotif(*l, i).tipe == 1) {
        printf("  -%s telah masuk ke dalam inventory\n", ElmtNotif(*l, i).makanan.Nama.TabWord);
      } else if (ElmtNotif(*l, i).tipe == 2) {
        printf("  -%s telah kedaluwarsa\n", ElmtNotif(*l, i).makanan.Nama.TabWord);
      }
    }
    NeffNotif(*l) = 0;
  } else {
    printf("-\n");
  }
}

