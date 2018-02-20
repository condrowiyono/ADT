/*Nama/NIM                   : Condro Wiyono	*/
/*Tanggal                    : 28 11 2016*/
/*Topik                      : ADT STACK LIST*/
/*Deskripsi                  : PrioQueue LIST */


#ifndef _PRIOPrioQueue_H
#define _PRIOPrioQueue_H
#include "boolean.h"
#include <stdlib.h>

/* Konstanta */
#define Nil NULL

/* Deklarasi infotype */
typedef struct {
	int id;          /* id siswa */
	int tKedatangan; /* waktu kedatangan */
	int dLayanan;    /* durasi/lama persiapan makanan untuk siswa */
} infotype;

/* PrioQueue dengan representasi berkait dengan pointer */
typedef struct tElmtPrioQueue * address;
typedef struct tElmtPrioQueue { 
	infotype Info;
	address Next; 
} ElmtPrioQueue; 

/* Type PrioQueue dengan ciri HEAD : */
typedef struct { 
	address HEAD; /* Alamat penghapusan */
	address TAIL; /* Alamat penambahan */
	int MaxEl;
} PrioQueue;

/*	----- Selektor ----- */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).HEAD->Info
#define Next(P) (P)->Next
#define Info(P) (P)->Info

/*{ *** Konstruktor *** } */
void CreateEmpty (PrioQueue * Q, int Max);
/*{ I.S. Max terdefinisi }
{ F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb : }
{ Jika alokasi berhasil, memori dialokasi berukuran Max }
{ atau : jika alokasi gagal, Q kosong dg Maksimum elemen=0 }
{ Proses : Melakukan alokasi memori dan membuat sebuah Q kosong }
*/

/* { *** Prototype manajemen memori *** } */
void Alokasi (address * P, infotype X);
/*{ I.S. P Sembarang, X terdefinisi }
{ F.S. Alamat P dialokasi, jika berhasil maka Info(P) = X dan Next(P) = Nil }
{ P = Nil jika alokasi gagal }*/

void Dealokasi (address * P);
/*{ I.S. P adalah hasil alokasi, P <> Nil }
{ F.S. Alamat P didealokasi, dikembalikan ke sistem }
{ *** Predikat Pemeriksaan Kondisi PrioQueue *** } */

bool IsEmpty (PrioQueue Q);
/*	Mengirim true jika Q kosong: HEAD(Q) = Nil and TAIL(Q) = Nil */

bool IsFull (PrioQueue Q);
/*{ Mengirim true jika PrioQueue sudah penuh yaitu mengandung MaxEl elemen } */

int NBElmt (PrioQueue Q);
/*{ Mengirimkan banyaknya elemen PrioQueue. Mengirimkan 0 jika Q kosong. }
{ *** Operator-Operator Dasar PrioQueue *** } */

void Add (PrioQueue * Q, infotype X);
/*{ Proses : Menambahkan X pada Q dengan aturan FIFO }
{ I.S. Q mungkin kosong }
{ F.S. X menjadi TAIL yang baru, TAIL "maju" } */

void Del (PrioQueue * Q, infotype * X);
/*{ Proses: Menghapus elemen pertama pada Q dengan aturan FIFO }
{ I.S. Q tidak kosong }
{ F.S. X = nilai elemen HEAD pada I.S.,
Jika PrioQueue masih isi : HEAD diset tetap = 1, elemen-elemen setelah HEAD yang
lama digeser ke "kiri", TAIL = TAIL – 1;
Jika PrioQueue menjadi kosong, HEAD = TAIL = Nil. }
*/
/*	---- Operasi Lain ----- */
void PrintPrioQueue (PrioQueue Q);


#endif
