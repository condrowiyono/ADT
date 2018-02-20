/*
{Nama/NIM                  : Condro Wiyono	}
{Tanggal                    : 19 September 2016}
{Topik                      : Abstract Data Type}
{Deskripsi                  : Ini adalah file driver dari Abstract Data Type Titik/Point}
*/


/* Driver Kotakan bro */


#include <stdio.h>
#include "P02-18215042-260916-02.h"

//KAMUS GLOBAL
JAM J;

//FUNGSI DAN PROSEDUR
void tulismenu() {
	printf("**********Program Jam**********\n");
	printf("1. Mengubah jam ke detik \n");
	printf("2. Membandingkan dengan jam lain \n");
	printf("3. Penambahan n detik \n");
	printf("4. Pengurangan n detik \n");
	printf("5. Hitung durasi dengan jam lain \n");
	printf("6. Keluar \n");

}

void satu(){
	printf("Hasil konversi jam ke detik adalah %d detik \n",jamToDetik(J));
}

void dua(){
	JAM J1;
	printf("----------------Membandingkan dengan jam lain ----------------- \n");
	printf("Masukkan komponen jam ke-2: \n");
	bacaJam(&J1);
	printf("Hasil perbandingan : \n");
	if (JEQ(J,J1)) {
		printf("Jam 1 sama dengan jam 2 \n");
	} else {
		printf("Jam 1 tidak sama dengan jam 2 \n");
		if (JLT(J,J1)) {
			printf("Jam 1 lebih kecil dari jam 2 \n");
		} else {
			printf("Jam 1 lebih besar dari jam 2 \n");
		}
	}
	
	
}

void tiga() {
	int detik;
	JAM J2;
	
	printf("---------------- Penambahan n detik ----------------- \n");
	printf("Masukan detik tambahan = "); scanf("%d",&detik);
	J2 = nextNDetik(J, detik);
	printf("Hasil penambahan = ");
	tulisJam(J2);
}

void empat() {
	int detik;
	JAM J2;
	
	printf("---------------- Penambahan n detik ----------------- \n");
	printf("Masukan detik pengurangan = "); scanf("%d",&detik);
	J2 = prevNDetik(J, detik);
	printf("Hasil pengurangan = ");
	tulisJam(J2);
}

void lima() {
	int selisih;
	JAM J1;
	JAM jamdurasi;
	
	printf("---------------- Hitung durasi dg jam lain ----------------- \n");
	printf("Masukkan komponen jam ke-2: \n");
	bacaJam(&J1);
	selisih = durasi(J,J1);
	jamdurasi = detikToJam(selisih);
	printf("Durasi = ");
	tulisJam(jamdurasi);
}


int main (){
	
	//KAMUS LOKAL
	int I;
	
		
	//ALGORITMA
	printf("Masukkan komponen jam : \n");
	bacaJam(&J);
	printf("Jam yang diinputkan adalah " );
	tulisJam(J);
	
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
			printf("Selamat tinggal !");
		} else { 
			printf("Masukan anda salah. Silakan periksa kembali! \n"); 
			break;
		}
		
	} while (I!=6);
	
	return 0;
}
