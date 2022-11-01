/* File: wordmachine.c */
/* Definisi Word Machine: Model Akuisisi Versi I */
#include "wordmachine.h"
#include <stdio.h>
#include <stdlib.h>

/* State Mesin Word */
boolean EndWord;
Word currentWord;

void IgnoreBlanks(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

    // KAMUS LOKAL
    // ALGORITMA
    while(currentChar == BLANK){ // Looping ketika current character = ' '
        ADV(); // Maju satu karakter
    }
};


void STARTWORD(){
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

    // KAMUS LOKAL
    // ALGORITMA
    START(); // Menyiapkan pita untuk dibaca
    IgnoreBlanks(); // Mengabaikan BLANK-BLANK
    EndWord = false;
    if(currentChar == MARK){
        EndWord = true; // Jika current character = MARK
    } else {
        CopyWord(); // Jika terdapat kata lain
    }
};


void ADVWORD(){
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

    // KAMUS LOKAL
    // ALGORITMA
    if(currentChar == MARK){
        EndWord = true; // Jika sudah kata terakhir
    } else {
        CopyWord(); // Mengakuisisi kata
        IgnoreBlanks(); // Skip blank-blank
    }
};


void CopyWord(){
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

    // KAMUS LOKAL
    // ALGORITMA
    IgnoreBlanks(); // Skip blank-blank
    currentWord.Length = 0; // Menginisiasi variabel panjang kata
    while(currentChar != BLANK && currentChar != MARK && currentWord.Length < NMax && currentChar != '\n'){ // Looping ketika character != ' ' dan != MARK dan panjang belum melebihi maksimum
        currentWord.TabWord[currentWord.Length] = currentChar;
        currentWord.Length++;
        ADV();
    }  
};

void PrintWord(Word Kata) {
    for(int i = 0; i < Kata.Length; i++){
        printf("%c", Kata.TabWord[i]);
    }
    //printf("\n");
}

void LowerCase(){

/* I.S. currentword terdefinisi sembarang tetapi tidak kosong */

/* F.S. currentword menjadi lowercase di setiap karakternya */

  // KAMUS LOKAL
  int i;
  // ALGORITMA
  for(i = 0; i < currentWord.Length;i++){
    if(currentWord.TabWord[i] >= 65 && currentWord.TabWord[i] <= 90) {
      currentWord.TabWord[i] += 32;
    }
  }
};

Word CreateWord(char word[], int length){
    Word Result;
    for(int i = 0; i < length; i++){
        Result.TabWord[i] = word[i];
    }
    Result.Length = length;
    return Result;
}

boolean isKataSama(Word W1, Word W2){
    boolean Sama = true;
    if(W1.Length != W2.Length){
        Sama = false;
    } else {
        for(int i = 0; i < W1.Length; i++){
            if(W1.TabWord[i] != W2.TabWord[i]){
                Sama = false;
                break;
            }
        }
    }

    return Sama;
}

int wordOnlyToInt (Word str) {
	/* Mengembalikan nilai integer dari WordFile yang dibaca */
	int val = 0;
	int k = 0;
	for (int i= str.Length-1; i >= 0; i--) {
		val += (str.TabWord[i]-48) * pangkatWord(10,k);
		k++;
	}
	return val;
}

int pangkatWord (int x, int y) {
	/* Mengembalikan nilai dari x pangkat y */
	
	int ret = 1;
	for (int i = 1; i <= y; i++){
		ret = ret*x;
	}
	return ret;
}



