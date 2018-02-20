/*
{Nama/NIM                  : Condro Wiyono	}
{Tanggal                    : 03 Oktober 2016}
{Topik                      : Abstract Data Type dan Array}
{Deskripsi                  : Ini adalah file haeder dari Abstract Data dari Array}
*/

#include <stdio.h>
#include "P03-18215042-031016-01.h"

const int IdxMax = 99;
const int IdxMin  = 0 ;
const int IdxUndef  = -999 ; /*{ indeks tak terdefinisi} */

#ifndef ARRAY2_C 
#define ARRAY2_C


void MakeEmpty (TabInt *T) {
/*{ I.S. sembarang }
{ F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 } */
	int i = IdxMin;
		
	for (i; i <= IdxMax-IdxMin+1 ;i++) {
		(*T).TI[i] = 0 ;
		(*T).Neff = 0 ; 
	}
}

/* ********** SELEKTOR ********** } */
/*{ *** Banyaknya elemen *** } */
int NbElmt (TabInt T) {
/*	{ Mengirimkan banyaknya elemen efektif tabel }
	{ Mengirimkan nol jika tabel kosong } */
	
	if (IsEmpty(T)) { 
		return 0; 
	} else {
		return T.Neff;
	}
}
/* { *** Daya tampung container *** } */
int MaxNbEl (TabInt T) {
/* { Mengirimkan maksimum elemen yang dapat ditampung oleh tabel } */
	return IdxMax;
	//gatau
}

/*{ *** Selektor INDEKS *** } */
IdxType GetFirstIdx (TabInt T) {
/*{ Prekondisi : Tabel T tidak kosong }
{ Mengirimkan indeks elemen pertama }*/
	return IdxMin;
}
IdxType GetLastIdx (TabInt T ){
/*{ Prekondisi : Tabel T tidak kosong }
{ Mengirimkan indeks elemen terakhir } */
	return T.Neff;

}
/*{ *** Menghasilkan sebuah elemen *** } */
ElType GetElmt (TabInt T, IdxType i) {
/*{ Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) }
{ Mengirimkan elemen tabel yang ke-i } */
	return T.TI[i];
}

/*{ *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** } */
/*{ Untuk type private/limited private pada bahasa tertentu }*/
void SetTab (TabInt Tin, TabInt *Tout) { 
/*{ I.S. Tin terdefinisi, sembarang }
  { F.S. Tout berisi salinan Tin } */
	int i = GetFirstIdx(Tin);
	
	for (i; i <= Tin.Neff ;i++) {
		(*Tout).TI[i] = Tin.TI[i] ;
		(*Tout).Neff = Tin.Neff ; 
	}
}

/*{ Assignment THsl -> Tin }*/
void SetEl (TabInt *T, IdxType i, ElType v) {
/*{ I.S. T terdefinisi, sembarang }
{ F.S. Elemen T yang ke-i bernilai v } */
	(*T).TI[i] = v ;
}
/*{ Mengeset nilai elemen tabel yang ke-i sehingga bernilai v } */
void SetNeff (TabInt *T, IdxType N) {
/*{ I.S. T terdefinisi, sembarang }
{ F.S. Nilai indeks efektif T bernilai N } */
/*{ Mengeset nilai indeks elemen efektif sehingga bernilai N }*/
	(*T).Neff = N ;
}

/*{ ********** Test Indeks yang valid ********** } */
bool IsIdxValid (TabInt T,IdxType i) {
/*{ Prekondisi : i sembarang } */
/*{ Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel }
{ yaitu antara indeks yang terdefinisi utk container} */
	if ((i>=IdxMin) && (i<=IdxMax)) {
		return true ;
	} else {
		return false ;
	}
}
bool IsIdxEff (TabInt T,IdxType i) {
/*{ Prekondisi : i sembarang}
{ Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel }
{ yaitu antara FirstIdx(T)..LastIdx(T) } */
	if ((i>=IdxMin) && (i<=T.Neff)) {
		return true ;
	} else {
		return false ;
	}
}

/*{ ********** TEST KOSONG/PENUH ********** } */

/*{ *** Test tabel kosong *** }*/
bool IsEmpty (TabInt T) {
/*{ Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak }*/
	if (T.Neff<=0) {
		return true ;
	} else {
		return false;
	}
}
/*{ *** Test tabel penuh *** }*/
bool IsFull (TabInt T){
/*{ Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak }*/
	if (T.Neff>=100) {
		return true ;
	} else {
		return false;
	}
}

/*{ ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** } */

/*{ *** Mendefinisikan isi tabel dari pembacaan *** } */
void BacaIsi (TabInt *T){
/*{ I.S. sembarang }
  { F.S. tabel T terdefinisi }
  { Proses : membaca banyaknya elemen T dan mengisi nilainya } */
	int i = IdxMin;
	int berapa ;
	int isinya ;
	
	printf("Jumlah elemen tabel ");
	scanf("%d",&berapa);
	
	(*T).Neff = -1;	
	
	for (i; i < berapa ;i++) {
		printf("Isi indeks ke-%d : ",i);
		scanf("%d",&isinya);
		(*T).TI[i] = isinya ;
		(*T).Neff++; 
	}
}
void TulisIsi (TabInt T) {
/*{ Proses : Menuliskan isi tabel dengan traversal }
{ I.S. T boleh kosong }
{ F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah }
{ Jika T kosong : Hanya menulis "Tabel kosong" } */
	//KAMUS
	int i = IdxMin;
	
	//ALGORITMA
	if (IsEmpty(T)) {
		printf("Tabel Kosong \n");
	} else {
		printf("=====TULIS TABEL=====\n");
		for (i; i <= T.Neff ;i++) {
			printf("Isi indeks ke-%d : "  ,i);
			printf("%d \n" ,T.TI[i]); 
		}
	}
}
void TulisIsiTab (TabInt T){
/*{ Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; antara dua elemen dipisahkan dengan separator "koma" }
{ I.S. T boleh kosong }
{ F.S. Jika T tidak kosong: [e1, e2, ... ,en] }
{ Contoh : jika ada tiga elemen bernilai 1, 20, 30 : [1, 20, 30] }
{ Jika tabel kosong : menulis [] }*/
	if (IsEmpty(T)) {
		printf("[]");
	} else {
		
		int i = GetFirstIdx(T);
		
		printf("[");
			for (i; i <= T.Neff ;i++) {
				printf("%d ," ,T.TI[i]);
			}
		printf("]");
	}
}

/*{ ********** OPERATOR ARITMATIKA ********** } */

/*{ *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** } */
TabInt PlusTab (TabInt T1,TabInt T2) {
/*{ Prekondisi : T1 dan T2 berukuran sama dan tidak kosong }
{ Mengirimkan T1 + T2 }*/
	int i = GetFirstIdx(T1);
	TabInt THasil;
	
	for (i; i <= T1.Neff ;i++) {
		THasil.TI[i] = T1.TI[i] + T2.TI[i] ;
		THasil.Neff = T1.Neff ; 
	}
	
	return THasil;

}
TabInt MinusTab (TabInt T1,TabInt T2){
/*{ Prekondisi : T1 dan T2 berukuran sama dan tidak kosong }
{ Mengirimkan T1 - T2 }*/
	int i = GetFirstIdx(T1);
	TabInt THasil;
	
	for (i; i <= T1.Neff ;i++) {
		THasil.TI[i] = T1.TI[i] - T2.TI[i] ;
		THasil.Neff = T1.Neff ; 
	}
	
	return THasil;

}





/* ********** NILAI EKSTREM ********** } */
ElType ValMax(TabInt T){
/*{ Prekondisi : Tabel T tidak kosong }
{ Mengirimkan nilai maksimum tabel }*/

  //KAMUS LOKAL
  ElType sekarang;
  int i;
  
  i = GetFirstIdx(T);
  sekarang = GetElmt(T,GetFirstIdx(T));
  do {
    if (sekarang>=GetElmt(T,i)) {
      sekarang = GetElmt(T,i);
      i++;
    } else { i++;}
    }
  while(i>=GetLastIdx(T));
  
  return sekarang;
}

ElType ValMin(TabInt T){
/*{ Prekondisi : Tabel T tidak kosong }
{ Mengirimkan nilai minimum tabel } */
  //KAMUS LOKAL
  ElType sekarang;
  int i;
  
  i = GetFirstIdx(T);
  sekarang = GetElmt(T,GetFirstIdx(T));
  do {
    if (sekarang<=GetElmt(T,i)) {
      sekarang = GetElmt(T,i) ;
      i++;
    } else { i++;} 
  }
  while(i>=GetLastIdx(T));
  
  return sekarang;

}
/*{ *** Mengirimkan indeks elemen bernilai ekstrem *** } */
IdxType IdxMaxTab (TabInt T) {
/* { Prekondisi : Tabel T tidak kosong }
  { Mengirimkan indeks i dengan elemen ke-i adalah nilai maksimum pada tabel 
}*/
  //KAMUS LOKAL
  ElType sekarang;
  int indeksnya;
  int i;
  
  indeksnya = GetFirstIdx(T);
  i = GetFirstIdx(T);
  sekarang = GetElmt(T,GetFirstIdx(T));
  do {
    if (sekarang>=GetElmt(T,i)) {
      sekarang = GetElmt(T,i) ;
      indeksnya = i;
      i++;
      } else
      { i++; }
    }
  while(i>=GetLastIdx(T));
  
  return i;
}

IdxType IdxMinTab (TabInt T){
/*{ Prekondisi : Tabel tidak kosong }
{ Mengirimkan indeks i }
{ dengan elemen ke-i nilai minimum pada  tabel } */

  //KAMUS LOKAL
  ElType sekarang;
  int indeksnya;
  int i;
  
  indeksnya = GetFirstIdx(T);
  i = GetFirstIdx(T);
  sekarang = GetElmt(T,GetFirstIdx(T));
  do {
    if (sekarang<=GetElmt(T,i)) {
      sekarang = GetElmt(T,i) ;
      indeksnya = i;
      i++;
      } else
      {
        i++;
      }
    }
  while(i>=GetLastIdx(T));
  
  return i;


}
/* { ********** SEARCHING ********** }
{ ***  Perhatian : Tabel boleh kosong!! *** } */

IdxType SearchTab (TabInt T, ElType X) {
/*{ Search apakah ada elemen tabel T yang bernilai X }
{ Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X }
{ Jika tidak ada, mengirimkan IdxUndef }
{ Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong }
{ Memakai skema search TANPA boolean */
    IdxType hasil;
    int i;
    
    
    i = GetFirstIdx(T);
    
    while (i<=GetLastIdx(T)) {
      if (GetElmt(T,i)==X) {
          hasil =  i;
      } else 
        { i++; }
    }
    
    if ((hasil>=GetFirstIdx(T)) && (hasil<=GetLastIdx(T))){
    return hasil;
  } else {
    return -999;
    }
}

/*
{ ********** MENAMBAH ELEMEN ********** }
{ *** Menambahkan elemen terakhir *** } */

void AddAsLastEl (TabInt Tin, TabInt *T, ElType X){
/*{ Menambahkan X sebagai elemen terakhir tabel }
{ I.S. Tabel boleh kosong, tetapi tidak penuh }
{ F.S. X adalah elemen terakhir T yang baru }
{ Proses : Menambahkan sebagai elemen ke-i yang baru } */
  
  int indekakhir;
  
  indekakhir = GetLastIdx(Tin) + 1;
  (*T).Neff = indekakhir ;
  (*T).TI[indekakhir] = X;

}
void  AddEli  (TabInt Tin, TabInt *T, ElType X, IdxType i){
/*{ Menambahkan  X  sebagai  elemen  ke-i  tabel  tanpa  mengganggu  kontiguitas terhadap elemen yang sudah ada }
{ I.S. Tabel tidak kosong dan tidak penuh }
{ i adalah indeks yang valid. }
{ F.S. X adalah elemen ke-i T yang baru }
{ Proses : Geser elemen ke-i+1 s.d. terakhir }
{Isi elemen ke-i dengan X }*/
  int indekisi ;
  int indekakhir;
  
  indekakhir = GetLastIdx(Tin) + 1;
  (*T).Neff = indekakhir ;
  
  (*T).TI[i] = X;
  for (i = i + 1; i <= indekakhir; i++) {
        (*T).TI[i] = Tin.TI[i-1];
  }
  

}
/*{ ********** MENGHAPUS ELEMEN ********** }*/

void DelLastEl (TabInt Tin, TabInt *T, ElType X){
/*Proses : Menghapus elemen terakhir tabel }
{ I.S. Tabel tidak kosong }
{ F.S. X adalah nilai elemen terakhir T sebelum penghapusan, }
{      Banyaknya elemen tabel berkurang satu }
{      Tabel T mungkin menjadi kosong }*/

  int indekakhir;
  
  indekakhir = GetLastIdx(Tin) - 1;
  (*T).Neff = indekakhir ;
  
}

void  DelEli(TabInt Tin, TabInt *T,  IdxType i , ElType *X) {
/*{ Proses : Menghapus elemen ke-i tabel }
{ I.S. Tabel tidak kosong, i adalah indeks efektif yang valid }
{ F.S. Elemen T berkurang satu }
{      Banyaknya elemen tabel berkurang satu }
{      Tabel T mungkin menjadi kosong }
{ Proses : Geser elemen ke-i+1 s.d. elemen terakhir }
{          Kurangi elemen efektif tabel }
*/

  int indekisi ;
  int indekakhir;
  
  indekakhir = GetLastIdx(Tin) - 1;
  (*T).Neff = indekakhir ;
  
  for (i ; i <= indekakhir; i++) {
        (*T).TI[i] = Tin.TI[i+1];
  }


}

#endif

