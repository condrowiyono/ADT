/* TUGAS BESAR IF2111 - Algoritma dan Struktur Data 
Pokemoon
---------------------------------------------------------------
Nomor Kelompok 	: 09
Nama File : stack_09.h
Deskripsi : Mendeklarasikan stack
---------------------------------------------------------------
*/

#include "boolean_09.h"
#include "pokemon_09.h"

#ifndef stack_h
#define stack_h

/*	KONSTANTA */
#define Nil 0 /* Nil adalah stack dengan elemen kosong */
#define MaxElStack 50

/*	PENDEKLARASIAN TIPE */
typedef Pokemon infotype;
typedef int address; /* indeks tabel */
/*	Contoh deklarasi variabel bertype stack dengan ciri TOP :
	Versi I : dengan menyimpan tabel dan alamat top secara eksplisit */
typedef struct {
	infotype T[MaxElStack+1]; /* tabel penyimpan elemen */
	address TOP; /* alamat TOP : elemen puncak */
} Stack;


/*	----- Prototype ----- */
/*	Konstruktor/Kreator */
void CreateEmptyStack (Stack *S);
/*	I.S.	: Sembarang
	F.S.	: Membuat sebuah stack S yang kosong berkapasitas MaxElStack dengan indeksnya 
			  antara 1..MaxElStack
	Ciri stack kosong : TOP bernilai Nil */

/*	----- Predikat Untuk test keadaan KOLEKSI ----- */
bool IsEmptyStack (Stack S);
/*	Mengirim true jika Stack kosong: lihat definisi di atas */
bool IsFullStack (Stack S);
/*	Mengirim true jika tabel penampung nilai elemen stack penuh */

/*	----- Operator Dasar Stack ----- */
void Push (Stack *S, infotype X);
/*	Menambahkan X sebagai elemen Stack S.
	I.S.	: S mungkin kosong, tabel penampung elemen stack TIDAK penuh
	F.S. 	: X menjadi TOP yang baru, TOP bertambah 1 */
void Pop (Stack *S, infotype *X);
/*	Menghapus Stack S.
	I.S. 	: S  tidak kosong
	F.S.	: X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

//Stack LoadPokemonPemain();

#endif