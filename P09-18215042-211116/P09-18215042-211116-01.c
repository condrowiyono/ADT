/*Nama/NIM                   : Condro Wiyono	*/
/*Tanggal                    : 30 Oktober 2016*/
/*Topik                      : ADT STACK LIST*/
/*Deskripsi                  : STACK LIST */


#include "P09-18215042-211116-01.h"
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang */
/* Ciri stack kosong : TOP bernilai Nil */
void CreateEmpty (Stack * S) {
	TOP(*S) = Nil;
}


/* -------ALOKASI MEMORI ----*/
/* I.S. P Sembarang, X terdefinisi */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P) = X dan Next(P) = Nil */
/* P = Nil jika alokasi gagal */
void Alokasi (address *P, infotype *X) {
	(*P) = (address) malloc (sizeof (ElmtStack));
	
	
	if ((*P) != Nil) {
		char string[256];
		strcpy(string,X);
		printf("%s",string);
		strcpy(Info(*P),string);
		//Info(*P) = string;
		Next(*P) = Nil;
	} else {printf("gagal");}
}


/* I.S. P adalah hasil alokasi, P <> Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
void Dealokasi (address *P) {
	free(*P);
}

/*
 * Mengirim true jika Stack kosong: TOP(S) = Nil
 */
bool IsEmpty (Stack S) {
	return TOP(S) == Nil;
}



/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru, jika alokasi elemen baru berhasil. */
/* Jika alokasi gagal, S tetap. */
void Push(Stack * S, infotype X) {
	/* Kamus Lokal */
	address P;
	/* Algoritma */
	Alokasi(&P,&X);
	if (P != Nil) {
		Next(P) = TOP(*S);
		TOP(*S) = P;
	}
}

/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, elemen top yang lama didealokasi, */
/* TOP(S) = Next(TOP(S)). */
void Pop (Stack * S, infotype * X) {
	address P;
	
	P = TOP(*S);
	char string[256];
	strcpy(string,Info(P));
	(*X) = *string;
	//(*X) = Info(P);
	TOP(*S) = Next(TOP(*S));
	Next(P) = Nil;
	Dealokasi(&P);
}

void Cetak (Stack  S) {
	address P;
	char *str;
	
	
	P = TOP(S);
	if (P == Nil) {
		printf("Stack kosong\n");
	} else {
		strcpy(str,Info(P));
		printf("%s",str);
		P = Next(P);
		while (P != Nil) {
			strcpy(str,Info(P));
			//printf("%s",str);
			printf(", %s",str);
			P = Next(P);
		}
		printf("\n");
	}
}

//PRAKTIKUM 9
//Bernilai true ketika str adalah begin
bool IsBegin(char *str){
	char string[256];
	strcpy(string,str);
	return ((strcmp(string,"begin")==0));
}

//Bernilai true ketika str adalah end
bool IsEnd(char *str){
	char string[256];
	strcpy(string,str);
	return ((strcmp(string,"end")==0));
}
//Bernilai true ketika str adalah "("
bool IsKurungBuka(char *str){
	char string[256];
	strcpy(string,str);
	return ((strcmp(string,"(")==0));
}

//Bernilai true ketika str adalah ")"
bool IsKurungTutup(char *str){
	char string[256];
	strcpy(string,str);
	return ((strcmp(string,")")==0));
}
//Bernilai true ketika str adalah "{"
bool IsKurawalBuka(char *str){
	char string[256];
	strcpy(string,str);
	return ((strcmp(string,"{")==0));
}
//Bernilai true ketika str adalah "}"
bool IsKurawalTutup(char *str) {
	char string[256];
	strcpy(string,str);
	return ((strcmp(string,"}")==0));
}
//Bernilai true ketika str adalah if
bool IsIf(char *str) {
	char string[256];
	strcpy(string,str);
	return ((strcmp(string,"if")==0));
}
//Bernilai true ketika str adalah then
bool IsThen(char *str) {
	char string[256];
	strcpy(string,str);
	return ((strcmp(string,"then")==0));
}

