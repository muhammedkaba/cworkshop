#include <stdio.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


char* smallLetter(char arg[15]){
	return arg;
}

int main(int argc, char *argv[]) {
	
	char patients[100][15];
	char bloodTypes[100][5];
	char charToFind = ' ';
	char charToSearch = ' ';
	char inputWord[15];
	char inputBlood[5];
	
	int count = 0;
	int wordCount = 0;
	int k = 0;
	int i = 0;
	
	
	while(1){
		scanf("%s", inputWord);
		if(strcmp(inputWord,"start") != 0){
			strcpy(patients[k], inputWord);
			scanf("%s", inputWord);
			strcpy(bloodTypes[k], inputWord);
			k++;
		}else{
			break;
		}
		
	}
	
	char tempChar;
	int found = 0;
	while(strcmp(inputWord,"end") != 0){
		scanf("%s", inputWord);
		if(strcmp(inputWord,"end") == 0){
			break;
		}
		found = 0;
		for(k = 0;k < 100;k++){
			if(stricmp(inputWord,patients[k]) == 0){
				printf("%s %s",strlwr(patients[k]),bloodTypes[k]);
				found = 1;
			}
		}
		if(found == 0){
			printf("%s 0+",strlwr(inputWord));
		}
		printf("\n");
		/*for(k = 0;k < 100;k++){
			count = 0;
			wordCount = 0;
			for(i = 0;i<15;i++){
				if(inputWord[i] < 'a'){
					charToFind = inputWord[i] - 'A' + 'a';
				}else{
					charToFind = inputWord[i];
				}
				if(patients[k][i] < 'a'){
					charToSearch = patients[k][i] - 'A' + 'a';
				}else{
					charToSearch = patients[k][i];
				}
				if(patients[k][i] != ' '){
					wordCount++;
				}
				if(charToFind == charToSearch) count++;
			}
			if(count == wordCount){
				printf("%s %s",patients[k],bloodTypes[k]);
			}
		}*/
	}
	
	/*printf("%d %d",count,wordCount);
	if(count == wordCount) printf("\nesit");*/
	
	
	return 0;
}