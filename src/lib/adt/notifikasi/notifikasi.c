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
    int i;
    for (i = 0; i<NeffNotif(l); i++) {
      if (ElmtNotif(l, i).tipe == 1) {
        printf("  -");
        PrintWord(Nama(ElmtNotif(l, i).makanan));
        printf(" telah masuk ke dalam inventory\n");
      } else if (ElmtNotif(l, i).tipe == 2) {
        printf("  -");
        PrintWord(Nama(ElmtNotif(l, i).makanan));
        printf(" berhasil dikembalikan\n");
      } else if (ElmtNotif(l, i).tipe == 3) {
        printf("  -Proses mix ");
        PrintWord(Nama(ElmtNotif(l, i).makanan));
        printf(" berhasil dilakukan.\n");
      } else if (ElmtNotif(l, i).tipe == 4) {
        printf("  -Proses chop ");
        PrintWord(Nama(ElmtNotif(l, i).makanan));
        printf(" berhasil dilakukan.\n");
      } else if (ElmtNotif(l, i).tipe == 5) {
        printf("  -Proses fry ");
        PrintWord(Nama(ElmtNotif(l, i).makanan));
        printf(" berhasil dilakukan.\n");
      } else if (ElmtNotif(l, i).tipe == 6) {
        printf("  -Proses boil ");
        PrintWord(Nama(ElmtNotif(l, i).makanan));
        printf(" berhasil dilakukan.\n");
      } else if (ElmtNotif(l, i).tipe == 7) {
        printf("  -Proses mix ");
        PrintWord(Nama(ElmtNotif(l, i).makanan));
        printf(" dibatalkan.\n");
      } else if (ElmtNotif(l, i).tipe == 8) {
        printf("  -Proses chop ");
        PrintWord(Nama(ElmtNotif(l, i).makanan));
        printf(" dibatalkan.\n");
      } else if (ElmtNotif(l, i).tipe == 9) {
        printf("  -Proses fry ");
        PrintWord(Nama(ElmtNotif(l, i).makanan));
        printf(" dibatalkan.\n");
      } else if (ElmtNotif(l, i).tipe == 10) {
        printf("  -Proses boil ");
        PrintWord(Nama(ElmtNotif(l, i).makanan));
        printf(" dibatalkan.\n");
      } else if (ElmtNotif(l, i).tipe == 11) {
        printf("  -");
        PrintWord(Nama(ElmtNotif(l, i).makanan));
        printf(" telah kedaluwarsa.\n");
      } else if (ElmtNotif(l, i).tipe == 12) {
        printf("  -");
        PrintWord(Nama(ElmtNotif(l, i).makanan));
        printf(" berhasil dikembalikan.\n");
      }
    }
  } else {
    printf("-\n");
  }
}

void changeNotif (ListNotif *l) {
  int i;
  for (i = 0; i<NeffNotif(*l); i++) {
    if (ElmtNotif(*l, i).tipe == 1) {
      ElmtNotif(*l, i).tipe = 2;
    } else if (ElmtNotif(*l, i).tipe == 2) {
      ElmtNotif(*l, i).tipe = 1;
    } else if (ElmtNotif(*l, i).tipe == 3) {
      ElmtNotif(*l, i).tipe = 7;
    } else if (ElmtNotif(*l, i).tipe == 4) {
      ElmtNotif(*l, i).tipe = 8;
    } else if (ElmtNotif(*l, i).tipe == 5) {
      ElmtNotif(*l, i).tipe = 9;
    } else if (ElmtNotif(*l, i).tipe == 6) {
      ElmtNotif(*l, i).tipe = 10;
    } else if (ElmtNotif(*l, i).tipe == 7) {
      ElmtNotif(*l, i).tipe = 3;
    } else if (ElmtNotif(*l, i).tipe == 8) {
      ElmtNotif(*l, i).tipe = 4;
    } else if (ElmtNotif(*l, i).tipe == 9) {
      ElmtNotif(*l, i).tipe = 5;
    } else if (ElmtNotif(*l, i).tipe == 10) {
      ElmtNotif(*l, i).tipe = 6;
    } else if (ElmtNotif(*l, i).tipe == 11) {
      ElmtNotif(*l, i).tipe = 12;
    } else if (ElmtNotif(*l, i).tipe == 12) {
      ElmtNotif(*l, i).tipe = 11;
    }
  }
}


