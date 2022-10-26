/* File: liststatik.c */
/* Body ADT List Statik */

#include "liststatik.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l){
    /* I.S. l sembarang */
    /* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
    /* Proses: Inisialisasi semua elemen List l dengan MARK */

    /* KAMUS LOKAL */
    /* ALGORITMA */
    IdxType idx;
    for(idx = IDX_MIN; idx < CAPACITY; idx++) {
        ELMT(*l, idx) = MARK;
    }
};


/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListStatik l){
    /* Mengirimkan banyaknya elemen efektif List */
    /* Mengirimkan nol jika List kosong */
    
    /* KAMUS LOKAL */
    int count = 0;

    /* ALGORITMA */
    while(ELMT(l, count) != MARK && count < CAPACITY){
        count++;
    }

    return count;
};


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
    return (listLength(l) - 1);
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
    return ((i >= IDX_MIN) && (i < listLength(l)));
};


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatik l){
    /* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */

    /* KAMUS LOKAL */
    /* ALGORITMA */
    return (listLength(l) == 0);
};

/* *** Test List penuh *** */
boolean isFull(ListStatik l){
    /* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

    /* KAMUS LOKAL */
    /* ALGORITMA */
    return (listLength(l) == CAPACITY);
};


/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListStatik *l){
    /* I.S. l sembarang */
    /* F.S. List l terdefinisi */
    /* Proses: membaca banyaknya elemen l dan mengisi nilainya */
    /* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
    /*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
    /*    Jika n tidak valid, tidak diberikan pesan kesalahan */
    /* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
            Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
    /*    Jika n = 0; hanya terbentuk List kosong */

    /* KAMUS LOKAL */
    int n;
    IdxType idx;
    ElType element;

    /* ALGORITMA */
    CreateListStatik(l);

    while(true){
        printf("Silahkan input jumlah elemen : ");
        scanf("%d", &n);
        if(n >= IDX_MIN && n <= CAPACITY){
            break;
        } else {
            printf("Jumlah elemen tidak valid. Silahkan input kembali.\n");
            continue;
        }
    }

    for(idx = 0; idx < n; idx++){
        printf("Elemen ke-%d: ", idx+1);
        scanf("%d", &element);
        ELMT(*l, idx) = element;
    }

};

void printList(ListStatik l){
    /* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
    siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
    karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
    /* I.S. l boleh kosong */
    /* F.S. Jika l tidak kosong: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika List kosong : menulis [] */

    /* KAMUS LOKAL */
    IdxType idx;

    /* ALGORITMA */
    printf("[");

    if(isEmpty(l)){
        printf("]");
    } else {
        for(idx = getFirstIdx(l); idx <= getLastIdx(l); idx++){
            if(idx != getLastIdx(l)){
                printf("%d,", ELMT(l, idx));
            } else {
                printf("%d", ELMT(l, idx));
            }
        }
        printf("]");
    }
};


/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus){
    /* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
    /* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
        indeks yang sama dijumlahkan */
    /* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
        elemen l2 pada indeks yang sama */

    /* KAMUS LOKAL */
    IdxType idx;
    ListStatik newList;

    /* ALGORITMA */
    CreateListStatik(&newList);
    for(idx = IDX_MIN; idx <= getLastIdx(l1); idx++){
        if(plus) {
            ELMT(newList, idx) = ELMT(l1, idx) + ELMT(l2, idx);
        } else {
            ELMT(newList, idx) = ELMT(l1, idx) - ELMT(l2, idx);
        }
    }

    return newList;
};

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListStatik l1, ListStatik l2){
    /* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
    elemennya sama */

    /* KAMUS LOKAL */
    IdxType idx;
    boolean equal = true;

    /* ALGORITMA */
    for(idx = IDX_MIN; idx <= getLastIdx(l1); idx++){
        if(ELMT(l1, idx) != ELMT(l2, idx)){
            equal = false;
            break;
        }
    }

    return equal;
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
            if(ELMT(l, idx) == val){
                return idx;
            }
        }

        return IDX_UNDEF;
    }
};

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListStatik l, ElType *max, ElType *min){
    /* I.S. List l tidak kosong */
    /* F.S. Max berisi nilai terbesar dalam l;
            Min berisi nilai terkecil dalam l */
    
    /* KAMUS LOKAL */
    IdxType idx;

    /* ALGORITMA */
    *max = ELMT(l, IDX_MIN);
    *min = ELMT(l, IDX_MIN);

    for(idx = IDX_MIN + 1; idx <= getLastIdx(l); idx++){
        if(ELMT(l, idx) > *max){
            *max = ELMT(l, idx);
        }
        if(ELMT(l, idx) < *min){
            *min = ELMT(l, idx);
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

    ELMT(*l, getLastIdx(*l)) = MARK;
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
    
    ELMT(*l, getLastIdx(*l)) = MARK;
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
    ELMT(*l, getLastIdx(*l)) = MARK;
};


/* ********** SORTING ********** */
void sortList(ListStatik *l, boolean asc){
    /* I.S. l boleh kosong */
    /* F.S. Jika asc = true, l terurut membesar */
    /*      Jika asc = false, l terurut mengecil */
    /* Proses : Mengurutkan l dengan salah satu algoritma sorting,
    algoritma bebas */

    /* KAMUS LOKAL */
    IdxType i, j, minimal, maksimal;
    ElType tempElmt;

    /* ALGORITMA */
    if(asc){
        for(i = IDX_MIN; i < getLastIdx(*l); i++){
            minimal = i;

            for(j = i + 1; j <= getLastIdx(*l); j++){
                if(ELMT(*l, j) < ELMT(*l, minimal)){
                    minimal = j;
                }
            }

            tempElmt = ELMT(*l, i);
            ELMT(*l, i) = ELMT(*l, minimal);
            ELMT(*l, minimal) = tempElmt;
        }
    } else {
        for(i = IDX_MIN; i < getLastIdx(*l); i++){
            maksimal = i;

            for(j = i + 1; j <= getLastIdx(*l); j++){
                if(ELMT(*l, j) > ELMT(*l, maksimal)){
                    maksimal = j;
                }
            }

            tempElmt = ELMT(*l, i);
            ELMT(*l, i) = ELMT(*l, maksimal);
            ELMT(*l, maksimal) = tempElmt;
        }
    }
};

