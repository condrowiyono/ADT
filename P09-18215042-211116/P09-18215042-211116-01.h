/*Nama/NIM                   : Condro Wiyono	*/
/*Tanggal                    : 30 Oktober 2016*/
/*Topik                      : ADT STACK LIST*/
/*Deskripsi                  : STACK LIST */

#ifndef _STACKLIST_H
#define _STACKLIST_H

#include "boolean.h"
#include <stdlib.h>

/* Konstanta */
#define Nil NULL

/* Deklarasi infotype */
typedef char infotype;

/* Stack dengan representasi berkait dengan pointer */
/*	Deklarasi Tipe */

typedef struct tElmtStack * address;
typedef struct tElmtStack {
	infotype *Info;
	address Next;
} ElmtStack;
typedef struct {
	address TOP;
} Stack;

/*	Selektor */
#define TOP(S) (S).TOP
#define InfoTop(S) (S).TOP->Info
#define Next(P) (P)->Next
#define Info(P) (P)->Info

void CreateEmpty (Stack * S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang */
/* Ciri stack kosong : TOP bernilai Nil */

/* Manajemen memori */
void Alokasi (address *P, infotype *X);
/* I.S. P Sembarang, X terdefinisi */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P) = X dan Next(P) = Nil */
/* P = Nil jika alokasi gagal */

void Dealokasi (address *P);
/* I.S. P adalah hasil alokasi, P <> Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */


bool IsEmpty (Stack S);
/*
 * Mengirim true jika Stack kosong: TOP(S) = Nil
 */

void Push (Stack * S, infotype X) ;
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru, jika alokasi elemen baru berhasil. */
/* Jika alokasi gagal, S tetap. */
void Pop (Stack * S, infotype * X);
/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, elemen top yang lama didealokasi, */
/* TOP(S) = Next(TOP(S)). */

void Cetak (Stack  S);

//PRAKTIKUM 9
//Bernilai true ketika str adalah begin
bool IsBegin(char *str);
//Bernilai true ketika str adalah end
bool IsEnd(char *str);
//Bernilai true ketika str adalah "("
bool IsKurungBuka(char*str);
//Bernilai true ketika str adalah ")"
bool IsKurungTutup(char *str);
//Bernilai true ketika str adalah "{"
bool IsKurawalBuka(char *str);
//Bernilai true ketika str adalah "}"
bool IsKurawalTutup(char *str);
//Bernilai true ketika str adalah if
bool IsIf(char *str);
//Bernilai true ketika str adalah then
bool IsThen(char *str);

#endif
