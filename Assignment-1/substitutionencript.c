/*
 ============================================================================
 Name        : ENGG1003_Assessment 1_Substitution Encription.c
 Author      : David Procter
 Version     : 004
 Copyright   : Copyright - David Procter
 Description : Substitution Encription
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int substitutionEncript (void);


int substitutionEncript (void)
{
	int b=0;

	puts("ENGG1003_Assessment 1_Sudstitution Encription"); /* prints ENGG1003_Assessment 1_Rotation Encription */

	char textstring [1024] = "AZ MY FIRST TEST STRING IS EASY TO ENCRIPT NOW I NEED TO DECRIPT THE STRING" ;
	char keystring [1024] = "LKJHGFDSAMNBVCXZPOIUYTREWQ" ;

	printf("%s\n", textstring);  //Print the tesxt string.

	for (int a=0 ; textstring[a] != '\0' ; a++ ) // Run a loop and encript the string.
	{
		b = textstring[a];
		if (b >= 65 && b <= 90) //Only encript the capital letters.
		{
			b=b-65;
			textstring[a] = keystring[b];
		}
	}
	printf("%s\n", textstring); //Print the encripted result

	return 0;
}
