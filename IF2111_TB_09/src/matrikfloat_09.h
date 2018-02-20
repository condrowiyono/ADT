/* TUGAS BESAR IF2111 - Algoritma dan Struktur Data 
Pokemoon
---------------------------------------------------------------
Nomor Kelompok 	: 09
Nama File : matrikfloat_09.h
Deskripsi : ADT Matrik untuk load Peta.
---------------------------------------------------------------
*/

#include "point_09.h"
#include "mesinkata_09.h"

#ifndef MATRIKSFLOAT_H
#define MATRIKSFLOAT_H

typedef float el_typeFloat;

typedef struct {
	el_typeFloat Mem[100-1][100-1];
	int NBrsEff;
	int NKolEff;
} MATRIKSFLOAT ;
 
//FUNGSI BAWAAN / PRIMITIF
void MakeMATRIKSFLOAT (int NB, int NK, MATRIKSFLOAT *M);
/*	Operasi mengubah nilai elemen matriks: Set / Assign */

void SetElMATRIKSFLOAT (MATRIKSFLOAT *M, int i, int j, el_typeFloat X);
/*	I.S. 	: M sudah terdefinisi 
	F.S. 	: M(i,j) bernilai X 
	Proses	: Mengisi M(i,j) dengan X */
el_typeFloat GetElmtMATRIKSFLOAT (MATRIKSFLOAT M, int i, int j);
/*	Mengirimkan elemen M dg nomor baris i dan nomor kolom j */

MATRIKSFLOAT LoadAbil();

#endif
