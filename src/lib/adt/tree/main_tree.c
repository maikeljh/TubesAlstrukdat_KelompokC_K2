#include "tree.c"

int main(){
    Tree T[100];
    addrNode P1,P2,P3,P4,P5;
    P1 = AlokNode(11);
    P2 = AlokNode(21);
    P3 = AlokNode(10);
    P4 = AlokNode(31);
    P5 = AlokNode(15);
    addrNode P11[1] = {P1};
    addrNode P22[2] = {P2,P3};
    addrNode P33[2] = {P4,P5};
    MakeTree(21,0, NULL, &T[0]);
    MakeTree(31,0,NULL, &T[1]);
    MakeTree(37,0,NULL, &T[2]);
    AddDaunByID(&T[0], 21, 11);
    AddDaunByID(&T[1], 31, 21);
    AddDaunByID(&T[1], 31, 10);
    AddDaunByID(&T[2], 37, 31);
    AddDaunByID(&T[2], 37, 15);

    PrintTree(T[0]);
    printf("\n");
    PrintTree(T[1]);
    printf("\n");
    PrintTree(T[2]);
    printf("\n");

    Tree Resep = mergeResep(T, 3);
    PrintTree(Resep);
    printf("\n");
}