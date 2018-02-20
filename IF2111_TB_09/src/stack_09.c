/* TUGAS BESAR IF2111 - Algoritma dan Struktur Data 
Pokemoon
---------------------------------------------------------------
Nomor Kelompok 	: 09
Nama File : stack_09.c
Deskripsi : Mendeklarasikan stack
---------------------------------------------------------------
*/

/*	Modul ADT STACK - Statis */
/*	Deklarasi stack yang diimplementasi dengan tabel kontigu alokasi statik 
	dan ukuran sama dengan TOP adalah alamat elemen puncak. */

/*	FILE INCLUDE */
#include "boolean_09.h"
#include "stack_09.h"
#include "mesinkata_09.h"
#include "helper_09.h"
#include <string.h>

/*	Definisi stack S kosong : S.TOP = Nil
	Elemen yang dipakai menyimpan nilai Stack T[1]..T[MaxEl]
	Jika S adalah Stack maka akses elemen :
	S.T[(S.TOP)] untuk mengakses elemen TOP
	S.TOP adalah alamat elemen TOP
	Definisi akses dengan Selektor : Isilah dengan selektor yang tepat */

/*	----- Prototype ----- */
/*	Konstruktor/Kreator */
void CreateEmptyStack (Stack *S) {
/*	I.S.	: Sembarang
	F.S.	: Membuat sebuah stack S yang kosong berkapasitas MaxEl dengan indeksnya 
			  antara 1..MaxEl
	Ciri stack kosong : TOP bernilai Nil */
	/*	Kamus */
	/*	Algoritma */
	(*S).TOP=Nil;
}

/*	----- Predikat Untuk test keadaan KOLEKSI ----- */
bool IsEmptyStack (Stack S) {
/*	Mengirim true jika Stack kosong: lihat definisi di atas */
	/*	Kamus */
	/*	Algoritma */
	return (S.TOP==Nil);
}
bool IsFullStack (Stack S) {
/*	Mengirim true jika tabel penampung nilai elemen stack penuh */
	/*	Kamus */
	/*	Algoritma */
	return (S.TOP==MaxElStack);
}

/*	----- Operator Dasar Stack ----- */
void Push (Stack *S, infotype X) {
	/*	Menambahkan X sebagai elemen Stack S.
	I.S.	: S mungkin kosong, tabel penampung elemen stack TIDAK penuh
	F.S. 	: X menjadi TOP yang baru, TOP bertambah 1 */
	/*	Kamus */
	/*	Algoritma */
	if (!IsFullStack(*S)) {
		((*S).TOP)++;
		(*S).T[(*S).TOP]=X;
	}
}
void Pop (Stack *S, infotype *X) {
/*	Menghapus X dari Stack S.
	I.S. 	: S  tidak kosong
	F.S.	: X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
	/*	Kamus */
	/*	Algoritma */
	(*X) = (*S).T[(*S).TOP] ;
	((*S).TOP)--;
}


/*
Stack LoadPokememonPemain(){
	//KAMUS
	char kata[100]; 	//penyimpanan temporary dari kata
	char kata2[100]; 	//penyimpanan temporary dari kata
	Stack S;	
	extern char CC;
	extern Kata CKata;
	extern bool EndKata;
	int i;
	int j,k;
	Pokemon P;
	int pjg;
	
	CreateEmptyStack(&S);
	//ALGORITMA
	j = 1;
	k = 1;
	EndKata = false;
	//Dari Pokemon Awal 
	STARTKATA(5);
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
			case 0 : {P.catch = strtoint(kata);
					 Pop(&S,P);
					 j = 0;
					 break; }
		}
			
		ADVKATA();
		j++;
		
	}
	return S;
}
*/