#include<bits/stdc++.h>
using namespace std;
int n,t;
stack<int> a;
long long ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t);
		while(!a.empty()&&a.top()<=t)
		{
			a.pop();			
		}
		ans+=a.size();
		a.push(t);
	}
	printf("%lld",ans);
	return 0;
}