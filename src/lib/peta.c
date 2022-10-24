#include <stdio.h>
#include "./adt/matrix/matrix.c"
#include "./adt/point/point.c"
#include "./adt/boolean.h"

// sementara input manual, blm bisa dari eksternal
void bacaPeta (Matrix *peta, POINT *S, POINT *T, POINT *M, POINT *C, POINT *F, POINT *B) {
  /*I.S. Matriks peta terdefinisi*/
  /*F.S. Membaca peta sesuai dengan inputan*/
  /*Proses: membaca inputan jumlah baris dan kolom*/
  /*Selanjutnya membaca nilai elemen per baris dan kolom*/

  int col, row, i ,j;
  char element;

  scanf("%d", &col);
  scanf("%d", &row);
  createMatrix(row+2, col+2, peta);
  
  // membuat kerangka (batas)
  for (i = 0; i < row+2; i++) {
    for (j = 0; j < col+2; j++) {
      if (i == 0 || i == row+1 || j == 0 || j == col+1) {
        ELMT(*peta, i, j) = '*';
      } else {
        ELMT(*peta, i , j) = ' ';
      }
    }
  }
  
  // membaca peta
  for (i = 1; i< row+1; i++){
    for (j = 0; j<col+1; j++) { 
      scanf("%c", &element);
      if (element != '#' && element != '\n') {
        ELMT(*peta, i,j) = element;

        //membaca koordinat masing-masing elemen
        if (element == 'S') {
          Absis(*S) = (int)i-1;
          Ordinat(*S) = j-1;
        } else if (element == 'T') {
          Absis(*T) = i-1;
          Ordinat(*T) = j-1;
        } else if (element == 'M') {
          Absis(*M) = i-1;
          Ordinat(*M) = j-1;
        } else if (element == 'C') {
          Absis (*C) = i-1;
          Ordinat (*C) = j-1;
        } else if (element == 'F') {
          Absis(*F) == i-1;
          Ordinat(*F) = j-1;
        } else if (element == 'B') {
          Absis(*B) = i-1;
          Ordinat(*B) = j-1;
        }
      }
    }
  }
}


void displayPeta(Matrix peta) {
  /*Menampilkan peta pada layar*/
  int i,j;
  for (i = 0; i <= getLastIdxRow(peta); i++){
    for (j = 0; j <= getLastIdxRow(peta); j++){
      if (j == getLastIdxCol(peta)) {
        printf("%c\n", ELMT(peta,i,j));
      } else {
        printf("%c ", ELMT(peta,i,j));
      }
    }
  }
  printf("\n");
}

boolean isBlocked(Matrix peta, int x, int y) {
  /*Memeriksa apakah koordinat x,y pada peta dapat dilewati*/
  return (ELMT(peta, x, y) != ' ');
}

void move (Matrix *peta, int direction, POINT *S) {
  /*Menggerakan S sebanyak satu satuan sesuai arah mata angin*/
  /*S tidak dapat berpindah apabila terhalang benda pada tujuannya*/
  /* 1 = atas
     2 = kanan
     3 = bawah
     4 = kiri   */
  
  int x, y, xOld, yOld;
  x = Absis(*S) + 1;
  y = Ordinat(*S) + 1;
  xOld = x;
  yOld = y;

  if (direction == 1) {         //MOVE NORTH
    x -= 1;
  } else if (direction == 2) {  //MOVE EAST
    y += 1;
  } else if (direction == 3) {  //MOVE SOUTH
    x += 1;
  } else if (direction == 4) {  //MOVW WEST 
    y -= 1;
  }

  if (!isBlocked(*peta, x, y)) {
    ELMT(*peta, xOld,yOld) = ' ';
    ELMT(*peta, x,y) = 'S';
    Absis(*S) = x - 1;
    Ordinat(*S) = y - 1;
    // kaitin sama ADT Time
  } else {
    printf("gabisa lewatt\n\n");
  }

}

boolean isNearby(POINT target, POINT S) {
  /*Memeriksa apakah S bersebelahan pada target*/
  // return (Absis(target)-1 <= Absis(S) && Absis(S) <= Absis(target)+1) && (Ordinat(target)-1 <= Ordinat(S) && Ordinat(S) <= Ordinat(target)+1); 

  
}


int main () {
  Matrix peta;
  POINT S,T,M,C,F,B;

  bacaPeta(&peta, &S, &T, &M, &C, &F, &B);
  printf("current loc: ");
  TulisPOINT(S);
  printf("Telephone loc: ");
  TulisPOINT(T);
  printf("Mixing loc: ");
  TulisPOINT(M);

  displayPeta(peta);
  move (&peta, 2, &S);
  move (&peta, 2, &S);
  move (&peta, 2, &S);
  printf("current loc: ")
  TulisPOINT(S);
  displayPeta(peta);
  if (isNearby(T, S)) {
    printf("deket telepon");
  } else {
    printf("gak deket telepon");
  }
}
