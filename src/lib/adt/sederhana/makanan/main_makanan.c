#include <stdio.h>
#include <stdlib.h>
#include "makanan.c"

// gcc main_makanan.c ../../wordfilemachine/wordfilemachine.c ../../wordfilemachine/charfilemachine.c ../time/time.c ../../wordmachine/wordmachine.c ../../wordmachine/charmachine.c -o main_makanan

int main(){
	// INISIASI MAKANAN FOOD
	Makanan Food;
	TIME WK, LP;

	// MELAKUKAN CreateMakanan
	Word yummy = CreateWord("Yummy", 5);
	CreateTime(&WK, 1, 0, 0);
	CreateTime(&LP, 2, 10, 0);
	CreateMakanan(&Food, 1, 3, yummy, WK, LP);
	printf("\n");

	// MELAKUKAN TulisMakanan
	TulisMakanan(Food);
	printf("\n");

	// MELAKUKAN getID
	int ID = getID(Food);
	printf("ID dari Makanan tersebut adalah %d\n", ID);
	printf("\n");

	// MELAKUKAN getLokasi
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
	WK = getWK(Food);
	printf("Waktu kedaluwarsa dari Makanan tersebut adalah ");
	TulisTIME(WK);
	printf("\n");
	printf("\n");

	// MELAKUKAN getWK
	LP = getLP(Food);
	printf("Lama Pengiriman dari Makanan tersebut adalah ");
	TulisTIME(LP);
	printf("\n");
	printf("\n");

	// MELAKUKAN pangkat
	printf("2 pangkat 3 bernilai %d\n", pangkat(2,3));
	printf("\n");

	// MELAKUKAN wordToInt
	WordFile W = CreateWordFile("20", 2);
	int number = wordToInt(W);
	printf("Nilai dari kata tersebut adalah %d\n", number);
	printf("\n");

	// INISIASI LIST MAKANAN M
	ListMakanan M;

	// INISIASI PATH KONFIGURASI FILE MAKANAN
	char fileName[100] = "../../../../../config/makanan.txt";

	// MELAKUKAN MEMBACA MAKANAN
	M = BacaMakanan(fileName);

	// MENAMPILKAN LIST MAKANAN DARI KONFIGURASI FILE
	printf("Berikut adalah contoh output dari TulisListMakanan\n", number);
	TulisListMakanan(M, JumlahMakanan(M));
}