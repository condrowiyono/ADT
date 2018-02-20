/*
{Nama/NIM                  : Condro Wiyono	}
{Tanggal                    : 26 September 2016}
{Topik                      : Abstract Data Type}
{Deskripsi                  : Soal Nomor 2 :  Ini adalah file HEADER dari Abstract Data Type jam}
*/

#ifndef JAM_c 
#define JAM_c
#include <stdio.h>
#include "P02-18215042-260916-02.h"
// Definisi TYPE JAM <HH:MM:SS> 


//***************************** 
//DEFINISI PRIMITIF 
//***************************** 
//KELOMPOK VALIDASI TERHADAP TYPE 
//***************************** 

bool isJAMValid(int H, int M, int S) {
	//Mengirim true jika H,M,S dapat membentuk J yang valid 
	//dipakai untuk mentest SEBELUM membentuk sebuah Jam
	//KAMUS
	
	//ALGORITMA
	if (((H>=0) && (H<=23)) && ((M>=0) && (M<=59)) && ((S>=0) && (S<=59))) {
		return true;
	}else{
		return false;
	}

}


// *** Konstruktor: Membentuk sebuah JAM dari komponen - komponennya *** 
JAM makeJAM(int HH, int MM, int SS) {
	//Membentuk sebuah JAM dari komponen-komponennya yang valid 
	//Prekondisi : HH, MM, SS valid untuk membentuk JAM 
	//KAMUS
	JAM J;
	
	//ALGORITMA
		J.HH = HH;
		J.MM = MM;
		J.SS = SS;
		return J;
}


// *** Operasi terhadap komponen : selektor Get dan Set *** 
// *** Selektor *** 

int getHour(JAM J) {
	//Mengirimkan bagian jam (HH) dari JAM 
	//KAMUS
	
	//ALGORITMA
	return (J.HH);
}

int getMinute(JAM J) {
	//Mengirimkan bagian menit (MM) dari JAM 
	//KAMUS
	
	//ALGORITMA
	return (J.MM);
}

int getSecond(JAM J) {
	//Mengirimkan bagian detik (SS) dari JAM 
	//KAMUS
	
	//ALGORITMA
	return (J.SS);
	
}


//*** Pengubah nilai Komponen *** 

void setHH(JAM *J, int newHH){
	//Mengubah nilai komponen jam (HH) dari J dengan newHH 
	//KAMUS
	
	//ALGORITMA
	(*J).HH = newHH;
}
void setMM(JAM *J, int newMM){
	//Mengubah nilai komponen menit (MM) dari J dengan 
	//KAMUS
	
	//ALGORITMA
	(*J).MM = newMM;

}

void setSS(JAM *J, int newSS) {
	//Mengubah nilai komponen detik (SS) dari J dengan newSS 
	//KAMUS
	
	//ALGORITMA
	(*J).SS = newSS;
}
//************************************
// KELOMPOK BACA/TULIS 
//************************************ 

void bacaJam(JAM *J) {
	// I.S. : J tidak terdefinisi 
	//F.S. : J terdefinisi dan merupakan jam yang valid 
	//Proses : mengulangi membaca komponen H,M,S sehingga membentuk J 
	//yang valid. Tidak mungkin menghasilkan J yang tidak valid. 
	//KAMUS
	int h;
	int m;
	int s;
	
	//ALGORITMA
	printf("Detik :");
	scanf("%d", &s);
	printf("Menit :"); 
	scanf("%d", &m);
	printf("Jam :");
	scanf("%d", &h);
	while (!(isJAMValid(h,m,s))) {
		printf("Ulangi \n");
		printf("Masukkan komponen jam : \n");
		printf("Detik :");
		scanf("%d", &s);
		printf("Menit :"); 
		scanf("%d", &m);
		printf("Jam :");
		scanf("%d", &h);
	
	} 
	
	(*J) = makeJAM(h,m,s);
	
}

void tulisJam(JAM J) {
	// I.S. : J sembarang 
	//F.S. : Nilai J ditulis dg format HH:MM:SS 
	//Proses : menulis nilai setiap komponen J ke layar 
	//KAMUS
	
	//ALGORITMA
	printf("%02d : %02d : %02d \n", J.HH, J.MM, J.SS); 
}

//***************************** 
//KELOMPOK KONVERSI TERHADAP TYPE 
//***************************** 

int jamToDetik(JAM J) {
	
	//Diberikan sebuah  JAM, mengkonversi menjadi jumlah  Detik dari  pukul 0:0:0 
	//Rumus :detik= 3600*HH + 60*MM + SS 
	//nilai maksimum = 3600*23+59*60+59 
	//KAMUS
	int detik ;
	//ALGORITMA
	detik= 3600*J.HH + 60*J.MM + J.SS;
	return detik;
	
}

JAM detikToJam(int N) {
	//Mengirim konversi detik ke JAM 
	//KAMUS
	int h;
	int m;
	int s;
	int t; //temporary
	JAM J;
	
	//ALGORITMA
	h = N/3600;
	t = N%3600;
	m = t/60;
	N = t%60;
	J = makeJAM(h,m,N);
	return J;
	
}

//***************************** 
//KELOMPOK OPERASI TERHADAP TYPE 
//***************************** 

//*** Kelompok Operator Relational *** 

bool JEQ(JAM J1, JAM J2) {
	//Mengirimkan true jika J1=J2, false jika tidak 
	//KAMUS
	
	//ALGORITMA
	if ((J1.HH==J2.HH) && (J1.MM==J2.MM) && (J1.SS==J2.SS)) {
		return true;
	}else{
		return false;
	}
}

bool JNEQ(JAM J1, JAM J2) {
	//Mengirimkan truejika J1 tidak sama dengan J2 
	//KAMUS
	
	//ALGORITMA
	if ((J1.HH!=J2.HH) || (J1.MM!=J2.MM) || (J1.SS!=J2.SS)) {
		return true;
	}else{
		return false;
	}
}

bool JLT(JAM J1, JAM J2) {
	//Mengirimkan true jika J1<J2 , false jika tidak 
	//KAMUS
	int detik1;
	int detik2;
	//ALGORITMA
	detik1 = jamToDetik(J1);
	detik2 = jamToDetik(J2);
	
	if (detik1<=detik2) {
		return true;
	}else{
		return false;
	}
}

bool JGT(JAM J1, JAM J2) {
	//Mengirimkan true jika J1>J2, false jika tidak 
	//KAMUS
	int detik1;
	int detik2;
	//ALGORITMA
	detik1 = jamToDetik(J1);
	detik2 = jamToDetik(J2);
	
	if (detik1>=detik2) {
		return true;
	}else{
		return false;
	}
	
}

//*** Operator aritmatika JAM *** 
JAM nextNDetik(JAM J, int N){ 
	//Mengirim N detik setelah J dalam bentuk JAM 
	//KAMUS
	int now;
	JAM J2;
	
	//ALGORITMA
	now = jamToDetik(J) + N ;
	J2 = detikToJam(now);
	return J2;
}

JAM prevNDetik(JAM J, int N) {
	//Mengirim N detik sebelum J dalam bentuk JAM 
	//KAMUS
	int now;
	JAM J2;
	
	//ALGORITMA
	now = jamToDetik(J) - N ;
	J2 = detikToJam(now);
	return J2;
	
	//ALGORITMA
	
}

//*** Kelompok Operator Aritmetika *** 

int durasi(JAM Jaw, JAM Jakh) {
	//Mengirim JAkh-JAw dlm Detik, dengan kalkulasi
	//Jika JAw >JAkhir, maka JAkhir adalah 1 hari setelah JAw
	//KAMUS
	int selisih; 		
	//ALGORITMA
	
	selisih = jamToDetik(Jakh) - jamToDetik(Jaw);
	
	if (selisih>0) {
		return selisih;
	} else {
		selisih = ((24*3600) + jamToDetik(Jakh)) - jamToDetik(Jaw);
		return selisih;
	}

}
#endif
