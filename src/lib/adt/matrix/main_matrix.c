/*File: main_matrix.c*/
/*Driver ADT matrix*/

#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

int main () {
  // Create matrix
  Matrix m1, m2;
  int row, col;
  printf("**Create Matrix M**\n");
  printf("** Membuat sebuah matrix kosong **\n");
  printf("Masukkan jumlah baris: ");
  scanf("%d", &row);
  printf("Masukkan jumlah kolom: ");
  scanf("%d", &col);
  createMatrix(row, col, &m1);
  printf("Matriks %d x %d berhasil dibuat.\n\n", row, col);

  // Read matrix
  int nRow,nCol;
  printf("**Membaca Matrix M**\n");
  printf("** Membuat matrix dan mengisi elemen - elemennya **\n");
  printf("Masukkan jumlah baris: ");
  scanf("%d", &nRow);
  printf("Masukkan jumlah kolom: ");
  scanf("%d", &nCol);
  printf("Masukkan elemen-elemen matriks: \n");
  readMatrix(&m2, nRow,nCol);
  printf("\n");
  printf("Matriks %d x %d berhasil dibuat dan berisi elemen dengan: \n", nRow, nCol);
  printf("\n");
  // Get last idx
  IdxType lastRow, lastCol;
  lastRow = getLastIdxRow(m2);
  lastCol = getLastIdxCol(m2);
  printf("**Mendapatkan last idx M**\n");
  printf("Last Idx Row: %d\n", lastRow);
  printf("Last Idx Col: %d\n", lastCol);
  printf("\n");

  // Display Matrix
  printf("**Display matriks M yang telah dibaca (readMatrix) **\n");
  displayMatrix(m2);
}