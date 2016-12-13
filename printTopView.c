/*
Find the top element in all the vertical lines
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

void findMinMax(struct node* root, int* min, int* max, int hd)
{
	if(root == NULL)return;
	if(hd < *min) *min = hd;
	else if(hd > *max) *max = hd;
	findMinMax(root->left,min,max,hd-1);
	findMinMax(root->right,min,max,hd+1);
}

void topView(struct node* root, int line, int hd, int first)
{
	if(root == NULL) return;
	if(hd == line)
	{
		if(first < line)
		{
			printf("%d\t",root->data);
			first = line;
		}
	}
	topView(root->left,line,hd-1,first);
	topView(root->right,line,hd+1,first);
}
int main()
{
	struct node* root = NULL;
	int min=0, max=0;
	push(&root,11);
	push(&root,9);
	push(&root,12);
	push(&root,4);
	push(&root,32);
	push(&root,2);
	push(&root,10);
	push(&root,3);
	printf("tree is:\n");
	print(root);
	printf("\nTop view of tree is:\n");
	
	findMinMax(root,&min,&max,0);
	for(int line= min; line<= max; line++)
	{
		topView(root,line,0,min-1);
		printf("\n");
	}
	printf("\n");
	return 0;
}
