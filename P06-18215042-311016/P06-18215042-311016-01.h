/*Nama/NIM                   : Condro Wiyono	*/
/*Tanggal                    : 30 Oktober 2016*/
/*Topik                      : ADT SETAK TAMBAHAN*/
/*Deskripsi                  : Ini adalah file haeder dari ADT STACK tambahan*/

typedef int bool; 
#define true 1 
#define false 0

#ifndef STACK_H
#define STACK_H

typedef int infotype ;
typedef int address; //indeks table0nya

#define Nil 0 // Nil adalah stack dengan elemen kosong
#define MaxEl 10


typedef struct { 
	infotype T[MaxEl+1];  
	address TOP;
}Stack;

#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/*	{ Definisi stack S kosong : S.TOP = Nil }
 * { Elemen yang dipakai menyimpan nilai Stack T[1]..T[MaxEl] }
 * { Jika S adalah Stack maka akses elemen : }
 * { S.T[(S.TOP)] untuk mengakses elemen TOP }
 * { S.TOP adalah alamat elemen TOP }
 * { Definisi akses dengan Selektor : Isilah dengan selektor yang tepat }
*/

/*{ ********* Prototype ********* }
 * { *** Konstruktor/Kreator *** } */

void CreateEmpty (Stack *S);
/* { I.S. Sembarang }
 * { F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl }
 * { jadi indeksnya antara 1..MaxEl }
 * { Ciri stack kosong : TOP bernilai Nil }
*/

/*{ ********* Predikat Untuk test keadaan KOLEKSI ********* } */

bool IsEmpty (Stack S);
/*	{ Mengirim true jika Stack kosong: lihat definisi di atas }
*/
bool IsFull (Stack S);
/*{ Mengirim true jika tabel penampung nilai elemen stack penuh }
*/


/*{ ********** Operator Dasar Stack ********* }*/
void Push (Stack *S, infotype X);
/*{ Menambahkan X sebagai elemen Stack S. }
 * { I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh }
 * { F.S. X menjadi TOP yang baru, TOP bertambah 1 }
*/

void Pop (Stack *S, infotype *X);
/*{ Menghapus X dari Stack S. }
 * { I.S. S tidak kosong }
 * { F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 }
*/

bool EndToken(char CT);
//true jika proses akuisisi mendapat hasil sebuah karakter 
//yang merupakan  akhir dari ekspresi


bool IsOperator(char CT);
//true jika CT adalah operator 

infotype Hitung (infotype OP1, infotype OP2, char Operator);
//menghitung ekspresi, mengkonversi hasil menjadi token

#endif
