/*Nama/NIM                   : Condro Wiyono	*/
/*Tanggal                    : 31 Oktober 2016*/
/*Topik                      : ADT SETAK*/
/*Deskripsi                  : Ini adalah file driver dari ADT STACK */

#include "P06-18215042-311016-01.h"
#include <stdio.h>

//KAMUS GLOBAL

void cetak(Stack S) {
/* Mencetak setiap nilai dari stack S */

	//KAMUS 
	int j;
	
	//ALGORITMA
	printf("Elemen Stack : ");
	for (j=1;j<=Top(S);j++) {
		printf("%d",S.T[j]);
		if (j!=Top(S)) 
			printf(",");
		
	}

}

int charkeint(char Z) {
	int X;
	
	if (Z==48) X=0; else	
	if (Z==49) X=1; else	
	if (Z==50) X=2; else	
	if (Z==51) X=3; else	
	if (Z==52) X=4; else	
	if (Z==53) X=5; else	
	if (Z==54) X=6; else	
	if (Z==55) X=7; else	
	if (Z==56) X=8; else	
	if (Z==57) X=9; else	
	if (Z==57) X=9; else	
	X = 0 ;
	
	return X;
}

void Kalkulator() {
// Menjalankan program utama yaitu kalkulator

}

int main() {
	Stack S;
	//Bermain dengan ASCII
	char Z;
	int Zin;
	int out;
	
	int OP1;
	int OP2;
	char CT;
	
	CreateEmpty(&S);
	
	printf("KALKULATOR \n");

	do  {
		printf("Operasi: "); 
		scanf("%c",&Z);
		if (!IsOperator(Z)) {
				Zin = charkeint(Z);
				Push(&S,Zin);
				cetak(S);
				//printf("\n"); 
		} else {
			   Pop(&S, &OP2) ;
			   Pop(&S, &OP1) ;
			   Push(&S,Hitung(OP1,OP2,Z));
			   cetak(S);
			   printf("\n"); 
		}

	} while (!EndToken(Z));
	
	printf("Hasil : %d ",InfoTop(S));
	
		
	return 0;
}

