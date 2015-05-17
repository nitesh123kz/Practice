#include <stdio.h>
int main()
{
	int T,i;
	int K,N,p,q,tmp,l,m;
	int A[100];
	int out,count;
	
	scanf("%d",&T);
	
	while(T--)
	{	
		//out = 0;
		count = 0;
		scanf("%d%d",&N,&K);
		for(i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
		}
		/*for(p=0;p<N-1;p++)
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
		}*/
		while(count!=K)
		{
			for(l=0;l<N-1;l++)
			{	
				
				for(m=l+1;m<N;m++)
				{
					
					if(A[m]==A[l])
					{
						count = count + 1;
					}
					else if(A[m]==(A[l]-1))
					{
						A[m] = A[m] + 1;
						out = out + 3; 
						count = count + 1;
					}
					else if(A[m]==(A[l]+1))
					{
						A[m] = A[m] - 1;
						out = out + 5; 
						count = count + 1;
					}
					/*if(count==K)
					{
						
						break;
					}*/
			    }
			}
		}
			printf("%d\n",out);
		
	}
return 0;
}