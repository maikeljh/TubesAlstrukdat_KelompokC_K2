#include "kulkas.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createKulkas(Kulkas *K){
    ListMakananKulkas M;
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
    int A = Lebar(M);
    int B = Panjang(M);
    if(ELMT(MatriksKulkas(*K), i ,j) != 0){
        printf("\nMakanan tidak bisa diisi di lokasi tersebut.\n");
    } else {
        boolean check = true;
        if(i < 1 || i > 10 || j < 1 || j > 20 || i + A - 1 > 10 || j + B - 1 > 20){
            check = false;
        } else {
            for(int x = i; x < i + A; x++){
                for(int y = j; y < j + B; y++){
                    if(ELMT(MatriksKulkas(*K), x ,y) != 0){
                        check = false;
                        break;
                    }
                }
                if(!check){
                    break;
                }
            }
        }
        if(check){
            int ID = ID(M);
            for(int x = i; x < i + A; x++){
                for(int y = j; y < j + B; y++){
                    ELMT(MatriksKulkas(*K), x ,y) = ID;
                }
            }
            JumlahMakanan(Kulkas(*K)) += 1;
            MakananKulkas(Kulkas(*K), JumlahMakanan(Kulkas(*K)) - 1) = M;
            Absis(PointMakananKulkas(Kulkas(*K), JumlahMakanan(Kulkas(*K)) - 1)) = j;
            Ordinat(PointMakananKulkas(Kulkas(*K), JumlahMakanan(Kulkas(*K)) - 1)) = i;
        } else {
            printf("\nMakanan tersebut tidak bisa diisi di lokasi (%d,%d).\n", i, j);
        }
    }
}

void deleteKulkas(Kulkas *K, int ID, Makanan *Out){
    boolean isValid = false;
    int idx;
    for(int i = 0; i < JumlahMakanan(Kulkas(*K)); i++){
        if(ID(MakananKulkas(Kulkas(*K), i)) == ID){
            isValid = true;
            idx = i;
            *Out = MakananKulkas(Kulkas(*K), i);
            break;
        }
    }
    if(isValid){
        POINT P = PointMakananKulkas(Kulkas(*K), idx);
        for(int x = Ordinat(P); x < Ordinat(P) + Lebar(*Out); x++){
            for(int y = Absis(P); y < Absis(P) + Panjang(*Out); y++){
                ELMT(MatriksKulkas(*K), x ,y) = 0;
            }
        }
        for(int i = idx; i < JumlahMakanan(Kulkas(*K)) - 1; i++){
            ElementKulkas(Kulkas(*K), i) = ElementKulkas(Kulkas(*K), i+1);
        }
        JumlahMakanan(Kulkas(*K)) -= 1;
    } else {
        printf("\nTidak ada makanan dengan ID tersebut.\n");
    }
}

/* ********** KELOMPOK TULIS ********** */
void displayKulkas(Kulkas K){
    printf("\n===============KULKAS PEMAIN===============\n");
    for(int i = 0; i < ROW_EFF(MatriksKulkas(K)) + 2; i++) {
        for(int j = 0; j < COL_EFF(MatriksKulkas(K)) + 2; j++) {
            if (i == 0 || i == ROW_EFF(MatriksKulkas(K)) + 1 || j == 0 || j == COL_EFF(MatriksKulkas(K)) + 1){
                printf("* ");
            } else {
                if(ELMT(MatriksKulkas(K), i, j) == 0){
                    printf("_ ");
                } else {
                    printf("%d ",ELMT(MatriksKulkas(K), i, j));
                }
            }
        }
        printf("\n");
    }
}

void ProsesKulkas(Kulkas *K, Simulator *S){
    displayKulkas(*K);
    while(true){
        printf("\nLIST COMMAND:\n");
        printf("1. INSERT");
        printf("2. TAKE");
    }
}