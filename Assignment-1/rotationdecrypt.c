/*
 ============================================================================
 Name        : ENGG1003_Assessment 1_Rotation Decryption.c
 Author      : David Procter
 Version     : 002
 Copyright   : Copyright - David Procter
 Description : Rotation Decryption
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int rotationDecrypt (void);


int rotationDecrypt (void)
{
	int b=0;
	int c=0;
	int key=10;

	puts("ENGG1003_Assessment 1_Rotation Decryption"); /* prints ENGG1003_Assessment 1_Rotation Encryption */

	char textstring [1024] = "KJ WI PSBCD DOCD CDBSXQ" ;

	printf("%s\n", textstring);  //Print the text string.

	for (int a=0 ; textstring[a] != '\0' ; a++ ) // Run a loop and encript the string.
	{
		b = textstring[a];
		if (b >= 65 && b <= 90) //Only encript the capital letters.
		{
			c=b-key;
			if (c<65) // Subtraction to keep the result within capital letters
			{
				c=c+26;
			}
			//printf("Value at index %d is: %d plus key value: %d\n", a, b, c); //Check the internal process
			textstring[a]=c; // Change the value of the letter
		}
	}
	printf("%s\n", textstring); //Print the encripted result

	return 0;
}
