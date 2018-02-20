/*
{Nama/NIM                  : Condro Wiyono	}
{Tanggal                    : 03 Oktober 2016}
{Topik                      : Abstract Data Type dan Array}
{Deskripsi                  : Ini adalah file haeder dari Abstract Data dari Array}
*/

typedef int bool; 
#define true 1 
#define false 0

#define IdxType int 
#define ElType int

#ifndef ARRAY2_H 
#define ARRAY2_H
/* 	MODUL TABEL INTEGER }
	{ Berisi definisi dan semua primitif pemrosesan tabel integer }
	{ Penempatan elemen selalu rapat kiri }
	{ Versi I : dengan banyaknya elemen didefinisikan secara eksplisit, memori tabel statik }*/


/*{ Definisi elemen dan koleksi objek } */ 


/*type IdxType : integer { type indeks } */
/*type ElType : integer { type elemen tabel } */
typedef struct { 
	int TI[100]; 	//{ memori tempat penyimpan elemen (container) } 
	int Neff; 		//{ banyaknya elemen efektif }
} TabInt; 
/*{ Indeks yang digunakan [IdxMin..IdxMax] }
{ Jika T adalah TabInt, cara deklarasi dan akses: }
{ Deklarasi : T : TabInt }
{ Maka cara akses:
T.Neff untuk mengetahui banyaknya elemen
T.TI untuk mengakses seluruh nilai elemen tabel
T.TI[i] untuk mengakses elemen ke-i } */

/*{ Definisi :
Tabel kosong: T.Neff = 0
Definisi elemen pertama : T.TI[i] dengan i=1
Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff } */

/*{ ********** KONSTRUKTOR ********** } */
/*{ Konstruktor : create tabel kosong } */

void MakeEmpty (TabInt *T);
/*{ I.S. sembarang }
{ F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 } */

/* ********** SELEKTOR ********** } */
/*{ *** Banyaknya elemen *** } */
int NbElmt (TabInt T);
/*	{ Mengirimkan banyaknya elemen efektif tabel }
	{ Mengirimkan nol jika tabel kosong } */

/* { *** Daya tampung container *** } */
int MaxNbEl (TabInt T) ;
/* { Mengirimkan maksimum elemen yang dapat ditampung oleh tabel } */

/*{ *** Selektor INDEKS *** } */
IdxType GetFirstIdx (TabInt T); 
/*{ Prekondisi : Tabel T tidak kosong }
{ Mengirimkan indeks elemen pertama }*/

IdxType GetLastIdx (TabInt T );
/*{ Prekondisi : Tabel T tidak kosong }
{ Mengirimkan indeks elemen terakhir } */


/*{ *** Menghasilkan sebuah elemen *** } */
ElType GetElmt (TabInt T, IdxType i) ;
/*{ Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) }
{ Mengirimkan elemen tabel yang ke-i } */

/*{ *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** } */
/*{ Untuk type private/limited private pada bahasa tertentu }*/
void SetTab (TabInt Tin, TabInt *Tout); 
/*{ I.S. Tin terdefinisi, sembarang }
  { F.S. Tout berisi salinan Tin } */

/*{ Assignment THsl -> Tin }*/
void SetEl (TabInt *T, IdxType i, ElType v);
/*{ I.S. T terdefinisi, sembarang }
{ F.S. Elemen T yang ke-i bernilai v } */

/*{ Mengeset nilai elemen tabel yang ke-i sehingga bernilai v } */
void SetNeff (TabInt *T, IdxType N);
/*{ I.S. T terdefinisi, sembarang }
{ F.S. Nilai indeks efektif T bernilai N } */

/*{ Mengeset nilai indeks elemen efektif sehingga bernilai N }*/

/*{ ********** Test Indeks yang valid ********** } */
bool IsIdxValid (TabInt T,IdxType i);
/*{ Prekondisi : i sembarang } */

/*{ Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel }
{ yaitu antara indeks yang terdefinisi utk container} */
bool IsIdxEff (TabInt T,IdxType i) ;
/*{ Prekondisi : i sembarang}
{ Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel }
{ yaitu antara FirstIdx(T)..LastIdx(T) } */

/*{ ********** TEST KOSONG/PENUH ********** } */

/*{ *** Test tabel kosong *** }*/
bool IsEmpty (TabInt T); 
/*{ Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak }*/

/*{ *** Test tabel penuh *** }*/
bool IsFull (TabInt T);
/*{ Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak }*/

/*{ ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** } */

/*{ *** Mendefinisikan isi tabel dari pembacaan *** } */
void BacaIsi (TabInt *T);
/*{ I.S. sembarang }
  { F.S. tabel T terdefinisi }
  { Proses : membaca banyaknya elemen T dan mengisi nilainya } */

void TulisIsi (TabInt T);
/*{ Proses : Menuliskan isi tabel dengan traversal }
{ I.S. T boleh kosong }
{ F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah }
{ Jika T kosong : Hanya menulis "Tabel kosong" } */

void TulisIsiTab (TabInt T);
/*{ Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; antara dua elemen dipisahkan dengan separator "koma" }
{ I.S. T boleh kosong }
{ F.S. Jika T tidak kosong: [e1, e2, ... ,en] }
{ Contoh : jika ada tiga elemen bernilai 1, 20, 30 : [1, 20, 30] }
{ Jika tabel kosong : menulis [] }*/

/*{ ********** OPERATOR ARITMATIKA ********** } */

/*{ *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** } */
TabInt PlusTab (TabInt T1,TabInt T2) ;
/*{ Prekondisi : T1 dan T2 berukuran sama dan tidak kosong }
{ Mengirimkan T1 + T2 }*/

TabInt MinusTab (TabInt T1,TabInt T2);
/*{ Prekondisi : T1 dan T2 berukuran sama dan tidak kosong }
{ Mengirimkan T1 - T2 }*/







/* ********** NILAI EKSTREM ********** } */
ElType ValMax (TabInt T);
/*{ Prekondisi : Tabel T tidak kosong }
{ Mengirimkan nilai maksimum tabel }*/

ElType ValMin (TabInt T); 
/*{ Prekondisi : Tabel T tidak kosong }
{ Mengirimkan nilai minimum tabel } */

/*{ *** Mengirimkan indeks elemen bernilai ekstrem *** } */
IdxType IdxMaxTab (TabInt T) ;
/* { Prekondisi : Tabel T tidak kosong }
  { Mengirimkan indeks i dengan elemen ke-i adalah nilai maksimum pada tabel 
}*/
IdxType IdxMinTab (TabInt T) ;
/*{ Prekondisi : Tabel tidak kosong }
{ Mengirimkan indeks i }
{ dengan elemen ke-i nilai minimum pada  tabel } */

/* { ********** SEARCHING ********** }
{ ***  Perhatian : Tabel boleh kosong!! *** } */

IdxType SearchTab (TabInt T, ElType X) ;
/*{ Search apakah ada elemen tabel T yang bernilai X }
{ Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X }
{ Jika tidak ada, mengirimkan IdxUndef }
{ Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong }
{ Memakai skema search TANPA boolean */

/*
{ ********** MENAMBAH ELEMEN ********** }
{ *** Menambahkan elemen terakhir *** } */

void AddAsLastEl (TabInt Tin, TabInt *T, ElType X);
/*{ Menambahkan X sebagai elemen terakhir tabel }
{ I.S. Tabel boleh kosong, tetapi tidak penuh }
{ F.S. X adalah elemen terakhir T yang baru }
{ Proses : Menambahkan sebagai elemen ke-i yang baru } */

void  AddEli  (TabInt Tin,TabInt *T, ElType X, IdxType i);
/*{ Menambahkan  X  sebagai  elemen  ke-i  tabel  tanpa  mengganggu  kontiguitas terhadap elemen yang sudah ada }
{ I.S. Tabel tidak kosong dan tidak penuh }
{ i adalah indeks yang valid. }
{ F.S. X adalah elemen ke-i T yang baru }
{ Proses : Geser elemen ke-i+1 s.d. terakhir }
{Isi elemen ke-i dengan X }

*/

/*{ ********** MENGHAPUS ELEMEN ********** }*/
void DelLastEl (TabInt Tin,TabInt *T, ElType X);
/*Proses : Menghapus elemen terakhir tabel }
{ I.S. Tabel tidak kosong }
{ F.S. X adalah nilai elemen terakhir T sebelum penghapusan, }
{      Banyaknya elemen tabel berkurang satu }
{      Tabel T mungkin menjadi kosong }*/

void  DelEli(TabInt Tin,TabInt *T,  IdxType i , ElType *X);
/*{ Proses : Menghapus elemen ke-i tabel }
{ I.S. Tabel tidak kosong, i adalah indeks efektif yang valid }
{ F.S. Elemen T berkurang satu }
{      Banyaknya elemen tabel berkurang satu }
{      Tabel T mungkin menjadi kosong }
{ Proses : Geser elemen ke-i+1 s.d. elemen terakhir }
{          Kurangi elemen efektif tabel }
*/


#endif
