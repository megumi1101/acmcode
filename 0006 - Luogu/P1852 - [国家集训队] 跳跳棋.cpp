#include<bits/stdc++.h>
using namespace std;
int tot,ans,flag,bs,l,r,mid,d1,d2,a[5];
struct node
{
	int x,y,z,tot;
}A,B;
void dfs(int x,int y,int z)
{
	tot=0;
	while(1)
	{
		d1=y-x,d2=z-y;
		if(d1==d2)break;
		if(d1>d2) bs=(d1-1)/d2,tot+=bs,y-=bs*d2,z-=bs*d2;
		else bs=(d2-1)/d1,tot+=bs,x+=bs*d1,y+=bs*d1;
	}
	if(!flag) flag=1,A=(node){x,y,z,tot};
	else B=(node){x,y,z,tot};
}
bool check(int tt,int x,int y,int z,int xx,int yy,int zz)
{
	tot=tt;
	while(tot)
	{
		d1=y-x,d2=z-y;
		if(d1==d2)break;
		if(d1>d2) bs=min((d1-1)/d2,tot),tot-=bs,y-=bs*d2,z-=bs*d2;
		else bs=min((d2-1)/d1,tot),tot-=bs,x+=bs*d1,y+=bs*d1;
	}
	tot=tt;
	while(tot)
	{
		d1=yy-xx,d2=zz-yy;
		if(d1==d2)break;
		if(d1>d2) bs=min((d1-1)/d2,tot),tot-=bs,yy-=bs*d2,zz-=bs*d2;
		else bs=min((d2-1)/d1,tot),tot-=bs,xx+=bs*d1,yy+=bs*d1;
	}
	return x==xx&y==yy&z==zz;
}
int main()
{
	int x,y,z,xx,yy,zz;
	for(int i=1;i<=3;i++)scanf("%d",&a[i]);
	sort(a+1,a+4);
	x=a[1],y=a[2],z=a[3];
	for(int i=1;i<=3;i++)scanf("%d",&a[i]);
	sort(a+1,a+4);
	xx=a[1],yy=a[2],zz=a[3];
	dfs(x,y,z),dfs(xx,yy,zz);
	if(A.x!=B.x||A.y!=B.y||A.z!=B.z)
	{
		printf("NO");
		return 0;
	}
	if(A.tot<B.tot)
	{
		swap(A,B);
		swap(x,xx),swap(y,yy),swap(z,zz);
	}
	ans=tot=A.tot-B.tot;
	while(tot)
	{
		d1=y-x,d2=z-y;
		if(d1==d2)break;
		if(d1>d2) bs=min((d1-1)/d2,tot),tot-=bs,y-=bs*d2,z-=bs*d2;
		else bs=min((d2-1)/d1,tot),tot-=bs,x+=bs*d1,y+=bs*d1;
	}
	l=0,r=B.tot;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(check(mid,x,y,z,xx,yy,zz))
		{
			r=mid;
		}
		else l=mid+1;
	}
	printf("YES\n%d",ans+2*l);
	return 0;
}