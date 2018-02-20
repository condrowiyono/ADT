/*
{Nama/NIM                  : Condro Wiyono	}
{Tanggal                    : 3 Oktober 2016}
{Topik                      : Abstract Data Type ARRAY KONTIGU}
{Deskripsi                  : Ini adalah file driver dari Abstract Data Type Array Kontigu}
*/



#include <stdio.h>
#include "P03-18215042-031016-01.h"


//KAUS GLOBAL
TabInt T;

//FUNGSI DAN PROSEDUR
void tulismenu() {
	printf("*****MENU UTAMA*****\n");
	printf("1. Tulis Tabel \n");
	printf("2. Nilai Ekstrem Tabel \n");
	printf("3. Search Tabel \n");
	printf("4. Add to Last Element \n");
        printf("5. Add to Element X \n");
        printf("6. Delete Last Element \n");
        printf("7. Delete Element X \n");
	printf("8. Keluar \n");

}

void satu(){
	
        TulisIsi(T);
        
}

void dua(){
        printf("===NILAI EKSTREM TABEL===\n");
        printf("Nilai elemen maksimum tabel : %d \n", ValMax(T));
        printf("Indeks elemen dengan nilai maksimum : %d \n", IdxMaxTab(T));
        printf("Nilai elemen minimum tabel : %d \n", ValMin(T));
        printf("Indeks elemen dengan nilai minimum : %d \n", IdxMinTab(T));
}

void tiga() {
        ElType X;
        
	printf("===SEARCH TABEL===\n");
        printf("Masukkan nilai yang ingin dicari : ");
        scanf("%d ",&X);
        
        if (SearchTab(T,X)==-999)  {
        printf("Nilai tersebut tidak ada pada tabel!\n"); }
        else { printf("%d",SearchTab(T,X));}
	 
}

void empat() {
	ElType V;
        
        
        printf("===ADD TO LAST ELEMENT=== \n");
        printf("Masukkan nilai elemen yang ingin ditambahkan : "); 
        scanf("%d",&V);
        
        AddAsLastEl(T,&T,V);
        
        printf("Penambahan elemen berhasil!\n");
        printf("*TABEL BARU* \n");
        TulisIsi(T);
}
void lima() {
        ElType V;
        IdxType i;
	printf("===ADD TO ELEMENT X===");
        printf("Masukkan indeks elemen yang ingin ditambahkan : ");
        scanf("%d",&V);
        
        printf("Masukkan nilai elemen yang ingin ditambahkan : ");
        scanf("%d",&i);
        AddEli(T, &T,V,i);
        
        printf("Penambahan elemen berhasil!\n");
        printf("*TABEL BARU* \n");
        TulisIsi(T);
}
void enam() {
	
}
void tujuh() {
	
}

int main (){
	
	//KAMUS LOKAL
	int I;
	
		
	//ALGORITMA
	printf("=== ADT TABEL KONTIGU === \n");		
	MakeEmpty(&T);
	
	BacaIsi(&T);

	
	do {
		tulismenu();
		printf("Pilihan anda = "); scanf("%d",&I);
		
		if (I==1) {
			satu();
		} else if (I==2) {
			dua();
		} else if (I==3) {
			tiga();
		} else if (I==4) {
			empat();
		} else if (I==8) {
			printf("Selamat tinggal ! \n");
			break;
		} else { 
			printf("Masukan anda salah. Silakan periksa kembali! \n"); 
			break;
		}
		
	} while (I!=8);
	
	return 0;
}
