#include<bits/stdc++.h>
using namespace std;
int g[51][51][51][51],f[51][51],a[52],b[52];
int main()
{
	int n,aa,bb;
	scanf("%d%d%d",&n,&aa,&bb);
	memset(g,0x3f,sizeof(g));
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	int size=unique(b+1,b+1+n)-b-1;
	for(int i=1;i<=n;i++)
	{
		a[i]=lower_bound(b+1,b+1+size,a[i])-b;
		f[i][i]=aa;
	}
	for(int i=1;i<=n;i++)
	{
		g[i][i][a[i]][a[i]]=0;
	}
	for(int len=1;len<=n;len++)
	{
		for(int l=1,r=len;r<=n;l++,r++)
		{
			for(int mn=1;mn<=size;mn++)
			{
				for(int mx=1;mx<=size;mx++)
				{		
					for(int k=1;k<r;k++)
					{
						g[l][r][mn][mx]=min(g[l][k][mn][mx]+f[k+1][r],g[l][r][mn][mx]);
					}
					g[l][r+1][min(mn,a[r+1])][max(mx,a[r+1])]=min(g[l][r+1][min(mn,a[r+1])][max(mx,a[r+1])],g[l][r][mn][mx]);
					f[l][r]=min(f[l][r],g[l][r][mn][mx]+aa+bb*(b[mx]-b[mn])*(b[mx]-b[mn]));
				}
			}
		}
	}
	printf("%d",f[1][n]);
	return 0;
}