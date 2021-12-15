#include <stdio.h>
#include <stdlib.h>

struct nodeFB
{
	int id;
	int age;
	struct nodeFB *next;
};

struct nodeGS
{
	int id;
	struct nodeGS *next;
};

struct newNodeFB
{
	int id;
	int age;
	struct newNodeGS *next;
};

struct newNodeGS
{
	int id;
	struct newNodeFB *next;
};

void insertFB(struct nodeFB** head, int id, int age){
	//printf("%d\n",&(*head));
	struct nodeFB *newNode = (struct nodeFB*)malloc(sizeof(struct nodeFB));
	newNode->id = id;
	newNode->age = age;
	newNode->next = NULL;
	if(*head == NULL || (*head)->id >= newNode->id){
		newNode->next = *head;
		*head = newNode;
		return;
	}
	struct nodeFB* current = *head;
	while (current->next != NULL && current->next->id < newNode->id) {
        current = current->next;
    }
 
    newNode->next = current->next;
    current->next = newNode;
}


void insertGS(struct nodeGS** head, int id){
	struct nodeGS *newNode = (struct nodeGS*)malloc(sizeof(struct nodeGS));
	newNode->id = id;
	newNode->next = NULL;
	if(*head == NULL || (*head)->id <= newNode->id){
		newNode->next = *head;
		*head = newNode;
		return;
	}
	struct nodeGS* current = *head;
	while (current->next != NULL && current->next->id > newNode->id) {
        current = current->next;
    }
 
    newNode->next = current->next;
    current->next = newNode;
}

void printFB(struct nodeFB* head)
{
	//printf("%d\n",&(*head));
    struct nodeFB* temp = head;
    while (temp != NULL)
    {
        printf("%d %d\n", temp->id,temp->age);
        temp = temp->next;
    }
    printf("\n");
}

void printGS(struct nodeGS* head)
{
    struct nodeGS* temp = head;
    while (temp)
    {
        printf("%d\n", temp->id);
        temp = temp->next;
    }
    printf("\n");
}

void createFinalList(struct newNodeFB** finalNode, struct nodeFB* fbNode, struct nodeGS* gsNode){
	struct nodeFB* tempFB = fbNode;
	struct nodeGS* tempGS = gsNode;
	//printf("%d\n",&(*finalNode));
	//struct newNodeFB* tempf = *finalNode;
	while(tempFB != NULL && tempGS != NULL){
		
		struct newNodeFB* fbnew = (struct newNodeFB*)malloc(sizeof(struct newNodeFB));
		fbnew->id = tempFB->id;
		fbnew->age = tempFB->age;
		//tempf = fbnew;
		//tempFB = tempFB->next;
		
		//struct newNodeFB* fbnext = (struct newNodeFB*)malloc(sizeof(struct newNodeFB));
		//fbnext->id = tempFB->next->id;
		//fbnext->age = tempFB->next->age;
		
		struct newNodeGS* gsnew = (struct newNodeGS*)malloc(sizeof(struct newNodeGS));
		gsnew->id = tempGS->id;
		//tempf->next = gsnew;
		//tempGS = tempGS->next;
		fbnew->next = gsnew;
		//gsnew->next = fbnext;
		(*finalNode) = fbnew;
		tempFB = tempFB->next;
		tempGS = tempGS->next;
		
		//printf("%d",tempf->id);
		//printf("%d\n",&(*finalNode));
		printf("%d %d\n%d\n",(*finalNode)->id, (*finalNode)->age,(*finalNode)->next->id);
		//(*finalNode)->next->next = fbnext;
		//(*finalNode)->next->next = (struct newNodeFB*)malloc(sizeof(struct newNodeFB));
		(*finalNode) = (*finalNode)->next->next;
	}
	//printf("%d",(*finalNode)->id);
}

void printAll(struct newNodeFB* newFB){
	/*struct newNodeFB* temp = newFB;
	//printf("%d",&newFB);
	while(temp != NULL){
		//printf("%d",&temp);
		printf("%d %d\n",temp->id,temp->age);
		printf("%d",temp->next->id);
		temp = temp->next->next;
	}*/
}

// You need to write all the function definitions to be used in this lab in this file.
// You can call other functions that you define from the mandatory functions.
// Do not make any changes to the main.c file.
// Upload the file function.h to the system as StudentNumber.h. 


