/*
{Nama/NIM                  : Condro Wiyono	}
{Tanggal                    : 19 September 2016}
{Topik                      : Abstract Data Type}
{Deskripsi                  : Ini adalah file driver dari Abstract Data Type Titik/Point}
*/


/* Driver Kotakan bro */


#include <stdio.h>
#include "P02-18215042-260916-01.h"

int main (){
	
	//KAMUS LOKAL
	Rectangle R ;
		
	//ALGORITMA
	bacaRectangle(&R);
	tulisRectangle(R);
	
	printf("Luas RECTANGLE adalah: %d satuan2 \n", luas(R));
	printf("Keliling RECTANGLE adalah: %d satuan \n",keliling(R));
	
	return 0;
}
