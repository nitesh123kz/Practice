#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int T,N,i,sz;
	int arr[100];
	scanf("%d",&T);
	int count=0;
	int X,found,found1,found2,pos,pos1,pos2;
	while(T--)
	{
		scanf("%d",&N);
		srand(time(NULL));
		sz=N;
		for(i=0;i<N;i++)
		{
			scanf("%d",&arr[i]);
		}
		
		while(sz!=0)
		{		count=count+1;
				found=0;
				found1=0;
				found2=0;
				X = arr[rand() % sz];
				for(i=0;i<N;i++)
				{
					if(arr[i]==X)
					{
						found=1;
						pos=i;
						break;
					}
				}
				for(i=0;i<N;i++)
				{
					if(arr[i]==X-1)
					{
						found1=1;
						pos1=i;
						break;
					}
				}
				for(i=0;i<N;i++)
				{
					if(arr[i]==X+1)
					{
						found2=1;
						pos2=i;
						break;
					}
				}
				if(found==1)
				{
					for(i=pos;i<N-1;i++)
					{
						arr[i]=arr[i+1];
					}
					sz=sz-1;
				}
				if(found1==1)
				{
					for(i=pos1;i<N-1;i++)
					{
						arr[i]=arr[i+1];
					}
					sz=sz-1;
				}
				if(found2==1)
				{
					for(i=pos2;i<N-1;i++)
					{
						arr[i]=arr[i+1];
					}
					sz=sz-1;
				}
		}
		printf("%d\n",count);
	}
	return 0;
}