/* MODUL LIST INTEGER STATIK DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer statik dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik */

#ifndef KULKAS_H
#define KULKAS_H

#include "../boolean.h"
#include "../matrix/matrix.h"
#include "../sederhana/simulator/simulator.h"
#include <stdio.h>

/* Definisi elemen dan koleksi objek */
typedef int ElType;  /* type elemen List */
typedef int IdxType;

typedef struct{
   Makanan M;
   POINT P;
} ElementKulkas;

typedef struct{
	int NMakanan;
	ElementKulkas E[200];
} ListMakananKulkas;

typedef struct {
   ListMakananKulkas Kulkas;
   Matrix Display;
} Kulkas;

/* ********** SELEKTOR ********** */
#define Kulkas(k) (k).Kulkas
#define MatriksKulkas(k) (k).Display
#define ElementKulkas(k, i) (k).E[i]
#define MakananKulkas(k, i) (k).E[i].M
#define PointMakananKulkas(k,i) (k).E[i].P

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Kulkas *** */
void createKulkas(Kulkas *K);
/* I.S. K sembarang */
/* F.S. Terbentuk Kulkas K kosong  */

/* *** Selektor: Untuk sebuah kulkas K yang terdefinisi: *** */
boolean isKulkasFull(Kulkas K);
/* Mengembalikkan true jika kulkas sudah penuh (tidak ada value 0 di dalam matriks kulkas ) */

boolean isKulkasKosong(Kulkas K);
/* Mengembalikkan true jika kulkas kosong (semua memiliki value 0 di dalam matriks kulkas ) */

/* ********** Assignment Kulkas ********** */
boolean insertKulkas(Kulkas *K, Makanan M, int i, int j);
/* Mengembalikkan true jika proses insert kulkas berhasil dan false jika proses gagal */

void deleteKulkas(Kulkas *K, int ID, Makanan *Out);
/* I.S. K terdefinisi dan tidak kosong, ID terdefinisi, dan Out sembarang */
/* F.S. Out menjadi terdefinisi dengan makanan yang memiliki ID 'ID' diambil dari kulkas */

/* ********** KELOMPOK BACA/TULIS ********** */
void displayKulkas(Kulkas K);
/* I.S. K terdefinisi */
/* F.S. Tercetaknya matriks kulkas pada layar */

void PrintMakananKulkas(Kulkas K);
/* I.S. K terdefinisi dan bisa jadi kosong */
/* F.S. Tercetaknya list makanan yang terdapat di dalam kulkas */

int commandKulkas();
/* Mengembalikkan command berupa integer untuk proses kulkas */

void ProsesKulkas(Kulkas *K, Simulator *S);
/* I.S. K terdefinisi dan S terdefinisi */
/* F.S. Melakukan proses kulkas */

#endif
