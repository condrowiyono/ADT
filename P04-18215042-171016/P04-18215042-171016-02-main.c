/*
/*Nama/NIM                  : Condro Wiyono	*/
/*Tanggal                    : 17 Oktober 2016*/
/*Topik                      : ADT MATRIKS*/
/*Deskripsi                  : Ini adalah file MAIN / DRIVER dari ADT Matriks*/


#include <stdio.h>
#include "P04-18215042-171016-01.h"


//KAMUS GLOBAL
MATRIKS M1,M2;

//FUNGSI DAN PROSEDUR
void tulismenu() {
	printf("\n");
	printf("*****MENU Matriks*****\n");
	printf("1. Pengecekan Jenis Matriks \n");
	printf("2. Perhitungan Determinan Matriks 1 dan Matriks 2 \n");
	printf("3. Ganti Elemen Matriks \n");
	printf("4. Hasil Transpose Matriks 1 dan Matriks 2 \n");
	printf("5. Penjumlahan Matriks \n");
	printf("6. Pengurangan Matriks \n");
	printf("7. Keluar \n");
}

void satu(){
	printf("=== Pengecekan Jenis Matriks === \n");
	printf("Matriks 1 : \n");
	if (IsBujurSangkar(M1)) {
		printf("-merupakan matriks bujur sangkar \n");
	} else
		printf("-bukan merupakan matriks bujur sangkar \n");
	if (IsSymetri(M1)){
		printf("-merupakan matriks simetri \n");
	} else {
		printf("-bukan merupakan matriks simetri \n");
	}
		
	printf("Matriks 2 : \n");
	if (IsBujurSangkar(M2)) {
		printf("-merupakan matriks bujur sangkar \n");
	} else
		printf("-bukan merupakan matriks bujur sangkar \n");
	if (IsSymetri(M2)){
		printf("-merupakan matriks simetri \n");
	} else {
		printf("-bukan merupakan matriks simetri \n");
	}
}


void dua() {
	
	//ALGORITMA
	printf("=== Determinan Matriks ===  \n");
	printf("Determinan Matriks 1 =  ");
	if (Determinan(M1)==-999) {
		printf("tidak dapat dihitung \n");
	} else {
		printf("%f",Determinan(M1));
	}
	printf("\n");
	printf("Determinan Matriks 2 =  ");
	if (Determinan(M2)==-999) {
		printf("tidak dapat dihitung \n");
	} else {
		printf("%f",Determinan(M2));
	}
}
void tiga(){
	//KAMUS
	int i;
	int Ba,Ko;
	el_type X;
	
	//ALGORITMA
	printf("=== Ganti Elemen Matriks ===\n");
	printf("Ganti Elemen Matriks ke- :");
	scanf("%d",&i);
	if (i==1) {
		printf("Baris elemen yang ingin diganti :");
		scanf("%d",&Ba);
		printf("Kolom elemen yang ingin diganti :");
		scanf("%d",&Ko);
		printf("Isi matriks ke-(%d,%d) : ",Ba,Ko);
		scanf("%d",&X);
		SetEl(&M1,Ba,Ko,X);
		printf("Matriks yang baru \n");
		TulisMATRIKS(M1);
	} else if (i==2) {
		printf("Baris elemen yang ingin diganti :");
		scanf("%d",&Ba);
		printf("Kolom elemen yang ingin diganti :");
		scanf("%d",&Ko);
		printf("Isi matriks ke-(%d,%d) : ",Ba,Ko);
		scanf("%d",&X);
		SetEl(&M2,Ba,Ko,X);
		printf("Matriks yang baru \n");
		TulisMATRIKS(M2);
	}
}

void empat() {
	MATRIKS M1T, M2T;
	
	printf("== Transpose Matriks === \n"); 
	printf("Transpose Matriks 1 : \n");
	Transpose(M1,&M1T);
	TulisMATRIKS(M1T);
	printf("Transpose Matriks 2 : \n");
	Transpose(M2,&M2T);
	TulisMATRIKS(M2T);
}

void lima() {
	MATRIKS M3; 
	
	printf("=== Penjumlahan Matriks === \n");
	M3 = tambah(M1,M2);
	if (GetElmt(M3,1,1)==-999) {
		printf("Matriks 1 tidak dapat dijumlahkan dengan Matriks 2 \n");
	} else {
		printf("Hasil Penjumlahan \n");
		TulisMATRIKS(M3);
	}
}
void enam() {
	MATRIKS M3; 
	
	printf("=== Pengurangan Matriks === \n");
	M3 = kurang(M1,M2);
	if (GetElmt(M3,1,1)==-999) {
		printf("Matriks 1 tidak dapat dikurangi dengan Matriks 2 \n");
	} else {
		printf("Hasil Penjumlahan \n");
		TulisMATRIKS(M3);
	}
}

int main (){
	
	//KAMUS LOKAL
	int I;
	int Ba,Ko ;
		
	//ALGORITMA
			
	
	printf("=== ADT MATRIKS === \n");
	printf("--- Matriks 1 ---\n");
	printf("Ukuran baris : "); 
	scanf("%d",&Ba);
	printf("Ukuran kolom : ");
	scanf("%d",&Ko);
	BacaMATRIKS(&M1,Ba,Ko);
	
	printf("\n");
	printf("--- Matriks 2 ---\n");
	printf("Ukuran baris : "); 
	scanf("%d",&Ba);
	printf("Ukuran kolom : ");
	scanf("%d",&Ko);
	BacaMATRIKS(&M2,Ba,Ko);
	

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
		} else if (I==5) {
			lima();
		} else if (I==6) {
			enam();
		} else if (I==7) {
			printf("===Terima kasih === \n");
			break;
		} else { 
			printf("Pilihan tidak sesuai. Ulangi! \n"); 
		}
		
	} while (I!=7);
	
	return 0;
}
