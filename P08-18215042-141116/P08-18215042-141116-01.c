/*Nama/NIM                   : Condro Wiyono	*/
/*Tanggal                    : 14 November 2016*/
/*Topik                      : ADT ListBrg*/
/*Deskripsi                  : Ini adalah file haeder dari ADT ListBrg*/

#include "P08-18215042-141116-01.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef ListBrg_C
#define ListBrg_C

bool IsListBrgEmptyB (ListBrg L ) {
	//ALGORITMA
	if (L.First == Nil) {
		return true ;
	} else return false;
}

void CreateListBrg (ListBrg *L){
	//ALGORITMA
	(*L).First = Nil;
}

addressBrg AlokasiB (infotype X){
	//KAMUS
	addressBrg P;
	
	//ALGO
	P = (addressBrg) malloc (sizeof (ElmtListBrg));
	infoBrg(P) = X ;
	nextBrg(P) = Nil;
	
	return P;
}

void Dealokasi(addressBrg *P){
	//ALGO
	free(*P);
}

addressBrg SearchNama(ListBrg L, char X[] ){
	//KAMUS
	addressBrg P;
	bool found;
	addressBrg j;
	char infonya[100] ;
	
	//ALGORITMA
	P = First(L);
	
	
	strcpy(infonya, infoBrg(P).Nama );
	found = false;
	
	while ((P != Nil) && (!found)) {
		if (strcmp(X,infonya)==0) {
			found = true;
		} else {
			P = nextBrg(P);
		}
	} 
	if (found==true) {
		return P;
	} else {
		return Nil;
	}
}

bool FSearch( ListBrg L, addressBrg P){
	//KAMUS
	addressBrg Pt;
	bool found;
	
	//ALGO
	Pt = First(L);
	found = false;
	
	while ((Pt != Nil) && (!found)) {
		if ((P)==Pt) {
			found = true;
		} else {
			Pt= nextBrg(Pt);
		}
	} 
	if (found==true) {
		return true;
	} else {
		return false;
	}
}

void InsertFirstB(ListBrg *L, addressBrg P){
	//ALGORITMA
	nextBrg(P) = First(*L);
	First(*L) = P;
}

void InsertAfterB(ListBrg *L, addressBrg P, addressBrg Prec){
	//ALGORITMA
	nextBrg(P) = nextBrg(Prec);
	nextBrg(Prec) = P;
}

void AddAlfabetis (ListBrg *L ,addressBrg P) {
	//KAMUS
	//ALGORITMA
}

void InsertLastB(ListBrg *L, addressBrg P){
	//KAMUS
	addressBrg Last;
	
	//ALGORITMA
	if (IsListBrgEmptyB(*L)) {
		InsertFirstB(&(*L),P);
	} else {
		Last = First(*L);
		while (nextBrg(Last)!= Nil) {
			Last = nextBrg(Last);
		}
		InsertAfterB(&(*L),P,Last);
	}
}

void DeleteFirst(ListBrg *L, addressBrg *P){
	//ALGORITMA
	(*P) = First(*L);
	First(*L) = nextBrg(First(*L));
}

void DeleteBrg(ListBrg *L, char X[]){
	//KAMUS
	addressBrg Prec;
	addressBrg P,Q;
	addressBrg temp;
	
	//ALGORITMA
	char infonya[100] ;
	char infonya2[100] ;
	
	P = First(*L);
	
	strcpy(infonya, infoBrg(P).Nama );
	
	if(strcmp(X,infonya)==0) {
		DeleteFirst(&(*L),&Prec);
	} else {
		Prec = First(*L);
		Q = nextBrg(Prec);
		while (strcmp(X,infonya)!=0) {
			Prec = nextBrg(Prec);
		}
		DeleteAfter(&(*L),&temp,Prec);
	}
}

void DeleteLast(ListBrg *L, addressBrg *P){
	//KAMUS
	addressBrg Last,PrecLast;
	
	//ALGORITMA
	Last = First(*L);
	PrecLast = Nil;
	while (nextBrg(Last)!=Nil) {
		PrecLast = Last;
		Last = nextBrg(Last);
	} 
	(*P) = Last;
	if ( PrecLast == Nil) {
		First(*L) = Nil;
	} else {
		nextBrg(PrecLast) =Nil;
	}
	
}

void DeleteAfter(ListBrg *L, addressBrg *Pdel, addressBrg Prec){
	//ALGORITMA
	(*Pdel) = nextBrg(Prec);
	nextBrg(Prec) = nextBrg(nextBrg(Prec));
}

void PrintinfoB(ListBrg L){
	//KAMUS
	addressBrg temp;
	//ALGORITMA
	//printf("%Efek : d\n",infoBrg(temp).Efek);
	
	if (IsListBrgEmptyB(L)) {
		printf("ListBrg kosong \n");
	} else
	{
		temp = First(L);
		for(;;) {
		printf("Efek : %d \n",infoBrg(temp).Efek);
		printf("Nama : %s \n",infoBrg(temp).Nama);
		if (nextBrg(temp) == Nil)
		{
			break;
		}
		temp = nextBrg(temp);
	}
	}
}

#endif
