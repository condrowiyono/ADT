/* TUGAS BESAR IF2111 - Algoritma dan Struktur Data 
Pokemoon
---------------------------------------------------------------
Nomor Kelompok 	: 09
Nama File : naration_09.c
Deskripsi : Beberapa teks narasi sebelum permainan mulai
---------------------------------------------------------------
*/

#include "naration_09.h"
#include <string.h>

DaftarNarasi BuatNarasiIntro(){
	//var
	DaftarNarasi D1;
	
	//GAMBAR PROFESOR
	strcpy(D1.Mem[1].Teks,"Hi, sorry to keep you waiting.");
	strcpy(D1.Mem[2].Teks,"Welcome to the world of Pokemon!");
	strcpy(D1.Mem[3].Teks,"My name is Riza.");
	strcpy(D1.Mem[4].Teks,"But everyone calls me Pak Riza or Pokemon Professor.");
	strcpy(D1.Mem[5].Teks,"This is what we call Pokemon.");
	//GAMBAR POKE
	strcpy(D1.Mem[6].Teks,"This world is widely inhibited by creatures known as Pokemon.");
	strcpy(D1.Mem[7].Teks,"We human live alongside Pokemon, at times as friendly playmates, ");
	strcpy(D1.Mem[8].Teks,"and at time as cooperative workmates.");
	strcpy(D1.Mem[9].Teks,"And sometimes, we band together and battle, like us.");
	strcpy(D1.Mem[10].Teks,"In fact, there are many SECRET Pokemon.");
	strcpy(D1.Mem[11].Teks,"To unlock the mistery, I do my job.");
	strcpy(D1.Mem[12].Teks,"And who are you?");
	//INPUT NAMA DISINI
	//GAMBAR ORANG
	strcpy(D1.Mem[13].Teks,"There is a SECRET pokemon in the area near here.");
	strcpy(D1.Mem[14].Teks,"To unlock it, you have to capture all the pokemon who lived there first.");
	strcpy(D1.Mem[15].Teks,"Are you ready?");
	strcpy(D1.Mem[16].Teks,"Take courage, and leap into the world of Pokemon where the dream, ");
	strcpy(D1.Mem[17].Teks,"adventures, and FRIENDSHIP await.");
	strcpy(D1.Mem[18].Teks,"First, thing first, choose your starting pokemon.");
	
	D1.Nef = 18;
	return D1;
}
DaftarNarasi BuatNarasiBatle(){
	
}
DaftarNarasi BuatNarasiBag(){
	
}
