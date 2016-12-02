/*
Delete odd valued nodes from linked list

Given Linked List
6 ->4 ->3 ->2 ->1 ->NULL
Output Linked List
6 ->4 ->2 ->NULL

Given Linked List
5 ->4 ->3 ->2 ->1 ->NULL
Output Linked List
4 ->2 ->NULL
*/
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
 
 
// A utility function to print a given linked list
void printList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ->", ptr->data );
        ptr = ptr->next;
    }
    printf("NULL\n");
}
 
// Utility function to create a new node.
void newNode(struct Node** head, int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = *head;
    *head = temp;
}
void deletOdd(struct Node** head)
{
	struct Node* curr = *head;
	struct Node* prev = NULL;
	while(curr != NULL)
	{
		if(curr->data % 2 == 0)
		{
			prev = curr;
			curr = curr->next;
		}
		else
		{
			if(prev == NULL)
			{
				struct Node* temp = curr;
				curr = curr->next;
				free(temp);
				*head = curr;
			}
			else
			{
				struct Node* temp = curr;
				curr = curr->next;
				prev->next = temp->next;
				free(temp);
			}
		}
		
	}
}
/* Driver program to test above function*/
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
    newNode(&head,1);
    newNode(&head,2);
    newNode(&head,3);
    newNode(&head,4);
 	newNode(&head,5);
    printf("Gven Linked List\n");
    printList(head);
    deletOdd(&head);
 	printf("Output Linked List\n");
 	printList(head);
    return 0;
}
