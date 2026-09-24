#include<bits/stdc++.h>
using namespace std;
#define db double
#define ll long long
const int maxn=1e6+10;
int n,q[maxn];
db a,b,c,s[maxn],f[maxn];
db X(int i){return s[i];}
db Y(int i){return f[i]+a*s[i]*s[i]-b*s[i]+c;}
db xl(int i,int j){return (Y(i)-Y(j))/(X(i)-X(j));}
int main()
{
	scanf("%d%lf%lf%lf",&n,&a,&b,&c);
	for(int i=1;i<=n;i++)scanf("%lf",&s[i]),s[i]+=s[i-1];
	int l=1,r=0;
	q[++r]=0;f[0]=0;
	for(int i=1;i<=n;i++)
	{
		while(l<r&&xl(q[l],q[l+1])>2*a*s[i])l++;
		f[i]=f[q[l]]+a*(s[i]-s[q[l]])*(s[i]-s[q[l]])+b*(s[i]-s[q[l]])+c;
		while(l<r&&xl(q[r-1],q[r])<xl(q[r],i))r--;
		q[++r]=i;
	}
	printf("%lld",(ll)f[n]);
	return 0;
}