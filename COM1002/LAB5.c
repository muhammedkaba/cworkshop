#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int ifPrime(int number){
	int dividerCounter = 0;
	int i = 0;
	for(i = 1;i<number;i++){
		if(number%i==0){
			dividerCounter++;
		}	
	}
	if(dividerCounter == 1){
		return 1;
	}
	else{
		return 0;
	}
}

int summationOfDigits(int number){
	int sum = 0;
	while(number > 0){
		sum += number%10;
		number /= 10;
	}
	return sum;
}

int main(int argc, char *argv[]) {
	
	int number = 0;
	int sumOfDigits = 0;
	int integerCounter = 0;
	int primeCounter = 0;
	
	while(scanf("%d",&number)!=EOF){
		if(ifPrime(number)){
			sumOfDigits = summationOfDigits(number);
			printf("%d ",sumOfDigits);
			primeCounter++;
		}
		integerCounter++;
	}
	if(primeCounter == 0){
		printf("0 ");
	}
	printf("%d",integerCounter);
	
	return 0;
}