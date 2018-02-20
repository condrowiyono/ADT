/* Nama/NIM : Condro Wiyono / 18215042
{ Tanggal : 5 September 2016} 
{ Topik : Review Konsep Dasar Pemrograman dan Pengenalan Bahasa C}
{ Deskripsi : { 
Menjumlahkan dan mencacah (melakukan counting) nilai-nilai X yang dibaca. 
Mark = 9999 }*/

#include <stdio.h>

/* Program Hellox */
int main () {
	//KAMUS
	int i;
	int x;
	int sum;
	
	//ALGORITMA
	i = 1 ;
	sum = 0;
	
	scanf("%d",&x);
	while (x != 9999 ) {
		printf("%d",x);
		sum = sum + x;
		i++ ;
		scanf("%d",&x);
	};
	
	printf("Jumlah : %d \n",sum);
	printf("Banyak bilangan : %d \n", i-1);
	return 0;
	}
