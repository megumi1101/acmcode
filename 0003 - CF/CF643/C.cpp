#include<bits/stdc++.h>
using namespace std;
#define db double
const int maxn=2e5+10;
db sa[maxn],sb[maxn],sc[maxn],a[maxn],f[maxn][2];
int q[maxn],n,k;
bool op;
db X(int i){return sa[i];}
db Y(int i){return f[i][op^1]-sc[i]+sa[i]*sb[i];}
db xl(int i,int j){return (Y(i)-Y(j))/(X(i)-X(j));}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf",&a[i]);
		sa[i]=sa[i-1]+a[i];
		sb[i]=sb[i-1]+(1/a[i]);
		sc[i]=sc[i-1]+sa[i]/a[i];
	}
	op=0;
	for(int i=1;i<=n;i++)f[i][0]=1e15;
	while(k--)
	{
		op^=1;
		int l=1,r=0,j;
		q[++r]=0;
		memset(q,0,sizeof(q));
		for(int i=1;i<=n;i++)
		{
			while(l<r&&xl(q[l],q[l+1])<sb[i])l++;j=q[l];
			f[i][op]=f[j][op^1]-sc[j]+sa[j]*sb[j]+sc[i]-sa[j]*sb[i];
			while(l<r&&xl(q[r-1],q[r])>xl(q[r],i))r--;
			q[++r]=i;
		}
	}
	printf("%.10lf",f[n][op]);
	return 0;
}
