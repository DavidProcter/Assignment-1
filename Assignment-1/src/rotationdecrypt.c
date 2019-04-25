/*
 ============================================================================
 Name        : ENGG1003_Assessment 1_Rotation Decryption.c
 Author      : David Procter
 Version     : 004
 Copyright   : Copyright - David Procter
 Description : Rotation Decryption Function
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int rotationDecrypt (void)
{
	FILE *rot_input_file;	//File pointer declaration
	FILE *rot_output_file;	//File pointer declaration

	int b=0;
	int c=0;
	int key=10;

	//puts("ENGG1003_Assessment 1_Rotation Decryption"); /* prints ENGG1003_Assessment 1_Rotation Encryption */

	char textstring [1024];	// = "KJ WI PSBCD DOCD CDBSXQ" ;

	rot_input_file = fopen("rotation_text.txt", "r");		//Open the file in read mode
			fgets(textstring, 1024,(FILE*)rot_input_file);		//Read the text string from file
			fscanf(rot_input_file, "%d", &key);					//Read the key from file
			fclose(rot_input_file);								//Close the file

			if (key <0 || key >26) {					//Check the input key is valid number range
				//system("cls");
				printf("\nKey value was invalid\n");	//Print to screen error message
				return 0;							//Turn around and do it again, back to the rotation menu
			}

	printf("Text string to decrypt: %s", textstring);  //Print the text string.
	printf("Decryption key: %d\n", key);  //Print the text string.


	for (int a=0 ; textstring[a] != '\0' ; a++ ) // Run a loop and encrypt the string.
	{
		b = textstring[a];
		if (b >= 65 && b <= 90) //Only encrypt the capital letters.
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

	rot_output_file = fopen("rotation_text.txt", "w");	//Open the file in write mode
	fputs(textstring, rot_output_file);						//Write the text string to file
	fputs("\n", rot_output_file);							//Add a new line character
	fprintf(rot_output_file, "%d", key);				//Write the manual output key value to the file
	fclose(rot_output_file);									//Close the file

	/*
	rot_start:
	rot_input_file = fopen("rotation_text_input.txt", "r");	//Open the file in read mode
	fgets(textstring, 1024,(FILE*)rot_input_file);			//Read the text string from file
	fscanf(rot_input_file, "%d", &key);						//Read the key from file
	fclose(rot_input_file);									//Close the file
	*/

	printf("\nDecrypted text: %s\n", textstring); //Print the decrypted result

	return 0;
}
