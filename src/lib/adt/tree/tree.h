/* ADT Pohon N-Ary */
/* Implementasi dengan menggunakan pointer */

#ifndef _TREE_H_
#define _TREE_H_

/* Modul lain yang digunakan : */
#include "../boolean.h"
#include "../wordfilemachine/wordfilemachine.h"
#include "../sederhana/makanan/makanan.h"

/* *** Definisi Type Pohon Biner *** */
/* typedef int infotype; */
typedef struct Node *addrNode;
typedef struct Node{
    int ID;
    int children;
    addrNode firstChild;
    addrNode nextSibling;
} Node;

/* Definisi Pohon N-Ary : */
/* Pohon N-Ary kosong : P = NULL */
typedef addrNode Tree;
typedef int infotype;
/* *** PROTOTYPE *** */

/* *** Selektor *** */
#define Akar(P) (P)->ID
#define BanyakChild(P) (P)->children
#define FirstChild(P) (P)->firstChild
#define Sibling(P) (P)->nextSibling

/* *** Konstruktor *** */
Tree AlokasiTree(infotype Akar, int N, addrNode Child[]);
/* Menghasilkan sebuah pohon N-Ary dari Akar, N, dan array Child, jika alokasi berhasil */
/* Menghasilkan pohon kosong (NULL) jika alokasi gagal */

void MakeTree(infotype Akar, int N, addrNode Child[], Tree *P);
/* I.S. Akar, N, Child terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P) = Akar, BanyakChild(P) = N, FirstChild(P), Sibling(P), dst = Child[i] jika Child[i] tidak NULL
		jika alokasi berhasil. P = NULL jika alokasi gagal. */

/* Manajemen Memory */
addrNode AlokNode(infotype X);
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak NULL, dan misalnya menghasilkan P, 
  maka Akar(P) = X, BanyakChild(P) = 0, FirstChild(P) = NULL , dan Sibling(P) = NULL */
/* Jika alokasi gagal, mengirimkan NULL */

void DealokNode(addrNode P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */


/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(Tree P);
/* Mengirimkan true jika P adalah pohon N-Ary kosong */

/* *** Traversal *** */
void PrintTree(Tree P);
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar dan child-child dari simpul P. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon pertama (B()()) dan subpohon kedua (C()()) */

/* *** Searching *** */
Tree SearchTree(Tree P, int ID);
/* Mengembalikkan Tree yang memiliki akar = ID */

/* *** Operasi lain *** */
void AddDaunByID(Tree *P, infotype ID, infotype X);
/* I.S. P tidak kosong, X adalah salah satu daun Pohon N-Ary P */
/* F.S. P bertambah simpulnya dengan X sebagai child dari P */

void insertTree(Tree *P, Tree newP);
/* I.S. P dan newP tidak kosong */
/* F.S. P bertambah simpulnya dengan simpul yang memiliki nilai sama dengan akar newP */

Tree mergeResep(Tree P[], int N);
/* Melakukan merging tree-tree resepnya yang sudah dibuat dari konfigurasi file */

Tree BacaResep(char fileName[]);
/* Melakukan baca resep dari file konfigurasi */

int indexOfAkar(Tree P[], int N);
/* Mencari indeks elemen array of Tree yang merupakan node utama (Akar) dari tree */

void TulisResep(ListMakanan M, Tree Resep);
/* I.S. M dan Resep terdefinisi */
/* F.S. Mencetak Resep dari kumpulan makanan yang dapat dibuat */

ListMakanan ListResep(ListMakanan M, Tree Resep, Word Kind);
/* Mengembalikkan list makanan yang berisi makanan-makanan yang dapat dibuat dengan action Kind */

ListMakanan ListResepAll(ListMakanan M, Tree Resep);
/* Mengembalikkan list makanan yang berisi makanan-makanan yang terdapat pada resep */

void TulisResepKind(ListMakanan M, Tree Resep, Word Kind);
/* Mencetak list makanan yang dapat dibuat dengan action Kind */

#endif