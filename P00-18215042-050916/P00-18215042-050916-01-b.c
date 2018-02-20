/* Nama/NIM : Condro Wiyono / 18215042
{ Tanggal : 5 September 2016} 
{ Topik : Review Konsep Dasar Pemrograman dan Pengenalan Bahasa C}
{ Deskripsi : { Dibaca arus I dan hambatan R, 
dihitung besarnya tegangan V = I * R dan
dituliskan hasilnya }*/

#include <stdio.h>
#include <stdlib.h>

/* Program Hellox */
int main () {
	//KAMUS
	float i,r,v;

	//ALGORITMA
	printf("Input nilai arus : ");
	scanf("%f",&i);
	printf("Input nilai hambatan : ");
	scanf("%f",&r);
	v = i * r ;
	printf("Tegangan listrik = %8.3f  Volt\n", v);
	

	
	return 0;
	}
