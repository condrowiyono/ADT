/*
/*Nama/NIM                  : Condro Wiyono	*/
/*Tanggal                    : 17 Oktober 2016*/
/*Topik                      : ADT MATRIKS*/
/*Deskripsi                  : Ini adalah file BODY / IMPLEMENTASI dari ADT Matriks*/

#ifndef MATRIKS_C
#define MATRIKS_C

#include <stdio.h>
#include "P04-18215042-171016-01.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ***********/
/* *** Konstruktor membentuk MATRIKS *** */

void MakeMATRIKS(MATRIKS *M, int NB, int NK) {
/*/*Membentuk sebuah MATRIKS “kosong” berukuran NB x NK di “ujung kiri” memori*/
/*I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/*F.S. sebuah matriks sesuai dengan def di atas terbentuk pada parameter pertama */
	(*M).NBrsEff = NB;
	(*M).NKolEff = NK;
}
bool IsIdxValid(indeks i, indeks j) {
/*/* Mengirimkan true jika i, j adalah indeks yang valid */
/* *** Untuk sebuah matriks M yang terdefinisi: *** */
	return (((i>=BrsMin) && (i<=BrsMax)) && ((j>=KolMin) && (j<=KolMax))) ;
}
indeks FirstIdxBrs(MATRIKS M){
/* Mengirimkan indeks baris terkecil M */
	return BrsMin; 
}
indeks FirstIdxKol(MATRIKS M) {
/* Mengirimkan indeks kolom terkecil M */
	return KolMin;
}
indeks LastIdxBrs(MATRIKS M) {
/* Mengirimkan indeks baris terbesar M */
	return BrsMax;
}
indeks LastIdxKol(MATRIKS M){
/* Mengirimkan indeks kolom terbesar M */
	return KolMax;
}
indeks GetNBrsEff(MATRIKS M){
/* Mengirimkan banyaknya baris efektif M */
	return M.NBrsEff;
}
indeks GetNKolEff(MATRIKS M){
/* Mengirimkan banyaknya kolom efektif M */
	return M.NKolEff;
}
el_type GetElmt(MATRIKS M, indeks i, indeks j) {
/* Mengirimkan elemen M dg nomor baris i dan nomor kolom j */
/* *** Operasi mengubah nilai elemen matriks: Set / Assign *** */
	return M.Mem[i][j];
}
void SetBrsEff(MATRIKS *Mout, int NB){
/* I.S. M sudah terdefinisi */
/* F.S. Nilai M.BrsEff diisi dengan NB, */
	(*Mout).NBrsEff = NB ;
}

void SetKolEff(MATRIKS *Mout, int NK) {
/* I.S. M sudah terdefinisi */
/* F.S. Nilai M.NKolEff diisi dengan NK */ 
	(*Mout).NKolEff = NK ;
}

void SetEl(MATRIKS *Mout, int i, int j, el_type X){
/* I.S. M sudah terdefinisi */
/* F.S. M(i,j) bernilai X */
/* Proses: Mengisi M(i,j) dengan X */
	(*Mout).Mem[i][j] = X;
}

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS(MATRIKS *M, int NB, int NK){
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, dan berukuran NB x NK */
/* Melakukan MakeMatriks(M,NB,NK) dan mengisi nilai efektifnya */
/* dari pembacaan dengan traversal per baris */
	int i,j;
	el_type X;

	(*M).NBrsEff= NB;
	(*M).NKolEff= NK;
	
	for (i = BrsMin;i <= NB; i++) {
		for (j = KolMin;j <= NK; j++) {
			printf("Isi matriks ke-(%d,%d) :",i,j);
			scanf("%d",&X);
			(*M).Mem[i][j] = X;
		};
	};

}
void TulisMATRIKS(MATRIKS M){
/* I.S. M terdefinisi */
/* F.S. Sama dengan I.S, dan nilai M(i,j) ditulis ke layar*/
/* Menulis Nilai setiap indeks dan elemen M ke layar */
/* dengan traversal per baris */
	int i,j;
	el_type X;
	
	for (i = BrsMin; i <= M.NBrsEff; i++) {
		for (j = KolMin; j <= M.NKolEff ; j++) {
			printf("%d ",M.Mem[i][j]);		
		};
		printf("\n");
	};
	
}
/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
MATRIKS dotproduct (MATRIKS M1, MATRIKS M2){
/* Prekondisi : Ukuran Baris efektif M = ukuran kolom efektif M */
/* Mengirim hasil perkalian matriks: salinan M1 . M2 */
	int i,j,k ;
    int sum = 0;
    MATRIKS Mout;
    
    Mout.NBrsEff = M1.NBrsEff;
    Mout.NKolEff = M2.NBrsEff;
    
    for ( i = BrsMin ; i <= M1.NBrsEff ; i++ )
    {
      for ( j = KolMin ; j <= M2.NKolEff ; j++ )
      {
        for ( k=1; k <= M1.NKolEff ; k++ )
        {
          sum = sum + M1.Mem[i][k] * M2.Mem[k][j];
        }
 
        Mout.Mem[i][j] = sum;
        sum = 0;
      }
    }
    
    return Mout;

}
/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
bool IsEqual(MATRIKS M1, MATRIKS M2) {
/* Mengirimkan true jika M1 = M2, */
/* yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom */
/* M1(i,j) = M2(i,j) */
	bool found = false;
	int i,j ;
	i = BrsMin;
	j = KolMin;
	
	while ((!found) && (i <= M1.NBrsEff)) {
		while ((!found) && (j <= M1.NKolEff)) {
			if (M1.Mem[i][j] != M2.Mem[i][j])  {
				found = true ;
			} else {
				j = j + 1;
			}	
		}
		i = i + 1;
	}
	
	if (found==true) {
		return false;
	} else {
		return true;
	}
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
bool IsIdentitas (MATRIKS M){
/* Mengirimkan true jika M adalah matriks satuan: dimana ukuran baris dan
kolom sama besar dan setiap elemen diagonal M bernilai 1 dan elemen yang
bukan diagonal bernilai 0 */
	bool found = false;
	int i,j ;
	i = BrsMin;
	j = KolMin;
	
	while ((!found) && (i <= M.NBrsEff)) {
		while ((!found) && (j <= M.NKolEff)) {
			if (i==j) {
				if (M.Mem[i][j]!=1)  {
					found = true ;
				} else {
					j = j + 1;
				}
			} else {
				if (M.Mem[i][j]!=0)  {
					found = true ;
				} else {
					j = j + 1;
				}
			}	
		}
		i = i + 1;
	}
	
	if (found==true) {
		return false;
	} else {
		return true;
	}
}

/*{ ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** } */
bool EQSize(MATRIKS M1, MATRIKS M2) {
/*{ Mengirimkan true jika ukuran efektif matriks M1 sama dengan }
{ ukuran efektif M2 }
{ yaitu GetBrsEff(M1)= GetNBrsEff (M2) dan GetNKolEff(M1)=GetNKolEff (M2) }*/
	return ((GetNBrsEff(M1)==GetNBrsEff(M1)) && (GetNKolEff(M1)==GetNKolEff(M2)));  
}
bool kurangDari(MATRIKS M1, MATRIKS M2) {
/*{ Mengirimkan true jika ukuran efektif M1 < Ukuran efektif M2 } */
	return ((GetNBrsEff(M1)<GetNBrsEff(M1)) || (GetNKolEff(M1)<GetNKolEff(M2)));
}

/*{ ********** KELOMPOK TEST TERHADAP MATRIKS ********** }  */
bool IsBujurSangkar(MATRIKS M) {
/*{ Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama } */
	return (GetNBrsEff(M)==GetNKolEff(M));
}
bool IsSymetri(MATRIKS M){
/*{ Mengirimkan  true  jika  M  adalah  matriks  simetri  :  IsBujurSangkar(M)  dan 
untuk setiap elemen M, M(i,j)=M(j,i) } */
	//KAMUS
	int i = BrsMin;
	int j = KolMin;
	
	//ALGORITMA
	
	if (IsBujurSangkar(M)) {
		for (i = BrsMin; i <= M.NBrsEff; i++) {
			for (j = KolMin; j <= M.NKolEff ; j++) {
				if (M.Mem[i][j]==M.Mem[j][i]) {
					return true;
				} else 
					return false;
			}
		}
	} else {
		return false;
	}
}
MATRIKS tambah(MATRIKS M1, MATRIKS M2) {
/*{ Prekondisi : M1 berukuran sama dengan M2 } 
{ Mengirim hasil penjumlahan matriks: M1 + M2 } 
{ Jika ukuran matriks tidak seharusnya, mengirimkan M1 dengan nilai elemen [1][1] diganti menjadi -999} */
	//KAMUS
	int i = BrsMin;
	int j = KolMin;
	MATRIKS Mout;
	
	
	//ALGORITMA
	
	if (EQSize(M1,M2)==true) {
		MakeMATRIKS(&Mout,M1.NBrsEff,M1.NKolEff);
		for (i = BrsMin; i <= Mout.NBrsEff; i++) {
			for (j = KolMin; j <= Mout.NKolEff ; j++) {
				 Mout.Mem[i][j] = M1.Mem[i][j] + M2.Mem[i][j] ;
			};
		}
	} else {
		MakeMATRIKS(&Mout,1,1);
		Mout.Mem[1][1] = -999;
	} 
	return Mout;
}
MATRIKS kurang(MATRIKS M1, MATRIKS M2) {
/*{ Prekondisi : M berukuran sama dengan M } 
{ Mengirim hasil pengurangan matriks: salinan M1 –M2 } 
{ Jika ukuran matriks tidak seharusnya, mengirimkan M1 dengan nilai elemen [1][1] diganti menjadi -999} */

	//KAMUS
	int i = BrsMin;
	int j = KolMin;
	MATRIKS Mout;
	
	
	//ALGORITMA
	
	if (EQSize(M1,M2)==true) {
		MakeMATRIKS(&Mout,M1.NBrsEff,M1.NKolEff);
		for (i = BrsMin; i <= Mout.NBrsEff; i++) {
			for (j = KolMin; j <= Mout.NKolEff ; j++) {
				 Mout.Mem[i][j] = M1.Mem[i][j] - M2.Mem[i][j] ;
			}
		}
	} else {
		MakeMATRIKS(&Mout,1,1);
		Mout.Mem[1][1] = -999;
	} ; 
	
	return Mout;
}

void Transpose(MATRIKS Min, MATRIKS *Mout){
/*{ I.S. M terdefinisi } 
{ F.S. M “di-transpose”, yaitu setiap elemen M(i,j) ditukar nilainya dengan 
elemen M(j,i) } */
		//KAMUS
		int i= BrsMin;
		int j= KolMin;
		
		//ALGORITMA
		(*Mout).NBrsEff = Min.NKolEff;
		(*Mout).NKolEff = Min.NBrsEff;
		
		for (i = KolMin; i <= Min.NKolEff; i++) {
			for (j = BrsMin; j <= Min.NBrsEff ; j++) {
				(*Mout).Mem[i][j] = Min.Mem[j][i];
			};
		}
}
float Determinan(MATRIKS M) {
/*{ Prekondisi : Ukuran Matriks 2x2 atau Matriks 3x3 } 
{ Menghasilkan determinan matriks 2x2 bertipe real }
{  Jika  ukuran  matriks  tidak  seharusnya,  beri  peringatan  dan  menghasilkan 
nilai -999} */
	float det;
	if (((GetNBrsEff(M)==2) && (GetNKolEff(M)==2))){
		det = (GetElmt(M,1,1) * GetElmt(M,2,2)) - (GetElmt(M,1,2)*GetElmt(M,2,1));
	} else if(((GetNBrsEff(M)==3) && (GetNKolEff(M)==3))) {
		det =     (GetElmt(M,1,1) * GetElmt(M,2,2) *  GetElmt(M,3,3))
				+ (GetElmt(M,2,1) * GetElmt(M,3,2) *  GetElmt(M,1,3))
				+ (GetElmt(M,1,2) * GetElmt(M,2,3) *  GetElmt(M,3,1))
				- (GetElmt(M,1,3) * GetElmt(M,2,2) *  GetElmt(M,3,1))
				- (GetElmt(M,1,1) * GetElmt(M,2,3) *  GetElmt(M,3,2))
				- (GetElmt(M,1,2) * GetElmt(M,2,1) *  GetElmt(M,3,3));
				
	} else {
		det = -999;
	}
	
	return det;
}

#endif
