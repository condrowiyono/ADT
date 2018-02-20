/* TUGAS BESAR IF2111 - Algoritma dan Struktur Data 
Pokemoon
---------------------------------------------------------------
Nomor Kelompok 	: 09
Nama File : listdp_09.c
Deskripsi : Bag List Double Pointer
---------------------------------------------------------------
*/

#include "boolean_09.h"
#include "listdp_09.h"
#include "helper_09.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool IsEmptyList (List L) {
	return First(L) == NilList && Last(L) == NilList;
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList (List *L) {
	First(*L) = NilList;
	Last(*L) = NilList;
}
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
addressList Alokasi (infotypeList X) {
	addressList hasil = (addressList) malloc(sizeof(ElmtList));
	if (hasil != NilList) {
		Info(hasil) = X;
		Next(hasil) = NilList;
		Prev(hasil) = NilList;
	}
	return hasil;
}
/* Mengirimkan addressList hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressList tidak NilList. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=NilList, Prev(P)=NilList */
/* Jika alokasi gagal, mengirimkan NilList. */
void Dealokasi (addressList P) {
	free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressList P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressList Search (List L, infotypeList X) {
	addressList i = First(L);
	addressList found = NilList;
	while (found == NilList && i != NilList) {
		if (strcmp(Info(i).nama_barang, X.nama_barang)==0)
			found = i;
		i = Next(i);
	}
	return found;
}
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan addressList elemen tersebut. */
/* Jika tidak ada, mengirimkan NilList */

/****************** PRIMITIF BERDASARKAN NilListAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotypeList X) {
	addressList p = Alokasi(X);
	if (p != NilList) {
		Next(p) = First(*L);
		if (First(*L) != NilList)
			Prev(First(*L)) = p;
		First(*L) = p;
		if (Last(*L) == NilList)
			Last(*L) = p;
	}
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan NilListai X jika alokasi berhasil */
void InsVLast (List *L, infotypeList X) {
	addressList p = Alokasi(X);
	if (p != NilList) {
		Prev(p) = Last(*L);
		if (Last(*L) != NilList)
			Next(Last(*L)) = p;
		Last(*L) = p;
		if (First(*L) == NilList)
			First(*L) = p;
	}
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* berNilListai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotypeList *X) {
	*X = Info(First(*L));
	addressList tmp = First(*L);
	First(*L) = Next(tmp);
	if (First(*L) != NilList)
		Prev(First(*L)) = NilList;
	else
		Last(*L) = NilList;
	Dealokasi(tmp);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: NilListai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotypeList *X) {
	*X = Info(Last(*L));
	addressList tmp = Last(*L);
	Last(*L) = Prev(tmp);
	if (Last(*L) != NilList)
		Next(Last(*L)) = NilList;
	else
		First(*L) = NilList;
	Dealokasi(tmp);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: NilListai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, addressList P) {
	Next(P) = First(*L);
	if (First(*L) != NilList)
		Prev(First(*L)) = P;
	else {
		Last(*L) = P;
		Next(Last(*L)) = NilList;
	}
	First(*L) = P;
	Prev(First(*L)) = NilList;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressList P sebagai elemen pertama */
void InsertLast (List *L, addressList P) {
	Prev(P) = Last(*L);
	if (Last(*L) != NilList)
		Next(Last(*L)) = P;
	else {
		First(*L) = P;
		Prev(First(*L)) = NilList;
	}
	Last(*L) = P;
	Next(Last(*L)) = NilList;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter (List *L, addressList P, addressList Prec) {
	Prev(P) = Prec;
	Next(P) = Next(Prec);
	Next(Prec) = P;
	if (Next(P) != NilList)
		Prev(Next(P)) = P;
	else {
		Last(*L) = P;
		Next(Last(*L)) = NilList;
	}
}
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBefore (List *L, addressList P, addressList Succ) {
	Next(P) = Succ;
	Prev(P) = Prev(Succ);
	Prev(Succ) = P;
	if (Prev(P) != NilList)
		Next(Prev(P)) = P;
	else {
		First(*L) = P;
		Prev(First(*L)) = NilList;
	}
}
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, addressList *P) {
	*P = First(*L);
	First(*L) = Next(First(*L));
	if (First(*L) == NilList)
		Last(*L) = NilList;
	else
		Prev(First(*L)) = NilList;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLast (List *L, addressList *P) {
	*P = Last(*L);
	Last(*L) = Prev(Last(*L));
	if (Last(*L) == NilList)
		First(*L) = NilList;
	else
		Next(Last(*L)) = NilList;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelP (List *L, infotypeList X) {
	addressList i = First(*L);
	bool terhapus;
	terhapus = false;
	
	while ((i != NilList) && (!terhapus)) {
		addressList tmp = Next(i);
		if (strcmp(Info(i).nama_barang,X.nama_barang)==0) {
			if (Prev(i) != NilList)
				Next(Prev(i)) = Next(i);
			else {
				First(*L) = Next(i);
				if (First(*L) != NilList)
					Prev(First(*L)) = NilList;
			}
			if (Next(i) != NilList)
				Prev(Next(i)) = Prev(i);
			else {
				Last(*L) = Prev(i);
				if (Last(*L) != NilList)
					Next(Last(*L)) = NilList;
			}
			Dealokasi(i);
			terhapus = true;
		}
		i = tmp;
	}
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressList P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelAfter (List *L, addressList *Pdel, addressList Prec) {
	*Pdel = Next(Prec);
	addressList hapus = Next(Prec);
	if (hapus != NilList) {
		if (Next(hapus) != NilList)
			Prev(Next(hapus)) = Prec;
		else {
			Last(*L) = Prec;
			Next(Last(*L)) = NilList;
		}
		Next(Prec) = Next(hapus);
	}
}
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelBefore (List *L, addressList *Pdel, addressList Succ) {
	*Pdel = Prev(Succ);
	addressList hapus = Prev(Succ);
	if (hapus != NilList) {
		if (Prev(hapus) != NilList)
			Next(Prev(hapus)) = Succ;
		else {
			First(*L) = Succ;
			Prev(First(*L)) = NilList;
		}
		Prev(Succ) = Prev(hapus);
	}
}
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L) {
	printf("[");
	addressList i = First(L);
	bool first = true;
	while (i != NilList) {
		if (!first)
			printf(",");
		printf("%d", Info(i));
		first = false;
		i = Next(i);
	}
	printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen berNilListai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void PrintBackward (List L) {
	printf("[");
	addressList i = Last(L);
	bool first = true;
	while (i != NilList) {
		if (!first)
			printf(",");
		printf("%d", Info(i));
		first = false;
		i = Prev(i);
	}
	printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen berNilListai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

addressList SearchPrec (List L, infotypeList X) {
	addressList i = First(L);
	addressList h = NilList;
	bool found = false;
	while (!found && i != NilList)
		if (strcmp((Info(i).nama_barang),(X.nama_barang))>= 0) {
			h = Prev(i);
			found = true;
		} else
			i = Next(i);
	return h;
}

void InsertUrut (List *L, infotypeList X) {
	if (IsEmptyList(*L))
		InsVLast(L, X);
	else {
		addressList prev = SearchPrec(*L,X);
		if (prev == NilList) {
			if (strcmp((Info(First(*L)).nama_barang),(X.nama_barang)) < 0)
				InsVLast(L, X);
			else
				InsVFirst(L, X);
		} else
			InsertAfter(L, Alokasi(X), prev);
	}
}
void TulisBag (List L) {
	addressList P;
	P=First(L);
	system("cls");
	while (P != NilList) {
		printf("Nama %s \n",Info(P).nama_barang);
		printf("Tipe %s \n",Info(P).tipe_barang);
		
		P  = Next(P);
	}
}
/*
int main() {
	List L;
	Barang B,C;
	addressList P;
	CreateEmptyList(&L);
	strcpy(B.nama_barang,"Barang A");
	strcpy(B.tipe_barang,"B");
	InsertUrut(&L,B);
	strcpy(B.nama_barang,"Barang X");
	strcpy(B.tipe_barang,"B");
	InsertUrut(&L,B);
	strcpy(B.nama_barang,"Barang B");
	strcpy(B.tipe_barang,"B");
	
	InsertUrut(&L,B);
	
	strcpy(C.nama_barang,"Barang B");
	DelP(&L,C);
	TulisBag(L);
}
*/
