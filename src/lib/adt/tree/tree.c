/* ADT Pohon N-Ary */
/* Implementasi dengan menggunakan pointer */

#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

/* *** Konstruktor *** */
Tree AlokasiTree(infotype Akar, int N, addrNode Child[]){
    /* Menghasilkan sebuah pohon N-Ary dari Akar, N, dan array Child, jika alokasi berhasil */
    /* Menghasilkan pohon kosong (NULL) jika alokasi gagal */

    Tree T = (Tree) malloc(sizeof(Node));
    if (T != NULL){
        Akar(T) = Akar;
        BanyakChild(T) = N;
        if(N != 0){
            FirstChild(T) = Child[0];
            int i = 1;
            addrNode P = FirstChild(T);
            while(i < N){
                Sibling(P) = Child[i];
                P = Sibling(P);
                i++;
            }
        } else {
            FirstChild(T) = NULL;
            Sibling(T) = NULL;
        }
        return T;
    } else {
        return NULL;
    }
};

void MakeTree(infotype Akar, int N, addrNode Child[], Tree *P){
    /* I.S. Akar, N, Child terdefinisi. P Sembarang */
    /* F.S. Membentuk pohon P dengan Akar(P) = Akar, BanyakChild(P) = N, FirstChild(P), Sibling(P), dst = Child[i] jika Child[i] tidak NULL
        jika alokasi berhasil. P = NULL jika alokasi gagal. */

    *P = AlokasiTree(Akar, N, Child);
};


/* Manajemen Memory */
addrNode AlokNode(infotype X){
    /* Mengirimkan addrNode hasil alokasi sebuah elemen */
    /* Jika alokasi berhasil, maka addrNode tidak NULL, dan misalnya menghasilkan P, 
     maka Akar(P) = X, BanyakChild(P) = 0, FirstChild(P) = NULL , dan Sibling(P) = NULL */
    /* Jika alokasi gagal, mengirimkan NULL */

    addrNode P = (addrNode) malloc(sizeof(Node));
    if (P != NULL){
        Akar(P) = X;
        BanyakChild(P) = 0;
        FirstChild(P) = NULL;
        Sibling(P) = NULL;
        return P;
    }
    else {
        return NULL;
    }
};

void DealokNode(addrNode P){
    /* I.S. P terdefinisi */
    /* F.S. P dikembalikan ke sistem */
    /* Melakukan dealokasi/pengembalian addrNode P */

    free(P);
};


/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(Tree P){
    /* Mengirimkan true jika P adalah pohon N-Ary kosong */

    return P == NULL;
};

/* *** Traversal *** */
void PrintTree(Tree P){
    /* I.S. P terdefinisi */
    /* F.S. Semua simpul P sudah dicetak secara preorder: akar dan child-child dari simpul P. 
    Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
    Pohon kosong ditandai dengan ().
    Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
    /* Contoh: 
    (A()()) adalah pohon dengan 1 elemen dengan akar A
    (A(B()())(C()())) adalah pohon dengan akar A dan subpohon pertama (B()()) dan subpohon kedua (C()()) */
    
    printf("(");
    if (!IsTreeEmpty(P)){
        printf("%d", Akar(P));
        addrNode P1 = FirstChild(P);
        for(int i = 0; i < BanyakChild(P); i++){
            PrintTree(P1);
            P1 = Sibling(P1);
        }
    }
    printf(")");
};

/* *** Searching *** */
boolean SearchTree(Tree P, infotype X);
/* Mengirimkan true jika ada node dari P yang bernilai X */

/* *** Operasi lain *** */
void AddDaunByID(Tree *P, infotype ID, infotype X){
    /* I.S. P tidak kosong, X adalah salah satu daun Pohon N-Ary P */
    /* F.S. P bertambah simpulnya dengan X sebagai child dari P */
    
    if(!IsTreeEmpty(*P)){
        boolean found = false;
        if(Akar(*P) == ID){
            BanyakChild(*P) += 1;
            addrNode PTemp = AlokNode(X);
            if(FirstChild(*P) == NULL){
                FirstChild(*P) = PTemp;
            } else {
                addrNode PTempX = FirstChild(*P);
                while(Sibling(PTempX) != NULL){
                    PTempX = Sibling(PTempX);
                }
                Sibling(PTempX) = PTemp;
            }
            found = true;
        } else {
            if(BanyakChild(*P) != 0){
                addrNode PTemp = FirstChild(*P);
                AddDaunByID(&PTemp, ID, X);
                int i = 1;
                while (i < BanyakChild(*P) && !found){
                    PTemp = Sibling(PTemp);
                    AddDaunByID(&PTemp, ID, X);
                    i++;
                }
            }
        }
    }
};

void insertTree(Tree *P, Tree newP){
    /* I.S. P dan newP tidak kosong */
    /* F.S. P bertambah simpulnya dengan simpul yang memiliki nilai sama dengan akar newP */

    if(!IsTreeEmpty(*P)){
        if(Akar(*P) == Akar(newP)){
            BanyakChild(*P) = BanyakChild(newP);
            FirstChild(*P) = FirstChild(newP);
        } else {
            if(BanyakChild(*P) != 0){
                addrNode PTemp = FirstChild(*P);
                insertTree(&PTemp, newP);
                int i = 1;
                while (i < BanyakChild(*P)){
                    PTemp = Sibling(PTemp);
                    insertTree(&PTemp, newP);
                    i++;
                }
            }
        }
    }
}

Tree mergeResep(Tree P[], int N){
    /* Melakukan merging tree-tree resepnya yang sudah dibuat dari konfigurasi file */
    
    for(int i = 0;i < N-1;i++){
        insertTree(&P[i+1], P[i]);
    }
    return P[N-1];
}