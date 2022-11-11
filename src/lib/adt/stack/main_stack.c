/* File: main_stack.c */
#include <stdio.h>
#include <stdlib.h>
#include "stack.c"
#include "../sederhana/simulator/simulator.c"
#include "../notifikasi/notifikasi.c"
#include "../sederhana/time/time.c"
#include "../wordfilemachine/wordfilemachine.c"
#include "../wordfilemachine/charfilemachine.c"
#include "../wordmachine/wordmachine.c"
#include "../wordmachine/charmachine.c"


int main() {
  Stack undo, redo;
  Simulator S,R;

  //Membuat undo stack dengan 1 element sebagai top yaitu simulator S
  CreateUndoStack(&undo, S);

  //Membuat redo stack kosong
  CreateRedoStack(&redo);

  //Mengecek apakah undo stack kosong
  if (IsEmptyStack(undo)) {
    printf("Undo stack kosong\n");
  } else {
    printf("Undo stack tidak kosong\n");
  }

  //Mengecek apakah redo stack kosong
  if (IsEmptyStack(redo)) {
    printf("Redo stack kosong\n");
  } else {
    printf("Redo stack tidak kosong\n");
  }

  //Mengecek apakah undo stack penuh
  if (IsFullStack(undo)) {
    printf("Undo stack penuh\n");
  } else {
    printf("Undo stack tidak penuh\n");
  }

  //Mengecek apakah redo stack penuh
  if (IsFullStack(redo)) {
    printf("Redo stack penuh\n");
  } else {
    printf("Redo stack tidak penuh\n");
  }
}