#include<bits/stdc++.h>
using namespace std;
int l[1010][1010],r[1010][1010],up[1010][1010],ha[10];
int ma[1010][1010];
int n,m,ans;
char c;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>c;
			if(c=='F')
			{
				ma[i][j]=1;
				ha[1]++;
			}
			else
			{
				ma[i][j]=0;
			}	
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			l[i][j]=j;
			r[i][j]=j;
			up[i][j]=1;			
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
		{
			if(ma[i][j]==1&&ma[i][j-1]==1)
			{
				l[i][j]=l[i][j-1];
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=m-1;j>0;j--)
		{
			if(ma[i][j]==1&&ma[i][j+1]==1)
			{
				r[i][j]=r[i][j+1];
			}
		}
	}
	
	if(ha[1]==0)
	{
		printf("0");
		return 0;
	}
	
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(ma[i][j]==1&&ma[i-1][j]==1)
			{
				l[i][j]=max(l[i-1][j],l[i][j]);
				r[i][j]=min(r[i-1][j],r[i][j]);
				up[i][j]=up[i-1][j]+1;
			}
			ans=max(ans,(r[i][j]-l[i][j]+1)*up[i][j]);
		}
	}
	printf("%d",3*ans);
	return 0;
}