#include<bits/stdc++.h>
using namespace std;
int C;
const int maxn=1e3+10;
int n,t[maxn],b[maxn],r;
int f[maxn][1<<8][20];
void qumin(int &a,int b) 
{
	a=min(a,b);
}
void work()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&t[i],&b[i]);
	}
	memset(f,0x3f3f3f3f,sizeof(f)),f[1][0][7]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<(1<<8);j++)
		{
			for(int k=-8;k<=7;k++)
			{
				if(f[i][j][k+8]!=0x3f3f3f3f)
				{
					if(j&1)
					{
						qumin(f[i+1][j>>1][k+7],f[i][j][k+8]);
					}
					else
					{	
						int r=1e9;
						for(int h=0;h<=7;h++)
						{
							if((j>>h)&1)continue;
							if(i+h>r)break;
							qumin(r,i+h+b[i+h]);			
							qumin(f[i][j|(1<<h)][h+8],f[i][j][k+8]+(i+k?t[i+k]^t[i+h]:0));
						}
					}
				}
			}
		}
	}
	int res=1e9;
	for(int k=0;k<=8;k++)
	{
		res=min(res,f[n+1][0][k]);
	}
	printf("%d\n",res);
	
}
int main()
{
	scanf("%d",&C);
	while(C--)work();
	return 0;
}