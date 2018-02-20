/*
/*Nama/NIM                  : Condro Wiyono	*/
/*Tanggal                    : 17 Oktober 2016*/
/*Topik                      : ADT MATRIKS*/
/*Deskripsi                  : Ini adalah file haeder dari ADT Matriks*/

typedef int bool; 
#define true 1 
#define false 0

#ifndef MATRIKS_H
#define MATRIKS_H
typedef int indeks;

#define BrsMin 1 // indeks
#define BrsMax 100 //indeks
#define KolMin 1 //indeks
#define KolMax 100 //indeks

typedef int el_type;

typedef struct {
	el_type Mem[BrsMax-BrsMin][KolMax-KolMin];
	int NBrsEff;
	int NKolEff;
} MATRIKS ; 


/* ********** DEFINISI PROTOTIPE PRIMITIF ***********/
/* *** Konstruktor membentuk MATRIKS *** */

void MakeMATRIKS(MATRIKS *M, int NB, int NK);
/*/*Membentuk sebuah MATRIKS “kosong” berukuran NB x NK di “ujung kiri” memori*/
/*I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/*F.S. sebuah matriks sesuai dengan def di atas terbentuk pada parameter
pertama */

bool IsIdxValid(indeks i, indeks j);
/*/* Mengirimkan true jika i, j adalah indeks yang valid */
/* *** Untuk sebuah matriks M yang terdefinisi: *** */

indeks FirstIdxBrs(MATRIKS M);
/* Mengirimkan indeks baris terkecil M */

indeks FirstIdxKol(MATRIKS M) ;
/* Mengirimkan indeks kolom terkecil M */

indeks LastIdxBrs(MATRIKS M);
/* Mengirimkan indeks baris terbesar M */

indeks LastIdxKol(MATRIKS M);
/* Mengirimkan indeks kolom terbesar M */

indeks GetNBrsEff(MATRIKS M);
/* Mengirimkan banyaknya baris efektif M */

indeks GetNKolEff(MATRIKS M);
/* Mengirimkan banyaknya kolom efektif M */
el_type GetElmt(MATRIKS M, indeks i, indeks j);
/* Mengirimkan elemen M dg nomor baris i dan nomor kolom j */
/* *** Operasi mengubah nilai elemen matriks: Set / Assign *** */

void SetBrsEff(MATRIKS *Mout, int NB);
/* I.S. M sudah terdefinisi */
/* F.S. Nilai M.BrsEff diisi dengan NB, */

void SetKolEff(MATRIKS *Mout, int NK);
/* I.S. M sudah terdefinisi */
/* F.S. Nilai M.NKolEff diisi dengan NK */ 

void SetEl(MATRIKS *Mout, int i, int j, el_type X);
/* I.S. M sudah terdefinisi */
/* F.S. M(i,j) bernilai X */
/* Proses: Mengisi M(i,j) dengan X */

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS(MATRIKS *M, int NB, int NK);
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, dan berukuran NB x NK */
/* Melakukan MakeMatriks(M,NB,NK) dan mengisi nilai efektifnya */
/* dari pembacaan dengan traversal per baris */

void TulisMATRIKS(MATRIKS M);
/* I.S. M terdefinisi */
/* F.S. Sama dengan I.S, dan nilai M(i,j) ditulis ke layar*/
/* Menulis Nilai setiap indeks dan elemen M ke layar */
/* dengan traversal per baris */

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
MATRIKS dotproduct (MATRIKS M1, MATRIKS M2);
/* Prekondisi : Ukuran Baris efektif M = ukuran kolom efektif M */
/* Mengirim hasil perkalian matriks: salinan M1 . M2 */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
bool IsEqual(MATRIKS M1, MATRIKS M2);
/* Mengirimkan true jika M1 = M2, */
/* yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom */
/* M1(i,j) = M2(i,j) */
/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */

bool IsIdentitas(MATRIKS M);
/* Mengirimkan true jika M adalah matriks satuan: dimana ukuran baris dan
kolom sama besar dan setiap elemen diagonal M bernilai 1 dan elemen yang
bukan diagonal bernilai 0 */

/*{ ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** } */
bool EQSize(MATRIKS M1, MATRIKS  M2); 
/*{ Mengirimkan true jika ukuran efektif matriks M1 sama dengan }
{ ukuran efektif M2 }
{ yaitu GetBrsEff(M1)= GetNBrsEff (M2) dan GetNKolEff(M1)=GetNKolEff (M2) }*/

bool kurangDari(MATRIKS M1, MATRIKS  M2); 
/*{ Mengirimkan true jika ukuran efektif M1 < Ukuran efektif M2 } */

/*{ ********** KELOMPOK TEST TERHADAP MATRIKS ********** }  */
bool IsBujurSangkar(MATRIKS M); 
/*{ Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama } */

bool IsSymetri(MATRIKS M);
/*{ Mengirimkan  true  jika  M  adalah  matriks  simetri  :  IsBujurSangkar(M)  dan 
untuk setiap elemen M, M(i,j)=M(j,i) } */

MATRIKS tambah(MATRIKS M1,MATRIKS M2); 
/*{ Prekondisi : M1 berukuran sama dengan M2 } 
{ Mengirim hasil penjumlahan matriks: M1 + M2 } 
{ Jika ukuran matriks tidak seharusnya, mengirimkan M1 dengan nilai elemen [1][1] diganti menjadi -999} */

MATRIKS kurang(MATRIKS M1,MATRIKS M2); 
/*{ Prekondisi : M berukuran sama dengan M } 
{ Mengirim hasil pengurangan matriks: salinan M1 –M2 } 
{ Jika ukuran matriks tidak seharusnya, mengirimkan M1 dengan nilai elemen 
[1][1] diganti menjadi -999} */


void Transpose(MATRIKS Min, MATRIKS *Mout); 
/*{ I.S. M terdefinisi } 
{ F.S. M “di-transpose”, yaitu setiap elemen M(i,j) ditukar nilainya dengan 
elemen M(j,i) } */

float Determinan(MATRIKS M);
/*{ Prekondisi : Ukuran Matriks 2x2 atau Matriks 3x3 } 
{ Menghasilkan determinan matriks 2x2 bertipe real }
{  Jika  ukuran  matriks  tidak  seharusnya,  beri  peringatan  dan  menghasilkan 
nilai -999}*/

 
#endif
