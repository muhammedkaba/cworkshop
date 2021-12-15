#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	
	char array[15][15];

	int i,j,k = 0;
	
	for(i=0;i<15;i++){
		for(j=0;j<15;j++){
			array[i][j] = ' ';
		}
	}

	for(i=0;i<15;i++){
		for(j=0;j<15;j++){
			scanf("%c ",&array[i][j]);
		}
	}
	
	char word[10]; 
	scanf("%s",word);
	int len = strlen(word);
	
	
	int index = 0;
	
	//printf("%c",*(word+index));
	int a,b;
	int c;
	int found = 0;
	
	
	//printf("%d",len);
	
	for(i=0;i<15;i++){
		index = 0;
		for(j=0;j<15;j++){
			if(array[i][j] == *(word+index)){
				index += 1;
			}
			if(index == len){
				found = 1;
				for(a=0;a<15;a++){
					for(b=0;b<15;b++){
						array[a][b] = '*';
					}
				}
				for(k = 0;k<len;k++){
					array[i][j-k] = *(word+(index-k-1));
					//printf("%d %d\n",k,len);
					//printf("%s",word);
				}
				break;
			}
		}
	}
	
	for(i=14;i>=0;i--){
		index = 0;
		for(j=14;j>=0;j--){
			if(array[i][j] == *(word+index)){
				index += 1;
			}
			if(index == len){
				found = 1;
				for(a=0;a<15;a++){
					for(b=0;b<15;b++){
						array[a][b] = '*';
					}
				}
				for(k = 0;k<len;k++){
					array[i][j+k] = *(word+(index-k-1));
				}
				break;
			}
		}
	}
	
	for(i=0;i<15;i++){
		index = 0;
		for(j=0;j<15;j++){
			if(array[j][i] == *(word+index)){
				index += 1;
			}
			if(index == len){
				found = 1;
				for(a=0;a<15;a++){
					for(b=0;b<15;b++){
						array[a][b] = '*';
					}
				}
				for(k = 0;k<len;k++){
					array[j-k][i] = *(word+(index-k-1));
				}
				break;
			}
		}
	}
	
	for(i=14;i>=0;i--){
		index = 0;
		for(j=14;j>=0;j--){
			if(array[j][i] == *(word+index)){
				index += 1;
			}
			if(index == len){
				found = 1;
				for(a=0;a<15;a++){
					for(b=0;b<15;b++){
						array[a][b] = '*';
					}
				}
				for(k = 0;k<len;k++){
					array[j+k][i] = *(word+(index-k-1));
				}
				break;
			}
		}
	}
	
	for(i=0;i<15;i++){
		for(j=0;j<15;j++){
			index = 0;
			if(array[i][j] == *(word+index)){
				index += 1;
				for(c = 1;c<len;c++){
					if(array[i+c][j+c] == *(word+index)){
						index++;
					}
				}
			}
			if(index == len){
				found = 1;
				for(a=0;a<15;a++){
					for(b=0;b<15;b++){
						array[a][b] = '*';
					}
				}
				for(k = 0;k<len;k++){
					array[i+k][j+k] = *(word+k);
				}
				break;
			}
		}
	}
	
	for(i=0;i<15;i++){
		for(j=0;j<15;j++){
			index = 0;
			if(array[i][j] == *(word+index)){
				//printf("%d %d\n",i,j);
				//printf("%d",index);
				index += 1;
				for(c = 1;c<len;c++){
					if(array[i+c][j-c] == *(word+index)){
						index++;
					}
				}
			}
			if(index == len){
				//printf("%d %d",i,j);
				found = 1;
				for(a=0;a<15;a++){
					for(b=0;b<15;b++){
						array[a][b] = '*';
					}
				}
				for(k = 0;k<len;k++){
					array[i+k][j-k] = *(word+k);
				}
				break;
			}
		}
		if(found) break;
	}
	
	for(i=0;i<15;i++){
		for(j=0;j<15;j++){
			index = 0;
			if(array[i][j] == *(word+index)){
				//printf("%d %d\n",i,j);
				//printf("%d",index);
				index += 1;
				for(c = 1;c<len;c++){
					if(array[i-c][j-c] == *(word+index)){
						index++;
					}
				}
			}
			if(index == len){
				//printf("%d %d",i,j);
				found = 1;
				for(a=0;a<15;a++){
					for(b=0;b<15;b++){
						array[a][b] = '*';
					}
				}
				for(k = 0;k<len;k++){
					array[i-k][j-k] = *(word+k);
				}
				break;
			}
		}
		if(found) break;
	}
	
	
	for(i=0;i<15;i++){
		for(j=0;j<15;j++){
			index = 0;
			if(array[i][j] == *(word+index)){
				//printf("%d %d\n",i,j);
				//printf("%d",index);
				index += 1;
				for(c = 1;c<len;c++){
					if(array[i-c][j+c] == *(word+index)){
						index++;
					}
				}
			}
			if(index == len){
				//printf("%d %d",i,j);
				found = 1;
				for(a=0;a<15;a++){
					for(b=0;b<15;b++){
						array[a][b] = '*';
					}
				}
				for(k = 0;k<len;k++){
					array[i-k][j+k] = *(word+k);
				}
				break;
			}
		}
		if(found) break;
	}
	
	//printf("\n%d",index);
	
	if(!found){
		for(a=0;a<15;a++){
			for(b=0;b<15;b++){
				array[a][b] = '*';
			}
		}
	}
	
	for(i=0;i<15;i++){
		for(j=0;j<15;j++){
			printf("%c",array[i][j]);
		}
		printf("\n");
	}
	
	return 0;
	
}