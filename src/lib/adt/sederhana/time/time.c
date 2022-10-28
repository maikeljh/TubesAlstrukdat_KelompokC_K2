/* Fail: time.c */
/* Implementasi ADT TIME */

#include <stdio.h>
#include "time.h"

/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TIPE                                   */
/* ***************************************************************** */
boolean IsTIMEValid (int D, int H, int M)
/* Mengirim true jika D, H, M dapat membentuk TIME yang valid */
/* Dipakai untuk mengetes SEBELUM membentuk sebuah TIME */
{
    /* KAMUS LOKAL */

    /* ALGORITMA */
    return ((D >= 0) && (H >= 0 && H <= 23) && (M >= 0 && M <= 59));
}

/* *** Konstruktor: Membentuk Sebuah TIME dari Komponen-komponennya *** */
void CreateTime (TIME * T, int DD, int HH, int MM)
/* Membentuk sebuah TIME dari komponen-komponennya yang valid */
/* Prekondisi: DD, HH, MM valid untuk membentuk TIME. */
{
    /* KAMUS LOKAL */

    /* ALGORITMA */
    Day(*T) = DD;
    Hour(*T) = HH;
    Minute(*T) = MM;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaTIME (TIME * T)
/* IS     : T tidak terdefinisi. */
/* FS     : T terdefinisi dan merupakan TIME yang valid. */
/* Proses : Mengulangi membaca komponen DD, HH, MM sehingga membentuk T */
/* yang valid. Tidak mungkin dihasilkan T yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen DD, HH, MM
   dalam satu baris, masing-masing dipisahkan satu spasi, dan diakhiri enter. */
/* Jika TIME tidak valid, diberikan pesan "TIME tidak valid.", dan pembacaan
   diulangi hingga didapatkan TIME yang valid. */
/* Contoh: 
   1 24 3
   TIME tidak valid.
   1 3 4
   --> Akan terbentuk TIME <1,3,4> */
{
    /* KAMUS LOKAL */
    int D, H, M;

    /* ALGORITMA */
    while (true) {
        scanf("%d %d %d", &D, &H, &M);
        if (IsTIMEValid(D,H,M))
            break;
        else
            printf("Jam tidak valid\n");
    }
    CreateTime(T, D, H, M);
}
   
void TulisTIME (TIME T)
/* IS     : T sebarang. */
/* FS     : Nilai T ditulis dengan format DD:HH:MM. */
/* Proses : Menulis nilai tiap komponen T ke layar dalam format DD:HH:MM
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi dan enter */ 
{
    /* KAMUS LOKAL */

    /* ALGORITMA */
    printf("%02d:%02d:%02d", Day(T), Hour(T), Minute(T));
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TIPE                                   */
/* ***************************************************************** */
long TIMEToMenit (TIME T)
/* Diberikan sebuah TIME, TIME dikonversi menjadi jumlah menit. */
/* Rumus: menit = 24 * 60 * DD + 60 * HH + MM */
{
    /* KAMUS LOKAL */

    /* ALGORITMA */
    return (24*60*Day(T) + 60*Hour(T) + Minute(T));
}

TIME MenitToTIME (long N)
/* Mengirim konversi jumlah menit ke TIME */
{
    /* KAMUS LOKAL */
    int day, hour, minute;
    TIME newTime;

    /* ALGORITMA */
    day = N / (24*60);
    hour = (N % (24*60)) / 60;
    minute = (N % (24*60)) % 60;
    CreateTime(&newTime, day, hour, minute);
    return newTime;
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TIPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean TEQ (TIME T1, TIME T2)
/* Mengirimkan true jika T1 = T2 atau false jika tidak */
{
    /* KAMUS LOKAL */

    /* ALGORITMA */
    return (TIMEToMenit(T1) == TIMEToMenit(T2));
}

boolean TNEQ (TIME T1, TIME T2)
/* Mengirimkan true jika T1 tidak sama dengan T2 */
{
    /* KAMUS LOKAL */

    /* ALGORITMA */
    return (TIMEToMenit(T1) != TIMEToMenit(T2));
}

boolean TLT (TIME T1, TIME T2)
/* Mengirimkan true jika T1 < T2 atau false jika tidak */
{
    /* KAMUS LOKAL */

    /* ALGORITMA */
    return (TIMEToMenit(T1) < TIMEToMenit(T2));
}

boolean TGT (TIME T1, TIME T2)
/* Mengirimkan true jika T1 > T2 atau false jika tidak */
{
    /* KAMUS LOKAL */

    /* ALGORITMA */
    return (TIMEToMenit(T1) > TIMEToMenit(T2));
}

/* *** Operator Aritmetika TIME *** */
TIME NextMenit (TIME T)
/* Mengirim 1 menit setelah T dalam bentuk TIME */
{
    /* KAMUS LOKAL */
    TIME newTime;
    long menit;

    /* ALGORITMA */
    menit = TIMEToMenit(T) + 1;
    newTime = MenitToTIME(menit);
    return newTime;
}

TIME NextNMenit (TIME T, int N)
/* Mengirim N menit setelah T dalam bentuk TIME */
{
    /* KAMUS LOKAL */
    TIME newTime;
    long menit;

    /* ALGORITMA */
    menit = TIMEToMenit(T) + N;
    newTime = MenitToTIME(menit);
    return newTime;
}

TIME PrevMenit (TIME T)
/* Mengirim 1 menit sebelum T dalam bentuk TIME */
{
    /* KAMUS LOKAL */
    TIME newTime;
    long menit;

    /* ALGORITMA */
    menit = TIMEToMenit(T) - 1;
    newTime = MenitToTIME(menit);
    return newTime;
}

TIME PrevNMenit (TIME T, int N)
/* Mengirim N menit sebelum T dalam bentuk TIME */
{
    /* KAMUS LOKAL */
    TIME newTime;
    long menit;

    /* ALGORITMA */
    menit = TIMEToMenit(T) - N;
    newTime = MenitToTIME(menit);
    return newTime;
}

/* *** Kelompok Operator Aritmetika *** */
long Durasi (TIME TAw, TIME TAkh)
/* Mengirim dalam menit TAkh - TAw jika TAw < TAkh atau TAw - TAkh */
/* jika TAw > TAkh dengan kalkulasi */
{
    /* KAMUS LOKAL */
    long durasi;

    /* ALGORITMA */
    if (TGT(TAw, TAkh))
        durasi = TIMEToMenit(TAw) - TIMEToMenit(TAkh);
    else
        durasi = TIMEToMenit(TAkh) - TIMEToMenit(TAw);
    return durasi;
}