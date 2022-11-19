#include <stdio.h>
#include <stdlib.h>
#include "makanan.h"

// cd src/lib/adt/sederhana/makanan
// gcc main_makanan.c makanan.c ../time/time.c ../../notifikasi/notifikasi.c ../../wordmachine/wordmachine.c ../../wordmachine/charmachine.c ../../wordfilemachine/wordfilemachine.c ../../wordfilemachine/charfilemachine.c ../../tree/tree.c -o ../../../../../build/lib/adt/sederhana/main_makanan

int main(){
	// INISIASI MAKANAN FOOD
	Makanan Food;
	TIME WK, LP, PO;

	// MELAKUKAN CreateMakanan
	printf("/* Melakukan CreateMakanan */\n");
	Word yummy = CreateWord("Yummy", 5);
	CreateTime(&WK, 1, 0, 0);
	CreateTime(&LP, 2, 10, 0);
	CreateTime(&PO, 0, 20, 0);
	CreateMakanan(&Food, 1, 3, yummy, WK, LP, PO, 2, 3);
	printf("\n");

	// MELAKUKAN TulisMakanan
	printf("/* Melakukan TulisMakanan */\n");
	TulisMakanan(Food);
	printf("\n");

	// MELAKUKAN getID
	printf("/* Melakukan getID */\n");
	int ID = getID(Food);
	printf("ID dari Makanan tersebut adalah %d\n", ID);
	printf("\n");

	// MELAKUKAN getLokasi
	printf("/* Melakukan getLokasi */\n");
	Word namaLokasi;
	Word Mix = CreateWord("Mix", 3);
    Word Chop = CreateWord("Chop", 4);
    Word Fry = CreateWord("Fry", 3);
    Word Boil = CreateWord("Boil", 4);
	Word Buy = CreateWord("Buy", 3);
	int lokasi = getLokasi(Food);
	if(lokasi == 3){
		namaLokasi = Buy;
	} else if (lokasi == 9){
		namaLokasi = Mix;
	} else if (lokasi == 10){
		namaLokasi = Chop;
	} else if (lokasi == 11){
		namaLokasi = Fry;
	} else if (lokasi == 12){
		namaLokasi = Boil;
	}
	printf("Lokasi dari Makanan tersebut adalah ");
	PrintWord(namaLokasi);
	printf("\n\n");

	// MELAKUKAN getWK
	printf("/* Melakukan getWK */\n");
	WK = getWK(Food);
	printf("Waktu kedaluwarsa dari Makanan tersebut adalah ");
	TulisTIME(WK);
	printf("\n");
	printf("\n");

	// MELAKUKAN getLP
	printf("/* Melakukan getLP */\n");
	LP = getLP(Food);
	printf("Lama Pengiriman dari Makanan tersebut adalah ");
	TulisTIME(LP);
	printf("\n");
	printf("\n");

	// INISIASI LIST MAKANAN M
	ListMakanan M;

	// INISIASI PATH KONFIGURASI FILE MAKANAN
	char fileName[100] = "config/makanan.txt";

	// MELAKUKAN MEMBACA MAKANAN
	printf("/* Melakukan BacaMakanan */\n");
	M = BacaMakanan(fileName);
	printf("\n");

	// MENAMPILKAN LIST MAKANAN DARI KONFIGURASI FILE
	printf("/* Melakukan TulisListMakanan */\n");
	printf("\nBerikut adalah contoh output dari TulisListMakanan\n");
	TulisListMakanan(M, JumlahMakanan(M));
	printf("\n");
	int n;
    printf("\nKetik 0 untuk exit. ");
    scanf("%d", &n); 
}