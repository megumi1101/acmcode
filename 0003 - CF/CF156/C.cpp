// LUOGU_RID: 92629041
#include<bits/stdc++.h>
using namespace std; 
const int N=105,M=26*105,mod=1e9+7;
void add(int &x,int y){if((x+=y)>=mod)x-=mod;}
char s[N];
int T,f[N][M];
void init()
{
	f[0][0]=1;
	for(int i=1;i<=100;i++)
		for(int j=i;j<=2600;j++)
			for(int k=1;k<=26&&j-k>=0;k++)
				add(f[i][j],f[i-1][j-k]);
}
signed main()
{
	init();
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		int n=strlen(s+1),m=0;
		for(int i=1;i<=n;i++)m+=s[i]-'a'+1;
		printf("%d\n",f[n][m]-1);
	}
	return 0;
}
//
