/*Nama/NIM                   : Condro Wiyono	*/
/*Tanggal                    : 24 Oktober 2016*/
/*Topik                      : ADT MESINKAR*/
/*Deskripsi                  : Ini adalah file impelementasi dari ADT KATA
*/

#include "mesinkar.h"
#include <stdio.h>

#ifndef MESINKATA_C
#define MESINKATA_C

#include "P05-18215042-241016-01.h"

Kata CKata;
bool EndKata;

void Ignore_Blank() {
	extern char CC;
	
	while ((CC==BLANK)&&(CC!=MARK)) {
		ADV();
	}
}

void STARTKATA() {
	//KAMUS
	extern char CC;
    
    //ALGORITMA
    START();
    Ignore_Blank();
    
    
    if (CC==MARK) {
		EndKata = true;
	} else {
		EndKata = false;
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
	extern char CC;
	
	int i = 1;
	
	do  {
		CKata.TabKata[i] = CC;
		ADV();
		
		if ((CC==MARK)||(CC==BLANK)) {
			break;
		} else {
			i++;
		}
	} while (i<=NMax);
	
	CKata.Length = i;

}

float PanjangRataRata(){
	int NbKata;
	int LTotal;
	float rata;
	
	NbKata = 0;
	LTotal = 0;
	
	do{
		NbKata = NbKata + 1;
		LTotal = LTotal + CKata.Length;
	} while (!EndKata);
	
	rata = LTotal / NbKata;
	return rata;
}

//Tambahan

int KataBiasa(){
	int NbKata;
	
	NbKata = 0;
	
	do{
		if (CKata.Length<PanjangRataRata()){
		NbKata = NbKata + 1;
	}		
	} while (!EndKata);
	
	return NbKata;

}

int KataPanjang(){
	int NbKata;
	
	NbKata = 0;
	
	do{
		if (CKata.Length>PanjangRataRata()){
		NbKata = NbKata + 1;
	}		
	} while (!EndKata);
	
	return NbKata;
}

#endif

