#include<cstdio>
#include<algorithm>
using namespace std;
int jilu[1010101],p[1010102],cnt;
struct node{
	int a;
	int b;
}yi[1010101],er[1010101];
int cmp(node x,node y)
{
	return x.a<y.a;
}
void add(int l,int r)
{
	if(l==r)return;
	int mid=(l+r)/2;
	int j=l;
    int yizu=l;
    int erzu=mid+1;
    add(l,mid);
    add(mid+1,r);
    while(yizu<=mid&&erzu<=r)
    {
    	if(jilu[yizu]<=jilu[erzu])
    	{
	    	p[j++]=jilu[yizu++];
	    }
	    else{
    		p[j++]=jilu[erzu++];
    		cnt=(cnt+mid-yizu+1)%99999997;
    	}
    }
	while(yizu<=mid)
	{
		p[j++]=jilu[yizu++];
	} 
	while(erzu<=r) 
	{
		p[j++]=jilu[erzu++];
	}
	for(int i=l;i<=r;i++)
	{
		jilu[i]=p[i];
	}  
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&yi[i].a);
		yi[i].b=i;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&er[i].a);
		er[i].b=i;
	}
	sort(yi+1,yi+n+1,cmp);
	sort(er+1,er+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		jilu[er[i].b]=yi[i].b;
	}
	add(1,n);
	printf("%d",cnt);
	return 0;
}