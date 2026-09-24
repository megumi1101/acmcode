#include<bits/stdc++.h>
using namespace std;
char s[55];
int n,f[55][55];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	memset(f,0x7f,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		f[i][i]=1;
	}
	for(int p=1;p<n;p++)
	{
		for(int i=1,j=i+p;i<n&&j<=n;i++,j=i+p)
		{
			if(s[i]==s[j])
			{
				f[i][j]=min(f[i+1][j],f[i][j-1]);
			}
			else
			{
				for(int k=i;k<j;k++)
				f[i][j]=min(f[i][k]+f[k+1][j],f[i][j]);
			}
		}
	}
	printf("%d",f[1][n]);
	return 0;
}
