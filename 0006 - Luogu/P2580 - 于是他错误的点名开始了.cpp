#include<bits/stdc++.h>
using namespace std;
int n,m,t=0,ans;
char x[55];
struct node
{
	int son[26];
	int num;
}a[1000005];
void build()
{
	int l=strlen(x),p=0;
	for(int i=0;i<l;i++)
	{
		if(a[p].son[x[i]-'a']==0)
		{
			a[p].son[x[i]-'a']=++t;
		}
		p=a[p].son[x[i]-'a'];
	}
}
int chck()
{
	int l=strlen(x),p=0;
	for(int i=0;i<l;i++)
	{
		if(a[p].son[x[i]-'a']==0)
		{
			return 0;
		}
		p=a[p].son[x[i]-'a'];
	}
	a[p].num++;
	return a[p].num;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",x);
		build();
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%s",x);
		ans=chck();
		if(ans==1) printf("OK\n");
		if(ans==0) printf("WRONG\n");
		if(ans>=2) printf("REPEAT\n");
	}
	return 0;
}