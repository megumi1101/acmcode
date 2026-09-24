#include<bits/stdc++.h>
using namespace std;
int n,s[2005],f[2005][2005];
int main()
{
	scanf("%d",&n);
	for(int i=n;i;i--)scanf("%d",&s[i]);
	for(int i=2;i<=n;i++)s[i]+=s[i-1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			f[i][j]=max(f[i][j-1],s[i]-f[i-j][min(i-j,j<<1)]);
	printf("%d",f[n][2]);
	return 0;
}