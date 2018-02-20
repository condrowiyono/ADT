/*Nama/NIM                   : Condro Wiyono	*/
/*Tanggal                    : 31 Oktober 2016*/
/*Topik                      : ADT SETAK TAMBAHAN*/
/*Deskripsi                  : Ini adalah file haeder dari ADT STACK tambahan*/

#include "P06-18215042-311016-01.h"
#include <stdio.h>

#ifndef STACK_C
#define STACK_C

/*{ ********* Prototype ********* }
 * { *** Konstruktor/Kreator *** } */

void CreateEmpty (Stack *S){
/* { I.S. Sembarang }
 * { F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl }
 * { jadi indeksnya antara 1..MaxEl }
 * { Ciri stack kosong : TOP berNIlai NIl }
*/

	//ALGORITMA
	(*S).TOP = Nil;

}
/*{ ********* Predikat Untuk test keadaan KOLEKSI ********* } */

bool IsEmpty (Stack S){
/*	{ Mengirim true jika Stack kosong: lihat definisi di atas }
*/
	//ALGORITMA
	return (Top(S)==Nil);
}

bool IsFull (Stack S){
/* { Mengirim true jika tabel penampung NIlai elemen stack penuh }
*/ 
	//ALGORITMA
	return (Top(S)==MaxEl);
}

/*{ ********** Operator Dasar Stack ********* }*/
void Push (Stack *S, infotype X){
/*{ Menambahkan X sebagai elemen Stack S. }
 * { I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh }
 * { F.S. X menjadi TOP yang baru, TOP bertambah 1 }
*/
	//ALGORITMA
	(*S).TOP = Top(*S) + 1;
	InfoTop(*S) = X;
}
void Pop (Stack *S, infotype *X){
/*{ Menghapus X dari Stack S. }
 * { I.S. S tidak kosong }
 * { F.S. X adalah NIlai elemen TOP yang lama, TOP berkurang 1 }
*/
	//ALGORITMA
	(*X) = InfoTop(*S);
	(*S).TOP = (*S).TOP - 1;
}

bool EndToken(char CT){
//true jika proses akuisisi mendapat hasil sebuah karakter 
//yang merupakan  akhir dari ekspresi
	return (CT=='=');
}

bool IsOperator(char CT) {
//true jika CT adalah operator 
	return ((CT=='+') || (CT=='-') || (CT=='/') || (CT=='*') || (CT=='^'));
	
}
infotype Hitung (infotype OP1, infotype OP2, char Operator) {
//menghitung ekspresi, mengkonversi hasil menjadi token
	
	//KAMUS
	infotype X;
	
	if (Operator=='+') 
		X = OP1 + OP2 ;
	else if (Operator=='-')
		X = OP1 - OP2;
	else if (Operator=='*')
		X = OP1 * OP2;
	else if (Operator=='/')
		X = OP1 / OP2;
	else if (Operator=='^')
		X = OP1 ^ OP2 ;
	
	return X;
}
#endif

