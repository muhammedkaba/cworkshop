#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int a = 0;

struct node{
	struct node* parent;
    int value;
    int balance;
    struct node *left,*right;
    int height;
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
 
int max(int a, int b)
{
    return (a > b) ? a : b;
}
 
struct node* newNode(int value, struct node* parent)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->value = value;
    temp->parent = parent;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;
    return(temp);
}

int Balance(struct node* root)
{
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

void printLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if(level == 1 && root->parent != NULL){
        	if (a != 0) printf(" ");
        	printf("%d ", root->value);
        	if(root->value < root->parent->value){
        		printf("(%d L) ",root->parent->value);
			}
			if(root->value > root->parent->value){
        		printf("(%d R) ",root->parent->value);
			}
			printf("(%d B)", Balance(root));
			a++;
		}else if(root->parent == NULL && level == 1) printf("%d (%d B)", root->value, Balance(root));
    else if (level > 1) {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}
void printLevelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++){
    	a = 0;
    	printLevel(root, i);
    	printf("\n");
	} 
        
}

struct node* rightRotate(struct node* root)
{
    struct node* x = root->left;
    struct node* T2 = x->right;
 
    x->right = root;
    root->left = T2;
    x->parent = root->parent;
    root->parent = x;
    if(T2 != NULL) T2->parent = root;
 
    root->height = max(height(root->left), height(root->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    return x;
}
 
struct node* leftRotate(struct node* root)
{
    struct node* y = root->right;
    struct node* T2 = y->left;
 
    y->left = root;
    root->right = T2;
    y->parent = root->parent;
    root->parent = y;
    if(T2 != NULL) T2->parent = root;
    
 
    root->height = max(height(root->left), height(root->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
    
    return y;
}


 

 
struct node* insert(struct node* node, int value, struct node* parent)
{
    if (node == NULL) return(newNode(value,parent));
 	
    if (value < node->value){
        node->left  = insert(node->left, value, node);
	}
    	
    else if (value > node->value){
    	node->right = insert(node->right, value, node);
	}
        
 
    node->height = 1 + max(height(node->left), height(node->right));
 
 
    int balance = Balance(node);

    if (balance > 1 && value < node->left->value){
    	return rightRotate(node);
	}
        

    if (balance < -1 && value > node->right->value)
        return leftRotate(node);

    if (balance > 1 && value > node->left->value)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && value < node->right->value)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    return node;
}

void InOrder(struct node* root)
{
    if (root != NULL) {
        InOrder(root->left);
        printf("%d\n", root->value);
        InOrder(root->right);
    }
}

int main()
{
	struct node *tree = NULL;
	
	int val = 0;
	
	scanf("%d",&val);
	while(val != -1){
		tree = insert(tree,val,NULL);
		scanf("%d",&val);
	}
	InOrder(tree);
	printf("\n");
	//printf("height : %d\n",height(tree));
	printLevelOrder(tree);
	/*for(int i = 0; i < height(tree);i++){
		a = 0;
		printLevel(tree,i);
		printf("\n");
	}*/
	
	
	return 0;

}
