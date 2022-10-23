#include "wordmachine.c"

int main(){
    STARTWORD();
    while(!currentChar != '\n'){
        if(currentWord.TabWord[0] == 'B' && currentWord.TabWord[1] == 'U' && currentWord.TabWord[2] == 'Y'){
            printf("BUY GAN");
            break;
        }
        ADVWORD();
    }
}