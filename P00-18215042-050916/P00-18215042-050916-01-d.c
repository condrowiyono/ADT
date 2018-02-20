/* Nama/NIM : Condro Wiyono / 18215042
{ Tanggal : 5 September 2016} 
{ Topik : Review Konsep Dasar Pemrograman dan Pengenalan Bahasa C}
{ Deskripsi : { Dibaca T(integer), temperatur air (dalam derajat Celsius) pada tekanan atmosfer }
{ Harus dituliskan wujud air pada temperatur T: Beku, Cair atau Uap }*/

#include <stdio.h>

/* Program Hellox */
int main () {
	//KAMUS
	int T;
	
	//ALGORITMA
	scanf("%d",&T);
	
	if (T <= 0) {
		printf("Beku \n");
	} else 	if (T > 0 && T <= 100) {
		printf("Cair \n");
	} else if (T > 100){
		printf("Uap \n");
	
	}
	return 0;
	}
