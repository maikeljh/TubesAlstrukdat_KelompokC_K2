/* ADT Pohon N-Ary */
/* Implementasi dengan menggunakan pointer */

#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

/* *** Konstruktor *** */
Tree AlokasiTree(infotype Akar, int N, addrNode Child[]){
    /* Menghasilkan sebuah pohon N-Ary dari Akar, N, dan array Child, jika alokasi berhasil */
    /* Menghasilkan pohon kosong (NULL) jika alokasi gagal */

    Tree T = (Tree) malloc(sizeof(Node));
    if (T != NULL){
        Akar(T) = Akar;
        BanyakChild(T) = N;
        if(N != 0){
            FirstChild(T) = Child[0];
            int i = 1;
            addrNode P = FirstChild(T);
            while(i < N){
                Sibling(P) = Child[i];
                P = Sibling(P);
                i++;
            }
        } else {
            FirstChild(T) = NULL;
            Sibling(T) = NULL;
        }
        return T;
    } else {
        return NULL;
    }
};

void MakeTree(infotype Akar, int N, addrNode Child[], Tree *P){
    /* I.S. Akar, N, Child terdefinisi. P Sembarang */
    /* F.S. Membentuk pohon P dengan Akar(P) = Akar, BanyakChild(P) = N, FirstChild(P), Sibling(P), dst = Child[i] jika Child[i] tidak NULL
        jika alokasi berhasil. P = NULL jika alokasi gagal. */

    *P = AlokasiTree(Akar, N, Child);
};


/* Manajemen Memory */
addrNode AlokNode(infotype X){
    /* Mengirimkan addrNode hasil alokasi sebuah elemen */
    /* Jika alokasi berhasil, maka addrNode tidak NULL, dan misalnya menghasilkan P, 
     maka Akar(P) = X, BanyakChild(P) = 0, FirstChild(P) = NULL , dan Sibling(P) = NULL */
    /* Jika alokasi gagal, mengirimkan NULL */

    addrNode P = (addrNode) malloc(sizeof(Node));
    if (P != NULL){
        Akar(P) = X;
        BanyakChild(P) = 0;
        FirstChild(P) = NULL;
        Sibling(P) = NULL;
        return P;
    }
    else {
        return NULL;
    }
};

void DealokNode(addrNode P){
    /* I.S. P terdefinisi */
    /* F.S. P dikembalikan ke sistem */
    /* Melakukan dealokasi/pengembalian addrNode P */

    free(P);
};


/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(Tree P){
    /* Mengirimkan true jika P adalah pohon N-Ary kosong */

    return P == NULL;
};

/* *** Traversal *** */
void PrintTree(Tree P){
    /* I.S. P terdefinisi */
    /* F.S. Semua simpul P sudah dicetak secara preorder: akar dan child-child dari simpul P. 
    Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
    Pohon kosong ditandai dengan ().
    Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
    /* Contoh: 
    (A()()) adalah pohon dengan 1 elemen dengan akar A
    (A(B()())(C()())) adalah pohon dengan akar A dan subpohon pertama (B()()) dan subpohon kedua (C()()) */
    
    printf("(");
    if (!IsTreeEmpty(P)){
        printf("%d", Akar(P));
        addrNode P1 = FirstChild(P);
        for(int i = 0; i < BanyakChild(P); i++){
            PrintTree(P1);
            P1 = Sibling(P1);
        }
    }
    printf(")");
};

/* *** Searching *** */
boolean SearchTree(Tree P, infotype X);
/* Mengirimkan true jika ada node dari P yang bernilai X */

/* *** Operasi lain *** */
void AddDaunByID(Tree *P, infotype ID, infotype X){
    /* I.S. P tidak kosong, X adalah salah satu daun Pohon N-Ary P */
    /* F.S. P bertambah simpulnya dengan X sebagai child dari P */
    
    if(!IsTreeEmpty(*P)){
        boolean found = false;
        if(Akar(*P) == ID){
            BanyakChild(*P) += 1;
            addrNode PTemp = AlokNode(X);
            if(FirstChild(*P) == NULL){
                FirstChild(*P) = PTemp;
            } else {
                addrNode PTempX = FirstChild(*P);
                while(Sibling(PTempX) != NULL){
                    PTempX = Sibling(PTempX);
                }
                Sibling(PTempX) = PTemp;
            }
            found = true;
        } else {
            if(BanyakChild(*P) != 0){
                addrNode PTemp = FirstChild(*P);
                AddDaunByID(&PTemp, ID, X);
                int i = 1;
                while (i < BanyakChild(*P) && !found){
                    PTemp = Sibling(PTemp);
                    AddDaunByID(&PTemp, ID, X);
                    i++;
                }
            }
        }
    }
};

void insertTree(Tree *P, Tree newP){
    /* I.S. P dan newP tidak kosong */
    /* F.S. P bertambah simpulnya dengan simpul yang memiliki nilai sama dengan akar newP */

    if(!IsTreeEmpty(*P)){
        if(Akar(*P) == Akar(newP)){
            BanyakChild(*P) = BanyakChild(newP);
            FirstChild(*P) = FirstChild(newP);
        } else {
            if(BanyakChild(*P) != 0){
                addrNode PTemp = FirstChild(*P);
                insertTree(&PTemp, newP);
                int i = 1;
                while (i < BanyakChild(*P)){
                    PTemp = Sibling(PTemp);
                    insertTree(&PTemp, newP);
                    i++;
                }
            }
        }
    }
}

int indexOfAkar(Tree P[], int N){
    /* Mencari indeks elemen array of Tree yang merupakan node utama (Akar) dari tree */
    
    int Temp[100];
    int result = -1;
    int idxNow = 0;
    int ID;
    boolean check;
    Tree PNow;
    for(int i = 0;i < N; i++){
        PNow = P[i];
        addrNode adr = FirstChild(PNow);
        for(int j = 0; j < BanyakChild(PNow); j++){
            ID = Akar(adr);
            check = false;
            for(int k = 0; k < idxNow;k++){
                if(Temp[k] == ID){
                    check = true;
                    break;
                }
            }
            if(!check){
                Temp[idxNow] = ID;
                idxNow++;
            }
            adr = Sibling(adr);
        }
    }
    for(int i = 0; i < N; i++){ 
        check = false;
        for(int k = 0; k <= idxNow;k++){
            if(Temp[k] == Akar(P[i])){
                check = true;
                break;
            }
        }
        if(!check){
            result = i;
            break;
        }
    }

    return result;
}

Tree mergeResep(Tree P[], int N){
    /* Melakukan merging tree-tree resepnya yang sudah dibuat dari konfigurasi file */
    int indexAkar = indexOfAkar(P, N);

    for(int i = 0;i < N;i++){
        for(int j = 0; j < N;j++){
            if(i != j){
                insertTree(&P[i], P[j]);
            }
        }
    }

    return P[indexAkar];
}

int pangkat (int x, int y) {
	/* Mengembalikan nilai dari x pangkat y */
	
	int ret = 1;
	for (int i = 1; i <= y; i++){
		ret = ret*x;
	}
	return ret;
}

int wordToInt (WordFile str) {
	/* Mengembalikan nilai integer dari WordFile yang dibaca */

	int val = 0;
	int k = 0;
	for (int i= str.Length-1; i >= 0; i--) {
		val += (str.TabWord[i]-48) * pangkat(10,k);
		k++;
	}
	return val;
}

Tree BacaResep(char fileName[]){
    /* Melakukan baca resep dari file konfigurasi */

    Tree Main;
    Tree T[100];
    int ID;
    int Child;
    startWordFile(fileName);
    int N = wordToInt(currentWordFile);
    advCharFile();
	advWordFile();
    for(int i = 0; i < N; i++){
        ID = wordToInt(currentWordFile);
        advWordFile();
        Child = wordToInt(currentWordFile);
        T[i] = AlokasiTree(ID, 0, NULL);
        int val;
        for(int j = 0; j < Child;j++){
            advWordFile();
            val = wordToInt(currentWordFile);
            AddDaunByID(&T[i], ID, val);
        }
        advCharFile();
        advWordFile();
    }
    Main = mergeResep(T, N);
    return Main;
}