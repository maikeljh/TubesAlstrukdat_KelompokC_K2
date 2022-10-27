/* File makanan.c */
/* Algoritma Makanan */


#include <stdio.h>
#include <stdlib.h>
#include "makanan.h"
#include "../../../commandparser.c"

/*
#define ID(m) (m).ID
#define Nama(m) (m).Nama
#define Kedaluwarsa(m) (m).WK
#define Pengiriman(m) (m).LP
#define JamWK(m) (m).WK.HH
#define MenitWK(m) (m).WK.MM
#define DetikWK(m) (m).WK.SS
#define JamLP(m) (m).LP.HH
#define MenitLP(m) (m).LP.MM
#define DetikLP(m) (m).LP.SS
*/
void CreateMakanan(Makanan *M, int id, int loc, Word Nama, TIME wk, TIME lp){
/* Membuat suatu makanan */
	/* KAMUS LOKAL*/
	int i;
	ID(*M) = id;
	Nama(*M) = Nama;
	Kedaluwarsa(*M) = wk;
	Pengiriman(*M) = lp;
    Lokasi(*M) = loc;

}

int getID(Makanan M){
	return ID(M);
}
int getLokasi(Makanan M){
	return Lokasi(M);
}
TIME getWK(Makanan M){
	return Kedaluwarsa(M);
}
TIME getLP(Makanan M){
	return Pengiriman(M);
}

void TulisMakanan(Makanan M){
	printf("ID Makanan 			: %d\n", ID(M));
	printf("Nama Makanan 			: ");
	PrintWord(Nama(M));
	Word namaLokasi;
	int Lokasi = getLokasi(M);
	Word Mix = CreateWord("Mix", 3);
    Word Chop = CreateWord("Chop", 4);
    Word Fry = CreateWord("Fry", 3);
    Word Boil = CreateWord("Boil", 4);
	Word Buy = CreateWord("Buy", 3);
	if(Lokasi == 3){
		namaLokasi = Buy;
	} else if (Lokasi == 9){
		namaLokasi = Mix;
	} else if (Lokasi == 10){
		namaLokasi = Chop;
	} else if (Lokasi == 11){
		namaLokasi = Fry;
	} else if (Lokasi == 12){
		namaLokasi = Boil;
	}
	printf("Lokasi Makanan			: ");
	PrintWord(namaLokasi);
	printf("Waktu Kedaluwarsa Makanan	: %d %d %d\n", JamWK(M), MenitWK(M), DetikWK(M));
	printf("Lama Pengiriman Makanan		: %d %d %d\n", JamLP(M), MenitLP(M), DetikLP(M));
}

int BacaMakanan(Makanan *M){
	int indexMakanan = 0;
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		int ID;
		Word NamaMakanan;
		int location;
		Makanan Food;
		scanf("%d\n", &ID);
		STARTWORD();
		int idxNama = 0;
		int EHH, EMM, ESS;
		int DHH, DMM, DSS;
		while(currentChar != '\n'){
			for (int i = 0; i < currentWord.Length; i++){
				NamaMakanan.TabWord[idxNama] = currentWord.TabWord[i];
				idxNama++;
			}
			NamaMakanan.TabWord[idxNama] = ' ';
			idxNama++;
			ADVWORD();
		}
		for (int i = 0; i < currentWord.Length; i++){
			NamaMakanan.TabWord[idxNama] = currentWord.TabWord[i];
			idxNama++;
		}
		NamaMakanan.Length = idxNama;
		scanf("%d %d %d", &EHH, &EMM, &ESS);
		scanf("%d %d %d\n", &DHH, &DMM, &DSS);
		STARTWORD();
		Word Mix = CreateWord("Mix", 3);
    	Word Chop = CreateWord("Chop", 4);
    	Word Fry = CreateWord("Fry", 3);
    	Word Boil = CreateWord("Boil", 4);
		Word Buy = CreateWord("Buy", 3);
		if(isKataSama(currentWord, Buy)){
			location = 3;
		} else if(isKataSama(currentWord, Mix)){
			location = 9;
		} else if(isKataSama(currentWord, Chop)){
			location = 10;
		} else if(isKataSama(currentWord, Fry)){
			location = 11;
		} else if(isKataSama(currentWord, Boil)){
			location = 12;
		} else {
			location = - 1; // Jika lokasi tidak valid
		}
		TIME WK, WD;
		CreateTime(&WK, EHH, EMM, ESS);
		CreateTime(&WD, DHH, DMM, DSS);
		CreateMakanan(&Food, ID, location, NamaMakanan, WK, WD);
		M[indexMakanan] = Food;
		indexMakanan++;
	}
	return N;
}

void TulisListMakanan(Makanan M[], int N){
	printf("\nList Bahan dan Makanan :\n\n");
	for(int i = 0; i < N; i++){
		printf("Makanan ke-%d :\n", i);
		TulisMakanan(M[i]);
		printf("\n");
	}
}