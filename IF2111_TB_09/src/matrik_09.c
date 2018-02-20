/* TUGAS BESAR IF2111 - Algoritma dan Struktur Data 
Pokemoon
---------------------------------------------------------------
Nomor Kelompok 	: 09
Nama File : matrik_09.c
Deskripsi : ADT Matrik untuk load Peta.
---------------------------------------------------------------
*/

#include <stdio.h>
#include "matrik_09.h"
#include "helper_09.h"

#ifndef MATRIKS_C
#define MATRIKS_C

/*	Konstruktor pembentuk MATRIKS */
void MakeMATRIKS (int NB, int NK, MATRIKS *M) {
/*	Membentuk sebuah MATRIKS “kosong” berukuran NB x NK di “ujung kiri” 
	memori 
	I.S. 	: NB dan NK adalah valid untuk memori matriks yang dibuat 
	F.S. 	: Matriks M sesuai dengan definisi di atas terbentuk */
	(*M).NBrsEff = NB;
	(*M).NKolEff = NK;
}

/*	Operasi mengubah nilai elemen matriks: Set / Assign */
void SetBrsEff (MATRIKS *M, int NB) {
/*	I.S. 	: M sudah terdefinisi 
	F.S. 	: Nilai M.NBrsEff diisi dengan NB */
	(*M).NBrsEff = NB;	
}
void SetKolEff (MATRIKS *M, int NK) {
/*	I.S. 	: M sudah terdefinisi
	F.S. 	: Nilai M.NKolEff diisi dengan NK */
	(*M).NKolEff = NK;	
}
void SetEl (MATRIKS *M, int i, int j, el_type X) {
/*	I.S. 	: M sudah terdefinisi 
	F.S. 	: M(i,j) bernilai X 
	Proses	: Mengisi M(i,j) dengan X */
	(*M).Mem[i][j]=X;
}

el_type GetElmt (MATRIKS M, indeks i, indeks j) {
/*	Mengirimkan elemen M dg nomor baris i dan nomor kolom j */
	return M.Mem[i][j];
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
			if (M.Mem[i][j]==80) {
				printf("%c ",M.Mem[i][j],M.Mem[i][j]);		
			} else {
				printf("%c%c",M.Mem[i][j],M.Mem[i][j]);		
			}
		};
		printf("\n");
	};
	
}

MATRIKS LoadPeta1() {
	//KAMUS 
	MATRIKS M1;	
	extern char CC;
	extern Kata CKata;
	int i;
	int j,k;
	extern bool EndKata;
	
	//ALGORITMA
	MakeMATRIKS(10,10,&M1);

	j = 1;
	k = 0;
	EndKata = false;
	STARTKATA(3);
	while (!EndKata) {
		for (i=1;i<=CKata.Length;i++) {
			if ( j % 10 ==1) { 
				j = 1;
				k++;
			}
			SetEl(&M1,k,j,CKata.TabKata[i]);
			if (GetElmt(M1,k,j)==80) {
				SetEl(&M1,k,j,80);
			} else if (GetElmt(M1,k,j)==74)  //J=74
			{
				SetEl(&M1,k,j,0);
			} else if (GetElmt(M1,k,j)==88)  //J=74
			{
				SetEl(&M1,k,j,46);
			} else if (GetElmt(M1,k,j)==82)  //R=82
			{
				SetEl(&M1,k,j,176);
			} else if (GetElmt(M1,k,j)==83) //S=83
			 {
				SetEl(&M1,k,j,35);
			} else if (GetElmt(M1,k,j)==77) //M=77
			{
				SetEl(&M1,k,j,219);
			}
			
			j++;
			
		}
		ADVKATA();
		
	}	
	return M1;
}


//Memuat semua data yang diperlukan untuk Peta / Maps 2 
//Menggunakan Mesin Kata, dari file eksternal ke MATRIKS
MATRIKS LoadPeta2() {
	//KAMUS
	MATRIKS M1;	
	extern char CC;
	extern Kata CKata;
	int i;
	int j,k;
	extern bool EndKata;
	
	//ALGORITMA
	MakeMATRIKS(10,10,&M1);
	//inisialisasi
	j = 1;
	k = 0;
	EndKata = false;
	STARTKATA(7);
	while (!EndKata) {
		for (i=1;i<=CKata.Length;i++) {
			if ( j % 10 ==1) { 
				j = 1;
				k++;
			}
			SetEl(&M1,k,j,CKata.TabKata[i]);
			if (GetElmt(M1,k,j)==80) {
				SetEl(&M1,k,j,80);
			} else if (GetElmt(M1,k,j)==74)  //J=74
			{
				SetEl(&M1,k,j,0);
			} else if (GetElmt(M1,k,j)==88)  //J=74
			{
				SetEl(&M1,k,j,46);
			} else if (GetElmt(M1,k,j)==82)  //R=82
			{
				SetEl(&M1,k,j,176);
			} else if (GetElmt(M1,k,j)==83) //S=83
			 {
				SetEl(&M1,k,j,35);
			} else if (GetElmt(M1,k,j)==77) //M=77
			{
				SetEl(&M1,k,j,219);
			}
			
			j++;
			
		}
		ADVKATA();
		
	}
	
	return M1;
}

MATRIKS LoadPeta3() {
	//KAMUS 
	MATRIKS M1;	
	extern char CC;
	extern Kata CKata;
	int i;
	int j,k;
	extern bool EndKata;
	
	//ALGORITMA
	MakeMATRIKS(10,10,&M1);

	j = 1;
	k = 0;
	EndKata = false;
	STARTKATA(8);
	while (!EndKata) {
		for (i=1;i<=CKata.Length;i++) {
			if ( j % 10 ==1) { 
				j = 1;
				k++;
			}
			SetEl(&M1,k,j,CKata.TabKata[i]);
			if (GetElmt(M1,k,j)==80) {
				SetEl(&M1,k,j,80);
			} else if (GetElmt(M1,k,j)==74)  //J=74
			{
				SetEl(&M1,k,j,0);
			} else if (GetElmt(M1,k,j)==88)  //J=74
			{
				SetEl(&M1,k,j,46);
			} else if (GetElmt(M1,k,j)==82)  //R=82
			{
				SetEl(&M1,k,j,176);
			} else if (GetElmt(M1,k,j)==83) //S=83
			 {
				SetEl(&M1,k,j,35);
			} else if (GetElmt(M1,k,j)==77) //M=77
			{
				SetEl(&M1,k,j,219);
			}
			
			j++;
			
		}
		ADVKATA();
		
	}
	
	return M1;
}

MATRIKS LoadPeta4() {
	//KAMUS 
	MATRIKS M1;	
	extern char CC;
	extern Kata CKata;
	int i;
	int j,k;
	extern bool EndKata;
	
	//ALGORITMA
	MakeMATRIKS(10,10,&M1);

	j = 1;
	k = 0;
	EndKata = false;
	STARTKATA(9);
	while (!EndKata) {
		for (i=1;i<=CKata.Length;i++) {
			if ( j % 10 ==1) { 
				j = 1;
				k++;
			}
			SetEl(&M1,k,j,CKata.TabKata[i]);
			if (GetElmt(M1,k,j)==80) {
				SetEl(&M1,k,j,80);
			} else if (GetElmt(M1,k,j)==74)  //J=74
			{
				SetEl(&M1,k,j,0);
			} else if (GetElmt(M1,k,j)==88)  //J=74
			{
				SetEl(&M1,k,j,46);
			} else if (GetElmt(M1,k,j)==82)  //R=82
			{
				SetEl(&M1,k,j,176);
			} else if (GetElmt(M1,k,j)==83) //S=83
			 {
				SetEl(&M1,k,j,35);
			} else if (GetElmt(M1,k,j)==77) //M=77
			{
				SetEl(&M1,k,j,219);
			}
			
			j++;
			
		}
		ADVKATA();
		
	}
	
	return M1;
}


POINT CariPosisi(MATRIKS M) {
	bool found ;
	int i,j;
	POINT Pos;
	
	i = 1;
	j = 1;
	found = false;
	while ((i<=10) && (!(found))) {
		j = 0 ; // initialization
		while ((j<=10) && (!(found))) {
			if (M.Mem[i][j]==80) {
				found = true;
			} else
			{
				j++;
			}
		} 
		if (!found) {
			i++;	
		}
	}
	
	if (found==true) {
		Pos.X = i;
		Pos.Y = j;
	} else {
		Pos.X = 0;
		Pos.Y = 0;
	}
	return Pos;
}

POINT PindahAtas(MATRIKS *M, int sebelum, int *temp) {
	POINT Pos, Prec;
	POINT kembali;
	Pos = CariPosisi((*M));
	Prec.X = Pos.X-1;
	Prec.Y = Pos.Y;
	
	kembali.X = 0;
	kembali.Y = 0;
	
	if (Pos.X==1&&Pos.Y==6) {
		kembali = Pos;
	} else if (Pos.X==1&&Pos.Y==3) {
		kembali = Pos;
	} else if (Pos.X==1&&Pos.Y==9) {
		SetEl(&(*M),Pos.X,Pos.Y,46);
		kembali = Pos;
	} else if (((*M).Mem[Prec.X][Prec.Y]==176)&&(acak(0,1)==1))  {	
			kembali.X = 9 ;
			kembali.Y = 9 ;
	} else if (((*M).Mem[Prec.X][Prec.Y] == 219))  {
			kembali.X = 10 ;
			kembali.Y = 10 ;
	}
	
	if ((Prec.X<1) || ((*M).Mem[Prec.X][Prec.Y] == 35))  {
		printf("No more move \n");
	} else {
		(*temp) = (*M).Mem[Prec.X][Prec.Y];
		(*M).Mem[Prec.X][Prec.Y] = 80;
		(*M).Mem[Pos.X][Pos.Y] = sebelum;
	}
	
	return kembali;
}

POINT PindahBawah(MATRIKS *M, int sebelum, int *temp) {
	POINT Pos,Prec;
	POINT kembali;
	Pos = CariPosisi((*M));
	Prec.X = Pos.X+1;
	Prec.Y = Pos.Y;
	
	kembali.X = 0;
	kembali.Y = 0;
	
	
	if (Pos.X==10&&Pos.Y==6) {
		kembali = Pos;
	} else if (Pos.X==10&&Pos.Y==3) {
		kembali = Pos;
	} else if (Pos.X==10&&Pos.Y==9) {
		SetEl(&(*M),Pos.X,Pos.Y,46);
		kembali = Pos;
	} else if (((*M).Mem[Prec.X][Prec.Y] == 176)&&(acak(0,1)==1))  {
			kembali.X = 9 ;
			kembali.Y = 9 ;
	} else if (((*M).Mem[Prec.X][Prec.Y] == 219))  {
			kembali.X = 10 ;
			kembali.Y = 10 ;
	}
	
	if ((Prec.X>10) || ((*M).Mem[Prec.X][Prec.Y] == 35)) {
		printf("No more move \n");
	} else {
		(*temp) = (*M).Mem[Prec.X][Prec.Y];
		(*M).Mem[Prec.X][Prec.Y] = 80;
		(*M).Mem[Pos.X][Pos.Y] = sebelum;
		
	}	
	return kembali;
}
POINT PindahKiri(MATRIKS *M, int sebelum, int *temp) {
	POINT Pos,Prec;
	POINT kembali;
	Pos = CariPosisi((*M));
	Prec.X = Pos.X;
	Prec.Y = Pos.Y-1;
	kembali.X = 0;
	kembali.Y = 0;
	
	if (Pos.X==7&&Pos.Y==1) {
		kembali = Pos;
	} else if (Pos.X==5&&Pos.Y==1) {
		kembali = Pos;
	} else if (((*M).Mem[Prec.X][Prec.Y] == 176)&&(acak(0,1)==1))  {
			kembali.X = 9 ;
			kembali.Y = 9 ;
	} else if (((*M).Mem[Prec.X][Prec.Y] == 219))  {
			kembali.X = 10 ;
			kembali.Y = 10 ;
	}
	
	
	if ((Prec.Y<1)  || ((*M).Mem[Prec.X][Prec.Y] == 35)){
		printf("No more move \n");
	} else {
		(*temp) = (*M).Mem[Prec.X][Prec.Y];
		(*M).Mem[Prec.X][Prec.Y] = 80;
		(*M).Mem[Pos.X][Pos.Y] = sebelum;
	}	
	return kembali;
}
POINT PindahKanan(MATRIKS *M, int sebelum, int *temp) {
	POINT Pos,Prec;
	POINT kembali;
	Pos = CariPosisi((*M));
	Prec.X = Pos.X;
	Prec.Y = Pos.Y+1;
	kembali.X = 0;
	kembali.Y = 0;
		
	if (Pos.X==7&&Pos.Y==10) {
		kembali = Pos;
	} else if (Pos.X==5&&Pos.Y==10) {
		kembali = Pos;
	} else if (((*M).Mem[Prec.X][Prec.Y] == 176)&&(acak(0,1)==1))  {
			kembali.X = 9 ;
			kembali.Y = 9 ;
	} else if (((*M).Mem[Prec.X][Prec.Y] == 219))  {
			kembali.X = 10 ;
			kembali.Y = 10 ;
	}
	
	if ((Prec.Y>10) || ((*M).Mem[Prec.X][Prec.Y] == 35)) {
		printf("No more move \n");
	} else
	{
		(*temp) = (*M).Mem[Prec.X][Prec.Y];
		(*M).Mem[Prec.X][Prec.Y] = 80;
		(*M).Mem[Pos.X][Pos.Y] = sebelum;

	}	
	return kembali;
}
#endif

