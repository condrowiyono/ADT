/*Nama/NIM                   : Condro Wiyono	*/
/*Tanggal                    : 24 Oktober 2016*/
/*Topik                      : ADT MESINKAR*/
/*Deskripsi                  : Ini adalah file haeder dari ADT KATA
*/

#include "mesinkar.h"

#ifndef MESINKATA_H
#define MESINKATA_H

#define BLANK ' '
#define NMax 50

typedef struct { 
	char TabKata[NMax-1];
	int Length;  
} Kata; 

extern Kata CKata;
extern bool EndKata;

void Ignore_Blank();

void STARTKATA();

void ADVKATA();

void SalinKata();

float PanjangRataRata();

int KataBiasa();
int KataPanjang();


#endif
