## BNMO
*“BNMO sedang memasak mengikuti program simulasi yang telah direkam Doni”*

BNMO sebuah robot game milik Indra dan Doni diminta untuk membantu Indra memasak makan malam Indra bersama dengan perempuan bernama Siska Kol. Namun, BNMO tidak bisa memasak dan tidak bisa mempelajarinya dari video youcub. Program simulasi ini dibuat agar BNMO dapat membuat makan malam yang terbaik untuk Indra dan Siska Kol dengan kemampuan untuk membuat makanan dengan pemilihan bahan makanan, penggunaan resep, dan teknik memasak.

Game ini adalah penerapan *abstract data type* dalam bahasa C. 

## Struktur Folder
Berikut daftar isi dalam program ini:
* Folder `doc` berisi laporan dan notulensi rapat internal kelompok
* Folder `src` berisi source program. Pada folder ini terdiri atas:
  * file program utama `main.c`
  * Folder `lib` berisi pustaka, driver pustaka, dan file header ADT
* Folder `build` berisi file *object* hasil kompilasi semua pustaka dan program utama
* Folder `config` berisi data makanan, resep, serta pemetaan map BNMO bersimulasi yang telah ditentukan.

## Prosedur Pemakaian Program
> Notes : Program ini dikompilasi menggunakan *Makefile*. Direkomendasikan untuk selalu mengompilasi ulang program sebelum menggunakan.

Pastikan bahwa gcc sudah diinstall pada OS Anda (gunakan gcc MinGW).

Berikut daftar isi prosedur pemakaian program ini:

1. Untuk mengompilasi program utama, jalankan
```
make main
```
2. Untuk mengonpilasi seluruh program, jalankan
```
make all
```
3. Untuk mengompilasi seluruh modul ADT, jalankan
```
make adt
```
4. Untuk menjalankan main program, jalankan
```
./build/main.exe
```
5. Untuk mengompilasi sebuah ADT 
```
make adt_<nama ADT>
```
6. Untuk menjalankan driver ADT sederhana, jalankan
```
./build/lib/adt/sederhana/main_<nama ADT>
```
7. Untuk menjalankan driver ADT tidak sederhana, jalankan
```
./build/lib/adt/non_sederhana/main_<nama ADT>
```
# Kontributor
Program ini dibuat dalam rangka memenuhi salah satu tugas besar mata kuliah Algoritma dan Struktur Data. Program ini dibuat oleh (K02 Kelompok )
1. Maggie Zeta Rosida `(13521117)`<br>
Inisiasi, Splash Screen, Laporan
2. Febryan Arota Hia `(13521120)`<br>
Peta, ADT Notifikasi, ADT Matrix, ADT Point, ADT Stack, Driver-Driver ADT, Laporan
3. Michael Jonathan Halim `(13521124)`<br>
Main Program, ADT Tree, ADT Set, ADT Kulkas, Bonus, ADT - ADT Lainnya, Fry, Chop, Boil, Mix, Delivery, Command-Command Lainnya, Laporan
4. Kenneth Dave Bahana `(13521145)`<br>
ADT PrioQueueTime, ADT Makanan, ADT Kulkas, Driver-Driver ADT, Laporan, Makefile, README 
5. Naufal Baldemar Ardanni `(13521154)`<br>
ADT Time, Laporan
6. Irgiansyah Mondo `(13521167)`<br>
Buy, Wait, Laporan

# Fitur/Command

<table>
<tr><td>No.</td><td>Command</td><td>Status</td></tr>
<tr><td>1.</td><td>START</td><td>Selesai</td></tr>
<tr><td>2.</td><td>BUY</td><td>Selesai</td></tr>
<tr><td>3.</td><td>DELIVERY</td><td>Selesai</td></tr>
<tr><td>4.</td><td>MOVE NORTH</td><td>Selesai</td></tr>
<tr><td>5.</td><td>MOVE EAST</td><td>Selesai</td></tr>
<tr><td>6.</td><td>MOVE WEST</td><td>Selesai</td></tr>
<tr><td>7.</td><td>MOVE SOUTH</td><td>Selesai</td></tr>
<tr><td>8.</td><td>MIX</td><td>Selesai</td></tr>
<tr><td>9.</td><td>CHOP</td><td>Selesai</td></tr>
<tr><td>10.</td><td>FRY</td><td>Selesai</td></tr>
<tr><td>11.</td><td>BOIL</td><td>Selesai</td></tr>
<tr><td>12.</td><td>WAIT X Y</td><td>Selesai</td></tr>
<tr><td>13.</td><td>CATALOG</td><td>Selesai</td></tr>
<tr><td>14.</td><td>COOKBOOK</td><td>Selesai</td></tr>
<tr><td>15.</td><td>UNDO</td><td>Selesai</td></tr>
<tr><td>16.</td><td>REDO</td><td>Selesai</td></tr>
<tr><td>17.</td><td>INVENTORY</td><td>Selesai</td></tr>
<tr><td>18.</td><td>RECOMMENDATION</td><td>Selesai</td></tr>
<tr><td>19.</td><td>KULKAS</td><td>Selesai</td></tr>
<tr><td>20.</td><td>EXIT</td><td>Selesai</td></tr>
</table>
