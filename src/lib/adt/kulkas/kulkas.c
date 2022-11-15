#include "kulkas.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Kulkas *** */
void createKulkas(Kulkas *K){
    /* I.S. K sembarang */
    /* F.S. Terbentuk Kulkas K kosong  */
    ListMakananKulkas M;
    JumlahMakanan(M) = 0;
    Matrix D;

    createMatrix(10, 20, &D);
    for(int i = 0 ; i < ROW_EFF(D); i++){
        for(int j = 0; j < COL_EFF(D); j++){
            ELMT(D, i , j) = 0;
        }
    }

    Kulkas(*K) = M;
    MatriksKulkas(*K) = D;
}

/* *** Selektor: Untuk sebuah kulkas K yang terdefinisi: *** */
boolean isKulkasFull(Kulkas K){
    /* Mengembalikkan true jika kulkas sudah penuh (tidak ada value 0 di dalam matriks kulkas )*/
    boolean full = true;
    Matrix D = MatriksKulkas(K);
    for(int i = 0 ; i < ROW_EFF(D); i++){
        for(int j = 0; j < COL_EFF(D); j++){
            if(ELMT(D, i , j) == 0){
                full = false;
                break;
            }
        }
        if(!full){
            break;
        }
    }

    return full;
}

boolean isKulkasKosong(Kulkas K){
    /* Mengembalikkan true jika kulkas kosong (semua memiliki value 0 di dalam matriks kulkas ) */
    return (JumlahMakanan(Kulkas(K)) == 0);
}

/* ********** Assignment Kulkas ********** */
boolean insertKulkas(Kulkas *K, Makanan M, int i, int j){
    /* Mengembalikkan true jika proses insert kulkas berhasil dan false jika proses gagal */
    int A = Lebar(M);
    int B = Panjang(M);
    if(ELMT(MatriksKulkas(*K), i ,j) != 0){
        printf("\nMakanan tidak bisa diisi di lokasi tersebut.\n");
        return false;
    } else {
        boolean check = true;
        if(i < 1 || i > 10 || j < 1 || j > 20 || i + A - 1 > 10 || j + B - 1 > 20){
            check = false;
        } else {
            for(int x = i; x < i + A; x++){
                for(int y = j; y < j + B; y++){
                    if(ELMT(MatriksKulkas(*K), x ,y) != 0){
                        check = false;
                        break;
                    }
                }
                if(!check){
                    break;
                }
            }
        }
        if(check){
            int ID = ID(M);
            for(int x = i; x < i + A; x++){
                for(int y = j; y < j + B; y++){
                    ELMT(MatriksKulkas(*K), x ,y) = ID;
                }
            }
            JumlahMakanan(Kulkas(*K)) += 1;
            MakananKulkas(Kulkas(*K), JumlahMakanan(Kulkas(*K)) - 1) = M;
            Absis(PointMakananKulkas(Kulkas(*K), JumlahMakanan(Kulkas(*K)) - 1)) = j;
            Ordinat(PointMakananKulkas(Kulkas(*K), JumlahMakanan(Kulkas(*K)) - 1)) = i;
            return true;
        } else {
            printf("\nMakanan tersebut tidak bisa diisi di lokasi (%d,%d).\n", i, j);
            return false;
        }
    }
}

void deleteKulkas(Kulkas *K, int idx, Makanan *Out){
    /* I.S. K terdefinisi dan tidak kosong, ID terdefinisi, dan Out sembarang */
    /* F.S. Out menjadi terdefinisi dengan makanan yang memiliki ID 'ID' diambil dari kulkas */
    *Out = MakananKulkas(Kulkas(*K), idx);
    POINT P = PointMakananKulkas(Kulkas(*K), idx);
    for(int x = Ordinat(P); x < Ordinat(P) + Lebar(*Out); x++){
        for(int y = Absis(P); y < Absis(P) + Panjang(*Out); y++){
            ELMT(MatriksKulkas(*K), x ,y) = 0;
        }
    }
    for(int i = idx; i < JumlahMakanan(Kulkas(*K)) - 1; i++){
        ElementKulkas(Kulkas(*K), i) = ElementKulkas(Kulkas(*K), i+1);
    }
    JumlahMakanan(Kulkas(*K)) -= 1;
}

/* ********** KELOMPOK TULIS ********** */
void displayKulkas(Kulkas K){
    /* I.S. K terdefinisi */
    /* F.S. Tercetaknya matriks kulkas pada layar */
    printf("\n===============KULKAS PEMAIN===============\n");
    for(int i = 0; i < ROW_EFF(MatriksKulkas(K)) + 2; i++) {
        for(int j = 0; j < COL_EFF(MatriksKulkas(K)) + 2; j++) {
            if (i == 0 || i == ROW_EFF(MatriksKulkas(K)) + 1 || j == 0 || j == COL_EFF(MatriksKulkas(K)) + 1){
                printf("* ");
            } else {
                if(ELMT(MatriksKulkas(K), i, j) == 0){
                    printf("_ ");
                } else {
                    printf("%d ",ELMT(MatriksKulkas(K), i, j));
                }
            }
        }
        printf("\n");
    }
}

void PrintMakananKulkas(Kulkas K){
    /* I.S. K terdefinisi dan bisa jadi kosong */
    /* F.S. Tercetaknya list makanan yang terdapat di dalam kulkas */
    for(int i = 0; i < JumlahMakanan(Kulkas(K)); i++){
        printf("   %d. ", i+1);
        PrintWord(Nama(MakananKulkas(Kulkas(K), i)));
        printf(" -");
        if (Day(Kedaluwarsa(MakananKulkas(Kulkas(K), i))) != 0){
            printf(" %d Hari", Day(Kedaluwarsa(MakananKulkas(Kulkas(K), i))));
        }
        if (Hour(Kedaluwarsa(MakananKulkas(Kulkas(K), i))) != 0){
            printf(" %d Jam", Hour(Kedaluwarsa(MakananKulkas(Kulkas(K), i))));
        }
        if (Minute(Kedaluwarsa(MakananKulkas(Kulkas(K), i))) != 0){
            printf(" %d Menit", Minute(Kedaluwarsa(MakananKulkas(Kulkas(K), i))));
        }
        printf("\n");
    }
}

int commandKulkas(){
    /* Mengembalikkan command berupa integer untuk proses kulkas */
    Word Insert = CreateWord("INSERT", 6);
    Word Take = CreateWord("TAKE", 4);
    Word Return = CreateWord("RETURN", 6);

    STARTWORD();
    if(isKataSama(currentWord, Insert) && currentChar == '\n'){
        return 1;
    } else if(isKataSama(currentWord, Take) && currentChar == '\n'){
        return 2;
    } else if(isKataSama(currentWord, Return) && currentChar == '\n'){
        return 3;
    } else {
        while(currentChar != '\n'){
            ADVWORD();
        }
        return -1;
    }
}

void ProsesKulkas(Kulkas *K, Simulator *S){
    /* I.S. K terdefinisi dan S terdefinisi */
    /* F.S. Melakukan proses kulkas */
    int action;
    int idx;
    int i, j;
    while(true){
        displayKulkas(*K);
        printf("\nLIST COMMAND:\n");
        printf("1. INSERT\n");
        printf("2. TAKE\n");
        printf("3. RETURN\n");
        printf("\n");
        printf("ENTER COMMAND: ");
        action = commandKulkas();
        if(action == 1){
            if(NBElmt(Inventory(*S)) == 0){
                printf("Inventory kosong.\n");
            } else {
                boolean isValid = false;
                while(!isValid){
                    printf("\nPilih makanan yang ingin dipindahkan:\n");
                    PrintPrioQueueTime(Inventory(*S));
                    printf("\nMasukkan Nomor: ");
                    scanf("%d", &idx);
                    if(idx >= 1 && idx <= NBElmt(Inventory(*S))){
                        isValid = true;
                    } else {
                        printf("\nInput salah. Silahkan input command kembali.\n");
                    }
                }
                isValid = false;
                Makanan Temp;
                DequeueIdx(&Inventory(*S), idx-1, &Temp);
                while(!isValid){
                    displayKulkas(*K);
                    printf("\nPilih lokasi baris (i): ");
                    scanf("%d", &i);
                    printf("\nPilih lokasi kolom (j): ");
                    scanf("%d", &j);
                    boolean check = insertKulkas(K, Temp, i, j);
                    if(check){
                        isValid = true;
                    } else {
                        printf("\nInput salah. Silahkan input command kembali.\n");
                    }
                }
                printf("\nMakanan berhasil dimasukkan ke kulkas!\n");
                displayKulkas(*K);
                ADV();
                break;
            }
        } else if(action == 2){
            if(isKulkasKosong(*K)){
                printf("Kulkas kosong.\n");
            } else {
                boolean isValid = false;
                while(!isValid){
                    printf("\nPilih makanan yang ingin diambil:\n");
                    PrintMakananKulkas(*K);
                    printf("\nMasukkan Nomor: ");
                    scanf("%d", &idx);
                    if(idx >= 1 && idx <= JumlahMakanan(Kulkas(*K))){
                        isValid = true;
                    } else {
                        printf("\nInput salah. Silahkan input command kembali.\n");
                    }
                }
                Makanan Temp;
                deleteKulkas(K, idx-1, &Temp);
                Kedaluwarsa(Temp) = NextMenit(Kedaluwarsa(Temp));
                Enqueue(&Inventory(*S), Temp);
                printf("\nMakanan berhasil dimasukkan ke inventory!\n");
                displayKulkas(*K);
                ADV();
                break;
            }
        } else if(action == 3){
            break;
        } else {
            printf("\nCommand salah. Silahkan input command kembali.\n");
        }
    }
}