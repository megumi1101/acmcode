#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>a[i-1])ans+=a[i]-a[i-1];
	}
	printf("%d",ans);
	return 0;
}

