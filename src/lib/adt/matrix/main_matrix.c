/*File: main_matrix.c*/
/*Driver ADT matrix*/

#include "matrix.c"

int main () {
  // Create matrix
  Matrix m;
  int row, col;
  printf("**Create Matrix M**\n");
  printf("Masukkan jumlah baris: ");
  scanf("%d", &row);
  printf("Masukkan jumlah kolom: ");
  scanf("%d", &col);
  printf("Matriks %d x %d berhasil dibuat.\n\n", row, col);

  // Read matrix
  int nRow,nCol;
  printf("**Membaca Matrix M**\n");
  printf("Masukkan jumlah baris: ");
  scanf("%d", &nRow);
  printf("Masukkan jumlah kolom: ");
  scanf("%d", &nCol);
  printf("Masukkan elemen-elemen matriks: \n");
  readMatrix(&m, nRow,nCol);
  printf("\n");

  // Get last idx
  int lastRow, lastCol;
  lastRow = getLastIdxRow(m);
  lastCol = getLastIdxCol(m);
  printf("**Mendapatkan last idx M**\n");
  printf("Last Idx Row: %d\n", lastRow);
  printf("Last Idx Col: %d\n", lastCol);
  printf("\n");

  // Display Matrix
  printf("**Display matriks M**\n");
  displayMatrix(m);
  printf("\n");
}