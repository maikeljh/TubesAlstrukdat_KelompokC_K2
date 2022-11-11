#include "set.h"

void createSet(Set *himpunan, ListMakanan M){
    /* I.S himpunan sembarang dan M terdefinisi */
    /* F.S Membuat himpunan dengan elemen-elemen dari M */
    Length(*himpunan) = JumlahMakanan(M);
    for(int i = 0; i < JumlahMakanan(M); i++){
        ElementSet Temp;
        MakananSet(Temp) = ID(Makanan(M, i));
        Exist(Temp) = false;
        ElSet(*himpunan, i) = Temp;
    }
}

void addSet(Set *himpunan, Makanan M){
    /* I.S himpunan terdefinisi */
    /* F.S Membuat elemen dari set menjadi exist(terdapat pada himpunan) */
    for(int i = 0; i < Length(*himpunan); i++){
        if(MakananSet(ElSet(*himpunan, i)) == ID(M)){
            Exist(ElSet(*himpunan, i)) = true;
            break;
        }
    }
}

void removeSet(Set *himpunan, Makanan M){
    /* I.S Himpunan terdefinisi */
    /* F.S Membuat sebuah elemen dari himpunan yaitu M menjadi tidak exist. */
    for(int i = 0; i < Length(*himpunan); i++){
        if(MakananSet(ElSet(*himpunan, i)) == ID(M)){
            Exist(ElSet(*himpunan, i)) = false;
            break;
        }
    }
}

boolean isSubset(Set himpunan1, Set himpunan2){
    /* Mengirim true jika himpunan1 subset dari himpunan2 */
    boolean subset;
    for(int i = 0; i < Length(himpunan1); i++){
        if(Exist(ElSet(himpunan1, i))){
            subset = false;
            for(int j = 0; j < Length(himpunan2); j++){
                if(MakananSet(ElSet(himpunan1, i)) == MakananSet(ElSet(himpunan2, j))){
                    if(Exist(ElSet(himpunan2, j))){
                        subset = true;
                        break;
                    }
                }
            }
            if(!subset){
                break;
            }
        }
    }
    return subset;
}

ListSet BacaRekomendasi(Tree Resep, ListMakanan KumpulanMakanan, ListMakanan ListResep){
    /* Mengembalikan list of set yang berisi set-set dari kumpulan resep */
    ListSet Temp;
    JumlahSet(Temp) = JumlahMakanan(ListResep);
    for(int i = 0; i < JumlahMakanan(ListResep); i++){
        Set RekomendasiEl;
        createSet(&RekomendasiEl, KumpulanMakanan);
        Rekomendasi(RekomendasiEl) = Makanan(ListResep, i);
        Tree ResepMakanan = SearchTree(Resep, ID(Makanan(ListResep, i)));
        addrNode P = FirstChild(ResepMakanan);
        for(int j = 0; j < BanyakChild(ResepMakanan); j++){
            for(int k = 0; k < Length(RekomendasiEl); k++){
                if(MakananSet(ElSet(RekomendasiEl, k)) == Akar(P)){
                    Exist(ElSet(RekomendasiEl, k)) = true;
                    break;
                }
            }
            P = Sibling(P);
        }
        ElSet(Temp, i) = RekomendasiEl;
    }
    return Temp;
}

Set BacaRekomendasiSimulator(ListMakanan KumpulanMakanan, Simulator S){
    /* Mengembalikan set yang berisi elemen-elemen dari inventory simulator */
    Set Temp;
    createSet(&Temp, KumpulanMakanan);
    for(int i = Head(Inventory(S)); i <= Tail(Inventory(S)); i++){
        addSet(&Temp, Elmt(Inventory(S), i));
    }
    return Temp;
}

void TulisRekomandasi(ListMakanan KumpulanMakanan, ListSet ListRekomendasi, Simulator S){
    /* I.S KumpulanMakanan, ListRekomendasi, dan S terdefinisi */
    /* F.S Menuliskan rekomendasi resep yang dapat dibuat oleh simulator */
    Set Now;
    boolean found = false;
    int idx = 0;
    Set Inventory = BacaRekomendasiSimulator(KumpulanMakanan, S);
    Word Mix = CreateWord("MIX", 3);
	Word Chop = CreateWord("CHOP", 4);
	Word Fry = CreateWord("FRY", 3);
	Word Boil = CreateWord("BOIL", 4);
    printf("\nList Resep yang Dapat Dibuat\n");
    printf("(Nama Makanan - Lokasi - Waktu Pengolahan)\n");
    for(int i = 0; i < JumlahSet(ListRekomendasi); i++){
        Now = ElSet(ListRekomendasi, i);
        if(isSubset(Now, Inventory)){
            found = true;
            printf("   %d. ", (idx+1));
            PrintWord(Nama(Rekomendasi(Now)));
            printf(" - ");
            Word namaLokasi;
            if (Lokasi(Rekomendasi(Now)) == 9){
                namaLokasi = Mix;
            } else if (Lokasi(Rekomendasi(Now)) == 10){
                namaLokasi = Chop;
            } else if (Lokasi(Rekomendasi(Now)) == 11){
                namaLokasi = Fry;
            } else if (Lokasi(Rekomendasi(Now)) == 12){
                namaLokasi = Boil;
            }
            PrintWord(namaLokasi);
            printf(" - ");
            if(DayPengolahan(Rekomendasi(Now)) == 0 && HourPengolahan(Rekomendasi(Now)) == 0 && MinutePengolahan(Rekomendasi(Now)) == 0){
			    printf("0");
            } else {
                if(DayPengolahan(Rekomendasi(Now)) > 0){
                    printf("%d hari ", DayPengolahan(Rekomendasi(Now)));
                }
                if(HourPengolahan(Rekomendasi(Now)) > 0){
                    printf("%d jam ", HourPengolahan(Rekomendasi(Now)));
                }
                if(MinutePengolahan(Rekomendasi(Now)) > 0){
                    printf("%d menit", MinutePengolahan(Rekomendasi(Now)));
                }
            }
            printf("\n");
            idx++;
        }
    }
    if(!found){
        printf("Tidak ada resep yang dapat dibuat.\n");
    }
}