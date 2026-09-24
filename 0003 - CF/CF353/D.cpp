// LUOGU_RID: 91790816
#include<bits/stdc++.h>
using namespace std;
int inline rid()
{
	int ans=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){ans=ans*10+ch-'0';ch=getchar();}
	return ans*f;
}
const int N=1e6+5;
char s[N];
int cnt=0,ans;
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='M'){cnt++;continue;}
		if(cnt)ans=max(ans+1,cnt);
	}
	printf("%d",ans);
	return 0;
}
