#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {
	
	char input;
	int x,y;
	int plx,ply;
	int fx,fy;
	int a,b;
	scanf("%d %d",&a,&b);
	int i,k;
	char charArray[a][b];
	int amountArray[a][b];
	int amount;
	int totalPoint;
	int ended = 0;
	int gameOver = 0;
	
	for(i = 0;i<a;i++){
		for(k = 0;k<b;k++){
			if(i == 0 || i % (a-1) == 0 || k == 0 || k % (b-1) == 0){
				charArray[i][k] = '*';
			}else{
				charArray[i][k] = ' ';
			}
		}
	}

	
	while(scanf(" %c",&input) != EOF){
		if(ended == 0){
			if(input == 's'){
				scanf("%d %d",&plx,&ply);
				charArray[plx][ply] = 'O';
			}
			if(input == 'f'){
				scanf("%d %d",&fx,&fy);
				charArray[fx][fy] = ' ';
			}
			if(input == '$'){
				scanf("%d %d",&x,&y);
				charArray[x][y] = '$';
				scanf("%d",&amount);
				amountArray[x][y] = amount;
			}
			if(input == 'b'){
				scanf("%d %d",&x,&y);
				charArray[x][y] = '*';
			}
			if(input == 'X'){
				scanf("%d %d",&x,&y);
				charArray[x][y] = 'X';
			}
			if(input == 'd'){
				ended = 1;
				for(i = 0;i<a;i++){
					for(k = 0;k<b;k++){
						printf("%c",charArray[i][k]);
						if(k == b-1 && i == a-1){
								printf("\n\n");
							}
						else if(k == b-1){
							printf("\n");
						}
					}
				}
			}
		}else{
			if(input == 'u'){
				if(charArray[plx-1][ply] == '*'){
					printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");
				}
				else if(charArray[plx-1][ply] == 'X'){
					printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
					for(i = 0;i<a;i++){
						for(k = 0;k<b;k++){
							printf("%c",charArray[i][k]);
							if(k == b-1 && i == a-1){
								printf("\n\n");
							}
							else if(k == b-1){
								printf("\n");
							}
						}
					}
					gameOver = 1;
					break;
				}
				else if(charArray[plx-1][ply] == '$'){
					printf("YOU GOT %d $.\n",amountArray[plx-1][ply]);
					totalPoint += amountArray[plx-1][ply];
					charArray[plx][ply] = ' ';	
					plx--;
					charArray[plx][ply] = 'O';
				}
				else{
					charArray[plx][ply] = ' ';	
					plx--;
					charArray[plx][ply] = 'O';
				}
			}
			if(input == 'd'){
				if(charArray[plx+1][ply] == '*'){
					printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");
				}
				else if(charArray[plx+1][ply] == 'X'){
					printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
					for(i = 0;i<a;i++){
						for(k = 0;k<b;k++){
							printf("%c",charArray[i][k]);
							if(k == b-1 && i == a-1){
								printf("\n\n");
							}
							else if(k == b-1){
								printf("\n");
							}
						}
					}
					gameOver = 1;
					break;
				}
				else if(charArray[plx+1][ply] == '$'){
					printf("YOU GOT %d $.\n",amountArray[plx+1][ply]);
					totalPoint += amountArray[plx+1][ply];
					charArray[plx][ply] = ' ';	
					plx++;
					charArray[plx][ply] = 'O';
				}
				else{
					charArray[plx][ply] = ' ';	
					plx++;
					charArray[plx][ply] = 'O';
				}	
			}
			if(input == 'r'){
				if(charArray[plx][ply+1] == '*'){
					printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");
				}
				else if(charArray[plx][ply+1] == 'X'){
					printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
					for(i = 0;i<a;i++){
						for(k = 0;k<b;k++){
							printf("%c",charArray[i][k]);
							if(k == b-1 && i == a-1){
								printf("\n\n");
							}
							else if(k == b-1){
								printf("\n");
							}
						}
					}
					gameOver = 1;
					break;
				}
				else if(charArray[plx][ply+1] == '$'){
					printf("YOU GOT %d $.\n",amountArray[plx][ply+1]);
					totalPoint += amountArray[plx][ply+1];
					charArray[plx][ply] = ' ';	
					ply++;
					charArray[plx][ply] = 'O';
				}
				else{
					charArray[plx][ply] = ' ';	
					ply++;
					charArray[plx][ply] = 'O';
				}	
			}
			if(input == 'l'){
				if(charArray[plx][ply-1] == '*'){
					printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");
				}
				else if(charArray[plx][ply-1] == 'X'){
					printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
					for(i = 0;i<a;i++){
						for(k = 0;k<b;k++){
							printf("%c",charArray[i][k]);
							if(k == b-1 && i == a-1){
								printf("\n\n");
							}
							else if(k == b-1){
								printf("\n");
							}
						}
					}
					gameOver = 1;
					break;
				}
				else if(charArray[plx][ply-1] == '$'){
					printf("YOU GOT %d $.\n",amountArray[plx][ply-1]);
					totalPoint += amountArray[plx][ply-1];
					charArray[plx][ply] = ' ';	
					ply--;
					charArray[plx][ply] = 'O';
				}
				else{
					charArray[plx][ply] = ' ';	
					ply--;
					charArray[plx][ply] = 'O';
				}
			}
			if(input == 'q'){
				break;
			}
			if(charArray[plx][ply] == charArray[fx][fy]){
				printf("CONGRATS! YOU GOT %d BONUS:)\n",totalPoint);
				for(i = 0;i<a;i++){
					for(k = 0;k<b;k++){
						printf("%c",charArray[i][k]);
						if(k == b-1 && i == a-1){
							printf("\n\n");
						}
						else if(k == b-1){
							printf("\n");
						}
					}
				}
				break;
			}else{
				for(i = 0;i<a;i++){
					for(k = 0;k<b;k++){
						printf("%c",charArray[i][k]);
						if(k == b-1 && i == a-1){
							printf("\n\n");
						}
						else if(k == b-1){
							printf("\n");
						}
					}
				}
			}
		}
	}
	
	if(charArray[plx][ply] != charArray[fx][fy] && gameOver == 0){
		printf("YOU COULD NOT REACH THE FINAL POSITION :(\nGAME IS OVER!\n");
		for(i = 0;i<a;i++){
			for(k = 0;k<b;k++){
				printf("%c",charArray[i][k]);
				if(k == b-1 && i == a-1){
					printf("\n\n");
				}
				else if(k == b-1){
					printf("\n");
				}
			}
		}
	}
	

	
	
	
	return 0;
}