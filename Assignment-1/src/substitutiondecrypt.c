/*
 ============================================================================
 Name        : ENGG1003_Assessment 1_Substitution Decryption.c
 Author      : David Procter
 Version     : 004
 Copyright   : Copyright - David Procter
 Description : Substitution Decryption Function
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int substitutionDecrypt (void)
{
	int b=0, c=0;

	puts("ENGG1003_Assessment 1_Substitution Decryption"); /* prints ENGG1003_Assessment 1_Rotation Encryption */

	char textstring [1024] = "LQ VW FAOIU UGIU IUOACD AI GLIW UX GCJOAZU CXR A CGGH UX HGJOAZU USG IUOACD" ;
	char keystring [1024] = "LKJHGFDSAMNBVCXZPOIUYTREWQ" ;

	printf("%s\n", textstring);  //Print the text string.

	for (int a=0 ; textstring[a] != '\0' ; a++ ) // Run a loop and decrypt the string.
	{
		b = textstring[a];
		c=0;
		if (b >= 65 && b <= 90) //Only decrypt the capital letters.
		{
			for (int d=0 ; b!=c ; d++) // Find the matching index to number
			{
				c=keystring[d];
				if (b==c)
				{
					textstring[a]=d+65; //After finding the matching number, add 65 to make it a capital letter.
				}
			}
		}
	}
	printf("%s\n", textstring); //Print the decrypted result.

	return 0;
}
