/* File: liststatik.c */
/* Body ADT List Statik */

#include "liststatik.h"

#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l){
    /* I.S. l sembarang */
    /* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
    /* Proses: Terbentuk List l dengan length 0 */

    /* KAMUS LOKAL */
    /* ALGORITMA */
    Length(*l) = 0;
};

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListStatik l){
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l pertama */

    /* KAMUS LOKAL */
    /* ALGORITMA */
    return IDX_MIN;
};

IdxType getLastIdx(ListStatik l){
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l terakhir */

    /* KAMUS LOKAL */
    /* ALGORITMA */
    if(isEmpty(l)){
        return 0;
    } else {
        return (Length(l) - 1);
    }
};

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListStatik l, IdxType i){
    /* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
    /* yaitu antara indeks yang terdefinisi utk container*/

    /* KAMUS LOKAL */
    /* ALGORITMA */
    return ((i >= IDX_MIN) && (i < CAPACITY));
};

boolean isIdxEff(ListStatik l, IdxType i){
    /* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
    /* yaitu antara 0..length(l)-1 */

    /* KAMUS LOKAL */
    /* ALGORITMA */
    return ((i >= IDX_MIN) && (i < Length(l)));
};

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatik l){
    /* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */

    /* KAMUS LOKAL */
    /* ALGORITMA */
    return (Length(l) == 0);
};

/* *** Test List penuh *** */
boolean isFull(ListStatik l){
    /* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

    /* KAMUS LOKAL */
    /* ALGORITMA */
    return (Length(l) == CAPACITY);
};

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListStatik l, ElType val){
    /* Search apakah ada elemen List l yang bernilai val */
    /* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
    /* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
    /* Skema Searching yang digunakan bebas */

    /* KAMUS LOKAL */
    IdxType idx;

    /* ALGORITMA */
    if(isEmpty(l)){
        return IDX_UNDEF;
    } else {
        for(idx = IDX_MIN; idx <= getLastIdx(l); idx++){
            if(ID(ELMT(l, idx)) == ID(val)){
                return idx;
            }
        }

        return IDX_UNDEF;
    }
};

void printList(ListStatik l){
    /* Proses : Menuliskan isi List dengan traversal */
    /* I.S. l boleh kosong */
    /* F.S. Menulis Isi dari List */

    /* KAMUS LOKAL */
    IdxType idx;

    /* ALGORITMA */
    if(isEmpty(l)){
        printf("List kosong.");
    } else {
        for(idx = getFirstIdx(l); idx <= getLastIdx(l); idx++){
            TulisMakanan(ELMT(l, idx));
            printf("\n");
        }
    }
};

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst(ListStatik *l, ElType val){
    /* Proses: Menambahkan val sebagai elemen pertama List */
    /* I.S. List l boleh kosong, tetapi tidak penuh */
    /* F.S. val adalah elemen pertama l yang baru */

    /* KAMUS LOKAL */
    IdxType idx;

    /* ALGORITMA */
    if(isEmpty(*l)){
        ELMT(*l, IDX_MIN) = val;
    } else {
        for(idx = getLastIdx(*l) + 1; idx > IDX_MIN; idx--){
            ELMT(*l, idx) = ELMT(*l, idx-1);
        }
        ELMT(*l, IDX_MIN) = val;
    }
    Length(*l) += 1;
};

/* *** Menambahkan elemen pada index tertentu *** */
void insertAt(ListStatik *l, ElType val, IdxType idx){
    /* Proses: Menambahkan val sebagai elemen pada index idx List */
    /* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
    /* F.S. val adalah elemen yang disisipkan pada index idx l */

    /* KAMUS LOKAL */
    IdxType i;

    /* ALGORITMA */
    for(i = getLastIdx(*l) + 1; i > idx; i--){
            ELMT(*l, i) = ELMT(*l, i-1);
    }

    ELMT(*l, idx) = val;
    Length(*l) += 1;
};


/* *** Menambahkan elemen terakhir *** */
void insertLast(ListStatik *l, ElType val){
    /* Proses: Menambahkan val sebagai elemen terakhir List */
    /* I.S. List l boleh kosong, tetapi tidak penuh */
    /* F.S. val adalah elemen terakhir l yang baru */

    /* KAMUS LOKAL */
    /* ALGORITMA */
    if(isEmpty(*l)) {
        ELMT(*l, IDX_MIN) = val;
    } else {
        ELMT(*l, getLastIdx(*l) + 1) = val;
    }
    Length(*l) += 1;
};


/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirst(ListStatik *l, ElType *val){
    /* Proses : Menghapus elemen pertama List */
    /* I.S. List tidak kosong */
    /* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
    /*      Banyaknya elemen List berkurang satu */
    /*      List l mungkin menjadi kosong */

    /* KAMUS LOKAL */
    IdxType idx;

    /* ALGORITMA */
    *val = ELMT(*l, IDX_MIN);

    for(idx = IDX_MIN; idx < getLastIdx(*l); idx++){
        ELMT(*l, idx) = ELMT(*l, idx + 1);
    }

    Length(*l) -= 1;
};

/* *** Menghapus elemen pada index tertentu *** */
void deleteAt(ListStatik *l, ElType *val, IdxType idx){
    /* Proses : Menghapus elemen pada index idx List */
    /* I.S. List tidak kosong, idx adalah index yang valid di l */
    /* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
    /*      Banyaknya elemen List berkurang satu */
    /*      List l mungkin menjadi kosong */

    /* KAMUS LOKAL */
    IdxType i;

    /* ALGORITMA */
    *val = ELMT(*l, idx);

    for(i = idx; i < getLastIdx(*l); i++){
        ELMT(*l, i) = ELMT(*l, i + 1);
    }
    
    Length(*l) -= 1;
};

/* *** Menghapus elemen terakhir *** */
void deleteLast(ListStatik *l, ElType *val){
    /* Proses : Menghapus elemen terakhir List */
    /* I.S. List tidak kosong */
    /* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
    /*      Banyaknya elemen List berkurang satu */
    /*      List l mungkin menjadi kosong */

    /* KAMUS LOKAL */
    /* ALGORITMA */
    *val = ELMT(*l, getLastIdx(*l));
    Length(*l) -= 1;
};