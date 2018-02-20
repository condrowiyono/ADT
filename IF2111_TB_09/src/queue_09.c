/* TUGAS BESAR IF2111 - Algoritma dan Struktur Data 
Pokemoon
---------------------------------------------------------------
Nomor Kelompok 	: 09
Nama File : queue_09.c
Deskripsi : ADT Queue untuk load Pokemoon.
---------------------------------------------------------------
*/

//Include Library
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*	File Include */
#include "queue_09.h"
#include "helper_09.h"


#ifndef queue_c
#define queue_c

/*	Predikat Pemeriksaan Kondisi Queue */
bool IsEmpty (Queue Q) {
	/* Kamus */
	/* Algoritma */
	return ((Head(Q)==0)&&(Tail(Q)==0));
}
bool IsFull (Queue Q) {
	/* Kamus */
	/* Algoritma */
	return (NBElmt(Q)==MaxEl(Q));
}
int NBElmt (Queue Q) {
	/* Kamus */
	/* Algoritma */
	if (IsEmpty(Q)) {
	 	return 0;
	} else if (Tail(Q)>Head(Q)) {
		return Tail(Q)-Head(Q)+1;
	} else if (Tail(Q)<Head(Q)) {
		return (MaxEl(Q)+Tail(Q))-Head(Q)+1;
	} else {
		return 1;
	}
}

/*	Konstruktor */
void CreateEmpty (Queue *Q, int Max) {
	/* Kamus */
	/* Algoritma */
	if (Max>0) {
		(*Q).T=(infotype *) malloc ((Max+1)*sizeof (infotype));
		MaxEl(*Q)=Max;
	} else {
		MaxEl(*Q)=0;
	}
	Head(*Q)=0;
	Tail(*Q)=0;
}

/*	Destruktor */
void DeAlokasi (Queue *Q) {
	/* Kamus */
	/* Algoritma */
	free((*Q).T);
	MaxEl(*Q)=0;
}

/*	Operator-Operator Dasar Queue */
void Add (Queue *Q, infotype X) {
	/* Kamus */
	/* Algoritma */
	if (!IsFull(*Q)) {
		if (IsEmpty(*Q)) {
			Head(*Q)=1;
			Tail(*Q)=1;
			InfoTail(*Q)=X;
		} else { 
			Tail(*Q)++;
			if (Tail(*Q)>MaxEl(*Q)) {
				Tail(*Q)=Tail(*Q)%MaxEl(*Q);
				InfoTail(*Q)=X;
			} else {
				InfoTail(*Q)=X;
			}
		}	
	}
}
void Del (Queue *Q, infotype *X) {
	/* Kamus */
	/* Algoritma */
	if (!IsEmpty(*Q)) {
		(*X)=InfoHead(*Q);
		if (NBElmt(*Q)==1) {
			Head(*Q)=0;
			Tail(*Q)=0;
		} else {
			Head(*Q)++;
			if (Head(*Q)>MaxEl(*Q)) {
				Head(*Q)=Head(*Q)%MaxEl(*Q);
			}
		}
	}
}


Queue LoadPokemon() {
	//KAMUS
	char kata[100]; 	//penyimpanan temporary dari kata
	char kata2[100]; 	//penyimpanan temporary dari kata
	Queue Q1;	
	extern char CC;
	extern Kata CKata;
	extern bool EndKata;
	int i;
	int j,k;
	Pokemon P;
	int pjg;
	
	CreateEmpty(&Q1,7);
	//ALGORITMA
	j = 1;
	k = 1;
	EndKata = false;
	//Dari Pokemon 
	STARTKATA(4);
	while (!EndKata) {
		for (i=1;i<=CKata.Length;i++) {
			//harus mulai index 0
			kata[i-1] = CKata.TabKata[i];
			pjg = CKata.Length;
		}
		
		//Menjadikannya string
		kata[pjg]='\0';
		
		//strcpy(kata2, kata);
		
		switch (j % 7) {
			case 1 : {strcpy(P.nama_pokemon,kata);break;} 
			case 2 : {strcpy(P.tipe_pokemon,kata);break;}
			case 3 : {P.hp = strtoint(kata);break;}
			case 4 : {P.attack = pisah(kata);break;}
			case 5 : {P.exp = pisah(kata); break;}
			case 6 : {P.money = pisah(kata);break;}
			case 0 : {P.catchrate = strtoint(kata);
					 Add(&Q1,P);
					 j = 0;
					 break; }
		}
			
		ADVKATA();
		j++;
		
	}
	j = 1;
	k = 1;
	EndKata = false;
	STARTKATA(5);
	while (!EndKata) {
		for (i=1;i<=CKata.Length;i++) {
			//harus mulai index 0
			kata[i-1] = CKata.TabKata[i];
			pjg = CKata.Length;
		}
		
		kata[pjg]='\0';
		//printf("\n");
		strcpy(kata2, kata);
		switch (j % 7) {
			case 1 : {strcpy(P.nama_pokemon,kata);break;} 
			case 2 : {strcpy(P.tipe_pokemon,kata);break;}
			case 3 : {P.hp = strtoint(kata);break;}
			case 4 : {P.attack = pisah(kata);break;}
			case 5 : {P.exp = pisah(kata); break;}
			case 6 : {P.money = pisah(kata);break;}
			case 0 : {P.catchrate = strtoint(kata);
					 Add(&Q1,P);
					 j = 0;
					 break; }
		}
			
		ADVKATA();
		j++;
		
	}
	
	return Q1;
}

#endif
