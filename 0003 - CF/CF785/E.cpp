// LUOGU_RID: 94036653
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int inline rid()
{
	int ans=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){ans=ans*10+ch-'0';ch=getchar();}
	return ans*f;
}
int ans,a[N],b[N],tot,bl,n,q,hs[N],l[N],r[N]; 
void build()
{
	bl=sqrt(n);tot=n/bl;if(n%bl)tot++;
	for(int i=1;i<=n;i++)a[i]=b[i]=i,hs[i]=(i-1)/bl+1;
	for(int i=1;i<=tot;i++)l[i]=(i-1)*bl+1,r[i]=i*bl;r[tot]=n;
	for(int i=1;i<=tot;i++)sort(b+l[i],b+r[i]+1);
}
int cx2(int i,int x)
{
	int xl=l[i],xr=r[i];
	while(xl<=xr)
	{
		int mid=(xl+xr)>>1;
		if(b[mid]<x)xl=mid+1;
		else xr=mid-1;
	}
	return xr-l[i]+1;
}
int cx(int x,int y,int k)
{
	int cnt=0;
	if(hs[x]>=hs[y])
	{
		for(int i=x;i<=y;i++)if(a[i]<k)cnt++;
		return cnt;
	}
	else
	{
		for(int i=x;i<=r[hs[x]];i++)if(a[i]<k)cnt++;
		for(int i=l[hs[y]];i<=y;i++)if(a[i]<k)cnt++;
		for(int i=hs[x]+1;i<=hs[y]-1;i++)cnt+=cx2(i,k);
	}
	return cnt;
}
signed main()
{
	n=rid(),q=rid();build();
	while(q--)
	{
		int cl=rid(),cr=rid();
		if(cl>cr)swap(cl,cr);
		if(cl==cr){printf("%lld\n",ans);continue;}
		ans+=2*cx(cl+1,cr-1,a[cr])-2*cx(cl+1,cr-1,a[cl]);
		if(a[cl]<a[cr])ans++;
		if(a[cl]>a[cr])ans--;
		swap(a[cl],a[cr]);
		for(int i=l[hs[cl]];i<=r[hs[cl]];i++)b[i]=a[i];
		for(int i=l[hs[cr]];i<=r[hs[cr]];i++)b[i]=a[i];
		sort(b+l[hs[cl]],b+r[hs[cl]]+1);
		sort(b+l[hs[cr]],b+r[hs[cr]]+1);
		printf("%lld\n",ans);
	}
	return 0;
}
/*
42 1
23 7
*/
