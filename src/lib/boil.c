void ProsesBoil(ListMakanan ResepBoil, ListMakanan KumpulanMakanan, Tree Resep, Word Kind, Simulator *S, boolean *Cook, int *JAM, int *MENIT){
    /* Melakukan Proses Boil Oleh Player jika Player berada di dekat area Boil*/
    /* I.S. ResepBoil, KumpulanMakanan, Resep, Kind, dan S terdefinisi. Cook, JAM, dan MENIT Sembarang */
    /* F.S. Terlaksananya Proses Boil oleh Player jika Player berada di dekat area Boil */
    while(true) {
        Makanan Temp;
        printf("\n======================\n");
        printf("=        BOIL         =\n");
        printf("======================\n");
        printf("List Bahan Makanan yang Bisa Dibuat\n");
        TulisResepKind(ResepBoil, Resep, Kind);
        printf("\nKirim 0 untuk exit.\n");
        printf("\nEnter Command: ");
        int command = readCommandNumber();
        if(command == 0){
            break;
        } else if(command > 0) {
            if(command <= JumlahMakanan(ResepBoil)){
                Tree ResepMakanan = SearchTree(Resep, ID(Makanan(ResepBoil, command-1)));
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
                    Kedaluwarsa(Makanan(ResepBoil, command-1)) = NextNMenit(Kedaluwarsa(Makanan(ResepBoil, command-1)), HourPengolahan(Makanan(ResepBoil, command-1)) * 60 + MinutePengolahan(Makanan(ResepBoil, command-1)));
                    Enqueue(&Inventory(*S), Makanan(ResepBoil, command-1));
                    printf("\n");
                    PrintWord(Nama(Makanan(ResepBoil, command-1)));
                    printf(" selesai dibuat dan sudah masuk ke inventory!\n");
                    AddNotif(&NotifSimulator(*S),6, Makanan(ResepBoil, command-1));
                    *Cook = true;
                    *JAM = HourPengolahan(Makanan(ResepBoil, command-1));
                    *MENIT = MinutePengolahan(Makanan(ResepBoil, command-1));
                    break;
                } else {
                    printf("\nGagal membuat ");
                    PrintWord(Nama(Makanan(ResepBoil, command-1)));
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