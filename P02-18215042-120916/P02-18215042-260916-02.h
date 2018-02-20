/*
{Nama/NIM                  : Condro Wiyono	}
{Tanggal                    : 26 September 2016}
{Topik                      : Abstract Data Type}
{Deskripsi                  : Soal Nomor 2 :  Ini adalah file HEADER dari Abstract Data Type jam}
*/

typedef int bool; 
#define true 1 
#define false 0
#ifndef JAM_H 
#define JAM_H
// Definisi TYPE JAM <HH:MM:SS> 

typedef struct {
	int HH;
	int MM;
	int SS;
}JAM;

//***************************** 
//DEFINISI PRIMITIF 
//***************************** 
//KELOMPOK VALIDASI TERHADAP TYPE 
//***************************** 

bool isJAMValid(int H, int M, int S);
//Mengirim true jika H,M,S dapat membentuk J yang valid 
//dipakai untuk mentest SEBELUM membentuk sebuah Jam 

// *** Konstruktor: Membentuk sebuah JAM dari komponen - komponennya *** 
JAM makeJAM(int HH, int MM, int SS);
//Membentuk sebuah JAM dari komponen-komponennya yang valid 
//Prekondisi : HH, MM, SS valid untuk membentuk JAM 

// *** Operasi terhadap komponen : selektor Get dan Set *** 
// *** Selektor *** 

int getHour(JAM J);
//Mengirimkan bagian jam (HH) dari JAM 

int getMinute(JAM J);
//Mengirimkan bagian menit (MM) dari JAM 

int getSecond(JAM J);
//Mengirimkan bagian detik (SS) dari JAM 

//*** Pengubah nilai Komponen *** 

void setHH(JAM *J, int newHH);
//Mengubah nilai komponen jam (HH) dari J dengan newHH 

void setMM(JAM *J, int newMM);
//Mengubah nilai komponen menit (MM) dari J dengan 

void setSS(JAM *J, int newSS);
//Mengubah nilai komponen detik (SS) dari J dengan newSS 

//************************************
// KELOMPOK BACA/TULIS 
//************************************ 

void bacaJam(JAM *J);
// I.S. : J tidak terdefinisi 
//F.S. : J terdefinisi dan merupakan jam yang valid 
//Proses : mengulangi membaca komponen H,M,S sehingga membentuk J 
//yang valid. Tidak mungkin menghasilkan J yang tidak valid. 

void tulisJam(JAM J);
// I.S. : J sembarang 
//F.S. : Nilai J ditulis dg format HH:MM:SS 
//Proses : menulis nilai setiap komponen J ke layar 
//***************************** 
//KELOMPOK KONVERSI TERHADAP TYPE 
//***************************** 

int jamToDetik(JAM J);
//Diberikan sebuah  JAM, mengkonversi menjadi jumlah  Detik dari  pukul 0:0:0 
//Rumus :detik= 3600*HH + 60*MM + SS 
//nilai maksimum = 3600*23+59*60+59 

JAM detikToJam(int N);
//Mengirim konversi detik ke JAM 

//***************************** 
//KELOMPOK OPERASI TERHADAP TYPE 
//***************************** 

//*** Kelompok Operator Relational *** 

bool JEQ(JAM J1, JAM J2);
//Mengirimkan true jika J1=J2, false jika tidak 

bool JNEQ(JAM J1, JAM J2);
//Mengirimkan truejika J1 tidak sama dengan J2 

bool JLT(JAM J1, JAM J2);
//Mengirimkan true jika J1<J2 , false jika tidak 

bool JGT(JAM J1, JAM J2);
//Mengirimkan truejika J1>J2, false jika tidak 

//*** Operator aritmatika JAM *** 
JAM nextNDetik(JAM J, int N);
//Mengirim N detik setelah J dalam bentuk JAM 

JAM prevNDetik(JAM J, int N);
//Mengirim N detik sebelum J dalam bentuk JAM 
//*** Kelompok Operator Aritmetika *** 

int durasi(JAM Jaw, JAM Jakh);
//Mengirim JAkh-JAw dlm Detik, dengan kalkulasi
//Jika JAw >JAkhir, maka JAkhir adalah 1 hari setelah JAw

#endif
