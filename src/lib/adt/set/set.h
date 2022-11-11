/* MODUL SET */

#ifndef SET_H
#define SET_H

#include "../boolean.h"
#include "../sederhana/makanan/makanan.h"
#include "../wordfilemachine/wordfilemachine.h"
#include "../wordfilemachine/charfilemachine.h"
#include "../wordmachine/wordmachine.h"
#include "../wordmachine/charmachine.h"
#include "../sederhana/time/time.h"
#include "../tree/tree.h"
#include "../sederhana/simulator/simulator.h"
#include "../notifikasi/notifikasi.h"

/*  Kamus Umum */
#define CAPACITY 100
/* Kapasitas penyimpanan */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

typedef struct {
    int ID;
    boolean exist;
} ElementSet;

/* Definisi koleksi objek */

typedef struct {
   ElementSet contents[CAPACITY]; /* memori tempat penyimpan elemen (container) */
   int length;
   Makanan utama;
} Set;

typedef struct {
    Set contents[100];
    int JumlahSet;
} ListSet;

/* ********** SELEKTOR ********** */
#define ElSet(l, i) (l).contents[(i)]
#define Exist(el) el.exist
#define MakananSet(el) el.ID
#define Length(l) (l).length
#define Rekomendasi(l) (l).utama
#define JumlahSet(L) (L).JumlahSet

void createSet(Set *himpunan, ListMakanan M);
/* I.S himpunan sembarang dan M terdefinisi */
/* F.S Membuat himpunan dengan elemen-elemen dari M */

void addSet(Set *himpunan, Makanan M);
/* I.S himpunan terdefinisi */
/* F.S Membuat elemen dari set menjadi exist (terdapat pada himpunan) */

void removeSet(Set *himpunan, Makanan M);
/* I.S Himpunan terdefinisi */
/* F.S Membuat sebuah elemen dari himpunan yaitu M menjadi tidak exist. */

boolean isSubset(Set himpunan1, Set himpunan2);
/* Mengirim true jika himpunan1 subset dari himpunan2 */

ListSet BacaRekomendasi(Tree Resep, ListMakanan KumpulanMakanan, ListMakanan ListResep);
/* Mengembalikan list of set yang berisi set-set dari kumpulan resep */

Set BacaRekomendasiSimulator(ListMakanan KumpulanMakanan, Simulator S);
/* Mengembalikan set yang berisi elemen-elemen dari inventory simulator */

void TulisRekomandasi(ListMakanan KumpulanMakanan, ListSet ListRekomendasi, Simulator S);
/* I.S KumpulanMakanan, ListRekomendasi, dan S terdefinisi */
/* F.S Menuliskan rekomendasi resep yang dapat dibuat oleh simulator */

#endif