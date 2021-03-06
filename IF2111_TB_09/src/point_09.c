/* TUGAS BESAR IF2111 - Algoritma dan Struktur Data 
Pokemoon
---------------------------------------------------------------
Nomor Kelompok 	: 09
Nama File : point_09.c
Deskripsi : Mendeklarasikan semua tipe data yang digunakan
---------------------------------------------------------------
*/

#include "point_09.h"
#include <stdio.h>
#include <math.h>
/*
 * MakePOINT
 * Membuat instance POINT baru berdasarkan nilai X dan Y
 */
POINT MakePOINT (float X, float Y){
	POINT p;
	Absis(p) = X;
	Ordinat(p) = Y;
	return p;
}
/*
 * BacaPOINT
 * Membaca nilai absis dan ordinat dari keyboard dan membentuk
 * POINT P berdasarkan dari nilai absis dan ordinat tersebut
 * Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi
 * I.S. Sembarang
 * F.S. P terdefinisi
 */
void BacaPOINT (POINT * P){
	float x, y;
	scanf("%f %f", &x, &y);
	*P = MakePOINT(x,y);
}
/*
 * TulisPOINT
 * Menuliskan nilai P ke layar dengan format "(X,Y)"
 * tanpa spasi, enter, atau karakter lain di depan, belakang, atau di antaranya
 * I.S. P terdefinisi
 * F.S. P tertulis di layar dengan format "(X,Y)"
 */
void TulisPOINT (POINT P){
	printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}
/*
 * EQ
 * mengambalikan nilai true jika P1 dan P2 adalah titik yang sama, dan false
 * jika sebaliknya
 */
bool EQ (POINT P1, POINT P2){
	return fabs(Absis(P1) - Absis(P2)) <= eps &&
		fabs(Ordinat(P1) - Ordinat(P2)) <= eps;
}
/*
 * NEQ
 * mengambalikan nilai true jika P1 dan P2 adalah titik yang berbeda, dan false
 * jika sebaliknya
 */
bool NEQ (POINT P1, POINT P2){
	return !EQ(P1,P2);
}
/*
 * IsOrigin
 * mengambalikan nilai true jika P adalah titik (0,0), dan false jika sebaliknya
 */
bool IsOrigin (POINT P){
	return fabs(Absis(P)) <= eps && fabs(Ordinat(P)) <= eps;
}
/*
 * IsOnSbX
 * mengambalikan nilai true jika P terletak pada sumbu X, dan false jika sebaliknya
 */
bool IsOnSbX (POINT P){
	return fabs(Ordinat(P)) <= eps;
}
/*
 * IsOnSbY
 * mengambalikan nilai true jika P terletak pada sumbu Y, dan false jika sebaliknya
 */
bool IsOnSbY (POINT P){
	return fabs(Absis(P)) <= eps;
}
/*
 * Kuadran
 * Menghasilkan kuadran dari P: 1, 2, 3, atau 4
 * Prekondisi :
 *	P bukan titik origin,
 *  dan P tidak terletak di sumbu X ataupun Y
 */
int Kuadran (POINT P){
	if (Absis(P) > 0 && Ordinat(P) > 0)
		return 1;
	else if (Absis(P) < 0 && Ordinat(P) > 0)
		return 2;
	else if (Absis(P) < 0 && Ordinat(P) < 0)
		return 3;
	else
		return 4;
}
/*
 * NextX
 * Mengirim salinan P dengan absis ditambah satu
 */
POINT NextX (POINT P){
	Absis(P) += 1.0;
	return P;
}
/*
 * NextY
 * Mengirim salinan P dengan ordinat ditambah satu
 */
POINT NextY (POINT P){
	Ordinat(P) += 1.0;
	return P;
}
/*
 * PlusDelta
 * Mengirim salinan P yang absisnya adalah Absis(P) + deltaX
 * dan ordinatnya adalah Ordinat(P) + deltaY
 */
POINT PlusDelta (POINT P, float deltaX, float deltaY){
	Absis(P) += deltaX;
	Ordinat(P) += deltaY;
	return P;
}
/*
 * MirrorOf
 * Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu
 * Jika SbX bernilai true, maka dicerminkan terhadap sumbu X
 * Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y
 */
POINT MirrorOf (POINT P, bool SbX){
	if (SbX)
		return MakePOINT(Absis(P), -Ordinat(P));
	else
		return MakePOINT(-Absis(P), Ordinat(P));
}
/*
 * MirrorOf
 * Menghitung jarak P ke (0,0)
 */
float Jarak0 (POINT P){
	return sqrt(Absis(P)*Absis(P) + Ordinat(P)*Ordinat(P));
}
/*
 * Panjang
 * Menghitung jarak antara titik P1 dan P2
 */
float Panjang (POINT P1, POINT P2){
	float wx = Absis(P1) - Absis(P2);
	float wy = Ordinat(P1) - Ordinat(P2);
	return sqrt(wx*wx + wy*wy);
}
/*
 * Geser
 * Menggeser nilai absis dan ordinat P sejauh deltaX dan deltaY
 * I.S. P terdefinisi
 * F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY
 */
void Geser (POINT *P, float deltaX, float deltaY){
	Absis(*P) += deltaX;
	Ordinat(*P) += deltaY;
}
/*
 * GeserKeSbX
 * Menggeser P ke sumbu X
 * I.S. P terdefinisi
 * F.S. P berada pada sumbu X dengan absis sama dengan absis semula.
 */
void GeserKeSbX (POINT *P){
	Ordinat(*P) = 0;
}
/*
 * GeserKeSbY
 * Menggeser P ke sumbu Y
 * I.S. P terdefinisi
 * F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula.
 */
void GeserKeSbY (POINT *P){
	Absis(*P) = 0;
}
/*
 * Mirror
 * Mencerminkan nilai P terhadap sumbu X atau Y
 * Jika SbX true maka dicerminkan terhadap sumbu X
 * Jika SbX false maka dicerminkan terhadap sumbu Y
 * I.S. P terdefinisi
 * F.S. P dicerminkan tergantung nilai SbX atau SbY
 */
void Mirror (POINT *P, bool SbX){
	*P = MirrorOf(*P, SbX);
}
/*
 * Putar
 * Memutar nilai P dengan titik pusat (0,0) sejauh Sudut berlawanan arah jarum jam
 * I.S. P terdefinisi
 * F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0)
 */
void Putar (POINT *P, float Sudut){
	float x = Absis(*P) * cos(Sudut) - Ordinat(*P) * sin(Sudut);
	float y = Absis(*P) * sin(Sudut) + Ordinat(*P) * cos(Sudut);
	Absis(*P) = x;
	Ordinat(*P) = y;
}