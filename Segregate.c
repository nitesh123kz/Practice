Segregate 0s and 1s in an array
You are given an array of 0s and 1s in random order. Segregate 0s on left side and 1s on right side of the array. Traverse array only once.

Input array   =  [0, 1, 0, 1, 0, 0, 1, 1, 1, 0] 
Output array =  [0, 0, 0, 0, 0, 1, 1, 1, 1, 1] 

#include<stdio.h>

int main()
{
int arr[10] = {1, 1, 1, 1, 1, 1, 0, 1, 1, 1};
int i, j, n=10;
i=-1;
j=n;
while(i<j)
{
  while(arr[++i] == 0);
  while(arr[--j] == 1);
  if(i<j)
  {
    int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
  }
}
if(i == 0 || i == n)
{
   printf("Either all elements are 0 or 1\n");
   //return 0;
}
for(i=0;i<10;i++)
{
  printf("%d",arr[i]);
}
printf("\n");
return 0;
}
