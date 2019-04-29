/*
 ============================================================================
 Name        : ENGG1003_Assessment 1_Rotation No Key Decryption
 Author      : David Procter
 Version     : 002
 Copyright   : Copyright - David Procter
 Description : Testing rotation decryption with no key.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nokeydecrypt(void) {

	FILE *rot_nokey_in;		//File pointer declaration
	FILE *rot_nokey_out;	//File pointer declaration

/*	Hard coded strings that can be used for testing
	char textstring[1536] = "MON MOTHMA: THE DATA BROUGHT TO US BY THE BOTHAN SPIES PINPOINTS THE EXACT LOCATION OF THE EMPEROR'S NEW BATTLE STATION. WE ALSO KNOW THAT THE WEAPON SYSTEMS OF THIS DEATH STAR ARE NOT YET OPERATIONAL. WITH THE IMPERIAL FLEET SPREAD THROUGHOUT THE GALAXY IN A VAIN EFFORT TO ENGAGE US, IT IS RELATIVELY UNPROTECTED. BUT MOST IMPORTANT OF ALL, WE'VE LEARNED THAT THE EMPEROR HIMSELF IS PERSONALLY OVERSEEING THE FINAL STAGES OF THE CONSTRUCTION OF THIS DEATH STAR. MANY BOTHANS DIED TO BRING US THIS INFORMATION" ;
	char textstring[1536] = "TVU TVAOTH: AOL KHAH IYVBNOA AV BZ IF AOL IVAOHU ZWPLZ WPUWVPUAZ AOL LEHJA SVJHAPVU VM AOL LTWLYVY'Z ULD IHAASL ZAHAPVU. DL HSZV RUVD AOHA AOL DLHWVU ZFZALTZ VM AOPZ KLHAO ZAHY HYL UVA FLA VWLYHAPVUHS. DPAO AOL PTWLYPHS MSLLA ZWYLHK AOYVBNOVBA AOL NHSHEF PU H CHPU LMMVYA AV LUNHNL BZ, PA PZ YLSHAPCLSF BUWYVALJALK. IBA TVZA PTWVYAHUA VM HSS, DL'CL SLHYULK AOHA AOL LTWLYVY OPTZLSM PZ WLYZVUHSSF VCLYZLLPUN AOL MPUHS ZAHNLZ VM AOL JVUZAYBJAPVU VM AOPZ KLHAO ZAHY. THUF IVAOHUZ KPLK AV IYPUN BZ AOPZ PUMVYTHAPVU." ;
	char textstring[1536] = "SJSFMPCRM WG O USBWIG. PIH WT MCI XIRUS O TWGV PM WHG OPWZWHM HC QZWAP O HFSS, WH KWZZ ZWJS WHG KVCZS ZWTS PSZWSJWBU HVOH WH WG GHIDWR. - OZPSFH SWBGHSWB" ;


*/

/*	Variables for use in the function.
	================================= */
	char textstring[1536];
	char outputstring1[1536];
	char outputstring2[1536];
	char outputstring3[1536];
	char outputstring4[1536];

	int b=0,c=0,e=65,f=0,g=0;
	int x=0,y=0,s=0;

	int key1=69; 	//key1 is 69 (ASCII for 'E')
	int key2=84; 	//key2 is 84 (ASCII for 'T')
	int key3=73; 	//key3 is 73 (ASCII for 'I')
	int key4=83; 	//key4 is 83 (ASCII for 'S')

/*	Open file and read in the encrypted text string
 	===============================================*/
	rot_nokey_in = fopen("rotation_nokey_in_text.txt", "r");	//Open the file in read mode
	fgets(textstring, 1536,(FILE*)rot_nokey_in);				//Read the text string from file
	fclose(rot_nokey_in);										//Close the file

// Sorry, still having problems working out the syntax for function arguments, so this function has duplicated sections.

/*	Copy the original string into strings that will be modified by the decryption sequence.
 	====================================================================================== */
	strupr(textstring);		//Make sure the text that was input is in upper case
	strcpy(outputstring1, textstring);
	strcpy(outputstring2, textstring);
	strcpy(outputstring3, textstring);
	strcpy(outputstring4, textstring);

/*	Finding the most popular letter in the text string.
	================================================== */
	for(int d=1 ; d<=26 ; d++ , e++){
		c=0;
		for (int a=0 ; textstring[a] != '\0' ; a++ ) {
			b=textstring[a];
			//printf("%d\n", b);
			if (b==e){
				c=c+1;
			}
			if (c>f){
				f=c;
				g=e;
			}
		}
	}

/*	Making a key based on the most popular letter.
	==============================================
 */
	key1=g-key1;	//-69 for ASCII letter 'E'
		if (key1<0) key1=key1+26;
	key2=g-key2;	//-84 for ASCII letter 'T'
		if (key2<0) key2=key2+26;
	key3=g-key3;	//-73 for ASCII letter 'I'
		if (key3<0) key3=key3+26;
	key4=g-key4;	//-83 for ASCII letter 'S'
		if (key4<0) key4=key4+26;

/*	Printing of the variables, used during testing, can be un-commented if wanting to see values.
	============================================================================================
	printf("C variable: %d\n",c); //last letter counted
	printf("F variable: %d\n",f); //largest letter count
	printf("G variable: %d\n",g); //Letter with the largest count
*/

/*	Decryption of the text using each of the keys (1-4)
	================================================= */
	for (int a=0 ; textstring[a] != '\0' ; a++ ) // Run a loop and decrypt the string.
		{
			x = textstring[a];
			if (x >= 65 && x <= 90) //Only decrypt the capital letters.
			{
				y=x-key1;
				if (y<65) // Subtraction to keep the result within capital letters
				{
					y=y+26;
				}
				outputstring1[a]=y; // Change the value of the letter
			}
		}

	y=0;
	for (int a=0 ; textstring[a] != '\0' ; a++ ) // Run a loop and decrypt the string.
		{
			x = textstring[a];
			if (x >= 65 && x <= 90) //Only decrypt the capital letters.
			{
				y=x-key2;
				if (y<65) // Subtraction to keep the result within capital letters
				{
					y=y+26;
				}
				outputstring2[a]=y; // Change the value of the letter
			}
		}

	y=0;
	for (int a=0 ; textstring[a] != '\0' ; a++ ) // Run a loop and decrypt the string.
		{
			x = textstring[a];
			if (x >= 65 && x <= 90) //Only decrypt the capital letters.
			{
				y=x-key3;
				if (y<65) // Subtraction to keep the result within capital letters
				{
					y=y+26;
				}
				outputstring3[a]=y; // Change the value of the letter
			}
		}

	y=0;
	for (int a=0 ; textstring[a] != '\0' ; a++ ) // Run a loop and decrypt the string.
		{
			x = textstring[a];
			if (x >= 65 && x <= 90) //Only decrypt the capital letters.
			{
				y=x-key4;
				if (y<65) // Subtraction to keep the result within capital letters
				{
					y=y+26;
				}
				outputstring4[a]=y; // Change the value of the letter
			}
		}

/*	Print to screen each version of the encrypted text.
	================================================== */
		printf("Decrypted text (E) 1: %s\n", outputstring1); //Print the decrypted result
		printf("Decrypted text (T) 2: %s\n", outputstring2); //Print the decrypted result
		printf("Decrypted text (I) 3: %s\n", outputstring3); //Print the decrypted result
		printf("Decrypted text (S) 4: %s\n", outputstring4); //Print the decrypted result

/*	Get the user to choose which encryption is correct.
	================================================== */
		ask_again:										//Goto label
		printf("\nWhich text string is correct?\n"); 	//Ask the question
		printf("Please enter a selection: "); 			//Request a selection from the user
		scanf("%d", &s);								//Get the selection from the user.

/*	Display the chosen text and write it and the key to the output file (each case for each key#).
	============================================================================================ */
		switch(s){
		case 1:
			system("cls");
			printf("\nText is: %s\n", outputstring1);		//Print to screen encrypted text string and key
			printf("Key is: %d\n\n", key1);
			printf("Saved to file: rotation_nokey_out_text.txt\n");		//Let user know output file has been written
			rot_nokey_out = fopen("rotation_nokey_out_text.txt", "w");	//Open the file in write mode
			fputs(outputstring1, rot_nokey_out);						//Write the text string to file
			fputs("\n", rot_nokey_out);									//Add a new line character to file
			fprintf(rot_nokey_out, "%d", key1);							//Write the key value to the file
			fclose(rot_nokey_out);										//Close the file
			break;
		case 2:
			system("cls");
			printf("\nText is: %s\n", outputstring2);
			printf("Key is: %d\n\n", key2);
			printf("Saved to file: rotation_nokey_out_text.txt\n");
			rot_nokey_out = fopen("rotation_nokey_out_text.txt", "w");
			fputs(outputstring2, rot_nokey_out);
			fputs("\n", rot_nokey_out);
			fprintf(rot_nokey_out, "%d", key2);
			fclose(rot_nokey_out);
			break;
		case 3:
			system("cls");
			printf("\nText is: %s\n", outputstring3);
			printf("Key is: %d\n\n", key3);
			printf("Saved to file: rotation_nokey_out_text.txt\n");
			rot_nokey_out = fopen("rotation_nokey_out_text.txt", "w");
			fputs(outputstring3, rot_nokey_out);
			fputs("\n", rot_nokey_out);
			fprintf(rot_nokey_out, "%d", key3);
			fclose(rot_nokey_out);
			break;
		case 4:
			system("cls");
			printf("\nText is: %s\n", outputstring4);
			printf("Key is: %d\n\n", key4);
			printf("Saved to file: rotation_nokey_out_text.txt\n");
			rot_nokey_out = fopen("rotation_nokey_out_text.txt", "w");
			fputs(outputstring4, rot_nokey_out);
			fputs("\n", rot_nokey_out);
			fprintf(rot_nokey_out, "%d", key4);
			fclose(rot_nokey_out);
			break;
		default:		//Error if user makes a selection outside of the 4 choices.
			printf("\nInvalid selection, please enter again (number between 1 - 4)\n");
			goto ask_again;
}

	return EXIT_SUCCESS;
}
