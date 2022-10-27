#include <stdio.h>
#include "./adt/wordmachine/wordmachine.h"

// COMMAND AVAILABLE
/*  1. START
    2. EXIT 
    3. BUY 
    4. DELIVERY
    5. MOVE NORTH
    6. MOVE EAST
    7. MOVE WEST 
    8. MOVE SOUTH
    9. MIX
    10. CHOP
    11. FRY
    12. BOIL
    13. WAIT X Y
    14. UNDO
    15. REDO
    16. CATALOG
    17. COOKBOOK
*/

int readCommand(){
    // Mengembalikan nomor command sesuai yang ada di list command di atas.
    
    Word Start = CreateWord("START", 5);
    Word Exit = CreateWord("EXIT", 4);
    Word Buy = CreateWord("BUY", 3);
    Word Delivery = CreateWord("DELIVERY", 8);
    Word Move = CreateWord("MOVE", 4);
    Word North = CreateWord("NORTH", 5);
    Word East = CreateWord("EAST", 4);
    Word West = CreateWord("WEST", 4);
    Word South = CreateWord("SOUTH", 5);
    Word Mix = CreateWord("MIX", 3);
    Word Chop = CreateWord("CHOP", 4);
    Word Fry = CreateWord("FRY", 3);
    Word Boil = CreateWord("BOIL", 4);
    Word Wait = CreateWord("WAIT", 4);
    Word Undo = CreateWord("UNDO", 4);
    Word Redo = CreateWord("REDO", 4);
    Word Catalog = CreateWord("CATALOG", 7);
    Word CookBook = CreateWord("COOKBOOK", 8);
    
    STARTWORD();
    if(isKataSama(currentWord, Start)){
        return 1;
    } else if(isKataSama(currentWord, Exit)){
        return 2;
    } else if(isKataSama(currentWord, Buy)){
        return 3;
    } else if(isKataSama(currentWord, Delivery)){
        return 4;
    } else if(isKataSama(currentWord, Move)){
        ADVWORD();
        if(isKataSama(currentWord, North)){
            return 5;
        } else if(isKataSama(currentWord, East)){
            return 6;
        } else if(isKataSama(currentWord, West)){
            return 7;
        } else if(isKataSama(currentWord, South)){
            return 8;
        } else {
            return -1;
        }
    } else if(isKataSama(currentWord, Mix)){
        return 9;
    } else if(isKataSama(currentWord, Chop)){
        return 10;
    } else if(isKataSama(currentWord, Fry)){
        return 11;
    } else if(isKataSama(currentWord, Boil)){
        return 12;
    } else if(isKataSama(currentWord, Wait)){
        return 13; // Perlu Koordinasi Dengan Waktu Permainan
    } else if(isKataSama(currentWord, Undo)){
        return 14;
    } else if(isKataSama(currentWord, Redo)){
        return 15;
    } else if(isKataSama(currentWord, Catalog)){
        return 16;
    } else if(isKataSama(currentWord, CookBook)){
        return 17;
    } else {
        return -1;
    }
}