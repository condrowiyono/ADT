/* TUGAS BESAR IF2111 - Algoritma dan Struktur Data 
Pokemoon
---------------------------------------------------------------
Nomor Kelompok 	: 09
Nama File : load_09.h
Deskripsi : Mendeklarasikan semua tipe data yang digunakan
---------------------------------------------------------------
*/

#include "mesinkata_09.h"
#include "boolean_09.h"
#include "boolean_09.h"
#include "load_09.h"
#include <stdio.h>
#include <string.h>

void simpanPemain(Pemain P) {
FILE *file;

	if((file = fopen("load_pemain.txt", "w+")) == NULL){ //buka file
       printf("File Tidak Ditemukan\n");
    } else {
		/* tulis data ke file */
		fprintf(file, "%s\n", P.nama);    
		fprintf(file, "%d\n", P.exp);
		fprintf(file, "%d\n", P.uang);
		fprintf(file, "%d\n", P.level);
		fprintf(file, "%d\n", P.Posisi.X);
		fprintf(file, "%d\n", P.Posisi.Y);
		fprintf(file, ".");   
   
		fclose(file); //tutup file
    }
	
}
void simpanPokemon(Stack P){
FILE *file;
int i;
	if((file = fopen("load_pokemon.txt", "w+")) == NULL){ //buka file
       printf("File Tidak Ditemukan\n");
    } else {
        for (i=1;i<=P.TOP;i++)
        {  
           /* tulis data ke file */
           fprintf(file, "%s\n", P.T[i].nama_pokemon);    
           fprintf(file, "%s\n", P.T[i].tipe_pokemon);
           fprintf(file, "%d\n", P.T[i].hp);
		   fprintf(file, "%d-%d\n", P.T[i].attack.X,P.T[i].attack.Y);
		   fprintf(file, "%d-%d\n", P.T[i].exp.X,P.T[i].exp.Y);
		   fprintf(file, "%d-%d\n", P.T[i].money.X,P.T[i].money.Y);
		   fprintf(file, "%d\n", P.T[i].catchrate);
           fprintf(file, "\n");   
		}
		fprintf(file, ".");   
       
       fclose(file); //tutup file
    }
	
}

void simpanBag(List B) {
FILE *file;
int i;
	addressList P;
	P = First(B); 
	
	if((file = fopen("load_bag.txt", "w+")) == NULL){ //buka file
       printf("File Tidak Ditemukan.\n");
    } else {
        while (P != NilList)
        {  
           /* tulis data ke file */
           fprintf(file, "%s\n", Info(P).nama_barang);    
           fprintf(file, "%s\n", Info(P).tipe_barang);
           fprintf(file, "%d\n", Info(P).harga);
           fprintf(file, "%d\n", Info(P).efek);
           fprintf(file, "\n");   
		   P  = Next(P);
		}
		fprintf(file, ".");   
       
       fclose(file); //tutup file
    }	
}
void simpanSemua(Pemain P, Stack S, List L) {
	simpanPemain(P);
	simpanPokemon(S);
	simpanBag(L);
}