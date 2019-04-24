/*
 ============================================================================
 Name        : ENGG1003_Assessment 1_Main.c
 Author      : David Procter
 Version     : 002
 Copyright   : Copyright - David Procter
 Description : Cipher System
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rotationEncrypt (void);
int rotationDecrypt (void);
int substitutionEncrypt (void);
int substitutionDecrypt (void);

int main(void) {

	FILE *rot_input_file;	//File pointer declaration
	FILE *sub_input_file;	//File pointer declaration

	int a=0, b=0, c=0;		//Declare variables used in the menus
	int key_input;			//Variable for collecting the rotation key value (manual input)
	int key=0;				//Variable for the value of the rotation encryption key (file value)

	char keystring_in[30];	//Character array for substitution key (manual input, this is written to the file)
	char keystring[30];		//Character array for substitution key (red from the value)
	char textinput[1024];	//Text input from user (for manual input this is written to the file)
	char textstring[1024];	//Character array for the text string (red from the value)
	char error[32];			//This string is to collect the unresolved line feed left from the scanf function.

	/*
	============================================================================
			Main Menu
	============================================================================
	 */

	system("cls");												//Clear the terminal  screen
	menu:														//Tag for the goto function, turn around and do it again
	printf("\nTitle  : Cipher Encryption and Decryption\n");	//Title screen
	printf("Class  : ENGG1003 2019_S1\n");						//Me
	printf("Author : David Procter, C3333199\n");

	printf("Please select from the following Menu\n");						//Menu instruction
	printf("1 for Rotation Cipher\n2 for Substitution Cipher\n9 for EXIT\n\n");	//Menu choices
	printf("Please enter selection: ");	//Request selection from the user
	scanf("%d", &a);					//Get the choice and store it.
	system("cls");						//Clear the terminal screen

	switch (a){						//Menu selection choices
		case 1:
			//printf("Rotation");
			goto rot_menu;				//Go to the rotation cipher menu
			break;
		case 2:
			//printf("Substitution");
			goto sub_menu;				//Go to the substitution menu
			break;
		case 9:
			printf("EXIT");				//Exit when selected
			break;
		default:						//Incorrect selection asks again
			system("cls");
			printf("\nPlease enter a value of 1,2 or 9\n\n");
			goto menu;
	}
	printf("EXIT from the main menu level");	//Text line to identify exit point when testing
	return 0;

	/*
	============================================================================
			Rotation cipher menu & manual input
	============================================================================
	 */

	rot_menu:								//Tag for the goto function
	printf("\nRotation Cipher Menu\n");		//Rotation cipher menu header
	printf("Please select from the following Menu\n");	//List the choices
	printf("1 to manually input Text and Key on screen\n2 to get Text and Key from file\n9 for return to Main Menu\n\n");
	printf("Please enter selection: ");			//Ask for selection
	scanf("%d", &b);							//Store the selection

	switch (b){							//Switch case for menu selection
		case 1:
			printf("Manual Input\n");
			goto rot_manual;				//Go to manual input for text string and key
			break;
		case 2:
			printf("File Input\n");
			goto rot_start;					//Skip past manual input for file input encryption
			break;
		case 9:
			printf("EXIT");
			system("cls");					//Return back to the main menu
			goto menu;
			break;
		default:
			system("cls");
			printf("\nPlease enter a value of 1,2 or 9\n\n");
			goto rot_menu;					//Go back and ask for a valid selection
	}
	printf("EXIT from the rotation menu level");	//Text line to identify exit point when testing
	return 0;

	rot_manual:						//Tag for the goto function (incorrect key value entered)
	printf("Enter text string: ");	//Ask for string input
	gets(error);					//Google is wise, scanf leaves an unresolved line feed in the system that causes problems with gets.
	gets(textinput);							//put string in char array
	keyin : printf("Enter number: ");			//Ask for the key value
	scanf("%d", &key_input);					//Store the manual input key

	if (key_input <0 || key_input >26) {					//Check the input key is valid number range
		//system("cls");
		printf("\nKey value must be between 0 and 26\n");	//Print to screen error message
		goto keyin ;										//Turn around and do it again
	}
	strupr(textinput);		//Make sure the text that was input is in upper case

	printf("Text is: %s\n", textinput);		//Read back of entries for text string and key
	printf("Number is: %d\n\n", key_input);

	rot_input_file = fopen("rotation_text_input.txt", "w");	//Open the file in write mode
	fputs(textinput, rot_input_file);						//Write the text string to file
	fputs("\n", rot_input_file);							//Add a new line character
	fprintf(rot_input_file, "%d", key_input);				//Write the manual input key value to the file
	fclose(rot_input_file);									//Close the file

	rot_start: rot_input_file = fopen("rotation_text_input.txt", "r");	//Open the file in read mode
	fgets(textstring, 1024,(FILE*)rot_input_file);			//Read the text string from file
	fscanf(rot_input_file, "%d", &key);						//Read the key from file
	fclose(rot_input_file);									//Close the file

	if (key <0 || key >26) {					//Check the input key is valid number range
		//system("cls");
		printf("\nKey value was invalid\n");	//Print to screen error message
		goto rot_menu ;							//Turn around and do it again, back to the rotation menu
	}

	strupr(textstring);

	printf("File text: %s\n", textstring);		//Print what was read from the file
	printf("File key: %d\n", key);

	puts("ENGG1003_Assessment 1_Menu - Rotation End"); /* prints ENGG1003_Assessment 1_Menu */

	return 0;

	/*
	============================================================================
			Substitution cipher menu & manual input
	============================================================================
	 */

	sub_menu:
	printf("\nSubstitution Cipher Menu\n");		//Substitution cipher menu header
	printf("Please select from the following Menu\n");	//List the choices
	printf("1 to manually input Text and Key on screen\n2 to get Text and Key from file\n9 for return to Main Menu\n\n");
	printf("Please enter selection: ");			//Ask for selection
	scanf("%d", &c);							//Store the selection

	switch (c){							//Switch case for menu selection
	case 1:
		printf("Manual Input\n");
		goto sub_manual;				//Go to manual input for text string and key
		break;
	case 2:
		printf("File Input\n");
		goto sub_start;					//Skip past manual input for file input encryption
		break;
	case 9:
		printf("EXIT");
		system("cls");					//Return back to the main menu
		goto menu;
		break;
	default:
		system("cls");
		printf("\nPlease enter a value of 1,2 or 9\n\n");
		goto sub_menu;					//Go back and ask for a valid selection
	}
	return 0;

	sub_manual:
	printf("Enter text string: ");	//Ask for string input
	gets(error);					//Google is wise, scanf leaves an unresolved line feed in the system that causes problems with gets.
	gets(textinput);							//put string in char array
	printf("Enter substitution key: ");			//Ask for the key value
	gets(keystring_in);					//Store the manual input key

	strupr(textinput);		//Make sure the text that was input is in upper case
	strupr(keystring_in);		//Make sure the key text that was input is in upper case

	printf("Text input is: %s\n", textinput);		//Read back of entries for text string and key
	printf("Key input is: %s\n\n", keystring_in);

	sub_input_file = fopen("substitution_text_input.txt", "w");	//Open the file in write mode
	fputs(textinput, sub_input_file);							//Write the text string to file
	fputs("\n", sub_input_file);								//Add a new line character
	fputs(keystring_in, sub_input_file);										//Write the manual input key value to the file
	fclose(sub_input_file);										//Close the file

	sub_start:
	sub_input_file = fopen("substitution_text_input.txt", "r");	//Open the file in read mode
	fgets(textstring, 1024,(FILE*)sub_input_file);				//Read the text string from file
	fgets(keystring, 30,(FILE*)sub_input_file);					//Read the key string from file
	fclose(sub_input_file);										//Close the file

	strupr(textinput);		//Make sure the text string from the file is in upper case
	strupr(keystring);		//Make sure the key string from the file is in upper case


	printf("File text: %s\n", textstring);		//Print what was read from the file
	printf("File key: %s\n", keystring);		//Print what was read from the file

	puts("ENGG1003_Assessment 1_Menu - Substitution End"); /* prints ENGG1003_Assessment 1_Menu */

	return EXIT_SUCCESS;
}
