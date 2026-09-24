#include<bits/stdc++.h>
using namespace std;
const int maxn=4e4+10;
int n,m,has[205][maxn],a[maxn],kk[205],cnt[205],f[maxn];
int main()
{
	scanf("%d%d",&n,&m);
	int mx=sqrt(n)+1;
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	f[0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=mx;j++)
		{		
			if(has[j][a[i]]==0)
			{	
				++has[j][a[i]];
				++cnt[j];
				if(cnt[j]>j)
				{
					while(--has[j][a[kk[j]]]!=0)
					{
						++kk[j];					
					}
					++kk[j];
					cnt[j]=j;
				}
			}
			else has[j][a[i]]++;
			if(cnt[j]==j)f[i]=min(f[i],f[kk[j]-1]+j*j);
		}		
	}
	printf("%d",f[n]);
	return 0;
}