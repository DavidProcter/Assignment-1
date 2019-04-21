/*
 ============================================================================
 Name        : ENGG1003_Assessment 1_Rotation Decription.c
 Author      : David Procter
 Version     : 003
 Copyright   : Copyright - David Procter
 Description : Rotation Decription
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int rotationDecript (void)
{
	int b=0;
	int c=0;
	int key=10;

	puts("ENGG1003_Assessment 1_Rotation Decription"); /* prints ENGG1003_Assessment 1_Rotation Encription */

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
