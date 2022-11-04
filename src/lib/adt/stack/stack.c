/* File: stack.c */
#include "stack.h"

void CreateUndoStack(Stack *S, Simulator simulator){
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S dengan 1 element */
/* InfoTop dari stack adalah kondisi awal pertama kali seluruh konfigurasi dibaca*/
/* Top = 0*/

// KAMUS LOKAL
// ALGORITMA
    Top(*S) = 0;
    InfoTop(*S) = simulator;
};

void CreateRedoStack(Stack *S) {
/* I.S sembarang*/
/* F.S Membuat stack kosong dengan Top = Nil*/
    Top(*S) = Nil;
}

boolean IsEmptyStack(Stack S){
/* Mengirim true jika Stack kosong: Top = Nil*/

// KAMUS LOKAL
// ALGORITMA
    return (Top(S) == -1);
}

boolean IsFullStack(Stack S){
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

// KAMUS LOKAL
// ALGORITMA
    return (Top(S) == MaxElement - 1);
};


void Push(Stack * S, Simulator simulator){
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

// KAMUS LOKAL
// ALGORITMA
    if(IsEmptyStack(*S)){
        Top(*S) = 0;
    } else {
        Top(*S) += 1;
    }
    InfoTop(*S) = simulator;
};

void Pop(Stack * S, Simulator* X){
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

// KAMUS LOKAL
// ALGORITMA
    *X = InfoTop(*S);
    if(Top(*S) == 0){
        Top(*S) = Nil;
    } else {
        Top(*S) -= 1;
    }
};
