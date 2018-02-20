/*Nama/NIM                   : Condro Wiyono	*/
/*Tanggal                    : 7 November 2016*/
/*Topik                      : ADT QUEUE*/
/*Deskripsi                  : Ini adalah file haeder dari ADT QUEUE*/

typedef int bool; 
#define true 1 
#define false 0

#ifndef QUEUE_H
#define QUEUE_H

typedef struct { 
	char Nama[50];  
	int Skor;
}Pemain;

typedef Pemain infotype ;
typedef int address; //indeks table0nya

#define Nil 0 // Nil adalah stack dengan elemen kosong

typedef struct { 
	infotype *T;  
	address HEAD;
	address TAIL;
	int MaxEl;
}Queue;

#define HEAD(Q) (Q).HEAD
#define TAIL(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q) (Q).MaxEl

bool IsEmpty (Queue Q);
bool IsFull(Queue Q);
int NBElmt(Queue Q);

void CreateEmpty(Queue *Q, int Max);
void DeAlokasi(Queue *Q);

void Add(Queue *Q, infotype X);
void Del(Queue *Q, infotype *X);

void CetakElmt(Queue Q);


//PRAKTIKUM 7

//MODUL TAMBAHAN


int IdxEff(Queue Q);
bool IsGameOver(Queue Q);
void CreateQueuePemain( Queue *Q, int Maks);
void ChangeTurn(Queue *Q);
void PrintSkor(Queue Q);


#endif
