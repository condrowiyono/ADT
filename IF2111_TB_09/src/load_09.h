/* TUGAS BESAR IF2111 - Algoritma dan Struktur Data 
Pokemoon
---------------------------------------------------------------
Nomor Kelompok 	: 09
Nama File : load_09.h
Deskripsi : Mendeklarasikan semua tipe data yang digunakan
---------------------------------------------------------------
*/

#include "pemain_09.h"
#include "pokemon_09.h"
#include "listdp_09.h"
#include "stack_09.h"

#ifndef LOADD_H
#define LOADD_H

void simpanPemain(Pemain P);
void simpanPokemon(Stack P);
void simpanBag(List B);
void simpanSemua(Pemain P, Stack S, List L);

void loadPemain(Pemain P);
void loadPokemon(Pokemon P);
void loadBag(List B);

#endif