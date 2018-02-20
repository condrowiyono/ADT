/* TUGAS BESAR IF2111 - Algoritma dan Struktur Data 
Pokemoon
---------------------------------------------------------------
Nomor Kelompok 	: 09
Nama File : helper_09.c
Deskripsi : Beberapa Fungsi yang mungkin digunakan nantinya
---------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "helper_09.h"

#ifndef PEMBANTU_C
//mengacak bilangan antara min dan max
int acak(int min, int max)
{
    int range, result, cutoff;
 
    if (min >= max)
        return min; // only one outcome possible, or invalid parameters
    range = max-min+1;
    cutoff = (RAND_MAX / range) * range;
 
    // Rejection method, to be statistically unbiased.
    do {
        result = rand();
    } while (result >= cutoff);
 
    return result % range + min;
}

//INPUU burapa string / char menghasilkan int
int strtoint(char inputString[20]) {

	int sign = 1, number = 0, index = 0;

	/* Check for negative numbers */
	if(inputString[0] == '-'){
		sign = -1;
		index = 1;
	}

	while(inputString[index] != '\0'){
		if(inputString[index] >= '0' && inputString[index] <= '9'){
			number = number*10 + inputString[index] - '0';
		} else {
		break;
		}
		index++;
	}

	number = number * sign;
	return number;

}

//Memisah dengan "-" menjadi POINT
POINT pisah(char inputString[20]) {
	POINT R1;
	char str[128];
	char *ptr;

	
	strcpy (str, inputString);
	strtok_r (str, "-", &ptr);

	//printf ("'%s'  '%s'\n", str, ptr);

	R1.X = strtoint(str);
	R1.Y = strtoint(ptr);
	
	return R1;
	
}

#endif