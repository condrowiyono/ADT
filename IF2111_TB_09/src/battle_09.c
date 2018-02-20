/* TUGAS BESAR IF2111 - Algoritma dan Struktur Data 
Pokemoon
---------------------------------------------------------------
Nomor Kelompok 	: 09
Nama File : battle_09.c
Deskripsi : Tarung
---------------------------------------------------------------
*/

#include "battle_09.h"
#include "helper_09.h"
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int awalHPA,awalHPB;

void PrintBattleScreen(Pemain P, Pokemon B){
	//KAMUS
	Pokemon Aktif ;
	MATRIKSFLOAT M;
	M = LoadAbil();
	

	//ALGORITMA
	Aktif = P.pokemon_aktif ;
	system("cls");
	
	printf("|---------------------------------------------------------------------------|\n"); 
	printf("| HP %-10s : %-5g                              HP %-10s : %-5g  |\n", Aktif.nama_pokemon, Aktif.hp, B.nama_pokemon, B.hp);
	printf("| Tipe : %-15s                            Tipe : %-15s  |\n", Aktif.tipe_pokemon, B.tipe_pokemon);
	printf("| Combo %-15g                              Combo %-15g  |\n", getAbil(M,P.pokemon_aktif,B),getAbil(M,B,P.pokemon_aktif));
	printf("|                                                                           |\n");
	printf("|                                                                           |\n");
	printf("|                                                                           |\n");
	printf("|                                                                           |\n");
	printf("|                                                                           |\n");
	printf("|                                                                           |\n");
	printf("|                                                                           |\n");
	printf("|                                                                           |\n");
	printf("|                                                                           |\n");
	printf("|                                                                           |\n");
	printf("|                                                                           |\n");
	printf("|                                                                           |\n");
	printf("|----------------------|------------|------------|--------------------------|\n");
	printf("| ATTACK ENTER         | RUN : R    | BAG : B    |                          |\n");
	printf("|----------------------|------------|------------|--------------------------|\n");
	
}

void PrintOpenBag(List L) {
	addressList P;
	char gerak;
	
	system("cls");
	do {
	
	P = First(L); 
	system("cls");
	printf("|---------------------------------------------------------------------------|\n"); 
	printf("| ISI TAS SAYA                                                              |\n");
	printf("|---------------------------------------------------------------------------|\n");
	while (P != NilList) {
			printf("| %-20s ( tipe: %-10s, harga: %-5d, efek: %-5d )      |\n",Info(P).nama_barang,Info(P).tipe_barang,Info(P).harga,Info(P).efek);
			P  = Next(P);
	}
	printf("|---------------------------------------------------------------------------|\n");
	printf("|---------------------------------------------------------------------------|\n");
	printf("| KELUAR : X                                                                |\n");
	printf("|---------------------------------------------------------------------------|\n");
	
		gerak = getch();
		if (gerak=='x') {
			break;
		} else {
			printf("Tekan X untuk kembali.\n");
			sleep(1);
		}
	} while (gerak !='x');
			
}
void OpenBag(List *L, Barang *item, bool *Pilih) {
	//KAMUS
	char gerak;
	int i,j;
	int pilihan;
	addressList P;
	Barang terpilih;
	
	//ALGORITMA
	pilihan = 1;
	system("cls");
	do {
	i = 1;
	P = First((*L)) ; 
	system("cls");
	printf("|---------------------------------------------------------------------------|\n"); 
	printf("| ISI TAS SAYA                                                              |\n");
	printf("|---------------------------------------------------------------------------|\n");
	while (P != NilList) {
		if (pilihan==i) {
			printf("|> %d. %-18s ( tipe: %-10s, harga: %-5d, efek: %-5d )    |\n",i,Info(P).nama_barang,Info(P).tipe_barang,Info(P).harga,Info(P).efek);
			terpilih = Info(P); 
		}
		else {
			printf("|%d. %-20s ( tipe: %-10s, harga: %-5d, efek: %-5d )    |\n",i,Info(P).nama_barang,Info(P).tipe_barang,Info(P).harga,Info(P).efek);
			
		}
		P  = Next(P);
		i++;
	}
	printf("|                                                                           |\n");
	printf("|-----------------------|---------------------------------------------------|\n");
	printf("| Pilih(W, S dan ENTER) | KELUAR : X                                        |\n");
	printf("|-----------------------|---------------------------------------------------|\n");
	
	if (P != First((*L))) {
		gerak = getch();
		if (gerak=='w') {
			if (pilihan<=1)
				pilihan = 1;
			else
				pilihan = pilihan - 1;
		} else if (gerak=='s') {
			if (pilihan>=i-1)
				pilihan =i-1;
			else
				pilihan = pilihan + 1;
		} else if (gerak==13) {
			(*item) = terpilih;
			DelP(&(*L), terpilih);
			*Pilih = true;
			break;
		} else if (gerak=='x') {
		break;
		} else {
			printf("Input tidak valid.\n");
			sleep(1);
		}
	} else {
		gerak = getch();
		if (gerak=='w') {
			printf("Tas kosong.\n");
			sleep(1);
		} else if (gerak=='s') {
			printf("Tas kosong.\n");
			sleep(1);
		} else if (gerak==13) {
			printf("Tas kosong.\n");
			sleep(1);
		} else
		if (gerak=='x') {
		break;
		} else {
			printf("Input tidak valid.\n");
			sleep(1);
		}
	}
	
	} while (gerak !='x');
		
}



float getAbil(MATRIKSFLOAT M, Pokemon A, Pokemon B){
    int i,j;
	float result;
    
    if (strcmp(A.tipe_pokemon,"BUG") == 0) { i=1;} else
    if (strcmp(A.tipe_pokemon,"ELECTRIC") == 0) { i=2;} else
    if (strcmp(A.tipe_pokemon,"FIRE") == 0) { i=3;} else
    if (strcmp(A.tipe_pokemon,"GRASS") == 0) { i=4;} else
    if (strcmp(A.tipe_pokemon,"POISON") == 0) { i=5;} else
    if (strcmp(A.tipe_pokemon,"PSYCHIC") == 0) { i=6;} else
    if (strcmp(A.tipe_pokemon,"WATER") == 0) { i=7;}
    
    if (strcmp(B.tipe_pokemon,"BUG") == 0) { j=1;} else
    if (strcmp(B.tipe_pokemon,"ELECTRIC") == 0) { j=2;} else
    if (strcmp(B.tipe_pokemon,"FIRE") == 0) { j=3;} else
    if (strcmp(B.tipe_pokemon,"GRASS") == 0) { j=4;} else
    if (strcmp(B.tipe_pokemon,"POISON") == 0) { j=5;} else
    if (strcmp(B.tipe_pokemon,"PSYCHIC") == 0) { j=6;} else
    if (strcmp(B.tipe_pokemon,"WATER") == 0) { j=7;}
    
    result = GetElmtMATRIKSFLOAT (M, i, j);
	return result;
	
}

bool isCombo(MATRIKSFLOAT M, Pokemon A, Pokemon B) {
	return (getAbil(M,A,B)!=1);
}

void hpAwal(int AwA, int AwB) {
	awalHPA = AwA;	
	awalHPB = AwB;
}


void attackpemain(Pemain *P, Pokemon *B){
	//KAMUS
	float damageplayer;
	
	MATRIKSFLOAT M;
	M = LoadAbil();
	//ALGORITMA

	//SAYA MENYERANG B DULUAN
	
	if (isCombo(M,(*P).pokemon_aktif ,(*B))) {
	printf("COMBO %gx damage!", getAbil(M, (*P).pokemon_aktif , (*B)));
	} 
	sleep(1);
	damageplayer = getAbil(M, (*P).pokemon_aktif , (*B)) * acak((*P).pokemon_aktif .attack.X, (*P).pokemon_aktif .attack.Y);
	printf("\n%s menyerang %g damage.", (*P).pokemon_aktif.nama_pokemon, damageplayer);
	(*B).hp = (*B).hp - damageplayer;
	sleep(1);	
}

void attackmusuh(Pemain *P, Pokemon *B){
	//KAMUS
	float damagemusuh;
	
	MATRIKSFLOAT M;
	M = LoadAbil();
	//ALGORITMA

	if ((*B).hp>0) {
		//B MENYERANG SAYA KEMUDIAN
		
		if (isCombo(M, (*B), (*P).pokemon_aktif))  {
		printf("COMBO %gx damage!\n", getAbil(M, (*B), (*P).pokemon_aktif));
		} 
		sleep(1);
		damagemusuh = getAbil(M, (*B), (*P).pokemon_aktif) * acak((*B).attack.X, (*B).attack.Y);
		printf("\n%s menyerang %g damage.\n", (*B).nama_pokemon, damagemusuh);
		(*P).pokemon_aktif .hp = (*P).pokemon_aktif .hp - damagemusuh;
		sleep(1);
	}
	
	
}