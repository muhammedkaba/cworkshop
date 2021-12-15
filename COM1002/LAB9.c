#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {
	
	
	int count;
	char inputWord[30];
	scanf("%d",&count);
	int i,k;
	
	char** inputs = (char**) malloc(count * sizeof(inputWord));
	
	for (i = 0; i < count; i++){
    	inputs[i] = (char*) malloc (sizeof(char) * 30);
	}
	
	
	for(i = 0;i<count;i++){
		scanf(" %s",inputs[i]);
	}
	

	//printf("----\n");
	
	
	for(i = 0;i<count;i++){
		//strcpy(tempWord,inputs[i]);
		//printf("--\n");
		//printf("%s\n",inputs[i]);
		for(k = 0;k<strlen(inputs[i]);k++){
			if(inputs[i][k] < 'a'){
				inputs[i][k] = inputs[i][k] - 'A' + 'a';
			}
		}
	}
	
	for(k = 0;k<26;k++){
		for(i = 0;i<count;i++){
			if(inputs[i][0] == ('z'-k)){
				printf("%s\n",inputs[i]);
			}
		}
	}

	
	
	return 0;
}