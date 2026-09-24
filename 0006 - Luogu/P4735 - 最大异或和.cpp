#include<bits/stdc++.h>
using namespace std;
const int maxn=6e5+10;
int cnt,ch[maxn*24][2],sum[maxn*24];
int a[maxn],b[maxn],bin[50],n,m,rt[maxn];
int insert(int x,int val)
{
	int o,y;
	o=y=++cnt;
	for(int i=23;i>=0;i--)
	{
		ch[y][0]=ch[x][0];
		ch[y][1]=ch[x][1];
		sum[y]=sum[x]+1;
		int t=val&bin[i];
		t>>=i;
		x=ch[x][t];
		ch[y][t]=++cnt;
		y=cnt;
	}
	sum[y]=sum[x]+1;
	return o;
}
int cx(int l,int r,int val)
{
	int tmp=0;
	for(int i=23;i>=0;i--)
	{
		int t=val&bin[i];
		t>>=i;
		if(sum[ch[r][t^1]]-sum[ch[l][t^1]])
		{
			tmp+=bin[i];
			r=ch[r][t^1];
			l=ch[l][t^1];
		}
		else
		{
			r=ch[r][t];
			l=ch[l][t];
		}
	}
	return tmp;
}
int main()
{
	bin[0]=1;
	for(int i=1;i<=30;i++)
	{
		bin[i]=bin[i-1]<<1;
	}
	scanf("%d%d",&n,&m);
	n++;
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		rt[i]=insert(rt[i-1],b[i]);
	}
	int l,r,x;
	while(m--)
	{
		char c[2];
		scanf("%s",c);
		if(c[0]=='A')
		{
			n++;
			scanf("%d",&a[n]);
			b[n]=b[n-1]^a[n];
			rt[n]=insert(rt[n-1],b[n]);
		}
		else
		{
			scanf("%d%d%d",&l,&r,&x);
			printf("%d\n",cx(rt[l-1],rt[r],b[n]^x));
		}
	}
	return 0;
	
}