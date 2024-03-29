/* File: wordmachine.h */
/* Definisi Word Machine: Model Akuisisi Versi I */

#ifndef __MESINKATA_FILE_H__
#define __MESINKATA_FILE_H__

#include "../boolean.h"
#include "charfilemachine.h"

#define NMax 50
#define BLANK ' '

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} WordFile;

/* State Mesin Word */
extern boolean EndWordFile;
extern WordFile currentWordFile;

void IgnoreBlanksFile();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK */

void startWordFile();
/* I.S. : currentCharFile sembarang
   F.S. : currentWordFile adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void advWordFile();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWordFile();
/* Mengakuisisi kata, menyimpan dalam currentWordFile
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

boolean isKataFileSama(WordFile W1, WordFile W2);
/* Mengembalikan true jika W1 memiliki length yang sama dengan W2 dan
   W1 memiliki TabWord yang sama dengan W2 */

WordFile CreateWordFile(char word[], int length);
/* Mengembalikan sebuah WordFile yang memiliki TabWord berisi word dan memiliki
   Length yaitu length */

int pangkat (int x, int y);
/* Mengembalikan nilai dari x pangkat y */

int wordToInt (WordFile str);
/* Mengembalikan nilai integer dari WordFile yang dibaca */

#endif