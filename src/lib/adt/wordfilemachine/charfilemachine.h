/* File: charfilemachine.h */

#ifndef __MESIN_KAR_FILE_H_
#define __MESIN_KAR_FILE_H_

#include "../boolean.h"

/* State Mesin */

#define MARK_FILE '.'

extern char currentCharFile;
extern boolean EOPFile;

void startCharFile(char fileName[]);
/* Mesin siap dioperasikan. File disiapkan untuk dibaca.
   Karakter pertama yang ada pada file posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentCharFile adalah karakter pertama pada file */

void advCharFile();
/* File dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentCharFile
   F.S. : currentCharFile adalah karakter berikutnya dari currentCharFile yang lama */

#endif