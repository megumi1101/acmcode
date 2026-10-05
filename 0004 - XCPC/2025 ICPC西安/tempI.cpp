#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n,a[N][N],fa[N],lca[N][N],sz[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++){
            scanf("%d",&a[i][j]),a[j][i]=a[i][j];
            lca[j][i]=lca[i][j]=a[1][i]^a[1][j]^a[i][j];
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(lca[i][j]==i)sz[i]++;
    sz[0]=n+1;
    for(int i=2;i<=n;i++){
        int f=0;
        for(int j=1;j<=n;j++)if(j!=i&&lca[i][j]==j)
            if(sz[j]<sz[f])f=j;
        fa[i]=f;
    }
	for(int i=2;i<=n;i++)printf("%d %d\n",fa[i],i);
	return 0;
}
