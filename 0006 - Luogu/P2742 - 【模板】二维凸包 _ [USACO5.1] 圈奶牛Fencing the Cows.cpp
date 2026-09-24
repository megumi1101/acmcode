#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const int N=1e5+5;
int n,top;
struct node
{
	double x,y;
}q[N],st[N];

double cj(node a1,node a2,node b1,node b2)
{
	return (a1.x-a2.x)*(b1.y-b2.y)-(b1.x-b2.x)*(a1.y-a2.y);
}

double dis(node a,node b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool cmp(node a,node b)
{
	double tmp=cj(q[1],a,q[1],b);
	if(tmp>0) return 1;
	else if(tmp==0&&dis(q[1],a)<dis(q[1],b)) return 1;
	return 0;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%lf%lf",&q[i].x,&q[i].y);
		if(i>1&&(q[i].y<q[1].y||(q[i].y==q[1].y&&q[i].x<q[1].x))) swap(q[1],q[i]);
	}
	sort(q+2,q+1+n,cmp);
	st[++top]=q[1];
	for(int i=2;i<=n;i++)
	{
		while(top>1&&cj(st[top-1],st[top],st[top],q[i])<=0) top--;
		st[++top]=q[i];
	}
	st[++top]=q[1];
	double ans=0;
	for(int i=1;i<top;i++) ans+=dis(st[i],st[i+1]);
	printf("%.2lf",ans);
	return 0;
}