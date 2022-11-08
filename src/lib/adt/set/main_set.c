#include "set.c"

int main(){
    Set SetMakanan, SetMakanan2;

    // INISIASI LIST MAKANAN M
	ListMakanan M;
    Tree Resep;

	// INISIASI PATH KONFIGURASI FILE MAKANAN
	char fileName[100] = "../../../../config/makanan.txt";
    char fileResep[100] = "../../../../config/resep.txt";

	// MELAKUKAN MEMBACA MAKANAN
	M = BacaMakanan(fileName);
    Resep = BacaResep(fileResep);

    // MELAKUKAN CREATE SET
    createSet(&SetMakanan, M);
    createSet(&SetMakanan2, M);

    // MELAKUKAN ADD SET
    addSet(&SetMakanan, Makanan(M, 0));
    addSet(&SetMakanan, Makanan(M, 1));
    addSet(&SetMakanan, Makanan(M, 2));

    addSet(&SetMakanan2, Makanan(M, 0));
    addSet(&SetMakanan2, Makanan(M, 1));

    // MEMERIKSA APAKAH SUBSET ATAU TIDAK
    if(isSubset(SetMakanan2, SetMakanan)){
        printf("S1 SUBSET S2");
    }

    // MEMBUAT LIST RESEP DAN LIST REKOMENDASI
    ListMakanan ListResep = ListResepAll(M, Resep);
    ListSet ListRekomendasi = BacaRekomendasi(Resep, M, ListResep);

    // MEMBUAT SIMULATOR
    Simulator S;
    Word Name = CreateWord("NAMA", 4);
    POINT P;
    CreatePoint(&P, 1, 2);
    TIME W;
    CreateTime(&W, 1, 1, 1);
    CreateSimulator(&S, Name, P, W);

    // MELAKUKAN ENQUEUE MAKANAN KE INVENTORY
    Enqueue(&Inventory(S), M.M[0]);
    Enqueue(&Inventory(S), M.M[1]);

    // MENULISKAN REKOMENDASI
    TulisRekomandasi(M, ListRekomendasi, S);
}