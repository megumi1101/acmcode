#include<bits/stdc++.h>
using namespace std;
int n,a[11110],ans=0;
int main()
{
	priority_queue<int,vector<int>,greater<int> >q;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		q.push(a[i]);
	}
	while(q.size()>=2)
	{
	int a=q.top();
	q.pop();
	int b=q.top();
	q.pop();
	ans+=a+b;
	q.push(a+b);	
	}
	printf("%d",ans);
	return 0;
}
	