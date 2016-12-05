/*
1st List is:
1 -> 2 -> 3 -> 4 -> 8 -> 9 -> 10 -> NULL
2nd List is:
6 -> 7 -> 8 -> 9 -> 10 -> NULL
count_1:7 count_2:5 diff:2
common node:8

1. Find length of list1 - use a tmp1 node starting from head of list1 and move till last node.
2. Find length of list2 - use a tmp2 node starting from head of list2 and move till last node.
3. If tmp1 and tmp2 are different, it means that linked lists are non-intersecting. Return null.
   Example: list1: 1-2-3-4 , list2: 5-6-7-8, last nodes are different.
4. Else set variables diff, tmp1 and tmp2 as:
   a). tmp1 (a list node) to head node of larger list.
   b). tmp2 (a list node) to head node of smaller list.
   c). diff (an integer) to difference of lengths of larger to smaller lists i.e. absolute difference of the lengths.
5. Move forward tmp1 by diff number of nodes.
6. Now lists starting from tmp1 and tmp2 have same number of nodes and intersect at a particular node. Therefore, both tmp1 and tmp2 are equidistant from the intersection node.
7. Starting from tmp1 and tmp2 simultaneously, move node by node till a common node is reached. This node is the intersection of the 2 lists.
*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
void push(struct node** head, int val)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = val;
	temp->next = *head;
	*head = temp;
}
void print(struct node* head)
{
	if(head == NULL) return;
	struct node* curr = head;
	while(curr != NULL)
	{
		printf("%d -> ",curr->data);
		curr = curr->next;
	}
	printf("NULL\n");
}
void findIntersection(struct node* head, struct node* head1)
{
	struct node* curr = head;
	struct node* curr1 = head1;
	int count_1 = 0, count_2 = 0;
	int diff = 0;
	int i;
	int last_1, last_2;
	while(curr != NULL)
	{
		++count_1;
		last_1 = curr->data;
		curr = curr->next;
	}
	while(curr1 != NULL)
	{
		++count_2;
		last_2 = curr1->data;
		curr1 = curr1->next;
	}
	if(last_1 != last_2)
	{
		printf("no intersection point\n");
		return;
	}
	diff = abs(count_1-count_2);
	printf("count_1:%d count_2:%d diff:%d",count_1,count_2,diff);
	curr = head;
	curr1 = head1;
	if(count_1 > count_2)
	{
		for(i=0;i<diff;i++)
		{
			curr = curr->next;	
		}
		while(diff <= count_1)
		{
			if(curr->data == curr1->data)
			{
				printf("\ncommon node:%d\n",curr->data);
				break;
			}
			else
			{
				curr = curr->next;
				curr1 = curr1->next;
			}
			diff++;
		}
	}
	else
	{
		for(i=0;i<diff;i++)
		{
			curr1 = curr1->next;	
		}
		while(diff <= count_2)
		{
			if(curr->data == curr1->data)
			{
				printf("\ncommon node:%d\n",curr->data);
				break;
			}
			else
			{
				curr = curr->next;
				curr1 = curr1->next;
			}
			diff++;
		}
	}
}
int main()
{
	struct node* head = NULL;
	struct node* head1 = NULL;
	
	push(&head,10);
	push(&head,9);
	push(&head,8);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	printf("1st List is:\n");
	print(head);
	
	
	push(&head1,10);
	push(&head1,9);
	push(&head1,8);
	push(&head1,7);
	push(&head1,6);
	printf("2nd List is:\n");
	print(head1);

	findIntersection(head,head1);
	return 0;
}
