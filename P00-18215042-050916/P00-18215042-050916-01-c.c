/* Nama/NIM : Condro Wiyono / 18215042
{ Tanggal : 5 September 2016} 
{ Topik : Review Konsep Dasar Pemrograman dan Pengenalan Bahasa C}
{ Deskripsi : { Input : JamAwal, JamAKhir bertype Jam (HH:MM:DD);
dan JamAkhir SELALU ≥ JamAwal
Output : Selisih waktu dalam detik antara JamAwal dan JamAkhir }*/

#include <stdio.h>

/* Program Hellox */
int main () {
	//KAMUS
    typedef struct { 
             int HH; 
             int MM;
             int DD;  } jam; 

	jam JamAwal, JamAkhir ;
	int durasi;
	
	//ALGORITMA
	scanf("%d",&JamAwal.HH);
	scanf("%d",&JamAwal.MM);
	scanf("%d",&JamAwal.DD);
	
	scanf("%d",&JamAkhir.HH);
	scanf("%d",&JamAkhir.MM);
	scanf("%d",&JamAkhir.DD);
	
	durasi = (JamAkhir.HH * 3600 + JamAkhir.MM * 60 + JamAkhir.DD)  - (JamAwal.HH * 3600 + JamAwal.MM * 60 + JamAwal.DD);
	
	printf("%d \n",durasi);
	return 0;
	}
