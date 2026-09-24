#include<cstdio>
#include<cmath>
using namespace std;
int t,x[10],y[10];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		for(int i=1;i<=3;i++)
		{
			scanf("%d%d",&x[i],&y[i]);
		}
		if(y[1]==y[2])
		{
			if(y[1]>y[3])
			{
				printf("%d\n",abs(x[1]-x[2]));
				continue;
			}
		}
		else if(y[1]==y[3])
		{
			if(y[1]>y[2])
			{
				printf("%d\n",abs(x[1]-x[3]));
				continue;
			}
		}
		else if(y[2]==y[3])
		{
			if(y[2]>y[1])
			{
				printf("%d\n",abs(x[3]-x[2]));
				continue;
			}
		}	
		printf("0");
		printf("\n");
	}
	return 0;
}
