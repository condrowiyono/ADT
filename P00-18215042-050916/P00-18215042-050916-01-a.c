/* Nama/NIM : Condro Wiyono / 18215042
{ Tanggal : 5 September 2016} 
{ Topik : Review Konsep Dasar Pemrograman dan Pengenalan Bahasa C}
{ Deskripsi : Menulis "HELLO" berikut nama yang diberikan dari piranti masukan ke
piranti keluaran} */

#include <stdio.h>


/* Program Hellox */
/* Menulis "HELLO" berikut nama yang diberikan dari piranti masukan ke
piranti keluaran */
int main () {
	//KAMUS
	char name[20];
	
	//ALGORITMA
	
	scanf("%s", &name);
	printf("HELLO %s \n", name);
	
	return 0;
	}
