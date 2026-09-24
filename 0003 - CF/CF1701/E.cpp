#include<bits/stdc++.h>
using namespace std;
const int maxn=5050,inf=1e9+7;
int n,m,f[2][maxn][3];
char s[maxn],t[maxn];
void sol()
{
	scanf("%d%d%s%s",&n,&m,s+1,t+1);int j=0;
	for(int i=1;i<=n;i++)
		if(j<m&&t[j+1]==s[i])j++;
	if(j<m){puts("-1");return;}int pl=m;
	for(int i=1;i<=m;i++)
		if(s[i]!=t[i]){pl=i-1;break;}
	int op=0;
	for(int i=0;i<=m;i++)
		f[0][i][0]=f[0][i][1]=f[0][i][2]=inf;
	f[0][0][0]=f[0][0][1]=f[0][0][2]=0;
	for(int i=1;i<=n;i++)
	{
		op^=1;
		for(int j=0;j<=m;j++)
		{
			f[op][j][0]=f[op][j][1]=f[op][j][2]=inf;
			f[op][j][0]=min(f[op][j][0],f[op^1][j][0]+2);
			f[op][j][2]=min(f[op][j][2],f[op^1][j][2]+1);
			if(j&&s[i]==t[j])
			{
				f[op][j][0]=min(f[op][j][0], f[op^1][j-1][0]+1);
				f[op][j][1]=min(f[op][j][1], f[op^1][j-1][1]);
				f[op][j][2]=min(f[op][j][2], f[op^1][j-1][2]+1);
			}
			f[op][j][1]=min(f[op][j][1],f[op][j][0]);
			f[op][j][2]=min(f[op][j][2],f[op][j][1]);
		}
	}
	printf("%d\n", min(n-pl,f[op][m][2]+1));
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)sol();
	return 0;
}
