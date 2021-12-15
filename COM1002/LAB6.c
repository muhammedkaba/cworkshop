#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {
	
	char input;
	int inputIndex;
	int calculatedIndex = 0;
	int a = 100;
	int i = 0;
	int k = 0;
	int wss = 0;
	char charArray[a];
	int ended = 0;
	
	for(k = 0 ; k<a ; k++){
		charArray[k] = ' ';
	}
	
	
	while(1){
		if(ended == 0){
			scanf("%c",&input);
			if(input == ' '){
				ended = 1;
			}else{
				charArray [i] = input;
				i++;
			}
		}else{
			scanf("%d",&inputIndex);
			if(inputIndex == -1){
				break;
			}
			else if(inputIndex < a){
				calculatedIndex = 0;
				for(int m = 0;m<inputIndex;m++){
					if(charArray[m] == ' '){
						calculatedIndex++;
					}
				}
				charArray[inputIndex + calculatedIndex] = ' ';
			}
		}
	}
	
	for(int j = 0;j<a;j++){
		if(charArray[j] != ' '){
			printf("%c",charArray[j]);
		}
	}
	
	return 0;
}