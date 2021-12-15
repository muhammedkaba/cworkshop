#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int a = 0;

struct node {
	struct node *parent;
	int studentId;
	int grade;
	int level;
	struct node *left, *right;
};

int height(struct node* root) {
    if (!root)
        return 0;
    else {
        int left_height = height(root->left);
        int right_height = height(root->right);
        if (left_height >= right_height) return left_height + 1;
        else return right_height + 1;
    }
}

struct node* newNode(int id, int grade, int level, struct node* parent)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->parent = parent;
    temp->studentId = id;
    temp->grade = grade;
    temp->level = level;
    temp->left = temp->right = NULL;
    return temp;
}

void InOrder(struct node* root)
{
    if (root != NULL) {
        InOrder(root->left);
        printf("%d %d\n", root->studentId, root->grade);
        InOrder(root->right);
    }
}

struct node* insert(struct node* root, int id, int grade)
{
	int level = 0;
	
	if (root == NULL) return newNode(id,grade,level,NULL);
	
	level++;
	struct node* temp = root;
	while(grade > temp->grade && temp->right != NULL){
		temp = temp->right;
		level++;
	}
	while(grade < temp->grade && temp->left != NULL){
		temp = temp->left;
		level++;
	}
	if(grade < temp->grade){
		temp->left = newNode(id,grade,level,temp);
	}
	if(grade > temp->grade){
		temp->right = newNode(id,grade,level,temp);
	}
 
    return root;
}

void printLevel(struct node* root, int level){
	if (root != NULL) {
        printLevel(root->left,level);
        if(root->level == level && root->parent != NULL){
        	if (a != 0) printf(" ");
        	printf("%d %d ", root->studentId, root->grade);
        	if(root->grade < root->parent->grade){
        		printf("(%d L)",root->parent->grade);
			}
			if(root->grade > root->parent->grade){
        		printf("(%d R)",root->parent->grade);
			}
			a++;
		}else if(root->parent == NULL && root->level == level) printf("%d %d", root->studentId, root->grade);
        printLevel(root->right,level);
    }
}

int main()
{
	struct node *tree = NULL;
	
	int grade, id = 0;
	
	scanf("%d",&id);
	while(id != -1){
		scanf("%d",&grade);
		//printf("%d %d\n",id,grade);
		tree = insert(tree,id,grade);
		scanf("%d",&id);
	}
	//printf("%d",tree->grade);
	InOrder(tree);
	printf("\n");
	//printf("height : %d\n",height(tree));
	for(int i = 0; i < height(tree);i++){
		a = 0;
		printLevel(tree,i);
		printf("\n");
	}
	
	
	return 0;

}
