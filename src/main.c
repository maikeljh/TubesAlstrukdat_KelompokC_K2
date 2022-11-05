#include <stdio.h>
#include <stdlib.h>
#include "./lib/adt/boolean.h"
#include "./lib/adt/sederhana/simulator/simulator.c"
#include "./lib/adt/matrix/matrix.c"
#include "./lib/commandparser.c"
#include "./lib/adt/sederhana/makanan/makanan.c"
#include "./lib/adt/tree/tree.c"
#include "./lib/peta.c"
#include "./lib/buy.c"
#include "./lib/delivery.c"
#include "./lib/mix.c"
#include "./lib/fry.c"
#include "./lib/chop.c"
#include "./lib/boil.c"
#include "./lib/adt/stack/stack.c"

// gcc main.c ./lib/adt/wordmachine/wordmachine.c ./lib/adt/wordmachine/charmachine.c ./lib/adt/wordfilemachine/wordfilemachine.c ./lib/adt/wordfilemachine/charfilemachine.c ./lib/adt/sederhana/time/time.c -o main

int main(){
    // KAMUS GLOBAL
    int command;
    ListMakanan KumpulanMakanan;
    ListMakanan ResepMix, ResepFry, ResepBoil, ResepChop;
    Tree Resep;
    int jumlahMakanan;
    Matrix peta;
    POINT S,T,M,C,F,B;
    TIME time;
    boolean isSucceed;
    boolean wait;
    Simulator Pemain, Temp;
    Stack Undo, Redo;
    int JAM, MENIT;
    
    // ALGORITMA UTAMA
    printf("\nHello, Welcome to Our Game!\n");
    printf("\n@@@@@@@@@@@@@&#BBBGGGPPGGGGGGGGGGGBBBBB##&&@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@B5YYJJJJJ5P55YYYYYYYYYYYYYYYYY55PPPPG&@@@@@@@@@@\n");
    printf("@@@@@@@@@@@&5Y555Y5YB57!7JJJJJJJJJJJJJJJJJJJJJJ?!?#@@@@@@@@@\n");
    printf("@@@@@@@@@@@#Y5GY5PY5#?!7G7^^::::::::::::::::::^PY!P@@@@@@@@@\n");
    printf("@@@@@@@@@@@G5P555P55#7!5Y....7?!..........7?!..J5!P@@@@@@@@@\n");
    printf("@@@@@@@@@@@GYP5P55P5B7!PJ.:.:!^!:.~7!!7^.:!^!..Y5!P@@@@@@@@@\n");
    printf("@@@@@@@@@@@PYP5Y5PYPB7!PJ.........:^~~^........Y5!P@@@@@@@@@\n");
    printf("@@@@@@@@@@@PYYYYYYYPG!!PJ......................Y5!P@@@@@@@@@\n");
    printf("@@@@@@@@@@@PPGP55YYGG!!PJ.:..:::.............:.Y5!P@@@@@@@@@\n");
    printf("&B#@@@@@@@@5B&&##GYGP!!5Y......................55!G@@@@@@@@@\n");
    printf("@J7#@@@@@@@5G&#&&#YGP!775J????????????????????Y57!G@@@@@@@@@\n");
    printf("@B7Y@@@@@@@5G&###PYB5!7!?555555555555????7?PP?7!77B@@@@@@@@@\n");
    printf("@@G7Y&@@@@@5G&&&#PYB5!7!JBBBBBBBBBBBB?!77!?GG?7777B@@@@@@@@@\n");
    printf("@@@B??G@@@@5G###&PYBY!777777777777777777!!77777777#@@@@@@@@@\n");
    printf("@@@@&PJJPB&GGBBBG5YBY!77777?Y5Y?777777!?G5777!!777&@@@@@@@@@\n");
    printf("@@@@@@@#PYJJYY5&#5YBY!77777PP?G5777777J#BGP7?YJ77?#GB#@@@@@@\n");
    printf("@@@@@@@@@@&BGGB#B5YBY!7777!!?Y?!7777777Y5YY7B#P5!?&G5JJ5#@@@\n");
    printf("@@@@@@@@@@@B55P5YYYBY!777?JJ?7?JJ?777!5&BPPG?YJ7!J@@@@BY?P@@\n");
    printf("@@@@@@@@@@@@BPYYYYYBY!7775GGG?PGGG777!JBBPP57!!7!J@@@@@@P7P@\n");
    printf("@@@@@@@@@@@@@@&BG5YBY!777!!!!!!!!!!!!!!7777!!!!!!5@@@@@@@##@\n");
    printf("@@@@@@@@@@@@@@@@@@&&#Y????????JJJJJJJJJJJYYYY555G&@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@GYG@@@@@@@@@@@@@5J#@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@P7P@@@@@@@@@@@@@Y7B@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@P7P@@@@@@@@@@@@@Y7B@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@G7JG&@@@@@@@@@@@P?JP&@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@#PYG@@@@@@@@@@@@&BG#@@@@@@@@@@@@@@@@\n");
    
    while(true){
        printf("\nLIST COMMAND:\n");
        printf("1. START\n2. EXIT\n");
        printf("\nEnter Command: ");
        command = readCommand();
        if(command == 1){
            break;
        } else if (command == 2){
            printf("\nTerima kasih telah mempermainkan game kami!\n");
            return 0;
        } else {
            printf("\nCommand salah. Silahkan input command kembali.\n");
        }
    }

    // INISIASI PETA, MAKANAN, DAN RESEP
    char fileMakanan[100] = "../config/makanan.txt";
    char fileResep[100] = "../config/resep.txt";
    char path[50] = "../config/testPeta.txt";
    bacaPeta(path,&peta, &S, &T, &M, &C, &F, &B);
    KumpulanMakanan = BacaMakanan(fileMakanan);
    Resep = BacaResep(fileResep);
    Word Mix = CreateWord("MIX", 3);
	Word Chop = CreateWord("CHOP", 4);
	Word Fry = CreateWord("FRY", 3);
	Word Boil = CreateWord("BOIL", 4);
    ResepMix = ListResep(KumpulanMakanan, Resep, Mix);
    ResepFry = ListResep(KumpulanMakanan, Resep, Fry);
    ResepChop = ListResep(KumpulanMakanan, Resep, Chop);
    ResepBoil = ListResep(KumpulanMakanan, Resep, Boil);

    // INISIASI LIST BUY
    ListMakanan ListBuy = CariBuy(KumpulanMakanan);

    // INISIASI WAKTU
    CreateTime(&time,0,0,0);

    // INISIASI SIMULATOR
    Word NamaPemain;
    int idxNama = 0;
    printf("\nMasukkan Nama Pemain: ");
    STARTWORD();
    while(currentChar != '\n'){
        for (int i = 0; i < currentWord.Length; i++){
            NamaPemain.TabWord[idxNama] = currentWord.TabWord[i];
            idxNama++;
        }
        NamaPemain.TabWord[idxNama] = ' ';
        idxNama++;
        ADVWORD();
	}
    for (int i = 0; i < currentWord.Length; i++){
        NamaPemain.TabWord[idxNama] = currentWord.TabWord[i];
        idxNama++;
    }
    NamaPemain.Length = idxNama;
    CreateSimulator(&Pemain, NamaPemain, S, time);
    printf("\nGAME STARTED.\n");

    // INISIASI STACK
    CreateUndoStack(&Undo, Pemain);
    CreateRedoStack(&Redo);

    // GAME STARTED
    // MAIN PROGRAM
    while(true){
        isSucceed = false;
        wait = false;
        TulisSimulator(Pemain);
        printf("\n");
        displayPeta(peta, LokasiSimulator(Pemain));
        printf("LIST COMMAND:\n");
        printf("1.  BUY\n");
        printf("2.  DELIVERY\n");
        printf("3.  MOVE NORTH\n");
        printf("4.  MOVE EAST\n");
        printf("5.  MOVE WEST\n");
        printf("6.  MOVE SOUTH\n");
        printf("7.  MIX\n");
        printf("8.  CHOP\n");
        printf("9.  FRY\n");
        printf("10. BOIL\n");
        printf("11. WAIT X Y\n");
        printf("12. CATALOG\n");
        printf("13. COOKBOOK\n");
        printf("14. INVENTORY\n");
        printf("15. EXIT\n");
        printf("\nEnter Command: ");
        command = readCommand();
        if(command == 5){
            move (peta, 1, &LokasiSimulator(Pemain), &isSucceed);
        } else if(command == 6){
            move (peta, 2, &LokasiSimulator(Pemain), &isSucceed);
        } else if(command == 8){
            move (peta, 3, &LokasiSimulator(Pemain), &isSucceed);
        } else if(command == 7){
            move (peta, 4, &LokasiSimulator(Pemain), &isSucceed);
        } else if(command == 3){
            if (isNearby(T,LokasiSimulator(Pemain))) {
                ProsesBuy(ListBuy, &DeliverySimulator(Pemain));
                isSucceed = true;
                // Terminate
                printf("\nPress enter to continue.");
                ADV();
            } else {
                printf("Tidak berada dekat telephone.\n");
            }
        } else if(command == 4){
            printf("\nList Makanan di Perjalanan\n");
            printf("(nama - waktu sisa delivery)\n");
            PrintDelivery(DeliverySimulator(Pemain));
            // Terminate
            printf("\nPress enter to continue.");
            ADV();
        } else if(command == 9){
            if (isNearby(M,LokasiSimulator(Pemain))) {
                ProsesMix(ResepMix, KumpulanMakanan, Resep, Mix, &Pemain);
                isSucceed = true;
                // Terminate
                printf("\nPress enter to continue.");
                ADV();
            } else {
                printf("Tidak berada dekat tempat Mix.\n");
            }
        } else if(command == 10){
            if (isNearby(C,LokasiSimulator(Pemain))) {
                ProsesChop(ResepChop, KumpulanMakanan, Resep, Chop, &Pemain);
                isSucceed = true;
                // Terminate
                printf("\nPress enter to continue.");
                ADV();
            } else {
                printf("Tidak berada dekat tempat Chop.\n");
            }
        } else if(command == 11){
            if (isNearby(F,LokasiSimulator(Pemain))) {
                ProsesFry(ResepFry, KumpulanMakanan, Resep, Fry, &Pemain);
                isSucceed = true;
                // Terminate
                printf("\nPress enter to continue.");
                ADV();
            } else {
                printf("Tidak berada dekat tempat Fry.\n");
            }
        } else if(command == 12){
            if (isNearby(B,LokasiSimulator(Pemain))) {
                ProsesBoil(ResepBoil, KumpulanMakanan, Resep, Boil, &Pemain);
                isSucceed = true;
                // Terminate
                printf("\nPress enter to continue.");
                ADV();
            } else {
                printf("Tidak berada dekat tempat Boil.\n");
            }
        } else if(command == 13){
            ADVWORD();
            boolean check = true;
            for(int i = 0; i < currentWord.Length; i++){
                if ( currentWord.TabWord[i] < '0' && currentWord.TabWord[i] > '9' ){
                    check = false;
                    break;
                }   
            }
            if(!check){
                printf("\nCommand salah. Silahkan input command kembali.\n");
            } else {
                JAM = wordOnlyToInt(currentWord);
            }

            if(currentChar == '\n'){
                printf("\nCommand salah. Silahkan input command kembali.\n");
            } else {
                ADVWORD();
                check = true;
                for(int i = 0; i < currentWord.Length; i++){
                    if ( currentWord.TabWord[i] < '0' && currentWord.TabWord[i] > '9' ){
                        check = false;
                        break;
                    }   
                }
                if(!check){
                    printf("\nCommand salah. Silahkan input command kembali.\n");
                } else {
                    MENIT = wordOnlyToInt(currentWord);
                }

                if(JAM >= 0 && JAM <= 23 && MENIT >= 0 && MENIT <= 59){
                    WaktuSimulator(Pemain) = NextNMenit(WaktuSimulator(Pemain), JAM * 60 + MENIT);
                    wait = true;
                } else {
                    printf("\nCommand salah. Silahkan input command kembali.\n");
                }
            }
        } else if(command == 14){
            if (Top(Undo) > 0) {
                Pop(&Undo, &Temp);
                Push(&Redo, Temp);
                Pemain = InfoTop(Undo);
            } else {
                printf("Tidak dapat melakukan undo.\n\n");
            }
        } else if(command == 15){
            if (!IsEmptyStack(Redo)) {
                Pop(&Redo, &Temp);
                Push(&Undo, Temp);
                Pemain = InfoTop(Redo);
            } else {
                printf("Tidak dapat melakukan redo\n\n");
            }

        } else if(command == 16){
            printf("\nList Makanan\n");
            printf("(nama - durasi kedaluwarsa - aksi yang diperlukan - delivery time)\n");
            TulisListMakanan(KumpulanMakanan, JumlahMakanan(KumpulanMakanan));
            // Terminate
            printf("\n\nPress enter to continue.");
            ADV();
        } else if(command == 17) {
            printf("\nList Resep\n");
            printf("(aksi yang diperlukan - bahan...)\n");
            TulisResep(KumpulanMakanan, Resep);
            printf("\nPress enter to continue.");
            ADV();
        } else if(command == 18) {
            printf("\nList Inventory\n");
            printf("(nama - waktu sisa kedaluwarsa)\n");
            PrintPrioQueueTime(Inventory(Pemain));
            printf("\nPress enter to continue.");
            ADV();
        } else if(command == 2) {
            printf("\nTerima kasih telah mempermainkan game kami!\n");
            return 0;
        } else {
            printf("\nCommand salah. Silahkan input command kembali.\n");
        }
        if (isSucceed && !wait) {
            WaktuSimulator(Pemain) = NextMenit(WaktuSimulator(Pemain));
            Shipping(&DeliverySimulator(Pemain), &Pemain);
            DecayKedaluwarsa(&Inventory(Pemain));
            Push(&Undo, Pemain);
            CreateRedoStack(&Redo);
        } else if(wait) {
            for(int i = 0; i < JAM * 60 + MENIT; i++){
                Shipping(&DeliverySimulator(Pemain), &Pemain);
                DecayKedaluwarsa(&Inventory(Pemain));
            }
            Push(&Undo, Pemain);
            CreateRedoStack(&Redo);
        }
    }
}