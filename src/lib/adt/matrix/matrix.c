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

boolean isIdxEff(Matrix m, IdxType i, IdxType j){
    /* Mengirimkan true jika i, j adalah Index efektif bagi m */

    /* Kamus Lokal */
    /* Algoritma */
    return ((i >= 0 && i <= getLastIdxRow(m)) && (j >= 0 && j <= getLastIdxCol(m)));
};

ElType getElmtDiagonal(Matrix m, IdxType i){
    /* Mengirimkan elemen m(i,i) */

    /* Kamus Lokal */
    /* Algoritma */
    return ELMT(m, i, i);
};


/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut){
    /* Melakukan assignment mOut <- mIn */

    /* Kamus Lokal */
    /* Algoritma */
    *mOut = mIn;
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

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2){
    /* Prekondisi : m1 berukuran sama dengan m2 */
    /* Mengirim hasil penjumlahan matriks: m1 + m2 */

    /* Kamus Lokal */
    Matrix newM;
    int i, j;

    /* Algoritma */
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &newM);

    for(i = 0; i <= getLastIdxRow(m1); i++){
        for(j = 0; j <= getLastIdxCol(m1); j++){
            ELMT(newM, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
        }
    }
    return newM;
};

Matrix subtractMatrix(Matrix m1, Matrix m2){
    /* Prekondisi : m1 berukuran sama dengan m2 */
    /* Mengirim hasil pengurangan matriks: salinan m1 – m2 */

    /* Kamus Lokal */
    Matrix newM;
    int i, j;

    /* Algoritma */
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &newM);

    for(i = 0; i <= getLastIdxRow(m1); i++){
        for(j = 0; j <= getLastIdxCol(m1); j++){
            ELMT(newM, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
        }
    }
    return newM;
};

Matrix multiplyMatrix(Matrix m1, Matrix m2){
    /* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
    /* Mengirim hasil perkalian matriks: salinan m1 * m2 */

    /* Kamus Lokal */
    Matrix newM;
    int i, j, k;
    
    /* Algoritma */
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &newM);

    for (i = 0; i < ROW_EFF(m1); i++){
        for (j = 0; j < COL_EFF(m2); j++){
            for (k = 0; k < COL_EFF(m1); k++){
                ELMT(newM, i, j) += ELMT(m1, i, k) * ELMT(m2, k, j);
            }
        }
    }
    return newM;
};

Matrix multiplyByConst(Matrix m, ElType x){
    /* Mengirim hasil perkalian setiap elemen m dengan x */

    /* Kamus Lokal */
    Matrix newM;
    int i, j;

    /* Algoritma */
    createMatrix(ROW_EFF(m), COL_EFF(m), &newM);

    for(i = 0; i <= getLastIdxRow(m); i++){
        for(j = 0; j <= getLastIdxCol(m); j++){
            ELMT(newM, i, j) = ELMT(m, i, j) * x;
        }
    }
    return newM;
};

void pMultiplyByConst(Matrix *m, ElType k){
    /* I.S. m terdefinisi, k terdefinisi */
    /* F.S. Mengalikan setiap elemen m dengan k */

    /* Kamus Lokal */
    int i, j;

    /* Algoritma */
    for(i = 0; i <= getLastIdxRow(*m); i++){
        for(j = 0; j <= getLastIdxCol(*m); j++){
            ELMT(*m, i, j) *= k;
        }
    }
};


/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2){
    /* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
    /* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
    /* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */

    /* Kamus Lokal */
    int i, j;
    boolean isEqual = true;

    /* Algoritma */
    if(countElmt(m1) != countElmt(m2)){
        return false;
    } else {
        for(i = 0; i <= getLastIdxRow(m1); i++){
            for(j = 0; j <= getLastIdxCol(m1); j++){
                if(ELMT(m1, i, j) != ELMT(m2, i, j)){
                    isEqual = false;
                    break;
                }
            }
        }
        return isEqual;
    }
};

boolean isMatrixNotEqual(Matrix m1, Matrix m2){
    /* Mengirimkan true jika m1 tidak sama dengan m2 */

    /* Kamus Lokal */
    /* Algoritma */
    return (!isMatrixEqual(m1,m2));
};

boolean isMatrixSizeEqual(Matrix m1, Matrix m2){
    /* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
    /* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */

    /* Kamus Lokal */
    /* Algoritma */
    return ((ROW_EFF(m1) == ROW_EFF(m2)) && (COL_EFF(m1) == COL_EFF(m2)));
};


/* ********** Operasi lain ********** */
int countElmt(Matrix m){
    /* Mengirimkan banyaknya elemen m */

    /* Kamus Lokal */
    /* Algoritma */
    return (ROW_EFF(m) * COL_EFF(m));
};


/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m){
    /* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */

    /* Kamus Lokal */
    /* Algoritma */
    return (ROW_EFF(m) == COL_EFF(m));
};

boolean isSymmetric(Matrix m){
    /* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */

    /* Kamus Lokal */
    boolean isSimetri = true;
    int i, j;

    /* Algoritma */
    if(isSquare(m)){
        for(i = 0; i <= getLastIdxRow(m); i++){
            for(j = 0; j <= getLastIdxCol(m); j++){
                if(ELMT(m, i, j) != ELMT(m, j, i)){
                    isSimetri = false;
                    break;
                }
            }
        }
    } else {
        isSimetri = false;
    }

    return isSimetri;
};

boolean isIdentity(Matrix m){
    /* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
    setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */

    /* Kamus Lokal */
    boolean isIdentitas = true;
    int i, j;

    /* Algoritma */
    if(isSquare(m)){
        for(i = 0; i <= getLastIdxRow(m); i++){
            for(j = 0; j <= getLastIdxCol(m); j++){
                if(i == j){
                    if(ELMT(m, i, j) != 1){
                        isIdentitas = false;
                        break;
                    }
                } else {
                    if(ELMT(m, i, j) != 0){
                        isIdentitas = false;
                        break;
                    }
                }
            }
        }
    } else {
        isIdentitas = false;
    }

    return isIdentitas;
};

boolean isSparse(Matrix m){
    /* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */

    /* Kamus Lokal */
    int i, j;
    int count = 0;
    boolean sparse = true;
    int maksimum = countElmt(m) * 5 / 100;

    /* Algoritma */
    for(i = 0; i <= getLastIdxRow(m); i++){
        for(j = 0; j <= getLastIdxCol(m); j++){
             if(ELMT(m,i,j) != 0){
                count += 1;
                if(count > maksimum) {
                    sparse = false;
                    break;
                }
             }   
        }
    }

    return sparse;
};

Matrix negation(Matrix m){
    /* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */

    /* Kamus Lokal */
    /* Algoritma */
    return multiplyByConst(m, -1);
};

void pNegation(Matrix *m){
    /* I.S. m terdefinisi */
    /* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */

    /* Kamus Lokal */
    /* Algoritma */
    pMultiplyByConst(m, -1);
};

float determinant(Matrix m){
    /* Prekondisi: isSquare(m) */
    /* Menghitung nilai determinan m */

    /* Kamus Lokal */
    Matrix temp = m;
    int i, j, k, pengali1, pengali2;
    float determinan = 1;

    /* Algoritma */
    for(j = 0; j < ROW_EFF(temp)-1;j++){
        if(ELMT(temp, j, j) == 0){
            int x = j+1;
            while(ELMT(temp, j, j) == 0 && x < ROW_EFF(temp)){
                if(ELMT(temp, x, j) == 0){
                    continue;
                } else {
                    for(k = 0; k < COL_EFF(temp); k++){
                        ELMT(temp, j, k) += ELMT(temp, x, k);
                    }
                    break;
                }
                x++;
            }
            if(ELMT(temp, j, j) == 0){
                return 0;
            }
        }
        for(i = j + 1; i < ROW_EFF(temp); i++){
            if (ELMT(temp, i, j) != 0){        
            pengali1 = ELMT(temp, j, j);
            pengali2 = ELMT(temp, i, j); 
               for (k = j; k < COL_EFF(temp); k++){
                  ELMT(temp, i, k) *= pengali1;
                  ELMT(temp, j, k) *= pengali2;
                  ELMT(temp, i, k) -= ELMT(temp, j, k);
               }
               determinan /= (pengali1 * pengali2);
            }
         }
    }
    for(i = 0; i < ROW_EFF(temp); i++){
        determinan *= ELMT(temp, i, i);
    }
    return determinan;
};

Matrix transpose(Matrix m){
    /* I.S. m terdefinisi dan IsSquare(m) */
    /* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */

    /* Kamus Lokal */
    Matrix temp_matriks;
    ElType temp;
    int i, j;

    /* Algoritma */
    createMatrix(ROW_EFF(m), COL_EFF(m), &temp_matriks);

    for(i = 0; i < ROW_EFF(m); i++){
        for(j = i;j < COL_EFF(m); j++){
            temp = ELMT(m, i,j);
            ELMT(temp_matriks, i,j) = ELMT(m, j,i);
            ELMT(temp_matriks, j,i) = temp;
        }
    }
    return temp_matriks;
};

void pTranspose(Matrix *m){
    /* I.S. m terdefinisi dan IsSquare(m) */
    /* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */

    /* Kamus Lokal */
    ElType temp;
    int i, j;

    /* Algoritma */
    for(i = 0; i < ROW_EFF(*m); i++){
        for(j = i;j < COL_EFF(*m); j++){
            temp = ELMT(*m, i,j);
            ELMT(*m, i,j) = ELMT(*m, j,i);
            ELMT(*m, j,i) = temp;
        }
    }
};

