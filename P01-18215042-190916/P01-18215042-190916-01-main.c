/*
{Nama/NIM                  : Condro Wiyono	}
{Tanggal                    : 19 September 2016}
{Topik                      : Abstract Data Type}
{Deskripsi                  : Ini adalah file haeder dari Abstract Data Type Titik/Point}
*/


/* Driver Point */


#include <stdio.h>
#include "P01-18215042-190916-01.h"

int main (){
	
	//KAMUS LOKAL
	Point P1;
	Point P2;
	
	Point jumlah;
	Point selisih;
	
	//ALGORITMA
	printf("Program Titik \n");
	
	printf("POINT 1: \n");
	bacaPOINT(&P1);
	printf("POINT 1 adalah  ");
	tulisPOINT(P1);	
	printf("\n");
	printf("\n");
	
	printf("POINT 2: \n");
	bacaPOINT(&P2);
	printf("POINT 2 adalah  ");
	tulisPOINT(P2);
	printf("\n");
	printf("\n");
	
	if (isLessThan(P1,P2)) {
		printf("Perbandingan POINT 1 dan POINT 2: POINT 1 lebih kecil dari POINT2 \n");
	} else {
		printf("Perbandingan POINT 1 dan POINT 2: POINT 1 lebih besar dari POINT2 \n");
	}
	
	printf("\n");
	printf("Kuadran POINT 1: Point 1 berada di kuadran %d \n", kuadran(P1));
	printf("Kuadran POINT 2: Point 2 berada di kuadran %d \n", kuadran(P2));
		
	jumlah = tambah(P1,P2);
	selisih = kurang(P1,P2);
	
	printf("\n");
	printf("POINT 1 + POINT 2 ="); tulisPOINT(P1); printf("+") ; tulisPOINT(P2) ; printf("=");tulisPOINT(jumlah);
	printf("\n");
	printf("POINT 1 - POINT 2 ="); tulisPOINT(P1); printf("-") ; tulisPOINT(P2) ; printf("=");tulisPOINT(selisih);
	printf("\n");
	return 0;
}
