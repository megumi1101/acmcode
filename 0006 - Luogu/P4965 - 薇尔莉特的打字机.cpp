#include<bits/stdc++.h>
#define p 19260817
#define I scanf
#define love ("%d%d"
#define violet ,&n,&m)
#define Love ("%s",
#define Violet s+1) 
using namespace std;
#include<cstdio>
int n,m,f[111],ans=1;
char s[5000003];
int main()
{
	I love violet ;
	I Love Violet ;
	char ch;
	while(m--)
	{
		cin>>ch;
		if(ch=='u')
		{
			if(n==0) continue;
			ans++;
			f[s[n]-'A']++;
			n--;
		}
		else
		{
			int tmp=f[ch-'A'];
			f[ch-'A']=ans;
			ans=((ans+ans-tmp)%p+p)%p;
		}
	}
	printf("%d",ans);
	return 0;
}