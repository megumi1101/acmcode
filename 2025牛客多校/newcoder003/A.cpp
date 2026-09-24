#include<bits/stdc++.h>
using namespace std;
#define N 2010
int T,n,a[N],b[N],ans[N][N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while (T--)
	{
		cin>>n;
		for (int i=1;i<=n;i++) cin>>a[i];
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++) ans[i][j]=-1;
		}
		for (int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				for (int j=1;j<=i;j++) ans[i][j]=ans[j][i]=0;
				continue;
			}
			for (int j=0;j<=i;j++) b[j]=0;
			int k=0;b[a[i]]=b[0]=1;
			for (int j=1;j<=i;j++)
				if(!b[a[j]])
				{
					b[a[j]]=1,ans[i][j]=ans[j][i]=k,k=a[j];
				}
			ans[i][i]=k;
			for (int j=1,k=0;j<=i;j++)
			{
				while (b[k]) k++;
//				cout<<j<<" "<<k<<endl;
				if(ans[i][j]==-1)
				{
					if(k<i) ans[i][j]=ans[j][i]=k,b[k]=1;
					else ans[i][j]=ans[j][i]=0;
				}
			}
//		for (int j=1;j<=n;j++)
//		{
//			for (int k=1;k<=n;k++)
//				cout<<ans[j][k]<<" ";
//			cout<<endl;
//		}
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
				cout<<ans[i][j]<<" ";
			cout<<endl;
		}
	}
	return 0;
}
/*
2
3
1 1 3
4
1 2 3 2
*/