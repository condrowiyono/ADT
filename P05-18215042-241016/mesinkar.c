/*Nama/NIM                   : Condro Wiyono	*/
/*Tanggal                    : 23 Oktober 2016*/
/*Topik                      : ADT MESINKAR*/
/*Deskripsi                  : Ini adalah file implementasi dari ADT MESINKAR*/

#ifndef MESINKAR_C
#define MESINKAR_C

#include <stdio.h>
#include "mesinkar.h"

char CC;

static FILE *pita;
static int retval;

void START(){
	/*	{ I.S. : sembarang }
	{ F.S. : CC adalah karakter pertama pita }
	{ Jika CC==MARK, EOP menyala (true) }
	{ Jika CC!=MARK, EOP padam (false) } */
	
	//ALGORITMA
	pita = fopen("pitakar.txt","r");
	ADV();
}
void ADV() {
	/*	{ I.S. : CC!=MARK }
	{ F.S. : CC adalah karakter berikutnya dari CC pada I.S. }
	{ Jika CC==MARK, EOP menyala (true) } */
	
	//ALGORITMA
	retval = fscanf(pita,"%c",&CC);
	if (EOP()) {
		fclose(pita);
	}
}

bool EOP() {
	/*	{ true jika CC == MARK } */
	
	//ALGORITMA
	return (CC==MARK);
}

#endif

