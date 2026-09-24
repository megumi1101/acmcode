#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
priority_queue<int> q;
vector<int> a[maxn];
int t,rd[maxn],ans[maxn],tot,n,m;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		tot=0;
		scanf("%d%d",&n,&m);
		memset(rd,0,sizeof(rd));
		for(int i=1;i<=n;i++)
		{
			a[i].clear();
		}
		for(int i=1;i<=m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			a[y].push_back(x);
			rd[x]++;
		}
		for(int i=1;i<=n;i++)
		{
			if(!rd[i])
			{
				q.push(i);
			}
		}
		while(!q.empty())
		{
			int u=q.top();
			q.pop();
			ans[++tot]=u;
			for(int i=0;i<a[u].size();i++)
			{
				int v=a[u][i];
				if(--rd[v]==0)
				{
					q.push(v);
				}
			}
		}
		if(tot<n)
		{
			printf("Impossible!\n");
			continue;
		}
		for(int i=n;i;i--)
		{
			printf("%d ",ans[i]);
		}
		printf("\n");
	}
	return 0;
}