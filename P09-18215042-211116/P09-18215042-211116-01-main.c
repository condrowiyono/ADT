/*Nama/NIM                   : Condro Wiyono	*/
/*Tanggal                    : 30 Oktober 2016*/
/*Topik                      : ADT STACK LIST*/
/*Deskripsi                  : STACK LIST */


#include "P09-18215042-211116-01.h"
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Stack S1;
Stack S2;
Stack S3;
Stack S4;

int main() {
	char * str;
	printf("Program :");
	scanf(" %[^\n]%*c",str);
	CreateEmpty(&S1);  //untuk begin end
	CreateEmpty(&S2);  //()
	CreateEmpty(&S3);  //{}
	CreateEmpty(&S4);  // if then
	
	char *pch;
	char strong[256];
	
	pch = strtok (str," ,.-");
	while (pch != NULL)
	{
		//printf ("%s\n",pch);
		pch = strtok (NULL, " ,.-");
	}
	
	printf("Hasil :");
	if (IsEmpty(S1)&&IsEmpty(S2)&&IsEmpty(S3)&&IsEmpty(S4)) {
			printf("kompilasi berhasil");
	}
	
}
