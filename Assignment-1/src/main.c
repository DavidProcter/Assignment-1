/*
 ============================================================================
 Name        : ENGG1003_Assessment 1_Main.c
 Author      : David Procter
 Version     : 001
 Copyright   : Copyright - David Procter
 Description : Cipher System Menu
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int rotationEncrypt (void);
int rotationDecrypt (void);
int substitutionEncrypt (void);
int substitutionDecrypt (void);

int main(void) {

	int a=0;


	if (a==0)
	{
		printf("Description : Cipher System - Option: %d\n", a);
		rotationEncrypt ();
		a++;
	}
	if (a==1)
	{
		printf("Descryption : Cipher System - Option: %d\n", a);
		rotationDecrypt ();
		a++;
	}
	if (a==2)
	{
		printf("Descryption : Cipher System - Option: %d\n", a);
		substitutionEncrypt ();
		a++;
	}
	if (a==3)
	{
		printf("Descryption : Cipher System - Option: %d\n", a);
		substitutionDecrypt ();
	}
	return 0;

}
