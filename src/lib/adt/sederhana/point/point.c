/* File: point.c */
/* Body ADT POINT */

#include "point.h"
#include <math.h>
#include <stdio.h>
        
/* *** Konstruktor membentuk POINT *** */
void CreatePoint (POINT * P, int X, int Y) {
   /* Kamus Lokal */
    /* Algoritma */
   Ordinat(*P) = X;
   Absis(*P) = Y;
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

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P){
   /* Kamus Lokal */
    /* Algoritma */
   return ((Absis(P) == 0) && (Ordinat(P) == 0));
};
/* Menghasilkan true jika P adalah titik origin */
boolean IsOnSbX (POINT P){
   /* Kamus Lokal */
    /* Algoritma */
   return (Ordinat(P) == 0);
};
/* Menghasilkan true jika P terletak Pada sumbu X */
boolean IsOnSbY (POINT P){
   /* Kamus Lokal */
    /* Algoritma */
   return (Absis(P) == 0);
};
/* Menghasilkan true jika P terletak pada sumbu Y */
int Kuadran (POINT P){
   /* Kamus Lokal */
    /* Algoritma */
   if((Absis(P) > 0) && (Ordinat(P) > 0)) {
      return 1;
   } else if((Absis(P) < 0) && (Ordinat(P) > 0)) {
      return 2;
   } else if((Absis(P) < 0) && (Ordinat(P) < 0)) {
      return 3;
   } else {
      return 4;
   }
};
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */

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
POINT PlusDelta (POINT P, int deltaX, int deltaY) {
   /* Kamus Lokal */
   POINT P2;
   /* Algoritma */
   CreatePoint(&P2, Absis(P) + deltaX, Ordinat(P) + deltaY);
   return P2;
};;
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
POINT MirrorOf (POINT P, boolean SbX) {
   /* Kamus Lokal */
   POINT P2;
   /* Algoritma */
   if(SbX) {
      CreatePoint(&P2, Absis(P), Ordinat(P) * (-1));
   } else {
      CreatePoint(&P2, Absis(P) * (-1), Ordinat(P));
   }
   return P2;
};
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
float Jarak0 (POINT P){
   /* Kamus Lokal */
   float jarak;
   /* Algoritma */
   jarak = sqrt((pow(Absis(P),2)) + (pow(Ordinat(P),2)));
   return jarak;
}
/* Menghitung jarak P ke (0,0) */
float Panjang (POINT P1, POINT P2){
   /* Kamus Lokal */
   float panjang;
   /* Algoritma */
   panjang = sqrt((pow((Absis(P1) - Absis(P2)),2)) + (pow((Ordinat(P1) - Ordinat(P2)),2)));
   return panjang;
}
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */
void Geser (POINT *P, int deltaX, int deltaY) {
   /* Kamus Lokal */
    /* Algoritma */
   CreatePoint(P, Ordinat(*P) + deltaX, Absis(*P) + deltaY);
};
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
void GeserKeSbX (POINT *P) {
   /* Kamus Lokal */
    /* Algoritma */
   CreatePoint(P, Absis(*P), 0);
};
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
void GeserKeSbY (POINT *P){
   /* Kamus Lokal */
    /* Algoritma */
   CreatePoint(P, 0, Ordinat(*P));
};
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
void Mirror (POINT *P, boolean SbX) {
   /* Kamus Lokal */
    /* Algoritma */
   if(SbX) {
      CreatePoint(P, Absis(*P), Ordinat(*P) * (-1));
   } else {
      CreatePoint(P, Absis(*P) * (-1), Ordinat(*P));
   }
};
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
void Putar (POINT *P, float Sudut) {
   /* Kamus Lokal */
   float radian = (-1) * Sudut / 57.2958;
    /* Algoritma */
   CreatePoint(P, (Absis(*P) * cos(radian)) - (Ordinat(*P) * sin(radian)), (Absis(*P) * sin(radian)) + (Ordinat(*P) * cos(radian)));
};
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */