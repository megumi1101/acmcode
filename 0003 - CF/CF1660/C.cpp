#include<bits/stdc++.h>
using namespace std;
char s[200202];
bool a[26];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		int n=strlen(s+1);
		int cnt=0,sg=0;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
		{
			if(!a[s[i]-'a'])
			{
				a[s[i]-'a']=1;
			}
			else
			{
				cnt+=i-sg-2;
				memset(a,0,sizeof(a));
				sg=i;
			}
		}
		for(int i=0;i<26;i++)
		{
			if(a[i])++cnt;
		}
		printf("%d\n",cnt);
	}
}
