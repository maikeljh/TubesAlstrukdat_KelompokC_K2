#include "./adt/notifikasi/notifikasi.h"

void DequeueDelivery (PrioQueueTime *Q, Simulator *S, ListNotif *notif){
/* Proses mengeluarkan makanan kedaluwarsa dari inventory jika ada.*/
    /* KAMUS LOKAL*/
    Makanan M;
    /* ALGORITMA */
    while (TIMEToMenit(Pengiriman(InfoHead(*Q))) <= 0 && !IsEmpty(*Q)){
        Dequeue(Q, &M);
        Enqueue(&Inventory(*S), M);
        AddNotif(notif, 1, M);
    }
}

void Shipping (PrioQueueTime *Q, Simulator *S, ListNotif *N){
/* Proses mengurangi waktu delivery setiap makanan dalam delivery berdasarkan suatu aksi. */
    /* KAMUS LOKAL*/
    int i;
    /* ALGORITMA */
    if(!IsEmpty(*Q)){
        i = Head(*Q);
        while (i != Tail(*Q)){
            Pengiriman(Elmt(*Q, i)) = PrevMenit(Pengiriman(Elmt(*Q, i)));
            i = (i+1) % MaxEl(*Q);
        }
        Pengiriman(Elmt(*Q, i)) = PrevMenit(Pengiriman(Elmt(*Q, i)));
        // Semua telah Decay, pengecekkan makanan expired.
        DequeueDelivery(Q, S, N);
    }
}