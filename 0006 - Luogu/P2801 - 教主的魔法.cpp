#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,q,xx[maxn],a[maxn],b[maxn];
int bl,tot,l[maxn],r[maxn],tag[maxn];
void build()
{
	bl=sqrt(n);tot=n/bl;if(n%bl)tot++;
	for(int i=1;i<=n;i++)xx[i]=(i-1)/bl+1,b[i]=a[i];
	for(int i=1;i<=tot;i++)l[i]=(i-1)*bl+1,r[i]=i*bl;r[tot]=n;
	for(int i=1;i<=tot;i++)sort(b+l[i],b+r[i]+1);
}
void update(int x,int y,int k)
{
	if(xx[x]==xx[y])
	{
		for(int i=x;i<=y;i++)a[i]+=k;
		for(int i=l[xx[x]];i<=r[xx[x]];i++)b[i]=a[i];
		sort(b+l[xx[x]],b+r[xx[x]]+1);
	}
	else
	{
		for(int i=x;i<=r[xx[x]];i++)a[i]+=k;
		for(int i=l[xx[x]];i<=r[xx[x]];i++)b[i]=a[i];
		sort(b+l[xx[x]],b+r[xx[x]]+1);
		for(int i=l[xx[y]];i<=y;i++)a[i]+=k;
		for(int i=l[xx[y]];i<=r[xx[y]];i++)b[i]=a[i];
		sort(b+l[xx[y]],b+r[xx[y]]+1);
		for(int i=xx[x]+1;i<=xx[y]-1;i++)tag[i]+=k;
	}
}
void cx(int x,int y,int k)
{
	int res=0;
	if(xx[x]==xx[y])
	{
		for(int i=x;i<=y;i++)if(tag[xx[x]]+a[i]>=k)res++;
		printf("%d\n",res);
	}
	else
	{
		for(int i=x;i<=r[xx[x]];i++)if(tag[xx[x]]+a[i]>=k)res++;
		for(int i=l[xx[y]];i<=y;i++)if(tag[xx[y]]+a[i]>=k)res++;
		for(int i=xx[x]+1;i<=xx[y]-1;i++)
		{
			int cl=l[i],cr=r[i],mid=0;
			while(cl<cr)
			{
				int mid=(cl+cr)>>1;
				if(b[mid]+tag[i]>=k)cr=mid;
				else cl=mid+1;
			}
			if(b[cl]+tag[i]<k)cl++;
			cl-=bl*(i-1);
			res+=(bl-cl+1);
		}
		printf("%d\n",res);
	}
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	build();
	while(q--)
	{
		char s[2];int x,y,k;
		scanf("%s%d%d%d",&s[0],&x,&y,&k);
		if(s[0]=='M')update(x,y,k);
		else cx(x,y,k);
	}
	return 0;
}