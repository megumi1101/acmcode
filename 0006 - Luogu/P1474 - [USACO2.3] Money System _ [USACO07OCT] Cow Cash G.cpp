#include<cstdio>
long long a[100],f[10100];
int main()
{
long long v,n;
	scanf("%lld %lld",&v,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
f[0]=1;
	for(int i=1;i<=v;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(j-a[i]>=0)
			{
				f[j]+=f[j-a[i]];
			}
		}
	}
	printf("%lld",f[n]);
	return 0;
 } 