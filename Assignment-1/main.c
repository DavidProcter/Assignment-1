/*
 ============================================================================
 Name        : ENGG1003_Assessment 1_Main.c
 Author      : David Procter
 Version     : 001
 Copyright   : Copyright - David Procter
 Description : Cipher System
 ============================================================================
 */

int main(void) {

	int a=0;

	if (a==0) {
	rotationEncript ();
	a++;
	}
	if (a==1) {
	rotationDecript ();
	a++;
	}
	if (a==2) {
	substitutionEncript ();
	a++;
	}
	if (a==3) {
	substitutionDecript ();
	}
	return 0;

}
