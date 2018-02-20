/* TUGAS BESAR IF2111 - Algoritma dan Struktur Data 
Pokemoon
---------------------------------------------------------------
Nomor Kelompok 	: 09
Nama File : MATRIKSFLOAT_09.c
Deskripsi : ADT Matrik untuk load Peta.
---------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrikfloat_09.h"
#include "helper_09.h"

#ifndef MATRIKSFLOAT_C
#define MATRIKSFLOAT_C

/*	Konstruktor pembentuk MATRIKS */
void MakeMATRIKSFLOAT (int NB, int NK, MATRIKSFLOAT *M){
/*	Membentuk sebuah MATRIKS “kosong” berukuran NB x NK di “ujung kiri” 
	memori 
	I.S. 	: NB dan NK adalah valid untuk memori matriks yang dibuat 
	F.S. 	: Matriks M sesuai dengan definisi di atas terbentuk */
	(*M).NBrsEff = NB;
	(*M).NKolEff = NK;
}

void SetElMATRIKSFLOAT (MATRIKSFLOAT *M, int i, int j, el_typeFloat X){
/*	I.S. 	: M sudah terdefinisi 
	F.S. 	: M(i,j) bernilai X 
	Proses	: Mengisi M(i,j) dengan X */
	(*M).Mem[i][j]=X;
}

el_typeFloat GetElmtMATRIKSFLOAT (MATRIKSFLOAT M, int i, int j) {
/*	Mengirimkan elemen M dg nomor baris i dan nomor kolom j */
	return M.Mem[i][j];
}

MATRIKSFLOAT LoadAbil() {
    //KAMUS 
    MATRIKSFLOAT M1;    
    extern char CC;
    extern Kata CKata;
    int i;
    int j,k;
	int l ;
    extern bool EndKata;
	char kata[10];
	int pjg;
    
    //ALGORITMA
    MakeMATRIKSFLOAT(7,7,&M1);

    j = 1;
    k = 0;
    EndKata = false;
    STARTKATA(1);
    while (!EndKata) {
        for (i=1;i<=CKata.Length;i++) {
			kata[i-1] = CKata.TabKata[i];
			//cari koma diganti titik
			if (kata[i-1]==',')
				kata[i-1]='.';
			pjg = CKata.Length;
			kata[pjg]='\0';
        }
		if ( j % 7 ==1) { 
			j = 1;
			k++;
		}
		
		SetElMATRIKSFLOAT(&M1,k,j,atof(kata));            
        j++;
        
		ADVKATA();
        
    }
    
    return M1;
}


#endif
/*
int main(){
	MATRIKSFLOAT M;
	M = LoadAbil();
	int i,j;
	el_typeFloat X;
	
	for (i = 1; i <= M.NBrsEff; i++) {
		for (j = 1; j <= M.NKolEff ; j++) {
				printf("%f ",GetElmtMATRIKSFLOAT(M,i,j));		
		};
		printf("\n");
	};
}
*/