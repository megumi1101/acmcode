// LUOGU_RID: 91774858
#include<bits/stdc++.h>
using namespace std;
const int N=5005; 
int inline rid()
{
	int ans=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){ans=ans*10+ch-'0';ch=getchar();}
	return ans*f;
}
int n,f[605][305][305],a[305][305];
int main()
{
	n=rid();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)a[i][j]=rid();
	memset(f,-0x3f,sizeof(f));
	f[1][1][1]=a[1][1];
	for(int i=2;i<=n+n-1;++i)
		for(int j=1;j<=n;++j)if(i-j+1>=1&&i-j+1<=n)
			for(int k=1;k<=n;++k)if(i-k+1>=1&&i-k+1<=n)
			{
				int t;
				if(j!=k)t=a[j][i-j+1]+a[k][i-k+1];
				else t=a[j][i-j+1];
				f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+t);
				f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k-1]+t);
				f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+t);
				f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+t);
			}
	printf("%d\n",f[n+n-1][n][n]);
	return 0;
}
