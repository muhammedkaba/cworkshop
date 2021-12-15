#include <stdio.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


double abso(double value){
	if(value < 0){
		return -value;
	}else{
		return value;
	}
	
}

int main(int argc, char *argv[]) {
	
	
	int xlimit,ylimit;
	int i,k;
	int plx,ply;
	char temp;
	char inputChar = ' ';

	scanf("%d %d",&xlimit,&ylimit);
	
	char inputWord[xlimit-2];
	char map[ylimit][xlimit];
	
	for(i = 0;i<ylimit;i++){
		for(k = 0;k<xlimit;k++){
			map[i][k] = ' ';
		}
	}
	
	for(i = 0;i<ylimit;i++){
		for(k = 0;k<xlimit;k++){
			if(i == 0){
				map[i][k] = '~';
			}
			if(k % (xlimit-1) == 0){
				map[i][k] = '|';
			}
		}
	}
	
	i = 1;
	
	while(strcmp(inputWord,"end") != 0){
		scanf("%c",&temp);
		scanf("%[^\n]s",inputWord);
		if(strcmp(inputWord,"end") != 0){
			for(k = 1;k<(xlimit-1);k++){
				map[i][k] = inputWord[k-1];
			}
			i++;
		}	
	}
	
	scanf("%d %d",&plx,&ply);
	map[ply][plx] = '_';
	
	
	
	
	for(i = 0;i<ylimit;i++){
		for(k = 0;k<xlimit;k++){
			printf("%c",map[i][k]);
			if(k == xlimit-1){
				printf("\n");
			}
		}
		if(i == (ylimit-1)){
			printf("\n");
		}
	}
	
	double xSpeed,ySpeed;
	double xPos,yPos;
	double forx;
	int count;
	int score = 0;

	
	while(scanf(" %c",&inputChar) != EOF){
		if(inputChar != 'q'){
			count = 0;
			xPos = (double)plx;
			yPos = (double)ply;
			scanf("%lf %lf",&xSpeed,&ySpeed);
			/*printf("%lf\n",ySpeed);
			printf("%lf\n",xSpeed);*/
			xSpeed = xSpeed/(-ySpeed);
			ySpeed = ySpeed/(-ySpeed);
			while(map[(int)yPos-1][(int)xPos] == ' '){
				/*printf("xPos = %lf\n",xPos);
				printf("yPos = %lf\n",yPos);*/
				for(forx = 0.01;forx<abso(xSpeed);forx+=(0.01)){
					/*printf("x : %lf\n",xPos);
					printf("y : %lf\n",yPos);*/
					if(xSpeed > 0){
						xPos += 0.01;
						if (xPos >= (xlimit-1.001)){
							xSpeed = -xSpeed;
						}
					}
					else{
						xPos -= 0.01;
						if(xPos <= 1.001){
							xSpeed = -xSpeed;
						}
					}
				}
				if(map[(int)yPos-1][(int)xPos] == ' '){
					yPos += -1;
				}
			}
			//printf("y midd : %lf",yPos);
			if(map[(int)yPos-1][(int)xPos] != ' '){
				//printf("y last: %lf\n",yPos);
				map[(int)yPos][(int)xPos] = inputChar;
				count++;
			}
			if(map[(int)yPos+1][(int)xPos] == inputChar) count++;
			if(map[(int)yPos-1][(int)xPos] == inputChar) count++;
			if(map[(int)yPos][(int)xPos+1] == inputChar) count++;
			if(map[(int)yPos][(int)xPos-1] == inputChar) count++;
			if(map[(int)yPos-1][(int)xPos+1] == inputChar) count++;
			if(map[(int)yPos-1][(int)xPos-1] == inputChar) count++;
			if(map[(int)yPos+1][(int)xPos+1] == inputChar) count++;
			if(map[(int)yPos+1][(int)xPos-1] == inputChar) count++;
			
			if(count >= 3){
				map[(int)yPos][(int)xPos] = ' ';
				if(map[(int)yPos+1][(int)xPos] == inputChar) map[(int)yPos+1][(int)xPos] = ' ';
				if(map[(int)yPos-1][(int)xPos] == inputChar) map[(int)yPos-1][(int)xPos] = ' ';
				if(map[(int)yPos][(int)xPos+1] == inputChar) map[(int)yPos][(int)xPos+1] = ' ';
				if(map[(int)yPos][(int)xPos-1] == inputChar) map[(int)yPos][(int)xPos-1] = ' ';
				if(map[(int)yPos-1][(int)xPos+1] == inputChar) map[(int)yPos-1][(int)xPos+1] = ' ';
				if(map[(int)yPos-1][(int)xPos-1] == inputChar) map[(int)yPos-1][(int)xPos-1] = ' ';
				if(map[(int)yPos+1][(int)xPos+1] == inputChar) map[(int)yPos+1][(int)xPos+1] = ' ';
				if(map[(int)yPos+1][(int)xPos-1] == inputChar) map[(int)yPos+1][(int)xPos-1] = ' ';
				if(count > 4){
					score += 100;
					printf("You got 100 points. Score: %d\n",score);
				}else{
					score += count*10;
					printf("You got %d points. Score: %d\n",count*10,score);
				}
			}
			/*printf("xPos = %lf\n",xPos);
			printf("yPos = %lf\n",yPos);*/
			for(i = 0;i<ylimit;i++){
				for(k = 0;k<xlimit;k++){
					printf("%c",map[i][k]);
					if(k == xlimit-1){
						printf("\n");
					}
				}
				if(i == ylimit-1){
					printf("\n");
				}
			}
		}else{
			printf("Game is over. Your score is %d!",score);
		}
	}
	
	
	
	return 0;
}