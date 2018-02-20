/*Nama/NIM                   : Condro Wiyono	*/
/*Tanggal                    : 11 November 2016*/
/*Topik                      : ADT QUEUE*/
/*Deskripsi                  : Ini adalah file driver dari ADT QUEUE*/

#include "P07-18215042-071116-01.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//KAMUS GLOBAL

int main() {
	//KAMUS
	int i; //Konter giliran
	int max,j,x,y;
	char kocok[10]; //yes or no
	int dadu1, dadu2;
	Pemain simpanDel;
	Queue F;
	
	printf("Permainan Dadu \n");
	printf("Masukkan Jumlah Pemain : ");
	scanf("%d",&max);
	while ((max<2) && (max>6)) {
		printf("Pemain tidak sesuai \n") ;
		printf("Masukkan Jumlah Pemain : ");
		scanf("%d",&max);
	}
	//sudah bener maks nya
	CreateQueuePemain(&F, max);
	
	//MULAI
	CetakElmt(F);
	while (!IsGameOver(F)) {
		i = 1;
		printf("Permainan dimulai \n");
		printf("Turn %d", i);
		printf("Giliran :  %s", InfoHead(F).Nama);
		printf("Kocok Dadu");
		scanf("%s",kocok);
		if (strcmp(kocok, "Ya")==0)  //jika ya
		{
			//mgerandom waktu
			srand(time(NULL));  
			dadu1 = rand() % x + y;
			dadu2 = rand() % x + y;
			printf("Hasil \n");
			printf("Dadu 1 : %d \n",dadu1);
			printf("Dadu 2 : %d \n",dadu2);
			if (dadu1==dadu2) {
				InfoHead(F).Skor++;
			}
		} else if (strcmp(kocok, "Tidak")==0) //jika tidak
		{
			printf("NOTE : Pipin keluar dari permainan");
			Del(&F, &simpanDel);
		}
		printf("Skor \n");
		printf("\n");
		PrintSkor(F);
		printf("\n");
		
		i++;
		
	}		
	return 0;
}

