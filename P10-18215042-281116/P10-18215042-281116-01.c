/*Nama/NIM                   : Condro Wiyono	*/
/*Tanggal                    : 28 11 2016*/
/*Topik                      : ADT STACK LIST*/
/*Deskripsi                  : PrioQueue LIST */

/*	----- File Include ----- */
#include "boolean.h"
#include "P10-18215042-281116-01.h"
#include <stdlib.h>
#include <stdio.h>

/*	----- Konstruktor ----- */
void CreateEmpty (PrioQueue * Q, int Max) {
	/* Kamus Lokal */

	/* Algoritma */
	Head(*Q) = Nil;
	Tail(*Q) = Nil;
	(*Q).MaxEl = Max;
	
}

/*	----- Prototype manajemen memori ----- */
void Alokasi (address * P, infotype X) {
	/* Kamus Lokal */

	/* Algoritma */
	(*P) = (address) malloc (sizeof (ElmtPrioQueue));
	if ((*P) != Nil) {
		Info(*P) = X;
		Next(*P) = Nil;
	}
}

void Dealokasi (address * P) {
	/* Kamus Lokal */

	/* Algoritma */
	free(*P);
}

bool IsEmpty (PrioQueue Q) {
	/* Kamus Lokal */

	/* Algoritma */
	return ((Head(Q) == Nil) && (Tail(Q) == Nil));
}

bool IsFull (PrioQueue Q) {
	/* Kamus Lokal */

	/* Algoritma */
	//return ((Head(Q)==1 && Tail(Q)==Q.MaxEl) );
}

int NBElmt (PrioQueue Q) {
	/* Kamus Lokal */
	address P;
	int N;
	
	/* Algoritma */
	P = Head(Q);
	N = 0;
	while (P != Nil) {
		N = N + 1;
		P = Next(P);
	}
	return N;
}



/*	----- Primitif Add/Delete ----- */
void Add (PrioQueue *Q, infotype X) {
	/* Kamus Lokal */
	address P;
	bool inserted; // boolean untuk menyatakan sudah diinsert ato belum

	/* Algoritma */
	Alokasi(&P,X);
	if (P != Nil) {
		if (IsEmpty(*Q)) {
			Head(*Q) = P;
			Tail(*Q) = P;
		} else {
				Next(Tail(*Q)) = P;
				Tail(*Q) = P;
				
				address prev = Nil;			//dua buah address untuk jalan2
				address i = Head(*Q);		//dua buah address untuk jalan2
				
				inserted = false;
				
				while (!inserted && i != Nil) {
					if (Info(i).dLayanan < X.dLayanan) {
						if (prev == Nil) {
							Head(*Q) = P;
							Next(P) = i;
						} else {
							Next(prev) = P;
							Next(P) = i;
						}
						inserted = true;
					}
					prev = i;
					i = Next(i);
				}
				
				if (!inserted)
					Next(prev) = P;	
	
		}
	}
}

void Del (PrioQueue * Q, infotype * X) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	(*X) = InfoHead(*Q);
	P = Head(*Q);
	Head(*Q) = Next(Head(*Q));
	
	//kasus
	if (Head(*Q) == Nil) {
		Tail(*Q) = Nil;
	}
	Dealokasi(&P);
}

/*	---- Operasi Lain ----- */
void PrintPrioQueue (PrioQueue Q) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	P = Head(Q);
	if (P == Nil) {
		printf("Stack kosong\n");
	} else {
		printf("[%d",Info(P));
		P = Next(P);
		while ((P != Nil)) {
			printf(", %d",Info(P));
			P = Next(P);
		}
		printf("]\n");
	}
}
