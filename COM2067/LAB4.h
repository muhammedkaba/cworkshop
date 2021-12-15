#include <stdio.h>
#include <stdlib.h>

struct nodeClass
{
	int classID;
	double classMidtermAverage;
	struct nodeClass *next;
	struct nodeStudent *studentPtr;
};

struct nodeStudent
{
	int studentID;
	int midterm;
	struct nodeStudent *next;
};

void insert(struct nodeClass** head, int id, int midterm){
	//printf("girdi\n");
	if(*head == NULL){
		for(int a = 0;a<4;a++){
			struct nodeClass* temp = (struct nodeClass*)malloc(sizeof(struct nodeClass));
			temp->classID = 4-a;
			temp->next = *head;
			*head = temp;
		}
	}
	//printf("%d\n",(*head)->classID);
	//printf("1\n");
	int i = (id/1000)/11-6;
	struct nodeClass* currentClass = *head;
	//printf("1\n");
	struct nodeStudent* newNode = (struct nodeStudent*)malloc(sizeof(struct nodeStudent));
	newNode->midterm = midterm;
	newNode->studentID = id;
	//printf("1\n");
	for(i;i>0;i--){
		currentClass = currentClass->next;
	}
	//printf("2\n");
	if(currentClass->studentPtr == NULL || currentClass->studentPtr->midterm < newNode->midterm || (currentClass->studentPtr->midterm == newNode->midterm && 
	currentClass->studentPtr->studentID > newNode->studentID)){
		newNode->next = currentClass->studentPtr;
		currentClass->studentPtr = newNode;
		return;
	}
	//printf("2\n");
	struct nodeStudent* currentStudent = currentClass->studentPtr;
	//printf("2\n");
	while(currentStudent->next != NULL && currentStudent->next->midterm > newNode->midterm){
		currentStudent = currentStudent->next;
	}
	//printf("3\n");
	while(currentStudent->next != NULL && currentStudent->next->midterm == newNode->midterm && currentStudent->next->studentID < newNode->studentID){
		currentStudent = currentStudent->next;
	}
	newNode->next = currentStudent->next;
	currentStudent->next = newNode;
}

void computeClassAverage(struct nodeClass* head){
	struct nodeClass* ptr = head;
	while(ptr != NULL){
		float sum = 0;
		float a = 0;
		struct nodeStudent* sptr = ptr->studentPtr;
		while(sptr != NULL){
			a++;
			sum += sptr->midterm;
			sptr = sptr->next;
		}
		ptr->classMidtermAverage = sum/a;
		ptr = ptr->next;
	}
}

void printAll(struct nodeClass* head){
	struct nodeClass* ptr = head;
	while(ptr != NULL){
		struct nodeStudent* sptr = ptr->studentPtr;
		printf("%d %.2f\n",ptr->classID,ptr->classMidtermAverage);
		while(sptr != NULL){
			printf("%d %d\n",sptr->studentID,sptr->midterm);
			sptr = sptr->next;
		}
		ptr = ptr->next;
	}
}

// You must write all the function definitions to be used in this lab into this file.
// You may also write other functions that may be called from our functions.
// Do not make any changes to the main.c file.
// Upload function.h file to the system as StudentNumber.h.



