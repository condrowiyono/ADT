/* TUGAS BESAR IF2111 - Algoritma dan Struktur Data 
Pokemoon
---------------------------------------------------------------
Nomor Kelompok 	: 09
Nama File 		: main.c
Deskripsi		 : Main Program untuk Pokemoon.
---------------------------------------------------------------
*/

/*========================= INCLUDE =========================== */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <unistd.h>

#include "matrik_09.h"
#include "pokemon_09.h"
#include "boolean_09.h"
#include "pemain_09.h"
#include "point_09.h"
#include "queue_09.h"
#include "mesinkata_09.h"
#include "battle_09.h"
#include "helper_09.h"
#include "toko_09.h"
#include "naration_09.h"
#include "stack_09.h"
#include "listdp_09.h"
#include "hiscore_09.h"



/*======== VARIABLE GLOBAL YANG DIGUNAKAN SELAMA MAIN ======== */
//KELOMPOK MATRIK
MATRIKS M1;			//Matrik Untuk Peta1
MATRIKS M2;			//Matrik Untuk Peta2
MATRIKS M3;			//Matrik Untuk Peta3
MATRIKS M4;			//Matrik Untuk Peta4
int MapNo;			//Sedang Berada di peta mana
POINT Posi;
int sebelum = 176;

//KEMOPOK TOKO
Toko PokeToko;		//Load Data Dari Toko Pokemon

//Kelompok Pokemon
Queue P1; 			//Pokemon

//Kelompok Permainan
bool GameBaru;
Pemain Player;
List Bag;
DaftarPokemon DP1;
//BAG
List Bag;

//Kelompok Narasi;
DaftarNarasi NarasiIntro;
int IdxNarasiIntro = 1;


//Kelompok HIScore
Scoreboard S;

/*================== FUNGSI DAN PROSEDUR ===================== */
// Sebuah Prosedur yang digunakan untuk menulis menu ke layar
void tulismenu() {
	system("cls");

	printf("|---------------------------------------------------------------------------|\n"); 
	printf("|                                                                           |\n");
	printf("|                                                                           |\n");
	printf("|        ::.        #`                                                      |\n");
	printf("|      `@@@@@@@     ;@@.              TUBES ALSTRUKDAT                      |\n");
	printf("|       @@@@@@@     :@@:              THE SECRET FRIEND                     |\n");
	printf("|       @@@ `@:      @@+               .                 .                  |\n");
	printf("|       #@:@#   @@@: @@#     #@@:    @@@@@      @@ @;@@@:  @@@@@@@@@.       |\n");
	printf("|       @@#   @@`@@  @@@ #@@ @@@@    @@@@@@     @# @@@@`@ @+@;@+@@@@        |\n");
	printf("|       @@   @@.  @@ @@@@@  @@@ @@#+ @@ @@@@.  @@@ .@  `@ @.@@  @@@@        |\n");
	printf("|      '@`  @@@:@@@  @@@#  @@#@  @@: @@  @@@@@:@@@ @@  @@ @@@@  @@@@        |\n");
	printf("|       @@  @@@@@@   +@@@@ `@@@`@    @@   @:@@@ @@ @@  @@ @@@@  @@@+        |\n");
	printf("|       @@  `@@@@   ;@@,@@@ @@@@@@@' @@    @@#  @@ @@#@@@ @+@@  @@@@:       |\n");
	printf("|       ;    ':     :@@  @@, +:      .` ,.  ':   .+` `    ..                |\n");
	printf("|                   .@@   +                                                 |\n");
	printf("|                                                                           |\n");
	printf("|                                                                           |\n");
	printf("|----------------------|--------------|------------|------------------------|\n");
	printf("| MULAI : M            | PETUNJUK : H | TENTANG : A| KELUAR : X             |\n");
	printf("|----------------------|--------------|------------|------------------------|\n");
}

void petunjuk() {
	system("cls");

	printf("|---------------------------------------------------------------------------|\n"); 
	printf("|                                                                           |\n");
	printf("|                                                                           |\n");
	printf("|      Petunjuk Permainan:                                                  |\n");
	printf("|      1. Mainkan dengan hati yang gembira. Tugas                           |\n");
	printf("|      2. Ikuti selalu petunjuk yang ada (akan ada                          |\n");
	printf("|         keterangan kalo input ga valid).                                  |\n");
	printf("|      3. Setelah mulai permainan, kamu punya 1000 gold. Pastikan           |\n");
	printf("|         beli item dulu!                                                   |\n");
	printf("|      4. Jangan terlalu pede dan nyerang semua pokemon. Beberapa bisa      |\n");
	printf("|         1-hit kill pokemon kamu.                                          |\n");
	printf("|      5. Seperti game keren dan seru lainnya, game ini butuh beberapa      |\n");
	printf("|         kali playthrough untuk menguasainya.                              |\n");
	printf("|      6. Oleh karena itu, jangan pernah menyerah.                          |\n");
	printf("|      7. Setelah menangkap semua pokemon, akan muncul pokemon              |\n");
	printf("|         SECRET FRIEND spesial, dan kamu akan memenangkan game ini         |\n");
	printf("|         setelah bisa mengalahkannya.                                      |\n");
	printf("|                                  SEMANGAT!                                |\n");
	printf("|---------------------------------------------------------------------------|\n");
}

void about() {
	system("cls");

	printf("|---------------------------------------------------------------------------|\n"); 
	printf("|                                                                           |\n");
	printf("|                                                                           |\n");
	printf("|      About:                                                               |\n");
	printf("|                                                                           |\n");
	printf("|      Condro : Lead Programmer                                             |\n");
	printf("|                                                                           |\n");
	printf("|                                                                           |\n");
	printf("|      Avid : Project Manager                                               |\n");
	printf("|                                                                           |\n");
	printf("|                                                                           |\n");
	printf("|      Kukuh : Producer                                                     |\n");
	printf("|                                                                           |\n");
	printf("|                                                                           |\n");
	printf("|                                                                           |\n");
	printf("|                                                                           |\n");
	printf("|                  COPYRIGHTED BY MOONWALKER 2016                           |\n");
	printf("|              (except -Pokemon- brand name, it's not ours.)                |\n");
	printf("|---------------------------------------------------------------------------|\n");
}

void gameover(){
	time_t rawtime;
	struct tm *info;
	char buffer[80];
	Score Scr;

	//MASALAH TANGGAL
	time( &rawtime );
	info = localtime( &rawtime );
	strftime(buffer,80,"%x", info);
	
	//SCORE
	strcpy(Scr.nama,Player.nama);
	strcpy(Scr.tanggal,buffer);
	Scr.exp = Player.exp;
	TambahScoreboard(&S,Scr);
	tulisFileScoreboard(S);
	
	system("cls");
	
	char gerak;
	
	printf("|---------------------------------------------------------------------------|\n"); 
	printf("|                                                                           |\n");
	printf("|                                                                           |\n");
	printf("|        ::.        #`                                                      |\n");
	printf("|      `@@@@@@@     ;@@.              GAME OVER                             |\n");
	printf("|       @@@@@@@     :@@:              SEE YOU                               |\n");
	printf("|       @@@ `@:      @@+               .                 .                  |\n");
	printf("|       #@:@#   @@@: @@#     #@@:    @@@@@      @@ @;@@@:  @@@@@@@@@.       |\n");
	printf("|       @@#   @@`@@  @@@ #@@ @@@@    @@@@@@     @# @@@@`@ @+@;@+@@@@        |\n");
	printf("|       @@   @@.  @@ @@@@@  @@@ @@#+ @@ @@@@.  @@@ .@  `@ @.@@  @@@@        |\n");
	printf("|      '@`  @@@:@@@  @@@#  @@#@  @@: @@  @@@@@:@@@ @@  @@ @@@@  @@@@        |\n");
	printf("|       @@  @@@@@@   +@@@@ `@@@`@    @@   @:@@@ @@ @@  @@ @@@@  @@@+        |\n");
	printf("|       @@  `@@@@   ;@@,@@@ @@@@@@@' @@    @@#  @@ @@#@@@ @+@@  @@@@:       |\n");
	printf("|       ;    ':     :@@  @@, +:      .` ,.  ':   .+` `    ..                |\n");
	printf("|                   .@@   +                                                 |\n");
	printf("|                                                                           |\n");
	printf("|                                                                           |\n");
	printf("|----------------------|--------------|------------|------------------------|\n");
	printf("|                        PRESS ANY KEY TO CONTINUE                          |\n");
	printf("|----------------------|--------------|------------|------------------------|\n");
	
	gerak = getch();
	tulisLayarScoreboard(S);
	gerak = getch();
	exit(0);
}

/* I.S. M terdefinisi */
/* F.S. Sama dengan I.S, dan nilai M(i,j) ditulis ke layar*/
/* Menulis Nilai setiap indeks dan elemen M ke layar */
/* dengan traversal per baris */
void TulisPeta2(MATRIKS M){
	int i,j;
	el_type X;
	
	printf("|---------------------------------------------------------------------------|\n"); 
	printf("|                                                                           |\n");
	printf("|                        |----------------------|                           |\n");
	for (i = BrsMin; i <= M.NBrsEff; i++) {
			printf("|                        | ");
			for (j = KolMin; j <= M.NKolEff ; j++) {
				if (M.Mem[i][j]==80) {
					printf("%c ",M.Mem[i][j]);			
				} else {
					printf("%c%c",M.Mem[i][j],M.Mem[i][j]);		
				}	
			};
			printf(" |                           |\n");
		};	
	printf("|                        |----------------------|                           |\n");
	printf("|                                                                           |\n");
	printf("|                        POKEMON CITY  %d                                    |\n",MapNo);
	printf("|                                                                           |\n");
	printf("|----------------------|------------|------------|--------------------------|\n");
	printf("| MOVE : W,A,S,D       | BAG : B    | MENU : M   |                          |\n");
	printf("|----------------------|------------|------------|--------------------------|\n");

}

/*Prosedur yang dijalankan jika pemain masuk ke sebuah toko */ 
void mauketoko(MATRIKS *M) {
	char gerak;
	//Pokemon PInfo;
	int i,j;
	system("cls");
	int pilihan;
	
	pilihan = 1; //inisialisasi
	
    do {
		system("cls");
		
		printf("|---------------------------------------------------------------------------|\n"); 
		printf("| POKE STORE                                                                |\n");
		printf("|---------------------------------------------------------------------------|\n");
		printf("|                                                                           |\n");
		for (i=1;i<=PokeToko.Nef;i++) {
			printf("|---------------------------------------------------------------------------|\n");
			if (i==pilihan)
				printf("|> %d. %-18s ( tipe: %-10s, harga: %-5d, efek: %-5d )    |\n",i,PokeToko.L[i].nama_barang,PokeToko.L[i].tipe_barang,PokeToko.L[i].harga,PokeToko.L[i].efek);
			else 
				printf("|%d. %-20s ( tipe: %-10s, harga: %-5d, efek: %-5d )    |\n",i,PokeToko.L[i].nama_barang,PokeToko.L[i].tipe_barang,PokeToko.L[i].harga,PokeToko.L[i].efek);
		}
		printf("|---------------------------------------------------------------------------|\n");
		printf("|                                                                           |\n");
		printf("|                                                                           |\n");
		printf("|-----------------------|---------------------------------------------------|\n");
		printf("| Pilih(W, S dan ENTER) | KELUAR : X                                        |\n");
		printf("|-----------------------|---------------------------------------------------|\n");
		
		
		gerak = getch();
		if (gerak=='x') {
			break;
		} else if (gerak=='w') {
			if (pilihan<=1)
				pilihan = 1;
			else
				pilihan = pilihan - 1;
		} else if (gerak=='s') {
			if (pilihan>=PokeToko.Nef)
				pilihan = PokeToko.Nef;
			else
				pilihan = pilihan + 1;
		} else if (gerak==13) {
			if (Player.uang>=PokeToko.L[pilihan].harga) {
				Player.uang = Player.uang - PokeToko.L[pilihan].harga;
				InsertUrut (&Bag, PokeToko.L[pilihan]);
				printf("Barang Terbeli. \n");
				sleep(1);
			} else {
				printf("Uang kurang!");
				sleep(1);
			}
		}
		else {
			printf("Input tidak valid.\n");
			sleep(1);
		}
	} while (gerak !='r');
}

void tampilpokemonawal() {
	char gerak;
	int i,j;
	system("cls");
	int pilihan;
	
	pilihan = 1; //inisialisasi
    do {
		system("cls");
		
		printf("|---------------------------------------------------------------------------|\n"); 
		printf("| PILIH POKEMONMU                                                           |\n");
		printf("|---------------------------------------------------------------------------|\n");
		printf("|                                                                           |\n");
		printf("|-------------|---------|-----------|----------|-----------|----------------|\n"); 
		for (i=1;i<=DP1.Nef;i++) {
			if (i==pilihan) {
				printf("|> %-9s  | HP      | ATTACK    | EXP      | MONEY     | CATCH RATE     |\n",DP1.P[i].nama_pokemon);
				printf("|> %-9s  | %-7g | %-2d - %-2d   | %-2d - %-2d | %-3d - %-3d | %-13d  |\n",DP1.P[i].tipe_pokemon,DP1.P[i].hp,DP1.P[i].attack.X,DP1.P[i].attack.Y,DP1.P[i].exp.X,DP1.P[i].exp.Y,DP1.P[i].money.X,DP1.P[i].money.X,DP1.P[i].catchrate);
			}
			else {
				printf("| %-10s  | HP      | ATTACK    | EXP      | MONEY     | CATCH RATE     |\n",DP1.P[i].nama_pokemon);
				printf("| %-10s  | %-7g | %-2d - %-2d   | %-2d - %-2d | %-3d - %-3d | %-13d  |\n",DP1.P[i].tipe_pokemon,DP1.P[i].hp,DP1.P[i].attack.X,DP1.P[i].attack.Y,DP1.P[i].exp.X,DP1.P[i].exp.Y,DP1.P[i].money.X,DP1.P[i].money.X,DP1.P[i].catchrate);
			}
			printf("|-------------|---------|-----------|----------|-----------|----------------|\n");
		}
		printf("|                                                                           |\n");
		printf("|                                                                           |\n");
		printf("|-----------------------|---------------------------------------------------|\n");
		printf("| Pilih(W, S dan ENTER) | KELUAR : X                                        |\n");
		printf("|-----------------------|---------------------------------------------------|\n");
		
		
		gerak = getch();
		if (gerak==13) {
			TambahPokemonPemain(&Player, DP1.P[pilihan]);
			break;
		} else if (gerak=='w') {
			if (pilihan<=1)
				pilihan = 1;
			else
				pilihan = pilihan - 1;
		} else if (gerak=='s') {
			if (pilihan>=DP1.Nef)
				pilihan = DP1.Nef;
			else
				pilihan = pilihan + 1;
		}
		else {
			printf("Input tidak valid.\n");
			sleep(1);
		}
	} while (gerak !=13);
}

// Pertarungan Antara Pokemon Aktif Player dengan B
void StartBattle (Pokemon B) {
	//KAMUS
	int expmusuh;
	int uangmusuh ;
	char gerak;
	bool keluar = false;		//boleh run
	int j;
	Pokemon Aktif;
	int tempHP = B.hp;
	
	//HP AWal;
	int AwA = Player.pokemon_aktif.hp;
	int AwB = B.hp;
	hpAwal(AwA,AwB);
	
	PrintBattleScreen(Player, B);
	printf("%s appeared!\n", B.nama_pokemon);
    sleep(2);
	
	
	do {
		PrintBattleScreen(Player, B);
		
		if (B.hp <=0) {
				expmusuh  = acak(B.exp.X, B.exp.Y);
				uangmusuh = acak(B.money.X, B.money.Y);
				
				printf("\n%s terkalahkan!",B.nama_pokemon);
				sleep(1);
				
				printf("\nDapat %d P.", uangmusuh);
				GantiUang(&Player,Player.uang + uangmusuh);
				sleep(1);
				
				printf("\nDapat %d EXP.", expmusuh);
				GantiExp(&Player,Player.exp + expmusuh);
				sleep(1);

				break;
			} else if (Player.pokemon_aktif.hp <=0) {
				printf("\n%s terkalahkan!",Player.pokemon_aktif.nama_pokemon);
				sleep(1);
				GantiPokemon(&Player, &Aktif);
				PrintBattleScreen(Player, B);
				if (Aktif.hp==-9999) { //DEFINISI KOSONG;
					printf("\nPokemonmu habis. Kamu Kalah!");
					sleep(2);
					gameover();
				}
			}
		
		gerak = getch();
		if (gerak==13) //ATTACK 
		{
			attackpemain(&Player,&B);
			PrintBattleScreen(Player, B);
			attackmusuh(&Player,&B);
		} else 
		if (gerak=='r') //RUN
		{	
			if (acak(0,1)==1) {
				printf("Kabur berhasil.\n");
				sleep(1);
				keluar = true;
			} else {
			printf("Kabur gagal.\n");
			sleep(1);
			attackmusuh(&Player,&B);
			}
		}
		else
		if (gerak=='b') //BAG
		{
			Barang item;
			bool Pilih=false;
			OpenBag(&Bag,&item,&Pilih);
			if (Pilih) {
				PrintBattleScreen(Player, B);
				printf("\nMenggunakan %s ( %s ).",item.nama_barang,item.tipe_barang);
				sleep(1);
				if ((strcmp(item.tipe_barang, "pokeball"))==0) {
					PrintBattleScreen(Player, B);
					printf("Menangkap %s ", B.nama_pokemon);
					int kesempatan ;
					kesempatan = B.catchrate + item.efek;
					printf("(%d persen).\n", kesempatan);
					sleep(1);
					if (acak(1,100)==kesempatan) {
						PrintBattleScreen(Player, B);
						printf("\nSuccess! %s tertangkap.",B.nama_pokemon);
						TambahPokemonPemain(&Player, B);
						sleep(1);
						break;
					} else {
						printf("\nFailed! %s gagal tertangkap.",B.nama_pokemon);
						sleep(1);
						attackmusuh(&Player,&B);
					}
				} else //pasti potion
				{
					PrintBattleScreen(Player, B);
					printf("\nHP bertambah sebesar %d.",item.efek);
					Player.pokemon_aktif.hp = Player.pokemon_aktif.hp + item.efek;
					AwA = Player.pokemon_aktif.hp;
					hpAwal(AwA,AwB);
					sleep(1);
					attackmusuh(&Player,&B);
				}
			}
		}
		 else {
			printf("Input tidak valid \n");
			sleep(1);
		}
		
		if (keluar) {
			break;
		}
	} while (!keluar);
}

/*Prosedur Pemain untuk berkeliling di peta Matrik M, dengan M sudah terdefinisi */
void jalan(MATRIKS *M) {
	Pokemon P2;
	char arah;
	POINT kode;
	system("cls");
	TulisPeta2(*M);
	Pokemon PInfo;
	
	do {
		system("cls");
		TulisPeta2(*M);
		
		//scanf(" %c",&arah);
		arah = getch();
		if (arah=='a') {
			kode = PindahKiri((&(*M)),sebelum,&sebelum);
		} else if (arah=='s') {
			kode = PindahBawah((&(*M)),sebelum,&sebelum);
			
		} else if (arah=='d') {
			kode = PindahKanan((&(*M)),sebelum,&sebelum);
			
		} else if (arah=='w') {
			kode = PindahAtas((&(*M)),sebelum,&sebelum);
			
		} else if (arah=='b') {
			PrintOpenBag(Bag);
		} else if (arah=='p') {
			Posi = CariPosisi((*M));
			switch (MapNo) {
				case 1 : Posi = Posi; break;
				case 2 : Posi.Y = 10 + Posi.Y;break;
				case 3 : Posi.X = 10 + Posi.X;break;
				case 4 : Posi.X = 10 + Posi.X;
					     Posi.Y = 10 + Posi.Y;
						 break;
			}
			PlayerInfo(Player,Posi,Bag);
		} else if (arah=='x') {
			Posi = CariPosisi((*M));
			break;
			tulismenu();
		} 
		
		if ((kode.X==9)&&(kode.Y==9)) {
			Pokemon PInfo;
			//Jika ketemu di semak2
			//Keluarkan Pokemon
			Del((&P1),&PInfo);
			
			//Masukkan Kembali dengan HP yang terestore
			int tempHP = PInfo.hp;
			
			//Mulai Batle
			StartBattle(PInfo);
			//Tambah
			Add((&P1),PInfo);
			//break;
		} else if ((kode.X==10)&&(kode.Y==10)) {
			mauketoko(&(*M));
			//break;
		} else if ((kode.X==7)&&(kode.Y==10)) {
			// 1 ke 2
			SetEl(&M1,kode.X,kode.Y,46);
			MapNo = 2;
			SetEl(&M2,7,1,80);
			jalan(&M2);
			break;
		} else if (((kode.X==7)&&(kode.Y==1))&&MapNo==2) {
			// 2 ke 1
			SetEl(&M2,kode.X,kode.Y,46);
			MapNo = 1;
			SetEl(&M1,7,10,80);
			jalan(&M1);
			break;
		} else if ((kode.X==10)&&(kode.Y==6)) {
			// 1 ke 3
			SetEl(&M1,kode.X,kode.Y,46);
			MapNo = 3;
			SetEl(&M3,1,6,80);
			jalan(&M3);
			break;
		} else if ((kode.X==1)&&(kode.Y==6)) {
			// 3 ke 1
			SetEl(&M3,kode.X,kode.Y,46);
			MapNo = 1;
			SetEl(&M1,10,6,80);
			jalan(&M1);
			break;
		} else if ((kode.X==1)&&(kode.Y==3)) {
			// 4 ke 2
			SetEl(&M4,kode.X,kode.Y,46);
			MapNo = 2;
			SetEl(&M2,10,3,80);
			jalan(&M2);
			break;
		} else if ((kode.X==1)&&(kode.Y==9)) {
			// 4 ke 2
			SetEl(&M4,kode.X,kode.Y,46);
			MapNo = 2;
			SetEl(&M2,10,9,80);
			jalan(&M2);
			break;
		} else if ((kode.X==10)&&(kode.Y==3)) {
			// 2 ke 4
			SetEl(&M2,kode.X,kode.Y,46);
			MapNo = 4;
			SetEl(&M4,1,3,80);
			jalan(&M4);
			break;
		} else if ((kode.X==10)&&(kode.Y==9)) {
			// 2 ke 4
			SetEl(&M2,kode.X,kode.Y,46);
			MapNo = 4;
			SetEl(&M4,1,9,80);
			jalan(&M4);
			break;
		} else if (MapNo==3&&(kode.X==5)&&(kode.Y==10)) {
			// 3 ke 4
			SetEl(&M3,kode.X,kode.Y,46);
			MapNo = 4;
			SetEl(&M4,5,1,80);
			jalan(&M4);
			break;
		} else if (MapNo==4&&(kode.X==5)&&(kode.Y==1)) {
			// 4 ke 3
			SetEl(&M4,kode.X,kode.Y,46);
			MapNo = 3;
			SetEl(&M3,5,10,80);
			jalan(&M3);
			break;
		}
 	} while (arah !='m');
}


void PermainanBaru(){
	char c;
	system("cls");
	do {
		system("cls");
		printf("|---------------------------------------------------------------------------|\n"); 
		printf("|                   ,,,.....                                                |\n");
		printf("|                  ,,,,,.,,,*.                                              |\n");
		printf("|                  ./*,...**(,                                              |\n");
		printf("|                   */*,./*,(,                                              |\n");
		printf("|                   .,.,*,,(*                                               |\n");
		printf("|                  .,//#((((,,                                              |\n");
		printf("|                ./*.*(((((( .**                                            |\n");
		printf("|                **.  //*/..   (.                                           |\n");
		printf("|               ,**. .***/  ,   (                                           |\n");
		printf("|          ..  .*,* ./**/.. ./,,*/                                          |\n");
		printf("|        .,/*((  *, .//*/,  ,/#*,*(                                         |\n");
		printf("|       ./((/,**,**,*#(((,,*//   .(                                         |\n");
		printf("|                                                                           |\n");
		printf("| %-74s|\n",NarasiIntro.Mem[IdxNarasiIntro].Teks);
		printf("|                                                                           |\n");	
		printf("|---------------------------------------------------------------------------|\n");
		printf("| LANJUT : ENTER                                                            |\n");
		printf("|---------------------------------------------------------------------------|\n");
		if (IdxNarasiIntro==12){
			BuatPemain(&Player);
			printf("Yakin? Tekan lanjut. Tekan tombol lain untuk cancel.");
		}
		
		c = getch();
		if (c==13) {
				IdxNarasiIntro++;
			} else {
				if (IdxNarasiIntro==12){
				} else {
				printf("Tekan ENTER untuk lanjut!");
                sleep(1);
				}
			}
		} while (IdxNarasiIntro <=NarasiIntro.Nef);
		tampilpokemonawal();
		GameBaru = false;
}



/*I.S. : Sembarang
 *F.S  : Load Semua Peta, Pokeon, Toko,Pemain, dan semuanya */
int SETUP() {
	M1 = LoadPeta1();	
	M2 = LoadPeta2();
	M3 = LoadPeta3();
	M4 = LoadPeta4();
	P1 = LoadPokemon();
	PokeToko = LoadBarang();
	NarasiIntro = BuatNarasiIntro();
	DP1 = LoadPokemonAwal();
	S = LoadScoreboard();
}

int main (){
	POINT Pos;
	char I;
	int j;	
	//ALGORITMA
	
	MapNo = 1; 			//MAP No default
	GameBaru = true ;		//Nilai Game Baru Default, 1 : New Game, 0 : resume;
	SETUP();
	do {
		tulismenu();
		I = getch();
		if (I=='m') {
			if (GameBaru==true) {
				CreateEmptyList(&Bag);
				PermainanBaru();
			} 
			//dapatkan informasi map
			switch (MapNo) {
				case 1 : jalan(&M1);break;
				case 2 : jalan(&M2);break;
				case 3 : jalan(&M3);break;
				case 4 : jalan(&M4);break;
				default : jalan(&M1);break;
			}
		} else if (I=='x') {
			printf("Good bye!");
			sleep(1);
			break;
		} else if (I=='h') {
			petunjuk();
			printf("\nPress any key to continue.");
			char q = getch();
		} else if (I=='a') {
			about();
			printf("\nPress any key to continue.");
			char q = getch();
		} 
		else { 
			printf("Masukan anda salah. Silakan periksa kembali! \n"); 
			sleep(1);
		}
		
	} while (I!='x');
	
	return 0;
}
