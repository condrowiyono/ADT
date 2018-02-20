/*Nama/NIM                   : Condro Wiyono	*/
/*Tanggal                    : 23 Oktober 2016*/
/*Topik                      : ADT MESINKAR*/
/*Deskripsi                  : Ini adalah file haeder dari ADT MESINKAR*/


typedef int bool; 
#define true 1 
#define false 0

#ifndef MESINKAR_H
#define MESINKAR_H
#define MARK '.'

extern char CC;

void START();
/*	{ I.S. : sembarang }
	{ F.S. : CC adalah karakter pertama pita }
	{ Jika CC==MARK, EOP menyala (true) }
	{ Jika CC!=MARK, EOP padam (false) } */

void ADV();
/*	{ I.S. : CC!=MARK }
	{ F.S. : CC adalah karakter berikutnya dari CC pada I.S. }
	{ Jika CC==MARK, EOP menyala (true) } */

bool EOP();
/*	{ true jika CC == MARK } */
#endif
