#include<bits/stdc++.h>
using namespace std;
#define N 20
int n,ans=0,a[N][N],b[N],bz[N];
void dfs(int x,int sum)
{
	if(x==n+1)
	{
		int t=0;
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				if(b[i]>b[j])
					t++;
		ans+=t%2==0?sum:-sum;
	}
	for (int i=1;i<=n;i++)
		if(!bz[i])
			bz[i]=1,b[x]=i,dfs(x+1,sum*a[x][i]),bz[i]=0;
}
int main()
{
	// freopen("test.in","r",stdin);
	ios::sync_with_stdio(false);
	// cin.tie(0),cout.tie(0);
	// cin>>n;
	// for (int i=1;i<=n;i++)
	// 	for (int j=1;j<=n;j++)
	// 		cin>>a[i][j];
	// dfs(1,1);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int t = 0; t < n; t++) {
        for (int i = 1; i <= n; i++) {
            int k = (i + t - 1) % n + 1;
            for (int j = 1; j <= n; j++) {
                cout << a[k][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
	cout<<ans<<endl;
	return 0;
}