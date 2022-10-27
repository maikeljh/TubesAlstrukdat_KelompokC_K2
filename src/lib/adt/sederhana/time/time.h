/* Fail: time.h */
/* Definisi ADT TIME */

#ifndef TIME_H
#define TIME_H

#include "../../boolean.h"

/* *** Definisi Tipe TIME <DD:HH:MM> *** */
typedef struct {
   int DD;
	int HH; /* integer [0..23] */
	int MM; /* integer [0..59] */
} TIME;

/* *** Notasi Akses: Selektor TIME *** */
#define Day(T) (T).DD
#define Hour(T) (T).HH
#define Minute(T) (T).MM

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TIPE                                   */
/* ***************************************************************** */
boolean IsTIMEValid (int D, int H, int M);
/* Mengirim true jika D, H, M dapat membentuk TIME yang valid */
/* Dipakai untuk mengetes SEBELUM membentuk sebuah TIME */

/* *** Konstruktor: Membentuk Sebuah TIME dari Komponen-komponennya *** */
void CreateTime (TIME * T, int DD, int HH, int MM);
/* Membentuk sebuah TIME dari komponen-komponennya yang valid */
/* Prekondisi: DD, HH, MM valid untuk membentuk TIME. */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaTIME (TIME * T);
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
   
void TulisTIME (TIME T);
/* IS     : T sebarang. */
/* FS     : Nilai T ditulis dengan format DD:HH:MM. */
/* Proses : Menulis nilai tiap komponen T ke layar dalam format DD:HH:MM
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi dan enter */ 

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TIPE                                   */
/* ***************************************************************** */
long TIMEToMenit (TIME T);
/* Diberikan sebuah TIME, TIME dikonversi menjadi jumlah menit. */
/* Rumus: menit = 24 * 60 * DD + 60 * HH + MM */

TIME MenitToTIME (long N); 
/* Mengirim konversi jumlah menit ke TIME */

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TIPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relasional *** */
boolean TEQ (TIME T1, TIME T2);
/* Mengirimkan true jika T1 = T2 atau false jika tidak */
boolean TNEQ (TIME T1, TIME T2);
/* Mengirimkan true jika T1 tidak sama dengan T2 */
boolean TLT (TIME T1, TIME T2);
/* Mengirimkan true jika T1 < T2 atau false jika tidak */
boolean TGT (TIME T1, TIME T2);
/* Mengirimkan true jika T1 > T2 atau false jika tidak */
/* *** Operator Aritmetika TIME *** */
TIME NextMenit (TIME T);
/* Mengirim 1 menit setelah T dalam bentuk TIME */
TIME NextNMenit (TIME T, int N);
/* Mengirim N menit setelah T dalam bentuk TIME */
TIME PrevMenit (TIME T);
/* Mengirim 1 menit sebelum T dalam bentuk TIME */
TIME PrevNMenit (TIME T, int N);
/* Mengirim N menit sebelum T dalam bentuk TIME */
/* *** Kelompok Operator Aritmetika *** */
long Durasi (TIME TAw, TIME TAkh);
/* Mengirim dalam menit TAkh - TAw jika TAw < TAkh atau TAw - TAkh */
/* jika TAw > TAkh dengan kalkulasi */

#endif