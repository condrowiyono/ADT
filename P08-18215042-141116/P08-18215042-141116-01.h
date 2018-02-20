/*Nama/NIM                   : Condro Wiyono	*/
/*Tanggal                    : 14 November 2016*/
/*Topik                      : ADT ListBrg*/
/*Deskripsi                  : Ini adalah file haeder dari ADT ListBrg*/

typedef int bool; 
#define true 1 
#define false 0

#ifndef ListBrg_H
#define ListBrg_H

#define Nil NULL
#define infoBrg(P) (P)->infoBrg
#define nextBrg(P) (P)->nextBrg
#define First(L) ((L).First)

typedef struct{ 
	char Tipe[100]; //tipe barang (Pokeball/Potion)
	char Nama[100]; //nama barang
	int Efek; //efek penggunaan barang
	int Jumlah;
} Barang;

typedef Barang infotype;
typedef struct tElmtListBrg *addressBrg;
typedef struct tElmtListBrg { 
	infotype infoBrg;
	addressBrg nextBrg;
} ElmtListBrg;

/* Definisi ListBrg : */
/* ListBrg kosong : First(L) = Nil */
/* Setiap elemen dengan addressBrg P dapat diacu infotype(P), nextBrg(P) */
/* Elemen terakhir ListBrg : jika addressBrgnya Last, maka nextBrg(Last)=Nil */

typedef struct { 
	addressBrg First;
 } ListBrg;
 

bool IsListBrgEmptyB (ListBrg L );
void CreateListBrg (ListBrg *L);

addressBrg Alokasi (infotype X);
void Dealokasi(addressBrg *P);

addressBrg Search(ListBrg L, char X[]);
bool FSearch( ListBrg L, addressBrg P);

void InsertFirstB(ListBrg *L, addressBrg P);
void InsertAfterB(ListBrg *L, addressBrg P, addressBrg Prec);
void InsertLastB(ListBrg *L, addressBrg P);
void AddAlfabetis (ListBrg *L ,addressBrg P);
/* I.S. Sembarang, P sudah dialokasi }
   F.S. P dimasukkan ke dalam list sesuai alfabetis nama barang.
		  List mungkin kosong
*/

void DeleteFirst(ListBrg *L, addressBrg *P);
void DeleteBrg(ListBrg *L, char X[]);
void DeleteLast(ListBrg *L, addressBrg *P);
void DeleteAfter(ListBrg *L, addressBrg *Pdel, addressBrg Prec);

void PrintinfoB(ListBrg L);

#endif
