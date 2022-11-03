/*#include "./adt/sederhana/makanan/makanan.c"
#include "./adt/tree/tree.c"
#include "./adt/wordmachine/wordmachine.c"
#include "./adt/wordmachine/charmachine.c"
#include "./adt/sederhana/simulator/simulator.c"
#include "./commandparser.c"
#include "./adt/wordfilemachine/wordfilemachine.c"
#include "./adt/wordfilemachine/charfilemachine.c"
#include "./adt/sederhana/time/time.c"*/

void ProsesMix(ListMakanan ResepMix, ListMakanan KumpulanMakanan, Tree Resep, Word Kind, Simulator *S){
    while(true) {
        Makanan Temp;
        printf("\n======================\n");
        printf("=        MIX         =\n");
        printf("======================\n");
        printf("List Bahan Makanan yang Bisa Dibuat\n");
        TulisResepKind(ResepMix, Resep, Kind);
        printf("\nKirim 0 untuk exit.\n");
        printf("\nEnter Command: ");
        int command = readCommandNumber();
        if(command == 0){
            break;
        } else if(command > 0) {
            if(command <= JumlahMakanan(ResepMix)){
                Tree ResepMakanan = SearchTree(Resep, ID(Makanan(ResepMix, command-1)));
                boolean isValid = false;
                int count = 0;
                addrNode P = FirstChild(ResepMakanan);
                for(int j = 0; j < BanyakChild(ResepMakanan); j++){
                    for(int k = 0; k < NBElmt(Inventory(*S)); k++){
                        if(getID(Elmt(Inventory(*S), k)) == Akar(P)){
                            count++;
                            break;
                        }
                    }
                    P = Sibling(P);
                }
                if(count == BanyakChild(ResepMakanan)){
                    P = FirstChild(ResepMakanan);
                    for(int j = 0; j < BanyakChild(ResepMakanan); j++){
                        DequeueAt(&Inventory(*S), Akar(P), &Temp);
                        P = Sibling(P);
                    }
                    Enqueue(&Inventory(*S), Makanan(ResepMix, command-1));
                    printf("\n");
                    PrintWord(Nama(Makanan(ResepMix, command-1)));
                    printf(" selesai dibuat dan sudah masuk ke inventory!\n");
                    break;
                } else {
                    printf("\nGagal membuat ");
                    PrintWord(Nama(Makanan(ResepMix, command-1)));
                    printf(" karena kamu tidak memiliki bahan berikut:\n");
                    P = FirstChild(ResepMakanan);
                    int idxNow = 1;
                    for(int j = 0; j < BanyakChild(ResepMakanan); j++){
                        isValid = false;
                        for(int k = 0; k < NBElmt(Inventory(*S)); k++){
                            if(getID(Elmt(Inventory(*S), k)) == Akar(P)){
                                isValid = true;
                                break;
                            }
                        }
                        if(!isValid){
                            printf("   %d. ", idxNow);
                            Makanan M;
                            for(int z = 0; z < JumlahMakanan(KumpulanMakanan); z++){
                                if(Akar(P) == ID(Makanan(KumpulanMakanan, z))){
                                    PrintWord(Nama(Makanan(KumpulanMakanan, z)));
                                    break;
                                }
                            }
                            printf("\n");
                            idxNow++;
                        }
                        P = Sibling(P);
                    }
                    break;
                }
            } else {
                printf("\nCommand salah. Silahkan input command kembali.\n");
            }
        } else {
            printf("\nCommand salah. Silahkan input command kembali.\n");
        }
    }
}

/*int main(){
    char fileMakanan[100] = "../../config/makanan.txt";
    char fileResep[100] = "../../config/resep.txt";
    Simulator S;
    Word Nama;
    Nama.TabWord[0] = 'M';
    Nama.Length = 1;
    POINT P;
    CreatePoint(&P, 1, 1);
    CreateSimulator(&S, Nama, P);
    Word Mix = CreateWord("MIX", 3);
    ListMakanan KumpulanMakanan = BacaMakanan(fileMakanan);
    Tree Resep = BacaResep(fileResep);
    ListMakanan ResepMix = ListResep(KumpulanMakanan, Resep, Mix);
    for(int i = 0; i < JumlahMakanan(KumpulanMakanan); i++){
        Enqueue(&Inventory(S), Makanan(KumpulanMakanan, i));
    }
    ProsesMix(ResepMix, KumpulanMakanan, Resep, Mix, &S);
}*/