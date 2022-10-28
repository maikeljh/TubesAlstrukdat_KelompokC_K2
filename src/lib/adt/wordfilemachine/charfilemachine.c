#include "charfilemachine.h"
#include <stdio.h>

char currentCharFile;


static FILE *file;
static int retfile;

void startCharFile(char fileName[])
/* Mesin siap dioperasikan. File disiapkan untuk dibaca.
   Karakter pertama yang ada pada file posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentCharFile adalah karakter pertama pada file */
{
  file = fopen(fileName, "r");
  advCharFile();
}

void advCharFile()
/* File dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentCharFile
   F.S. : currentCharFile adalah karakter berikutnya dari currentCharFile yang lama */
{
  retfile = fscanf(file, "%c", &currentCharFile);
  if(feof(file)){
    fclose(file);
  }
}

// int main (){
//   startCharFile("test.txt");
//   printf("%c", currentCharFile);
// }