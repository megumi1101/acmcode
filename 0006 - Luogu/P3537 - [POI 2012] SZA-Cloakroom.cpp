#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,q,ans[maxn],f[maxn];
struct node
{
	int a,b,c,id;
}a[1010],b[maxn];
bool cmp(node x,node y)
{
	return x.a<y.a;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i].c,&a[i].a,&a[i].b);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d%d",&b[i].a,&b[i].b,&b[i].c);
		b[i].id=i;
	}
	sort(a+1,a+1+n,cmp);sort(b+1,b+1+q,cmp);int j=1;
	f[0]=1e9;
	for(int i=1;i<=q;i++)
	{
		while(j<=n&&a[j].a<=b[i].a)
		{
			for(int k=1e5;k>=a[j].c;k--)
			{
				f[k]=max(f[k],min(f[k-a[j].c],a[j].b));
			}
			j++;
		}
		if(f[b[i].b]>b[i].a+b[i].c)ans[b[i].id]=1;
	}
	for(int i=1;i<=q;i++)
	{
		if(ans[i])printf("TAK\n");
		else printf("NIE\n");
	}
	return 0;
}