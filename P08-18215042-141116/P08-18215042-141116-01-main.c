/*Nama/NIM                   : Condro Wiyono	*/
/*Tanggal                    : 14 November 2016*/
/*Topik                      : ADT LIST*/
/*Deskripsi                  : Ini adalah file driver dari ADT LIST*/

#include "P08-18215042-141116-01.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//KAMUS GLOBAL

void tulismenu() {
/* Menulis menu */
	printf("**OPERASI BAGIAN PEMAIN**\n");
	printf("1. Beli Barang \n");
	printf("2. Gunakan Baran \n");
	printf("3. Lihat Isi Tas \n");
	printf("4. Tutup Tas ( Keluar ) \n");
}


int main() {
	//KAMUS
	int I;
	int max,j,x,y;
	addressBrg Q;
	ListBrg M;
	char konf;
	int tamb;
	Barang OP;
	char barangg[100];
	char tipee;
	int ef,jum;
	//printf("Inisialisasi List \n");
	//Alokasi dan Inisialisasi
	
	strcpy(OP.Tipe,"");
	strcpy(OP.Nama,"");
	OP.Efek = 100;
	OP.Jumlah =0;
	Q = AlokasiB(OP);
	
	CreateListBrg(&M);
	
	 
	do {
		printf("\n");
		tulismenu();
		printf("Pilihan Anda : "); scanf("%d",&I);
		
		if (I==1) {
			printf("----TAMBAH ELEMEN----\n");
			do {
				printf(" Nama Barang: ");
				scanf("%s",barangg);
				strcpy(OP.Tipe,barangg);
				printf(" Tipe barang Potin/Pokebol? (P/B): ");
				scanf(" %c",&tipee);
					if (tipee=='P') {
						strcpy(OP.Tipe,"Potion");
					} else if (tipee=='B') {
						strcpy(OP.Tipe,"Pokeball");
					}
				printf(" Efek: ");
				scanf("%d",&ef);
				printf(" Jumlah: ");
				scanf("%d",&jum);
				OP.Efek = ef;
				OP.Jumlah = jum;
				Dealokasi(&Q);
				Q = AlokasiB(OP);
				InsertFirstB(&M,Q);
				printf("Tambah Lagi? (Y/N) : ");
				scanf(" %c",&konf);
			} while (konf=='Y'); 
			
		} else if (I==2) {
			printf("----HAPUS ELEMEN----\n");
			if (IsListBrgEmptyB(M)) {
				printf("List masih kosong! Tambah ELemen terlebih dahulu.\n");
			} else {
				
			}
		} else if (I==3) {
			printf("==List= \n");
			PrintinfoB(M);
		} else if (I==4) {
			printf("==Terima Kasih== \n");
			exit(0);
		}
		else { 
	
		}
		
	} while (I!=4);
		
	return 0;
}

