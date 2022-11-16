/* File : peta.c */

void bacaPeta (char fileName[], Matrix *peta, POINT *S, POINT *T, POINT *M, POINT *C, POINT *F, POINT *B) {
  /*I.S. Matriks peta terdefinisi*/
  /*F.S. Membaca peta sesuai dengan inputan*/
  /*Proses: membaca inputan jumlah baris dan kolom*/
  /*Selanjutnya membaca nilai elemen per baris dan kolom*/

  int col, row, i ,j;
  char element;

  startWordFile(fileName);
  row = wordToInt(currentWordFile);
  advWordFile();
  col = wordToInt(currentWordFile);

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
    for (j = 1; j<col+2; j++) { 
      advCharFile();
      element = currentCharFile;
      if (element != '#' && element != '\n') {
        ELMT(*peta, i,j) = element;

        //membaca koordinat masing-masing elemen
        if (element == 'S') {
          CreatePoint(S, i-1, j-1);
        } else if (element == 'T') {
          CreatePoint(T, i-1, j-1);
        } else if (element == 'M') {
          CreatePoint(M, i-1, j-1);
        } else if (element == 'C') {
          CreatePoint(C, i-1, j-1);
        } else if (element == 'F') {
          CreatePoint(F, i-1, j-1);
        } else if (element == 'B') {
          CreatePoint(B, i-1, j-1);
        }
      }
    }
  }
}


void displayPeta(Matrix peta, POINT S) {
  /*Menampilkan peta pada layar*/
  int i,j;
  for (i = 0; i <= getLastIdxRow(peta); i++){
    for (j = 0; j <= getLastIdxCol(peta); j++){
      if (ELMT(peta,i,j) == 'S') {
        ELMT(peta,i,j) = ' ';
      }

      if (i == Absis(S)+1 && j == Ordinat(S)+1) {
        ELMT(peta,i,j) = 'S';
      }

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

void move (Matrix peta, int direction, POINT *S, boolean *moved) {
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

  if (!isBlocked(peta, x, y)) {
    // ELMT(*peta, xOld,yOld) = ' ';
    // ELMT(*peta, x,y) = 'S';
    Absis(*S) = x - 1;
    Ordinat(*S) = y - 1;
    *moved = true;
  } else {
    printf("\n Pemain tidak bisa lewat\n\n");
    *moved = false;
  }

}

boolean isNearby(POINT target, POINT S) {
  /*Memeriksa apakah S bersebelahan (adjacent) pada target*/ 
  if (Absis(target) == Absis(S)) {
    if (Ordinat(target)-1 == Ordinat(S) || Ordinat(target)+1 == Ordinat(S)) {
      return true;
    } else {
      return false;
    }
  } else if (Ordinat(target) == Ordinat(S)) {
    if (Absis(target)-1 == Absis(S) || Absis(target)+1 == Absis(S)) {
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}
