/* TUGAS BESAR IF2111 - Algoritma dan Struktur Data 
Pokemoon
---------------------------------------------------------------
Nomor Kelompok 	: 09
Nama File : pokemon_09.c
Deskripsi : Mendeklarasikan semua tipe data yang digunakan
---------------------------------------------------------------
*/

#include "pokemon_09.h"
#include "mesinkata_09.h"
#include "helper_09.h"
#include <string.h>
 
 
void BuatDaftarPokemon(DaftarPokemon *D){
	(*D).Nef = 0;
}

void TambahDaftarPokemon(DaftarPokemon *D, Pokemon P){
	int i = (*D).Nef;
	
	(*D).P[i+1] = P;
	(*D).Nef = (*D).Nef + 1; 
}


DaftarPokemon LoadPokemonAwal() {
	//KAMUS
	char kata[100]; 	//penyimpanan temporary dari kata
	char kata2[100]; 	//penyimpanan temporary dari kata
	DaftarPokemon D1;	
	extern char CC;
	extern Kata CKata;
	extern bool EndKata;
	int i;
	int j,k;
	Pokemon P;
	int pjg;
	
	BuatDaftarPokemon(&D1);
	//ALGORITMA
	j = 1;
	k = 1;
	EndKata = false;
	STARTKATA(5);
	while (!EndKata) {
		for (i=1;i<=CKata.Length;i++) {
			//harus mulai index 0
			kata[i-1] = CKata.TabKata[i];
			pjg = CKata.Length;
		}
		
		kata[pjg]='\0';
		//printf("\n");
		strcpy(kata2, kata);
		switch (j % 7) {
			case 1 : {strcpy(P.nama_pokemon,kata);break;} 
			case 2 : {strcpy(P.tipe_pokemon,kata);break;}
			case 3 : {P.hp = strtoint(kata);break;}
			case 4 : {P.attack = pisah(kata);break;}
			case 5 : {P.exp = pisah(kata); break;}
			case 6 : {P.money = pisah(kata);break;}
			case 0 : {P.catchrate = strtoint(kata);
					 TambahDaftarPokemon(&D1,P);
					 j = 0;
					 break; }
		}
			
		ADVKATA();
		j++;
		
	}
	
	return D1;
}