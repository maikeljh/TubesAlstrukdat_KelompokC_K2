#include <stdio.h>
#include <stdlib.h>
#include "./lib/commandparser.c"

int main(){
    // KAMUS GLOBAL
    int command;
    
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
            printf("\nGAME STARTED.\n");
            break;
        } else if (command == 2){
            printf("\nTerima kasih telah mempermainkan game kami!\n");
            break;
        } else {
            printf("\nCommand salah. Silahkan input command kembali.\n");
        }
    }
}