/* Nama/NIM : Condro Wiyono / 18215042
{ Tanggal : 5 September 2016} 
{ Topik : Review Konsep Dasar Pemrograman dan Pengenalan Bahasa C}
{ Deskripsi :  Menghitung deret S = 1 
-
1/2 + 1/3 
-
1/4 + ... + 1/999 
-
1/1000 */

#include <stdio.h>

/* Program Hellox */
int main () {
	//KAMUS
	const long int N = 3;
	long int i;
	int tanda;
	float s;
	
	//ALGORITMA
	tanda = 1 ;
	s = 1 ;
	i = 2 ;
	
	while (i <= N) {
		tanda = (-1 * tanda);
		s = 1/2;
		//printf("%ld \n", tanda);
		//printf("%ld \n", i);
		printf("%f \n", s);
		i = i + 1;
	}
	
	printf("%f \n", s);
	
	return 0;
	}
