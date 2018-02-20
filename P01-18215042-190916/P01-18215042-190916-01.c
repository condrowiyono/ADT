/*
{Nama/NIM                  : Condro Wiyono	}
{Tanggal                    : 19 September 2016}
{Topik                      : Abstract Data Type}
{Deskripsi                  : Ini adalah file haeder dari Abstract Data Type Titik/Point}
*/


/* body untuk point.h */

#ifndef POINT_C 
#define POINT_C
#include <stdio.h>
#include "P01-18215042-190916-01.h"

/*BODY NYA*/

Point makePOINT (int x, int y){
	//DEFINISI
	//Membentuk sebuah POINT dari komponen-komponennya 
	
	//KAMUS LOKAL
	Point P;

	//ALGORITMA
	P.x = x ;
	P.y = y ;

	return P;
}

int getAbsis(Point P) { 
	// DEFINISI
	//Mengirimkan komponen Absis dari POINT P 
	
	//KAMUS LOKAL
	
	//ALGORITMA
	return P.y;
}

int getOrdinat (Point P) { 
	//DEFINISI
	//Mengirimkan komponen Ordinat dari POINT P


	//KAMUS LOKAL
	
	//ALGORITMA
	return P.x;
	
}
void bacaPOINT (Point *P) { 
	//DEFINISI
	//makePOINT(x,y) membentuk P dari x dan y yang dibaca
	
	//KAMUS LOKAL
	int x1 ;
	int y1 ;
	
	//ALGORITMA
	printf("x:");
	scanf("%d",&x1);
	printf("y:");
	scanf("%d",&y1);
	(*P) = makePOINT(x1,y1); 

}
void tulisPOINT (Point P) {
	//DEFINISI
	//Nilai P ditulis ke layar dg format “(X,Y)”
	
	//ALGORITMA
	printf("(%d,%d)", P.x, P.y );
	
}
bool isEqual(Point P1, Point P2) {
	//DEFINISi
	//Mengirimkan true jika P1=P2: absis dan ordinatnya sama
	
	//ALGORITMA
	if ((P1.x==P2.x) && (P1.y==P2.y)) {
		return true ;
	} else { 
		return false; 
	}

}
bool isLessThan (Point P1, Point P2) {
	//DEFINISI
	// Mengirimkan true jika P1<P2. Definisi lebih kecil: lebih “kiribawah” 
	// dalam bidang kartesian 


	//ALGORITMA
	if ((P1.x<P2.x) && (P1.y<P2.y)) {
		return true ;
	} else { 
		return false; 
	}	
}	
bool isGreaterThan (Point P1, Point P2) {
	//DEFINISI
	//Mengirimkan true jika P1 > P2. Definisi lebih besar: lebih 
	//“kananatas” dalam bidang kartesian
	//ALGORITMA
	if ((P1.x>P2.x) && (P1.y>P2.y)) {
		return true ;
	} else { 
		return false; 
	}	


}

int kuadran (Point P) {
	//DEFINISI
	//Menghasilkan kuadran dari P: 1,2,3, atau 4.
	//Prekondisi: P bukan Titik Origin dan P tidak terletak di salah satu 
	//sumbu.

	//ALGORITMA
	
	if (( P.x > 0 ) && ( P.y > 0 )) {
		return 1;
	} else if (( P.x < 0 ) && ( P.y > 0 )) {
		return 2;
	} else if (( P.x < 0 ) && ( P.y < 0 )) {
		return 3;
	} else if (( P.x > 0 ) && ( P.y < 0 )) {
		return 4;
	}
}
	

Point tambah(Point P1, Point P2) {
	//DEFINISI
	//Menghasilkan operasi penjumlahan vector P1+P2
	
	//KAMUS LOKAL
	Point P;
	
	//ALGORITMA
	P.x = (P1.x + P2.x);
	P.y = (P1.y + P2.y);

	return P;
}
Point kurang(Point P1, Point P2) {
	//DEFINISI
	//Menghasilkan operasi pengurangan vector P1-P2
	
	//KAMUS LOKAL
	Point P;
	
	//ALGORITMA
	P.x = (P1.x - P2.x);
	P.y = (P1.y - P2.y);

	return P;

}

#endif
	
