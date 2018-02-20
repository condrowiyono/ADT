/* TUGAS BESAR IF2111 - Algoritma dan Struktur Data 
Pokemoon
---------------------------------------------------------------
Nomor Kelompok 	: 09
Nama File : pokemon_09.h
Deskripsi : Mendeklarasikan semua tipe data yang digunakan
---------------------------------------------------------------
*/

#include "boolean_09.h"
#include "point_09.h"

#ifndef POKEMON_H
#define POKEMON_H

//Tipe data Pokemon
typedef struct {
	char nama_pokemon[100];
	char tipe_pokemon[100];
	float hp;
	POINT attack;  	//X untuk maksimal Y minimal
	POINT exp;		//X untuk maksimal Y minimal
	POINT money;	//X untuk maksimal Y minimal
	int catchrate;
}Pokemon; 

typedef struct {
	Pokemon P[100];
	int Nef;
}DaftarPokemon; 

void BuatDaftarPokemon(DaftarPokemon *D);

void TambahDaftarPokemon(DaftarPokemon *D, Pokemon P);

DaftarPokemon LoadPokemonAwal();


#endif