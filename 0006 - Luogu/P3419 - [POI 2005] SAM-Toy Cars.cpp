#include<bits/stdc++.h>
using namespace std;
const int M=500050;
int n,k,p;
int a[M],head[M],nex[M],vis[M];
int ans,cnt;
struct node
{
	int x,y;
	friend bool operator <(node a,node b)
	{
		return a.x<b.x;
	}
};
priority_queue<node > q;
int main()
{
	scanf("%d%d%d",&n,&k,&p);
	for(int i=1;i<=p;i++)
	{
		scanf("%d",&a[i]);
	}
	memset(head,0,sizeof(head));
	for(int i=p;i>=1;i--)
	{
		nex[i]=head[a[i]];
		head[a[i]]=i;
	}
	for(int i=1;i<=p;i++)
	{
		if(!nex[i])
		{
			nex[i]=p+1;
		}
	}
	for(int i=1;i<=p;i++)
	{
		if(!vis[a[i]])
		{
			ans++;
			if(cnt<k)
			{
				cnt++;
			}
			else
			{
				vis[q.top().y]=0;
				q.pop();
			}				
		}
		vis[a[i]]=1;
		q.push((node){nex[i],a[i]});
	}
	printf("%d\n",ans);
}