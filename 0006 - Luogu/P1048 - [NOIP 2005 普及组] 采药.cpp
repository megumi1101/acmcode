#include<cstdio>
#include<iostream>
using namespace std;
int va[1010],tt[1010],f[1010],t=0;
int main()
{
	int ttt,n;
	scanf("%d%d",&ttt,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&tt[i],&va[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int t=ttt;t>=0;t--)
		if(t>=tt[i])
		{f[t]=max(f[t],f[t-tt[i]]+va[i]);
		}
	}
	printf("%d",f[ttt]);
	return 0;
}