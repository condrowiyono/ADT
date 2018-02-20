/* TUGAS BESAR IF2111 - Algoritma dan Struktur Data 
Pokemoon
---------------------------------------------------------------
Nomor Kelompok 	: 09
Nama File : pemain_09.c
Deskripsi : Pemain dan Lev
---------------------------------------------------------------
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "pemain_09.h"
#include "mesinkata_09.h"
#include "helper_09.h"
#include "load_09.h"

void BuatPemain(Pemain *P) {
	char k[100];
	printf("Nama : ");
	scanf("%s",k);
	strcpy((*P).nama,k);
	CreateEmptyStack(&((*P).pokemon));
	(*P).exp = 0;
	(*P).uang = 1000;
	(*P).level = 1;
	(*P).Posisi.Y=6;
	(*P).Posisi.X=6;
}

void TambahPokemonPemain(Pemain *P,Pokemon Poke) {
	//I.S : Pemain dengan Pokemon tertentu bisa kosong, asumsi stack sudah pernah dibuat
	//F.S : Pemain dengan Pokemon bertambah satu
	//Tambahkan
	Push(&((*P).pokemon),Poke);
	(*P).pokemon_aktif = ((*P).pokemon).T[((*P).pokemon).TOP];
}

void GantiPokemon(Pemain *P,Pokemon *Poke) {
	//I.S : Pemain dengan Pokemon tertentu bisa kosong, asumsi stack sudah pernah dibuat
	//F.S : Pemain dengan Pokemon bertambah satu
	//Tambahkan
	Pop(&((*P).pokemon),Poke);
	
	if (IsEmptyStack(((*P).pokemon)))
		(*Poke).hp=-9999;
	else
		(*P).pokemon_aktif = ((*P).pokemon).T[((*P).pokemon).TOP];
}

int getExp(Pemain P) {
	return P.exp;
}

int getUang(Pemain P) {
	return P.uang;
}
int getLevel(Pemain P) {
	return P.level;
}
POINT getPosisi(Pemain P) {
	return P.Posisi;
}
Stack getSemuaPokemon(Pemain P){
	return P.pokemon;
}
Pokemon getPokemon(Pemain P) {
	return P.pokemon_aktif;
}

void PlayerInfo(Pemain P, POINT Posi, List Bag){
	char gerak;
	int i;
	P.Posisi = Posi;
	system("cls");
    do {
		system("cls");
		printf("|---------------------------------------------------------------------------|\n"); 
		printf("| Player Info                                                               |\n");
		printf("|---------------------------------------------------------------------------|\n"); 
		printf("| Nama              : %-50s    |\n",P.nama);
		printf("| Pokemon Aktif     : %-50s    |\n",getPokemon(P).nama_pokemon);
		printf("| Pokemon           :                                                       |\n");
		printf("| [ %s",P.pokemon.T[1].nama_pokemon);
		for (i=2;i<=P.pokemon.TOP;i++){
			printf(", %s",P.pokemon.T[i].nama_pokemon);
		}
		printf("]");
		printf("\n");
		printf("| Uang              : %-50d    |\n",getUang(P));
		printf("| Experience        : %-50d    |\n",getExp(P));
		printf("| Level             : %-50d    |\n",getLevel(P));
		printf("| Posisi            : %-2d,%-2d                                                 |\n",P.Posisi.X, P.Posisi.Y);
		printf("|                                                                           |\n");
		printf("|                                                                           |\n");
		printf("|                                                                           |\n");
		printf("|                                                                           |\n");
		printf("|                                                                           |\n");
		printf("|                                                                           |\n");
		printf("|                                                                           |\n");
		printf("|---------------------------------------------------------------------------|\n");
		printf("| KELUAR X  | SAVE S                                                        |\n");
		printf("|---------------------------------------------------------------------------|\n");
		gerak = getch();
		if (gerak=='x') {			
			break; 
		} else if ( gerak=='s') {
			simpanSemua(P, P.pokemon, Bag);
		}
		else {
			printf("Arah tidak valid \n");
		}
	} while (gerak !='x');
}

void GantiExp(Pemain *P,int exp) {
	(*P).exp = exp;
	GantiLevel(&(*P));
}
void GantiUang(Pemain *P,int uang) {
	(*P).uang = uang;
}
void GantiLevel(Pemain *P){
	//KAMUS
	DaftarLevel L = LoadLevel();
	int level;
	int i;
	bool found = false;
	
	level = (*P).exp;

	i = 1;
	while ((!found)&& (i<10)) {
		if ((level >= L.L[i].rentang.X) && (level <= L.L[i].rentang.Y))
			found = true;
		else 
			i++;
	}
	if (found) 
		(*P).level = i;
	else
		(*P).level = 10;
}

void BuatDaftarLevel(DaftarLevel *L){
	(*L).Nef = 0;
}

void TambahDaftarLevel(DaftarLevel *L, Leveling X){
	int i = (*L).Nef;
	
	(*L).L[i+1] = X;
	(*L).Nef = (*L).Nef + 1; 
}


DaftarLevel LoadLevel() {
	//KAMUS
	char kata[100]; 	//penyimpanan temporary dari kata
	DaftarLevel L;
	Leveling Lv;
	extern char CC;
	extern Kata CKata;
	extern bool EndKata;
	//Keperluan Indexing
	int i;
	int j;
	int pjg;
	bool temu = false;
	
	//ALGORITMA
	j = 1;
	EndKata = false;
	BuatDaftarLevel(&L);
	STARTKATA(2);
	while (!EndKata) {
		for (i=1;i<=CKata.Length;i++) {
			//harus mulai index 0
			kata[i-1] = CKata.TabKata[i];
			pjg = CKata.Length;
			//KASUS UNTUK LEVEL 10
			if (kata[i-1]=='>')
				temu=true;
		}
		kata[pjg]='\0';
		
		//KASUS UNTUK LEVEL 10 JIKA KETEMU
		if (temu) {
			break;
		}
		
		//printf("%d %s \n",j, kata);
			
		switch (j % 2) {
			case 1 : {Lv.level=strtoint(kata);break;} 
			case 0 : {Lv.rentang = pisah(kata);
					  TambahDaftarLevel(&L,Lv);
					  j = 0;
					  break; }
		}
		
		ADVKATA();
		j++;
		
	}
	return L;	
}


