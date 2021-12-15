#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	
	int item = 0;
	char areYouSure;
	float quantity = 0;
	float totalPrice = 0;
	float totalMoney = 0;
	float moneyAdded = 0;
	printf("****************Online Shopping*****************\n\
1- Apple	5$\n\
2- Orange	7$\n\
3- Tomate	9$\n\
4- Meat   	50$\n\
5- Chicken	25$\n\
6- Milk   	2.5$\n\
7- Yoghurt	4.2$\n\
8- Egg   	1.1$\n\
9- Lemonate	1.9$\n\
10-Coke  	2.3$\n\
************************************************\n");
	
	while(1){
		item = -2;
		quantity = 0;
		scanf("%d",&item);
		if(item == 1){
			scanf("%f",&quantity);
			printf("Please enter your choice and quantity(Enter '0' for exit, '-1' for total price): %.2f kg %s: %.2f$\n",quantity,"Apple",5*quantity);
			totalPrice += 5*quantity;
		}
		else if(item == 2){
			scanf("%f",&quantity);
			printf("Please enter your choice and quantity(Enter '0' for exit, '-1' for total price): %.2f kg %s: %.2f$\n",quantity,"Orange",7*quantity);
			totalPrice += 7*quantity;
		}
		else if(item == 3){
			scanf("%f",&quantity);
			printf("Please enter your choice and quantity(Enter '0' for exit, '-1' for total price): %.2f kg %s: %.2f$\n",quantity,"Tomate",9*quantity);
			totalPrice += 9*quantity;
		}
		else if(item == 4){
			scanf("%f",&quantity);
			printf("Please enter your choice and quantity(Enter '0' for exit, '-1' for total price): %.2f kg %s: %.2f$\n",quantity,"Meat",50*quantity);
			totalPrice += 50*quantity;
		}
		else if(item == 5){
			scanf("%f",&quantity);
			printf("Please enter your choice and quantity(Enter '0' for exit, '-1' for total price): %.2f kg %s: %.2f$\n",quantity,"Chicken",25*quantity);
			totalPrice += 25*quantity;
		}
		else if(item == 6){
			scanf("%f",&quantity);
			printf("Please enter your choice and quantity(Enter '0' for exit, '-1' for total price): %.2f lt %s: %.2f$\n",quantity,"Milk",2.5*quantity);
			totalPrice += 2.5*quantity;
		}
		else if(item == 7){
			scanf("%f",&quantity);
			printf("Please enter your choice and quantity(Enter '0' for exit, '-1' for total price): %.2f kg %s: %.2f$\n",quantity,"Yoghurt",4.2*quantity);
			totalPrice += 4.2*quantity;
		}
		else if(item == 8){
			scanf("%f",&quantity);
			printf("Please enter your choice and quantity(Enter '0' for exit, '-1' for total price): %.2f kg %s: %.2f$\n",quantity,"Egg",1.1*quantity);
			totalPrice += 1.1*quantity;
		}
		else if(item == 9){
			scanf("%f",&quantity);
			printf("Please enter your choice and quantity(Enter '0' for exit, '-1' for total price): %.2f lt %s: %.2f$\n",quantity,"Lemonate",1.9*quantity);
			totalPrice += 1.9*quantity;
		}
		else if(item == 10){
			scanf("%f",&quantity);
			printf("Please enter your choice and quantity(Enter '0' for exit, '-1' for total price): %.2f lt %s: %.2f$\n",quantity,"Coke",2.3*quantity);
			totalPrice += 2.3*quantity;
		}
		else if(item == -1){
			printf("Please enter your choice and quantity(Enter '0' for exit, '-1' for total price): -1\n");
			scanf("%f",&totalMoney);
			printf("Your total price is %.2f$. How much money you enter: %.2f$\n",totalPrice,totalMoney);
			while(totalPrice > totalMoney){
				scanf("%f",&moneyAdded);
				printf("Your money is not enough. You must add %.2f$ for total price. How much money you enter: %.2f$\n",totalPrice-totalMoney,moneyAdded);
				totalMoney += moneyAdded;
			}
			printf("Total price has been paid. Your remaining money %.2f$. \n",totalMoney-totalPrice);
			printf("Have a good day...\n");
		}
		else if(item == 0){
			scanf(" %c",&areYouSure);
			if(areYouSure == 'n'){
				printf("Please enter your choice and quantity(Enter '0' for exit, '-1' for total price): Are you sure (y/n) : n\n");
			}
			else{
				printf("Please enter your choice and quantity(Enter '0' for exit, '-1' for total price): Are you sure (y/n) : y\n");
				printf("Have a good day...\n");
				break;
			}
		}
		else{
			break;
		}
	}
	return 0;
}