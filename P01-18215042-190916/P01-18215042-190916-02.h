/*
{Nama/NIM                  : Condro Wiyono	}
{Tanggal                    : 19 September 2016}
{Topik                      : Abstract Data Type}
{Deskripsi                  : Ini adalah file haeder dari Abstract Data Type Garis}
*/


typedef int bool; 
#define true 1 
#define false 0

#ifndef GARIS_H 
#define GARIS_H
#include "P01-18215042-190916-01.h"

//Definisi ABSTRACT DATA TYPE GARIS
typedef struct { 
	Point P1; //titik awal
	Point P2; //titik akhir
}  Garis; 

Garis makeGARIS(Point P1, Point P2); 
//Membentuk sebuah GARISdari komponen - komponennya 

void bacaGARIS (Garis *G); 
//I.S: sembarang
//F.S mengulangi membaca dua buah nilai P1 dan P2 sehingga membentuk
//garis yang valid
//makeGARIS(P1,P2) membentuk G dari dua titik yang dibaca

void tulisGARIS (Garis G); 
//Nilai G ditulis ke layar dengan format ((x1,y1),(x2,y2))

Point getPAw(Garis G); 
//Mengirimkan komponen titik awal dari garis

Point getPAk (Garis G); 
//Mengirimkan komponen titik akhir dari garis

float panjang (Garis G);
//Menghitung panjang garis G: sqrt((x1- x2)2+(y1-y2)2)

void geser (Garis *G, int deltaX, int deltaY);
//I.S: G terdefinisi
//F.S: absis G digeser sejauh deltaX dan ordinatnya sejauh deltaY


#endif



