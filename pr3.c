#include <stdio.h>
int main()
{
	int T,i,j;
	int K,N,p,q,tmp;
	int A[100];
	int out,count;
	int maxE=0,max=0;
	scanf("%d",&T);
	
	while(T--)
	{	
		out = 0;
		count = 0;
		scanf("%d%d",&N,&K);
		for(i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
		}
		for(p=0;p<N-1;p++)
		{
			for(q=p+1;q<N;q++)
			{
				if(A[q]<A[p])
				{
					tmp=A[p];
					A[p]=A[q];
					A[q]=tmp;
				}
			}
		}
		for(i=0;i<N;i++)
		{
			count=0;
			for(j=0;j<N-1;j++)
			{
				if(A[j]==A[j+1])
				{
					count+=1;
				}
				if(count>max)
				{
					max=count;
					maxE=A[j];
				}
		    }
		}
		for(i=0;i<N;i++)
		{
			if(A[i]==maxE-1)
			{
				A[i]=A[i]+1;
				out=out+3;
				max=max+1;
			}
			else if(A[i]==maxE+1)
			{
				A[i]=A[i]-1;
				out=out+5;	
				max=max+1;
			}
			if(max==K)
			{
				printf("%d\n",out);
				break;
			}
		}
	}
return 0;
}