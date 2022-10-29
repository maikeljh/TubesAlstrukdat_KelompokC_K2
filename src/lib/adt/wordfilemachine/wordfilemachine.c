/* File: wordmachine.h */
/* Definisi Word Machine: Model Akuisisi Versi I */

#include "wordfilemachine.h"
#include <math.h>


/* State Mesin Word */
WordFile currentWordFile;

void IgnoreBlanksFile()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK */
{
   while (currentCharFile == BLANK) {
      advCharFile();
   }
}

void startWordFile(char fileName[])
/* I.S. : currentCharFile sembarang
   F.S. : currentWordFile adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
{
   startCharFile(fileName);
   IgnoreBlanksFile();
   CopyWordFile();
   
}

void advWordFile()
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisi*/
{
   CopyWordFile();
   IgnoreBlanksFile();
}


void CopyWordFile()
/* Mengakuisisi kata, menyimpan dalam currentWordFile
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
   IgnoreBlanksFile();
   currentWordFile.Length = 0;
   while (currentCharFile != BLANK && currentCharFile != '\n') {
      currentWordFile.TabWord[currentWordFile.Length] = currentCharFile;
      currentWordFile.Length++;
      advCharFile();
   }
}

boolean isKataFileSama(WordFile W1, WordFile W2){
/* Mengembalikan true jika W1 memiliki length yang sama dengan W2 dan
   W1 memiliki TabWord yang sama dengan W2 */

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

WordFile CreateWordFile(char word[], int length){
/* Mengembalikan sebuah WordFile yang memiliki TabWord berisi word dan memiliki
   Length yaitu length */

   WordFile Result;
    for(int i = 0; i < length; i++){
        Result.TabWord[i] = word[i];
    }
    Result.Length = length;
    return Result;
}


