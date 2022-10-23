#include <stdio.h>

void readCommand(char command[]){
    if(command[0] == 'B' && command[1] == 'U' && command[2] == 'Y'){
        printf("Buy Gan");
    } else {
        printf("Gagal");
    }
}

char user_input[100];

int main(){
    fgets(user_input, 100, stdin);
    printf("%s", user_input);
    readCommand(user_input);
}

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
    13. */