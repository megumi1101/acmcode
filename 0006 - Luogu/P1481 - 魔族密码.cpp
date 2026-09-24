#include<bits/stdc++.h>
using namespace std;
char s[2020][88];
int n,ans=0,f[2020];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s[i]);
		f[i]=1;
		for(int j=i-1;j>=1;j--)
		{
			if(strstr(s[i],s[j])==s[i])
			{
				f[i]=max(f[i],f[j]+1);
			}
		}
		ans=max(f[i],ans);
	}
	printf("%d",ans);
	return 0;
}