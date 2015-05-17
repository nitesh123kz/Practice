#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N,i;
	int max1=0,max2=0;
	int tmp1,tmp2;
	scanf("%d",&N);
	int a[100],b[100];
	for (i = 0; i < N; i++)
	{
		scanf("%d",&a[i]);
	}
	for (i = 0; i < N; i++)
	{
		scanf("%d",&b[i]);
	}
	for(i=0;i<N-1;i++)
	{
		tmp1=abs(a[i]-a[i+1]);
		tmp2=abs(b[i]-b[i+1]);
		if(tmp1>max1)
		{
			max1=tmp1;
		}
		if(tmp2>max2)
		{
			max2=tmp2;
		}
	}
	if(max1>max2)
	{
		printf("Dom\n");
		printf("%d\n",max1);
	}
	else if(max1<max2)
	{
		printf("Brian\n");
		printf("%d\n",max2);
	}
	else if(max1==max2)
	{
		printf("Tie\n");
	}
return 0;
}