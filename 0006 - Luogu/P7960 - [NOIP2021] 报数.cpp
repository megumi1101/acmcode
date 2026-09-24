#include<bits/stdc++.h>
using namespace std;
const int N=1e7+50,mx=1e7+10;
int inline rd()
{
	int ans=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){ans=ans*10+ch-'0';ch=getchar();}
	return ans*f;
}
int T,nx[N],f[N];
bool pd(int x)
{
	while(x){if(x%10==7)return 1;x/=10;}
	return 0;
}
void init()
{
	int ls=0;
	for(int i=1;i<=mx;i++)
	{
		if(f[i])continue;
		if(pd(i)){for(int j=i;j<=mx;j+=i)f[j]=1;continue;}
		nx[ls]=i;ls=i;
	}
}
int main()
{
	T=rd();
	init();
	while(T--)
	{
		int x=rd();
		if(f[x])printf("-1\n");
		else printf("%d\n",nx[x]);
	}
	return 0;
}