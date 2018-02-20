/*
{Nama/NIM                  : Condro Wiyono	}
{Tanggal                    : 26 September 2016}
{Topik                      : Abstract Data Type}
{Deskripsi                  : Ini adalah file prototipe dari Abstract Data Type Kotak}
*/


#ifndef RECT_C
#define RECT_C
#include <stdio.h>
#include "PP02-18215042-190916-01.h"
#include "P02-18215042-260916-01.h"

//BODY NYA

Rectangle makeRectangle(Point P1, int pjg, int lbr) { 
	//Membentuk sebuah RECTANGLE dan seluruh titik ujungnya jika diketahui 
	//titik paling kiri atas, panjang, dan lebar persegi panjang
	
	//KAMUS LOKAL
	Rectangle R;
	
	
	//ALGORITMA
	//kiri atas
	R.P1.x = P1.x;
	R.P1.y = P1.y;
	
	//kanan atas
	R.P2.x = P1.x + pjg ;
	R.P2.y = P1.y ;
	
	//kanan bawah
	R.P3.x = P1.x + pjg ;
	R.P3.y = P1.y - lbr;
	
	//kiri bawah
	R.P4.x = P1.x ;
	R.P4.y = P1.y - lbr;
	
	return R;
}

void bacaRectangle(Rectangle *R) { 	
	//I.S: sembarang
	//F.S:mengulangi membaca dua buah nilai  panjang dan lebar sehingga  membentuk  garis yang valid
	//(panjang dan lebar tidak sama dengan 0)
	//makeRect(P1, panjang, lebar) membentuk R dari dua titik, panjang, dan lebar
	//yang dibaca
	
	//KAMUS LOKAL
	int x1 ;
	int y1 ;
	int p;
	int l;
	
	Point P1;
	//ALGORITMA
	printf("Masukkan titik kiri atas (P1) :  \n");
	
	//inputan x
	printf("x:");
	scanf("%d",&x1);
	
	//validasi x
	while (x1<0)  { 
		printf("x:");
		scanf("%d",&x1);
	}
	
	printf("y:");
	scanf("%d",&y1);
	
	//validasi y
	while (y1<0) {
		printf("y:");
		scanf("%d",&y1);
	}
	printf("Masukkan panjang (p): \n");
	scanf("%d",&p);
	printf("Masukkan lebar (l): \n" );
	scanf("%d",&l);

	//PROSES
	P1 = makePOINT(x1,y1);
	(*R) = makeRectangle(P1, p, l);
}

void tulisRectangle ( Rectangle R) {
	//I.S: sembarang
	//F.S: Nilai R ditulis ke layar dengan format 
	//((x1,y1),(x2,y2),(x2,y2),(x2,y2))
	
	//KAMUS LOKAL
	
	//ALGORITMA
	printf("RECTANGLE adalah : (%d,%d),(%d,%d),(%d,%d),(%d,%d)) \n", R.P1.x, R.P1.y, R.P2.x, R.P2.y, R.P3.x, R.P3.y, R.P4.x, R.P4.y   );
	
}
int getPanjang (Rectangle R) {
	//Mengirimkan  panjang Rectange R (jarak point P1 dan P2)
	
	//KAMUS LOKAL
	int panjang;
	//ALGORITMA
	panjang = R.P2.x - R.P1.x;
	
	return panjang; 
	

}

int getLebar(Rectangle R) {
	//Mengirimkan lebar Rectange R (jarak point P2 dan P3) 
	
	//KAMUS LOKAL
	int lebar;
	//ALGORITMA
	lebar = R.P2.y - R.P3.y ;
	
	return lebar; 
	
}

int keliling (Rectangle R ) {
	//Menghitung  keliling Rectangle
	//KAMUS LOKAL
	int keliling;
	//ALGORITMA
	keliling = 2 * (getLebar(R) + getPanjang(R)) ;

	return keliling;
}
int luas(Rectangle R) {
	//menghitung luas Rectangle
	//KAMUS LOKAL 
	int luas;
	
	//ALGORITMA
	luas = getLebar(R) * getPanjang(R);
	return luas;
}
#endif
