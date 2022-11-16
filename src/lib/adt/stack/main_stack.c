/* File: main_stack.c */
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "../sederhana/simulator/simulator.h"
#include "../notifikasi/notifikasi.h"
#include "../sederhana/time/time.h"
#include "../wordfilemachine/wordfilemachine.h"
#include "../wordfilemachine/charfilemachine.h"
#include "../wordmachine/wordmachine.h"
#include "../wordmachine/charmachine.h"
// cd src/lib/adt/stack
// gcc main_stack.c stack.c ../sederhana/simulator/simulator.c ../notifikasi/notifikasi.c ../sederhana/time/time.c ../wordfilemachine/wordfilemachine.c ../wordfilemachine/charfilemachine.c ../wordmachine/wordmachine.c ../wordmachine/charmachine.c ../sederhana/point/point.c ../prioqueue/prioqueuetime.c -o ../../../../build/lib/adt/main_stack


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
  int kelularinp;
  printf("\nKetik 0 untuk keluar.\n"); scanf("%d",&kelularinp);
}