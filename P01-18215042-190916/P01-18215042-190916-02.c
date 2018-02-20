/*
{Nama/NIM                  : Condro Wiyono	}
{Tanggal                    : 19 September 2016}
{Topik                      : Abstract Data Type}
{Deskripsi                  : Ini adalah file haeder dari Abstract Data Type Garis}
*/

/* body untuk garis.h */


#ifndef GARIS_C
#define GARIS_C
#include "P01-18215042-190916-02.h"
#include <stdio.h>
#include <math.h>


//BODYNYA

//Definisi ABSTRACT DATA TYPE GARIS

Garis makeGARIS(Point P1, Point P2) {
	//DEFINISI
	//Membentuk sebuah GARIS dari komponen - komponennya 
	
	//KAMUS LOKAL
	Garis G ;
	
	G.P1 = P1;
	G.P2 = P2;
	
	return G;
}


void bacaGARIS (Garis *G){ 
	
	//I.S: sembarang
	//F.S mengulangi membaca dua buah nilai P1 dan P2 sehingga membentuk
	//garis yang valid
	//makeGARIS(P1,P2) membentuk G dari dua titik yang dibaca
	
	//KAMUS LOKAL
	int x1 ;
	int y1 ;
	
	int x2 ;
	int y2 ;
	
	Point P1;
	Point P2;
	
	//ALGORITMA
	printf("Point 1: \n");
	printf("x:");
	scanf("%d",&x1);
	printf("y:");
	scanf("%d",&y1);
	P1.x = x1;
	P1.y = y1;
	
	printf("Point 2: \n");
	printf("x:");
	scanf("%d",&x2);
	printf("y:");
	scanf("%d",&y2);
	P2.x = x2;
	P2.y = y2;
	
	
	(*G) = makeGARIS(P1,P2); 
}

void tulisGARIS (Garis G){
//Nilai G ditulis ke layar dengan format ((x1,y1),(x2,y2))

	//ALGORITMA
	printf("(");
	printf("(%d,%d)", G.P1.x, G.P1.y );
	printf(",");
	printf("(%d,%d)", G.P2.x, G.P2.y );
	printf(")");
}
Point getPAw(Garis G) {
	//Mengirimkan komponen titik awal dari garis
	//KAMUS LOKAL
	Point P;
	
	P = G.P1;
	
	return P ;
}

Point getPAk (Garis G) {
	//Mengirimkan komponen titik akhir dari garis
	//KAMUS LOKAL
	Point P;
	
	P = G.P2;
	
	return P ;
}

float panjang (Garis G) {
//Menghitung panjang garis G: sqrt((x1- x2)^2+(y1-y2)^2)
	//KAMUS LOKAL
	int panjangnya;
	int panjangnya2;
	
	Point P1;
	
	panjangnya2 = G.P1.x;
	
	//ALGORITMA, tidak tahu
	return sqrt(panjangnya2);
}


void geser (Garis *G, int deltaX, int deltaY) {
//I.S: G terdefinisi
//F.S: absis G digeser sejauh deltaX dan ordinatnya sejauh deltaY
	//KAMUS LOKAL
	Point P1;
	Point P2;
	
	//ALGORITMA
	
	P1.x = (*G).P1.x + deltaX;
	P2.y = (*G).P1.y + deltaY; 

	(*G) = makeGARIS(P1,P2);
}

#endif



