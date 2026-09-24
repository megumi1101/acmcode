#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,y;
}xbb[150005];
long long sum;
int ans,n;
bool cmp(node a,node b)
{
	return a.y<b.y;
}
priority_queue<int> q;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&xbb[i].x,&xbb[i].y);
	}
	sort(xbb+1,xbb+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		if(xbb[i].x+sum<=xbb[i].y)
		{
			ans++;
			sum+=xbb[i].x;
			q.push(xbb[i].x);
		}
		else
		{
			if(xbb[i].x<q.top())
			{
				sum-=q.top();
				q.pop();
				q.push(xbb[i].x);
				sum+=xbb[i].x;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
