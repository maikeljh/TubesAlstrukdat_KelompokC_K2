/* File : buy.c */

ListMakanan CariBuy(ListMakanan L){
    ListMakanan Result;
    int jumlahMakanan = 0;
    for(int i = 0; i < JumlahMakanan(L); i++){
        if(Lokasi(Makanan(L, i)) == 3){
            Makanan(Result, jumlahMakanan) = Makanan(L, i);
            jumlahMakanan++;
        }
    }
    JumlahMakanan(Result) = jumlahMakanan;
    return Result;
}

void TulisBuy(ListMakanan L){
    printf("\n======================\n");
    printf("=        BUY         =\n");
    printf("======================\n");
    printf("List Bahan Makanan:\n");
    int idx = 1;
    for(int i = 0; i < JumlahMakanan(L); i++){
        printf("   %d. ", idx);
        idx++;
        PrintWord(Nama(Makanan(L, i)));
        printf(" (");
        if(DayLP(Makanan(L, i)) == 0 && HourLP(Makanan(L, i)) == 0 && MinuteLP(Makanan(L, i)) == 0){
            printf("0");
        } else {
            if(DayLP(Makanan(L, i)) > 0){
                printf("%d hari", DayLP(Makanan(L, i)));
                if(HourLP(Makanan(L, i)) > 0){
                    printf(" ");
                }
            }
            if(HourLP(Makanan(L, i)) > 0){
                printf("%d jam", HourLP(Makanan(L, i)));
                if(MinuteLP(Makanan(L, i)) > 0){
                    printf(" ");
                }
            }
            if(MinuteLP(Makanan(L, i)) > 0){
                printf("%d menit", MinuteLP(Makanan(L, i)));
            }
        }
        printf(")\n");
    }
    printf("\nKirim 0 untuk exit.\n");
}

void ProsesBuy(ListMakanan L, PrioQueueTime *S){
    while(true){
        TulisBuy(L);
        printf("\nEnter Command: ");
        int command = readCommandNumber();
        if(command == 0){
            break;
        } else if(command > 0) {
            if(command <= JumlahMakanan(L)){
                printf("\nBerhasil memesan ");
                PrintWord(Nama(Makanan(L, command-1)));
                printf(". ");
                PrintWord(Nama(Makanan(L, command-1)));
                printf(" akan diantar dalam ");
                if(DayLP(Makanan(L, command-1)) == 0 && HourLP(Makanan(L, command-1)) == 0 && MinuteLP(Makanan(L, command-1)) == 0){
                    printf("0");
                } else {
                    if(DayLP(Makanan(L, command-1)) > 0){
                        printf("%d hari", DayLP(Makanan(L, command-1)));
                        if(HourLP(Makanan(L, command-1)) > 0){
                            printf(" ");
                        }
                    }
                    if(HourLP(Makanan(L, command-1)) > 0){
                        printf("%d jam", HourLP(Makanan(L, command-1)));
                        if(MinuteLP(Makanan(L, command-1)) > 0){
                            printf(" ");
                        }
                    }
                    if(MinuteLP(Makanan(L, command-1)) > 0){
                        printf("%d menit", MinuteLP(Makanan(L, command-1)));
                    }
                }
                printf(".\n");
                Pengiriman(Makanan(L, command-1)) = NextMenit(Pengiriman(Makanan(L, command-1)));
                EnqueueDelivery(S, Makanan(L, command-1));
                break;
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
    Simulator S;
    Word Nama;
    Nama.TabWord[0] = 'M';
    Nama.Length = 1;
    POINT P;
    CreatePoint(&P, 1, 1);
    CreateSimulator(&S, Nama, P);
    ListMakanan KumpulanMakanan = BacaMakanan(fileMakanan);
    ListMakanan ListBuy = CariBuy(KumpulanMakanan);
    ProsesBuy(ListBuy, &S);
}*/