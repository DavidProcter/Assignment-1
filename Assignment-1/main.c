/*
 ============================================================================
 Name        : ENGG1003_Assessment 1_Main.c
 Author      : David Procter
 Version     : 001
 Copyright   : Copyright - David Procter
 Description : Cipher System
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int rotationEncript (void);
int rotationDecript (void);
int substitutionEncript (void);
int substitutionDecript (void);

int main(void) {

	int a=0;


	if (a==0)
	{
		printf("Description : Cipher System - Option: %d\n", a);
		rotationEncript ();
		a++;
	}
	if (a==1)
	{
		printf("Description : Cipher System - Option: %d\n", a);
		rotationDecript ();
		a++;
	}
	if (a==2)
	{
		printf("Description : Cipher System - Option: %d\n", a);
		substitutionEncript ();
		a++;
	}
	if (a==3)
	{
		printf("Description : Cipher System - Option: %d\n", a);
		substitutionDecript ();
	}
	return 0;

}
