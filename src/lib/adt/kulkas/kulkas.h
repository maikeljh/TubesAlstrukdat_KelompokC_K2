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
/* *** Konstruktor membentuk Matrix *** */
void createKulkas(Kulkas *K);

/* *** Selektor: Untuk sebuah kulkas K yang terdefinisi: *** */
boolean isKulkasFull(Kulkas K);

/* ********** Assignment Kulkas ********** */
boolean insertKulkas(Kulkas *K, Makanan M, int i, int j);

void deleteKulkas(Kulkas *K, int ID, Makanan *Out);

/* ********** KELOMPOK BACA/TULIS ********** */
void displayKulkas(Kulkas K);

void PrintMakananKulkas(Kulkas K);

int commandKulkas();

void ProsesKulkas(Kulkas *K, Simulator *S);
#endif
