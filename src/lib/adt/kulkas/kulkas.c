#include "kulkas.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createKulkas(Kulkas *K){
    ListMakanan M;
    JumlahMakanan(M) = 0;
    Matrix D;

    createMatrix(10, 20, &D);
    for(int i = 0 ; i < ROW_EFF(D); i++){
        for(int j = 0; j < COL_EFF(D); j++){
            ELMT(D, i , j) = 0;
        }
    }

    Kulkas(*K) = M;
    MatriksKulkas(*K) = D;
}

/* *** Selektor: Untuk sebuah kulkas K yang terdefinisi: *** */
boolean isKulkasFull(Kulkas K){
    boolean full = true;
    Matrix D = MatriksKulkas(K);
    for(int i = 0 ; i < ROW_EFF(D); i++){
        for(int j = 0; j < COL_EFF(D); j++){
            if(ELMT(D, i , j) != 0){
                full = false;
                break;
            }
        }
        if(!full){
            break;
        }
    }

    return full;
}

/* ********** Assignment Kulkas ********** */
void insertKulkas(Kulkas *K, Makanan M, int i, int j){
    int A,B;
    if(ELMT(MatriksKulkas(*K), i ,j) != 0){
        printf("\nMakanan tidak bisa diisi di lokasi tersebut.\n");
    } else {
        boolean check = true;
        for(int x = i; x < i + A; x++){
            for(int y = j; y < j + B; y++){
                if(ELMT(MatriksKulkas(*K), x ,y) != 0){
                    check = false;
                    break
                }
            }
            if(!check){
                break;
            }
        }
        if(check){
            int ID = getID(M);
            for(int x = i; x < i + A; x++){
                for(int y = j; y < j + B; y++){
                    ELMT(MatriksKulkas(*K), x ,y) = ID;
                }
            }
            JumlahMakanan(Kulkas(*K)) += 1;
            Makanan(Kulkas(*K), JumlahMakanan(Kulkas(*K)) - 1) = M;
        } else {
            printf("\nMakanan tidak bisa diisi di lokasi tersebut.\n");
        }
    }
}

void deleteKulkas(Kulkas *K, int ID);

/* ********** KELOMPOK TULIS ********** */
void displayKulkas(Kulkas K){
    printf("\n===============KULKAS PEMAIN===============\n");
    for(int i = 0; i < ROW_EFF(MatriksKulkas(K)) + 2; i++) {
        for(int j = 0; j < COL_EFF(MatriksKulkas(K)) + 2; j++) {
            if (i == 0 || i == ROW_EFF(MatriksKulkas(K)) + 1 || j == 0 || j == COL_EFF(MatriksKulkas(K)) + 1){
                printf("* ");
            } else {
                printf("%d ",ELMT(MatriksKulkas(K), i, j));
            }
        }
        printf("\n");
    }
}