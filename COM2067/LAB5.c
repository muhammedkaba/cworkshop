#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


struct Employee{
	int id;
	int work;
	int end;
};

struct Employee stack[6];
int top = -1;

struct Customer{
	int id;
	int start;
	int work;
};

struct Job{
	int customerId;
	struct Employee employee;
	int start;
	int work;
	int end;
	int wait;
};

int IsEmpty() {
	if(top == -1) 
		return 1;
	else 
		return 0;
}

void PushToStack(struct Employee e){
	stack[++top] = e;
}

struct Employee PopFromStack(){
	if(!IsEmpty()) 
		return stack[top--];
	else {
		struct Employee e = {-1,0,0
		};
		return e;
	}
}

void SortStack(){
	struct Employee sort[6];
	
	int i,j;
	for(i = 0;i<6;i++){
		sort[i] = PopFromStack();
	}
	
	for(i = 1;i<7;i++){
		for(j = 0;j<6;j++){
			//printf("%d",sort[j].id);
			if(sort[j].id == i){
				PushToStack(sort[j]);
				//printf("a.");
			} 
		}
	}
}

int main()
{
	int id,work,start = 0;
	int i,j = 0;
	int time = 1;
	
	struct Customer c[30];
	struct Job jobs[30];
	for(i = 0;i<30;i++){
		c[i].id = -1;
		c[i].start = 0;
	}
	for(i = 0;i<30;i++){
		jobs[i].customerId = -1;
		jobs[i].wait = 0;
	}
	scanf("%d",&id);
	i = 0;
	while(id != -1){
		scanf("%d",&start);
		scanf("%d",&work);
		c[i].id = id;
		c[i].start = start;
		c[i].work = work;
		i++;
		scanf("%d",&id);
	}
	
	for(i = 0;i < 30;i++){
		if(c[i].id != -1){
			//printf("%d %d %d\n",c[i].id,c[i].start,c[i].work);
		}
	}
	
	struct Employee e;
	
	for(i = 0;i<6;i++){
		e.id = i+1;
		e.work = 0;
		PushToStack(e);
	}
	
	for(i = 0;i<6;i++){
		//printf("%d\n",PopFromStack().id);
	}
	
	while(time < 21){
		SortStack();
		for(i = 29;i>=0;i--){
			if(jobs[i].customerId != -1 && jobs[i].end == time){
				//printf("%d %d %d\n",jobs[i].end,time,jobs[i].employee.id);
				PushToStack(jobs[i].employee);
			}
		}
		for(i = 0;i<30;i++){
			if(c[i].start == time){
				if(!IsEmpty()){
				//printf("%d",time);
				jobs[i].customerId = c[i].id;
				//printf("popped\n");
				jobs[i].employee = PopFromStack();
				//printf("%d",PopFromStack().id);
				jobs[i].start = c[i].start;
				jobs[i].end = c[i].start + c[i].work;
				jobs[i].work = c[i].work;
				jobs[i].employee.work += jobs[i].work;
				//printf("%d\n",jobs[i].employee.id);
				//j++;
				}else{
					
					jobs[i].customerId = c[i].id;
					c[i].start++;
					jobs[i].wait += 1;
					//printf("%d\n",jobs[i].customerId);
				}
				
			}
		}
		
		time++;
	}
	
	for(i = 0;i < 30;i++){
		if(jobs[i].customerId != -1){
			printf("%d %d %d %d %d\n",jobs[i].customerId,jobs[i].employee.id,jobs[i].start,jobs[i].end,jobs[i].wait);
		}
	}
	
	//SortStack();
	
	printf("\n");
	
	
	
	for(i = 0;i<6;i++){
		e = PopFromStack();
		printf("%d %d\n",e.id,e.work);
	}
	
	/*for(i = 1;i < 7;i++){
		PushToStack(i);
	}
	for(i = 0;i<6;i++){
		printf("%d\n",PopFromStack());
	}*/
	
	return 0;

}
