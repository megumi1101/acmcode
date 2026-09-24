#include<bits/stdc++.h>
using namespace std;
long long n,x[1000001],ans;
int main(){
	scanf("%lld%lld",&n,&x[1]);
	for(int i=2;i<=n;i++)scanf("%d",&x[i]),ans+=max(x[i],x[i-1]);
	printf("%lld",ans);
}