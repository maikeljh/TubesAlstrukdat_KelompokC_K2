#include "tree.c"

int main(){
    /*
    // INISIASI ARRAY OF TREE
    Tree T[100];

    // Melakukan alokasi Node
    addrNode P1,P2,P3,P4,P5;
    P1 = AlokNode(11);
    P2 = AlokNode(21);
    P3 = AlokNode(10);
    P4 = AlokNode(31);
    P5 = AlokNode(15);

    addrNode P11[1] = {P1};
    addrNode P22[2] = {P2,P3};
    addrNode P33[2] = {P4,P5};

    // Melakukan Alokasi Tree
    Tree T1, T2, T3;
    MakeTree(21,0, NULL, &T1);
    MakeTree(31,0,NULL, &T2);
    MakeTree(37,0,NULL, &T3);

    // Memeriksa apakah tree kosong atau tidak
    if(IsTreeEmpty(T1)){
        printf("Tree Kosong\n");
    } else {
        printf("Tree tidak kosong\n");
    }

    // Melakukan penambahan daun sesuai dengan akar
    AddDaunByID(&T1, 21, 11);
    AddDaunByID(&T2, 31, 21);
    AddDaunByID(&T2, 31, 21);
    AddDaunByID(&T3, 37, 31);
    AddDaunByID(&T3, 37, 15);

    // Melakukan Pencetakan Tree
    printf("Tree 1 berisi ");
    PrintTree(T1);
    printf("\n");
    printf("Tree 2 berisi ");
    PrintTree(T2);
    printf("\n");
    printf("Tree 3 berisi ");
    PrintTree(T3);
    printf("\n");

    // Melakukan Merge Resep
    T[0] = T1;
    T[1] = T2;
    T[2] = T3;
    Tree Resep = mergeResep(T, 3);
    printf("Tree Resep Dari Makanan Tersebut adalah ");
    PrintTree(Resep);
    printf("\n");
    */

   // INISIASI PATH KONFIGURASI FILE MAKANAN
	char fileName[100] = "../../../../config/resep.txt";
    Tree Main = BacaResep(fileName);
    PrintTree(Main);
}