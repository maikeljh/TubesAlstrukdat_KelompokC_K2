/* File : prioqueuetime.c */
/* Definisi ADT Priority Queue Char dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut membesar berdasarkan elemen time */

#include "prioqueuetime.h"
#include <stdio.h>
#include <stdlib.h>

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueTime Q){
	/* Mengirim true jika Q kosong: lihat definisi di atas */
	return(Head(Q) == Nil && Tail(Q) == Nil);
}

boolean IsFull (PrioQueueTime Q){
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
	return(NBElmt(Q) == MaxEl(Q));
}

int NBElmt (PrioQueueTime Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

    // KAMUS LOKAL
    int count;

    // ALGORITMA
    if(IsEmpty(Q)){
        count = 0;
    } else {
        if(Tail(Q) >= Head(Q)){
            count = Tail(Q) - Head(Q) + 1;
        } else {
            count = MaxEl(Q) - Head(Q) + Tail(Q) + 1;
        }
    }

    return count;
}


/* *** Kreator *** */
void MakeEmpty (PrioQueueTime * Q, int Max){
	/* I.S. sembarang */
	/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
	/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
	/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
	/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

	(*Q).T = (infotype*)malloc((Max)*sizeof(infotype));
	if ((*Q).T != NULL){
		MaxEl(*Q) = Max;
		Head(*Q) = Nil;
		Tail(*Q) = Nil;
	} else {
		MaxEl(*Q) = 0;
	}
}

/* *** Destruktor *** */
void DeAlokasi(PrioQueueTime * Q){
	/* Proses: Mengembalikan memori Q */
	/* I.S. Q pernah dialokasi */
	/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

	MaxEl(*Q) = 0;
	Head(*Q) = Nil;
	Tail(*Q) = Nil;
	free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueTime * Q, infotype X){
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan time */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */

	if(IsEmpty(*Q)){
		Head(*Q) = 0;
		Tail(*Q) = 0;
		InfoTail(*Q) = X;
	} else {
		Tail(*Q) = (Tail(*Q) + 1) % MaxEl(*Q);
		int time = Time(X);
		int idx = Tail(*Q)-1;
		while(idx != Head(*Q)-1 & time < Time(Elmt(*Q, idx))){
            if(idx == -1){
                idx = MaxEl(*Q) - 1;
            }
            (*Q).T[(idx+1) % MaxEl(*Q)] = (*Q).T[idx];
            idx--;
        }
		(*Q).T[idx+1] = X;
	}
}

void Dequeue (PrioQueueTime * Q, infotype * X){
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

	*X = InfoHead(*Q);

    if(NBElmt(*Q) == 1){
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        Head(*Q) = (Head(*Q) + 1) % MaxEl(*Q);
    }
}

/* Operasi Tambahan */
void PrintPrioQueueTime (PrioQueueTime Q){
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<time-1> <elemen-1>
...
<time-n> <elemen-n>
#
*/
	// KAMUS LOKAL
    int idx = Head(Q);

    // ALGORITMA
    if(IsEmpty(Q)){
        printf("#\n");
    } else {
        while(idx != Tail(Q)){
            if(idx == MaxEl(Q)){
                idx %= MaxEl(Q);
            }
            printf("%d %c\n", Time((Q).T[idx]), Info((Q).T[idx]));
            idx++;
        }
        printf("%d %c\n", Time((Q).T[idx]), Info((Q).T[idx]));
        printf("#\n");
    }
}

