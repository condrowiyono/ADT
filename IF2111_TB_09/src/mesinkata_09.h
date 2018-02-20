/* TUGAS BESAR IF2111 - Algoritma dan Struktur Data 
Pokemoon
---------------------------------------------------------------
Nomor Kelompok 	: 09
Nama File : mesinkata_09.h
Deskripsi : Mesin Karakter + Mesin Kata digunakan untuk load
			data dari file external.
---------------------------------------------------------------
*/
#include "boolean_09.h"

#ifndef MESINKATA_H
#define MESINKATA_H

#define BLANK ' '
#define NMax 50
#define MARK '.'

//Tipe Kata
typedef struct { 
	char TabKata[NMax-1];
	int Length;  
} Kata; 

extern char CC;
extern Kata CKata;
extern bool EndKata;

//I.S. : sembarang 
//F.S. : CC adalah karakter pertama pita 
//Jika CC==MARK, EOP menyala (true)
//Jika CC!=MARK, EOP padam (false)
void START(int i);

//I.S. : CC!=MARK }
//F.S. : CC adalah karakter berikutnya dari CC pada I.S. }
//Jika CC==MARK, EOP menyala (true) } */
void ADV();

/*	{ true jika CC == MARK } */
bool EOP();

void Ignore_Blank();

void STARTKATA(int i);

void ADVKATA();

void SalinKata();

#endif
