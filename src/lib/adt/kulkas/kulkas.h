/* MODUL LIST INTEGER STATIK DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer statik dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik */

#ifndef KULKAS_H
#define KULKAS_H

#include "../boolean.h"
#include "../sederhana/makanan/makanan.h"
#include "../matrix/matrix.h"
#include <stdio.h>

/* Definisi elemen dan koleksi objek */
typedef int ElType;  /* type elemen List */
typedef int IdxType;
typedef struct {
   ListMakanan Kulkas;
   Matrix Display;
} Kulkas;

/* ********** SELEKTOR ********** */
#define Kulkas(k) (k).Kulkas
#define MatriksKulkas(k) (k).Display

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createKulkas(Kulkas *K);

/* *** Selektor: Untuk sebuah kulkas K yang terdefinisi: *** */
boolean isKulkasFull(Kulkas K);

/* ********** Assignment Kulkas ********** */
void insertKulkas(Kulkas *K, Makanan M);

void deleteKulkas(Kulkas *K, int ID);

/* ********** KELOMPOK BACA/TULIS ********** */
void displayKulkas(Kulkas K);

#endif
