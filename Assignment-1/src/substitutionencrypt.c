/*
 ============================================================================
 Name        : ENGG1003_Assessment 1_Substitution Encryption.c
 Author      : David Procter
 Version     : 005
 Copyright   : Copyright - David Procter
 Description : Substitution Encryption Function
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int substitutionEncrypt (void)
{
	FILE *sub_input_file;	//File pointer declaration
	FILE *sub_output_file;	//File pointer declaration

	int b=0;
	int x=0,y=0,z=0;

	//puts("ENGG1003_Assessment 1_Sudstitution Encryption"); /* prints ENGG1003_Assessment 1_Rotation Encryption */

	char textstring [1024];	// = "AZ MY FIRST TEST STRING IS EASY TO ENCRIPT NOW I NEED TO DECRIPT THE STRING" ;
	char keystring [30];	//= "LKJHGFDSAMNBVCXZPOIUYTREWQ" ;

	sub_input_file = fopen("substitution_text.txt", "r");	//Open the file in read mode
		fgets(textstring, 1024,(FILE*)sub_input_file);				//Read the text string from file
		fgets(keystring, 30,(FILE*)sub_input_file);					//Read the key string from file
		fclose(sub_input_file);										//Close the file

	strupr(textstring);		//Make sure the text string from the file is in upper case
	strupr(keystring);		//Make sure the key string from the file is in upper case

/*	Check the key string is a valid set of upper case alphabet with no missing or double characters
	==============================================================================================*/
		for (x=0 ; keystring[x] != '\0' ; x++ ) // Run loop and sum the string.
			{
				y = y + keystring[x];
			}
		z=y/x;
		/*Prints used during testing
		printf("Keystring sum: %d\n", y);
		printf("Keystring count: %d\n", x);
		printf("Keystring avg: %d\n", z);*/
		if (y==2015 && x==26 && z==77){
			printf("Keystring is valid\n");
		} else {
			printf("\nKeystring is invalid\nPlease return and re-enter\n\n");
			goto end_message_1 ;
		}

/*Run the encryption and output to screen and file
=================================================*/

	printf("Text to encrypt: %s", textstring);  //Print the text string.
	printf("Encryption key: %s\n", keystring);  //Print the key.

	for (int a=0 ; textstring[a] != '\0' ; a++ ) // Run a loop and encrypt the string.
	{
		b = textstring[a];
		if (b >= 65 && b <= 90) //Only encrypt the capital letters.
		{
			b=b-65;
			textstring[a] = keystring[b];
		}
	}

	sub_output_file = fopen("substitution_text.txt", "w");	//Open the file in write mode
		fputs(textstring, sub_output_file);					//Write the text string to file
		//fputs("\n", sub_output_file);						//Add a new line character
		fputs(keystring, sub_output_file);					//Write the manual input key value to the file
		fclose(sub_output_file);							//Close the file

	printf("\nEncrypted text: %s\n", textstring); //Print the encrypted result
	return 0;

	end_message_1:
	//printf("Keystring is bad, go do it again\n");
	return 0;
}
