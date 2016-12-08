/*
tree is:
2       4       9       10      11      12      32
 
Boundry of tree is:
11      9       4       2       10      32      12
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
};

void push(struct node** root, int val)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;
	if(*root == NULL)
	{
		*root = temp;
		return;
	}
	else if((*root)->data > val)
	{
		push(&(*root)->left,val);
	}
	else if((*root)->data < val)
	{
		push(&(*root)->right,val);
	}
}

void print(struct node* root)
{
	if(root)
	{
		print(root->left);
		printf("%d\t", root->data);
		print(root->right);
	}
}

int isLeaf(struct node* root)
{
	if(root == NULL)return 0;
	if(root->left == NULL && root->right == NULL)
		return 1;
	return 0;
}
void printLeaf(struct node* root)
{
	if(root == NULL)return;
	printLeaf(root->left);
	if(isLeaf(root))
	{
		printf("%d\t",root->data);
	}
	printLeaf(root->right);
}
void printLeftBoundry(struct node* root)
{
	if(root)
	{
		if(root->left)
		{
			printf("%d\t",root->data);
			printLeftBoundry(root->left);
		}
		else if(root->right)
		{
			printf("%d\t",root->data);
			printLeftBoundry(root->right);
		}
	}
	
}
void printRightBoundry(struct node* root)
{
	if(root)
	{
		if(root->right)
		{
			printRightBoundry(root->right);
			printf("%d\t",root->data);
		}
		else if(root->left)
		{
			printRightBoundry(root->left);
			printf("%d\t",root->data);
		}
	}
}
void printBoundry(struct node* root)
{
	if(root)
	{
		printf("%d\t");
		printLeftBoundry(root->left);
		printLeaf(root->left);
		printLeaf(root->right);
		printRightBoundry(root->right);
	}
}
int main()
{
	int maxlevel = 0;
	int h = 0;
	struct node* root = NULL;
	push(&root,11);
	push(&root,9);
	push(&root,12);
	push(&root,4);
	push(&root,32);
	push(&root,2);
	push(&root,10);
	printf("tree is:\n");
	print(root);
	printf("\n Boundry of tree is:\n");
	printBoundry(root);
	return 0;
}
