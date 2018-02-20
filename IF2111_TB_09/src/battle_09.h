/* TUGAS BESAR IF2111 - Algoritma dan Struktur Data 
Pokemoon
---------------------------------------------------------------
Nomor Kelompok 	: 09
Nama File : battle_09.h
Deskripsi : Tarung
---------------------------------------------------------------
*/

#include "boolean_09.h"
#include "pemain_09.h"
#include "listdp_09.h"
#include "matrikfloat_09.h"

#ifndef BATTLE_H
#define BATTLE_H

float getAbil(MATRIKSFLOAT M, Pokemon A, Pokemon B);

void attackpemain(Pemain *P, Pokemon *B);
void attackmusuh(Pemain *P, Pokemon *B);
void lari();
bool isCombo(MATRIKSFLOAT M, Pokemon A, Pokemon B);

void hpAwal(int AwA, int AwB);
void PrintBattleScreen(Pemain P, Pokemon B);
void PrintOpenBag(List L);
void OpenBag(List *L, Barang *item, bool *Pilih);

#endif