/* File: point.c */
/* Body ADT POINT */

#include "point.h"
#include <math.h>
#include <stdio.h>
        
/* *** Konstruktor membentuk POINT *** */
void CreatePoint (POINT * P, int X, int Y) {
   /* Kamus Lokal */
    /* Algoritma */
   Ordinat(*P) = Y;
   Absis(*P) = X;
};
/* Membentuk sebuah POINT dari komponen-komponennya */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P) {
   /* Kamus Lokal */
   float x, y;
   /* Algoritma */
   scanf("%f", &x);
   scanf("%f", &y);
   CreatePoint(P, x, y);
}; 
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
void TulisPOINT (POINT P){
   /* Kamus Lokal */
    /* Algoritma */
   printf("(%d,%d)", Absis(P), Ordinat(P));
};
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */                

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2){
   /* Kamus Lokal */
    /* Algoritma */
   return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
};
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
boolean NEQ (POINT P1, POINT P2){
   /* Kamus Lokal */
    /* Algoritma */
   return ((Absis(P1) != Absis(P2)) || (Ordinat(P1) != Ordinat(P2)));
};
/* Mengirimkan true jika P1 tidak sama dengan P2 */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
POINT NextX (POINT P) {
   /* Kamus Lokal */
   POINT P2;
   /* Algoritma */
   CreatePoint(&P2, Absis(P) + 1, Ordinat(P));
   return P2;
};
/* Mengirim salinan P dengan absis ditambah satu */  
            
POINT NextY (POINT P) {
   /* Kamus Lokal */
   POINT P2;
   /* Algoritma */
   CreatePoint(&P2, Absis(P), Ordinat(P) + 1);
   return P2;
};
/* Mengirim salinan P dengan ordinat ditambah satu */

void Geser (POINT *P, int deltaX, int deltaY) {
   /* Kamus Lokal */
    /* Algoritma */
   CreatePoint(P, Ordinat(*P) + deltaX, Absis(*P) + deltaY);
};
