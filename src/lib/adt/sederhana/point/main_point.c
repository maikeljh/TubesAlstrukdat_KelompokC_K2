/*File: main_point.c*/
/*Driver ADT point*/


// cd/src/lib/adt/sederhana/point
// gcc main_point.c point.c -o ../../../../../build/lib/adt/sederhana/main_point
#include "point.h"
#include <stdio.h>

int main () {
  // Create point
  POINT P, Q, R;
  int x,y, delX, delY;
  printf("*** Create Point P ***\n");
  printf("Masukkan absis: ");
  scanf("%d", &x);
  printf("Masukkan ordinat: ");
  scanf("%d", &y);
  CreatePoint(&P, x, y);
  printf("*Point berhasil dibuat\n\n");
  
  // bacaPoint
  printf("*** Baca Point Q ***\n");
  printf("Masukkan absis dan ordinat baru: \n");
  BacaPOINT(&Q);

  // tulis point (menampilkan point)
  printf("\n*** Tulis Point P ***\n");
  printf("P: ");
  TulisPOINT(P);

  // memeriksa apakah kedua poin sama EQ/NEQ
  printf("\n\n*** Memeriksa apakah P dan Q bernilai sama ***\n");
  if (EQ(Q, P)) {
    printf("-> Koordinat P dan Q sama.\n");
  } 
  if (NEQ(Q, P)) {
    printf("-> Koordinat P dan Q tidak sama.\n");
  }

  // NextX
  printf("\n*** Mengirim salinan P dengan absis ditambah satu ***\n");
  R = NextX(P);
  printf("R: ");
  TulisPOINT(R);

  // NextY
  printf("\n\n*** Mengirim salinan P dengan ordinat ditambah satu ***\n");
  R = NextY(P);
  printf("R: ");
  TulisPOINT(R);
  
  // Geser
  printf("\n\n*** Memindahkan titik P ***\n");
  printf("Masukkan delta x: ");
  scanf("%d", &delX);
  printf("Masukkan delta y: ");
  scanf("%d", &delY);
  Geser(&P, delX, delY);
  printf("P: ");
  TulisPOINT(P);
  int iptklr;
  printf("\nKetik 0 untuk keluar."); 
  scanf("%d", &iptklr);
}