#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


struct Flight{
	int number;
	char departureCity[15];
	char arrivalCity[15];
	char departureDay[15];
	char departureTime[15];
	char arrivalDay[15];
	char arrivalTime[15];
	int passengerCount;
};

void addFlight(struct Flight flights[],struct Flight addedFlight,int index){
	flights[index] = addedFlight;
}

void printFlightInfo(struct Flight flightArray[],int flightCount){
	printf("\n");
	for(int i = 0;i<flightCount;i++){
		printf("%d %s %s %s %s %s %s\n",flightArray[i].number,flightArray[i].departureCity,flightArray[i].arrivalCity,
		flightArray[i].departureDay,flightArray[i].departureTime,flightArray[i].arrivalDay,flightArray[i].arrivalTime);
	}
}

void printWP(struct Flight flightArray[],int flightCount){
	printf("\n");
	for(int i = 0;i<flightCount;i++){
		printf("%d %s %s %s %s %s %s %d\n",flightArray[i].number,flightArray[i].departureCity,flightArray[i].arrivalCity,
		flightArray[i].departureDay,flightArray[i].departureTime,flightArray[i].arrivalDay,flightArray[i].arrivalTime,flightArray[i].passengerCount);
	}
}

struct Passenger{
	char firstName[15];
	char lastName[15];
	char departureCity[15];
	char arrivalCity[15];
	char departureDay[15];
	int flightNumber;
};

void printPassengerInfo(struct Passenger passenger){
	printf("%s %s %s %s %s",passenger.firstName,passenger.lastName,passenger.departureCity,passenger.arrivalCity,passenger.departureDay);
}

void addPassenger(struct Passenger passengerArray[],struct Passenger passengerAdded,int index){
	passengerArray[index] = passengerAdded;
}

int main(int argc, char *argv[]) {
	
	
	int i,k;
	
	int flightCount, passengerCount;
	scanf("%d",&flightCount);
	struct Flight *flightArray = malloc(flightCount * sizeof(struct Flight));
	
	
	struct Flight tempF;
	
	
	for(i=0;i<flightCount;i++){
		scanf("%d %s%s%s%s%s%s",&tempF.number,&tempF.departureCity,&tempF.arrivalCity,
		&tempF.departureDay,&tempF.departureTime,&tempF.arrivalDay,&tempF.arrivalTime);
		tempF.passengerCount = 0;
		addFlight(flightArray,tempF,i);
	}
	
	
	/*for(i = 0;i<flightCount;i++){
		printf("%d:\n%d\n%s\n%s\n%s\n%s\n%s\n%s\n",i,flightArray[i].number,flightArray[i].departureCity,flightArray[i].arrivalCity,
		flightArray[i].departureDay,flightArray[i].departureTime,flightArray[i].arrivalDay,flightArray[i].arrivalTime);
	}*/
	
	scanf("%d",&passengerCount);
	
	struct Passenger *passengerArray = malloc(passengerCount * sizeof(struct Passenger));
	
	struct Passenger tempP;
	
	for(i=0;i<passengerCount;i++){
		scanf("%s%s%s%s%s",&tempP.firstName,&tempP.lastName,
		&tempP.departureCity,&tempP.arrivalCity,&tempP.departureDay);
		addPassenger(passengerArray,tempP,i);
	}
	//printPassengerInfo(passengerArray,passengerCount);
	
	int found = 0;
	for(i = 0;i<passengerCount;i++){
		found = 0;
		for(int z = 0;z<flightCount;z++){
			if(strcmp(flightArray[z].departureCity,passengerArray[i].departureCity) == 0 && strcmp(flightArray[z].arrivalCity,passengerArray[i].arrivalCity) == 0 
			&& strcmp(flightArray[z].departureDay,passengerArray[i].departureDay) == 0 ){
				flightArray[z].passengerCount += 1;
				passengerArray[i].flightNumber = flightArray[z].number;
				found = 1;
			}
		}
		if(found == 0){
			printPassengerInfo(passengerArray[i]);
			printf(" No reservation\n");
		}
	}
	
	
	
	
	
	char inputWord[30];
	int fNumber;
	
	while(strcmp(inputWord,"END") != 0){
		k = 0;
		struct Flight *flights = malloc(flightCount * sizeof(struct Flight));
		scanf(" %s",inputWord);
		if(strcmp(inputWord,"END") == 0){
			break;
		}
		if(strcmp(inputWord,"search") == 0){
			scanf(" %s",inputWord);
			if(strcmp(inputWord,"flightNumber") == 0){
				scanf("%d",&fNumber);
				for(i = 0;i<flightCount;i++){
					if(fNumber == flightArray[i].number){
						flights[k] = flightArray[i];
						k++;
					}
				}
				if(k > 0){
					printFlightInfo(flights,k);
				}else{
					printf("\nNo flight with number %d\n",fNumber);
				}
			}
			if(strcmp(inputWord,"departure") == 0){
				scanf(" %s",inputWord);
				for(i = 0;i<flightCount;i++){
					if(strcmp(inputWord,flightArray[i].departureCity) == 0){
						flights[k] = flightArray[i];
						k++;
					}
				}
				if(k > 0){
					printFlightInfo(flights,k);
				}else{
					printf("\nNo departure city %s\n",inputWord);
				}
			}
			if(strcmp(inputWord,"arrival") == 0){
				scanf(" %s",inputWord);
				for(i = 0;i<flightCount;i++){
					if(strcmp(inputWord,flightArray[i].arrivalCity) == 0){
						flights[k] = flightArray[i];
						k++;
					}
				}
				if(k > 0){
					printFlightInfo(flights,k);
				}else{
					printf("\nNo arrival city %s\n",inputWord);
				}
			}
		}
		if(strcmp(inputWord,"print") == 0){
			scanf("%d",&fNumber);
			for(i = 0;i<flightCount;i++){
				if(fNumber == flightArray[i].number){
					flights[k] = flightArray[i];
					k++;
				}
			}
			if(k > 0){
				printWP(flights,k);
			}
		}
		if(strcmp(inputWord,"printwP") == 0){
			scanf("%d",&fNumber);
			for(i = 0;i<flightCount;i++){
				if(fNumber == flightArray[i].number){
					flights[k] = flightArray[i];
					k++;
				}
			}
			if(k > 0){
				printWP(flights,k);
			}
			for(int z = 0;z<k;z++){
				found = 0;
				for(i = 0;i<passengerCount;i++){
					if(strcmp(flights[z].departureCity,passengerArray[i].departureCity) == 0 && strcmp(flights[z].arrivalCity,passengerArray[i].arrivalCity) == 0 
					&& strcmp(flights[z].departureDay,passengerArray[i].departureDay) == 0 ){
						printf("%s %s\n",passengerArray[i].firstName,passengerArray[i].lastName);
					}
				}
			}
		}
		if(strcmp(inputWord,"printR") == 0){
			char firstName[15],lastName[15];
			scanf(" %s %s",firstName,lastName);
			for(i = 0;i<passengerCount;i++){
				if(strcmp(firstName,passengerArray[i].firstName) == 0 && strcmp(lastName,passengerArray[i].lastName) == 0){
					fNumber = passengerArray[i].flightNumber;
				}
			}
			for(i = 0;i<flightCount;i++){
				if(fNumber == flightArray[i].number){
					flights[0] = flightArray[i];
					k++;
				}
			}
			printf("\n%s %s %d %s %s %s %s %s %s\n",firstName,lastName,flights[0].number,flights[0].departureCity,flights[0].arrivalCity,flights[0].departureDay
			,flights[0].departureTime,flights[0].arrivalDay,flights[0].arrivalTime);
		}
		
		free(flights);
	}
	
	printf("\n");
	free(flightArray);
	
	
	return 0;
}