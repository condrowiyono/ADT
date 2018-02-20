/*
{Nama/NIM                  : Condro Wiyono	}
{Tanggal                    : 19 September 2016}
{Topik                      : Abstract Data Type}
{Deskripsi                  : Ini adalah file haeder dari Abstract Data Type Titik/Point}
*/


typedef int bool; 
#define true 1 
#define false 0

#ifndef POINT_H 
#define POINT_H

//Definisi ABSTRACT DATA TYPE POINT 
typedef struct { 
	int x; //absis 
	int y; //ordinat 
} Point; 

Point makePOINT (int x, int y); 
//Membentuk sebuah POINT dari komponen-komponennya 

int getAbsis(Point P); 
//Mengirimkan komponen Absis dari POINT P 

int getOrdinat (Point P); 
//Mengirimkan komponen Ordinat dari POINT P

void bacaPOINT (Point *P); 
//makePOINT(x,y) membentuk P dari x dan y yang dibaca

void tulisPOINT (Point P); 
//Nilai P ditulis ke layar dg format “(X,Y)”

bool isEqual(Point P1, Point P2);
//Mengirimkan true jika P1=P2: absis dan ordinatnya sama

bool isLessThan (Point P1, Point P2); 
// Mengirimkan true jika P1<P2. Definisi lebih kecil: lebih “kiribawah” 
// dalam bidang kartesian 

bool isGreaterThan (Point P1, Point P2); 
//Mengirimkan true jika P1 > P2. Definisi lebih besar: lebih 
//“kananatas” dalam bidang kartesian

int kuadran (Point P); 
//Menghasilkan kuadran dari P: 1,2,3, atau 4.
//Prekondisi: P bukan Titik Origin dan P tidak terletak di salah satu 
//sumbu.

Point tambah(Point P1, Point P2);
//Menghasilkan operasi penjumlahan vector P1+P2


Point kurang(Point P1, Point P2);
//Menghasilkan operasi pengurangan vector P1-P2


#endif











