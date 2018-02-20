/* TUGAS BESAR IF2111 - Algoritma dan Struktur Data 
Pokemoon
---------------------------------------------------------------
Nomor Kelompok 	: 09
Nama File : matrik_09.h
Deskripsi : ADT Matrik untuk load Peta.
---------------------------------------------------------------
*/

#include "point_09.h"
#include "mesinkata_09.h"

#ifndef MATRIKS_H
#define MATRIKS_H

#define BrsMin 1 // indeks
#define BrsMax 100 //indeks
#define KolMin 1 //indeks
#define KolMax 100 //indeks

typedef int indeks;
typedef int el_type;

typedef struct {
	el_type Mem[BrsMax-BrsMin][KolMax-KolMin];
	int NBrsEff;
	int NKolEff;
} MATRIKS ;
 
//FUNGSI BAWAAN / PRIMITIF
void MakeMATRIKS (int NB, int NK, MATRIKS *M);
/*	Operasi mengubah nilai elemen matriks: Set / Assign */
void SetBrsEff (MATRIKS *M, int NB);
/*	I.S. 	: M sudah terdefinisi 
	F.S. 	: Nilai M.BrsEff diisi dengan NB */
void SetKolEff (MATRIKS *M, int NK);
/*	I.S. 	: M sudah terdefinisi
	F.S. 	: Nilai M.NKolEff diisi dengan NK */
void SetEl (MATRIKS *M, int i, int j, el_type X);
/*	I.S. 	: M sudah terdefinisi 
	F.S. 	: M(i,j) bernilai X 
	Proses	: Mengisi M(i,j) dengan X */
el_type GetElmt (MATRIKS M, indeks i, indeks j);
/*	Mengirimkan elemen M dg nomor baris i dan nomor kolom j */


void TulisMATRIKS(MATRIKS M);
/* I.S. M terdefinisi */
/* F.S. Sama dengan I.S, dan nilai M(i,j) ditulis ke layar*/
/* Menulis Nilai setiap indeks dan elemen M ke layar */
/* dengan traversal per baris */

//LOAD MATRIKS untuk Peta Pertama
MATRIKS LoadPeta1();

//LOAD MATRIKS untuk Peta Kedua
MATRIKS LoadPeta2();

//LOAD MATRIKS untuk Peta Kedua
MATRIKS LoadPeta3();

//LOAD MATRIKS untuk Peta Kedua
MATRIKS LoadPeta4();

POINT CariPosisi(MATRIKS M);

POINT PindahAtas(MATRIKS *M, int sebelum ,int *temp);
POINT PindahBawah(MATRIKS *M, int sebelum ,int *temp);
POINT PindahKiri(MATRIKS *M, int sebelum ,int *temp);
POINT PindahKanan(MATRIKS *M, int sebelum ,int *temp);

#endif
