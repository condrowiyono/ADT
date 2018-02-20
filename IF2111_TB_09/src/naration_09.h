/* TUGAS BESAR IF2111 - Algoritma dan Struktur Data 
Pokemoon
---------------------------------------------------------------
Nomor Kelompok 	: 09
Nama File : naration_09.h
Deskripsi : Beberapa teks narasi sebelum permainan mulai
---------------------------------------------------------------
*/

#ifndef NARATION_H
#define NARATION_H

#define AKHIRNARASI '.'
typedef struct {
	char Teks[256] ;
} Narasi;
typedef struct {
	Narasi Mem[50];
	int Nef;
} DaftarNarasi;

DaftarNarasi BuatNarasiIntro();
DaftarNarasi BuatNarasiBatle();
DaftarNarasi BuatNarasiBag();

#endif