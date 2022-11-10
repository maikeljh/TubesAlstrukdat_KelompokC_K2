/* File makanan.h */
/* Definisi Makanan */

#ifndef __MAKANAN_H__
#define __MAKANAN_H__

#include "../../boolean.h"
#include "../time/time.h"
#include "../../wordmachine/wordmachine.h"
#include "../../wordfilemachine/wordfilemachine.h"
#include "../../tree/tree.h"

typedef struct{
	int ID; // ID Makanan
	Word Nama; // Nama makanan 
	TIME WK; // Waktu kedaluwarsa
    int Lokasi; // Lokasi Makanan (Representasi Lokasi berbentuk angka)
	TIME LP; // Lama pengiriman
	TIME Pengolahan; // Waktu Pengolahan
} Makanan;

typedef struct{
	int NMakanan;
	Makanan M[200];
} ListMakanan;

/* AKSES (Selektor) */
/* Jika m adalah Makanan, maka akses elemen: */
#define ID(m) (m).ID
#define Nama(m) (m).Nama
#define Kedaluwarsa(m) (m).WK
#define Lokasi(m) (m).Lokasi
#define Pengiriman(m) (m).LP
#define Pengolahan(m) (m).Pengolahan
#define DayWK(m) (m).WK.DD
#define HourWK(m) (m).WK.HH
#define MinuteWK(m) (m).WK.MM
#define DayLP(m) (m).LP.DD
#define HourLP(m) (m).LP.HH
#define MinuteLP(m) (m).LP.MM
#define DayPengolahan(m) (m).Pengolahan.DD
#define HourPengolahan(m) (m).Pengolahan.HH
#define MinutePengolahan(m) (m).Pengolahan.MM

/* AKSES List Makanan (Selektor) */
#define Makanan(L, i) (L).M[i]
#define JumlahMakanan(L) (L).NMakanan

void CreateMakanan(Makanan *M, int id, int loc, Word Nama, TIME wk, TIME lp, TIME Pengolahan);
/* Membuat suatu makanan dengan id, location, nama, waktu kedaluwarsa, dan waktu delivery yang terdefinisi */
/* I.S. Makanan M sembarang, id, loc, Nama, wk, dan lp terdefinisi */
/* F.S. Terbuatnya makanan M dengan masukkan sesuai argumen */

int getID(Makanan M);
/* Mengembalikan ID dari Makanan M */
int getLokasi(Makanan M);
/* Mengembalikan Lokasi dari Makanan M */

TIME getWK(Makanan M);
/* Mengembalikan waktu kedaluwarsa dari Makanan M */

TIME getLP(Makanan M);
/* Mengembalikan waktu delivery dari Makanan M */

// int pangkat(int x, int y);
/* Mengembalikan nilai dari x pangkat y */

// int wordToInt (WordFile str);
/* Mengembalikan nilai integer dari WordFile yang dibaca */

void TulisMakanan(Makanan M);
/* Menuliskan makanan ke layar yang berisi detail lengkap mengenai makanan tersebut */
/* I.S. Makanan M terdefinisi */
/* F.S. Tampilnya informasi detail mengenai Makanan M */

ListMakanan BacaMakanan(char fileName[]);
/* Membaca list makanan dari konfigurasi file dan mengembalikannya sebagai list of makanan */

void TulisListMakanan(ListMakanan M, int N);
/* Menuliskan list of makanan ke layar yang berisi detail lengkap mengenai setiap makanan dalam list */
/* I.S. ListMakanan M terdefinisi */
/* F.S. Tampilnya informasi detail mengenai ListMakanan M */

#endif