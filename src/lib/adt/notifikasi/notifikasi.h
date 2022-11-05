#ifndef __NOTIFIKASI_H__
#define __NOTIFIKASI_H__

#include "../sederhana/makanan/makanan.h"

typedef struct{
	int tipe; // tipe notifikasi
	Makanan makanan; // Nama makanan 
} Notif;

typedef struct{
  int Neff;
  Notif N[100];
} ListNotif;
/* AKSES (Selektor) */

#define TipeNotif(n) (n).tipe
#define NeffNotif(l) (l).Neff
#define ElmtNotif(l,i) (l).N[i]

void CreateListNotif(ListNotif *L);

void AddNotif (ListNotif *L, int tipe, Makanan M);

void TulisNotif(ListNotif *l);


#endif
