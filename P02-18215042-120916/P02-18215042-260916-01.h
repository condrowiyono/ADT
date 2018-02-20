/*
{Nama/NIM                  : Condro Wiyono	}
{Tanggal                    : 26 September 2016}
{Topik                      : Abstract Data Type}
{Deskripsi                  : Ini adalah file haeder dari Abstract Data Type Kotak}
*/

typedef int bool; 
#define true 1 
#define false 0
#ifndef RECT_H 
#define RECT_H
#include "PP02-18215042-190916-01.h"

//Definisi ABSTRACT DATA TYPE RECTANGLE
typedef struct { 
	Point P1; //titik kiri atas
	Point P2; //titik kanan atas
	Point P3; //titik kanan bawah
	Point P4; //titik kiri bawah
}Rectangle; 

Rectangle makeRectangle(Point P1, int pjg, int lbr); 
//Membentuk sebuah RECTANGLE dan seluruh titik ujungnya jika diketahui 
//titik paling kiri atas, panjang, dan lebar persegi panjang

void bacaRectangle(Rectangle *R); 
//I.S: sembarang
//F.S:mengulangi membaca dua buah nilai  panjang dan lebar sehingga  membentuk  garis yang valid
//(panjang dan lebar tidak sama dengan 0)
//makeRect(P1, panjang, lebar) membentuk R dari dua titik, panjang, dan lebar
//yang dibaca

void tulisRectangle ( Rectangle R); 
//I.S: sembarang
//F.S: Nilai R ditulis ke layar dengan format 
//((x1,y1),(x2,y2),(x2,y2),(x2,y2))

int getPanjang (Rectangle R); 
//Mengirimkan  panjang Rectange R (jarak point P1 dan P2)

int getLebar(Rectangle R); 
//Mengirimkan lebar Rectange R (jarak point P2 dan P3) 

int keliling (Rectangle R );
//Menghitung  keliling Rectangle

int luas(Rectangle R);
//menghitung luas Rectangle

#endif
