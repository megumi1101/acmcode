#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=105;
char a[N],b[N],c[N];
int alen,blen,clen,f[N][N][N],now[N],lasta[N],lastb[N],lastc[N];
void init()
{
	for(int i=1;i<=alen;i++)
	{
		lasta[i]=now[a[i]-'a'];
		now[a[i]-'a']=i;
	}
	memset(now,0,sizeof(now));
	for(int i=1;i<=blen;i++)
	{
		lastb[i]=now[b[i]-'a'];
		now[b[i]-'a']=i;
	}
	memset(now,0,sizeof(now));
	for(int i=1;i<=clen;i++)
	{
		lastc[i]=now[c[i]-'a'];
		now[c[i]-'a']=i;
	}
}
signed main()
{
	scanf("%s%s%s",a+1,b+1,c+1);
	alen=strlen(a+1);blen=strlen(b+1);clen=strlen(c+1);
	init();
	for(int i=1;i<=alen;i++)
    for(int j=1;j<=blen;j++)
    for(int k=1;k<=clen;k++)
    {
    	if(a[i]==b[j]&&b[j]==c[k])
        {
            f[i][j][k]=f[i-1][j-1][k-1]*2+1;
            if (lasta[i]&&lastb[j]&&lastc[k])
            	f[i][j][k]-=f[lasta[i]-1][lastb[j]-1][lastc[k]-1]+1;
        }
        else f[i][j][k]=f[i-1][j][k]+f[i][j-1][k]+f[i][j][k-1]-f[i-1][j-1][k]-f[i][j-1][k-1]-f[i-1][j][k-1]+f[i-1][j-1][k-1];
    }
    printf("%lld",f[alen][blen][clen]);
}
/*
apartment
apache
approach
*/