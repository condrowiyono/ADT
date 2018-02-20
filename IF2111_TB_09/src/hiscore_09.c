/* TUGAS BESAR IF2111 - Algoritma dan Struktur Data 
Pokemoon
---------------------------------------------------------------
Nomor Kelompok 	: 09
Nama File : hiscore_09.c
Deskripsi : Mendeklarasikan semua tipe data yang digunakan
---------------------------------------------------------------
*/

#include "hiscore_09.h"
#include "mesinkata_09.h"
#include "boolean_09.h"
#include "helper_09.h"
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>



void tulisFileScoreboard(Scoreboard S){
FILE *file;
int i;

	if((file = fopen("hiscore.txt", "w+")) == NULL){ //buka file
       printf("File Tidak Ditemukan\n");
    } else {
        for(i=1; i<=S.Nef; i++)
        {  
           /* tulis data ke file */
           fprintf(file, "%s\n", S.S[i].nama);    
           fprintf(file, "%d\n", S.S[i].exp);
           fprintf(file, "%s\n", S.S[i].tanggal);
           fprintf(file, "\n", S.S[i].tanggal);   
		}
		fprintf(file, ".", S.S[i].tanggal);   
       
       fclose(file); //tutup file
    }
	  
}
void ScoreboardKosong(Scoreboard *S) {
	(*S).Nef = 0;
}
void TambahScoreboard(Scoreboard *S, Score Sc){
	int n = (*S).Nef;
	(*S).S[n+1] = Sc;
	(*S).Nef = (*S).Nef + 1; 	
	
	Sort(&(*S));
	
	if ((*S).Nef > 10) { 
		(*S).Nef = 10;
	} 
}

void Sort(Scoreboard *S){
	int n = (*S).Nef;
	int i,j;
	int k;
	Score tmp;

	for(i=1;i<=n;i++)
     {
           for(j=1;j<=n-i;j++)
           {
                 if (((*S).S[j].exp)  <= ((*S).S[j+1].exp))
                 {
                       tmp=(*S).S[j+1];
                       (*S).S[j+1]=(*S).S[j];
                       (*S).S[j]=tmp;
                 }
           }
     }
	 
}

Scoreboard LoadScoreboard(){
	//KAMUS
	char kata[100]; 	//penyimpanan temporary dari kata
	char kata2[100]; 	//penyimpanan temporary dari kata	
	extern char CC;
	extern Kata CKata;
	extern bool EndKata;
	int i;
	int j,k;
	int pjg;
	Scoreboard S;
	Score Sc; 
	
	ScoreboardKosong(&S);
	
	//ALGORITMA
	j = 1;
	k = 1;
	EndKata = false;
	//Dari Pokemon 
	STARTKATA(10);
	while (!EndKata) {
		for (i=1;i<=CKata.Length;i++) {
			//harus mulai index 0
			kata[i-1] = CKata.TabKata[i];
			pjg = CKata.Length;
		}
		
		//Menjadikannya string
		kata[pjg]='\0';
		
		//strcpy(kata2, kata);
		//printf("%s",kata);
		switch (j % 3) {
			case 1 : {strcpy(Sc.nama,kata);break;} 
			case 2 : {Sc.exp=strtoint(kata);break;}
			case 0 : {strcpy(Sc.tanggal,kata);
					 TambahScoreboard(&S,Sc);
					 j = 0;
					 break; }
		}	
		ADVKATA();
		j++;
		
	}

	return S;
}

void TampilScoreboard(Scoreboard S){
	
}

void tulisLayarScoreboard(Scoreboard S) {
	int i;
	
	system("cls");
	
	
	printf("|---------------------------------------------------------------------------|\n"); 
	printf("| HI-SCORE                                                                  |\n");
	printf("|---------------------------------------------------------------------------|\n");
	for (i=1;i<=S.Nef;i++) {
	printf("| %-3d %-20s   %-10d    %-20s             |\n",i,S.S[i].nama,S.S[i].exp,S.S[i].tanggal);
	}
	printf("|                                                                           |\n");
	printf("|                                                                           |\n");
	printf("|                                                                           |\n");
	printf("|                                                                           |\n");
	printf("|---------------------------------------------------------------------------|\n");
	printf("|                        PRESS ANY KEY TO EXIT                              |\n");
	printf("|---------------------------------------------------------------------------|\n");
	
}