/* File: wordmachine.h */
/* Definisi Word Machine: Model Akuisisi Versi I */

#include "wordfilemachine.h"
#include "math.h"


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

