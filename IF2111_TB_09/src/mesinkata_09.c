/* TUGAS BESAR IF2111 - Algoritma dan Struktur Data 
Pokemoon
---------------------------------------------------------------
Nomor Kelompok 	: 09
Nama File : mesinkata_09.c
Deskripsi : Mesin Karakter + Mesin Kata digunakan untuk load
			data dari file external.
---------------------------------------------------------------
*/

// INclude dari Library
#include <stdio.h>
#include <string.h>

//INclude header
#include "mesinkata_09.h"

#ifndef MESINKATA_C
#define MESINKATA_C

//Definisi dari karakter external file h
char CC;
Kata CKata;
bool EndKata;

static FILE *pita;
static int retval;

/*
 * KODE FILE POKEMON
 * 1 : ability
 * 2 : pemetaan level
 * 3 : peta
 * 4 : pokemon
 * 5 : pokemon-permainan-baru
 * 6 : toko
 * 7 : peta2
 * 8 : peta3
 * 9 : peta4
 */
 
static char ability[50]  = "ability.txt"; 
static char pemetaanlevel[50]  = "pemetaan-level.txt"; 
static char peta[50]  = "peta.txt"; 
static char pokemon[50]  = "pokemon.txt"; 
static char pokemonpermainanbaru[50]  = "pokemon-permainan-baru.txt"; 
static char toko[50]  = "toko.txt"; 
static char peta2[50]  = "peta2.txt"; 
static char peta3[50]  = "peta3.txt"; 
static char peta4[50]  = "peta4.txt"; 
static char hiscore[50]  = "hiscore.txt"; 

//I.S. : sembarang 
//F.S. : CC adalah karakter pertama pita 
//Jika CC==MARK, EOP menyala (true)
//Jika CC!=MARK, EOP padam (false)
void START(int i){
	//KAMUS
	
	//ALGORITMA
	
	//case of
	switch(i) {
      case 1 : {pita = fopen(ability,"r");break;}
      case 2 : {pita = fopen(pemetaanlevel,"r");break;}
      case 3 : {pita = fopen(peta,"r");break;}
      case 4 : {pita = fopen(pokemon,"r");break;}
      case 5 : {pita = fopen(pokemonpermainanbaru,"r");break;}
      case 6 : {pita = fopen(toko,"r");break;}
      case 7 : {pita = fopen(peta2,"r");break;}
	  case 8 : {pita = fopen(peta3,"r");break;}
	  case 9 : {pita = fopen(peta4,"r");break;}
	  case 10 : {pita = fopen(hiscore,"r");break;}
	  case 11 : {pita = fopen("load_pemain","r");break;}
      default :
         printf("Load file error\n" );
	}	
	ADV();
}

void ADV() {
	//ALGORITMA
	retval = fscanf(pita,"%c",&CC);
	if (EOP()) {
		fclose(pita);
	}
}

bool EOP() {
	
	//ALGORITMA
	return (CC==MARK);
}

void Ignore_Blank() {
	//KAMUS
	extern char CC;
	
	//ALGORITMA
	while (((CC==BLANK)||(CC=='\n'))&&(CC!=MARK)) {
		ADV();
	}
}


void STARTKATA(int i) {
	//KAMUS
	extern char CC;
    
    //ALGORITMA
    START(i);
    Ignore_Blank();
    
    
    if (CC==MARK) {
		EndKata = true;
	} else {
		//EndKata = false;
		SalinKata();
	}
    
}

void ADVKATA() {
	extern char CC;
	
	Ignore_Blank();
	if (CC == MARK ) {
		EndKata = true;
	} else {
		SalinKata();
	}
}

void SalinKata() {
	//KAMUS
	extern char CC;
	bool found;
	int i = 1;
	int j,k;
	
	//ALGORITMA
	do  {
		CKata.TabKata[i] = CC;
		ADV();
		if ((CC==MARK)||(CC==BLANK)||(CC=='\n')) {
			break;
		} else {
			i++;
		}
		
	} while (i<=NMax);
	
	CKata.Length = i;	
}

#endif

