/*
 ============================================================================
 Name        : ENGG1003_Assessment 1_Substitution Decryption.c
 Author      : David Procter
 Version     : 005
 Copyright   : Copyright - David Procter
 Description : Substitution Decryption Function
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int substitutionDecrypt (void)
{
	FILE *sub_input_file;	//File pointer declaration
	FILE *sub_output_file;	//File pointer declaration

	int b=0, c=0;

	//puts("ENGG1003_Assessment 1_Substitution Decryption"); /* prints ENGG1003_Assessment 1_Rotation Encryption */

	char textstring [1024];	// = "LQ VW FAOIU UGIU IUOACD AI GLIW UX GCJOAZU CXR A CGGH UX HGJOAZU USG IUOACD" ;
	char keystring [30];	// = "LKJHGFDSAMNBVCXZPOIUYTREWQ" ;

	sub_input_file = fopen("substitution_text.txt", "r");	//Open the file in read mode
		fgets(textstring, 1024,(FILE*)sub_input_file);				//Read the text string from file
		fgets(keystring, 30,(FILE*)sub_input_file);					//Read the key string from file
		fclose(sub_input_file);										//Close the file

	strupr(textstring);		//Make sure the text string from the file is in upper case
	strupr(keystring);		//Make sure the key string from the file is in upper case

	printf("Text string to decrypt: %s", textstring); 	//Print the text string.
	printf("Decryption key: %s\n", keystring); 			//Print the key string.

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

	sub_output_file = fopen("substitution_text.txt", "w");	//Open the file in write mode
			fputs(textstring, sub_output_file);					//Write the text string to file
			//fputs("\n", sub_output_file);						//Add a new line character
			fputs(keystring, sub_output_file);					//Write the manual input key value to the file
			fclose(sub_output_file);							//Close the file

	printf("\nDecrypted text: %s\n", textstring); //Print the decrypted result.

	return 0;
}
