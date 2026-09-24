#include<bits/stdc++.h>
using namespace std;
const int N=4e5+10;
int n,m1,m2,cnt=0,mx1,mx2;
int f[N],g[N],ans;
struct nod
{
	int x,y;
	friend bool operator<(nod a,nod b)
	{
		return a.x<b.x;
	}	
}a[N],b[N];
struct node
{
	int x,y;
	friend bool operator<(node a,node b)
	{
		return a.x>b.x;
	}
};
priority_queue<node> q;
priority_queue<int,vector<int>,greater<int> > q2;
int main()
{
    scanf("%d%d%d",&n,&m1,&m2);
    for(int i=1;i<=m1;i++)scanf("%d%d",&a[i].x,&a[i].y);
    for(int i=1;i<=m2;i++)scanf("%d%d",&b[i].x,&b[i].y);
    sort(a+1,a+1+m1);sort(b+1,b+1+m2);
    for(int i=1;i<=n;i++)q2.push(i);
    for(int i=1;i<=m1;i++)
    {
    	while(!q.empty()&&a[i].x>=q.top().x)
    	{
    		q2.push(q.top().y);
    		q.pop();
    	}
    	if(q2.empty())continue;
    	int k=q2.top();
    	f[k]++;
    	q2.pop();
    	q.push((node){a[i].y,k});
    }
    for(int i=1;i<=n;i++)f[i]+=f[i-1];
    while(!q.empty())q.pop();
    while(!q2.empty())q2.pop();
    for(int i=1;i<=n;i++)q2.push(i);
    for(int i=1;i<=m2;i++)
    {
    	while(!q.empty()&&b[i].x>=q.top().x)
    	{
    		q2.push(q.top().y);
    		q.pop();
    	}
    	if(q2.empty())continue;
    	int k=q2.top();
    	g[k]++;
    	q2.pop();
    	q.push((node){b[i].y,k});
    }
    for(int i=1;i<=n;i++)g[i]+=g[i-1];
    for(int i=0;i<=n;i++)
        ans=max(ans,f[i]+g[n-i]);
    printf("%d",ans);
    return 0;
}