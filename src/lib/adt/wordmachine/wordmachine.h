/* File: wordmachine.h */
/* Definisi Word Machine: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../boolean.h"
#include "charmachine.h"

#define NMax 50
#define BLANK ' '

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Word */
extern boolean EndWord;
extern Word currentWord;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void PrintWord(Word Kata);
/* I.S. Kata terdefinisi sembarang tetapi tidak kosong */
/* F.S. Mencetak Kata ke layar */

void LowerCase();
/* I.S. currentword terdefinisi sembarang tetapi tidak kosong */
/* F.S. currentword menjadi lowercase di setiap karakternya */

Word CreateWord(char word[], int length);
/* Mengembalikkan kata yang dibuat dari array of char word dan int length yang terdefinisi */

boolean isKataSama(Word W1, Word W2);
/* Mengembalikan true jika W1 memiliki length yang sama dengan W2 dan
   W1 memiliki TabWord yang sama dengan W2 */

int wordOnlyToInt (Word str);
/* Mengembalikan nilai integer dari WordFile yang dibaca */

int pangkatWord (int x, int y);
/* Mengembalikan nilai dari x pangkat y */

#endif