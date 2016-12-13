/*
1. Do simple traversal of the tree

2. Set a variable:Key as 0 for the root

// To add the elements of the same slope of diagonal

3.When recurse for the left child increase the key by 1

4.When recurse for the right child keep the key same.

5.Use some DS (array) to add the elements having the same key.

tree is:
2	4	9	10	11	12	32	
diagonal sum of tree is:
55	19	4	2
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

void sumDiagonal(int sum[], struct node* root, int level, int* total)
{
    if(root == NULL)	return;
    if(*total < level)
    {
    	*total = level;
    }
    sum[level] += root->data;
    sumDiagonal(sum, root->left, level+1, total);
    sumDiagonal(sum, root->right, level, total);
}

int main()
{
	struct node* root = NULL;
	int sum[10],i,total=1;
	push(&root,11);
	push(&root,9);
	push(&root,12);
	push(&root,4);
	push(&root,32);
	push(&root,2);
	push(&root,10);
	
	printf("tree is:\n");
	print(root);
	printf("\ndiagonal sum of tree is:\n");
	sumDiagonal(sum,root,1,&total);
	for(int i=1;i<=total;i++)
	{
		printf("%d\t",sum[i]);
	}
	printf("\n");
	return 0;
}
