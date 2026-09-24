#include <bits/stdc++.h>
using namespace std;
const int maxn=150+5,mod=51123987;
char s[maxn];
int f[maxn][(maxn + 2)/3][(maxn + 2)/3][(maxn+2)/3],nxt[maxn][3],n,ans;
int main()
{
    scanf("%d%s",&n,s+1);
    nxt[n+1][0]=nxt[n+1][1]=nxt[n+1][2]=n+1;
    for(int i=n;i>=1;i--)
	{
        nxt[i][0]=nxt[i+1][0];nxt[i][1]=nxt[i+1][1];nxt[i][2]=nxt[i+1][2];
        if(s[i]=='a')nxt[i][0]=i;if(s[i]=='b')nxt[i][1]=i;if(s[i]=='c')nxt[i][2]=i;
    }
    f[1][0][0][0]=1;
    for(int i=1;i<=n;i++)
        for(int a=0;a<=(n+2)/3;a++)
            for(int b=0;b<=(n+2)/3;b++)
                for(int c=0;c<=(n+2)/3;c++)
                {
                    if(a+b+c==n&&abs(a-b)<=1&&abs(a-c)<=1&&abs(b-c)<=1)ans=(ans+f[i][a][b][c])%mod; 
                    f[nxt[i][0]][a+1][b][c]=(f[nxt[i][0]][a+1][b][c]+f[i][a][b][c])%mod;
                    f[nxt[i][1]][a][b+1][c]=(f[nxt[i][1]][a][b+1][c]+f[i][a][b][c])%mod;
                    f[nxt[i][2]][a][b][c+1]=(f[nxt[i][2]][a][b][c+1]+f[i][a][b][c])%mod;
                }
    printf("%d\n",ans);
    return 0;
}
