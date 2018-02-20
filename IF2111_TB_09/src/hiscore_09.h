/* TUGAS BESAR IF2111 - Algoritma dan Struktur Data 
Pokemoon
---------------------------------------------------------------
Nomor Kelompok 	: 09
Nama File : hiscore_09.h
Deskripsi : Mendeklarasikan semua tipe data yang digunakan
---------------------------------------------------------------
*/

typedef struct {
	char nama[100];
	int exp;
	char tanggal[20];
} Score;

typedef struct {
	Score S[100];
	int Nef;
} Scoreboard;

#ifndef HISCORE_H
#define HISCORE_H
Scoreboard LoadScoreboard();
void TampilScoreboard(Scoreboard S);
void ScoreboardKosong(Scoreboard *S);
void TambahScoreboard(Scoreboard *S, Score Sc);
void Sort(Scoreboard *S );
void tulisFileScoreboard(Scoreboard S);
void tulisLayarScoreboard(Scoreboard S);
#endif