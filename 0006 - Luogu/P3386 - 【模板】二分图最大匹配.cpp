#include<bits/stdc++.h>
using namespace std;
int n,m,e,cnt=0;
int eg[555][555],v[555],ma[555];
int find(int x)
{
	for(int i=1;i<=m;i++)
	{
		if(eg[x][i])
		{
			if(v[i])
			continue;
			v[i]=1;
			if(!ma[i]||find(ma[i]))
			{
				ma[i]=x;
				return 1;
			}
		}
		
	}return 0;
}
void mach()
{
	for(int i=1;i<=n;i++)
	{
		memset(v,0,sizeof(v));
		if(find(i))
		{
			cnt++;
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&e);
	for(int i=1;i<=e;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		eg[a][b]=1;
	}
	memset(ma,0,sizeof(ma));
	mach();
	printf("%d",cnt);
	return 0;
}