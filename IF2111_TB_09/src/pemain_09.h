/* TUGAS BESAR IF2111 - Algoritma dan Struktur Data 
Pokemoon
---------------------------------------------------------------
Nomor Kelompok 	: 09
Nama File : pemain_09.h
Deskripsi : Pemain dan leveling
---------------------------------------------------------------
*/

#include "boolean_09.h"
#include "pokemon_09.h"
#include "stack_09.h"
#include "point_09.h"
#include "listdp_09.h"

#ifndef PEMAIN_H
#define PEMAIN_H

//Tipe data Pokemon

typedef struct {
	char nama[100];
	Pokemon pokemon_aktif;
	Stack pokemon;
	int uang;
	int exp;
	int level;
	POINT Posisi; //Posisi X dan Y
}Pemain; 

typedef struct {
	int level;
	POINT rentang;
} Leveling;

typedef struct {
	Leveling L[10];
	int Nef;
} DaftarLevel;

//KELOMPOK CREATE
void BuatPemain(Pemain *P) ;
void TambahPokemonPemain(Pemain *P,Pokemon Poke);

//KELOMPOK GET
int getExp(Pemain P);
int getUang(Pemain P);
int getLevel(Pemain P);
POINT getPosisi(Pemain P);
Stack getSemuaPokemon(Pemain P);
Pokemon getPokemon(Pemain P);
void PlayerInfo(Pemain P,POINT Posi, List Bag);
void GantiPokemon(Pemain *P, Pokemon *Poke);

//KELOMPOK EDIT
void GantiExp(Pemain *P,int exp);
void GantiUang(Pemain *P,int uang);
void GantiLevel(Pemain *P);

//KELOMPOK LEVELING
void BuatLeveling(DaftarLevel *L);
void TambahLeveling(DaftarLevel *L, Leveling X);
DaftarLevel LoadLevel();
#endif