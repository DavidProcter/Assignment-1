/*
 ============================================================================
 Name        : ENGG1003_Assessment 1_Rotation Encryption.c
 Author      : David Procter
 Version     : 105
 Copyright   : Copyright - David Procter
 Description : Rotation Encryption
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int rotationEncript (void);

int main(void) {
	puts("ENGG1003_Assessment 1_Rotation Encryption"); /* prints ENGG1003_Assessment 1_Rotation Encryption */
	rotationEncript ();
	rotationDecrypt ();
	substitutionEncript ();
	substitutionDecript ();
	return EXIT_SUCCESS;
}

int rotationEncript (void)
{
	int b=0, c=0, key=10;

	char textstring [1024] = "AZ MY FIRST TEST STRING" ;



	printf("%s\n", textstring);  //Print the text string.

	for (int a=0 ; textstring[a] != '\0' ; a++ ) // Run a loop and encrypt the string.
	{
		b = textstring[a];
		if (b >= 65 && b <= 90) //Only encrypt the capital letters.
		{
			c=b+key;
			if (c>90) // Subtraction to keep the result within capital letters
			{
				c=c-26;
			}
			//printf("Value at index %d is: %d plus key value: %d\n", a, b, c); //Check the internal process
			textstring[a]=c; // Change the value of the letter
		}
	}
	printf("%s\n", textstring); //Print the encrypted result

	return 0;
}
