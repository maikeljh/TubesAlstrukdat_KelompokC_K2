/* File makanan.h */
/* Definisi Makanan */

#ifndef __MAKANAN_H__
#define __MAKANAN_H__

#include "../../boolean.h"
#include "../time/time.h"
#include "../../wordmachine/wordmachine.h"

typedef struct{
	int ID; // ID Makanan
	Word Nama; // Nama makanan 
	TIME WK; // Waktu kedaluwarsa
    int Lokasi; 
	TIME LP; // Lama pengiriman
} Makanan;

/* AKSES (Selektor) */
/* Jika m adalah Makanan, maka akses elemen: */
#define ID(m) (m).ID
#define Nama(m) (m).Nama
#define Kedaluwarsa(m) (m).WK
#define Lokasi(m) (m).Lokasi
#define Pengiriman(m) (m).LP
#define JamWK(m) (m).WK.HH
#define MenitWK(m) (m).WK.MM
#define DetikWK(m) (m).WK.SS
#define JamLP(m) (m).LP.HH
#define MenitLP(m) (m).LP.MM
#define DetikLP(m) (m).LP.SS

void CreateMakanan(Makanan *M, int id, int loc, Word Nama, TIME wk, TIME lp);
/* Membuat suatu makanan */
int getID(Makanan M);
int getLokasi(Makanan M);
TIME getWK(Makanan M);
TIME getLP(Makanan M);

void TulisMakanan(Makanan M);

void BacaMakanan(Makanan M[]);
void TulisListMakanan(Makanan M[], int N);
#endif