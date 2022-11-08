/* File makanan.c */

#include <stdio.h>
#include <stdlib.h>
#include "makanan.h"
#include "../../wordmachine/wordmachine.h"
#include "../../wordmachine/charmachine.h"
#include "../time/time.h"

void CreateMakanan(Makanan *M, int id, int loc, Word Nama, TIME wk, TIME lp, TIME Pengolahan){
/* Membuat suatu makanan dengan id, location, nama, waktu kedaluwarsa, dan waktu delivery yang terdefinisi */
/* I.S. Makanan M sembarang, id, loc, Nama, wk, dan lp terdefinisi */
/* F.S. Terbuatnya makanan M dengan masukkan sesuai argumen */

	int i;
	ID(*M) = id;
	Nama(*M) = Nama;
	Kedaluwarsa(*M) = wk;
	Pengiriman(*M) = lp;
    Lokasi(*M) = loc;
	Pengolahan(*M) = Pengolahan;
}

int getID(Makanan M){
	/* Mengembalikan ID dari Makanan M */

	return ID(M);
}
int getLokasi(Makanan M){
	/* Mengembalikan Lokasi dari Makanan M */

	return Lokasi(M);
}
TIME getWK(Makanan M){
	/* Mengembalikan waktu kedaluwarsa dari Makanan M */

	return Kedaluwarsa(M);
}
TIME getLP(Makanan M){
	/* Mengembalikan waktu delivery dari Makanan M */

	return Pengiriman(M);
}

TIME getPengolahan(Makanan M){
	/* Mengembalikan waktu delivery dari Makanan M */

	return Pengolahan(M);
}

void TulisMakanan(Makanan M){
/* Menuliskan makanan ke layar yang berisi detail lengkap mengenai makanan tersebut */
/* I.S. Makanan M terdefinisi */
/* F.S. Tampilnya informasi detail mengenai Makanan M */

	printf("ID Makanan 			: %d\n", ID(M));
	printf("Nama Makanan 			: ");
	PrintWord(Nama(M));
	printf("\n");
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
	printf("\n");
	printf("Waktu Kedaluwarsa Makanan	: %d %d %d\n", DayWK(M), HourWK(M), MinuteWK(M));
	printf("Lama Pengiriman Makanan		: %d %d %d\n", DayLP(M), HourLP(M), MinuteLP(M));
	printf("Lama Pengolahan Makanan		: %d %d %d\n", DayPengolahan(M), HourPengolahan(M), MinutePengolahan(M));
}

ListMakanan BacaMakanan(char fileName[]){
	/* Membaca list makanan dari konfigurasi file dan mengembalikannya sebagai list of makanan */

	int ID;
	Word NamaMakanan;
	int location;
	Makanan Food;
	ListMakanan L;
	int indexMakanan = 0;
	startWordFile(fileName);
	int N = wordToInt(currentWordFile);
	JumlahMakanan(L) = N;
	advCharFile();
	advWordFile();
	for(int i = 0; i <= N; i++){
		ID = wordToInt(currentWordFile);
		advCharFile();
		advWordFile();
		int idxNama = 0;
		int EHH, EMM, ESS;
		int DHH, DMM, DSS;
		int PHH, PMM, PSS;
		while(currentCharFile != '\n'){
			for (int i = 0; i < currentWordFile.Length; i++){
				NamaMakanan.TabWord[idxNama] = currentWordFile.TabWord[i];
				idxNama++;
			}
			NamaMakanan.TabWord[idxNama] = ' ';
			idxNama++;
			advWordFile();
		}
		for (int i = 0; i < currentWordFile.Length; i++){
			NamaMakanan.TabWord[idxNama] = currentWordFile.TabWord[i];
			idxNama++;
		}
		NamaMakanan.Length = idxNama;
		
		advCharFile();
		advWordFile();
		
		EHH = wordToInt(currentWordFile);
		advWordFile();

		EMM = wordToInt(currentWordFile);
		advWordFile();

		ESS = wordToInt(currentWordFile);
		advCharFile();
		advWordFile();

		DHH = wordToInt(currentWordFile);
		advWordFile();

		DMM = wordToInt(currentWordFile);
		advWordFile();
		
		DSS = wordToInt(currentWordFile);
		advCharFile();
		advWordFile();

		PHH = wordToInt(currentWordFile);
		advWordFile();

		PMM = wordToInt(currentWordFile);
		advWordFile();
		
		PSS = wordToInt(currentWordFile);
		advCharFile();
		advWordFile();

		WordFile Mix = CreateWordFile("Mix", 3);
    	WordFile Chop = CreateWordFile("Chop", 4);
    	WordFile Fry = CreateWordFile("Fry", 3);
    	WordFile Boil = CreateWordFile("Boil", 4);
		WordFile Buy = CreateWordFile("Buy", 3);
		if(isKataFileSama(currentWordFile, Buy)){
			location = 3;
		} else if(isKataFileSama(currentWordFile, Mix)){
			location = 9;
		} else if(isKataFileSama(currentWordFile, Chop)){
			location = 10;
		} else if(isKataFileSama(currentWordFile, Fry)){
			location = 11;
		} else if(isKataFileSama(currentWordFile, Boil)){
			location = 12;
		} else {
			location = - 1; // Jika lokasi tidak valid
		}
		TIME WK, WD, WP;
		CreateTime(&WK, EHH, EMM, ESS);
		CreateTime(&WD, DHH, DMM, DSS);
		CreateTime(&WP, PHH, PMM, PSS);
		CreateMakanan(&Food, ID, location, NamaMakanan, WK, WD, WP);
		Makanan(L, indexMakanan) = Food;
		indexMakanan += 1;
		advCharFile();
		advWordFile();
	}
	return L;
}

void TulisListMakanan(ListMakanan M, int N){
/* Menuliskan list of makanan ke layar yang berisi detail lengkap mengenai setiap makanan dalam list */
/* I.S. ListMakanan M terdefinisi */
/* F.S. Tampilnya informasi detail mengenai ListMakanan M */

	for(int i = 0; i < N; i++){
		printf("   %d. ", (i+1));
		PrintWord(Nama(Makanan(M, i)));
		printf(" - ");
		if(DayWK(Makanan(M, i)) == 0 && HourWK(Makanan(M, i)) == 0 && MinuteWK(Makanan(M, i)) == 0){
			printf("0 ");
		} else {
			if(DayWK(Makanan(M, i)) > 0){
				printf("%d hari ", DayWK(Makanan(M, i)));
			}
			if(HourWK(Makanan(M, i)) > 0){
				printf("%d jam ", HourWK(Makanan(M, i)));
			}
			if(MinuteWK(Makanan(M, i)) > 0){
				printf("%d menit ", MinuteWK(Makanan(M, i)));
			}
		}
		printf("- ");
		Word namaLokasi;
		int Lokasi = getLokasi(Makanan(M, i));
		Word Mix = CreateWord("MIX", 3);
		Word Chop = CreateWord("CHOP", 4);
		Word Fry = CreateWord("FRY", 3);
		Word Boil = CreateWord("BOIL", 4);
		Word Buy = CreateWord("BUY", 3);
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
		PrintWord(namaLokasi);
		printf(" - ");
		if(DayLP(Makanan(M, i)) == 0 && HourLP(Makanan(M, i)) == 0 && MinuteLP(Makanan(M, i)) == 0){
			printf("0");
		} else {
			if(DayLP(Makanan(M, i)) > 0){
				printf("%d hari ", DayLP(Makanan(M, i)));
			}
			if(HourLP(Makanan(M, i)) > 0){
				printf("%d jam ", HourLP(Makanan(M, i)));
			}
			if(MinuteLP(Makanan(M, i)) > 0){
				printf("%d menit", MinuteLP(Makanan(M, i)));
			}
		}
		printf(" - ");
		if(DayPengolahan(Makanan(M, i)) == 0 && HourPengolahan(Makanan(M, i)) == 0 && MinutePengolahan(Makanan(M, i)) == 0){
			printf("0");
		} else {
			if(DayPengolahan(Makanan(M, i)) > 0){
				printf("%d hari ", DayPengolahan(Makanan(M, i)));
			}
			if(HourPengolahan(Makanan(M, i)) > 0){
				printf("%d jam ", HourPengolahan(Makanan(M, i)));
			}
			if(MinutePengolahan(Makanan(M, i)) > 0){
				printf("%d menit", MinutePengolahan(Makanan(M, i)));
			}
		}
		if(i != N-1){
			printf("\n");
		}
	}
}