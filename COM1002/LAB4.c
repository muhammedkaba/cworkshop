#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	
	char inputLetter;
	int vowelTest;
	int numberTest;
	while(scanf("%c",&inputLetter) != EOF){
		vowelTest = 0;
		numberTest = 0;
		
		if(inputLetter == ' '){
			continue;
		}
		inputLetter = (inputLetter >= 'A' && inputLetter <= 'Z') ?
			(inputLetter - 'A' + 'a') : inputLetter;
		
		vowelTest = inputLetter == 'a' || inputLetter == 'e' || inputLetter == 'i' || inputLetter == 'o' || inputLetter == 'u';
		numberTest = inputLetter == '0' || inputLetter == '1' || inputLetter == '2' || inputLetter == '3' || inputLetter == '4' || inputLetter == '5'
		 || inputLetter == '6' || inputLetter == '7' || inputLetter == '8' || inputLetter == '9';
		
		
		if(vowelTest){
			printf("%c",inputLetter - 'a' + 'A');
		}
		else if(numberTest){
			
		}
		else{
			printf("%c",inputLetter);
		}
	}
	
	
	
	return 0;
}