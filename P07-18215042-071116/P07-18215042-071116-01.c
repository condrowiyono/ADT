/*Nama/NIM                   : Condro Wiyono	*/
/*Tanggal                    : 11 November 2016*/
/*Topik                      : ADT QUEUE*/
/*Deskripsi                  : Ini adalah file haeder dari ADT QUEUE*/

#include "P07-18215042-071116-01.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#ifndef QUEUE_C
#define QUEUE_C


bool IsEmpty (Queue Q) {
	/* Mengirim true jika Q kosong */
	return ( (HEAD(Q)==Nil&&TAIL(Q)==Nil ));
}

bool IsFull(Queue Q){
	/* Mengirim true jika tabel penampung elemen Q sudah penuh 
	 * yaitu mengandungMaxEl elemen */
	return ( (HEAD(Q)==1 && TAIL(Q)==MaxEl(Q)) );
}
int NBElmt(Queue Q){
	/* { Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
	if (IsEmpty(Q))
		return 0 ;
	else
		return MaxEl(Q);
}
void CreateEmpty(Queue *Q, int Max){
/* I.S. Max terdefinisi */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb : */
/* Jika alokasi berhasil, tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg Maksimum elemen=0 */
/* Proses : Melakukan alokasi memori dan membuat sebuah Q kosong */ 
	
	//ALGORITMA
	
	(*Q).T = (infotype *)malloc((Max+1)*sizeof(infotype *));
	//mengalokasikan memori untuk q.t sebanyak max+1
	
	if ((*Q).T != NULL) //jika berhasil
	{
		MaxEl(*Q) = Max;
		HEAD(*Q) = Nil;
		TAIL(*Q) = Nil;
	} else //jika gagal
	{
		MaxEl(*Q) = Nil;
	}
	
}
void DeAlokasi(Queue *Q){
/* Proses : Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
	
	//ALGORITMA
	free((*Q).T); //membuat dealokasi dari memori yang pernah disimpan
	MaxEl(*Q) = Nil; //MaxElm dibuat nil, atau dikembalikan
}

void Add(Queue *Q, infotype X){
/* Proses : Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" */

	//ALGORITMA
	if (IsEmpty(*Q)) //kalo masih kosong 
	{
		HEAD(*Q)=1;
		TAIL(*Q)=1;
		InfoTail(*Q) = X;
		//di isikan di tail X-nya ( yang juga akan diisikan di HEad)
	} else
	{
		if (IsFull(*Q))
		{
			printf("Antrian Sudah Penuh! \n");
		} else //lalkukan disini
		{
			TAIL(*Q)++; //tail di increament
			InfoTail(*Q)=X; //infotail diisi dengan X
		}
	}
}
void Del(Queue *Q, infotype *X){
/* Proses: Menghapus elemen pertama pada Q dengan aturan FIFO */
/* I.S. Q tidak kosong */
/* F.S. X = nilai elemen HEAD pada I.S.,
	Jika Queue masih isi : HEAD diset tetap = 1, elemen-elemen setelah
	HEAD yang lama digeser ke "kiri", TAIL = TAIL – 1;
	Jika Queue menjadi kosong, HEAD = TAIL = Nil. */
	
	//KAMUS
	int i;
	
	//ALGORITMA
	if (IsEmpty(*Q)) {
		printf("Antrian Kosong \n");
	} else
	{
		(*X) = InfoHead(*Q);
		TAIL(*Q)--;
		if (TAIL(*Q)==0) //jika menjadi kosong
		{
			HEAD(*Q) = Nil;
		} else //kalo masih berisi lebih dari nil
		{
			for(i=1;i<=TAIL(*Q);i++)
			{
				(*Q).T[i]=(*Q).T[i+1];
			}
		}
	}
	
}
void CetakElmt(Queue Q) {
//Mencetak Elemen

//KAMUS
int i;

//ALGORITMA
if (IsEmpty(Q)) {
	printf("Antrian Kosong \n");
} else
{
	for (i=1;i<=TAIL(Q);i++) {
		printf("%d ",Q.T[i].Nama );
		printf("%d ",Q.T[i].Skor );
	}
	printf(" \n");
}
}
//PRAKTIKUM 7

int IdxEff(Queue Q){
/* mengembalikan nilai indeks 
 * efektif tabel / jumlah elemen yang ada } */
	return (HEAD(Q) + TAIL(Q) - 1);
}

bool IsGameOver(Queue Q){
/* mengembalikan true apabila kondisi permainan 
 * berakhir terpenuhi, yaitu  
 * salah satu pemain mendapatkan skor 
 * sebesar 3 atau hanya tinggal
 * satupemain yang bermain */
//KAMUS
int i;
bool ketemu;
//SATU ORANG PEMAIN
	ketemu = false;
	i = 1;
	if (TAIL(Q)==0) {
		ketemu = true ;
	} else //jika enggak
	{
	while (!ketemu) {
		if (Q.T[i].Skor >= 3) {
			ketemu = true;
		}
		i++;
	}
	}
}

void CreateQueuePemain(Queue *Q, int Maks){
/*I.S : Queue kosong dengan alokasi Min 2 dan Maks 6 
 * { F.S : Menghasilkan Q yang berisi informasi seluruh 
 * pemain berupa nama dengan skor awal = 0
*/

//Asumi maks nya sudah benar

//KAMUS
int i,j,l;
char namaa[50];
int skor;
Pemain P;
Queue F;
//ALGORITMA
	CreateEmpty(&F,Maks);
	skor = 0;
	
	for(i=1;i<=Maks;i++) {
		printf("Nama Pemain %d :", i );
		scanf("%s", namaa);
		l = strlen(namaa);
		for (j = 0;j<l+1; ++j)
			P.Nama[i] = namaa[i];
		P.Skor = 0;
		Add(&F,P);
	} 


}
 
void ChangeTurn(Queue *Q){
/* I.S : Queue berisi minimal 2 elemen } 
 * F.S : Head(Q) diganti menjadi pemain yang berada di antrian selanjutnya } 
		Sedangkan untuk Head(Q) di awal dipindah ke antrian paling
		belakang / Tail(Q) } */
//KAMUS
Pemain X ; //mengampung nilai dari elemen terdelet
Queue F;
//ALGO
	Del(&F,&X);
	Add(&F,X);
}
void PrintSkor(Queue Q){
int i;

for (i=1;i<=IdxEff(Q);i++) {
	printf("%s", Q.T[i].Nama);
	printf(":");
	printf("%d", Q.T[i].Skor);
	printf(" ");
	}


}
#endif

