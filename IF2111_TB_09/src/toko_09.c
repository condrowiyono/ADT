/* TUGAS BESAR IF2111 - Algoritma dan Struktur Data 
Pokemoon
---------------------------------------------------------------
Nomor Kelompok 	: 09
Nama File : toko_09.c
Deskripsi : Barang Barang di toko
---------------------------------------------------------------
*/

#include "toko_09.h"
#include "mesinkata_09.h"
#include "helper_09.h"
#include <string.h>
#include <stdio.h>


void TokoKosong(Toko *T) {
	(*T).Nef = 0 ;	
}

void TambahBarang(Toko *T, Barang X) {
	int i = (*T).Nef;
	
	(*T).L[i+1] = X;
	(*T).Nef = (*T).Nef + 1; 
}

Toko LoadBarang() {
	//KAMUS
	char kata[100]; 	//penyimpanan temporary dari kata
	char kata2[100]; 	//penyimpanan temporary dari kata	
	extern char CC;
	extern Kata CKata;
	extern bool EndKata;
	int i;
	int j,k;
	int pjg;
	Toko T;
	Barang B; 
	
	TokoKosong(&T);
	
	//ALGORITMA
	j = 1;
	k = 1;
	EndKata = false;
	//Dari Pokemon 
	STARTKATA(6);
	while (!EndKata) {
		for (i=1;i<=CKata.Length;i++) {
			//harus mulai index 0
			kata[i-1] = CKata.TabKata[i];
			pjg = CKata.Length;
		}
		
		//Menjadikannya string
		kata[pjg]='\0';
		
		//strcpy(kata2, kata);
		
		switch (j % 4) {
			case 1 : {strcpy(B.tipe_barang,kata);break;} 
			case 2 : {strcpy(B.nama_barang,kata);break;}
			case 3 : {B.harga = strtoint(kata);break;}
			case 0 : {B.efek = strtoint(kata);
					 TambahBarang(&T,B);
					 j = 0;
					 break; }
		}	
		ADVKATA();
		j++;
		
	}
	//
	T.Nef = 5;
	return T;
}

/*
int main() {
	Toko T;
	Barang B;
	
	
	strcpy(B.tipe_barang,"Poke");
	strcpy(B.nama_barang,"Poke");
	B.harga = 100;
	B.efek = 100;
	
	TokoKosong(&T);
	TambahBarang(&T,B);
	TambahBarang(&T,B);
	
	int i;
	for (i=1;i<=T.Nef;i++) {
		printf("%s, %s, %d, %d \n", T.L[i].tipe_barang,T.L[i].nama_barang,T.L[i].harga,T.L[i].efek);
	}
}
*/