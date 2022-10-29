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

	(*Q).T = (Makanan*)malloc((Max)*sizeof(Makanan));
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
void Enqueue (PrioQueueTime * Q, Makanan X){
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
		int idx = Tail(*Q)-1;
		while(idx != Head(*Q)-1 && TIMEToMenit(Kedaluwarsa(X)) < TIMEToMenit(Kedaluwarsa(Elmt(*Q, idx)))){
            if(idx == -1){
                idx = MaxEl(*Q) - 1;
            }
            Elmt(*Q, (idx+1) % MaxEl(*Q)) = Elmt(*Q, idx);
            idx--;
        }
        Elmt(*Q, idx+1) = X;
	}
}

void Dequeue (PrioQueueTime * Q, Makanan * X){
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

	*X = InfoHead(*Q);

    if(NBElmt(*Q) == 1){
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        int i = HEAD(*Q) % MaxEl(*Q);
        while (i != TAIL(*Q) % MaxEl(*Q)){
            Elmt(*Q, i) = Elmt(*Q, i+1);
            i = (i+1) % MaxEl(*Q);
        }
        TAIL(*Q) = (TAIL(*Q) - 1) % MaxEl(*Q);
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
    int count = 1;
    // ALGORITMA
    if(IsEmpty(Q)){
        printf("#\n");
    } else {
        while(idx != Tail(Q)){
            if(idx == MaxEl(Q)){
                idx %= MaxEl(Q);
            }
            //TulisTIME(Kedaluwarsa((Q).T[idx]));
            // Elmt(Q, idx)
            printf("%d. ", count);
            PrintWord(Nama((Q).T[idx]));
            printf(" -");
            if (Day(Kedaluwarsa(Elmt(Q, idx))) != 0){
                printf(" %d Hari", Day(Kedaluwarsa((Q).T[idx])));
            }
            if (Hour(Kedaluwarsa(Elmt(Q, idx))) != 0){
                printf(" %d Jam", Hour(Kedaluwarsa((Q).T[idx])));
            }
            if (Minute(Kedaluwarsa(Elmt(Q, idx))) != 0){
                printf(" %d Menit", Minute(Kedaluwarsa((Q).T[idx])));
            }
            printf("\n");
            count++;
            idx++;
        }
        printf("%d. ", count);
            PrintWord(Nama((Q).T[idx]));
            printf(" -");
            if (Day(Kedaluwarsa(Elmt(Q, idx))) != 0){
                printf(" %d Hari", Day(Kedaluwarsa((Q).T[idx])));
            }
            if (Hour(Kedaluwarsa(Elmt(Q, idx))) != 0){
                printf(" %d Jam", Hour(Kedaluwarsa((Q).T[idx])));
            }
            if (Minute(Kedaluwarsa(Elmt(Q, idx))) != 0){
                printf(" %d Menit", Minute(Kedaluwarsa((Q).T[idx])));
            }
            printf("\n");
    }
}

int CariMakanan(PrioQueueTime Q, Makanan X, int id){
/* Mencari lokasi makanan (indeks) dalam inventory makanan dengan ID makanan*/
    // KAMUS LOKAL
    int idx;
    boolean found;
    // ALGORITMA 
    found = false;
    idx = HEAD(Q);
    while (!found && idx != TAIL(Q) % MaxEl(Q)){
        if (ID(Elmt(Q, idx) == id)){
            found = true;
        }
        else{
            idx = (idx+1) % MaxEl(Q);
        }
    }
    return idx;
}
void DequeueAt (PrioQueueTime *Q, Makanan * X, int id){
/* Proses: Menghapus X yang memiliki nilai "id" makanan tersebut pada Q. 
/* I.S. Q tidak mungkin kosong, id makanan valid berada di dalam inventory */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; Q mungkin kosong */
    /* KAMUS LOKAL */
    int idx; // idx dari pemilik id makanan.
    /* ALGORITMA */
    idx = CariMakanan(*Q, *X, id);
    if (NbElmt(*Q) == 1){
        HEAD(*Q) = Nil;
        TAIL(*Q) = Nil;
    }
    else /* NbElmt(*Q) > 1*/ {
        if (idx == HEAD(*Q)){
            Dequeue(&*Q, &*X);
        }
        else{
            while (idx != TAIL(*Q) % MaxEl(*Q)){
                Elmt(*Q, idx) = Elmt(*Q, idx+1);
                idx = (idx+1) % MaxEl(*Q); 
            }
            TAIL(*Q) = (TAIL(*Q) - 1) % MaxEl(*Q);
        }
    }
}