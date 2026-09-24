#include<bits/stdc++.h>
using namespace std;
const int N=4e4+10;
int inline rd()
{
	int ans=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans*f;
}
int n,m,a[N],bl,tot,b[N],hs[N],l[N],r[N],sz;
int f[205][205],s[205][N],ans,t[N];
void build()
{
	bl=sqrt(n);tot=n/bl;if(n%bl)tot++;
	for(int i=1;i<=n;i++)hs[i]=(i-1)/bl+1;
	for(int i=1;i<=tot;i++)l[i]=(i-1)*bl+1,r[i]=i*bl;r[tot]=n;
	for(int i=1;i<=tot;i++)
	{
		for(int j=1;j<=sz;j++)s[i][j]=s[i-1][j];
		for(int j=l[i];j<=r[i];j++)
			s[i][a[j]]++;
	}
	for(int i=1;i<=tot;i++)
		for(int j=i;j<=tot;j++)
		{
			int mx=f[i][j-1];
			for(int k=l[j];k<=r[j];k++)
				if(s[j][a[k]]-s[i-1][a[k]]>s[j][mx]-s[i-1][mx]
				||(s[j][a[k]]-s[i-1][a[k]]==s[j][mx]-s[i-1][mx]&&a[k]<mx))
				mx=a[k];
			f[i][j]=mx;	
		}
}
int cx(int x,int y)
{
	int mx=0;
	if(hs[y]-hs[x]<2)
	{
		for(int i=x;i<=y;i++)t[a[i]]++;
		for(int i=x;i<=y;i++)
			if(t[a[i]]>t[mx]||(t[a[i]]==t[mx]&&a[i]<mx))mx=a[i];
		for(int i=x;i<=y;i++)t[a[i]]=0;
	}
	else
	{
		for(int i=x;i<=r[hs[x]];i++)t[a[i]]++;
		for(int i=l[hs[y]];i<=y;i++)t[a[i]]++;
		int cl=hs[x],cr=hs[y];
		mx=f[cl+1][cr-1];
		for(int i=x;i<=r[cl];i++)
		{
			int p=t[mx]+s[cr-1][mx]-s[cl][mx];
			int u=t[a[i]]+s[cr-1][a[i]]-s[cl][a[i]];
			if(u>p||(u==p&&a[i]<mx))mx=a[i];
		}
		for(int i=l[cr];i<=y;i++)
		{
			int p=t[mx]+s[cr-1][mx]-s[cl][mx];
			int u=t[a[i]]+s[cr-1][a[i]]-s[cl][a[i]];
			if(u>p||(u==p&&a[i]<mx))mx=a[i];
		}
		for(int i=x;i<=r[hs[x]];i++)t[a[i]]=0;
		for(int i=l[hs[y]];i<=y;i++)t[a[i]]=0;
	}
	return b[mx];
}
int main()
{
	n=rd();m=rd();
	for(int i=1;i<=n;i++)a[i]=rd(),b[i]=a[i];
	sort(b+1,b+1+n);
	sz=unique(b+1,b+1+n)-b-1;
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(b+1,b+sz+1,a[i])-b;
	build();
	while(m--)
	{
		int x=(rd()+ans-1)%n+1,y=(rd()+ans-1)%n+1;
		if(x>y)swap(x,y);
		ans=cx(x,y);
		printf("%d\n",ans);
	}
	return 0;
}
/*
6 3 
1 2 3 2 1 2 
1 5 
3 6 
1 5
*/