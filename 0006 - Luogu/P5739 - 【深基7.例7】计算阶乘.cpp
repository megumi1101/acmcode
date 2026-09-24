#include<cstdio>

int main()
{
	long long n,s;
	scanf("%lld",&n);
	s=1;
	for(long long i=1;i<=n;i++)
	{
		s *=i;
		s%=1000000007;
	}
	printf("%lld",s);
	return 0;		
}