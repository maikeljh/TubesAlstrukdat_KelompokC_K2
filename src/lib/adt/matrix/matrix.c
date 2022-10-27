/* File: matrix.c */
/* Body ADT MATRIX */

#include "matrix.h"
#include <stdio.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m){
    /* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
    /* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
    /* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

    /* Kamus Lokal */
    /* Algoritma */
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
};

/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j){
    /* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */

    /* Kamus Lokal */
    /* Algoritma */
    return ((i >= 0 && i < ROW_CAP) && (j >= 0 && j < COL_CAP));
};


/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m){
    /* Mengirimkan Index baris terbesar m */

    /* Kamus Lokal */
    /* Algoritma */
    return ROW_EFF(m) - 1;
};

IdxType getLastIdxCol(Matrix m){
    /* Mengirimkan Index kolom terbesar m */

    /* Kamus Lokal */
    /* Algoritma */
    return COL_EFF(m) - 1;
};

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol){
    /* I.S. isIdxValid(nRow,nCol) */
    /* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
    /* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
    /* Selanjutnya membaca nilai elemen per baris dan kolom */
    /* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
    1 2 3
    4 5 6
    8 9 10 
    */

    /* Kamus Lokal */
    int i, j, newElement;

    /* Algoritma */
    createMatrix(nRow, nCol, m);

    for(i = 0; i < nRow; i++){
        for(j = 0; j < nCol; j++){
            scanf("%d", &newElement);
            ELMT(*m, i, j) = newElement;
        }
    }
};

void displayMatrix(Matrix m){
    /* I.S. m terdefinisi */
    /* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
    dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
    /* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
    /* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
    1 2 3
    4 5 6
    8 9 10
    */

    /* Kamus Lokal */
    int i, j, newElement;

    /* Algoritma */
    for(i = 0; i <= getLastIdxRow(m); i++){
        for(j = 0; j <= getLastIdxCol(m); j++){
            if(j == getLastIdxCol(m)){
                printf("%d\n", ELMT(m,i,j));
            } else {
                printf("%d ", ELMT(m,i,j));
            }
        }
    }
};

