#ifndef __NOTIFIKASI_H__
#define __NOTIFIKASI_H__

#include "../sederhana/makanan/makanan.h"

typedef struct{
	Makanan makanan; // Nama makanan 
	int tipe; // tipe notifikasi
} Notif;

typedef struct{
  int Neff;
  Notif N[20];
} ListNotif;
/* AKSES (Selektor) */

#define TipeNotif(n) (n).tipe
#define NeffNotif(l) (l).Neff
#define ElmtNotif(l,i) (l).N[i]

void MakeEmptyNotif(ListNotif *L);

void AddNotif (ListNotif *L, int tipe, Makanan M);

void TulisNotif(ListNotif l);

void changeNotif (ListNotif *l);

#endif
