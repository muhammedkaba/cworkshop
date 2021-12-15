#include <stdio.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {
	
	char myArray[20][30];
	int pointArray[20];
	char searchArray[30][30];
	char inputWord[30];
	char empty[30] = "";
	int inputPoint;
	int ended = 0;
	int i = 0;
	int k = 0;
	
	for(i = 0;i<20;i++){
		strcpy(myArray[i],empty);
	}
	
	for(i = 0;i<30;i++){
		strcpy(searchArray[i],empty);
	}
	
	for(i = 0;i<20;i++){
		pointArray[i] = 0;
	}
	
	
	
	i = 0;
	
	while(scanf("%s",&inputWord) != EOF){
		if(ended == 1){
			strcpy(searchArray[i],inputWord);
			i++;
		}else{
			if(strcmp(inputWord,"END") == 0){
				ended = 1;
				i = 0;
			}else{
				strcpy(myArray[i],inputWord);
				scanf("%d",&inputPoint);
				pointArray[i] = inputPoint;
				i++;
			}
		}
	}
	
	
	for(i = 0;i<30;i++){
		for(k = 0;k<20;k++){
			if((strcmp(myArray[k],searchArray[i]) == 0) && (pointArray[k] != 0)){
				printf("%s %d\n",myArray[k],pointArray[k]);
				break;
			}
		}
	}
	
	
	return 0;
}