#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=(1<<20)+10;
char s[N];
int T,cnt[30],nxt[N],qz[N],hz[N],f[30],n;
ll ans;
void wk()
{
	char c=getchar();
	memset(cnt,0,sizeof(cnt));
	memset(nxt,0,sizeof(nxt));
	memset(qz,0,sizeof(qz));
	memset(hz,0,sizeof(hz));
	memset(f,0,sizeof(f));ans=(ll)0;
	while(c>'z'||c<'a')	c=getchar();n=0;
	while(c<='z'&&c>='a'){s[++n]=c;c=getchar();}
	for(int i=2,j=0;i<=n;i++)
	{
		while(j&&s[i]!=s[j+1])j=nxt[j];
		if(s[i]==s[j+1])j++;nxt[i]=j;
	}
	for(int i=n;i>=1;i--)
	{
		cnt[s[i]-'a']++;
		if(cnt[s[i]-'a']&1)hz[i]=hz[i+1]+1;
		else hz[i]=hz[i+1]-1;
	}
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++)
	{
		cnt[s[i]-'a']++;
		if(cnt[s[i]-'a']&1)qz[i]=qz[i-1]+1;
		else qz[i]=qz[i-1]-1;
	}
	for(int i=1;i<n;i++)
	{
		if(i>=2)
		{
			ans+=(ll)f[hz[i+1]];
			for(int j=2*i;j<n;j+=i)
			{
				if(((i%(j-nxt[j]))==0)&&((j/(j-nxt[j]))>1))ans+=(ll)f[hz[j+1]];
				else break;
			}		
		}
		for(int j=qz[i];j<=26;j++)f[j]++;
	}	
	printf("%lld\n",ans);
}
int main()
{
	scanf("%d",&T);
	while(T--)wk();
	return 0;
}
