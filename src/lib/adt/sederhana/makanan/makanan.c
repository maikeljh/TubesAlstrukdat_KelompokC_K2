/* File makanan.c */
/* Algoritma Makanan */


#include <stdio.h>
#include <stdlib.h>
#include "makanan.h"
/*
#define ID(m) (m).ID
#define Nama(m) (m).Nama
#define Kedaluwarsa(m) (m).WK
#define Pengiriman(m) (m).LP
#define JamWK(m) (m).WK.HH
#define MenitWK(m) (m).WK.MM
#define DetikWK(m) (m).WK.SS
#define JamLP(m) (m).LP.HH
#define MenitLP(m) (m).LP.MM
#define DetikLP(m) (m).LP.SS
*/
void CreateMakanan(Makanan *M, int id, int loc, char nama[NMax], TIME wk, TIME lp){
/* Membuat suatu makanan */
	/* KAMUS LOKAL*/
	int i;
	ID(*M) = id;
	for (i = 0; i < NMax; i++){
		Nama(*M)[i] = nama[i];
	}
	Kedaluwarsa(*M) = wk;
	Pengiriman(*M) = lp;
    Lokasi(*M) = loc;

}

void TulisMakanan(Makanan M){
	printf("ID Makanan 			: %d\n", ID(M));
	printf("Nama Makanan 			: %s\n", Nama(M));	
	printf("Waktu Kedaluwarsa Makanan	: %d %d %d\n", JamWK(M), MenitWK(M), DetikWK(M));
	printf("Lama Pengiriman Makanan		: %d %d %d\n", JamLP(M), MenitLP(M), DetikLP(M));
}