/*Nama/NIM                   : Condro Wiyono	*/
/*Tanggal                    : 28 11 2016*/
/*Topik                      : ADT STACK LIST*/
/*Deskripsi                  : QUEUE LIST */

/*	----- File Include ----- */
#include "P10-18215042-281116-01.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
	// Kamus
	PrioQueue queue;
	infotype X,C;
	int n;				//banyaknya event
	int curTime;		//waktu sekarang
	int dilayani; 		//waktu dilayani
	
	printf("Jumlah siswa : ");
	scanf("%d", &n);
	// Inisialisasi priority queue dan current time
	CreateEmpty(&queue,n);
	
	
	// Mensimulasikan antrian
	int i;
	i = 1;
	while (n--) {
		printf("Info Siswa %d : ",i);
		scanf("%d%d%d", &X.tKedatangan, &X.id, &X.dLayanan);
		
		// Melayani antrian jika current time masih kurang dari kedatangan X
		while (!IsEmpty(queue) && curTime < X.tKedatangan) {
			Del(&queue, &C);
			printf("Siswa %d : ",dilayani+1);
			printf("%d %d %d\n", curTime, C.id, curTime - C.tKedatangan);
			
			curTime += X.dLayanan;
			dilayani++;
		}
		
		// Memasukkan X kedalam antrian
		Add(&queue, X);
		if (curTime < X.tKedatangan)
			curTime = X.tKedatangan;
		i++;
	}
	
	// Melayani siswa yang masih ada di antrian
	while (!IsEmpty(queue)) {
		Del(&queue, &C);
		printf("Siswa %d : ",dilayani+1);
		printf("%d %d %d\n", curTime, C.id, curTime - C.tKedatangan);
		curTime += C.dLayanan;
		dilayani++;
	}
	// Kasus ketika tidak ada siswa yang dilayani
	if (dilayani == 0)
		printf("Tidak ada layanan\n");
	
	return 0;
} 

