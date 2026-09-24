#include<bits/stdc++.h>
using namespace std;
double eps=1e-8;
double x[20],y[20];
int q,n,m,lowunbit[1<<20],line[20][20],dp[1<<20];
void tt(double &a,double &b,int i,int j)
{
	a=-(y[i]*x[j]-y[j]*x[i])/(x[j]*x[j]*x[i]-x[i]*x[i]*x[j]);
	b=(y[i]*x[j]*x[j]-y[j]*x[i]*x[i])/(x[i]*x[j]*x[j]-x[j]*x[i]*x[i]);
}
int main()
{	
	for(int i=0;i<(1<<18);i++)
	{	
	int j=1;		
	for(;j<=18&&i&(1<<j-1);j++);
	lowunbit[i]=j;	
	}
	scanf("%d",&q);
	while(q--)
	{
		memset(line,0,sizeof(line));
		memset(dp,0x3f,sizeof(dp));
		dp[0]=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%lf%lf",x+i,y+i);
		}		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(fabs(x[i]-x[j])<eps)continue;
				double a,b;
				tt(a,b,i,j);
				if(a>-eps)continue;
				for(int k=1;k<=n;k++)
				{
					if(fabs(a*x[k]*x[k]+b*x[k]-y[k])<eps)
					line[i][j]|=(1<<(k-1));
				}
			}
		}
		for(int i=0;i<(1<<n);i++)
		{
			int j=lowunbit[i];
			dp[i|(1<<(j-1))]=min(dp[i|(1<<(j-1))],dp[i]+1); 
			for(int k=1;k<=n;k++)
			{
				dp[i|line[j][k]]=min(dp[i|line[j][k]],dp[i]+1); 
			}
			
		}
		printf("%d\n",dp[(1<<n)-1]);
	}
	return 0;
}