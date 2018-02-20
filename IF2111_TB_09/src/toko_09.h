/* TUGAS BESAR IF2111 - Algoritma dan Struktur Data 
Pokemoon
---------------------------------------------------------------
Nomor Kelompok 	: 09
Nama File : toko_09.h
Deskripsi : Mendeklarasikan semua tipe data yang digunakan
---------------------------------------------------------------
*/

#ifndef TOKO_H
#define TOKO_H

//Tipe data baranf
typedef struct {
	char tipe_barang[100];
	char nama_barang[100];
	long harga;
	long efek;  	
}Barang; 

typedef struct {
	Barang L[101];
	int Nef;  	
}Toko; 


void TokoKosong(Toko *T);
void TambahBarang(Toko *T, Barang X);

Toko LoadBarang();
#endif