/*Nama/NIM                   : Condro Wiyono	*/
/*Tanggal                    : 23 Oktober 2016*/
/*Topik                      : ADT MESINKAR*/
/*Deskripsi                  : Ini adalah file driver dari ADT MESINKAR tambahan*/

#include "mesinkar.h"
#include <stdio.h>
#include "P05-18215042-241016-01.h"

int main() {
	extern char CC;
	extern Kata CKata;
	int i;
	int wordbiasa;
	int wordpanjang;
	int biaya;
	
	wordbiasa = 0;
	wordpanjang = 0;
	printf("==== TELEGRAM ==== \n");
	printf("Isi Telegram: ");
	
	STARTKATA();
	while (!EndKata) {
		for (i=1;i<=CKata.Length;i++) {
			printf("%c",CKata.TabKata[i]);
			
		}
		printf(" ");
		
		ADVKATA();
	}
	
	printf("\n");
	printf("Kata Biasa : %d \n",wordbiasa);
	printf("Kata Panjang : %d \n",wordpanjang);
	printf("Panjang Rata - rata : %f karakter/kata \n",PanjangRataRata());
	
	biaya = (wordbiasa + wordpanjang) * 1000 + wordpanjang * 200 ;
	
	if ((wordbiasa + wordpanjang)>10) {
		biaya = biaya + 200;
	}
	printf("Biaya : %f : \n", biaya);

return 0;
}
