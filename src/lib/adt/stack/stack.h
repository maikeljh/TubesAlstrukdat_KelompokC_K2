/* File : stack.h */

#ifndef stackt_H
#define stackt_H

#include "../boolean.h"
#include "../sederhana/makanan/makanan.h"
#include "../sederhana/simulator/simulator.h"
#include "../sederhana/time/time.h"
#include "../prioqueue/prioqueuetime.h"
#include "../kulkas/kulkas.h"

/* Nil adalah stack dengan elemen kosong . */
#define Nil -1
/* Implementasi dalam bahasa C dengan alokasi statik */
#define MaxElement 100

/* TOP adalah alamat elemen puncak */
typedef int top;   /* indeks Label */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct { 
  Simulator T[MaxElement]; /* tabel penyimpan elemen */
  top TOP;  /* alamat TOP: elemen puncak */
} Stack;

/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxEl-1] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

void CreateUndoStack(Stack *S, Simulator simulator);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S dengan 1 element */
/* InfoTop dari stack adalah kondisi awal pertama kali seluruh file konfigurasi dibaca*/
/* Top = 0*/

void CreateRedoStack(Stack *S);
/* I.S sembarang*/
/* F.S Membuat stack kosong dengan Top = Nil*/

boolean IsEmptyStack(Stack S);
/* Mengirim true jika Stack kosong: Top = Nil*/

boolean IsFullStack(Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

void Push(Stack * S, Simulator simulator);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

void Pop(Stack * S, Simulator* X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

#endif