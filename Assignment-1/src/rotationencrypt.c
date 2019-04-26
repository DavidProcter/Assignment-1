/*
 ============================================================================
 Name        : ENGG1003_Assessment 1_Rotation Encryption.c
 Author      : David Procter
 Version     : 107
 Copyright   : Copyright - David Procter
 Description : Rotation Encryption Function
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rotationEncrypt (void)
{
	FILE *rot_input_file;	//File pointer declaration
	FILE *rot_output_file;	//File pointer declaration

	int b=0, c=0, key=10;

	char textstring [1024];	//Declaration for text string array

	rot_input_file = fopen("rotation_text.txt", "r");	//Open the file in read mode
		fgets(textstring, 1024,(FILE*)rot_input_file);	//Read the text string from file
		fscanf(rot_input_file, "%d", &key);				//Read the key from file
		fclose(rot_input_file);							//Close the file

		if (key <0 || key >26) {					//Check the input key is valid number range
			printf("\nKey value was invalid\n");	//Print to screen error message
			return 0;								//Turn around and do it again, back to the rotation menu
		}

	strupr(textstring);		//Make sure the text string from the file is in upper case

	printf("Text to encrypt: %s", textstring);  //Print the text string.
	printf("Encryption key: %d\n", key);  		//Print the key.

	for (int a=0 ; textstring[a] != '\0' ; a++ ) // Run a loop and encrypt the string until the NULL at the end of the string is reached.
	{
		b = textstring[a];			//b is assigned the integer value of the letter at that index
		if (b >= 65 && b <= 90) 	//Only encrypt the capital letters.
		{
			c=b+key;	//Add the key value to the letter value
			if (c>90) 	//If the added value goes higher than upper case Z, subtraction required
			{
				c=c-26;	// Subtraction to keep the result within capital letters
			}

			textstring[a]=c; //Assign the new encrypted value of the letter
		}
	}

	rot_output_file = fopen("rotation_text.txt", "w");	//Open the file in write mode
	fputs(textstring, rot_output_file);					//Write the encrypted text string to the file
	fputs("\n", rot_output_file);						//Add a new line character
	fprintf(rot_output_file, "%d", key);				//Write the manual output key value to the file
	fclose(rot_output_file);							//Close the file

	/*
	rot_start:
	rot_input_file = fopen("rotation_text_input.txt", "r");	//Open the file in read mode
	fgets(textstring, 1024,(FILE*)rot_input_file);			//Read the text string from file
	fscanf(rot_input_file, "%d", &key);						//Read the key from file
	fclose(rot_input_file);									//Close the file
	*/

	printf("\nEncrypted text: %s\n", textstring); //Print the encrypted result

	return 0;
}
